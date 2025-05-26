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
int yylex();
extern int yylineno;
#line 7 "miniC.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <unistd.h>

#define MAX_TAC 1000

typedef struct TAC {
    char* op;       // Operação (e.g., "IF", "GOTO", "+", "-", etc.)
    char* arg1;     // Primeiro argumento
    char* arg2;     // Segundo argumento (se aplicável)
    char* result;   // Resultado ou label
} TAC;

TAC tacBuffer[MAX_TAC];
int tacIndex = 0;
int labelCount = 0; // Para gerar labels únicos
char label[10];
char label0[10];

void addTAC(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (tacIndex >= MAX_TAC) {
        fprintf(stderr, "Error: TAC buffer overflow.\n");
        exit(1);
    }
    tacBuffer[tacIndex].op = op ? strdup(op) : NULL;
    tacBuffer[tacIndex].arg1 = arg1 ? strdup(arg1) : NULL;
    tacBuffer[tacIndex].arg2 = arg2 ? strdup(arg2) : NULL;
    tacBuffer[tacIndex].result = result ? strdup(result) : NULL;
    tacIndex++;
}

void printTAC() {
    printf("\nThree-Address Code:\n");
    for (int i = 0; i < tacIndex; i++) {
        if (tacBuffer[i].op &&
            strcmp(tacBuffer[i].op, "+") != 0 &&
            strcmp(tacBuffer[i].op, "-") != 0 &&
            strcmp(tacBuffer[i].op, "*") != 0 &&
            strcmp(tacBuffer[i].op, "/") != 0 &&
            strcmp(tacBuffer[i].op, ">") != 0 &&
            strcmp(tacBuffer[i].op, "<") != 0 &&
            strcmp(tacBuffer[i].op, ">=") != 0 &&
            strcmp(tacBuffer[i].op, "<=") != 0 &&
            strcmp(tacBuffer[i].op, "==") != 0 &&
            strcmp(tacBuffer[i].op, "!=") != 0 &&
            strcmp(tacBuffer[i].op, "&&") != 0 &&
            strcmp(tacBuffer[i].op, "||") != 0 &&
            strcmp(tacBuffer[i].op, "!") != 0 &&
            strcmp(tacBuffer[i].op, "(int)") != 0 &&
            strcmp(tacBuffer[i].op, "(float)") != 0 &&
            strcmp(tacBuffer[i].op, "(char)") != 0 &&
            strcmp(tacBuffer[i].op, "(bool)") != 0){
            
            if(strcmp(tacBuffer[i].arg1, ":") != 0) {
                printf("\t%s %s %s %s\n",
                    tacBuffer[i].op,
                    tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "",
                    tacBuffer[i].arg2 ? tacBuffer[i].arg2 : "",
                    tacBuffer[i].result ? tacBuffer[i].result : "");
            } else {
                printf("%s%s",
                    tacBuffer[i].op,
                    tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "");
            }
        } else {
            printf("\t%s = %s %s %s\n",
                tacBuffer[i].result ? tacBuffer[i].result : "",
                tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "",
                tacBuffer[i].op ? tacBuffer[i].op : "",
                tacBuffer[i].arg2 ? tacBuffer[i].arg2 : "");
        }
    }
    printf("\n");
}

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

int yywrap( );
void yyerror(const char* str);

int if_condition = 1;
int if_else_condition = 0;


