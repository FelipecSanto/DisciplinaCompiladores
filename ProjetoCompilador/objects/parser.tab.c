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
#line 1 "compiler/parser.y"

#include "LLVMUtils.h"
#include "SymbolTable.h"
#include "UtilsConditionals.h"
#include "VarType.h"

#define MAX_PARAMS 10

typedef struct Param_call {
    double value;
    VarType type;
    LLVMValueRef llvm_value;
} Param_call;

int yylex();
int yywrap( );
void yyerror(const char* str);
extern int yylineno;

double* vals = NULL; // Array para armazenar valores de inicialização de vetor
int array_value_count = 0; // Contador de valores de vetor

char* param_names[MAX_PARAMS];
LLVMTypeRef param_typesLLVM[MAX_PARAMS];
VarType param_types[MAX_PARAMS];
int param_count = 0;

Param_call param_call[MAX_PARAMS];
int param_call_count = 0;



#line 104 "objects/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_ELSEIF = 5,                     /* ELSEIF  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_CHAR = 7,                       /* CHAR  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_BOOL = 9,                       /* BOOL  */
  YYSYMBOL_PRINTF = 10,                    /* PRINTF  */
  YYSYMBOL_SCANF = 11,                     /* SCANF  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_NUMBER = 15,                    /* NUMBER  */
  YYSYMBOL_ID = 16,                        /* ID  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_CARACTERE = 18,                 /* CARACTERE  */
  YYSYMBOL_RECEIVE = 19,                   /* RECEIVE  */
  YYSYMBOL_EQUAL = 20,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 21,                    /* NEQUAL  */
  YYSYMBOL_LESS = 22,                      /* LESS  */
  YYSYMBOL_GREAT = 23,                     /* GREAT  */
  YYSYMBOL_LEQUAL = 24,                    /* LEQUAL  */
  YYSYMBOL_GEQUAL = 25,                    /* GEQUAL  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MIN = 30,                       /* MIN  */
  YYSYMBOL_MULT = 31,                      /* MULT  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_LEFTPAR = 33,                   /* LEFTPAR  */
  YYSYMBOL_RIGHTPAR = 34,                  /* RIGHTPAR  */
  YYSYMBOL_LEFTKEYS = 35,                  /* LEFTKEYS  */
  YYSYMBOL_RIGHTKEYS = 36,                 /* RIGHTKEYS  */
  YYSYMBOL_LEFTBRACKET = 37,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 38,              /* RIGHTBRACKET  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_DONE = 40,                      /* DONE  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program_globals = 42,           /* program_globals  */
  YYSYMBOL_program_global_list = 43,       /* program_global_list  */
  YYSYMBOL_program_global = 44,            /* program_global  */
  YYSYMBOL_program_locals = 45,            /* program_locals  */
  YYSYMBOL_program_local_list = 46,        /* program_local_list  */
  YYSYMBOL_program_local = 47,             /* program_local  */
  YYSYMBOL_function = 48,                  /* function  */
  YYSYMBOL_int_function = 49,              /* int_function  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_float_function = 52,            /* float_function  */
  YYSYMBOL_53_3 = 53,                      /* $@3  */
  YYSYMBOL_54_4 = 54,                      /* $@4  */
  YYSYMBOL_char_function = 55,             /* char_function  */
  YYSYMBOL_56_5 = 56,                      /* $@5  */
  YYSYMBOL_57_6 = 57,                      /* $@6  */
  YYSYMBOL_bool_function = 58,             /* bool_function  */
  YYSYMBOL_59_7 = 59,                      /* $@7  */
  YYSYMBOL_60_8 = 60,                      /* $@8  */
  YYSYMBOL_void_function = 61,             /* void_function  */
  YYSYMBOL_62_9 = 62,                      /* $@9  */
  YYSYMBOL_63_10 = 63,                     /* $@10  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_parameter_list = 65,            /* parameter_list  */
  YYSYMBOL_parameter = 66,                 /* parameter  */
  YYSYMBOL_declaration_global = 67,        /* declaration_global  */
  YYSYMBOL_int_declaration_globals = 68,   /* int_declaration_globals  */
  YYSYMBOL_int_declaration_global_list = 69, /* int_declaration_global_list  */
  YYSYMBOL_int_declaration_global = 70,    /* int_declaration_global  */
  YYSYMBOL_array = 71,                     /* array  */
  YYSYMBOL_float_declaration_globals = 72, /* float_declaration_globals  */
  YYSYMBOL_float_declaration_global_list = 73, /* float_declaration_global_list  */
  YYSYMBOL_float_declaration_global = 74,  /* float_declaration_global  */
  YYSYMBOL_char_declaration_globals = 75,  /* char_declaration_globals  */
  YYSYMBOL_char_declaration_global_list = 76, /* char_declaration_global_list  */
  YYSYMBOL_char_declaration_global = 77,   /* char_declaration_global  */
  YYSYMBOL_bool_declaration_globals = 78,  /* bool_declaration_globals  */
  YYSYMBOL_bool_declaration_global_list = 79, /* bool_declaration_global_list  */
  YYSYMBOL_bool_declaration_global = 80,   /* bool_declaration_global  */
  YYSYMBOL_array_values_global = 81,       /* array_values_global  */
  YYSYMBOL_term_const = 82,                /* term_const  */
  YYSYMBOL_declaration_local = 83,         /* declaration_local  */
  YYSYMBOL_int_declaration_local = 84,     /* int_declaration_local  */
  YYSYMBOL_intArray_declaration_local = 85, /* intArray_declaration_local  */
  YYSYMBOL_float_declaration_local = 86,   /* float_declaration_local  */
  YYSYMBOL_char_declaration_local = 87,    /* char_declaration_local  */
  YYSYMBOL_bool_declaration_local = 88,    /* bool_declaration_local  */
  YYSYMBOL_array_values_local = 89,        /* array_values_local  */
  YYSYMBOL_comand = 90,                    /* comand  */
  YYSYMBOL_assignment = 91,                /* assignment  */
  YYSYMBOL_if_statement = 92,              /* if_statement  */
  YYSYMBOL_93_11 = 93,                     /* $@11  */
  YYSYMBOL_94_12 = 94,                     /* $@12  */
  YYSYMBOL_else_if_chain = 95,             /* else_if_chain  */
  YYSYMBOL_96_13 = 96,                     /* $@13  */
  YYSYMBOL_97_14 = 97,                     /* $@14  */
  YYSYMBOL_98_15 = 98,                     /* $@15  */
  YYSYMBOL_while = 99,                     /* while  */
  YYSYMBOL_100_16 = 100,                   /* $@16  */
  YYSYMBOL_while_aux = 101,                /* while_aux  */
  YYSYMBOL_printf = 102,                   /* printf  */
  YYSYMBOL_scanf = 103,                    /* scanf  */
  YYSYMBOL_return = 104,                   /* return  */
  YYSYMBOL_expression = 105,               /* expression  */
  YYSYMBOL_soma_sub = 106,                 /* soma_sub  */
  YYSYMBOL_mult_div = 107,                 /* mult_div  */
  YYSYMBOL_comparison = 108,               /* comparison  */
  YYSYMBOL_log_exp = 109,                  /* log_exp  */
  YYSYMBOL_cast = 110,                     /* cast  */
  YYSYMBOL_call_function = 111,            /* call_function  */
  YYSYMBOL_call_parameters = 112,          /* call_parameters  */
  YYSYMBOL_call_parameter_list = 113,      /* call_parameter_list  */
  YYSYMBOL_term = 114                      /* term  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   646

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  371

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   107,   111,   112,   116,   117,   118,   123,
     124,   128,   129,   133,   134,   139,   140,   141,   142,   143,
     149,   151,   149,   184,   186,   184,   219,   221,   219,   254,
     256,   254,   290,   292,   290,   323,   324,   327,   328,   332,
     342,   352,   362,   376,   377,   378,   379,   383,   386,   387,
     390,   397,   404,   407,   421,   448,   451,   452,   455,   462,
     472,   475,   476,   479,   486,   496,   499,   500,   503,   510,
     521,   529,   538,   548,   557,   561,   581,   595,   617,   621,
     640,   644,   658,   662,   680,   681,   685,   709,   710,   724,
     749,   750,   754,   776,   777,   781,   798,   799,   803,   821,
     829,   836,   837,   838,   839,   840,   841,   842,   847,   892,
     924,   944,   924,   964,   968,   971,   971,   985,  1006,   985,
    1021,  1021,  1043,  1058,  1099,  1123,  1141,  1175,  1186,  1197,
    1198,  1199,  1200,  1201,  1202,  1203,  1204,  1208,  1230,  1255,
    1277,  1308,  1330,  1352,  1374,  1396,  1422,  1450,  1461,  1472,
    1486,  1492,  1498,  1503,  1508,  1513,  1518,  1525,  1536,  1581,
    1582,  1590,  1591,  1599,  1609,  1636,  1668
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "ELSEIF",
  "INT", "CHAR", "FLOAT", "BOOL", "PRINTF", "SCANF", "WHILE", "VOID",
  "RETURN", "NUMBER", "ID", "STRING", "CARACTERE", "RECEIVE", "EQUAL",
  "NEQUAL", "LESS", "GREAT", "LEQUAL", "GEQUAL", "AND", "OR", "NOT",
  "PLUS", "MIN", "MULT", "DIV", "LEFTPAR", "RIGHTPAR", "LEFTKEYS",
  "RIGHTKEYS", "LEFTBRACKET", "RIGHTBRACKET", "COMMA", "DONE", "$accept",
  "program_globals", "program_global_list", "program_global",
  "program_locals", "program_local_list", "program_local", "function",
  "int_function", "$@1", "$@2", "float_function", "$@3", "$@4",
  "char_function", "$@5", "$@6", "bool_function", "$@7", "$@8",
  "void_function", "$@9", "$@10", "parameters", "parameter_list",
  "parameter", "declaration_global", "int_declaration_globals",
  "int_declaration_global_list", "int_declaration_global", "array",
  "float_declaration_globals", "float_declaration_global_list",
  "float_declaration_global", "char_declaration_globals",
  "char_declaration_global_list", "char_declaration_global",
  "bool_declaration_globals", "bool_declaration_global_list",
  "bool_declaration_global", "array_values_global", "term_const",
  "declaration_local", "int_declaration_local",
  "intArray_declaration_local", "float_declaration_local",
  "char_declaration_local", "bool_declaration_local", "array_values_local",
  "comand", "assignment", "if_statement", "$@11", "$@12", "else_if_chain",
  "$@13", "$@14", "$@15", "while", "$@16", "while_aux", "printf", "scanf",
  "return", "expression", "soma_sub", "mult_div", "comparison", "log_exp",
  "cast", "call_function", "call_parameters", "call_parameter_list",
  "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-326)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-74)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     571,  -326,    -5,    26,    30,    54,    91,   132,   581,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
      92,    96,  -326,    76,   102,    89,   104,   148,   108,   131,
    -326,  -326,   581,    81,  -326,    81,   150,   128,    81,  -326,
     161,   130,    81,  -326,   168,   146,    81,  -326,   174,   152,
    -326,  -326,  -326,  -326,  -326,   195,   185,   120,    96,  -326,
    -326,   195,   175,   102,  -326,  -326,   195,   179,   104,  -326,
    -326,   195,   206,   108,  -326,   195,   214,   221,   224,   226,
    -326,   193,   225,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,   209,   195,  -326,   211,   228,
     229,   230,   231,   241,   193,   103,   246,   247,   249,   250,
     554,  -326,   260,     7,   265,   112,    82,   266,  -326,   222,
     575,  -326,  -326,  -326,  -326,  -326,  -326,  -326,   554,   554,
     554,   554,   233,   244,   267,   270,   287,   271,   272,  -326,
      10,   154,   280,   554,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,   281,    33,   112,  -326,  -326,  -326,   289,   290,
     291,   292,   404,  -326,   103,   112,   112,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   286,   300,   305,
     306,   112,    34,    -9,     8,    13,   219,   327,   273,  -326,
     129,   112,   112,  -326,  -326,   554,  -326,   307,   311,   317,
     328,   147,   156,   160,   181,  -326,  -326,   575,   601,   601,
     601,   601,   601,   601,   614,   588,   106,   106,  -326,  -326,
    -326,  -326,  -326,  -326,   419,   112,   112,   330,   321,   112,
     346,   323,   112,   348,   325,   112,   359,   340,   349,   350,
     360,   365,   112,  -326,   186,   347,  -326,  -326,    33,  -326,
    -326,   112,  -326,   112,  -326,   112,  -326,   112,  -326,  -326,
     248,   366,    35,  -326,   268,    62,  -326,   288,    65,  -326,
     308,    73,  -326,   341,   342,   361,   362,   434,  -326,   381,
     317,   449,   464,   479,   494,   368,   373,    74,   112,  -326,
     378,   112,  -326,   379,   112,  -326,   380,   112,  -326,  -326,
    -326,  -326,  -326,  -326,   112,  -326,  -326,  -326,  -326,  -326,
     554,  -326,   386,   406,   392,   248,  -326,   268,  -326,   288,
    -326,   308,   402,   227,   411,   112,   415,  -326,  -326,  -326,
    -326,  -326,   554,  -326,  -326,    66,   112,   426,   216,   428,
     112,   385,  -326,   444,   459,  -326,   442,    75,   112,   462,
     112,  -326,   472,  -326,   509,   554,   524,   112,  -326,   476,
    -326,    67,  -326,   487,   428,   554,  -326,   491,  -326,   216,
    -326
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     0,     0,     0,     0,     0,     0,     0,     6,
      15,    16,    17,    18,    19,     7,    43,    44,    45,    46,
      50,    48,    52,    63,    61,    58,    56,    68,    66,     0,
       1,     3,     0,     0,    20,     0,     0,     0,     0,    26,
       0,     0,     0,    23,     0,     0,     0,    29,     0,     0,
      32,     5,    72,    73,    51,    35,     0,    50,    48,    47,
      64,    35,    63,    61,    60,    59,    35,    58,    56,    55,
      69,    35,    68,    66,    65,    35,     0,     0,     0,     0,
      21,    37,    53,    49,    27,    62,    24,    57,    30,    67,
      33,    39,    41,    40,    42,     0,     0,    36,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       9,    38,   163,   164,   166,     0,     0,     0,    70,     0,
      99,   129,   130,   132,   133,   134,   135,   136,     9,     9,
       9,     9,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,    11,    14,    13,   101,   102,   103,   104,
     105,   106,     0,   159,     0,   163,   166,   149,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    84,    93,    90,    96,     0,     0,     0,   128,
       0,     0,     0,    22,    10,    11,   107,   164,     0,   161,
       0,     0,     0,     0,     0,   131,    71,   100,   145,   146,
     141,   142,   143,   144,   147,   148,   137,   138,   139,   140,
      28,    25,    31,    34,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,    12,   158,     0,   160,
     165,     0,   151,     0,   155,     0,   153,     0,   157,   110,
      84,     0,    84,    74,    93,    93,    80,    90,    90,    78,
      96,    96,    82,     0,     0,     0,     0,     0,   108,     0,
     161,     0,     0,     0,     0,     0,     0,    87,     0,    85,
       0,     0,    94,     0,     0,    91,     0,     0,    97,   124,
     123,   125,   126,   120,     0,   162,   150,   154,   152,   156,
       9,    75,     0,     0,     0,    84,    81,    93,    79,    90,
      83,    96,     0,     0,     0,     0,     0,    76,    86,    95,
      92,    98,     9,   109,   111,     0,     0,     0,   113,    87,
       0,     0,   121,   115,     0,   112,     0,    87,     0,     0,
       0,    77,     0,    88,     0,     9,     0,     0,   114,     0,
     117,     0,   116,     0,    87,     9,    89,     0,   118,   113,
     119
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -326,  -326,   505,   542,  -127,   357,  -126,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,   158,   455,   471,  -326,  -326,   511,   537,
    -326,  -326,   506,   531,  -326,   513,   543,  -326,   512,   538,
    -326,   -30,  -326,  -247,  -325,  -233,  -241,  -234,  -316,  -326,
    -326,  -326,  -326,  -326,   223,  -326,  -326,  -326,  -326,  -326,
    -326,  -326,  -326,  -326,  -109,  -326,  -326,  -326,  -326,  -326,
    -110,  -326,   313,  -124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,    31,    32,   142,   194,   143,     9,    10,    55,
      95,    11,    66,   100,    12,    61,    99,    13,    71,   101,
      14,    75,   102,    80,    97,    81,    15,    16,    37,    21,
      22,    17,    45,    26,    18,    41,    24,    19,    49,    28,
     117,    54,   144,   228,   314,   234,   231,   237,   119,   145,
     146,   147,   285,   338,   345,   349,   363,   369,   148,   322,
     188,   149,   150,   151,   120,   121,   122,   123,   124,   125,
     126,   198,   249,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     152,   177,   178,   179,   180,    56,   157,   162,    60,   335,
     229,    20,    65,   286,   346,   289,    70,   195,   152,   152,
     152,   152,   353,   290,   292,   155,   113,   232,   156,   199,
     230,   190,   235,   152,   293,   295,   296,   298,   115,   366,
     153,   361,    23,   116,   154,   200,    25,   233,   155,   197,
     189,   156,   236,   225,   288,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   328,   195,
      27,   226,   224,   227,   227,   118,   329,   252,   254,   256,
     258,   291,   244,   245,   294,   152,   330,   331,   158,   159,
     160,   161,   297,   312,   352,    38,    52,   155,   113,    53,
     156,   230,   339,   364,   233,   340,   340,    29,    42,    39,
     115,    33,   236,   313,   313,   116,   260,   261,   112,   113,
     264,   114,    43,   267,   280,    34,   270,   155,   113,    35,
     156,   115,    30,   277,   206,    36,   116,   175,   176,    33,
     115,    40,   281,    44,   282,   116,   283,    48,   284,   165,
     166,   167,   168,   169,   170,   171,   172,    35,   173,   174,
     175,   176,   155,   197,    50,   156,    57,    46,    59,   243,
      64,   155,   197,   191,   156,   155,   197,    62,   156,   315,
     251,    47,   317,   324,    67,   319,    69,   153,   321,   253,
      72,   192,    74,   255,    38,   323,   155,   197,    42,   156,
     152,    76,    77,    78,    79,   337,   165,   166,   167,   168,
     169,   170,   171,   172,   257,   173,   174,   175,   176,    84,
     343,   344,   152,    82,    86,    46,   278,   341,   359,    88,
      91,   207,    96,    90,   238,   239,   240,    92,   367,   354,
      93,   356,    94,   103,    98,   152,   105,   165,   166,   167,
     168,   169,   170,   171,   172,   152,   173,   174,   175,   176,
     182,   164,   106,   107,   108,   109,   181,   333,   165,   166,
     167,   168,   169,   170,   171,   172,   110,   173,   174,   175,
     176,   128,   129,   183,   130,   131,   184,   227,   165,   166,
     167,   168,   169,   170,   171,   172,   -72,   173,   174,   175,
     176,   -73,   163,   185,   186,   187,   242,   230,   165,   166,
     167,   168,   169,   170,   171,   172,   193,   173,   174,   175,
     176,   196,   220,   201,   202,   203,   204,   233,   165,   166,
     167,   168,   169,   170,   171,   172,   221,   173,   174,   175,
     176,   222,   223,   241,   154,   247,   262,   236,   165,   166,
     167,   168,   169,   170,   171,   172,   248,   173,   174,   175,
     176,   263,   265,   266,   268,   269,   250,   165,   166,   167,
     168,   169,   170,   171,   172,   271,   173,   174,   175,   176,
     272,   299,   300,   273,   274,   279,   165,   166,   167,   168,
     169,   170,   171,   172,   275,   173,   174,   175,   176,   276,
     304,   301,   302,   310,   287,   165,   166,   167,   168,   169,
     170,   171,   172,   311,   173,   174,   175,   176,   316,   318,
     320,   325,   326,   347,   165,   166,   167,   168,   169,   170,
     171,   172,   327,   173,   174,   175,   176,   332,   205,   165,
     166,   167,   168,   169,   170,   171,   172,   334,   173,   174,
     175,   176,   336,   259,   165,   166,   167,   168,   169,   170,
     171,   172,   342,   173,   174,   175,   176,   313,   303,   165,
     166,   167,   168,   169,   170,   171,   172,   348,   173,   174,
     175,   176,   351,   306,   165,   166,   167,   168,   169,   170,
     171,   172,   350,   173,   174,   175,   176,   355,   307,   165,
     166,   167,   168,   169,   170,   171,   172,   357,   173,   174,
     175,   176,   362,   308,   165,   166,   167,   168,   169,   170,
     171,   172,   365,   173,   174,   175,   176,   368,   309,   165,
     166,   167,   168,   169,   170,   171,   172,    51,   173,   174,
     175,   176,     8,   358,   165,   166,   167,   168,   169,   170,
     171,   172,   246,   173,   174,   175,   176,   132,   360,   111,
     133,   134,   135,   136,   137,   138,   139,   104,   140,    83,
     141,    -2,     1,    58,    87,    68,    85,     2,     3,     4,
       5,    -4,     1,    63,     6,    89,    73,     2,     3,     4,
       5,     0,   370,   305,     6,   165,   166,   167,   168,   169,
     170,   171,   172,     0,   173,   174,   175,   176,   165,   166,
     167,   168,   169,   170,   171,     0,     0,   173,   174,   175,
     176,   -74,   -74,   -74,   -74,   -74,   -74,     0,     0,     0,
     173,   174,   175,   176,   165,   166,   167,   168,   169,   170,
       0,     0,     0,   173,   174,   175,   176
};

static const yytype_int16 yycheck[] =
{
     110,   128,   129,   130,   131,    35,   115,   116,    38,   325,
      19,    16,    42,   260,   339,   262,    46,   143,   128,   129,
     130,   131,   347,   264,   265,    15,    16,    19,    18,   153,
      39,   140,    19,   143,   267,   268,   270,   271,    28,   364,
      33,   357,    16,    33,    37,   154,    16,    39,    15,    16,
      40,    18,    39,    19,    19,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   315,   195,
      16,    37,   181,    39,    39,   105,   317,   201,   202,   203,
     204,    19,   191,   192,    19,   195,   319,   321,     6,     7,
       8,     9,    19,    19,    19,    19,    15,    15,    16,    18,
      18,    39,    36,    36,    39,    39,    39,    16,    19,    33,
      28,    19,    39,    39,    39,    33,   225,   226,    15,    16,
     229,    18,    33,   232,   248,    33,   235,    15,    16,    37,
      18,    28,     0,   242,   164,    39,    33,    31,    32,    19,
      28,    39,   251,    39,   253,    33,   255,    39,   257,    20,
      21,    22,    23,    24,    25,    26,    27,    37,    29,    30,
      31,    32,    15,    16,    33,    18,    16,    19,    40,    40,
      40,    15,    16,    19,    18,    15,    16,    16,    18,   288,
      33,    33,   291,   310,    16,   294,    40,    33,   297,    33,
      16,    37,    40,    33,    19,   304,    15,    16,    19,    18,
     310,     6,     7,     8,     9,   332,    20,    21,    22,    23,
      24,    25,    26,    27,    33,    29,    30,    31,    32,    61,
       4,     5,   332,    38,    66,    19,    40,   336,   355,    71,
      16,   340,    39,    75,    15,    16,    17,    16,   365,   348,
      16,   350,    16,    34,    19,   355,    35,    20,    21,    22,
      23,    24,    25,    26,    27,   365,    29,    30,    31,    32,
      16,    39,    34,    34,    34,    34,    33,    40,    20,    21,
      22,    23,    24,    25,    26,    27,    35,    29,    30,    31,
      32,    35,    35,    16,    35,    35,    16,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    36,    29,    30,    31,
      32,    36,    36,    16,    33,    33,    33,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    36,    29,    30,    31,
      32,    40,    36,    34,    34,    34,    34,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    36,    29,    30,    31,
      32,    36,    36,    16,    37,    34,    16,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    39,    29,    30,    31,
      32,    40,    16,    40,    16,    40,    38,    20,    21,    22,
      23,    24,    25,    26,    27,    16,    29,    30,    31,    32,
      40,    40,    40,    34,    34,    38,    20,    21,    22,    23,
      24,    25,    26,    27,    34,    29,    30,    31,    32,    34,
      19,    40,    40,    35,    38,    20,    21,    22,    23,    24,
      25,    26,    27,    40,    29,    30,    31,    32,    40,    40,
      40,    35,    16,    38,    20,    21,    22,    23,    24,    25,
      26,    27,    40,    29,    30,    31,    32,    35,    34,    20,
      21,    22,    23,    24,    25,    26,    27,    36,    29,    30,
      31,    32,    37,    34,    20,    21,    22,    23,    24,    25,
      26,    27,    36,    29,    30,    31,    32,    39,    34,    20,
      21,    22,    23,    24,    25,    26,    27,    33,    29,    30,
      31,    32,    40,    34,    20,    21,    22,    23,    24,    25,
      26,    27,    33,    29,    30,    31,    32,    35,    34,    20,
      21,    22,    23,    24,    25,    26,    27,    35,    29,    30,
      31,    32,    36,    34,    20,    21,    22,    23,    24,    25,
      26,    27,    35,    29,    30,    31,    32,    36,    34,    20,
      21,    22,    23,    24,    25,    26,    27,    32,    29,    30,
      31,    32,     0,    34,    20,    21,    22,    23,    24,    25,
      26,    27,   195,    29,    30,    31,    32,     3,    34,   104,
       6,     7,     8,     9,    10,    11,    12,    96,    14,    58,
      16,     0,     1,    36,    68,    44,    63,     6,     7,     8,
       9,     0,     1,    40,    13,    73,    48,     6,     7,     8,
       9,    -1,   369,   280,    13,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    32,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      29,    30,    31,    32,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,     7,     8,     9,    13,    42,    44,    48,
      49,    52,    55,    58,    61,    67,    68,    72,    75,    78,
      16,    70,    71,    16,    77,    16,    74,    16,    80,    16,
       0,    43,    44,    19,    33,    37,    39,    69,    19,    33,
      39,    76,    19,    33,    39,    73,    19,    33,    39,    79,
      33,    43,    15,    18,    82,    50,    82,    16,    70,    40,
      82,    56,    16,    77,    40,    82,    53,    16,    74,    40,
      82,    59,    16,    80,    40,    62,     6,     7,     8,     9,
      64,    66,    38,    69,    64,    76,    64,    73,    64,    79,
      64,    16,    16,    16,    16,    51,    39,    65,    19,    57,
      54,    60,    63,    34,    66,    35,    34,    34,    34,    34,
      35,    65,    15,    16,    18,    28,    33,    81,    82,    89,
     105,   106,   107,   108,   109,   110,   111,   114,    35,    35,
      35,    35,     3,     6,     7,     8,     9,    10,    11,    12,
      14,    16,    45,    47,    83,    90,    91,    92,    99,   102,
     103,   104,   111,    33,    37,    15,    18,   105,     6,     7,
       8,     9,   105,    36,    39,    20,    21,    22,    23,    24,
      25,    26,    27,    29,    30,    31,    32,    45,    45,    45,
      45,    33,    16,    16,    16,    16,    33,    33,   101,    40,
     105,    19,    37,    36,    46,    47,    40,    16,   112,   114,
     105,    34,    34,    34,    34,    34,    82,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
      36,    36,    36,    36,   105,    19,    37,    39,    84,    19,
      39,    87,    19,    39,    86,    19,    39,    88,    15,    16,
      17,    16,    33,    40,   105,   105,    46,    34,    39,   113,
      38,    33,   114,    33,   114,    33,   114,    33,   114,    34,
     105,   105,    16,    40,   105,    16,    40,   105,    16,    40,
     105,    16,    40,    34,    34,    34,    34,   105,    40,    38,
     114,   105,   105,   105,   105,    93,    84,    38,    19,    84,
      87,    19,    87,    86,    19,    86,    88,    19,    88,    40,
      40,    40,    40,    34,    19,   113,    34,    34,    34,    34,
      35,    40,    19,    39,    85,   105,    40,   105,    40,   105,
      40,   105,   100,   105,    45,    35,    16,    40,    84,    87,
      86,    88,    35,    40,    36,    89,    37,    45,    94,    36,
      39,   105,    36,     4,     5,    95,    85,    38,    33,    96,
      33,    40,    19,    85,   105,    35,   105,    35,    34,    45,
      34,    89,    36,    97,    36,    35,    85,    45,    36,    98,
      95
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    48,    48,    48,    48,
      50,    51,    49,    53,    54,    52,    56,    57,    55,    59,
      60,    58,    62,    63,    61,    64,    64,    65,    65,    66,
      66,    66,    66,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    84,    85,    85,    85,
      86,    86,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      93,    94,    92,    95,    95,    96,    95,    97,    98,    95,
     100,    99,   101,   102,   102,   102,   103,   104,   104,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   108,   108,   108,   109,   109,   109,
     110,   110,   110,   110,   110,   110,   110,   110,   111,   112,
     112,   113,   113,   114,   114,   114,   114
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     0,    10,     0,     0,    10,     0,     0,    10,     0,
       0,    10,     0,     0,    10,     0,     2,     0,     3,     2,
       2,     2,     2,     1,     1,     1,     1,     4,     0,     3,
       1,     3,     1,     4,     8,     4,     0,     3,     1,     3,
       4,     0,     3,     1,     3,     4,     0,     3,     1,     3,
       1,     3,     1,     1,     4,     6,     7,    11,     4,     6,
       4,     6,     4,     6,     0,     3,     5,     0,     6,    10,
       0,     3,     5,     0,     3,     5,     0,     3,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     4,     7,
       0,     0,    10,     0,     4,     0,     5,     0,     0,    10,
       0,     9,     0,     5,     5,     5,     5,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       6,     4,     6,     4,     6,     4,     6,     4,     4,     0,
       2,     0,     3,     1,     1,     4,     1
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
  case 2: /* program_globals: %empty  */
