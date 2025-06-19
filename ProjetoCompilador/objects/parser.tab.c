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
  YYSYMBOL_ADDRESS = 12,                   /* ADDRESS  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_VOID = 14,                      /* VOID  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_NUMBER = 16,                    /* NUMBER  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_CARACTERE = 19,                 /* CARACTERE  */
  YYSYMBOL_RECEIVE = 20,                   /* RECEIVE  */
  YYSYMBOL_EQUAL = 21,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 22,                    /* NEQUAL  */
  YYSYMBOL_LESS = 23,                      /* LESS  */
  YYSYMBOL_GREAT = 24,                     /* GREAT  */
  YYSYMBOL_LEQUAL = 25,                    /* LEQUAL  */
  YYSYMBOL_GEQUAL = 26,                    /* GEQUAL  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_OR = 28,                        /* OR  */
  YYSYMBOL_NOT = 29,                       /* NOT  */
  YYSYMBOL_PLUS = 30,                      /* PLUS  */
  YYSYMBOL_MIN = 31,                       /* MIN  */
  YYSYMBOL_MULT = 32,                      /* MULT  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_LEFTPAR = 34,                   /* LEFTPAR  */
  YYSYMBOL_RIGHTPAR = 35,                  /* RIGHTPAR  */
  YYSYMBOL_LEFTKEYS = 36,                  /* LEFTKEYS  */
  YYSYMBOL_RIGHTKEYS = 37,                 /* RIGHTKEYS  */
  YYSYMBOL_LEFTBRACKET = 38,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 39,              /* RIGHTBRACKET  */
  YYSYMBOL_COMMA = 40,                     /* COMMA  */
  YYSYMBOL_DONE = 41,                      /* DONE  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program_globals = 43,           /* program_globals  */
  YYSYMBOL_program_global_list = 44,       /* program_global_list  */
  YYSYMBOL_program_global = 45,            /* program_global  */
  YYSYMBOL_program_locals = 46,            /* program_locals  */
  YYSYMBOL_program_local_list = 47,        /* program_local_list  */
  YYSYMBOL_program_local = 48,             /* program_local  */
  YYSYMBOL_function = 49,                  /* function  */
  YYSYMBOL_int_function = 50,              /* int_function  */
  YYSYMBOL_51_1 = 51,                      /* $@1  */
  YYSYMBOL_52_2 = 52,                      /* $@2  */
  YYSYMBOL_float_function = 53,            /* float_function  */
  YYSYMBOL_54_3 = 54,                      /* $@3  */
  YYSYMBOL_55_4 = 55,                      /* $@4  */
  YYSYMBOL_char_function = 56,             /* char_function  */
  YYSYMBOL_57_5 = 57,                      /* $@5  */
  YYSYMBOL_58_6 = 58,                      /* $@6  */
  YYSYMBOL_bool_function = 59,             /* bool_function  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_61_8 = 61,                      /* $@8  */
  YYSYMBOL_void_function = 62,             /* void_function  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_parameters = 65,                /* parameters  */
  YYSYMBOL_parameter_list = 66,            /* parameter_list  */
  YYSYMBOL_parameter = 67,                 /* parameter  */
  YYSYMBOL_declaration_global = 68,        /* declaration_global  */
  YYSYMBOL_int_declaration_globals = 69,   /* int_declaration_globals  */
  YYSYMBOL_int_declaration_global_list = 70, /* int_declaration_global_list  */
  YYSYMBOL_int_declaration_global = 71,    /* int_declaration_global  */
  YYSYMBOL_array_global = 72,              /* array_global  */
  YYSYMBOL_float_declaration_globals = 73, /* float_declaration_globals  */
  YYSYMBOL_float_declaration_global_list = 74, /* float_declaration_global_list  */
  YYSYMBOL_float_declaration_global = 75,  /* float_declaration_global  */
  YYSYMBOL_char_declaration_globals = 76,  /* char_declaration_globals  */
  YYSYMBOL_char_declaration_global_list = 77, /* char_declaration_global_list  */
  YYSYMBOL_char_declaration_global = 78,   /* char_declaration_global  */
  YYSYMBOL_bool_declaration_globals = 79,  /* bool_declaration_globals  */
  YYSYMBOL_bool_declaration_global_list = 80, /* bool_declaration_global_list  */
  YYSYMBOL_bool_declaration_global = 81,   /* bool_declaration_global  */
  YYSYMBOL_array_values_global = 82,       /* array_values_global  */
  YYSYMBOL_term_const = 83,                /* term_const  */
  YYSYMBOL_declaration_local = 84,         /* declaration_local  */
  YYSYMBOL_int_declaration_locals = 85,    /* int_declaration_locals  */
  YYSYMBOL_int_declaration_local_list = 86, /* int_declaration_local_list  */
  YYSYMBOL_int_declaration_local = 87,     /* int_declaration_local  */
  YYSYMBOL_array_local = 88,               /* array_local  */
  YYSYMBOL_float_declaration_locals = 89,  /* float_declaration_locals  */
  YYSYMBOL_float_declaration_local_list = 90, /* float_declaration_local_list  */
  YYSYMBOL_float_declaration_local = 91,   /* float_declaration_local  */
  YYSYMBOL_char_declaration_locals = 92,   /* char_declaration_locals  */
  YYSYMBOL_char_declaration_local_list = 93, /* char_declaration_local_list  */
  YYSYMBOL_char_declaration_local = 94,    /* char_declaration_local  */
  YYSYMBOL_bool_declaration_locals = 95,   /* bool_declaration_locals  */
  YYSYMBOL_bool_declaration_local_list = 96, /* bool_declaration_local_list  */
  YYSYMBOL_bool_declaration_local = 97,    /* bool_declaration_local  */
  YYSYMBOL_array_values_local = 98,        /* array_values_local  */
  YYSYMBOL_comand = 99,                    /* comand  */
  YYSYMBOL_assignment = 100,               /* assignment  */
  YYSYMBOL_if_statement = 101,             /* if_statement  */
  YYSYMBOL_102_11 = 102,                   /* $@11  */
  YYSYMBOL_103_12 = 103,                   /* $@12  */
  YYSYMBOL_else_if_chain = 104,            /* else_if_chain  */
  YYSYMBOL_105_13 = 105,                   /* $@13  */
  YYSYMBOL_106_14 = 106,                   /* $@14  */
  YYSYMBOL_107_15 = 107,                   /* $@15  */
  YYSYMBOL_while = 108,                    /* while  */
  YYSYMBOL_109_16 = 109,                   /* $@16  */
  YYSYMBOL_while_aux = 110,                /* while_aux  */
  YYSYMBOL_printf = 111,                   /* printf  */
  YYSYMBOL_printf_args = 112,              /* printf_args  */
  YYSYMBOL_scanf = 113,                    /* scanf  */
  YYSYMBOL_scanf_args = 114,               /* scanf_args  */
  YYSYMBOL_return = 115,                   /* return  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_soma_sub = 117,                 /* soma_sub  */
  YYSYMBOL_mult_div = 118,                 /* mult_div  */
  YYSYMBOL_comparison = 119,               /* comparison  */
  YYSYMBOL_log_exp = 120,                  /* log_exp  */
  YYSYMBOL_cast = 121,                     /* cast  */
  YYSYMBOL_call_function = 122,            /* call_function  */
  YYSYMBOL_call_parameters = 123,          /* call_parameters  */
  YYSYMBOL_call_parameter_list = 124,      /* call_parameter_list  */
  YYSYMBOL_term = 125                      /* term  */
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
#define YYLAST   536

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  84
/* YYNRULES -- Number of rules.  */
#define YYNRULES  170
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  345

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   114,   114,   115,   119,   120,   124,   125,   126,   131,
     132,   136,   137,   141,   142,   147,   148,   149,   150,   151,
     157,   159,   157,   192,   194,   192,   227,   229,   227,   262,
     264,   262,   298,   300,   298,   331,   332,   335,   336,   340,
     350,   360,   370,   384,   385,   386,   387,   391,   394,   395,
     398,   405,   412,   415,   429,   456,   459,   460,   463,   470,
     480,   483,   484,   487,   494,   504,   507,   508,   511,   518,
     529,   537,   546,   556,   564,   565,   566,   567,   571,   574,
     575,   578,   582,   602,   606,   620,   645,   648,   649,   652,
     656,   678,   681,   682,   685,   689,   706,   709,   710,   713,
     717,   734,   742,   749,   750,   751,   752,   753,   754,   755,
     760,   805,   837,   857,   837,   877,   881,   884,   884,   898,
     919,   898,   934,   934,   956,   971,   992,   993,  1003,  1024,
    1025,  1040,  1051,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1073,  1095,  1120,  1142,  1173,  1195,  1217,  1239,  1261,
    1287,  1315,  1326,  1337,  1351,  1357,  1363,  1368,  1373,  1378,
    1383,  1390,  1401,  1446,  1447,  1455,  1456,  1464,  1474,  1501,
    1533
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
  "INT", "CHAR", "FLOAT", "BOOL", "PRINTF", "SCANF", "ADDRESS", "WHILE",
  "VOID", "RETURN", "NUMBER", "ID", "STRING", "CARACTERE", "RECEIVE",
  "EQUAL", "NEQUAL", "LESS", "GREAT", "LEQUAL", "GEQUAL", "AND", "OR",
  "NOT", "PLUS", "MIN", "MULT", "DIV", "LEFTPAR", "RIGHTPAR", "LEFTKEYS",
  "RIGHTKEYS", "LEFTBRACKET", "RIGHTBRACKET", "COMMA", "DONE", "$accept",
  "program_globals", "program_global_list", "program_global",
  "program_locals", "program_local_list", "program_local", "function",
  "int_function", "$@1", "$@2", "float_function", "$@3", "$@4",
  "char_function", "$@5", "$@6", "bool_function", "$@7", "$@8",
  "void_function", "$@9", "$@10", "parameters", "parameter_list",
  "parameter", "declaration_global", "int_declaration_globals",
  "int_declaration_global_list", "int_declaration_global", "array_global",
  "float_declaration_globals", "float_declaration_global_list",
  "float_declaration_global", "char_declaration_globals",
  "char_declaration_global_list", "char_declaration_global",
  "bool_declaration_globals", "bool_declaration_global_list",
  "bool_declaration_global", "array_values_global", "term_const",
  "declaration_local", "int_declaration_locals",
  "int_declaration_local_list", "int_declaration_local", "array_local",
  "float_declaration_locals", "float_declaration_local_list",
  "float_declaration_local", "char_declaration_locals",
  "char_declaration_local_list", "char_declaration_local",
  "bool_declaration_locals", "bool_declaration_local_list",
  "bool_declaration_local", "array_values_local", "comand", "assignment",
  "if_statement", "$@11", "$@12", "else_if_chain", "$@13", "$@14", "$@15",
  "while", "$@16", "while_aux", "printf", "printf_args", "scanf",
  "scanf_args", "return", "expression", "soma_sub", "mult_div",
  "comparison", "log_exp", "cast", "call_function", "call_parameters",
  "call_parameter_list", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     440,  -161,     8,    20,    29,    48,    57,    13,   444,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
       2,    49,  -161,   -19,    63,    -4,    69,     4,    84,    54,
    -161,  -161,   444,    31,  -161,    31,   118,    89,    31,  -161,
     122,   100,    31,  -161,   129,   125,    31,  -161,   154,   134,
    -161,  -161,  -161,  -161,  -161,   105,   138,   -17,    49,  -161,
    -161,   105,   167,    63,  -161,  -161,   105,   170,    69,  -161,
    -161,   105,   175,    84,  -161,   105,   166,   179,   182,   183,
    -161,   164,   194,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,   168,   105,  -161,   184,   186,
     187,   189,   191,   192,   164,    31,   193,   195,   196,   197,
     422,  -161,   116,  -161,   422,   422,   422,   422,   209,   202,
     231,   232,   234,   216,   218,  -161,    32,   113,   225,   422,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,   226,  -161,    31,   244,   249,   250,   251,   115,
       6,   228,  -161,   269,   229,   270,   230,   280,   265,   253,
     297,   296,  -161,   -20,  -161,   115,    26,  -161,    74,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,   115,   126,   115,  -161,
    -161,   422,  -161,  -161,  -161,  -161,  -161,  -161,   271,   115,
     115,   202,   279,   115,   231,   294,   115,   232,   304,   115,
     234,   309,   320,   325,   115,   115,  -161,   340,   345,   355,
     360,   286,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,  -161,    95,   367,   375,   380,   214,
    -161,  -161,   438,   233,   228,  -161,   438,   229,  -161,   438,
     230,  -161,   438,   265,  -161,   115,   392,   424,   399,   301,
     252,    53,   121,   157,   163,  -161,   464,   464,   464,   464,
     464,   464,   477,   451,    25,    25,  -161,  -161,  -161,  -161,
     126,  -161,   418,   406,   423,  -161,  -161,  -161,  -161,   185,
     414,   439,   416,  -161,  -161,   115,  -161,   115,  -161,   115,
    -161,   115,  -161,   380,   115,   422,   431,  -161,  -161,   325,
    -161,   443,   316,   331,   346,   361,  -161,   137,   454,   115,
    -161,   422,  -161,  -161,  -161,  -161,  -161,  -161,   144,   438,
     455,    59,  -161,   115,  -161,   446,   459,  -161,   438,   115,
     468,   115,   376,   422,   391,  -161,   469,  -161,  -161,   475,
     422,   476,  -161,    59,  -161
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
       9,    38,     0,    70,     9,     9,     9,     9,     0,     0,
       0,     0,     0,     0,     0,   124,     0,     0,     0,    11,
      14,    74,    75,    76,    77,    13,   103,   104,   105,   106,
     107,   108,     0,    54,     0,     0,     0,     0,     0,     0,
      81,    79,    83,    94,    92,    89,    87,    99,    97,     0,
       0,     0,   167,   168,   170,     0,     0,   132,     0,   133,
     134,   136,   137,   138,   139,   140,     0,   163,     0,    22,
      10,    11,   109,    71,    28,    25,    31,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   126,   129,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,   168,     0,   165,     0,
      12,   112,    82,     0,    79,    78,    95,    92,    91,    90,
      87,    86,   100,    97,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,   149,   150,   145,   146,
     147,   148,   151,   152,   141,   142,   143,   144,   110,   162,
       0,   164,     0,     0,    84,    80,    93,    88,    98,   126,
       0,     0,     0,   122,   169,     0,   155,     0,   159,     0,
     157,     0,   161,   165,     0,     9,     0,   127,   125,   129,
     128,     0,     0,     0,     0,     0,   166,     0,     0,     0,
     130,     9,   154,   158,   156,   160,   111,   113,     0,   101,
       0,   115,    85,     0,   123,   117,     0,   114,   102,     0,
       0,     0,     0,     9,     0,   116,     0,   119,   118,     0,
       9,     0,   120,   115,   121
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,   473,   512,  -106,   333,  -127,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,   127,   411,   420,  -161,  -161,   460,   481,
    -161,  -161,   452,   478,  -161,   456,   483,  -161,   448,   479,
    -161,   -15,  -161,  -161,   290,   334,  -161,  -161,   288,   329,
    -161,   292,   336,  -161,   289,   335,  -161,  -161,  -161,  -161,
    -161,  -161,   188,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
     254,  -161,   235,  -161,  -137,  -161,  -161,  -161,  -161,  -161,
    -110,  -161,   243,  -160
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,    31,    32,   128,   180,   129,     9,    10,    55,
      95,    11,    66,   100,    12,    61,    99,    13,    71,   101,
      14,    75,   102,    80,    97,    81,    15,    16,    37,    21,
      22,    17,    45,    26,    18,    41,    24,    19,    49,    28,
     112,    54,   130,   131,   192,   151,   152,   132,   198,   156,
     133,   195,   154,   134,   201,   158,   318,   135,   136,   137,
     273,   321,   327,   330,   339,   343,   138,   301,   161,   139,
     246,   140,   248,   141,   168,   169,   170,   171,   172,   173,
     174,   227,   271,   175
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     142,    38,   181,    33,   142,   142,   142,   142,   145,   146,
     147,   148,   188,    30,   177,    39,    42,   228,   205,   142,
      56,    35,    33,    60,    46,    20,   189,    65,   206,   211,
      43,    70,   207,   208,   209,   210,    34,    23,    47,   225,
      35,   229,   162,   163,   190,   164,    25,    52,   162,   163,
      53,   164,   232,   233,   181,   165,   236,   222,   223,   239,
     166,   165,   242,   325,   326,    27,   166,   249,   250,   162,
     226,   142,   164,   167,    29,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   285,    50,    36,
     113,   286,   288,   290,   292,   212,   213,   214,   215,   216,
     217,   218,   219,    40,   220,   221,   222,   223,   279,    44,
     293,    76,    77,    78,    79,   224,   212,   213,   214,   215,
     216,   217,   218,   219,    48,   220,   221,   222,   223,   183,
      59,   162,   163,   176,   164,    57,   268,   162,   226,    62,
     164,    64,   162,   226,   165,   164,    67,   177,   302,   166,
     303,   178,   304,   143,   305,   287,   144,   307,   212,   213,
     214,   215,   216,   217,   218,   219,    69,   220,   221,   222,
     223,    72,   319,   162,   226,    74,   164,    82,   316,   162,
     226,   322,   164,    91,   323,   142,   328,    38,    84,   308,
      42,   289,   332,    86,   334,    46,    92,   291,    88,    93,
      94,   142,    90,   103,    96,   320,   212,   213,   214,   215,
     216,   217,   218,   219,    98,   220,   221,   222,   223,   150,
     105,   106,   107,   142,   108,   245,   109,   336,   110,   114,
     142,   115,   116,   117,   341,   212,   213,   214,   215,   216,
     217,   218,   219,   149,   220,   221,   222,   223,   153,   155,
     159,   157,   160,   272,   212,   213,   214,   215,   216,   217,
     218,   219,   179,   220,   221,   222,   223,   182,   191,   194,
     197,   202,   274,   212,   213,   214,   215,   216,   217,   218,
     219,   184,   220,   221,   222,   223,   185,   186,   187,   193,
     196,   284,   212,   213,   214,   215,   216,   217,   218,   219,
     199,   220,   221,   222,   223,   200,   231,   212,   213,   214,
     215,   216,   217,   218,   219,   203,   220,   221,   222,   223,
     235,   255,   212,   213,   214,   215,   216,   217,   218,   219,
     204,   220,   221,   222,   223,   238,   283,   212,   213,   214,
     215,   216,   217,   218,   219,   241,   220,   221,   222,   223,
     244,   312,   212,   213,   214,   215,   216,   217,   218,   219,
     245,   220,   221,   222,   223,   247,   313,   212,   213,   214,
     215,   216,   217,   218,   219,   251,   220,   221,   222,   223,
     252,   314,   212,   213,   214,   215,   216,   217,   218,   219,
     253,   220,   221,   222,   223,   254,   315,   212,   213,   214,
     215,   216,   217,   218,   219,   205,   220,   221,   222,   223,
     269,   335,   212,   213,   214,   215,   216,   217,   218,   219,
     270,   220,   221,   222,   223,   118,   337,   280,   119,   120,
     121,   122,   123,   124,   282,   125,   281,   126,   294,   127,
      -2,     1,   295,   296,    -4,     1,     2,     3,     4,     5,
       2,     3,     4,     5,     6,   298,   299,   300,     6,   212,
     213,   214,   215,   216,   217,   218,   219,   309,   220,   221,
     222,   223,   212,   213,   214,   215,   216,   217,   218,   311,
     329,   220,   221,   222,   223,    -5,    -5,    -5,    -5,    -5,
      -5,   317,   324,   331,   220,   221,   222,   223,   212,   213,
     214,   215,   216,   217,   333,    51,   338,   220,   221,   222,
     223,   340,     8,   342,   230,   111,   104,    58,    83,    85,
      87,    89,    68,    63,   275,   234,   240,    73,   277,   276,
     237,   344,   278,   297,   310,   243,   306
};