#line 262 "miniC.tab.c"

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
  YYSYMBOL_if = 39,                        /* if  */
  YYSYMBOL_40_1 = 40,                      /* $@1  */
  YYSYMBOL_41_2 = 41,                      /* $@2  */
  YYSYMBOL_else = 42,                      /* else  */
  YYSYMBOL_43_3 = 43,                      /* $@3  */
  YYSYMBOL_write = 44,                     /* write  */
  YYSYMBOL_read = 45,                      /* read  */
  YYSYMBOL_while = 46,                     /* while  */
  YYSYMBOL_47_4 = 47,                      /* $@4  */
  YYSYMBOL_expression = 48,                /* expression  */
  YYSYMBOL_soma_sub = 49,                  /* soma_sub  */
  YYSYMBOL_mult_div = 50,                  /* mult_div  */
  YYSYMBOL_comparison = 51,                /* comparison  */
  YYSYMBOL_log_exp = 52,                   /* log_exp  */
  YYSYMBOL_cast = 53,                      /* cast  */
  YYSYMBOL_term = 54                       /* term  */
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
#define YYLAST   268

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

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
       0,   251,   251,   252,   253,   254,   259,   265,   271,   277,
     288,   289,   290,   291,   292,   297,   319,   341,   319,   349,
     350,   350,   381,   406,   422,   432,   479,   479,   508,   509,
     510,   511,   512,   513,   514,   517,   535,   555,   573,   598,
     613,   628,   643,   658,   677,   698,   712,   726,   742,   751,
     760,   768,   776,   784,   792,   804,   818,   825
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
  "declaration", "comand", "assignment", "if", "$@1", "$@2", "else", "$@3",
  "write", "read", "while", "$@4", "expression", "soma_sub", "mult_div",
  "comparison", "log_exp", "cast", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     217,    13,   -22,    -2,     3,     5,    14,    20,    22,    31,
      12,    32,    13,    13,   -76,   -76,   -76,   -76,   -76,   -76,
      49,    38,    41,    43,    45,    71,    92,    49,    49,   -76,
     -76,   -76,   -76,   -76,    49,    58,    94,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,    66,    77,    88,
      93,   111,    72,   -76,    95,   105,   110,   120,   126,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
      49,   -76,    70,   124,   134,   139,   -76,   -76,    16,    18,
      55,    73,   -76,   227,   227,   227,   227,   227,   227,   240,
     214,   210,   210,   -76,   -76,   148,   -76,   -76,   -76,   -76,
     153,    49,   -76,    49,   -76,    49,   -76,    49,   -76,    47,
      47,   141,   156,   171,   186,   162,   167,   -76,   -76,   -76,
     -76,   -76,   -76,   206,   -76,   -76,   183,    47,   188,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,     5,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       4,     3,    57,    56,     0,     0,     0,    28,    29,    31,
      32,    33,    34,     6,     8,     7,     9,     0,     0,     0,
       0,     0,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     0,     0,    26,    15,     0,     0,
       0,     0,    30,    43,    44,    39,    40,    41,    42,    45,
      46,    35,    36,    37,    38,     0,    25,    22,    23,    24,
       0,     0,    49,     0,    53,     0,    51,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,    48,    52,    50,
      54,    17,    27,    19,    20,    18,     0,     0,     0,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,    -1,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -26,   -76,   -76,   -76,   -76,   -76,
     -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,    95,   123,   125,   126,
      16,    17,    18,   100,    36,    37,    38,    39,    40,    41,
      42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      19,    51,    52,   102,   104,   106,   108,    20,    53,    58,
      21,    30,    31,    -2,     1,    22,     2,    23,     3,     4,
       5,     6,     7,     8,     9,    10,    24,    28,    32,    33,
      32,    33,    29,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,   101,    -2,   103,     1,    25,
       2,    26,     3,     4,     5,     6,     7,     8,     9,    10,
      27,    32,    33,    54,    55,    56,    57,    32,    33,    43,
      32,    33,    44,    34,    45,   111,    46,   112,    35,   113,
      -2,   114,    34,    47,   105,    32,    33,    35,    59,    60,
      61,    62,    63,    64,    65,    66,    72,    67,    68,    69,
      70,    96,   107,    77,    48,    49,    50,    73,   115,   116,
      59,    60,    61,    62,    63,    64,    65,    66,    74,    67,
      68,    69,    70,    75,    71,    78,   128,    59,    60,    61,
      62,    63,    64,    65,    66,    79,    67,    68,    69,    70,
      80,    76,    59,    60,    61,    62,    63,    64,    65,    66,
      81,    67,    68,    69,    70,    97,    82,    59,    60,    61,
      62,    63,    64,    65,    66,    98,    67,    68,    69,    70,
      99,   117,    59,    60,    61,    62,    63,    64,    65,    66,
     109,    67,    68,    69,    70,   110,   118,    59,    60,    61,
      62,    63,    64,    65,    66,   121,    67,    68,    69,    70,
     122,   119,    59,    60,    61,    62,    63,    64,    65,    66,
     124,    67,    68,    69,    70,   127,   120,    -2,     1,     0,
       2,   129,     3,     4,     5,     6,     7,     8,     9,    10,
      59,    60,    61,    62,    63,    64,    65,    69,    70,    67,
      68,    69,    70,    -3,    -3,    -3,    -3,    -3,    -3,     0,
       0,     0,    67,    68,    69,    70,    59,    60,    61,    62,
      63,    64,     0,     0,     0,    67,    68,    69,    70
};