#line 106 "compiler/parser.y"
                  {}
#line 1790 "objects/parser.tab.c"
    break;

  case 3: /* program_globals: program_global program_global_list  */
#line 107 "compiler/parser.y"
                                         {}
#line 1796 "objects/parser.tab.c"
    break;

  case 4: /* program_global_list: %empty  */
#line 111 "compiler/parser.y"
                  {}
#line 1802 "objects/parser.tab.c"
    break;

  case 5: /* program_global_list: program_global program_global_list  */
#line 112 "compiler/parser.y"
                                         {}
#line 1808 "objects/parser.tab.c"
    break;

  case 6: /* program_global: function  */
#line 116 "compiler/parser.y"
               {}
#line 1814 "objects/parser.tab.c"
    break;

  case 7: /* program_global: declaration_global  */
#line 117 "compiler/parser.y"
                         {}
#line 1820 "objects/parser.tab.c"
    break;

  case 8: /* program_global: error  */
#line 118 "compiler/parser.y"
            { yyerrok; yyclearin; }
#line 1826 "objects/parser.tab.c"
    break;

  case 9: /* program_locals: %empty  */
#line 123 "compiler/parser.y"
                  {}
#line 1832 "objects/parser.tab.c"
    break;

  case 10: /* program_locals: program_local program_local_list  */