static const yytype_int16 yycheck[] =
{
     110,    20,   129,    20,   114,   115,   116,   117,   114,   115,
     116,   117,   149,     0,    34,    34,    20,   177,    38,   129,
      35,    38,    20,    38,    20,    17,    20,    42,   165,   166,
      34,    46,     6,     7,     8,     9,    34,    17,    34,   176,
      38,   178,    16,    17,    38,    19,    17,    16,    16,    17,
      19,    19,   189,   190,   181,    29,   193,    32,    33,   196,
      34,    29,   199,     4,     5,    17,    34,   204,   205,    16,
      17,   181,    19,    41,    17,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,    34,    34,    40,
     105,   251,   252,   253,   254,    21,    22,    23,    24,    25,
      26,    27,    28,    40,    30,    31,    32,    33,   245,    40,
     270,     6,     7,     8,     9,    41,    21,    22,    23,    24,
      25,    26,    27,    28,    40,    30,    31,    32,    33,   144,
      41,    16,    17,    20,    19,    17,    41,    16,    17,    17,
      19,    41,    16,    17,    29,    19,    17,    34,   285,    34,
     287,    38,   289,    37,   291,    34,    40,   294,    21,    22,
      23,    24,    25,    26,    27,    28,    41,    30,    31,    32,
      33,    17,   309,    16,    17,    41,    19,    39,    41,    16,
      17,    37,    19,    17,    40,   295,   323,    20,    61,   295,
      20,    34,   329,    66,   331,    20,    17,    34,    71,    17,
      17,   311,    75,    35,    40,   311,    21,    22,    23,    24,
      25,    26,    27,    28,    20,    30,    31,    32,    33,    17,
      36,    35,    35,   333,    35,    40,    35,   333,    36,    36,
     340,    36,    36,    36,   340,    21,    22,    23,    24,    25,
      26,    27,    28,    34,    30,    31,    32,    33,    17,    17,
      34,    17,    34,    39,    21,    22,    23,    24,    25,    26,
      27,    28,    37,    30,    31,    32,    33,    41,    40,    40,
      40,    18,    39,    21,    22,    23,    24,    25,    26,    27,
      28,    37,    30,    31,    32,    33,    37,    37,    37,    20,
      20,    39,    21,    22,    23,    24,    25,    26,    27,    28,
      20,    30,    31,    32,    33,    40,    35,    21,    22,    23,
      24,    25,    26,    27,    28,    18,    30,    31,    32,    33,
      41,    35,    21,    22,    23,    24,    25,    26,    27,    28,
      34,    30,    31,    32,    33,    41,    35,    21,    22,    23,
      24,    25,    26,    27,    28,    41,    30,    31,    32,    33,
      41,    35,    21,    22,    23,    24,    25,    26,    27,    28,
      40,    30,    31,    32,    33,    40,    35,    21,    22,    23,
      24,    25,    26,    27,    28,    35,    30,    31,    32,    33,
      35,    35,    21,    22,    23,    24,    25,    26,    27,    28,
      35,    30,    31,    32,    33,    35,    35,    21,    22,    23,
      24,    25,    26,    27,    28,    38,    30,    31,    32,    33,
      35,    35,    21,    22,    23,    24,    25,    26,    27,    28,
      40,    30,    31,    32,    33,     3,    35,    35,     6,     7,
       8,     9,    10,    11,    35,    13,    12,    15,    20,    17,
       0,     1,    36,    20,     0,     1,     6,     7,     8,     9,
       6,     7,     8,     9,    14,    41,    17,    41,    14,    21,
      22,    23,    24,    25,    26,    27,    28,    36,    30,    31,
      32,    33,    21,    22,    23,    24,    25,    26,    27,    36,
      34,    30,    31,    32,    33,    21,    22,    23,    24,    25,
      26,    37,    37,    34,    30,    31,    32,    33,    21,    22,
      23,    24,    25,    26,    36,    32,    37,    30,    31,    32,
      33,    36,     0,    37,   181,   104,    96,    36,    58,    63,
      68,    73,    44,    40,   234,   191,   197,    48,   240,   237,
     194,   343,   243,   279,   299,   200,   293
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     6,     7,     8,     9,    14,    43,    45,    49,
      50,    53,    56,    59,    62,    68,    69,    73,    76,    79,
      17,    71,    72,    17,    78,    17,    75,    17,    81,    17,
       0,    44,    45,    20,    34,    38,    40,    70,    20,    34,
      40,    77,    20,    34,    40,    74,    20,    34,    40,    80,
      34,    44,    16,    19,    83,    51,    83,    17,    71,    41,
      83,    57,    17,    78,    41,    83,    54,    17,    75,    41,
      83,    60,    17,    81,    41,    63,     6,     7,     8,     9,
      65,    67,    39,    70,    65,    77,    65,    74,    65,    80,
      65,    17,    17,    17,    17,    52,    40,    66,    20,    58,
      55,    61,    64,    35,    67,    36,    35,    35,    35,    35,
      36,    66,    82,    83,    36,    36,    36,    36,     3,     6,
       7,     8,     9,    10,    11,    13,    15,    17,    46,    48,
      84,    85,    89,    92,    95,    99,   100,   101,   108,   111,
     113,   115,   122,    37,    40,    46,    46,    46,    46,    34,
      17,    87,    88,    17,    94,    17,    91,    17,    97,    34,
      34,   110,    16,    17,    19,    29,    34,    41,   116,   117,
     118,   119,   120,   121,   122,   125,    20,    34,    38,    37,
      47,    48,    41,    83,    37,    37,    37,    37,   116,    20,
      38,    40,    86,    20,    40,    93,    20,    40,    90,    20,
      40,    96,    18,    18,    34,    38,   116,     6,     7,     8,
       9,   116,    21,    22,    23,    24,    25,    26,    27,    28,
      30,    31,    32,    33,    41,   116,    17,   123,   125,   116,
      47,    35,   116,   116,    87,    41,   116,    94,    41,   116,
      91,    41,   116,    97,    41,    40,   112,    40,   114,   116,
     116,    35,    35,    35,    35,    35,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   116,    41,    35,
      40,   124,    39,   102,    39,    86,    93,    90,    96,   116,
      35,    12,    35,    35,    39,    34,   125,    34,   125,    34,
     125,    34,   125,   125,    20,    36,    20,   112,    41,    17,
      41,   109,   116,   116,   116,   116,   124,   116,    46,    36,
     114,    36,    35,    35,    35,    35,    41,    37,    98,   116,
      46,   103,    37,    40,    37,     4,     5,   104,   116,    34,
     105,    34,   116,    36,   116,    35,    46,    35,    37,   106,
      36,    46,    37,   107,   104
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    44,    45,    45,    45,    46,
      46,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      51,    52,    50,    54,    55,    53,    57,    58,    56,    60,
      61,    59,    63,    64,    62,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    68,    69,    70,    70,
      71,    71,    71,    72,    72,    73,    74,    74,    75,    75,
      76,    77,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    84,    84,    84,    84,    85,    86,
      86,    87,    87,    87,    88,    88,    89,    90,    90,    91,
      91,    92,    93,    93,    94,    94,    95,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,    99,
     100,   100,   102,   103,   101,   104,   104,   105,   104,   106,
     107,   104,   109,   108,   110,   111,   112,   112,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   119,   119,   119,
     119,   120,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   122,   123,   123,   124,   124,   125,   125,   125,
     125
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
       1,     3,     1,     1,     1,     1,     1,     1,     4,     0,
       3,     1,     3,     1,     4,     8,     4,     0,     3,     1,
       3,     4,     0,     3,     1,     3,     4,     0,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     7,     0,     0,    10,     0,     4,     0,     5,     0,
       0,    10,     0,     9,     0,     6,     0,     3,     6,     0,
       4,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     6,     4,     6,     4,     6,     4,
       6,     4,     4,     0,     2,     0,     3,     1,     1,     4,
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
  case 2: /* program_globals: %empty  */
#line 114 "compiler/parser.y"
                  {}
#line 1779 "objects/parser.tab.c"
    break;

  case 3: /* program_globals: program_global program_global_list  */
#line 115 "compiler/parser.y"
                                         {}
#line 1785 "objects/parser.tab.c"
    break;

  case 4: /* program_global_list: %empty  */
#line 119 "compiler/parser.y"
                  {}
#line 1791 "objects/parser.tab.c"
    break;

  case 5: /* program_global_list: program_global program_global_list  */
#line 120 "compiler/parser.y"
                                         {}
#line 1797 "objects/parser.tab.c"
    break;

  case 6: /* program_global: function  */
#line 124 "compiler/parser.y"
               {}
#line 1803 "objects/parser.tab.c"
    break;

  case 7: /* program_global: declaration_global  */
#line 125 "compiler/parser.y"
                         {}
#line 1809 "objects/parser.tab.c"
    break;

  case 8: /* program_global: error  */
#line 126 "compiler/parser.y"
            { yyerrok; yyclearin; }
#line 1815 "objects/parser.tab.c"
    break;

  case 9: /* program_locals: %empty  */
#line 131 "compiler/parser.y"
                  {}
#line 1821 "objects/parser.tab.c"
    break;

  case 10: /* program_locals: program_local program_local_list  */
#line 132 "compiler/parser.y"
                                       {}
#line 1827 "objects/parser.tab.c"
    break;

  case 11: /* program_local_list: %empty  */
#line 136 "compiler/parser.y"
                  {}
#line 1833 "objects/parser.tab.c"
    break;

  case 12: /* program_local_list: program_local program_local_list  */
#line 137 "compiler/parser.y"
                                       {}
#line 1839 "objects/parser.tab.c"
    break;

  case 13: /* program_local: comand  */
#line 141 "compiler/parser.y"
             {}
#line 1845 "objects/parser.tab.c"
    break;

  case 14: /* program_local: declaration_local  */
#line 142 "compiler/parser.y"
                        {}
#line 1851 "objects/parser.tab.c"
    break;

  case 15: /* function: int_function  */
#line 147 "compiler/parser.y"
                   {}
#line 1857 "objects/parser.tab.c"
    break;

  case 16: /* function: float_function  */
#line 148 "compiler/parser.y"
                     {}
#line 1863 "objects/parser.tab.c"
    break;

  case 17: /* function: char_function  */
#line 149 "compiler/parser.y"
                    {}
#line 1869 "objects/parser.tab.c"
    break;

  case 18: /* function: bool_function  */
#line 150 "compiler/parser.y"
                    {}
#line 1875 "objects/parser.tab.c"
    break;

  case 19: /* function: void_function  */
#line 151 "compiler/parser.y"
                    {}
#line 1881 "objects/parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 157 "compiler/parser.y"
                     {
        pushScope();
    }
#line 1889 "objects/parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 159 "compiler/parser.y"
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
#line 1922 "objects/parser.tab.c"
    break;

  case 22: /* int_function: INT ID LEFTPAR $@1 parameters $@2 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 186 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1930 "objects/parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 192 "compiler/parser.y"
                       {
            pushScope();
        }
#line 1938 "objects/parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 194 "compiler/parser.y"
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
#line 1971 "objects/parser.tab.c"
    break;

  case 25: /* float_function: FLOAT ID LEFTPAR $@3 parameters $@4 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 221 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1979 "objects/parser.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 227 "compiler/parser.y"
                      {
        pushScope();
    }
#line 1987 "objects/parser.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 229 "compiler/parser.y"
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
#line 2020 "objects/parser.tab.c"
    break;

  case 28: /* char_function: CHAR ID LEFTPAR $@5 parameters $@6 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 256 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2028 "objects/parser.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 262 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2036 "objects/parser.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 264 "compiler/parser.y"
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
#line 2069 "objects/parser.tab.c"
    break;

  case 31: /* bool_function: BOOL ID LEFTPAR $@7 parameters $@8 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 291 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2077 "objects/parser.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 298 "compiler/parser.y"
                      {
            pushScope();
    }
#line 2085 "objects/parser.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 300 "compiler/parser.y"
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
#line 2115 "objects/parser.tab.c"
    break;

  case 34: /* void_function: VOID ID LEFTPAR $@9 parameters $@10 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 324 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2123 "objects/parser.tab.c"
    break;

  case 36: /* parameters: parameter parameter_list  */
#line 332 "compiler/parser.y"
                               {}
#line 2129 "objects/parser.tab.c"
    break;

  case 38: /* parameter_list: COMMA parameter parameter_list  */
#line 336 "compiler/parser.y"
                                     {}
#line 2135 "objects/parser.tab.c"
    break;

  case 39: /* parameter: INT ID  */
#line 340 "compiler/parser.y"
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
#line 2150 "objects/parser.tab.c"
    break;

  case 40: /* parameter: FLOAT ID  */
#line 350 "compiler/parser.y"
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
#line 2165 "objects/parser.tab.c"
    break;

  case 41: /* parameter: CHAR ID  */
#line 360 "compiler/parser.y"
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
#line 2180 "objects/parser.tab.c"
    break;

  case 42: /* parameter: BOOL ID  */
#line 370 "compiler/parser.y"
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
#line 2195 "objects/parser.tab.c"
    break;

  case 43: /* declaration_global: int_declaration_globals  */
#line 384 "compiler/parser.y"
                              {}
#line 2201 "objects/parser.tab.c"
    break;

  case 44: /* declaration_global: float_declaration_globals  */
#line 385 "compiler/parser.y"
                                {}
#line 2207 "objects/parser.tab.c"
    break;

  case 45: /* declaration_global: char_declaration_globals  */
#line 386 "compiler/parser.y"
                               {}
#line 2213 "objects/parser.tab.c"
    break;

  case 46: /* declaration_global: bool_declaration_globals  */
#line 387 "compiler/parser.y"
                               {}
#line 2219 "objects/parser.tab.c"
    break;

  case 47: /* int_declaration_globals: INT int_declaration_global int_declaration_global_list DONE  */
#line 391 "compiler/parser.y"
                                                                  {}
#line 2225 "objects/parser.tab.c"
    break;

  case 50: /* int_declaration_global: ID  */
#line 398 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2237 "objects/parser.tab.c"
    break;

  case 51: /* int_declaration_global: ID RECEIVE term_const  */
#line 405 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2249 "objects/parser.tab.c"
    break;

  case 52: /* int_declaration_global: array_global  */
#line 412 "compiler/parser.y"
                   {}
#line 2255 "objects/parser.tab.c"
    break;

  case 53: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET  */
#line 415 "compiler/parser.y"
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
#line 2274 "objects/parser.tab.c"
    break;

  case 54: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET RECEIVE LEFTKEYS array_values_global RIGHTKEYS  */
#line 429 "compiler/parser.y"
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
#line 2301 "objects/parser.tab.c"
    break;

  case 55: /* float_declaration_globals: FLOAT float_declaration_global float_declaration_global_list DONE  */
#line 456 "compiler/parser.y"
                                                                        {}
#line 2307 "objects/parser.tab.c"
    break;

  case 58: /* float_declaration_global: ID  */
#line 463 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstReal(type, 0.0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2319 "objects/parser.tab.c"
    break;

  case 59: /* float_declaration_global: ID RECEIVE term_const  */
#line 470 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2331 "objects/parser.tab.c"
    break;

  case 60: /* char_declaration_globals: CHAR char_declaration_global char_declaration_global_list DONE  */
#line 480 "compiler/parser.y"
                                                                     {}
#line 2337 "objects/parser.tab.c"
    break;

  case 61: /* char_declaration_global_list: %empty  */
#line 483 "compiler/parser.y"
                  {}
#line 2343 "objects/parser.tab.c"
    break;

  case 62: /* char_declaration_global_list: COMMA char_declaration_global char_declaration_global_list  */
#line 484 "compiler/parser.y"
                                                                 {}
#line 2349 "objects/parser.tab.c"
    break;

  case 63: /* char_declaration_global: ID  */
#line 487 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2361 "objects/parser.tab.c"
    break;

  case 64: /* char_declaration_global: ID RECEIVE term_const  */
#line 494 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2373 "objects/parser.tab.c"
    break;

  case 65: /* bool_declaration_globals: BOOL bool_declaration_global bool_declaration_global_list DONE  */
#line 504 "compiler/parser.y"
                                                                     {}
#line 2379 "objects/parser.tab.c"
    break;

  case 66: /* bool_declaration_global_list: %empty  */
#line 507 "compiler/parser.y"
                  {}
#line 2385 "objects/parser.tab.c"
    break;

  case 67: /* bool_declaration_global_list: COMMA bool_declaration_global bool_declaration_global_list  */
#line 508 "compiler/parser.y"
                                                                 {}
#line 2391 "objects/parser.tab.c"
    break;

  case 68: /* bool_declaration_global: ID  */
#line 511 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2403 "objects/parser.tab.c"
    break;

  case 69: /* bool_declaration_global: ID RECEIVE term_const  */
#line 518 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2415 "objects/parser.tab.c"
    break;

  case 70: /* array_values_global: term_const  */
#line 529 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2428 "objects/parser.tab.c"
    break;

  case 71: /* array_values_global: array_values_global COMMA term_const  */
#line 537 "compiler/parser.y"
                                           {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
    }
#line 2438 "objects/parser.tab.c"
    break;

  case 72: /* term_const: NUMBER  */
#line 546 "compiler/parser.y"
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
#line 2453 "objects/parser.tab.c"
    break;

  case 73: /* term_const: CARACTERE  */
#line 556 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 2463 "objects/parser.tab.c"
    break;

  case 74: /* declaration_local: int_declaration_locals  */
#line 564 "compiler/parser.y"
                             {}
#line 2469 "objects/parser.tab.c"
    break;

  case 75: /* declaration_local: float_declaration_locals  */
#line 565 "compiler/parser.y"
                               {}
#line 2475 "objects/parser.tab.c"
    break;

  case 76: /* declaration_local: char_declaration_locals  */
#line 566 "compiler/parser.y"
                              {}
#line 2481 "objects/parser.tab.c"
    break;

  case 77: /* declaration_local: bool_declaration_locals  */
#line 567 "compiler/parser.y"
                              {}
#line 2487 "objects/parser.tab.c"
    break;

  case 78: /* int_declaration_locals: INT int_declaration_local int_declaration_local_list DONE  */
#line 571 "compiler/parser.y"
                                                                {}
#line 2493 "objects/parser.tab.c"
    break;

  case 79: /* int_declaration_local_list: %empty  */
#line 574 "compiler/parser.y"
                  {}
#line 2499 "objects/parser.tab.c"
    break;

  case 80: /* int_declaration_local_list: COMMA int_declaration_local int_declaration_local_list  */
#line 575 "compiler/parser.y"
                                                             {}
#line 2505 "objects/parser.tab.c"
    break;

  case 81: /* int_declaration_local: ID  */
#line 578 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        allocaVars((yyvsp[0].id), TYPE_INT);
    }