static const yytype_int8 yycheck[] =
{
       1,    27,    28,    78,    79,    80,    81,    29,    34,    35,
      12,    12,    13,     0,     1,    12,     3,    12,     5,     6,
       7,     8,     9,    10,    11,    12,    12,    15,    12,    13,
      12,    13,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    29,    33,    29,     1,    29,
       3,    29,     5,     6,     7,     8,     9,    10,    11,    12,
      29,    12,    13,     5,     6,     7,     8,    12,    13,    31,
      12,    13,    31,    24,    31,   101,    31,   103,    29,   105,
      33,   107,    24,    12,    29,    12,    13,    29,    16,    17,
      18,    19,    20,    21,    22,    23,    30,    25,    26,    27,
      28,    31,    29,    31,    12,    13,    14,    30,   109,   110,
      16,    17,    18,    19,    20,    21,    22,    23,    30,    25,
      26,    27,    28,    30,    30,    30,   127,    16,    17,    18,
      19,    20,    21,    22,    23,    30,    25,    26,    27,    28,
      30,    30,    16,    17,    18,    19,    20,    21,    22,    23,
      30,    25,    26,    27,    28,    31,    30,    16,    17,    18,
      19,    20,    21,    22,    23,    31,    25,    26,    27,    28,
      31,    30,    16,    17,    18,    19,    20,    21,    22,    23,
      32,    25,    26,    27,    28,    32,    30,    16,    17,    18,
      19,    20,    21,    22,    23,    33,    25,    26,    27,    28,
      33,    30,    16,    17,    18,    19,    20,    21,    22,    23,
       4,    25,    26,    27,    28,    32,    30,     0,     1,    -1,
       3,    33,     5,     6,     7,     8,     9,    10,    11,    12,
      16,    17,    18,    19,    20,    21,    22,    27,    28,    25,
      26,    27,    28,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    16,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,     9,    10,    11,
      12,    35,    36,    37,    38,    39,    44,    45,    46,    35,
      29,    12,    12,    12,    12,    29,    29,    29,    15,     0,
      35,    35,    12,    13,    24,    29,    48,    49,    50,    51,
      52,    53,    54,    31,    31,    31,    31,    12,    12,    13,
      14,    48,    48,    48,     5,     6,     7,     8,    48,    16,
      17,    18,    19,    20,    21,    22,    23,    25,    26,    27,
      28,    30,    30,    30,    30,    30,    30,    31,    30,    30,
      30,    30,    30,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    40,    31,    31,    31,    31,
      47,    29,    54,    29,    54,    29,    54,    29,    54,    32,
      32,    48,    48,    48,    48,    35,    35,    30,    30,    30,
      30,    33,    33,    41,     4,    42,    43,    32,    35,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    35,    35,    35,    36,    36,    36,    36,
      37,    37,    37,    37,    37,    38,    40,    41,    39,    42,
      43,    42,    44,    44,    44,    45,    47,    46,    48,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     4,     0,     0,    10,     0,
       0,     5,     5,     5,     5,     5,     0,     8,     1,     1,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     6,     4,
       6,     4,     6,     4,     6,     4,     1,     1
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
#line 251 "miniC.y"
                     {}
#line 1675 "miniC.tab.c"
    break;

  case 3: /* program: comand program  */
#line 252 "miniC.y"
                        {}
#line 1681 "miniC.tab.c"
    break;

  case 4: /* program: declaration program  */
#line 253 "miniC.y"
                             {}
#line 1687 "miniC.tab.c"
    break;

  case 5: /* program: error program  */
#line 254 "miniC.y"
                       { yyerrok; yyclearin; }
#line 1693 "miniC.tab.c"
    break;

  case 6: /* declaration: INT ID DONE  */
#line 259 "miniC.y"
                         {
                addTAC("declare", "int", (yyvsp[-1].id), NULL);
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_INT);
                }
           }