#line 124 "compiler/parser.y"
                                       {}
#line 1838 "objects/parser.tab.c"
    break;

  case 11: /* program_local_list: %empty  */
#line 128 "compiler/parser.y"
                  {}
#line 1844 "objects/parser.tab.c"
    break;

  case 12: /* program_local_list: program_local program_local_list  */
#line 129 "compiler/parser.y"
                                       {}
#line 1850 "objects/parser.tab.c"
    break;

  case 13: /* program_local: comand  */
#line 133 "compiler/parser.y"
             {}
#line 1856 "objects/parser.tab.c"
    break;

  case 14: /* program_local: declaration_local  */
#line 134 "compiler/parser.y"
                        {}
#line 1862 "objects/parser.tab.c"
    break;

  case 15: /* function: int_function  */
#line 139 "compiler/parser.y"
                   {}
#line 1868 "objects/parser.tab.c"
    break;

  case 16: /* function: float_function  */
#line 140 "compiler/parser.y"
                     {}
#line 1874 "objects/parser.tab.c"
    break;

  case 17: /* function: char_function  */
#line 141 "compiler/parser.y"
                    {}
#line 1880 "objects/parser.tab.c"
    break;

  case 18: /* function: bool_function  */
#line 142 "compiler/parser.y"
                    {}
