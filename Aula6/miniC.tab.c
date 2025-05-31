/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "miniC.y"

#include "VarType.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <unistd.h>
#include <stdint.h>
#include <execinfo.h>
#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/Target.h>
#include <llvm-c/ExecutionEngine.h>

#define HASH_SIZE 100

typedef struct Symbol {
    char* id;
    double value;
    VarType type;
    struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
    Symbol* table[HASH_SIZE];
    struct SymbolTable* prev; // points to the previous scope
} SymbolTable;

SymbolTable* currentScope = NULL;

unsigned int hash(const char* id) {
    unsigned int h = 0;
    for (; *id; id++) {
        h = (h << 4) + *id;
    }
    return h % HASH_SIZE;
}

Symbol* findSymbol(const char* id) {
    SymbolTable* scope = currentScope;
    while (scope != NULL) {
        Symbol* sym = scope->table[hash(id)];
        while (sym != NULL) {
            if (strcmp(sym->id, id) == 0) return sym;
            sym = sym->next;
        }
        scope = scope->prev;
    }
    return NULL;
}

void insertSymbol(const char* id, double value, VarType type) {
    if(currentScope) {
        Symbol* sym = findSymbol(id);
        if (sym != NULL) {
            sym->value = value;
            sym->type = type;
        } else {
            unsigned int index = hash(id);
            sym = malloc(sizeof(Symbol));
            sym->id = strdup(id);
            sym->value = value;
            sym->type = type;
            sym->next = currentScope->table[index];
            currentScope->table[index] = sym;
        }
    }
}

void pushScope() {
    SymbolTable* newScope = malloc(sizeof(SymbolTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        newScope->table[i] = NULL;
    }
    newScope->prev = currentScope;
    currentScope = newScope;
}

void popScope() {
    if (currentScope == NULL) exit(1);
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol* sym = currentScope->table[i];
        while (sym != NULL) {
            Symbol* temp = sym;
            sym = sym->next;
            free(temp->id);
            free(temp);
        }
    }
    SymbolTable* tempScope = currentScope;
    currentScope = currentScope->prev;
    free(tempScope);
}

void freeSymbolTable(SymbolTable* table) {
    while (table != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            Symbol* sym = table->table[i];
            while (sym != NULL) {
                Symbol* temp = sym;
                sym = sym->next;
                free(temp->id);
                free(temp);
            }
        }
        SymbolTable* temp = table;
        table = table->prev;
        free(temp);
    }
}

#define MAX_VARS 1000

char* var_names[MAX_VARS];
LLVMValueRef var_values[MAX_VARS];
int var_count = 0;

LLVMModuleRef module;
LLVMBuilderRef builder;
LLVMContextRef context;
LLVMValueRef mainFunc;
LLVMBasicBlockRef entry;

void allocaVars(const char* name, VarType type) {
    if (var_count >= MAX_VARS) {
        fprintf(stderr, "Error: too many variables.\n");
        exit(1);
    }

    LLVMTypeRef llvm_type;
    switch (type) {
        case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
        case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
        case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
        case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
        default:         llvm_type = LLVMDoubleTypeInContext(context); break;
    }
    LLVMValueRef alloc = LLVMBuildAlloca(builder, llvm_type, name);
    var_names[var_count] = strdup(name);
    var_values[var_count++] = alloc;
}

LLVMValueRef getVarLLVM(const char* name) {
    for (int i = 0; i < var_count; ++i)
        if (strcmp(var_names[i], name) == 0)
            return var_values[i];
    
    return NULL;
}

LLVMValueRef createGlobalString(const char* str, const char* name) {
    LLVMValueRef str_const = LLVMConstStringInContext(context, str, strlen(str), 1);
    LLVMValueRef global = LLVMAddGlobal(module, LLVMTypeOf(str_const), name);
    LLVMSetInitializer(global, str_const);
    LLVMSetGlobalConstant(global, 1);
    LLVMSetLinkage(global, LLVMPrivateLinkage);
    return global;
}

LLVMValueRef aux;

int yylex();
int yywrap( );
void yyerror(const char* str);
extern int yylineno;

int if_condition = 1;
int if_else_condition = 0;