#line 1704 "miniC.tab.c"
    break;

  case 7: /* declaration: FLOAT ID DONE  */
#line 265 "miniC.y"
                           {
                addTAC("declare", "float", (yyvsp[-1].id), NULL);
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_FLOAT);
                }
           }
#line 1715 "miniC.tab.c"
    break;

  case 8: /* declaration: CHAR ID DONE  */
#line 271 "miniC.y"
                          {
                addTAC("declare", "char", (yyvsp[-1].id), NULL);
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_CHAR);
                }
           }
#line 1726 "miniC.tab.c"
    break;

  case 9: /* declaration: BOOL ID DONE  */
#line 277 "miniC.y"
                          {
                addTAC("declare", "bool", (yyvsp[-1].id), NULL);
                if(if_condition == 1) {
                    insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_BOOL);
                }
           }
#line 1737 "miniC.tab.c"
    break;

  case 10: /* comand: assignment  */
#line 288 "miniC.y"
                   {}
#line 1743 "miniC.tab.c"
    break;

  case 11: /* comand: if  */
#line 289 "miniC.y"
           {}
#line 1749 "miniC.tab.c"
    break;

  case 12: /* comand: write  */
#line 290 "miniC.y"
              {}
#line 1755 "miniC.tab.c"
    break;

  case 13: /* comand: read  */
#line 291 "miniC.y"
             {}
#line 1761 "miniC.tab.c"
    break;

  case 14: /* comand: while  */
#line 292 "miniC.y"
              {}
#line 1767 "miniC.tab.c"
    break;

  case 15: /* assignment: ID RECEIVE expression DONE  */
#line 297 "miniC.y"
                                       {
                addTAC(NULL, (yyvsp[-1].number).result, NULL, (yyvsp[-3].id));
                if(if_condition == 1) {
                    Symbol* symbol = findSymbol((yyvsp[-3].id));
                    if (symbol != NULL) {
                        if (symbol->type == (yyvsp[-1].number).type) {
                            insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, symbol->type);
                        } else if (symbol->type == TYPE_FLOAT && (yyvsp[-1].number).type == TYPE_INT) {
                            insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, symbol->type);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    } else {
                        fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                    }
                }
		  }
#line 1789 "miniC.tab.c"
    break;

  case 16: /* $@1: %empty  */
#line 319 "miniC.y"
                                   {
        pushScope();
        if ((yyvsp[-1].number).type == TYPE_BOOL) {
            if_condition = (yyvsp[-1].number).value;
            if_else_condition = (yyvsp[-1].number).value;
        } else {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
            if_condition = 0;
        }

        char labelTrue[10], labelFalse[10];
        sprintf(labelTrue, "L%d", labelCount++);
        sprintf(labelFalse, "L%d", labelCount++);

        // Gera TAC para a condição
        addTAC("if", (yyvsp[-1].number).result, "goto", labelTrue);
        addTAC("goto", labelFalse, NULL, NULL);

        // Label para o bloco "if"
        addTAC(labelTrue, ":", NULL, NULL);

        strcpy(label, labelFalse);
    }
#line 1817 "miniC.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 341 "miniC.y"
                                 {
        if (if_condition == 0) {
            popScope();
            if_condition = 1;
        }
    }
#line 1828 "miniC.tab.c"
    break;

  case 18: /* if: IF LEFTPAR expression RIGHTPAR $@1 LEFTKEYS program RIGHTKEYS $@2 else  */
#line 346 "miniC.y"
           {}
#line 1834 "miniC.tab.c"
    break;

  case 19: /* else: %empty  */
#line 349 "miniC.y"
                  {}