#line 1886 "objects/parser.tab.c"
    break;

  case 19: /* function: void_function  */
#line 143 "compiler/parser.y"
                    {}
#line 1892 "objects/parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 149 "compiler/parser.y"
                     {
        pushScope();
    }
#line 1900 "objects/parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 151 "compiler/parser.y"
                 {
        
        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt32TypeInContext(context), // tipo de retorno int
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, (yyvsp[-3].id), func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol((yyvsp[-3].id), TYPE_INT, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
    }
#line 1933 "objects/parser.tab.c"
    break;

  case 22: /* int_function: INT ID LEFTPAR $@1 parameters $@2 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 178 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1941 "objects/parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 184 "compiler/parser.y"
                       {
            pushScope();
        }
#line 1949 "objects/parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 186 "compiler/parser.y"
                     {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMDoubleTypeInContext(context), // tipo de retorno float
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, (yyvsp[-3].id), func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol((yyvsp[-3].id), TYPE_FLOAT, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
    }
#line 1982 "objects/parser.tab.c"
    break;

  case 25: /* float_function: FLOAT ID LEFTPAR $@3 parameters $@4 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 213 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1990 "objects/parser.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 219 "compiler/parser.y"
                      {
        pushScope();
    }
#line 1998 "objects/parser.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 221 "compiler/parser.y"
                 {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt8TypeInContext(context), // tipo de retorno char
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, (yyvsp[-3].id), func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol((yyvsp[-3].id), TYPE_CHAR, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
    }
#line 2031 "objects/parser.tab.c"
    break;

  case 28: /* char_function: CHAR ID LEFTPAR $@5 parameters $@6 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 248 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2039 "objects/parser.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 254 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2047 "objects/parser.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 256 "compiler/parser.y"
                 {

        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMInt1TypeInContext(context), // tipo de retorno bool
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, (yyvsp[-3].id), func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol((yyvsp[-3].id), TYPE_BOOL, param_count, param_types);

        // Limpa as variáveis de parâmetros para a próxima função
        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
        
    }
#line 2080 "objects/parser.tab.c"
    break;

  case 31: /* bool_function: BOOL ID LEFTPAR $@7 parameters $@8 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 283 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2088 "objects/parser.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 290 "compiler/parser.y"
                      {
            pushScope();
    }
#line 2096 "objects/parser.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 292 "compiler/parser.y"
                 {
        LLVMTypeRef func_type = LLVMFunctionType(
            LLVMVoidTypeInContext(context), // tipo de retorno void
            param_typesLLVM, param_count, 0
        );
        LLVMValueRef func = LLVMAddFunction(module, (yyvsp[-3].id), func_type);
        LLVMBasicBlockRef entryBB = LLVMAppendBasicBlockInContext(context, func, "entry");
        LLVMPositionBuilderAtEnd(builder, entryBB);
        currentFunc = func; // Atualize currentFunc para a função atual

        for (int i = 0; i < param_count; i++) {
            LLVMValueRef param = LLVMGetParam(func, i);
            LLVMValueRef var = allocaVars(param_names[i], param_types[i]);
            LLVMBuildStore(builder, param, var);
        }

        insertFunctionSymbol((yyvsp[-3].id), TYPE_VOID, param_count, param_types);

        for (int i = 0; i < MAX_PARAMS; i++) {
            param_names[i] = NULL;
            param_typesLLVM[i] = NULL;
            param_types[i] = 0;
        }
        param_count = 0;
    }
#line 2126 "objects/parser.tab.c"
    break;

  case 34: /* void_function: VOID ID LEFTPAR $@9 parameters $@10 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 316 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2134 "objects/parser.tab.c"
    break;

  case 36: /* parameters: parameter parameter_list  */
#line 324 "compiler/parser.y"
                               {}
#line 2140 "objects/parser.tab.c"
    break;

  case 38: /* parameter_list: COMMA parameter parameter_list  */
#line 328 "compiler/parser.y"
                                     {}
#line 2146 "objects/parser.tab.c"
    break;

  case 39: /* parameter: INT ID  */
#line 332 "compiler/parser.y"
             {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = (yyvsp[0].id);
            param_types[param_count] = TYPE_INT;
            param_typesLLVM[param_count++] = LLVMInt32TypeInContext(context);
            insertSymbol((yyvsp[0].id), 0.0, TYPE_INT);
        }
    }
#line 2161 "objects/parser.tab.c"
    break;

  case 40: /* parameter: FLOAT ID  */
#line 342 "compiler/parser.y"
               {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = (yyvsp[0].id);
            param_types[param_count] = TYPE_FLOAT;
            param_typesLLVM[param_count++] = LLVMDoubleTypeInContext(context);
            insertSymbol((yyvsp[0].id), 0.0, TYPE_FLOAT);
        }
    }
#line 2176 "objects/parser.tab.c"
    break;

  case 41: /* parameter: CHAR ID  */
#line 352 "compiler/parser.y"
              {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = (yyvsp[0].id);
            param_types[param_count] = TYPE_CHAR;
            param_typesLLVM[param_count++] = LLVMInt8TypeInContext(context);
            insertSymbol((yyvsp[0].id), 0.0, TYPE_CHAR);
        }
    }
#line 2191 "objects/parser.tab.c"
    break;

  case 42: /* parameter: BOOL ID  */
#line 362 "compiler/parser.y"
              {
        if (param_count >= MAX_PARAMS) {
            fprintf(stderr, "Error: too many parameters at line %d.\n", yylineno);
        } else {
            param_names[param_count] = (yyvsp[0].id);
            param_types[param_count] = TYPE_BOOL;
            param_typesLLVM[param_count++] = LLVMInt1TypeInContext(context);
            insertSymbol((yyvsp[0].id), 0.0, TYPE_BOOL);
        }
}
#line 2206 "objects/parser.tab.c"
    break;

  case 43: /* declaration_global: int_declaration_globals  */
#line 376 "compiler/parser.y"
                              {}
#line 2212 "objects/parser.tab.c"
    break;

  case 44: /* declaration_global: float_declaration_globals  */
#line 377 "compiler/parser.y"
                                {}
#line 2218 "objects/parser.tab.c"
    break;

  case 45: /* declaration_global: char_declaration_globals  */
#line 378 "compiler/parser.y"
                               {}
#line 2224 "objects/parser.tab.c"
    break;

  case 46: /* declaration_global: bool_declaration_globals  */
#line 379 "compiler/parser.y"
                               {}
#line 2230 "objects/parser.tab.c"
    break;

  case 47: /* int_declaration_globals: INT int_declaration_global int_declaration_global_list DONE  */
#line 383 "compiler/parser.y"
                                                                  {}
#line 2236 "objects/parser.tab.c"
    break;

  case 50: /* int_declaration_global: ID  */
#line 390 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2248 "objects/parser.tab.c"
    break;

  case 51: /* int_declaration_global: ID RECEIVE term_const  */
#line 397 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2260 "objects/parser.tab.c"
    break;

  case 52: /* int_declaration_global: array  */
#line 404 "compiler/parser.y"
            {}