#line 2514 "objects/parser.tab.c"
    break;

  case 82: /* int_declaration_local: ID RECEIVE expression  */
#line 582 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_INT);
        allocaVars((yyvsp[-2].id), TYPE_INT);
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef value = (yyvsp[0].number).llvm_value;
        if(symbol) {
            if ((yyvsp[0].number).type == TYPE_INT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[0].number).type == TYPE_FLOAT) {
                printf("Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2539 "objects/parser.tab.c"
    break;

  case 84: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 606 "compiler/parser.y"
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
#line 2558 "objects/parser.tab.c"
    break;

  case 85: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS  */
#line 620 "compiler/parser.y"
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
#line 2585 "objects/parser.tab.c"
    break;

  case 86: /* float_declaration_locals: FLOAT float_declaration_local float_declaration_local_list DONE  */
#line 645 "compiler/parser.y"
                                                                      {}
#line 2591 "objects/parser.tab.c"
    break;

  case 87: /* float_declaration_local_list: %empty  */
#line 648 "compiler/parser.y"
                  {}
#line 2597 "objects/parser.tab.c"
    break;

  case 88: /* float_declaration_local_list: COMMA float_declaration_local float_declaration_local_list  */
#line 649 "compiler/parser.y"
                                                                 {}
#line 2603 "objects/parser.tab.c"
    break;

  case 89: /* float_declaration_local: ID  */
#line 652 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        allocaVars((yyvsp[0].id), TYPE_FLOAT);
    }
#line 2612 "objects/parser.tab.c"
    break;

  case 90: /* float_declaration_local: ID RECEIVE expression  */
#line 656 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_FLOAT);
        allocaVars((yyvsp[-2].id), TYPE_FLOAT);
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
        LLVMTypeRef llvm_type = LLVMDoubleTypeInContext(context);
        LLVMValueRef value = (yyvsp[0].number).llvm_value;
        if(symbol) {
            if ((yyvsp[0].number).type == TYPE_FLOAT) {
                LLVMBuildStore(builder, value, var);
            }
            else if ((yyvsp[0].number).type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2636 "objects/parser.tab.c"
    break;

  case 91: /* char_declaration_locals: CHAR char_declaration_local char_declaration_local_list DONE  */
#line 678 "compiler/parser.y"
                                                                   {}
#line 2642 "objects/parser.tab.c"
    break;

  case 92: /* char_declaration_local_list: %empty  */
#line 681 "compiler/parser.y"
                  {}
#line 2648 "objects/parser.tab.c"
    break;

  case 93: /* char_declaration_local_list: COMMA char_declaration_local char_declaration_local_list  */
#line 682 "compiler/parser.y"
                                                               {}
#line 2654 "objects/parser.tab.c"
    break;

  case 94: /* char_declaration_local: ID  */
#line 685 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        allocaVars((yyvsp[0].id), TYPE_CHAR);
    }
#line 2663 "objects/parser.tab.c"
    break;

  case 95: /* char_declaration_local: ID RECEIVE expression  */
#line 689 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_CHAR);
        allocaVars((yyvsp[-2].id), TYPE_CHAR);
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
        LLVMValueRef value = (yyvsp[0].number).llvm_value;
        if(symbol) {
            if ((yyvsp[0].number).type == TYPE_CHAR) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2682 "objects/parser.tab.c"
    break;

  case 96: /* bool_declaration_locals: BOOL bool_declaration_local bool_declaration_local_list DONE  */
#line 706 "compiler/parser.y"
                                                                   {}
#line 2688 "objects/parser.tab.c"
    break;

  case 97: /* bool_declaration_local_list: %empty  */
#line 709 "compiler/parser.y"
                  {}
#line 2694 "objects/parser.tab.c"
    break;

  case 98: /* bool_declaration_local_list: COMMA bool_declaration_local bool_declaration_local_list  */
#line 710 "compiler/parser.y"
                                                               {}
#line 2700 "objects/parser.tab.c"
    break;

  case 99: /* bool_declaration_local: ID  */
#line 713 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        allocaVars((yyvsp[0].id), TYPE_BOOL);
    }
#line 2709 "objects/parser.tab.c"
    break;

  case 100: /* bool_declaration_local: ID RECEIVE expression  */
#line 717 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_BOOL);
        allocaVars((yyvsp[-2].id), TYPE_BOOL);
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
        LLVMValueRef value = (yyvsp[0].number).llvm_value;
        if(symbol) {
            if ((yyvsp[0].number).type == TYPE_BOOL) {
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2728 "objects/parser.tab.c"
    break;

  case 101: /* array_values_local: expression  */
#line 734 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2741 "objects/parser.tab.c"
    break;

  case 102: /* array_values_local: array_values_local COMMA expression  */
#line 742 "compiler/parser.y"
                                          {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
}
#line 2751 "objects/parser.tab.c"
    break;

  case 103: /* comand: assignment  */
#line 749 "compiler/parser.y"
                   {}
#line 2757 "objects/parser.tab.c"
    break;

  case 104: /* comand: if_statement  */
#line 750 "compiler/parser.y"
                     {}
#line 2763 "objects/parser.tab.c"
    break;

  case 105: /* comand: while  */
#line 751 "compiler/parser.y"
              {}
#line 2769 "objects/parser.tab.c"
    break;

  case 106: /* comand: printf  */
#line 752 "compiler/parser.y"
               {}
#line 2775 "objects/parser.tab.c"
    break;

  case 107: /* comand: scanf  */
#line 753 "compiler/parser.y"
              {}
#line 2781 "objects/parser.tab.c"
    break;

  case 108: /* comand: return  */
#line 754 "compiler/parser.y"
               {}
#line 2787 "objects/parser.tab.c"
    break;

  case 109: /* comand: call_function DONE  */
#line 755 "compiler/parser.y"
                           {}
#line 2793 "objects/parser.tab.c"
    break;

  case 110: /* assignment: ID RECEIVE expression DONE  */
#line 760 "compiler/parser.y"
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
#line 2843 "objects/parser.tab.c"
    break;

  case 111: /* assignment: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE expression DONE  */
#line 805 "compiler/parser.y"
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
#line 2875 "objects/parser.tab.c"
    break;

  case 112: /* $@11: %empty  */
#line 837 "compiler/parser.y"
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
#line 2901 "objects/parser.tab.c"
    break;

  case 113: /* $@12: %empty  */
#line 857 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 2914 "objects/parser.tab.c"
    break;

  case 114: /* if_statement: IF LEFTPAR expression RIGHTPAR $@11 LEFTKEYS program_locals RIGHTKEYS $@12 else_if_chain  */
#line 864 "compiler/parser.y"
                    {
        // Finaliza este contexto
        ConditionalContext current = pop_cond_context();
        LLVMPositionBuilderAtEnd(builder, current.endBB);
        
        LLVMBasicBlockRef endBB = LLVMAppendBasicBlockInContext(context, currentFunc, "endif");
        LLVMBuildBr(builder, endBB);

        LLVMPositionBuilderAtEnd(builder, endBB);
    }
#line 2929 "objects/parser.tab.c"
    break;

  case 115: /* else_if_chain: %empty  */
#line 877 "compiler/parser.y"
                  {
        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 2938 "objects/parser.tab.c"
    break;

  case 116: /* else_if_chain: ELSE LEFTPAR expression RIGHTPAR  */
#line 881 "compiler/parser.y"
                                       {
        fprintf(stderr, "Error: else cannot have a condition at line %d.\n", yylineno);
    }
#line 2946 "objects/parser.tab.c"
    break;

  case 117: /* $@13: %empty  */
#line 884 "compiler/parser.y"
           {

        pushScope();
        
        ConditionalContext* current = top_cond_context();
        // Transforma o nextCondBB em bloco else
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 2959 "objects/parser.tab.c"
    break;

  case 118: /* else_if_chain: ELSE $@13 LEFTKEYS program_locals RIGHTKEYS  */
#line 891 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 2971 "objects/parser.tab.c"
    break;

  case 119: /* $@14: %empty  */
#line 898 "compiler/parser.y"
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
#line 2998 "objects/parser.tab.c"
    break;

  case 120: /* $@15: %empty  */
#line 919 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3011 "objects/parser.tab.c"
    break;

  case 121: /* else_if_chain: ELSEIF LEFTPAR expression RIGHTPAR $@14 LEFTKEYS program_locals RIGHTKEYS $@15 else_if_chain  */
#line 926 "compiler/parser.y"
                    {}
#line 3017 "objects/parser.tab.c"
    break;

  case 122: /* $@16: %empty  */
#line 934 "compiler/parser.y"
                                                  {
        pushScope();
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-3].while_blocks).bodyBB, (yyvsp[-3].while_blocks).endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-3].while_blocks).bodyBB);
    }
#line 3033 "objects/parser.tab.c"
    break;

  case 123: /* while: WHILE while_aux LEFTPAR expression RIGHTPAR $@16 LEFTKEYS program_locals RIGHTKEYS  */
#line 944 "compiler/parser.y"
                                        {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, (yyvsp[-7].while_blocks).condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).endWHILEBB);

        popScope();
    }