#line 1840 "miniC.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 350 "miniC.y"
           {
        pushScope();
        if (if_else_condition == 1) {
            if_condition = 0;
        } 

        char labelEnd[10];
        sprintf(labelEnd, "L%d", labelCount++);
        addTAC("goto", labelEnd, NULL, NULL);

        // Label para o bloco "else" ou saída
        addTAC(label, ":", NULL, NULL);

        strcpy(label, labelEnd);
    }
#line 1860 "miniC.tab.c"
    break;

  case 21: /* else: ELSE $@3 LEFTKEYS program RIGHTKEYS  */
#line 364 "miniC.y"
                                 {
        // Gera TAC para o bloco "else"
        addTAC(label, ":", NULL, NULL);

        if (if_condition == 0) {
            if_condition = 1;
        }

        if(if_else_condition == 1) {
            popScope();
        }
    }
#line 1877 "miniC.tab.c"
    break;

  case 22: /* write: WRITE LEFTPAR ID RIGHTPAR DONE  */
#line 381 "miniC.y"
                                      {
        addTAC("write", (yyvsp[-2].id), NULL, NULL);
        if (if_condition == 1) {
            Symbol* sym = findSymbol((yyvsp[-2].id));
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
            }
            else if(sym->value == -DBL_MAX) {
                fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", (yyvsp[-2].id), yylineno);
            }
            else {
                if (sym->type == TYPE_INT) {
                    printf("%s = %d (Type == INT)\n", (yyvsp[-2].id), (int)sym->value);
                } else if (sym->type == TYPE_BOOL) {
                    printf("%s = %d (Type == BOOL)\n", (yyvsp[-2].id), (int)sym->value);
                } else if (sym->type == TYPE_FLOAT) {
                    printf("%s = %.2lf (Type == FLOAT)\n", (yyvsp[-2].id), sym->value);
                } else if (sym->type == TYPE_CHAR) {
                    printf("%s = %c (Type == CHAR)\n", (yyvsp[-2].id), (char)sym->value);
                } else {
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
                }
            }
        }
     }
#line 1907 "miniC.tab.c"
    break;

  case 23: /* write: WRITE LEFTPAR NUMBER RIGHTPAR DONE  */
#line 406 "miniC.y"
                                          {
        char temp[16];
        sprintf(temp, "%lf", (yyvsp[-2].number).value);
        addTAC("write", temp, NULL, NULL);
        if (if_condition == 1) {
            if ((yyvsp[-2].number).type == TYPE_INT) {
                printf("%d (Type == INT)\n", (int)(yyvsp[-2].number).value);
            } else if ((yyvsp[-2].number).type == TYPE_FLOAT) {
                printf("%lf (Type == FLOAT)\n", (yyvsp[-2].number).value);
            } else if ((yyvsp[-2].number).type == TYPE_CHAR) {
                printf("%c (Type == CHAR)\n", (char)(yyvsp[-2].number).value);
            } else {
                fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
            }
        }
     }
#line 1928 "miniC.tab.c"
    break;

  case 24: /* write: WRITE LEFTPAR STRING RIGHTPAR DONE  */
#line 422 "miniC.y"
                                          {
        addTAC("write", (yyvsp[-2].id), NULL, NULL);
        if (if_condition == 1) {
            printf("%s\n", (yyvsp[-2].id));
        }
        free((yyvsp[-2].id)); // Free the string after printing
     }
#line 1940 "miniC.tab.c"
    break;

  case 25: /* read: READ LEFTPAR ID RIGHTPAR DONE  */