#line 2266 "objects/parser.tab.c"
    break;

  case 53: /* array: ID LEFTBRACKET term_const RIGHTBRACKET  */
#line 407 "compiler/parser.y"
                                             {
        // Declaração de vetor
        int size = (int)(yyvsp[-1].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else {
            double valores[size];
            for (int i = 0; i < size; i++) {
                valores[i] = -DBL_MAX; // Inicializa com valor padrão
            }
            createArraySymbol((yyvsp[-3].id), valores, size);
            allocaArrayVars((yyvsp[-3].id), TYPE_INT, size);
        }
    }
#line 2285 "objects/parser.tab.c"
    break;

  case 54: /* array: ID LEFTBRACKET term_const RIGHTBRACKET RECEIVE LEFTKEYS array_values_global RIGHTKEYS  */
#line 421 "compiler/parser.y"
                                                                                            {
        int size = (int)(yyvsp[-5].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else if (array_value_count != size) {
            fprintf(stderr, "Error: number of initializers (%d) does not match array size (%d) at line %d.\n", array_value_count, size, yylineno);
        } else {
            createArraySymbol((yyvsp[-7].id), vals, size);
            allocaArrayVars((yyvsp[-7].id), TYPE_INT, size);
            LLVMValueRef var = getVarLLVM((yyvsp[-7].id));
            for (int i = 0; i < size; i++) {
                LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), i, 0);
                LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
                LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var, indices, 2, "");
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
#line 2312 "objects/parser.tab.c"
    break;

  case 55: /* float_declaration_globals: FLOAT float_declaration_global float_declaration_global_list DONE  */
#line 448 "compiler/parser.y"
                                                                        {}
#line 2318 "objects/parser.tab.c"
    break;

  case 58: /* float_declaration_global: ID  */
#line 455 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstReal(type, 0.0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2330 "objects/parser.tab.c"
    break;

  case 59: /* float_declaration_global: ID RECEIVE term_const  */
#line 462 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2342 "objects/parser.tab.c"
    break;

  case 60: /* char_declaration_globals: CHAR char_declaration_global char_declaration_global_list DONE  */
#line 472 "compiler/parser.y"
                                                                     {}
#line 2348 "objects/parser.tab.c"
    break;

  case 61: /* char_declaration_global_list: %empty  */
#line 475 "compiler/parser.y"
                  {}
#line 2354 "objects/parser.tab.c"
    break;

  case 62: /* char_declaration_global_list: COMMA char_declaration_global char_declaration_global_list  */
#line 476 "compiler/parser.y"
                                                                 {}
#line 2360 "objects/parser.tab.c"
    break;

  case 63: /* char_declaration_global: ID  */
#line 479 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2372 "objects/parser.tab.c"
    break;

  case 64: /* char_declaration_global: ID RECEIVE term_const  */
#line 486 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2384 "objects/parser.tab.c"
    break;

  case 65: /* bool_declaration_globals: BOOL bool_declaration_global bool_declaration_global_list DONE  */
#line 496 "compiler/parser.y"
                                                                     {}
#line 2390 "objects/parser.tab.c"
    break;

  case 66: /* bool_declaration_global_list: %empty  */
#line 499 "compiler/parser.y"
                  {}
#line 2396 "objects/parser.tab.c"
    break;

  case 67: /* bool_declaration_global_list: COMMA bool_declaration_global bool_declaration_global_list  */
#line 500 "compiler/parser.y"
                                                                 {}
#line 2402 "objects/parser.tab.c"
    break;

  case 68: /* bool_declaration_global: ID  */
#line 503 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2414 "objects/parser.tab.c"
    break;

  case 69: /* bool_declaration_global: ID RECEIVE term_const  */
#line 510 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2426 "objects/parser.tab.c"
    break;

  case 70: /* array_values_global: term_const  */
#line 521 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2439 "objects/parser.tab.c"
    break;

  case 71: /* array_values_global: array_values_local COMMA term_const  */
#line 529 "compiler/parser.y"
                                          {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
    }
#line 2449 "objects/parser.tab.c"
    break;

  case 72: /* term_const: NUMBER  */
#line 538 "compiler/parser.y"
             {
        (yyval.number).value = (yyvsp[0].number).value; 
        (yyval.number).type = (yyvsp[0].number).type; 
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:   (yyval.number).llvm_value = LLVMConstInt(LLVMInt32TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            case TYPE_FLOAT: (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
            case TYPE_BOOL:  (yyval.number).llvm_value = LLVMConstInt(LLVMInt1TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            default:         (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
        }
    }
#line 2464 "objects/parser.tab.c"
    break;

  case 73: /* term_const: CARACTERE  */
#line 548 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 2474 "objects/parser.tab.c"
    break;

  case 74: /* declaration_local: INT ID int_declaration_local DONE  */
#line 557 "compiler/parser.y"
                                        {
        insertSymbol((yyvsp[-2].id), -DBL_MAX, TYPE_INT);
        allocaVars((yyvsp[-2].id), TYPE_INT);
    }
#line 2483 "objects/parser.tab.c"
    break;

  case 75: /* declaration_local: INT ID RECEIVE expression int_declaration_local DONE  */
#line 561 "compiler/parser.y"
                                                           {
        insertSymbol((yyvsp[-4].id), (yyvsp[-2].number).value, TYPE_INT);
        allocaVars((yyvsp[-4].id), TYPE_INT);
        Symbol* symbol = findSymbol((yyvsp[-4].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-4].id));
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef value = (yyvsp[-2].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-2].number).type == TYPE_INT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[-2].number).type == TYPE_FLOAT) {
                printf("Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-4].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2508 "objects/parser.tab.c"
    break;

  case 76: /* declaration_local: INT ID LEFTBRACKET expression RIGHTBRACKET intArray_declaration_local DONE  */
#line 581 "compiler/parser.y"
                                                                                 {
        // Declaração de vetor
        int size = (int)(yyvsp[-3].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else {
            double valores[size];
            for (int i = 0; i < size; i++) {
                valores[i] = -DBL_MAX; // Inicializa com valor padrão
            }
            createArraySymbol((yyvsp[-5].id), valores, size);
            allocaArrayVars((yyvsp[-5].id), TYPE_INT, size);
        }
    }
#line 2527 "objects/parser.tab.c"
    break;

  case 77: /* declaration_local: INT ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS intArray_declaration_local DONE  */
#line 595 "compiler/parser.y"
                                                                                                                               {
        int size = (int)(yyvsp[-7].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else if (array_value_count != size) {
            fprintf(stderr, "Error: number of initializers (%d) does not match array size (%d) at line %d.\n", array_value_count, size, yylineno);
        } else {
            createArraySymbol((yyvsp[-9].id), vals, size);
            allocaArrayVars((yyvsp[-9].id), TYPE_INT, size);
            LLVMValueRef var = getVarLLVM((yyvsp[-9].id));
            for (int i = 0; i < size; i++) {
                LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), i, 0);
                LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
                LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var, indices, 2, "");
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
#line 2554 "objects/parser.tab.c"
    break;

  case 78: /* declaration_local: FLOAT ID float_declaration_local DONE  */
#line 617 "compiler/parser.y"
                                            {
        insertSymbol((yyvsp[-2].id), -DBL_MAX, TYPE_FLOAT);
        allocaVars((yyvsp[-2].id), TYPE_FLOAT);
    }
#line 2563 "objects/parser.tab.c"
    break;

  case 79: /* declaration_local: FLOAT ID RECEIVE expression float_declaration_local DONE  */
#line 621 "compiler/parser.y"
                                                               {
        insertSymbol((yyvsp[-4].id), (yyvsp[-2].number).value, TYPE_FLOAT);
        allocaVars((yyvsp[-4].id), TYPE_FLOAT);
        Symbol* symbol = findSymbol((yyvsp[-4].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-4].id));
        LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
        LLVMValueRef value = (yyvsp[-2].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-2].number).type == TYPE_FLOAT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[-2].number).type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2587 "objects/parser.tab.c"
    break;

  case 80: /* declaration_local: CHAR ID char_declaration_local DONE  */
#line 640 "compiler/parser.y"
                                          {
        insertSymbol((yyvsp[-2].id), -DBL_MAX, TYPE_CHAR);
        allocaVars((yyvsp[-2].id), TYPE_CHAR);
    }
#line 2596 "objects/parser.tab.c"
    break;

  case 81: /* declaration_local: CHAR ID RECEIVE expression char_declaration_local DONE  */
#line 644 "compiler/parser.y"
                                                             {
        insertSymbol((yyvsp[-4].id), (yyvsp[-2].number).value, TYPE_CHAR);
        allocaVars((yyvsp[-4].id), TYPE_CHAR);
        Symbol* symbol = findSymbol((yyvsp[-4].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-4].id));
        LLVMValueRef value = (yyvsp[-2].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-2].number).type == TYPE_CHAR) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2615 "objects/parser.tab.c"
    break;

  case 82: /* declaration_local: BOOL ID bool_declaration_local DONE  */
#line 658 "compiler/parser.y"
                                          {
        insertSymbol((yyvsp[-2].id), -DBL_MAX, TYPE_BOOL);
        allocaVars((yyvsp[-2].id), TYPE_BOOL);
    }
#line 2624 "objects/parser.tab.c"
    break;

  case 83: /* declaration_local: BOOL ID RECEIVE expression bool_declaration_local DONE  */
#line 662 "compiler/parser.y"
                                                             {
        insertSymbol((yyvsp[-4].id), (yyvsp[-2].number).value, TYPE_BOOL);
        allocaVars((yyvsp[-4].id), TYPE_BOOL);
        Symbol* symbol = findSymbol((yyvsp[-4].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-4].id));
        LLVMValueRef value = (yyvsp[-2].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-2].number).type == TYPE_BOOL) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2643 "objects/parser.tab.c"
    break;

  case 84: /* int_declaration_local: %empty  */
#line 680 "compiler/parser.y"
                  {}