#line 247 "miniC.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "miniC.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_CHAR = 6,                       /* CHAR  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_READ = 9,                       /* READ  */
  YYSYMBOL_WRITE = 10,                     /* WRITE  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_ID = 12,                        /* ID  */
  YYSYMBOL_NUMBER = 13,                    /* NUMBER  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_RECEIVE = 15,                   /* RECEIVE  */
  YYSYMBOL_EQUAL = 16,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 17,                    /* NEQUAL  */
  YYSYMBOL_LESS = 18,                      /* LESS  */
  YYSYMBOL_GREAT = 19,                     /* GREAT  */
  YYSYMBOL_LEQUAL = 20,                    /* LEQUAL  */
  YYSYMBOL_GEQUAL = 21,                    /* GEQUAL  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MIN = 26,                       /* MIN  */
  YYSYMBOL_MULT = 27,                      /* MULT  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_LEFTPAR = 29,                   /* LEFTPAR  */
  YYSYMBOL_RIGHTPAR = 30,                  /* RIGHTPAR  */
  YYSYMBOL_DONE = 31,                      /* DONE  */
  YYSYMBOL_LEFTKEYS = 32,                  /* LEFTKEYS  */
  YYSYMBOL_RIGHTKEYS = 33,                 /* RIGHTKEYS  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_declaration = 36,               /* declaration  */
  YYSYMBOL_comand = 37,                    /* comand  */
  YYSYMBOL_assignment = 38,                /* assignment  */
  YYSYMBOL_if_then = 39,                   /* if_then  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_if_then_aux = 42,               /* if_then_aux  */
  YYSYMBOL_if_then_aux2 = 43,              /* if_then_aux2  */
  YYSYMBOL_else = 44,                      /* else  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_while = 46,                     /* while  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_while_aux = 48,                 /* while_aux  */
  YYSYMBOL_write = 49,                     /* write  */
  YYSYMBOL_read = 50,                      /* read  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_soma_sub = 52,                  /* soma_sub  */
  YYSYMBOL_mult_div = 53,                  /* mult_div  */
  YYSYMBOL_comparison = 54,                /* comparison  */
  YYSYMBOL_log_exp = 55,                   /* log_exp  */
  YYSYMBOL_cast = 56,                      /* cast  */
  YYSYMBOL_term = 57                       /* term  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   277

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   242,   242,   243,   244,   245,   250,   256,   262,   268,
     279,   280,   281,   282,   283,   288,   340,   350,   340,   370,
     382,   386,   387,   387,   405,   405,   419,   432,   470,   498,
     509,   545,   546,   547,   548,   549,   550,   551,   554,   576,
     600,   622,   652,   674,   696,   718,   740,   766,   793,   804,
     815,   828,   834,   840,   845,   850,   855,   860,   867,   876,
     887
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "INT",
  "CHAR", "FLOAT", "BOOL", "READ", "WRITE", "WHILE", "ID", "NUMBER",
  "STRING", "RECEIVE", "EQUAL", "NEQUAL", "LESS", "GREAT", "LEQUAL",
  "GEQUAL", "AND", "OR", "NOT", "PLUS", "MIN", "MULT", "DIV", "LEFTPAR",
  "RIGHTPAR", "DONE", "LEFTKEYS", "RIGHTKEYS", "$accept", "program",
  "declaration", "comand", "assignment", "if_then", "$@1", "$@2",
  "if_then_aux", "if_then_aux2", "else", "$@3", "while", "$@4",
  "while_aux", "write", "read", "expression", "soma_sub", "mult_div",
  "comparison", "log_exp", "cast", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-64)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     226,    44,   -23,    10,    11,    19,    34,    29,    31,   -64,
      33,    73,    44,    44,   -64,   -64,   -64,   -64,   -64,   -64,
       1,    48,    54,    60,    61,    63,    15,    58,     1,   -64,
     -64,   -64,   -64,   -64,     1,    -3,   105,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,    64,    65,    66,
      67,     1,    85,   -64,    79,    87,    88,    89,   120,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,   -64,    62,    68,   103,   113,   135,   -64,    57,    59,
      69,    71,   -64,   236,   236,   236,   236,   236,   236,   249,
     223,    -8,    -8,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,     1,   -64,     1,   -64,     1,   -64,     1,   -64,   117,
     127,   150,   165,   180,   195,    56,    56,   -64,   -64,   -64,
     -64,   131,   141,   -64,   -64,   -64,    86,   -64,   -64,   147,
      56,   156,   -64
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,    10,    11,    12,    13,    14,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       4,     3,    60,    59,     0,     0,     0,    31,    32,    34,
      35,    36,    37,     6,     8,     7,     9,     0,     0,     0,
       0,     0,     0,    50,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,     0,    15,     0,     0,
       0,     0,    33,    46,    47,    42,    43,    44,    45,    48,
      49,    38,    39,    40,    41,    19,    30,    27,    28,    29,
      24,     0,    52,     0,    56,     0,    54,     0,    58,     0,
       0,     0,     0,     0,     0,     0,     0,    51,    55,    53,
      57,     0,     0,    20,    25,    17,    21,    22,    18,     0,
       0,     0,    23
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -64,    -1,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -27,   -64,   -64,
     -64,   -64,   -64,   -63
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    95,   126,   109,   125,
     128,   129,    16,   110,    27,    17,    18,    36,    37,    38,
      39,    40,    41,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    52,    54,    55,    56,    57,    20,    53,    58,    32,
      33,    30,    31,    32,    33,   102,   104,   106,   108,    69,
      70,    34,    21,    22,    76,    34,    35,    48,    49,    50,
      35,    23,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    -2,     1,    24,     2,    28,     3,
       4,     5,     6,     7,     8,     9,    10,     1,    25,     2,
      26,     3,     4,     5,     6,     7,     8,     9,    10,    32,
      33,    32,    33,    29,   111,    47,   112,    -2,   113,    43,
     114,    32,    33,    32,    33,    44,   101,    51,   103,    -2,
     127,    45,    46,    96,    72,    73,    74,    75,   105,    97,
     107,    59,    60,    61,    62,    63,    64,    65,    66,    78,
      67,    68,    69,    70,   121,   122,    77,    79,    80,    81,
       0,    59,    60,    61,    62,    63,    64,    65,    66,   131,
      67,    68,    69,    70,    98,    71,    59,    60,    61,    62,
      63,    64,    65,    66,    99,    67,    68,    69,    70,   115,
      82,    59,    60,    61,    62,    63,    64,    65,    66,   116,
      67,    68,    69,    70,   123,   100,    59,    60,    61,    62,
      63,    64,    65,    66,   124,    67,    68,    69,    70,   130,
     117,    59,    60,    61,    62,    63,    64,    65,    66,   132,
      67,    68,    69,    70,     0,   118,    59,    60,    61,    62,
      63,    64,    65,    66,     0,    67,    68,    69,    70,     0,
     119,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      67,    68,    69,    70,     0,   120,    -2,     1,     0,     2,
       0,     3,     4,     5,     6,     7,     8,     9,    10,    59,
      60,    61,    62,    63,    64,    65,     0,     0,    67,    68,
      69,    70,    -3,    -3,    -3,    -3,    -3,    -3,     0,     0,
       0,    67,    68,    69,    70,    59,    60,    61,    62,    63,
      64,     0,     0,     0,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
       1,    28,     5,     6,     7,     8,    29,    34,    35,    12,
      13,    12,    13,    12,    13,    78,    79,    80,    81,    27,
      28,    24,    12,    12,    51,    24,    29,    12,    13,    14,
      29,    12,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     1,    12,     3,    15,     5,
       6,     7,     8,     9,    10,    11,    12,     1,    29,     3,
      29,     5,     6,     7,     8,     9,    10,    11,    12,    12,
      13,    12,    13,     0,   101,    12,   103,    33,   105,    31,
     107,    12,    13,    12,    13,    31,    29,    29,    29,    33,
       4,    31,    31,    31,    30,    30,    30,    30,    29,    31,
      29,    16,    17,    18,    19,    20,    21,    22,    23,    30,
      25,    26,    27,    28,   115,   116,    31,    30,    30,    30,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,   130,
      25,    26,    27,    28,    31,    30,    16,    17,    18,    19,
      20,    21,    22,    23,    31,    25,    26,    27,    28,    32,
      30,    16,    17,    18,    19,    20,    21,    22,    23,    32,
      25,    26,    27,    28,    33,    30,    16,    17,    18,    19,
      20,    21,    22,    23,    33,    25,    26,    27,    28,    32,
      30,    16,    17,    18,    19,    20,    21,    22,    23,    33,
      25,    26,    27,    28,    -1,    30,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    -1,
      30,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    -1,    30,     0,     1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    25,    26,
      27,    28,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    16,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    35,    36,    37,    38,    39,    46,    49,    50,    35,
      29,    12,    12,    12,    12,    29,    29,    48,    15,     0,
      35,    35,    12,    13,    24,    29,    51,    52,    53,    54,
      55,    56,    57,    31,    31,    31,    31,    12,    12,    13,
      14,    29,    51,    51,     5,     6,     7,     8,    51,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    26,    27,
      28,    30,    30,    30,    30,    30,    51,    31,    30,    30,
      30,    30,    30,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    40,    31,    31,    31,    31,
      30,    29,    57,    29,    57,    29,    57,    29,    57,    42,
      47,    51,    51,    51,    51,    32,    32,    30,    30,    30,
      30,    35,    35,    33,    33,    43,    41,     4,    44,    45,
      32,    35,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    36,    36,    36,    36,
      37,    37,    37,    37,    37,    38,    40,    41,    39,    42,
      43,    44,    45,    44,    47,    46,    48,    49,    49,    49,
      50,    51,    51,    51,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     4,     0,     0,    12,     0,
       0,     0,     0,     5,     0,     9,     0,     5,     5,     5,
       5,     1,     1,     3,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     6,     4,     6,     4,     6,     4,     6,     4,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 242 "miniC.y"
                     {}
#line 1672 "miniC.tab.c"
    break;

  case 3: /* program: comand program  */