#line 432 "miniC.y"
                                    {
        addTAC("read", (yyvsp[-2].id), NULL, NULL);
        if (if_condition == 1) {
            Symbol* sym = findSymbol((yyvsp[-2].id));
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
            }
            else {
                FILE* input = fopen("/dev/tty", "r");
                if (input == NULL) {
                    fprintf(stderr, "Error: unable to read from keyboard.\n");
                    exit(1);
                }
                switch (sym->type) {
                        case TYPE_INT: printf("Enter value for variable '%s with Type == INT': ", (yyvsp[-2].id)); break;
                        case TYPE_BOOL: printf("Enter value for variable '%s with Type == BOOL': ", (yyvsp[-2].id)); break;
                        case TYPE_FLOAT: printf("Enter value for variable '%s with Type == FLOAT': ", (yyvsp[-2].id)); break;
                        case TYPE_CHAR: printf("Enter value for variable '%s with Type == CHAR': ", (yyvsp[-2].id)); break;
                        default: break;
                }
                if (sym->type == TYPE_INT) {
                    int value = 0;
                    fscanf(input, "%d", &value);
                    insertSymbol(sym->id, (double)value, TYPE_INT);
                } else if (sym->type == TYPE_FLOAT) {
                    double value = 0.0;
                    fscanf(input, "%lf", &value);
                    insertSymbol(sym->id, value, TYPE_FLOAT);
                } else if (sym->type == TYPE_CHAR) {
                    char value = 'a';
                    fscanf(input, " %c", &value);
                    insertSymbol(sym->id, value, TYPE_CHAR);
                } else if (sym->type == TYPE_BOOL) {
                    double value = 0.0;
                    fscanf(input, "%lf", &value);
                    insertSymbol(sym->id, value ? 1.0 : 0.0, TYPE_BOOL);
                } else {
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", sym->id, yylineno);
                }
                fclose(input);
            }
        }
    }
#line 1988 "miniC.tab.c"
    break;

  case 26: /* $@4: %empty  */
#line 479 "miniC.y"
                                         {
            char labelStart[10], labelLoop[10], labelEnd[10];
            sprintf(labelStart, "L%d", labelCount++);
            sprintf(labelLoop, "L%d", labelCount++);
            sprintf(labelEnd, "L%d", labelCount++);

            // Label para o início do loop
            addTAC(labelStart, ":", NULL, NULL);

            // Gera TAC para a condição
            addTAC("if", (yyvsp[-1].number).result, "goto", labelLoop);
            addTAC("goto", labelEnd, NULL, NULL);

            // Label para o fim do loop
            addTAC(labelLoop, ":", NULL, NULL);

            strcpy(label, labelEnd);
            strcpy(label0, labelStart);
     }
#line 2012 "miniC.tab.c"
    break;

  case 27: /* while: WHILE LEFTPAR expression RIGHTPAR $@4 LEFTKEYS program RIGHTKEYS  */
#line 497 "miniC.y"
                                  {
            // Gera TAC para voltar ao início do loop
            addTAC("goto", label0, NULL, NULL);

            // Label para o fim do loop
            addTAC(label, ":", NULL, NULL);
     }
#line 2024 "miniC.tab.c"
    break;

  case 28: /* expression: soma_sub  */