#line 2649 "objects/parser.tab.c"
    break;

  case 85: /* int_declaration_local: COMMA ID int_declaration_local  */
#line 681 "compiler/parser.y"
                                     {
        insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_INT);
        allocaVars((yyvsp[-1].id), TYPE_INT);
    }
#line 2658 "objects/parser.tab.c"
    break;

  case 86: /* int_declaration_local: COMMA ID RECEIVE expression int_declaration_local  */
#line 685 "compiler/parser.y"
                                                        {
        insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, TYPE_INT);
        allocaVars((yyvsp[-3].id), TYPE_INT);
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef value = (yyvsp[-1].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-1].number).type == TYPE_INT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[-1].number).type == TYPE_FLOAT) {
                printf("Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2683 "objects/parser.tab.c"
    break;

  case 87: /* intArray_declaration_local: %empty  */
#line 709 "compiler/parser.y"
                  {}
#line 2689 "objects/parser.tab.c"
    break;

  case 88: /* intArray_declaration_local: COMMA ID LEFTBRACKET expression RIGHTBRACKET intArray_declaration_local  */
#line 710 "compiler/parser.y"
                                                                              {
        // Declaração de vetor
        int size = (int)(yyvsp[-2].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else {
            double valores[size];
            for (int i = 0; i < size; i++) {
                valores[i] = -DBL_MAX; // Inicializa com valor padrão
            }
            createArraySymbol((yyvsp[-4].id), valores, size);
            allocaArrayVars((yyvsp[-4].id), TYPE_INT, size);
        }
    }
#line 2708 "objects/parser.tab.c"
    break;

  case 89: /* intArray_declaration_local: COMMA ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS intArray_declaration_local  */
#line 724 "compiler/parser.y"
                                                                                                                            {
        int size = (int)(yyvsp[-6].number).value;
        if (size <= 0) {
            fprintf(stderr, "Error: array size must be positive at line %d.\n", yylineno);
        } else if (array_value_count != size) {
            fprintf(stderr, "Error: number of initializers (%d) does not match array size (%d) at line %d.\n", array_value_count, size, yylineno);
        } else {
            createArraySymbol((yyvsp[-8].id), vals, size);
            allocaArrayVars((yyvsp[-8].id), TYPE_INT, size);
            LLVMValueRef var = getVarLLVM((yyvsp[-8].id));
            for (int i = 0; i < size; i++) {
                LLVMValueRef idx = LLVMConstInt(LLVMInt32TypeInContext(context), i, 0);
                LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0), idx };
                LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var, indices, 2, "");
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
#line 2735 "objects/parser.tab.c"
    break;

  case 90: /* float_declaration_local: %empty  */
#line 749 "compiler/parser.y"
                  {}
#line 2741 "objects/parser.tab.c"
    break;

  case 91: /* float_declaration_local: COMMA ID float_declaration_local  */
#line 750 "compiler/parser.y"
                                       {
        insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_FLOAT);
        allocaVars((yyvsp[-1].id), TYPE_FLOAT);
    }
#line 2750 "objects/parser.tab.c"
    break;

  case 92: /* float_declaration_local: COMMA ID RECEIVE expression float_declaration_local  */
#line 754 "compiler/parser.y"
                                                          {
        insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, TYPE_FLOAT);
        allocaVars((yyvsp[-3].id), TYPE_FLOAT);
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
        LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
        LLVMValueRef value = (yyvsp[-1].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-1].number).type == TYPE_FLOAT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[-1].number).type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2774 "objects/parser.tab.c"
    break;

  case 93: /* char_declaration_local: %empty  */
#line 776 "compiler/parser.y"
                  {}
#line 2780 "objects/parser.tab.c"
    break;

  case 94: /* char_declaration_local: COMMA ID char_declaration_local  */
#line 777 "compiler/parser.y"
                                      {
        insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_CHAR);
        allocaVars((yyvsp[-1].id), TYPE_CHAR);
    }
#line 2789 "objects/parser.tab.c"
    break;

  case 95: /* char_declaration_local: COMMA ID RECEIVE expression char_declaration_local  */
#line 781 "compiler/parser.y"
                                                         {
        insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, TYPE_CHAR);
        allocaVars((yyvsp[-3].id), TYPE_CHAR);
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
        LLVMValueRef value = (yyvsp[-1].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-1].number).type == TYPE_CHAR) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2808 "objects/parser.tab.c"
    break;

  case 96: /* bool_declaration_local: %empty  */
#line 798 "compiler/parser.y"
                  {}
#line 2814 "objects/parser.tab.c"
    break;

  case 97: /* bool_declaration_local: COMMA ID bool_declaration_local  */
#line 799 "compiler/parser.y"
                                      {
        insertSymbol((yyvsp[-1].id), -DBL_MAX, TYPE_BOOL);
        allocaVars((yyvsp[-1].id), TYPE_BOOL);
    }
#line 2823 "objects/parser.tab.c"
    break;

  case 98: /* bool_declaration_local: COMMA ID RECEIVE expression bool_declaration_local  */
#line 803 "compiler/parser.y"
                                                         {
        insertSymbol((yyvsp[-3].id), (yyvsp[-1].number).value, TYPE_BOOL);
        allocaVars((yyvsp[-3].id), TYPE_BOOL);
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
        LLVMValueRef value = (yyvsp[-1].number).llvm_value;
        if(symbol) {
            if ((yyvsp[-1].number).type == TYPE_BOOL) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2842 "objects/parser.tab.c"
    break;

  case 99: /* array_values_local: expression  */
#line 821 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2855 "objects/parser.tab.c"
    break;

  case 100: /* array_values_local: array_values_local COMMA expression  */
#line 829 "compiler/parser.y"
                                          {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
}
#line 2865 "objects/parser.tab.c"
    break;

  case 101: /* comand: assignment  */
#line 836 "compiler/parser.y"
                   {}
#line 2871 "objects/parser.tab.c"
    break;

  case 102: /* comand: if_statement  */
#line 837 "compiler/parser.y"
                     {}
#line 2877 "objects/parser.tab.c"
    break;

  case 103: /* comand: while  */
#line 838 "compiler/parser.y"
              {}
#line 2883 "objects/parser.tab.c"
    break;

  case 104: /* comand: printf  */
#line 839 "compiler/parser.y"
               {}
#line 2889 "objects/parser.tab.c"
    break;

  case 105: /* comand: scanf  */
#line 840 "compiler/parser.y"
              {}
#line 2895 "objects/parser.tab.c"
    break;

  case 106: /* comand: return  */
#line 841 "compiler/parser.y"
               {}
#line 2901 "objects/parser.tab.c"
    break;

  case 107: /* comand: call_function DONE  */
#line 842 "compiler/parser.y"
                           {}
#line 2907 "objects/parser.tab.c"
    break;

  case 108: /* assignment: ID RECEIVE expression DONE  */
#line 847 "compiler/parser.y"
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
#line 2957 "objects/parser.tab.c"
    break;

  case 109: /* assignment: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE expression DONE  */
#line 892 "compiler/parser.y"
                                                                     {
        ArraySymbol* symbol = findArraySymbol((yyvsp[-6].id));
        if (!symbol) {
            fprintf(stderr, "Error: variable '%s' is not an array or not exist at line %d.\n", (yyvsp[-6].id), yylineno);
        }
        LLVMValueRef var = getVarLLVM((yyvsp[-6].id));
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef index = (yyvsp[-4].number).llvm_value;
        LLVMValueRef value = (yyvsp[-1].number).llvm_value;

        // Gera o índice do array
        LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, false), index };
        LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var, indices, 2, "arrayptr");

        // Armazena o valor no array
        if ((yyvsp[-1].number).type == TYPE_INT) {
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-6].id), (yyvsp[-1].number).value, (int)(yyvsp[-4].number).value);
        } else if ((yyvsp[-1].number).type == TYPE_FLOAT) {
            printf("Warning: casting float to int for array '%s' at line %d.\n", (yyvsp[-6].id), yylineno);
            value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-6].id), (int)(yyvsp[-1].number).value, (int)(yyvsp[-4].number).value);
        } else {
            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
        }
    }
#line 2989 "objects/parser.tab.c"
    break;

  case 110: /* $@11: %empty  */
#line 924 "compiler/parser.y"
                                     {
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        
        // Cria blocos básicos
        LLVMBasicBlockRef ifBB = LLVMAppendBasicBlockInContext(context, currentFunc, "if");
        LLVMBasicBlockRef nextCondBB = LLVMAppendBasicBlockInContext(context, currentFunc, "next_cond");
        LLVMBasicBlockRef intermediary = LLVMAppendBasicBlockInContext(context, currentFunc, "intermediary");
        
        // Empilha contexto
        push_cond_context(intermediary, nextCondBB);
        
        // Gera branch condicional
        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, ifBB, nextCondBB);
        
        // Entra no bloco if
        LLVMPositionBuilderAtEnd(builder, ifBB);

        pushScope();
    }
#line 3015 "objects/parser.tab.c"
    break;

  case 111: /* $@12: %empty  */
#line 944 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3028 "objects/parser.tab.c"
    break;

  case 112: /* if_statement: IF LEFTPAR expression RIGHTPAR $@11 LEFTKEYS program_locals RIGHTKEYS $@12 else_if_chain  */
#line 951 "compiler/parser.y"
                    {
        // Finaliza este contexto
        ConditionalContext current = pop_cond_context();
        LLVMPositionBuilderAtEnd(builder, current.endBB);
        
        LLVMBasicBlockRef endBB = LLVMAppendBasicBlockInContext(context, currentFunc, "endif");
        LLVMBuildBr(builder, endBB);

        LLVMPositionBuilderAtEnd(builder, endBB);
    }
#line 3043 "objects/parser.tab.c"
    break;

  case 113: /* else_if_chain: %empty  */