#line 243 "miniC.y"
                        {}
#line 1678 "miniC.tab.c"
    break;

  case 4: /* program: declaration program  */
#line 244 "miniC.y"
                             {}
#line 1684 "miniC.tab.c"
    break;

  case 5: /* program: error program  */
#line 245 "miniC.y"
                       { yyerrok; yyclearin; }
#line 1690 "miniC.tab.c"
    break;

  case 6: /* declaration: INT ID DONE  */
#line 250 "miniC.y"
                         {
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_INT);
                    allocaVars((yyvsp[-1].id), TYPE_INT);
                }
           }
#line 1701 "miniC.tab.c"
    break;

  case 7: /* declaration: FLOAT ID DONE  */
#line 256 "miniC.y"
                           {
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_FLOAT);
                    allocaVars((yyvsp[-1].id), TYPE_FLOAT);
                }
           }
#line 1712 "miniC.tab.c"
    break;

  case 8: /* declaration: CHAR ID DONE  */
#line 262 "miniC.y"
                          {
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_CHAR);
                    allocaVars((yyvsp[-1].id), TYPE_CHAR);
                }
           }
#line 1723 "miniC.tab.c"
    break;

  case 9: /* declaration: BOOL ID DONE  */
#line 268 "miniC.y"
                          {
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_BOOL);
                    allocaVars((yyvsp[-1].id), TYPE_BOOL);
                }
           }