#line 508 "miniC.y"
                     { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2030 "miniC.tab.c"
    break;

  case 29: /* expression: mult_div  */
#line 509 "miniC.y"
                             { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2036 "miniC.tab.c"
    break;

  case 30: /* expression: LEFTPAR expression RIGHTPAR  */
#line 510 "miniC.y"
                                        { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).result = (yyvsp[-1].number).result; }
#line 2042 "miniC.tab.c"
    break;

  case 31: /* expression: comparison  */
#line 511 "miniC.y"
                       { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2048 "miniC.tab.c"
    break;

  case 32: /* expression: log_exp  */
#line 512 "miniC.y"
                    { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2054 "miniC.tab.c"
    break;

  case 33: /* expression: cast  */
#line 513 "miniC.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2060 "miniC.tab.c"
    break;

  case 34: /* expression: term  */
#line 514 "miniC.y"
                         { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).result = (yyvsp[0].number).result; }
#line 2066 "miniC.tab.c"
    break;

  case 35: /* soma_sub: expression PLUS expression  */
#line 517 "miniC.y"
                                     { 
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("+", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && (yyvsp[0].number).type == TYPE_FLOAT)
                        || ((yyvsp[-2].number).type == TYPE_FLOAT && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    (yyval.number).value = (yyvsp[-2].number).value + (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for addition at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2089 "miniC.tab.c"
    break;

  case 36: /* soma_sub: expression MIN expression  */
#line 535 "miniC.y"
                                     {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("-", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && (yyvsp[0].number).type == TYPE_FLOAT)
                        || ((yyvsp[-2].number).type == TYPE_FLOAT && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    (yyval.number).value = (yyvsp[-2].number).value - (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for subtraction at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2112 "miniC.tab.c"
    break;

  case 37: /* mult_div: expression MULT expression  */
#line 555 "miniC.y"
                                     {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("*", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && (yyvsp[0].number).type == TYPE_FLOAT)
                        || ((yyvsp[-2].number).type == TYPE_FLOAT && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    (yyval.number).value = (yyvsp[-2].number).value * (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for multiplication at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
        }
#line 2135 "miniC.tab.c"
    break;

  case 38: /* mult_div: expression DIV expression  */
#line 573 "miniC.y"
                                             { 
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("/", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if ((yyvsp[0].number).value == 0.0) {
                        fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
                        (yyval.number).value = -1;
                        (yyval.number).type = TYPE_UNKNOWN;
                }
                if ((yyvsp[-2].number).type == TYPE_INT && (yyvsp[0].number).type == TYPE_INT) {
                    (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_INT;
                } else if ((((yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_INT) && (yyvsp[0].number).type == TYPE_FLOAT)
                        || ((yyvsp[-2].number).type == TYPE_FLOAT && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT))) {
                    (yyval.number).value = (yyvsp[-2].number).value / (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for division at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
		}
#line 2163 "miniC.tab.c"
    break;

  case 39: /* comparison: expression LESS expression  */
#line 598 "miniC.y"
                                         {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("<", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT)) {
                    (yyval.number).value = (yyvsp[-2].number).value < (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
          }
#line 2183 "miniC.tab.c"
    break;

  case 40: /* comparison: expression GREAT expression  */
#line 613 "miniC.y"
                                         {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC(">", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT)) {
                    (yyval.number).value = (yyvsp[-2].number).value > (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
          }
#line 2203 "miniC.tab.c"
    break;

  case 41: /* comparison: expression LEQUAL expression  */
#line 628 "miniC.y"
                                         {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("<=", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT)) {
                    (yyval.number).value = (yyvsp[-2].number).value <= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
          }
#line 2223 "miniC.tab.c"
    break;

  case 42: /* comparison: expression GEQUAL expression  */
#line 643 "miniC.y"
                                         {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC(">=", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT)) {
                    (yyval.number).value = (yyvsp[-2].number).value >= (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
          }
#line 2243 "miniC.tab.c"
    break;

  case 43: /* comparison: expression EQUAL expression  */
#line 658 "miniC.y"
                                         { 
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("==", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_BOOL) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_BOOL)) {
                    (yyval.number).value = (yyvsp[-2].number).value == (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else if ((yyvsp[-2].number).type == TYPE_CHAR && (yyvsp[0].number).type == TYPE_CHAR) {
                    (yyval.number).value = (yyvsp[-2].number).value == (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
          }
#line 2267 "miniC.tab.c"
    break;

  case 44: /* comparison: expression NEQUAL expression  */
#line 677 "miniC.y"
                                         {
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("!=", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
                (yyval.number).result = strdup(temp);
                if(((yyvsp[-2].number).type == TYPE_INT || (yyvsp[-2].number).type == TYPE_FLOAT || (yyvsp[-2].number).type == TYPE_BOOL) && ((yyvsp[0].number).type == TYPE_INT || (yyvsp[0].number).type == TYPE_FLOAT || (yyvsp[0].number).type == TYPE_BOOL)) {
                    (yyval.number).value = (yyvsp[-2].number).value != (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else if ((yyvsp[-2].number).type == TYPE_CHAR && (yyvsp[0].number).type == TYPE_CHAR) {
                    (yyval.number).value = (yyvsp[-2].number).value != (yyvsp[0].number).value;
                    (yyval.number).type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                }
           }
#line 2291 "miniC.tab.c"
    break;

  case 45: /* log_exp: expression AND expression  */
#line 698 "miniC.y"
                                   {
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("&&", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
            (yyval.number).result = strdup(temp);
            if ((yyvsp[-2].number).type == TYPE_BOOL && (yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = (yyvsp[-2].number).value && (yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical AND between incompatible types at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
       }
#line 2310 "miniC.tab.c"
    break;

  case 46: /* log_exp: expression OR expression  */
#line 712 "miniC.y"
                                   {
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("||", (yyvsp[-2].number).result, (yyvsp[0].number).result, temp);
            (yyval.number).result = strdup(temp);
            if ((yyvsp[-2].number).type == TYPE_BOOL && (yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = (yyvsp[-2].number).value || (yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical OR between incompatible types at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
       }
#line 2329 "miniC.tab.c"
    break;

  case 47: /* log_exp: NOT expression  */
#line 726 "miniC.y"
                        {
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("!", NULL, (yyvsp[0].number).result, temp);
            (yyval.number).result = strdup(temp);
            if ((yyvsp[0].number).type == TYPE_BOOL) {
                (yyval.number).value = !(yyvsp[0].number).value;
                (yyval.number).type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical NOT on incompatible type at line %d.\n", yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            }
        }
#line 2348 "miniC.tab.c"
    break;

  case 48: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 742 "miniC.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(int)", NULL, (yyvsp[-1].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2362 "miniC.tab.c"
    break;

  case 49: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 751 "miniC.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(int)", NULL, (yyvsp[0].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2376 "miniC.tab.c"
    break;

  case 50: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 760 "miniC.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(float)", NULL, (yyvsp[-1].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2389 "miniC.tab.c"
    break;

  case 51: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 768 "miniC.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(float)", NULL, (yyvsp[0].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2402 "miniC.tab.c"
    break;

  case 52: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 776 "miniC.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(char)", NULL, (yyvsp[-1].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2415 "miniC.tab.c"
    break;

  case 53: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 784 "miniC.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(char)", NULL, (yyvsp[0].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2428 "miniC.tab.c"
    break;

  case 54: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 792 "miniC.y"
                                                        {
        if((yyvsp[-1].number).value != 0.0) {
            (yyval.number).value = 1.0;
        } else {
            (yyval.number).value = 0.0;
        }
        (yyval.number).type = TYPE_BOOL;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(bool)", NULL, (yyvsp[-1].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2445 "miniC.tab.c"
    break;

  case 55: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 804 "miniC.y"
                                 {
        if((yyvsp[0].number).value != 0.0) {
            (yyval.number).value = 1.0;
        } else {
            (yyval.number).value = 0.0;
        }
        (yyval.number).type = TYPE_BOOL;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(bool)", NULL, (yyvsp[0].number).result, tempStr);
        (yyval.number).result = strdup(tempStr);
    }
#line 2462 "miniC.tab.c"
    break;

  case 56: /* term: NUMBER  */
#line 818 "miniC.y"
             { 
        (yyval.number).value = (yyvsp[0].number).value; 
        (yyval.number).type = (yyvsp[0].number).type; 
        char temp[16];
        sprintf(temp, "%g", (yyvsp[0].number).value);
        (yyval.number).result = strdup(temp);
    }
#line 2474 "miniC.tab.c"
    break;

  case 57: /* term: ID  */
#line 825 "miniC.y"
         { 
        Symbol* sym = findSymbol((yyvsp[0].id));
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", (yyvsp[0].id), yylineno);
            (yyval.number).value = -1;
            (yyval.number).type = TYPE_UNKNOWN;
            (yyval.number).result = "";
        } else {
            if (sym->value == -DBL_MAX) {
                fprintf(stderr, "Uninitialized variable '%s' at line %d\n", (yyvsp[0].id), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).result = NULL;
            } else {
                (yyval.number).value = sym->value;
                (yyval.number).type = sym->type;
                (yyval.number).result = strdup(sym->id);
            }
        }
    }
#line 2499 "miniC.tab.c"
    break;


#line 2503 "miniC.tab.c"

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

#line 848 "miniC.y"


int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);
}

void handleSegfault(int sig) {
    fprintf(stderr, "Segmentation fault (signal %d). Exiting gracefully.\n", sig);
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
    yyparse( );
    printTAC(); // Imprime o código de três endereços
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}