#line 3047 "objects/parser.tab.c"
    break;

  case 124: /* while_aux: %empty  */
#line 956 "compiler/parser.y"
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
#line 3064 "objects/parser.tab.c"
    break;

  case 125: /* printf: PRINTF LEFTPAR STRING printf_args RIGHTPAR DONE  */
#line 971 "compiler/parser.y"
                                                      {
        // Cria global para a string de formatação
        LLVMValueRef str_global = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-3].id)) + 1), "str_literal");
        LLVMSetInitializer(str_global, LLVMConstStringInContext(context, (yyvsp[-3].id), strlen((yyvsp[-3].id)), 0));
        LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
        LLVMValueRef indices[2] = { zero, zero };
        LLVMValueRef str_ptr = LLVMBuildGEP2(builder, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-3].id)) + 1), str_global, indices, 2, "strptr");

        // Monta lista de argumentos: primeiro a string, depois os valores
        LLVMValueRef args[MAX_PARAMS + 1];
        args[0] = str_ptr;
        for (int i = 0; i < (yyvsp[-2].printf).count; i++)
            args[i+1] = (yyvsp[-2].printf).values[i];

        LLVMValueRef printf_func = LLVMGetNamedFunction(module, "printf");
        LLVMBuildCall2(builder, printf_type, printf_func, args, (yyvsp[-2].printf).count + 1, "");
        free((yyvsp[-3].id));
    }