#line 1734 "miniC.tab.c"
    break;

  case 10: /* comand: assignment  */
#line 279 "miniC.y"
                   {}
#line 1740 "miniC.tab.c"
    break;

  case 11: /* comand: if_then  */
#line 280 "miniC.y"
                {}
#line 1746 "miniC.tab.c"
    break;

  case 12: /* comand: while  */
#line 281 "miniC.y"
              {}
#line 1752 "miniC.tab.c"
    break;

  case 13: /* comand: write  */
#line 282 "miniC.y"
              {}
#line 1758 "miniC.tab.c"
    break;

  case 14: /* comand: read  */
#line 283 "miniC.y"
             {}
#line 1764 "miniC.tab.c"
    break;

  case 15: /* assignment: ID RECEIVE expression DONE  */
#line 288 "miniC.y"
                                       {
                Symbol* symbol = findSymbol((yyvsp[-3].id));
                LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
                LLVMTypeRef llvm_type;
                if (symbol) {
                    switch (symbol->type) {
                        case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                        case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                        case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                        case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                        default:         llvm_type = LLVMInt32TypeInContext(context); break;
                    }
                }
                LLVMValueRef value = (yyvsp[-1].number).llvm_value;
                if(symbol) {
                    if (symbol->type == (yyvsp[-1].number).type) {
                        LLVMBuildStore(builder, value, var);
                    }
                    // Cast se necessário
                    else if (symbol->type == TYPE_FLOAT && (yyvsp[-1].number).type == TYPE_INT) {
                        value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                        LLVMBuildStore(builder, value, var);
                    }
                    else if (symbol->type == TYPE_INT && (yyvsp[-1].number).type == TYPE_FLOAT) {
                        printf("Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                        value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                        LLVMBuildStore(builder, value, var);
                    }
                }

                // Atualiza a tabela de símbolos
                if(if_condition == 1) {
                    if (symbol) {
                        if (symbol->type == (yyvsp[-1].number).type) {
                            insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, symbol->type);
                        } else if (symbol->type == TYPE_FLOAT && (yyvsp[-1].number).type == TYPE_INT) {
                            insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, symbol->type);
                        } else if (symbol->type == TYPE_INT && (yyvsp[-1].number).type == TYPE_FLOAT) {
                            insertSymbol((yyvsp[-3].id), (int)(yyvsp[-1].number).value, symbol->type);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    } else {
                        fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                    }
                }
		  }
#line 1816 "miniC.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 340 "miniC.y"
                                        {
            pushScope();
            if ((yyvsp[-1].number).type == TYPE_BOOL) {
                if_condition = (yyvsp[-1].number).value;
                if_else_condition = (yyvsp[-1].number).value;
            } else {
                fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
                if_condition = 0;
            }
            aux = (yyvsp[-1].number).llvm_value;
        }
#line 1832 "miniC.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 350 "miniC.y"
                                                              {
            if (if_condition == 0) {
                popScope();
                if_condition = 1;
            }

            // Ao final do bloco if, faz branch para o fim do if
            LLVMBuildBr(builder, (yyvsp[0].if_else_blocks).endIFBB);

            // Entra no bloco else para continuar parsing
            LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].if_else_blocks).elseBB);
        }
#line 1849 "miniC.tab.c"
    break;

  case 18: /* if_then: IF LEFTPAR expression RIGHTPAR $@1 if_then_aux LEFTKEYS program RIGHTKEYS if_then_aux2 $@2 else  */
#line 361 "miniC.y"
               {
            // Ao final do else, faz branch para o fim do if
            LLVMBuildBr(builder, (yyvsp[-2].if_else_blocks).endIFBB);

            // Posiciona o builder no bloco de saída do if
            LLVMPositionBuilderAtEnd(builder, (yyvsp[-2].if_else_blocks).endIFBB);
        }
#line 1861 "miniC.tab.c"
    break;

  case 19: /* if_then_aux: %empty  */