#line 964 "compiler/parser.y"
                  {
        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 3052 "objects/parser.tab.c"
    break;

  case 114: /* else_if_chain: ELSE LEFTPAR expression RIGHTPAR  */
#line 968 "compiler/parser.y"
                                       {
        fprintf(stderr, "Error: else cannot have a condition at line %d.\n", yylineno);
    }
#line 3060 "objects/parser.tab.c"
    break;

  case 115: /* $@13: %empty  */
#line 971 "compiler/parser.y"
           {

        pushScope();
        
        ConditionalContext* current = top_cond_context();
        // Transforma o nextCondBB em bloco else
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3073 "objects/parser.tab.c"
    break;

  case 116: /* else_if_chain: ELSE $@13 LEFTKEYS program_locals RIGHTKEYS  */
#line 978 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 3085 "objects/parser.tab.c"
    break;

  case 117: /* $@14: %empty  */
#line 985 "compiler/parser.y"
                                         {
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        
        ConditionalContext* current = top_cond_context();
        
        // Cria blocos para este elseif
        LLVMBasicBlockRef elseifBB = LLVMAppendBasicBlockInContext(context, currentFunc, "elseif");
        LLVMBasicBlockRef newNextBB = LLVMAppendBasicBlockInContext(context, currentFunc, "next_cond");
        
        // Gera branch condicional
        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, elseifBB, newNextBB);
        
        // Atualiza contexto
        current->nextCondBB = newNextBB;
        
        // Entra no bloco elseif
        LLVMPositionBuilderAtEnd(builder, elseifBB);

        pushScope();
    }
#line 3112 "objects/parser.tab.c"
    break;

  case 118: /* $@15: %empty  */
#line 1006 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3125 "objects/parser.tab.c"
    break;

  case 119: /* else_if_chain: ELSEIF LEFTPAR expression RIGHTPAR $@14 LEFTKEYS program_locals RIGHTKEYS $@15 else_if_chain  */
#line 1013 "compiler/parser.y"
                    {}
#line 3131 "objects/parser.tab.c"
    break;

  case 120: /* $@16: %empty  */
#line 1021 "compiler/parser.y"
                                                  {
        pushScope();
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-3].while_blocks).bodyBB, (yyvsp[-3].while_blocks).endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-3].while_blocks).bodyBB);
    }
#line 3147 "objects/parser.tab.c"
    break;

  case 121: /* while: WHILE while_aux LEFTPAR expression RIGHTPAR $@16 LEFTKEYS program_locals RIGHTKEYS  */
#line 1031 "compiler/parser.y"
                                        {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, (yyvsp[-7].while_blocks).condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).endWHILEBB);

        popScope();
    }
#line 3161 "objects/parser.tab.c"
    break;

  case 122: /* while_aux: %empty  */
#line 1043 "compiler/parser.y"
      {
        // Cria blocos para condicional, corpo e fim do while
        (yyval.while_blocks).condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.cond");
        (yyval.while_blocks).bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.body");
        (yyval.while_blocks).endWHILEBB = LLVMAppendBasicBlockInContext(context, currentFunc, "while.end");

        // Branch para o bloco condicional
        LLVMBuildBr(builder, (yyval.while_blocks).condBB);

        // Condicional
        LLVMPositionBuilderAtEnd(builder, (yyval.while_blocks).condBB);
    }
#line 3178 "objects/parser.tab.c"
    break;

  case 123: /* printf: PRINTF LEFTPAR ID RIGHTPAR DONE  */
#line 1058 "compiler/parser.y"
                                      {
        Symbol* sym = findSymbol((yyvsp[-2].id));
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
        } else if(sym->value == -DBL_MAX) {
            fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", (yyvsp[-2].id), yylineno);
        } else {
            LLVMValueRef fmt = NULL;
            switch (sym->type) {
                case TYPE_INT:
                    fmt = fmt_int;
                    break;
                case TYPE_FLOAT:
                    fmt = fmt_float;
                    break;
                case TYPE_CHAR:
                    fmt = fmt_char;
                    break;
                case TYPE_BOOL:
                    fmt = fmt_bool;
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
            }
            if (fmt) {
                LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
                LLVMTypeRef llvm_type;
                switch (sym->type) {
                    case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                    case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                    case TYPE_CHAR:  llvm_type = LLVMInt8TypeInContext(context); break;
                    case TYPE_BOOL:  llvm_type = LLVMInt1TypeInContext(context); break;
                    default:         llvm_type = LLVMDoubleTypeInContext(context); break;
                }
                LLVMValueRef loaded = LLVMBuildLoad2(builder, llvm_type, var, "loadtmp");
                LLVMValueRef args[2] = { fmt, loaded };
                LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
                LLVMBuildCall2(builder, printf_type, printf_func, args, 2, "");
            }
        }
    }
#line 3224 "objects/parser.tab.c"
    break;

  case 124: /* printf: PRINTF LEFTPAR NUMBER RIGHTPAR DONE  */
#line 1099 "compiler/parser.y"
                                          {
        LLVMValueRef fmt = NULL;
        switch ((yyvsp[-2].number).type) {
            case TYPE_INT:
                fmt = fmt_int;
                break;
            case TYPE_FLOAT:
                fmt = fmt_float;
                break;
            case TYPE_CHAR:
                fmt = fmt_char;
                break;
            case TYPE_BOOL:
                fmt = fmt_bool;
                break;
            default:
                fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
        }
        if (fmt) {
            LLVMValueRef args[2] = { fmt, (yyvsp[-2].number).llvm_value };
            LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
            LLVMBuildCall2(builder, printf_type, printf_func, args, 2, "");
        }
    }
#line 3253 "objects/parser.tab.c"
    break;

  case 125: /* printf: PRINTF LEFTPAR STRING RIGHTPAR DONE  */
#line 1123 "compiler/parser.y"
                                          {
        LLVMValueRef fmt = fmt_str;
        // Cria um valor global para a string literal
        LLVMValueRef str_global = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-2].id)) + 1), "str_literal");
        LLVMSetInitializer(str_global, LLVMConstStringInContext(context, (yyvsp[-2].id), strlen((yyvsp[-2].id)), 0));
        // Gera ponteiro para o início da string
        LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
        LLVMValueRef indices[2] = { zero, zero };
        LLVMValueRef str_ptr = LLVMBuildGEP2(builder, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-2].id)) + 1), str_global, indices, 2, "strptr");
        LLVMValueRef args[2] = { fmt, str_ptr };
        LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
        LLVMBuildCall2(builder, printf_type, printf_func, args, 2, "");
        free((yyvsp[-2].id));
    }
#line 3272 "objects/parser.tab.c"
    break;

  case 126: /* scanf: SCANF LEFTPAR ID RIGHTPAR DONE  */
#line 1141 "compiler/parser.y"
                                     {
        Symbol* sym = findSymbol((yyvsp[-2].id));
        sym->value = 0.0;
        if (sym == NULL) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-2].id), yylineno);
        } else {
            LLVMValueRef fmt = NULL;
            switch (sym->type) {
                case TYPE_INT:
                    fmt = fmt_int;
                    break;
                case TYPE_FLOAT:
                    fmt = fmt_float;
                    break;
                case TYPE_CHAR:
                    fmt = fmt_char;
                    break;
                case TYPE_BOOL:
                    fmt = fmt_bool;
                    break;
                default:
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
            }
            if (fmt) {
                LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
                LLVMValueRef args[2] = { fmt, var };
                LLVMValueRef scanf_func = LLVMGetNamedFunction(module, "scanf");
                LLVMBuildCall2(builder, scanf_type, scanf_func, args, 2, "");
            }
        }
    }
#line 3308 "objects/parser.tab.c"
    break;

  case 127: /* return: RETURN expression DONE  */
#line 1175 "compiler/parser.y"
                             {
        if(functionList->returnType != TYPE_VOID) {
            if((yyvsp[-1].number).type != functionList->returnType) {
                fprintf(stderr, "Error: return type mismatch at line %d. Expected %s but got %s.\n", yylineno, typeToString(functionList->returnType), typeToString((yyvsp[-1].number).type));
            } else {
                LLVMBuildRet(builder, (yyvsp[-1].number).llvm_value);
            }
        } else {
            fprintf(stderr, "Error: cannot return a value in a void function at line %d.\n", yylineno);
        }
    }
#line 3324 "objects/parser.tab.c"
    break;

  case 128: /* return: RETURN DONE  */
#line 1186 "compiler/parser.y"
                  {
        if(functionList->returnType != TYPE_VOID) {
            fprintf(stderr, "Error: function '%s' must return a value at line %d.\n", functionList->id, yylineno);
        } else {
            LLVMBuildRetVoid(builder);
        }
}
#line 3336 "objects/parser.tab.c"
    break;

  case 129: /* expression: soma_sub  */
#line 1197 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3342 "objects/parser.tab.c"
    break;

  case 130: /* expression: mult_div  */
#line 1198 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3348 "objects/parser.tab.c"
    break;

  case 131: /* expression: LEFTPAR expression RIGHTPAR  */
#line 1199 "compiler/parser.y"
                                  { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; }
#line 3354 "objects/parser.tab.c"
    break;

  case 132: /* expression: comparison  */
#line 1200 "compiler/parser.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3360 "objects/parser.tab.c"
    break;

  case 133: /* expression: log_exp  */