#line 3087 "objects/parser.tab.c"
    break;

  case 126: /* printf_args: %empty  */
#line 992 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3093 "objects/parser.tab.c"
    break;

  case 127: /* printf_args: COMMA expression printf_args  */
#line 993 "compiler/parser.y"
                                   {
        (yyval.printf).values[0] = (yyvsp[-1].number).llvm_value;
        for (int i = 0; i < (yyvsp[0].printf).count; i++)
            (yyval.printf).values[i+1] = (yyvsp[0].printf).values[i];
        (yyval.printf).count = (yyvsp[0].printf).count + 1;
    }
#line 3104 "objects/parser.tab.c"
    break;

  case 128: /* scanf: SCANF LEFTPAR STRING scanf_args RIGHTPAR DONE  */
#line 1003 "compiler/parser.y"
                                                    {
        // Cria global para a string de formatação
        LLVMValueRef str_global = LLVMAddGlobal(module, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-3].id)) + 1), "str_literal_scanf");
        LLVMSetInitializer(str_global, LLVMConstStringInContext(context, (yyvsp[-3].id), strlen((yyvsp[-3].id)), 0));
        LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
        LLVMValueRef indices[2] = { zero, zero };
        LLVMValueRef str_ptr = LLVMBuildGEP2(builder, LLVMArrayType(LLVMInt8TypeInContext(context), strlen((yyvsp[-3].id)) + 1), str_global, indices, 2, "strptr_scanf");

        // Monta lista de argumentos: primeiro a string, depois os ponteiros das variáveis
        LLVMValueRef args[MAX_PARAMS + 1];
        args[0] = str_ptr;
        for (int i = 0; i < (yyvsp[-2].printf).count; i++)
            args[i+1] = (yyvsp[-2].printf).values[i];

        LLVMValueRef scanf_func = LLVMGetNamedFunction(module, "scanf");
        LLVMBuildCall2(builder, scanf_type, scanf_func, args, (yyvsp[-2].printf).count + 1, "");
        free((yyvsp[-3].id));
    }