#line 370 "miniC.y"
             {
    // Cria blocos para if, else e fim
    (yyval.if_else_blocks).ifBB = LLVMAppendBasicBlockInContext(context, mainFunc, "if");
    (yyval.if_else_blocks).elseBB = LLVMAppendBasicBlockInContext(context, mainFunc, "else");

    // Gera branch condicional
    LLVMBuildCondBr(builder, aux, (yyval.if_else_blocks).ifBB, (yyval.if_else_blocks).elseBB);

    // Entra no bloco do if
    LLVMPositionBuilderAtEnd(builder, (yyval.if_else_blocks).ifBB);
}
#line 1877 "miniC.tab.c"
    break;

  case 20: /* if_then_aux2: %empty  */
#line 382 "miniC.y"
              {
    (yyval.if_else_blocks).endIFBB = LLVMAppendBasicBlockInContext(context, mainFunc, "endif");
}
#line 1885 "miniC.tab.c"
    break;

  case 21: /* else: %empty  */
#line 386 "miniC.y"
                  {}
#line 1891 "miniC.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 387 "miniC.y"
           {
        pushScope();
        if (if_else_condition == 1) {
            if_condition = 0;
        }
    }
#line 1902 "miniC.tab.c"
    break;

  case 23: /* else: ELSE $@3 LEFTKEYS program RIGHTKEYS  */
#line 392 "miniC.y"
                                 {
        if (if_condition == 0) {
            if_condition = 1;
        }

        if(if_else_condition == 1) {
            popScope();
        }
    }
#line 1916 "miniC.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 405 "miniC.y"
                                                   {
        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-3].while_blocks).bodyBB, (yyvsp[-3].while_blocks).endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-3].while_blocks).bodyBB);
    }
#line 1927 "miniC.tab.c"
    break;

  case 25: /* while: WHILE while_aux LEFTPAR expression RIGHTPAR $@4 LEFTKEYS program RIGHTKEYS  */
#line 410 "miniC.y"
                                 {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, (yyvsp[-7].while_blocks).condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).endWHILEBB);
    }
#line 1939 "miniC.tab.c"
    break;

  case 26: /* while_aux: %empty  */
#line 419 "miniC.y"
           {
    // Cria blocos para condicional, corpo e fim do while
        (yyval.while_blocks).condBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.cond");
        (yyval.while_blocks).bodyBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.body");
        (yyval.while_blocks).endWHILEBB = LLVMAppendBasicBlockInContext(context, mainFunc, "while.end");

        // Branch para o bloco condicional
        LLVMBuildBr(builder, (yyval.while_blocks).condBB);

        // Condicional
        LLVMPositionBuilderAtEnd(builder, (yyval.while_blocks).condBB);
}
#line 1956 "miniC.tab.c"
    break;

  case 27: /* write: WRITE LEFTPAR ID RIGHTPAR DONE  */
#line 432 "miniC.y"
                                      {
        Symbol* sym = findSymbol((yyvsp[-2].id));
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
        }
        else if(sym->value == -DBL_MAX) {
            fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", (yyvsp[-2].id), yylineno);
        }
        else {
            LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
            LLVMValueRef loaded[1];
            LLVMValueRef write_func;
            switch (sym->type) {
                case TYPE_INT:
                    write_func = LLVMGetNamedFunction(module, "write_int");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt32TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_FLOAT:
                    write_func = LLVMGetNamedFunction(module, "write_float");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMDoubleTypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_BOOL:
                    write_func = LLVMGetNamedFunction(module, "write_bool");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt1TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                case TYPE_CHAR:
                    write_func = LLVMGetNamedFunction(module, "write_char");
                    loaded[0] = LLVMBuildLoad2(builder, LLVMInt8TypeInContext(context), var, "loadtmp");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, loaded, 1, "");
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
            }
        }
     }
#line 1999 "miniC.tab.c"
    break;

  case 28: /* write: WRITE LEFTPAR NUMBER RIGHTPAR DONE  */
#line 470 "miniC.y"
                                         {
        LLVMValueRef write_func;
        LLVMValueRef arg[1];
        switch ((yyvsp[-2].number).type) {
            case TYPE_INT:
                write_func = LLVMGetNamedFunction(module, "write_int");
                arg[0] = LLVMConstInt(LLVMInt32TypeInContext(context), (int)(yyvsp[-2].number).value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_FLOAT:
                write_func = LLVMGetNamedFunction(module, "write_float");
                arg[0] = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[-2].number).value);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_CHAR:
                write_func = LLVMGetNamedFunction(module, "write_char");
                arg[0] = LLVMConstInt(LLVMInt8TypeInContext(context), (char)(yyvsp[-2].number).value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            case TYPE_BOOL:
                write_func = LLVMGetNamedFunction(module, "write_bool");
                arg[0] = LLVMConstInt(LLVMInt1TypeInContext(context), (int)(yyvsp[-2].number).value, 0);
                LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
                break;
            default:
                fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
        }
    }
#line 2032 "miniC.tab.c"
    break;

  case 29: /* write: WRITE LEFTPAR STRING RIGHTPAR DONE  */