#line 1201 "compiler/parser.y"
              { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3366 "objects/parser.tab.c"
    break;

  case 134: /* expression: cast  */
#line 1202 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3372 "objects/parser.tab.c"
    break;

  case 135: /* expression: call_function  */
#line 1203 "compiler/parser.y"
                    { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3378 "objects/parser.tab.c"
    break;

  case 136: /* expression: term  */
#line 1204 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3384 "objects/parser.tab.c"
    break;

  case 137: /* soma_sub: expression PLUS expression  */
#line 1208 "compiler/parser.y"
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
#line 3411 "objects/parser.tab.c"
    break;

  case 138: /* soma_sub: expression MIN expression  */
#line 1230 "compiler/parser.y"
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
#line 3438 "objects/parser.tab.c"
    break;

  case 139: /* mult_div: expression MULT expression  */
#line 1255 "compiler/parser.y"
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
#line 3465 "objects/parser.tab.c"
    break;

  case 140: /* mult_div: expression DIV expression  */
#line 1277 "compiler/parser.y"
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
#line 3498 "objects/parser.tab.c"
    break;

  case 141: /* comparison: expression LESS expression  */
#line 1308 "compiler/parser.y"
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
#line 3525 "objects/parser.tab.c"
    break;

  case 142: /* comparison: expression GREAT expression  */
#line 1330 "compiler/parser.y"
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
#line 3552 "objects/parser.tab.c"
    break;

  case 143: /* comparison: expression LEQUAL expression  */
#line 1352 "compiler/parser.y"
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
#line 3579 "objects/parser.tab.c"
    break;

  case 144: /* comparison: expression GEQUAL expression  */
#line 1374 "compiler/parser.y"
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
#line 3606 "objects/parser.tab.c"
    break;

  case 145: /* comparison: expression EQUAL expression  */
#line 1396 "compiler/parser.y"
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
#line 3637 "objects/parser.tab.c"
    break;

  case 146: /* comparison: expression NEQUAL expression  */
#line 1422 "compiler/parser.y"
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
#line 3667 "objects/parser.tab.c"
    break;

  case 147: /* log_exp: expression AND expression  */
#line 1450 "compiler/parser.y"
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
#line 3683 "objects/parser.tab.c"
    break;

  case 148: /* log_exp: expression OR expression  */
#line 1461 "compiler/parser.y"
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
#line 3699 "objects/parser.tab.c"
    break;

  case 149: /* log_exp: NOT expression  */
#line 1472 "compiler/parser.y"
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
#line 3715 "objects/parser.tab.c"
    break;

  case 150: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1486 "compiler/parser.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3726 "objects/parser.tab.c"
    break;

  case 151: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 1492 "compiler/parser.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3737 "objects/parser.tab.c"
    break;

  case 152: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1498 "compiler/parser.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3747 "objects/parser.tab.c"
    break;

  case 153: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 1503 "compiler/parser.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3757 "objects/parser.tab.c"
    break;

  case 154: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1508 "compiler/parser.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3767 "objects/parser.tab.c"
    break;

  case 155: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 1513 "compiler/parser.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3777 "objects/parser.tab.c"
    break;

  case 156: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1518 "compiler/parser.y"
                                                        {
        (yyval.number).value = ((yyvsp[-1].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[-1].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
    }
#line 3789 "objects/parser.tab.c"
    break;

  case 157: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 1525 "compiler/parser.y"
                                 {
        (yyval.number).value = ((yyvsp[0].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[0].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
    }
#line 3801 "objects/parser.tab.c"
    break;

  case 158: /* call_function: ID LEFTPAR call_parameters RIGHTPAR  */
#line 1536 "compiler/parser.y"
                                          {
        FunctionSymbol* func = findFunctionSymbol((yyvsp[-3].id));
        if (func == NULL) {
            fprintf(stderr, "Error: function '%s' not declared at line %d.\n", (yyvsp[-3].id), yylineno);
            (yyval.number).value = -1;
            (yyval.number).type = TYPE_UNKNOWN;
            (yyval.number).llvm_value = NULL;
        } else {
            if (func->paramCount != param_call_count) {
                fprintf(stderr, "Error: function '%s' expects %d parameters but got %d at line %d.\n", (yyvsp[-3].id), func->paramCount, param_call_count, yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
            } else {
                LLVMValueRef args[param_call_count];
                int j = 0;
                for (int i = param_call_count - 1; i >= 0; i--) {
                    args[j++] = param_call[i].llvm_value;
                }
                switch (func->returnType) {
                    case TYPE_INT:   func_type = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0); break;
                    case TYPE_FLOAT: func_type = LLVMFunctionType(LLVMDoubleTypeInContext(context), NULL, 0, 0); break;
                    case TYPE_CHAR:  func_type = LLVMFunctionType(LLVMInt8TypeInContext(context), NULL, 0, 0); break;
                    case TYPE_BOOL:  func_type = LLVMFunctionType(LLVMInt1TypeInContext(context), NULL, 0, 0); break;
                    default:         func_type = LLVMFunctionType(LLVMVoidTypeInContext(context), NULL, 0, 0); break;
                }
                LLVMValueRef func_ref = LLVMGetNamedFunction(module, (yyvsp[-3].id));
                if (func_ref == NULL) {
                    fprintf(stderr, "Error: function '%s' not found in module at line %d.\n", (yyvsp[-3].id), yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                    (yyval.number).llvm_value = NULL;
                } else {
                    // Chama a função e armazena o valor de retorno
                    (yyval.number).llvm_value = LLVMBuildCall2(builder, func_type, func_ref, args, param_call_count, "");
                    (yyval.number).type = func->returnType;
                    (yyval.number).value = 0; // Opcional: você pode tentar calcular o valor se quiser
                }
            }
        }
        param_call_count = 0; // Limpa para próxima chamada
    }
#line 3848 "objects/parser.tab.c"
    break;

  case 159: /* call_parameters: %empty  */
#line 1581 "compiler/parser.y"
                  {}
#line 3854 "objects/parser.tab.c"
    break;

  case 160: /* call_parameters: term call_parameter_list  */
#line 1582 "compiler/parser.y"
                               {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3864 "objects/parser.tab.c"
    break;

  case 161: /* call_parameter_list: %empty  */
#line 1590 "compiler/parser.y"
                  {}
#line 3870 "objects/parser.tab.c"
    break;

  case 162: /* call_parameter_list: COMMA term call_parameter_list  */
#line 1591 "compiler/parser.y"
                                     {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3880 "objects/parser.tab.c"
    break;

  case 163: /* term: NUMBER  */
#line 1599 "compiler/parser.y"
             { 
        (yyval.number).value = (yyvsp[0].number).value; 
        (yyval.number).type = (yyvsp[0].number).type; 
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:   (yyval.number).llvm_value = LLVMConstInt(LLVMInt32TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            case TYPE_FLOAT: (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
            case TYPE_BOOL:  (yyval.number).llvm_value = LLVMConstInt(LLVMInt1TypeInContext(context), (int)(yyvsp[0].number).value, 0); break;
            default:         (yyval.number).llvm_value = LLVMConstReal(LLVMDoubleTypeInContext(context), (yyvsp[0].number).value); break;
        }
    }
#line 3895 "objects/parser.tab.c"
    break;

  case 164: /* term: ID  */
#line 1609 "compiler/parser.y"
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
#line 3927 "objects/parser.tab.c"
    break;

  case 165: /* term: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 1636 "compiler/parser.y"
                                             {
        ArraySymbol* array_sym = findArraySymbol((yyvsp[-3].id));
        if (!array_sym) {
            fprintf(stderr, "Undeclared array '%s' at line %d\n", (yyvsp[-3].id), yylineno);
            (yyval.number).value = -1;
            (yyval.number).type = TYPE_UNKNOWN;
        } else {
            if((int)(yyvsp[-1].number).value < 0 || (int)(yyvsp[-1].number).value >= array_sym->size) {
                fprintf(stderr, "Array index out of bounds for '%s' at line %d\n", (yyvsp[-3].id), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            } else {
                if (array_sym->values[(int)(yyvsp[-1].number).value] == -DBL_MAX) {
                    fprintf(stderr, "Array in position %d is uninitialized at line %d\n", (int)(yyvsp[-1].number).value, yylineno);
                    (yyval.number).value = -1;
                    (yyval.number).type = TYPE_UNKNOWN;
                } else {
                    if ((yyvsp[-1].number).type != TYPE_INT) {
                        fprintf(stderr, "Array index must be an integer at line %d\n", yylineno);
                        (yyval.number).value = -1;
                        (yyval.number).type = TYPE_UNKNOWN;
                    } else {
                        (yyval.number).value = array_sym->values[(int)(yyvsp[-1].number).value];
                        (yyval.number).type = TYPE_INT;
                        LLVMValueRef var = getArrayVarLLVM((yyvsp[-3].id), (int)(yyvsp[-1].number).value);
                        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
                        (yyval.number).llvm_value = LLVMBuildLoad2(builder, llvm_type, var, "loadtmp");
                    }
                }
            }
        }
    }
#line 3964 "objects/parser.tab.c"
    break;

  case 166: /* term: CARACTERE  */
#line 1668 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 3974 "objects/parser.tab.c"
    break;


#line 3978 "objects/parser.tab.c"

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

#line 1675 "compiler/parser.y"


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

int main() {
    signal(SIGSEGV, handleSegfault); // Handle segmentation faults
    pushScope(); // Initialize the first scope

    // Inicialização LLVM
    context = LLVMContextCreate();
    module = LLVMModuleCreateWithNameInContext("parser", context);
    builder = LLVMCreateBuilderInContext(context);

    // Declarações de funções padrão
    printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(context), 0) },
        1, 1 // 1 argumento fixo, variádico
    );
    LLVMAddFunction(module, "printf", printf_type);

    scanf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(context), 0) },
        1, 1 // 1 argumento fixo, variádico
    );
    LLVMAddFunction(module, "scanf", scanf_type);

    currentFunc = NULL; // Inicializa o ponteiro da função atual

    // Variáveis globais para formatação de strings
    fmt_int   = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), 4), "fmt_int");
    LLVMSetInitializer(fmt_int, LLVMConstStringInContext(context, "%d\n", 4, 0));

    fmt_float = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), 4), "fmt_float");
    LLVMSetInitializer(fmt_float, LLVMConstStringInContext(context, "%f\n", 4, 0));

    fmt_char  = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), 4), "fmt_char");
    LLVMSetInitializer(fmt_char, LLVMConstStringInContext(context, "%c\n", 4, 0));

    fmt_bool  = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), 4), "fmt_bool");
    LLVMSetInitializer(fmt_bool, LLVMConstStringInContext(context, "%d\n", 4, 0));

    fmt_str   = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), 4), "fmt_str");
    LLVMSetInitializer(fmt_str, LLVMConstStringInContext(context, "%s\n", 4, 0));

    yyparse( );

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