#line 3127 "objects/parser.tab.c"
    break;

  case 129: /* scanf_args: %empty  */
#line 1024 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3133 "objects/parser.tab.c"
    break;

  case 130: /* scanf_args: COMMA ADDRESS ID scanf_args  */
#line 1025 "compiler/parser.y"
                                  {
        Symbol* sym = findSymbol((yyvsp[-1].id));
        if (!sym) {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", (yyvsp[-1].id), yylineno);
            (yyval.printf).count = (yyvsp[0].printf).count;
        } else {
            (yyval.printf).values[0] = getVarLLVM((yyvsp[-1].id));
            for (int i = 0; i < (yyvsp[0].printf).count; i++)
                (yyval.printf).values[i+1] = (yyvsp[0].printf).values[i];
            (yyval.printf).count = (yyvsp[0].printf).count + 1;
        }
    }
#line 3150 "objects/parser.tab.c"
    break;

  case 131: /* return: RETURN expression DONE  */
#line 1040 "compiler/parser.y"
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
#line 3166 "objects/parser.tab.c"
    break;

  case 132: /* return: RETURN DONE  */
#line 1051 "compiler/parser.y"
                  {
        if(functionList->returnType != TYPE_VOID) {
            fprintf(stderr, "Error: function '%s' must return a value at line %d.\n", functionList->id, yylineno);
        } else {
            LLVMBuildRetVoid(builder);
        }
}
#line 3178 "objects/parser.tab.c"
    break;

  case 133: /* expression: soma_sub  */