#line 498 "miniC.y"
                                         {
        LLVMValueRef write_func = LLVMGetNamedFunction(module, "write_string");
        LLVMValueRef str = LLVMBuildPointerCast(builder, createGlobalString((yyvsp[-2].id), "str_literal"), LLVMPointerType(LLVMInt8TypeInContext(context), 0), "");
        LLVMValueRef arg[1];
        arg[0] = str;
        LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(write_func)), write_func, arg, 1, "");
        free((yyvsp[-2].id));
    }
#line 2045 "miniC.tab.c"
    break;

  case 30: /* read: READ LEFTPAR ID RIGHTPAR DONE  */
#line 509 "miniC.y"
                                    {
        Symbol* sym = findSymbol((yyvsp[-2].id));
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
        }
        else {
            LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
            LLVMValueRef arg[1];
            arg[0] = var;
            LLVMValueRef read_func;
            switch (sym->type) {
                case TYPE_INT:
                    read_func = LLVMGetNamedFunction(module, "read_int");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_FLOAT:
                    read_func = LLVMGetNamedFunction(module, "read_float");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_BOOL:
                    read_func = LLVMGetNamedFunction(module, "read_bool");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                case TYPE_CHAR:
                    read_func = LLVMGetNamedFunction(module, "read_char");
                    LLVMBuildCall2(builder, LLVMGetElementType(LLVMTypeOf(read_func)), read_func, arg, 1, "");
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
            }
        }
    }
#line 2082 "miniC.tab.c"
    break;

  case 31: /* expression: soma_sub  */
#line 545 "miniC.y"
                     { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2088 "miniC.tab.c"
    break;

  case 32: /* expression: mult_div  */
#line 546 "miniC.y"
                             { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2094 "miniC.tab.c"
    break;

  case 33: /* expression: LEFTPAR expression RIGHTPAR  */
#line 547 "miniC.y"
                                        { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; }
#line 2100 "miniC.tab.c"
    break;

  case 34: /* expression: comparison  */
#line 548 "miniC.y"
                       { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2106 "miniC.tab.c"
    break;

  case 35: /* expression: log_exp  */
#line 549 "miniC.y"
                    { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2112 "miniC.tab.c"
    break;

  case 36: /* expression: cast  */
#line 550 "miniC.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2118 "miniC.tab.c"
    break;

  case 37: /* expression: term  */
#line 551 "miniC.y"
                         { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 2124 "miniC.tab.c"
    break;

  case 38: /* soma_sub: expression PLUS expression  */
#line 554 "miniC.y"
                                     { 
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                    (yyval.number).llvm_value = LLVMBuildAdd(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "addtmp");
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                    (yyval.number).llvm_value = LLVMBuildFAdd(builder, left, right, "faddtmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for addition at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2151 "miniC.tab.c"
    break;

  case 39: /* soma_sub: expression MIN expression  */
#line 576 "miniC.y"
                                     {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                    (yyval.number).llvm_value = LLVMBuildSub(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "subtmp");
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                    (yyval.number).llvm_value = LLVMBuildFSub(builder, left, right, "fsubtmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for subtraction at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2178 "miniC.tab.c"
    break;

  case 40: /* mult_div: expression MULT expression  */
#line 600 "miniC.y"
                                     {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                    (yyval.number).llvm_value = LLVMBuildMul(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "multtmp");
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                    (yyval.number).llvm_value = LLVMBuildFMul(builder, left, right, "fmulttmp");
                } else {
                    fprintf(stderr, "Error: incompatible types for multiplication at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2205 "miniC.tab.c"
    break;

  case 41: /* mult_div: expression DIV expression  */
#line 622 "miniC.y"
                                             { 
                if ((yyvsp[0].number).value == 0.0) {
                        fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
                        (yyval.number).value = -1;
                        (yyval.number).type = TYPE_UNKNOWN;
                } else {
                    if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                        (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value;
                        (yyval.number).type = TYPE_INT;
                        (yyval.number).llvm_value = LLVMBuildSDiv(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "divtmp");
                    } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                        // Promove para float se necessário
                        LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                        LLVMValueRef right = (yyvsp[0].number).llvm_value;
                        if ((yyvsp[-2].number).type == TYPE_INT)
                            left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                        if ((yyvsp[0].number).type == TYPE_INT)
                            right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                        (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value;
                        (yyval.number).type = TYPE_FLOAT;
                        (yyval.number).llvm_value = LLVMBuildFDiv(builder, left, right, "fdivtmp");
                    } else {
                        fprintf(stderr, "Error: incompatible types for division at line %d.\n", yylineno);
                        (yyval.number).value = -1;
                        (yyval.number).type = TYPE_UNKNOWN;
                    }
                }
		}
#line 2238 "miniC.tab.c"
    break;

  case 42: /* comparison: expression LESS expression  */
#line 652 "miniC.y"
                                       {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value < (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntSLT, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value < (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealULT, left, right, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2265 "miniC.tab.c"
    break;

  case 43: /* comparison: expression GREAT expression  */
#line 674 "miniC.y"
                                          {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value > (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntSGT, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value > (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUGT, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2292 "miniC.tab.c"
    break;

  case 44: /* comparison: expression LEQUAL expression  */
#line 696 "miniC.y"
                                           {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value <= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntSLE, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value <= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealULE, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2319 "miniC.tab.c"
    break;

  case 45: /* comparison: expression GEQUAL expression  */
#line 718 "miniC.y"
                                           {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value >= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntSGE, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value >= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUGE, left, right, "fcmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2346 "miniC.tab.c"
    break;

  case 46: /* comparison: expression EQUAL expression  */
#line 740 "miniC.y"
                                           { 
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value == (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    // Promove para float se necessário
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    else if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value == (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUEQ, left, right, "fcmptmp");
                } else if ((yyvsp[-2].number).type == TYPE_CHAR && (yyvsp[0].number).type == TYPE_CHAR) {
                    (yyval.number).value = (yyvsp[-2].number).value == (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntEQ, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2377 "miniC.tab.c"
    break;

  case 47: /* comparison: expression NEQUAL expression  */
#line 766 "miniC.y"
                                           {
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value != (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else if (((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && ((yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_INT)) {
                    LLVMValueRef left = (yyvsp[-2].number).llvm_value;
                    LLVMValueRef right = (yyvsp[0].number).llvm_value;
                    if ((yyvsp[-2].number).type == TYPE_INT)
                        left = LLVMBuildSIToFP(builder, left, LLVMDoubleTypeInContext(context), "inttofloatl");
                    if ((yyvsp[0].number).type == TYPE_INT)
                        right = LLVMBuildSIToFP(builder, right, LLVMDoubleTypeInContext(context), "inttofloatr");
                    (yyval.number).value = (yyvsp[-2].number).value != (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, left, right, "fcmptmp");
                } else if ((yyvsp[-2].number).type == TYPE_CHAR && (yyvsp[0].number).type == TYPE_CHAR) {
                    (yyval.number).value = (yyvsp[-2].number).value != (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                    (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "cmptmp");
                } else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
            }
#line 2407 "miniC.tab.c"
    break;

  case 48: /* log_exp: expression AND expression  */
#line 793 "miniC.y"
                                   {
            if ((yyvsp[-2].number).type == TYPE_BOOL && (yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = (yyvsp[-2].number).value && (yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
                (yyval.number).llvm_value = LLVMBuildAnd(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "andtmp");
            } else {
                fprintf(stderr, "Error: logical AND between incompatible types at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
       }
#line 2423 "miniC.tab.c"
    break;

  case 49: /* log_exp: expression OR expression  */
#line 804 "miniC.y"
                                   {
            if ((yyvsp[-2].number).type == TYPE_BOOL && (yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = (yyvsp[-2].number).value || (yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
                (yyval.number).llvm_value = LLVMBuildOr(builder, (yyvsp[-2].number).llvm_value, (yyvsp[0].number).llvm_value, "ortmp");
            } else {
                fprintf(stderr, "Error: logical OR between incompatible types at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
       }
#line 2439 "miniC.tab.c"
    break;

  case 50: /* log_exp: NOT expression  */
#line 815 "miniC.y"
                        {
            if ((yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = !(yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
                (yyval.number).llvm_value = LLVMBuildNot(builder, (yyvsp[0].number).llvm_value, "nottmp");
            } else {
                fprintf(stderr, "Error: logical NOT on incompatible type at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
        }
#line 2455 "miniC.tab.c"
    break;

  case 51: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 828 "miniC.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 2466 "miniC.tab.c"
    break;

  case 52: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 834 "miniC.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 2477 "miniC.tab.c"
    break;

  case 53: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 840 "miniC.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 2487 "miniC.tab.c"
    break;

  case 54: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 845 "miniC.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 2497 "miniC.tab.c"
    break;

  case 55: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 850 "miniC.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 2507 "miniC.tab.c"
    break;

  case 56: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 855 "miniC.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 2517 "miniC.tab.c"
    break;

  case 57: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 860 "miniC.y"
                                                        {
        (yyval.number).value = ((yyvsp[-1].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[-1].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
    }
#line 2529 "miniC.tab.c"
    break;

  case 58: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 867 "miniC.y"
                                 {
        (yyval.number).value = ((yyvsp[0].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[0].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
    }
#line 2541 "miniC.tab.c"
    break;

  case 59: /* term: NUMBER  */
#line 876 "miniC.y"
             { 
        (yyval.number).value = (yyvsp[0].number).value; 
        (yyval.number).type = (yyvsp[0].number).type; 
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:   (yyval.number).llvm_value = LLVMConstInt(LLVMInt32TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            case TYPE_FLOAT: (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
            case TYPE_CHAR:  (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            case TYPE_BOOL:  (yyval.number).llvm_value = LLVMConstInt(LLVMInt1TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            default:         (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
        }
    }
#line 2557 "miniC.tab.c"
    break;

  case 60: /* term: ID  */
#line 887 "miniC.y"
         {
        Symbol* sym = findSymbol((yyvsp[0].id));
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", (yyvsp[0].id), yylineno);
            (yyval.number).value = -1;
            (yyval.number).type = TYPE_UNKNOWN;
        } else {
            if (sym->value == -DBL_MAX) {
                fprintf(stderr, "Uninitialized variable '%s' at line %d\n", (yyvsp[0].id), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            } else {
                (yyval.number).value = sym->value;
                (yyval.number).type = sym->type;
                LLVMValueRef var = getVarLLVM((yyvsp[0].id));
                LLVMTypeRef llvm_type;
                switch (sym->type) {
                    case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                    case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                    case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                    case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                    default:         llvm_type = LLVMDoubleTypeInContext(context); break;
                }
                (yyval.number).llvm_value = LLVMBuildLoad2(builder, llvm_type, var, "loadtmp");
            }
        }
    }
#line 2589 "miniC.tab.c"
    break;


#line 2593 "miniC.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 917 "miniC.y"


int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);
}

void handleSegfault(int sig) {
    void *array[10];
    size_t size;

    fprintf(stderr, "Segmentation fault (signal %d). Exiting gracefully.\n", sig);

    // Captura o backtrace
    size = backtrace(array, 10);
    backtrace_symbols_fd(array, size, STDERR_FILENO);

    exit(1);
}

void printSymbolTable(SymbolTable* table) {
    printf("\nSymbol Table:\n");
    printf("-------------------------------------------------\n");
    printf("| %-10s | %-10s | %-10s |\n", "Identifier", "Value", "Type");
    printf("-------------------------------------------------\n");
    while (table != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            Symbol* sym = table->table[i];
            while (sym != NULL) {
                if(sym->value >= INT_MAX - 10 || sym->value <= INT_MIN + 10) {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "CHAR"); break;
                        default: break;
                    }
                }
                else {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10.2lf | %-10s |\n", sym->id, sym->value, "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10c | %-10s |\n", sym->id, (char)sym->value, "CHAR"); break;
                        case TYPE_UNKNOWN: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "UNKNOWN"); break;
                        default: break;
                    }
                }
                sym = sym->next;
            }
        }
        table = table->prev;
    }
    printf("-------------------------------------------------\n\n");
}

int main( ) {
    signal(SIGSEGV, handleSegfault); // Handle segmentation faults
    pushScope(); // Initialize the first scope

    // Inicialização LLVM
    context = LLVMContextCreate();
    module = LLVMModuleCreateWithNameInContext("miniC", context);
    builder = LLVMCreateBuilderInContext(context);

    // Cria função write: void write(param)
    LLVMTypeRef write_int_args[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef write_int_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_int_args, 1, 0);
    LLVMAddFunction(module, "write_int", write_int_type);

    LLVMTypeRef write_float_args[] = { LLVMDoubleTypeInContext(context) };
    LLVMTypeRef write_float_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_float_args, 1, 0);
    LLVMAddFunction(module, "write_float", write_float_type);

    LLVMTypeRef write_char_args[] = { LLVMInt8TypeInContext(context) };
    LLVMTypeRef write_char_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_char_args, 1, 0);
    LLVMAddFunction(module, "write_char", write_char_type);

    LLVMTypeRef write_bool_args[] = { LLVMInt1TypeInContext(context) };
    LLVMTypeRef write_bool_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_bool_args, 1, 0);
    LLVMAddFunction(module, "write_bool", write_bool_type);

    LLVMTypeRef write_string_args[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    LLVMTypeRef write_string_type = LLVMFunctionType(LLVMVoidTypeInContext(context), write_string_args, 1, 0);
    LLVMAddFunction(module, "write_string", write_string_type);

    // Cria função read: void read(param)
    LLVMTypeRef read_int_args[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef read_int_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_int_args, 1, 0);
    LLVMAddFunction(module, "read_int", read_int_type);

    LLVMTypeRef read_float_args[] = { LLVMDoubleTypeInContext(context) };
    LLVMTypeRef read_float_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_float_args, 1, 0);
    LLVMAddFunction(module, "read_float", read_float_type);

    LLVMTypeRef read_char_args[] = { LLVMInt8TypeInContext(context) };
    LLVMTypeRef read_char_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_char_args, 1, 0);
    LLVMAddFunction(module, "read_char", read_char_type);

    LLVMTypeRef read_bool_args[] = { LLVMInt1TypeInContext(context) };
    LLVMTypeRef read_bool_type = LLVMFunctionType(LLVMVoidTypeInContext(context), read_bool_args, 1, 0);
    LLVMAddFunction(module, "read_bool", read_bool_type);

    // Cria função main: int main()
    LLVMTypeRef mainType = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0);
    mainFunc = LLVMAddFunction(module, "main", mainType);
    entry = LLVMAppendBasicBlockInContext(context, mainFunc, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    yyparse( );

    // Retorno main
    LLVMBuildRet(builder, LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0));

    // Imprime IR
    char *irstr = LLVMPrintModuleToString(module);
    printf("\nLLVM IR:\n%s\n", irstr);
    LLVMDisposeMessage(irstr);

    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);
    LLVMContextDispose(context);
    
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}