#line 1062 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3184 "objects/parser.tab.c"
    break;

  case 134: /* expression: mult_div  */
#line 1063 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3190 "objects/parser.tab.c"
    break;

  case 135: /* expression: LEFTPAR expression RIGHTPAR  */
#line 1064 "compiler/parser.y"
                                  { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; }
#line 3196 "objects/parser.tab.c"
    break;

  case 136: /* expression: comparison  */
#line 1065 "compiler/parser.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3202 "objects/parser.tab.c"
    break;

  case 137: /* expression: log_exp  */
#line 1066 "compiler/parser.y"
              { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3208 "objects/parser.tab.c"
    break;

  case 138: /* expression: cast  */
#line 1067 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3214 "objects/parser.tab.c"
    break;

  case 139: /* expression: call_function  */
#line 1068 "compiler/parser.y"
                    { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3220 "objects/parser.tab.c"
    break;

  case 140: /* expression: term  */
#line 1069 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3226 "objects/parser.tab.c"
    break;

  case 141: /* soma_sub: expression PLUS expression  */
#line 1073 "compiler/parser.y"
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
#line 3253 "objects/parser.tab.c"
    break;

  case 142: /* soma_sub: expression MIN expression  */
#line 1095 "compiler/parser.y"
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
#line 3280 "objects/parser.tab.c"
    break;

  case 143: /* mult_div: expression MULT expression  */
#line 1120 "compiler/parser.y"
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
#line 3307 "objects/parser.tab.c"
    break;

  case 144: /* mult_div: expression DIV expression  */
#line 1142 "compiler/parser.y"
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
#line 3340 "objects/parser.tab.c"
    break;

  case 145: /* comparison: expression LESS expression  */
#line 1173 "compiler/parser.y"
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
#line 3367 "objects/parser.tab.c"
    break;

  case 146: /* comparison: expression GREAT expression  */
#line 1195 "compiler/parser.y"
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
#line 3394 "objects/parser.tab.c"
    break;

  case 147: /* comparison: expression LEQUAL expression  */
#line 1217 "compiler/parser.y"
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
#line 3421 "objects/parser.tab.c"
    break;

  case 148: /* comparison: expression GEQUAL expression  */
#line 1239 "compiler/parser.y"
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
#line 3448 "objects/parser.tab.c"
    break;

  case 149: /* comparison: expression EQUAL expression  */
#line 1261 "compiler/parser.y"
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
#line 3479 "objects/parser.tab.c"
    break;

  case 150: /* comparison: expression NEQUAL expression  */
#line 1287 "compiler/parser.y"
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
#line 3509 "objects/parser.tab.c"
    break;

  case 151: /* log_exp: expression AND expression  */
#line 1315 "compiler/parser.y"
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
#line 3525 "objects/parser.tab.c"
    break;

  case 152: /* log_exp: expression OR expression  */
#line 1326 "compiler/parser.y"
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
#line 3541 "objects/parser.tab.c"
    break;

  case 153: /* log_exp: NOT expression  */
#line 1337 "compiler/parser.y"
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
#line 3557 "objects/parser.tab.c"
    break;

  case 154: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1351 "compiler/parser.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3568 "objects/parser.tab.c"
    break;

  case 155: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 1357 "compiler/parser.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3579 "objects/parser.tab.c"
    break;

  case 156: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1363 "compiler/parser.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3589 "objects/parser.tab.c"
    break;

  case 157: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 1368 "compiler/parser.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3599 "objects/parser.tab.c"
    break;

  case 158: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1373 "compiler/parser.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3609 "objects/parser.tab.c"
    break;

  case 159: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 1378 "compiler/parser.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3619 "objects/parser.tab.c"
    break;

  case 160: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1383 "compiler/parser.y"
                                                        {
        (yyval.number).value = ((yyvsp[-1].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[-1].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
    }
#line 3631 "objects/parser.tab.c"
    break;

  case 161: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 1390 "compiler/parser.y"
                                 {
        (yyval.number).value = ((yyvsp[0].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[0].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
    }
#line 3643 "objects/parser.tab.c"
    break;

  case 162: /* call_function: ID LEFTPAR call_parameters RIGHTPAR  */
#line 1401 "compiler/parser.y"
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
#line 3690 "objects/parser.tab.c"
    break;

  case 163: /* call_parameters: %empty  */
#line 1446 "compiler/parser.y"
                  {}
#line 3696 "objects/parser.tab.c"
    break;

  case 164: /* call_parameters: term call_parameter_list  */
#line 1447 "compiler/parser.y"
                               {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3706 "objects/parser.tab.c"
    break;

  case 165: /* call_parameter_list: %empty  */
#line 1455 "compiler/parser.y"
                  {}
#line 3712 "objects/parser.tab.c"
    break;

  case 166: /* call_parameter_list: COMMA term call_parameter_list  */
#line 1456 "compiler/parser.y"
                                     {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3722 "objects/parser.tab.c"
    break;

  case 167: /* term: NUMBER  */
#line 1464 "compiler/parser.y"
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
#line 3737 "objects/parser.tab.c"
    break;

  case 168: /* term: ID  */
#line 1474 "compiler/parser.y"
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
#line 3769 "objects/parser.tab.c"
    break;

  case 169: /* term: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 1501 "compiler/parser.y"
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
#line 3806 "objects/parser.tab.c"
    break;

  case 170: /* term: CARACTERE  */
#line 1533 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 3816 "objects/parser.tab.c"
    break;


#line 3820 "objects/parser.tab.c"

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

#line 1540 "compiler/parser.y"


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

    // Declarações de funções padrão (assinaturas iguais às da linguagem C)
    LLVMTypeRef printf_arg_types[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        printf_arg_types,
        1, 1 // 1 argumento fixo, variádico (igual ao C)
    );
    LLVMAddFunction(module, "printf", printf_type);

    LLVMTypeRef scanf_arg_types[] = { LLVMPointerType(LLVMInt8TypeInContext(context), 0) };
    scanf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(context),
        scanf_arg_types,
        1, 1 // 1 argumento fixo, variádico (igual ao C)
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
