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
#include "stdbool.h"
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



#line 105 "objects/codeIR/parser.tab.c"

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
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_VOID = 15,                      /* VOID  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_NUMBER = 17,                    /* NUMBER  */
  YYSYMBOL_ID = 18,                        /* ID  */
  YYSYMBOL_STRING = 19,                    /* STRING  */
  YYSYMBOL_CARACTERE = 20,                 /* CARACTERE  */
  YYSYMBOL_RECEIVE = 21,                   /* RECEIVE  */
  YYSYMBOL_EQUAL = 22,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 23,                    /* NEQUAL  */
  YYSYMBOL_LESS = 24,                      /* LESS  */
  YYSYMBOL_GREAT = 25,                     /* GREAT  */
  YYSYMBOL_LEQUAL = 26,                    /* LEQUAL  */
  YYSYMBOL_GEQUAL = 27,                    /* GEQUAL  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MIN = 32,                       /* MIN  */
  YYSYMBOL_MULT = 33,                      /* MULT  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_LEFTPAR = 35,                   /* LEFTPAR  */
  YYSYMBOL_RIGHTPAR = 36,                  /* RIGHTPAR  */
  YYSYMBOL_LEFTKEYS = 37,                  /* LEFTKEYS  */
  YYSYMBOL_RIGHTKEYS = 38,                 /* RIGHTKEYS  */
  YYSYMBOL_LEFTBRACKET = 39,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 40,              /* RIGHTBRACKET  */
  YYSYMBOL_COMMA = 41,                     /* COMMA  */
  YYSYMBOL_DONE = 42,                      /* DONE  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program_globals = 44,           /* program_globals  */
  YYSYMBOL_program_global_list = 45,       /* program_global_list  */
  YYSYMBOL_program_global = 46,            /* program_global  */
  YYSYMBOL_program_locals = 47,            /* program_locals  */
  YYSYMBOL_program_local_list = 48,        /* program_local_list  */
  YYSYMBOL_program_local = 49,             /* program_local  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_int_function = 51,              /* int_function  */
  YYSYMBOL_52_1 = 52,                      /* $@1  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_float_function = 54,            /* float_function  */
  YYSYMBOL_55_3 = 55,                      /* $@3  */
  YYSYMBOL_56_4 = 56,                      /* $@4  */
  YYSYMBOL_char_function = 57,             /* char_function  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_bool_function = 60,             /* bool_function  */
  YYSYMBOL_61_7 = 61,                      /* $@7  */
  YYSYMBOL_62_8 = 62,                      /* $@8  */
  YYSYMBOL_void_function = 63,             /* void_function  */
  YYSYMBOL_64_9 = 64,                      /* $@9  */
  YYSYMBOL_65_10 = 65,                     /* $@10  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_parameter_list = 67,            /* parameter_list  */
  YYSYMBOL_parameter = 68,                 /* parameter  */
  YYSYMBOL_declaration_global = 69,        /* declaration_global  */
  YYSYMBOL_int_declaration_globals = 70,   /* int_declaration_globals  */
  YYSYMBOL_int_declaration_global_list = 71, /* int_declaration_global_list  */
  YYSYMBOL_int_declaration_global = 72,    /* int_declaration_global  */
  YYSYMBOL_array_global = 73,              /* array_global  */
  YYSYMBOL_float_declaration_globals = 74, /* float_declaration_globals  */
  YYSYMBOL_float_declaration_global_list = 75, /* float_declaration_global_list  */
  YYSYMBOL_float_declaration_global = 76,  /* float_declaration_global  */
  YYSYMBOL_char_declaration_globals = 77,  /* char_declaration_globals  */
  YYSYMBOL_char_declaration_global_list = 78, /* char_declaration_global_list  */
  YYSYMBOL_char_declaration_global = 79,   /* char_declaration_global  */
  YYSYMBOL_bool_declaration_globals = 80,  /* bool_declaration_globals  */
  YYSYMBOL_bool_declaration_global_list = 81, /* bool_declaration_global_list  */
  YYSYMBOL_bool_declaration_global = 82,   /* bool_declaration_global  */
  YYSYMBOL_array_values_global = 83,       /* array_values_global  */
  YYSYMBOL_term_const = 84,                /* term_const  */
  YYSYMBOL_declaration_local = 85,         /* declaration_local  */
  YYSYMBOL_int_declaration_locals = 86,    /* int_declaration_locals  */
  YYSYMBOL_int_declaration_local_list = 87, /* int_declaration_local_list  */
  YYSYMBOL_int_declaration_local = 88,     /* int_declaration_local  */
  YYSYMBOL_array_local = 89,               /* array_local  */
  YYSYMBOL_float_declaration_locals = 90,  /* float_declaration_locals  */
  YYSYMBOL_float_declaration_local_list = 91, /* float_declaration_local_list  */
  YYSYMBOL_float_declaration_local = 92,   /* float_declaration_local  */
  YYSYMBOL_char_declaration_locals = 93,   /* char_declaration_locals  */
  YYSYMBOL_char_declaration_local_list = 94, /* char_declaration_local_list  */
  YYSYMBOL_char_declaration_local = 95,    /* char_declaration_local  */
  YYSYMBOL_bool_declaration_locals = 96,   /* bool_declaration_locals  */
  YYSYMBOL_bool_declaration_local_list = 97, /* bool_declaration_local_list  */
  YYSYMBOL_bool_declaration_local = 98,    /* bool_declaration_local  */
  YYSYMBOL_array_values_local = 99,        /* array_values_local  */
  YYSYMBOL_comand = 100,                   /* comand  */
  YYSYMBOL_assignment = 101,               /* assignment  */
  YYSYMBOL_assignment_notfull = 102,       /* assignment_notfull  */
  YYSYMBOL_if_statement = 103,             /* if_statement  */
  YYSYMBOL_104_11 = 104,                   /* $@11  */
  YYSYMBOL_105_12 = 105,                   /* $@12  */
  YYSYMBOL_else_if_chain = 106,            /* else_if_chain  */
  YYSYMBOL_107_13 = 107,                   /* $@13  */
  YYSYMBOL_108_14 = 108,                   /* $@14  */
  YYSYMBOL_109_15 = 109,                   /* $@15  */
  YYSYMBOL_while = 110,                    /* while  */
  YYSYMBOL_111_16 = 111,                   /* $@16  */
  YYSYMBOL_while_aux = 112,                /* while_aux  */
  YYSYMBOL_for = 113,                      /* for  */
  YYSYMBOL_114_17 = 114,                   /* $@17  */
  YYSYMBOL_115_18 = 115,                   /* $@18  */
  YYSYMBOL_for_aux = 116,                  /* for_aux  */
  YYSYMBOL_printf = 117,                   /* printf  */
  YYSYMBOL_printf_args = 118,              /* printf_args  */
  YYSYMBOL_scanf = 119,                    /* scanf  */
  YYSYMBOL_scanf_args = 120,               /* scanf_args  */
  YYSYMBOL_return = 121,                   /* return  */
  YYSYMBOL_expression = 122,               /* expression  */
  YYSYMBOL_soma_sub = 123,                 /* soma_sub  */
  YYSYMBOL_mult_div = 124,                 /* mult_div  */
  YYSYMBOL_comparison = 125,               /* comparison  */
  YYSYMBOL_log_exp = 126,                  /* log_exp  */
  YYSYMBOL_cast = 127,                     /* cast  */
  YYSYMBOL_call_function = 128,            /* call_function  */
  YYSYMBOL_call_parameters = 129,          /* call_parameters  */
  YYSYMBOL_call_parameter_list = 130,      /* call_parameter_list  */
  YYSYMBOL_term = 131                      /* term  */
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
#define YYLAST   541

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  360

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   115,   115,   116,   120,   121,   125,   126,   127,   132,
     133,   137,   138,   142,   143,   148,   149,   150,   151,   152,
     158,   160,   158,   193,   195,   193,   228,   230,   228,   263,
     265,   263,   299,   301,   299,   332,   333,   336,   337,   341,
     351,   361,   371,   385,   386,   387,   388,   392,   395,   396,
     399,   406,   413,   416,   430,   457,   460,   461,   464,   471,
     481,   484,   485,   488,   495,   505,   508,   509,   512,   519,
     530,   538,   547,   557,   565,   566,   567,   568,   572,   575,
     576,   579,   583,   603,   607,   621,   646,   649,   650,   653,
     657,   679,   682,   683,   686,   690,   707,   710,   711,   714,
     718,   735,   743,   750,   751,   752,   753,   754,   755,   756,
     757,   762,   766,   811,   843,   863,   843,   883,   887,   890,
     890,   904,   925,   904,   940,   940,   962,   978,   985,   978,
    1008,  1018,  1039,  1040,  1050,  1071,  1072,  1087,  1098,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1120,  1142,  1167,
    1189,  1220,  1242,  1264,  1286,  1308,  1334,  1362,  1373,  1384,
    1398,  1404,  1410,  1415,  1420,  1425,  1430,  1437,  1448,  1493,
    1494,  1502,  1503,  1511,  1521,  1548,  1580
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
  "FOR", "VOID", "RETURN", "NUMBER", "ID", "STRING", "CARACTERE",
  "RECEIVE", "EQUAL", "NEQUAL", "LESS", "GREAT", "LEQUAL", "GEQUAL", "AND",
  "OR", "NOT", "PLUS", "MIN", "MULT", "DIV", "LEFTPAR", "RIGHTPAR",
  "LEFTKEYS", "RIGHTKEYS", "LEFTBRACKET", "RIGHTBRACKET", "COMMA", "DONE",
  "$accept", "program_globals", "program_global_list", "program_global",
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
  "assignment_notfull", "if_statement", "$@11", "$@12", "else_if_chain",
  "$@13", "$@14", "$@15", "while", "$@16", "while_aux", "for", "$@17",
  "$@18", "for_aux", "printf", "printf_args", "scanf", "scanf_args",
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

#define YYPACT_NINF (-167)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-5)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     301,  -167,   -16,     1,     9,    30,    56,   104,   305,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
       2,    84,  -167,   -18,    89,    25,   102,    55,   107,   124,
    -167,  -167,   305,   158,  -167,   158,    91,   128,   158,  -167,
     142,   134,   158,  -167,   171,   152,   158,  -167,   180,   153,
    -167,  -167,  -167,  -167,  -167,   106,   159,    28,    84,  -167,
    -167,   106,   179,    89,  -167,  -167,   106,   181,   102,  -167,
    -167,   106,   183,   107,  -167,   106,   187,   188,   189,   190,
    -167,   169,   191,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,   175,   106,  -167,   185,   193,
     194,   195,   197,   198,   169,   158,   200,   202,   204,   205,
     282,  -167,   149,  -167,   282,   282,   282,   282,   208,   209,
     210,   226,   229,   211,   213,  -167,  -167,    -4,     4,   220,
     282,  -167,  -167,  -167,  -167,  -167,  -167,  -167,   221,  -167,
    -167,  -167,  -167,  -167,  -167,   222,  -167,   158,   227,   239,
     244,   245,    33,    31,   225,  -167,   246,   243,   265,   253,
     276,   258,   284,   285,   280,   283,  -167,   -17,  -167,    33,
      27,  -167,    74,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
      33,   127,    33,  -167,  -167,   282,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,   299,    33,    33,   209,   275,    33,   210,
     277,    33,   226,   287,    33,   229,   292,   303,   308,    33,
     177,    33,  -167,   323,   328,   338,   343,   314,    33,    33,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
    -167,   434,   350,   358,   363,   192,  -167,  -167,   434,   228,
     225,  -167,   434,   243,  -167,   434,   253,  -167,   434,   258,
    -167,    33,   373,   407,   388,   329,  -167,   247,   114,   118,
     122,   162,  -167,   460,   460,   460,   460,   460,   460,   473,
     447,    32,    32,  -167,  -167,  -167,   127,  -167,   413,   402,
     428,  -167,  -167,  -167,  -167,   140,   412,   446,   435,  -167,
      33,  -167,    33,  -167,    33,  -167,    33,  -167,    33,  -167,
     363,    33,   282,   439,  -167,  -167,   308,  -167,   451,    95,
     344,   359,   374,   389,  -167,   434,   452,    33,  -167,   282,
     471,  -167,  -167,  -167,  -167,  -167,   150,   434,   463,    38,
     466,    68,  -167,    33,  -167,  -167,   468,   474,  -167,   434,
     475,    33,   476,    33,   282,   404,   282,   419,   470,  -167,
     472,  -167,  -167,  -167,   477,   282,   478,  -167,    68,  -167
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
       0,     0,     0,     0,     0,   126,   130,     0,     0,     0,
      11,    14,    74,    75,    76,    77,    13,   103,     0,   104,
     105,   106,   107,   108,   109,     0,    54,     0,     0,     0,
       0,     0,     0,    81,    79,    83,    94,    92,    89,    87,
      99,    97,     0,     0,     0,     0,   173,   174,   176,     0,
       0,   138,     0,   139,   140,   142,   143,   144,   145,   146,
       0,   169,     0,    22,    10,    11,   111,   110,    71,    28,
      25,    31,    34,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   132,   135,     0,
       0,     0,   159,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   112,   174,     0,   171,     0,    12,   114,    82,     0,
      79,    78,    95,    92,    91,    90,    87,    86,   100,    97,
      96,     0,     0,     0,     0,     0,   127,     0,     0,     0,
       0,     0,   141,   155,   156,   151,   152,   153,   154,   157,
     158,   147,   148,   149,   150,   168,     0,   170,     0,     0,
      84,    80,    93,    88,    98,   132,     0,     0,     0,   124,
       0,   175,     0,   161,     0,   165,     0,   163,     0,   167,
     171,     0,     9,     0,   133,   131,   135,   134,     0,     0,
       0,     0,     0,     0,   172,   113,     0,     0,   136,     9,
       0,   160,   164,   162,   166,   115,     0,   101,     0,     0,
       0,   117,    85,     0,   125,   128,   119,     0,   116,   102,
       0,     0,     0,     0,     9,     0,     9,     0,     0,   118,
       0,   121,   129,   120,     0,     9,     0,   122,   117,   123
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,   479,   515,  -106,   332,  -129,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,    80,   414,   423,  -167,  -167,   462,   485,
    -167,  -167,   454,   480,  -167,   464,   483,  -167,   453,   481,
    -167,   -14,   315,  -167,   288,   334,  -167,  -167,   286,   331,
    -167,   291,   336,  -167,   289,   326,  -167,  -167,  -167,   216,
    -167,  -167,  -167,   182,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,   252,  -167,   233,  -167,  -140,
    -167,  -167,  -167,  -167,  -167,  -110,  -167,   241,  -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,    31,    32,   129,   184,   130,     9,    10,    55,
      95,    11,    66,   100,    12,    61,    99,    13,    71,   101,
      14,    75,   102,    80,    97,    81,    15,    16,    37,    21,
      22,    17,    45,    26,    18,    41,    24,    19,    49,    28,
     112,    54,   131,   132,   197,   154,   155,   133,   203,   159,
     134,   200,   157,   135,   206,   161,   326,   136,   137,   138,
     139,   279,   331,   338,   342,   354,   358,   140,   308,   164,
     141,   290,   340,   165,   142,   252,   143,   254,   144,   172,
     173,   174,   175,   176,   177,   178,   233,   277,   179
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     145,   185,    20,    38,   145,   145,   145,   145,   148,   149,
     150,   151,   193,   166,   167,   234,   168,    39,   181,    23,
     145,    56,   211,    33,    60,   180,   169,    25,    65,   212,
     217,   170,    70,   213,   214,   215,   216,    34,   171,   181,
     231,    35,   235,   182,   166,   167,    42,   168,    27,    33,
     166,   167,   194,   168,   238,   239,   185,   169,   242,   180,
      43,   245,   170,   169,   248,   228,   229,    35,   170,   255,
     195,   257,   336,   337,    29,   145,    46,   182,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      47,   113,   293,   295,   297,   299,   218,   219,   220,   221,
     222,   223,   224,   225,    30,   226,   227,   228,   229,    57,
     300,   285,    76,    77,    78,    79,   230,   218,   219,   220,
     221,   222,   223,   224,   225,    36,   226,   227,   228,   229,
      40,   166,   232,   188,   168,   166,   232,   320,   168,   166,
     232,    84,   168,    44,   166,   232,    86,   168,    48,   292,
     309,    88,   310,   294,   311,    90,   312,   296,   313,    50,
      62,   315,   218,   219,   220,   221,   222,   223,   224,   225,
      59,   226,   227,   228,   229,    52,    64,   327,    53,   166,
     232,   251,   168,   119,   120,   121,   122,   146,   332,    67,
     147,   333,   145,   339,    69,    74,   316,   298,    72,    82,
      38,   345,    42,   347,    46,    91,    92,    93,    94,   145,
      96,   103,    98,   328,   218,   219,   220,   221,   222,   223,
     224,   225,   105,   226,   227,   228,   229,   153,   156,   106,
     107,   108,   278,   109,   145,   110,   145,   114,   348,   115,
     350,   116,   117,   152,   158,   145,   162,   160,   163,   356,
     218,   219,   220,   221,   222,   223,   224,   225,   183,   226,
     227,   228,   229,   186,   187,   189,   196,   198,   280,   218,
     219,   220,   221,   222,   223,   224,   225,   190,   226,   227,
     228,   229,   191,   192,   199,   118,   201,   291,   119,   120,
     121,   122,   123,   124,   202,   125,   126,   204,   127,   205,
     128,    -2,     1,   207,   208,    -4,     1,     2,     3,     4,
       5,     2,     3,     4,     5,   209,     6,   241,   210,   244,
       6,   218,   219,   220,   221,   222,   223,   224,   225,   247,
     226,   227,   228,   229,   250,   237,   218,   219,   220,   221,
     222,   223,   224,   225,   251,   226,   227,   228,   229,   253,
     262,   218,   219,   220,   221,   222,   223,   224,   225,   258,
     226,   227,   228,   229,   259,   289,   218,   219,   220,   221,
     222,   223,   224,   225,   260,   226,   227,   228,   229,   261,
     321,   218,   219,   220,   221,   222,   223,   224,   225,   211,
     226,   227,   228,   229,   275,   322,   218,   219,   220,   221,
     222,   223,   224,   225,   276,   226,   227,   228,   229,   286,
     323,   218,   219,   220,   221,   222,   223,   224,   225,   287,
     226,   227,   228,   229,   288,   324,   218,   219,   220,   221,
     222,   223,   224,   225,   301,   226,   227,   228,   229,   302,
     349,   218,   219,   220,   221,   222,   223,   224,   225,   303,
     226,   227,   228,   229,   305,   351,   218,   219,   220,   221,
     222,   223,   224,   225,   306,   226,   227,   228,   229,   218,
     219,   220,   221,   222,   223,   224,   317,   307,   226,   227,
     228,   229,    -5,    -5,    -5,    -5,    -5,    -5,   319,   329,
     325,   226,   227,   228,   229,   218,   219,   220,   221,   222,
     223,   334,   335,   341,   226,   227,   228,   229,   352,   343,
     353,    51,   344,   346,   355,     8,   357,   236,   111,   104,
      83,    58,    87,    63,    68,   256,    89,    85,   281,    73,
     240,   249,   283,   246,   282,   243,   330,   304,   284,   318,
     359,   314
};

static const yytype_int16 yycheck[] =
{
     110,   130,    18,    21,   114,   115,   116,   117,   114,   115,
     116,   117,   152,    17,    18,   181,    20,    35,    35,    18,
     130,    35,    39,    21,    38,    21,    30,    18,    42,   169,
     170,    35,    46,     6,     7,     8,     9,    35,    42,    35,
     180,    39,   182,    39,    17,    18,    21,    20,    18,    21,
      17,    18,    21,    20,   194,   195,   185,    30,   198,    21,
      35,   201,    35,    30,   204,    33,    34,    39,    35,   209,
      39,   211,     4,     5,    18,   185,    21,    39,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
      35,   105,   258,   259,   260,   261,    22,    23,    24,    25,
      26,    27,    28,    29,     0,    31,    32,    33,    34,    18,
     276,   251,     6,     7,     8,     9,    42,    22,    23,    24,
      25,    26,    27,    28,    29,    41,    31,    32,    33,    34,
      41,    17,    18,   147,    20,    17,    18,    42,    20,    17,
      18,    61,    20,    41,    17,    18,    66,    20,    41,    35,
     290,    71,   292,    35,   294,    75,   296,    35,   298,    35,
      18,   301,    22,    23,    24,    25,    26,    27,    28,    29,
      42,    31,    32,    33,    34,    17,    42,   317,    20,    17,
      18,    41,    20,     6,     7,     8,     9,    38,    38,    18,
      41,    41,   302,   333,    42,    42,   302,    35,    18,    40,
      21,   341,    21,   343,    21,    18,    18,    18,    18,   319,
      41,    36,    21,   319,    22,    23,    24,    25,    26,    27,
      28,    29,    37,    31,    32,    33,    34,    18,    18,    36,
      36,    36,    40,    36,   344,    37,   346,    37,   344,    37,
     346,    37,    37,    35,    18,   355,    35,    18,    35,   355,
      22,    23,    24,    25,    26,    27,    28,    29,    38,    31,
      32,    33,    34,    42,    42,    38,    41,    21,    40,    22,
      23,    24,    25,    26,    27,    28,    29,    38,    31,    32,
      33,    34,    38,    38,    41,     3,    21,    40,     6,     7,
       8,     9,    10,    11,    41,    13,    14,    21,    16,    41,
      18,     0,     1,    19,    19,     0,     1,     6,     7,     8,
       9,     6,     7,     8,     9,    35,    15,    42,    35,    42,
      15,    22,    23,    24,    25,    26,    27,    28,    29,    42,
      31,    32,    33,    34,    42,    36,    22,    23,    24,    25,
      26,    27,    28,    29,    41,    31,    32,    33,    34,    41,
      36,    22,    23,    24,    25,    26,    27,    28,    29,    36,
      31,    32,    33,    34,    36,    36,    22,    23,    24,    25,
      26,    27,    28,    29,    36,    31,    32,    33,    34,    36,
      36,    22,    23,    24,    25,    26,    27,    28,    29,    39,
      31,    32,    33,    34,    36,    36,    22,    23,    24,    25,
      26,    27,    28,    29,    41,    31,    32,    33,    34,    36,
      36,    22,    23,    24,    25,    26,    27,    28,    29,    12,
      31,    32,    33,    34,    36,    36,    22,    23,    24,    25,
      26,    27,    28,    29,    21,    31,    32,    33,    34,    37,
      36,    22,    23,    24,    25,    26,    27,    28,    29,    21,
      31,    32,    33,    34,    42,    36,    22,    23,    24,    25,
      26,    27,    28,    29,    18,    31,    32,    33,    34,    22,
      23,    24,    25,    26,    27,    28,    37,    42,    31,    32,
      33,    34,    22,    23,    24,    25,    26,    27,    37,    18,
      38,    31,    32,    33,    34,    22,    23,    24,    25,    26,
      27,    38,    36,    35,    31,    32,    33,    34,    38,    35,
      38,    32,    37,    37,    37,     0,    38,   185,   104,    96,
      58,    36,    68,    40,    44,   210,    73,    63,   240,    48,
     196,   205,   246,   202,   243,   199,   320,   285,   249,   306,
     358,   300
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,     7,     8,     9,    15,    44,    46,    50,
      51,    54,    57,    60,    63,    69,    70,    74,    77,    80,
      18,    72,    73,    18,    79,    18,    76,    18,    82,    18,
       0,    45,    46,    21,    35,    39,    41,    71,    21,    35,
      41,    78,    21,    35,    41,    75,    21,    35,    41,    81,
      35,    45,    17,    20,    84,    52,    84,    18,    72,    42,
      84,    58,    18,    79,    42,    84,    55,    18,    76,    42,
      84,    61,    18,    82,    42,    64,     6,     7,     8,     9,
      66,    68,    40,    71,    66,    78,    66,    75,    66,    81,
      66,    18,    18,    18,    18,    53,    41,    67,    21,    59,
      56,    62,    65,    36,    68,    37,    36,    36,    36,    36,
      37,    67,    83,    84,    37,    37,    37,    37,     3,     6,
       7,     8,     9,    10,    11,    13,    14,    16,    18,    47,
      49,    85,    86,    90,    93,    96,   100,   101,   102,   103,
     110,   113,   117,   119,   121,   128,    38,    41,    47,    47,
      47,    47,    35,    18,    88,    89,    18,    95,    18,    92,
      18,    98,    35,    35,   112,   116,    17,    18,    20,    30,
      35,    42,   122,   123,   124,   125,   126,   127,   128,   131,
      21,    35,    39,    38,    48,    49,    42,    42,    84,    38,
      38,    38,    38,   122,    21,    39,    41,    87,    21,    41,
      94,    21,    41,    91,    21,    41,    97,    19,    19,    35,
      35,    39,   122,     6,     7,     8,     9,   122,    22,    23,
      24,    25,    26,    27,    28,    29,    31,    32,    33,    34,
      42,   122,    18,   129,   131,   122,    48,    36,   122,   122,
      88,    42,   122,    95,    42,   122,    92,    42,   122,    98,
      42,    41,   118,    41,   120,   122,    85,   122,    36,    36,
      36,    36,    36,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,    36,    41,   130,    40,   104,
      40,    87,    94,    91,    97,   122,    36,    12,    36,    36,
     114,    40,    35,   131,    35,   131,    35,   131,    35,   131,
     131,    21,    37,    21,   118,    42,    18,    42,   111,   122,
     122,   122,   122,   122,   130,   122,    47,    37,   120,    37,
      42,    36,    36,    36,    36,    38,    99,   122,    47,    18,
     102,   105,    38,    41,    38,    36,     4,     5,   106,   122,
     115,    35,   107,    35,    37,   122,    37,   122,    47,    36,
      47,    36,    38,    38,   108,    37,    47,    38,   109,   106
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    46,    46,    46,    47,
      47,    48,    48,    49,    49,    50,    50,    50,    50,    50,
      52,    53,    51,    55,    56,    54,    58,    59,    57,    61,
      62,    60,    64,    65,    63,    66,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78,    79,    79,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    85,    85,    85,    85,    86,    87,
      87,    88,    88,    88,    89,    89,    90,    91,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     100,   101,   102,   102,   104,   105,   103,   106,   106,   107,
     106,   108,   109,   106,   111,   110,   112,   114,   115,   113,
     116,   117,   118,   118,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125,   125,   125,   126,   126,   126,
     127,   127,   127,   127,   127,   127,   127,   127,   128,   129,
     129,   130,   130,   131,   131,   131,   131
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
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     3,     6,     0,     0,    10,     0,     4,     0,
       5,     0,     0,    10,     0,     9,     0,     0,     0,    13,
       0,     6,     0,     3,     6,     0,     4,     3,     2,     1,
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
#line 115 "compiler/parser.y"
                  {}
#line 1792 "objects/codeIR/parser.tab.c"
    break;

  case 3: /* program_globals: program_global program_global_list  */
#line 116 "compiler/parser.y"
                                         {}
#line 1798 "objects/codeIR/parser.tab.c"
    break;

  case 4: /* program_global_list: %empty  */
#line 120 "compiler/parser.y"
                  {}
#line 1804 "objects/codeIR/parser.tab.c"
    break;

  case 5: /* program_global_list: program_global program_global_list  */
#line 121 "compiler/parser.y"
                                         {}
#line 1810 "objects/codeIR/parser.tab.c"
    break;

  case 6: /* program_global: function  */
#line 125 "compiler/parser.y"
               {}
#line 1816 "objects/codeIR/parser.tab.c"
    break;

  case 7: /* program_global: declaration_global  */
#line 126 "compiler/parser.y"
                         {}
#line 1822 "objects/codeIR/parser.tab.c"
    break;

  case 8: /* program_global: error  */
#line 127 "compiler/parser.y"
            { yyerrok; yyclearin; }
#line 1828 "objects/codeIR/parser.tab.c"
    break;

  case 9: /* program_locals: %empty  */
#line 132 "compiler/parser.y"
                  {}
#line 1834 "objects/codeIR/parser.tab.c"
    break;

  case 10: /* program_locals: program_local program_local_list  */
#line 133 "compiler/parser.y"
                                       {}
#line 1840 "objects/codeIR/parser.tab.c"
    break;

  case 11: /* program_local_list: %empty  */
#line 137 "compiler/parser.y"
                  {}
#line 1846 "objects/codeIR/parser.tab.c"
    break;

  case 12: /* program_local_list: program_local program_local_list  */
#line 138 "compiler/parser.y"
                                       {}
#line 1852 "objects/codeIR/parser.tab.c"
    break;

  case 13: /* program_local: comand  */
#line 142 "compiler/parser.y"
             {}
#line 1858 "objects/codeIR/parser.tab.c"
    break;

  case 14: /* program_local: declaration_local  */
#line 143 "compiler/parser.y"
                        {}
#line 1864 "objects/codeIR/parser.tab.c"
    break;

  case 15: /* function: int_function  */
#line 148 "compiler/parser.y"
                   {}
#line 1870 "objects/codeIR/parser.tab.c"
    break;

  case 16: /* function: float_function  */
#line 149 "compiler/parser.y"
                     {}
#line 1876 "objects/codeIR/parser.tab.c"
    break;

  case 17: /* function: char_function  */
#line 150 "compiler/parser.y"
                    {}
#line 1882 "objects/codeIR/parser.tab.c"
    break;

  case 18: /* function: bool_function  */
#line 151 "compiler/parser.y"
                    {}
#line 1888 "objects/codeIR/parser.tab.c"
    break;

  case 19: /* function: void_function  */
#line 152 "compiler/parser.y"
                    {}
#line 1894 "objects/codeIR/parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 158 "compiler/parser.y"
                     {
        pushScope();
    }
#line 1902 "objects/codeIR/parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 160 "compiler/parser.y"
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
#line 1935 "objects/codeIR/parser.tab.c"
    break;

  case 22: /* int_function: INT ID LEFTPAR $@1 parameters $@2 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 187 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1943 "objects/codeIR/parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 193 "compiler/parser.y"
                       {
            pushScope();
        }
#line 1951 "objects/codeIR/parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 195 "compiler/parser.y"
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
#line 1984 "objects/codeIR/parser.tab.c"
    break;

  case 25: /* float_function: FLOAT ID LEFTPAR $@3 parameters $@4 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 222 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 1992 "objects/codeIR/parser.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 228 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2000 "objects/codeIR/parser.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 230 "compiler/parser.y"
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
#line 2033 "objects/codeIR/parser.tab.c"
    break;

  case 28: /* char_function: CHAR ID LEFTPAR $@5 parameters $@6 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 257 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2041 "objects/codeIR/parser.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 263 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2049 "objects/codeIR/parser.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 265 "compiler/parser.y"
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
#line 2082 "objects/codeIR/parser.tab.c"
    break;

  case 31: /* bool_function: BOOL ID LEFTPAR $@7 parameters $@8 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 292 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2090 "objects/codeIR/parser.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 299 "compiler/parser.y"
                      {
            pushScope();
    }
#line 2098 "objects/codeIR/parser.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 301 "compiler/parser.y"
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
#line 2128 "objects/codeIR/parser.tab.c"
    break;

  case 34: /* void_function: VOID ID LEFTPAR $@9 parameters $@10 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 325 "compiler/parser.y"
                                                 {
        popScope();
    }
#line 2136 "objects/codeIR/parser.tab.c"
    break;

  case 36: /* parameters: parameter parameter_list  */
#line 333 "compiler/parser.y"
                               {}
#line 2142 "objects/codeIR/parser.tab.c"
    break;

  case 38: /* parameter_list: COMMA parameter parameter_list  */
#line 337 "compiler/parser.y"
                                     {}
#line 2148 "objects/codeIR/parser.tab.c"
    break;

  case 39: /* parameter: INT ID  */
#line 341 "compiler/parser.y"
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
#line 2163 "objects/codeIR/parser.tab.c"
    break;

  case 40: /* parameter: FLOAT ID  */
#line 351 "compiler/parser.y"
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
#line 2178 "objects/codeIR/parser.tab.c"
    break;

  case 41: /* parameter: CHAR ID  */
#line 361 "compiler/parser.y"
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
#line 2193 "objects/codeIR/parser.tab.c"
    break;

  case 42: /* parameter: BOOL ID  */
#line 371 "compiler/parser.y"
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
#line 2208 "objects/codeIR/parser.tab.c"
    break;

  case 43: /* declaration_global: int_declaration_globals  */
#line 385 "compiler/parser.y"
                              {}
#line 2214 "objects/codeIR/parser.tab.c"
    break;

  case 44: /* declaration_global: float_declaration_globals  */
#line 386 "compiler/parser.y"
                                {}
#line 2220 "objects/codeIR/parser.tab.c"
    break;

  case 45: /* declaration_global: char_declaration_globals  */
#line 387 "compiler/parser.y"
                               {}
#line 2226 "objects/codeIR/parser.tab.c"
    break;

  case 46: /* declaration_global: bool_declaration_globals  */
#line 388 "compiler/parser.y"
                               {}
#line 2232 "objects/codeIR/parser.tab.c"
    break;

  case 47: /* int_declaration_globals: INT int_declaration_global int_declaration_global_list DONE  */
#line 392 "compiler/parser.y"
                                                                  {}
#line 2238 "objects/codeIR/parser.tab.c"
    break;

  case 50: /* int_declaration_global: ID  */
#line 399 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2250 "objects/codeIR/parser.tab.c"
    break;

  case 51: /* int_declaration_global: ID RECEIVE term_const  */
#line 406 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2262 "objects/codeIR/parser.tab.c"
    break;

  case 52: /* int_declaration_global: array_global  */
#line 413 "compiler/parser.y"
                   {}
#line 2268 "objects/codeIR/parser.tab.c"
    break;

  case 53: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET  */
#line 416 "compiler/parser.y"
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
#line 2287 "objects/codeIR/parser.tab.c"
    break;

  case 54: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET RECEIVE LEFTKEYS array_values_global RIGHTKEYS  */
#line 430 "compiler/parser.y"
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
#line 2314 "objects/codeIR/parser.tab.c"
    break;

  case 55: /* float_declaration_globals: FLOAT float_declaration_global float_declaration_global_list DONE  */
#line 457 "compiler/parser.y"
                                                                        {}
#line 2320 "objects/codeIR/parser.tab.c"
    break;

  case 58: /* float_declaration_global: ID  */
#line 464 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstReal(type, 0.0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2332 "objects/codeIR/parser.tab.c"
    break;

  case 59: /* float_declaration_global: ID RECEIVE term_const  */
#line 471 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2344 "objects/codeIR/parser.tab.c"
    break;

  case 60: /* char_declaration_globals: CHAR char_declaration_global char_declaration_global_list DONE  */
#line 481 "compiler/parser.y"
                                                                     {}
#line 2350 "objects/codeIR/parser.tab.c"
    break;

  case 61: /* char_declaration_global_list: %empty  */
#line 484 "compiler/parser.y"
                  {}
#line 2356 "objects/codeIR/parser.tab.c"
    break;

  case 62: /* char_declaration_global_list: COMMA char_declaration_global char_declaration_global_list  */
#line 485 "compiler/parser.y"
                                                                 {}
#line 2362 "objects/codeIR/parser.tab.c"
    break;

  case 63: /* char_declaration_global: ID  */
#line 488 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2374 "objects/codeIR/parser.tab.c"
    break;

  case 64: /* char_declaration_global: ID RECEIVE term_const  */
#line 495 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2386 "objects/codeIR/parser.tab.c"
    break;

  case 65: /* bool_declaration_globals: BOOL bool_declaration_global bool_declaration_global_list DONE  */
#line 505 "compiler/parser.y"
                                                                     {}
#line 2392 "objects/codeIR/parser.tab.c"
    break;

  case 66: /* bool_declaration_global_list: %empty  */
#line 508 "compiler/parser.y"
                  {}
#line 2398 "objects/codeIR/parser.tab.c"
    break;

  case 67: /* bool_declaration_global_list: COMMA bool_declaration_global bool_declaration_global_list  */
#line 509 "compiler/parser.y"
                                                                 {}
#line 2404 "objects/codeIR/parser.tab.c"
    break;

  case 68: /* bool_declaration_global: ID  */
#line 512 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2416 "objects/codeIR/parser.tab.c"
    break;

  case 69: /* bool_declaration_global: ID RECEIVE term_const  */
#line 519 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2428 "objects/codeIR/parser.tab.c"
    break;

  case 70: /* array_values_global: term_const  */
#line 530 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2441 "objects/codeIR/parser.tab.c"
    break;

  case 71: /* array_values_global: array_values_global COMMA term_const  */
#line 538 "compiler/parser.y"
                                           {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
    }
#line 2451 "objects/codeIR/parser.tab.c"
    break;

  case 72: /* term_const: NUMBER  */
#line 547 "compiler/parser.y"
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
#line 2466 "objects/codeIR/parser.tab.c"
    break;

  case 73: /* term_const: CARACTERE  */
#line 557 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 2476 "objects/codeIR/parser.tab.c"
    break;

  case 74: /* declaration_local: int_declaration_locals  */
#line 565 "compiler/parser.y"
                             {}
#line 2482 "objects/codeIR/parser.tab.c"
    break;

  case 75: /* declaration_local: float_declaration_locals  */
#line 566 "compiler/parser.y"
                               {}
#line 2488 "objects/codeIR/parser.tab.c"
    break;

  case 76: /* declaration_local: char_declaration_locals  */
#line 567 "compiler/parser.y"
                              {}
#line 2494 "objects/codeIR/parser.tab.c"
    break;

  case 77: /* declaration_local: bool_declaration_locals  */
#line 568 "compiler/parser.y"
                              {}
#line 2500 "objects/codeIR/parser.tab.c"
    break;

  case 78: /* int_declaration_locals: INT int_declaration_local int_declaration_local_list DONE  */
#line 572 "compiler/parser.y"
                                                                {}
#line 2506 "objects/codeIR/parser.tab.c"
    break;

  case 79: /* int_declaration_local_list: %empty  */
#line 575 "compiler/parser.y"
                  {}
#line 2512 "objects/codeIR/parser.tab.c"
    break;

  case 80: /* int_declaration_local_list: COMMA int_declaration_local int_declaration_local_list  */
#line 576 "compiler/parser.y"
                                                             {}
#line 2518 "objects/codeIR/parser.tab.c"
    break;

  case 81: /* int_declaration_local: ID  */
#line 579 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        allocaVars((yyvsp[0].id), TYPE_INT);
    }
#line 2527 "objects/codeIR/parser.tab.c"
    break;

  case 82: /* int_declaration_local: ID RECEIVE expression  */
#line 583 "compiler/parser.y"
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
#line 2552 "objects/codeIR/parser.tab.c"
    break;

  case 84: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 607 "compiler/parser.y"
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
#line 2571 "objects/codeIR/parser.tab.c"
    break;

  case 85: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS  */
#line 621 "compiler/parser.y"
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
#line 2598 "objects/codeIR/parser.tab.c"
    break;

  case 86: /* float_declaration_locals: FLOAT float_declaration_local float_declaration_local_list DONE  */
#line 646 "compiler/parser.y"
                                                                      {}
#line 2604 "objects/codeIR/parser.tab.c"
    break;

  case 87: /* float_declaration_local_list: %empty  */
#line 649 "compiler/parser.y"
                  {}
#line 2610 "objects/codeIR/parser.tab.c"
    break;

  case 88: /* float_declaration_local_list: COMMA float_declaration_local float_declaration_local_list  */
#line 650 "compiler/parser.y"
                                                                 {}
#line 2616 "objects/codeIR/parser.tab.c"
    break;

  case 89: /* float_declaration_local: ID  */
#line 653 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        allocaVars((yyvsp[0].id), TYPE_FLOAT);
    }
#line 2625 "objects/codeIR/parser.tab.c"
    break;

  case 90: /* float_declaration_local: ID RECEIVE expression  */
#line 657 "compiler/parser.y"
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
#line 2649 "objects/codeIR/parser.tab.c"
    break;

  case 91: /* char_declaration_locals: CHAR char_declaration_local char_declaration_local_list DONE  */
#line 679 "compiler/parser.y"
                                                                   {}
#line 2655 "objects/codeIR/parser.tab.c"
    break;

  case 92: /* char_declaration_local_list: %empty  */
#line 682 "compiler/parser.y"
                  {}
#line 2661 "objects/codeIR/parser.tab.c"
    break;

  case 93: /* char_declaration_local_list: COMMA char_declaration_local char_declaration_local_list  */
#line 683 "compiler/parser.y"
                                                               {}
#line 2667 "objects/codeIR/parser.tab.c"
    break;

  case 94: /* char_declaration_local: ID  */
#line 686 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        allocaVars((yyvsp[0].id), TYPE_CHAR);
    }
#line 2676 "objects/codeIR/parser.tab.c"
    break;

  case 95: /* char_declaration_local: ID RECEIVE expression  */
#line 690 "compiler/parser.y"
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
#line 2695 "objects/codeIR/parser.tab.c"
    break;

  case 96: /* bool_declaration_locals: BOOL bool_declaration_local bool_declaration_local_list DONE  */
#line 707 "compiler/parser.y"
                                                                   {}
#line 2701 "objects/codeIR/parser.tab.c"
    break;

  case 97: /* bool_declaration_local_list: %empty  */
#line 710 "compiler/parser.y"
                  {}
#line 2707 "objects/codeIR/parser.tab.c"
    break;

  case 98: /* bool_declaration_local_list: COMMA bool_declaration_local bool_declaration_local_list  */
#line 711 "compiler/parser.y"
                                                               {}
#line 2713 "objects/codeIR/parser.tab.c"
    break;

  case 99: /* bool_declaration_local: ID  */
#line 714 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        allocaVars((yyvsp[0].id), TYPE_BOOL);
    }
#line 2722 "objects/codeIR/parser.tab.c"
    break;

  case 100: /* bool_declaration_local: ID RECEIVE expression  */
#line 718 "compiler/parser.y"
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
#line 2741 "objects/codeIR/parser.tab.c"
    break;

  case 101: /* array_values_local: expression  */
#line 735 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2754 "objects/codeIR/parser.tab.c"
    break;

  case 102: /* array_values_local: array_values_local COMMA expression  */
#line 743 "compiler/parser.y"
                                          {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
}
#line 2764 "objects/codeIR/parser.tab.c"
    break;

  case 103: /* comand: assignment  */
#line 750 "compiler/parser.y"
                   {}
#line 2770 "objects/codeIR/parser.tab.c"
    break;

  case 104: /* comand: if_statement  */
#line 751 "compiler/parser.y"
                     {}
#line 2776 "objects/codeIR/parser.tab.c"
    break;

  case 105: /* comand: while  */
#line 752 "compiler/parser.y"
              {}
#line 2782 "objects/codeIR/parser.tab.c"
    break;

  case 106: /* comand: for  */
#line 753 "compiler/parser.y"
            {}
#line 2788 "objects/codeIR/parser.tab.c"
    break;

  case 107: /* comand: printf  */
#line 754 "compiler/parser.y"
               {}
#line 2794 "objects/codeIR/parser.tab.c"
    break;

  case 108: /* comand: scanf  */
#line 755 "compiler/parser.y"
              {}
#line 2800 "objects/codeIR/parser.tab.c"
    break;

  case 109: /* comand: return  */
#line 756 "compiler/parser.y"
               {}
#line 2806 "objects/codeIR/parser.tab.c"
    break;

  case 110: /* comand: call_function DONE  */
#line 757 "compiler/parser.y"
                           {}
#line 2812 "objects/codeIR/parser.tab.c"
    break;

  case 112: /* assignment_notfull: ID RECEIVE expression  */
#line 766 "compiler/parser.y"
                            {
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
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
        LLVMValueRef value = (yyvsp[0].number).llvm_value;
        if(symbol) {
            if (symbol->type == (yyvsp[0].number).type) {
                LLVMBuildStore(builder, value, var);
            }
            // Cast se necessário
            else if (symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
            }
            else if (symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                printf("Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            }
        }

        // Atualiza a tabela de símbolos
        if (symbol) {
            if (symbol->type == (yyvsp[0].number).type) {
                insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, symbol->type);
            } else if (symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, symbol->type);
            } else if (symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                insertSymbol((yyvsp[-2].id), (int)(yyvsp[0].number).value, symbol->type);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        } else {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
        }
    }
#line 2862 "objects/codeIR/parser.tab.c"
    break;

  case 113: /* assignment_notfull: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE expression  */
#line 811 "compiler/parser.y"
                                                                {
        ArraySymbol* symbol = findArraySymbol((yyvsp[-5].id));
        if (!symbol) {
            fprintf(stderr, "Error: variable '%s' is not an array or not exist at line %d.\n", (yyvsp[-5].id), yylineno);
        }
        LLVMValueRef var = getVarLLVM((yyvsp[-5].id));
        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
        LLVMValueRef index = (yyvsp[-3].number).llvm_value;
        LLVMValueRef value = (yyvsp[0].number).llvm_value;

        // Gera o índice do array
        LLVMValueRef indices[2] = { LLVMConstInt(LLVMInt32TypeInContext(context), 0, false), index };
        LLVMValueRef array_ptr = LLVMBuildGEP2(builder, LLVMInt32TypeInContext(context), var, indices, 2, "arrayptr");

        // Armazena o valor no array
        if ((yyvsp[0].number).type == TYPE_INT) {
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-5].id), (yyvsp[0].number).value, (int)(yyvsp[-3].number).value);
        } else if ((yyvsp[0].number).type == TYPE_FLOAT) {
            printf("Warning: casting float to int for array '%s' at line %d.\n", (yyvsp[-5].id), yylineno);
            value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-5].id), (int)(yyvsp[0].number).value, (int)(yyvsp[-3].number).value);
        } else {
            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
        }
    }
#line 2894 "objects/codeIR/parser.tab.c"
    break;

  case 114: /* $@11: %empty  */
#line 843 "compiler/parser.y"
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
#line 2920 "objects/codeIR/parser.tab.c"
    break;

  case 115: /* $@12: %empty  */
#line 863 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 2933 "objects/codeIR/parser.tab.c"
    break;

  case 116: /* if_statement: IF LEFTPAR expression RIGHTPAR $@11 LEFTKEYS program_locals RIGHTKEYS $@12 else_if_chain  */
#line 870 "compiler/parser.y"
                    {
        // Finaliza este contexto
        ConditionalContext current = pop_cond_context();
        LLVMPositionBuilderAtEnd(builder, current.endBB);
        
        LLVMBasicBlockRef endBB = LLVMAppendBasicBlockInContext(context, currentFunc, "endif");
        LLVMBuildBr(builder, endBB);

        LLVMPositionBuilderAtEnd(builder, endBB);
    }
#line 2948 "objects/codeIR/parser.tab.c"
    break;

  case 117: /* else_if_chain: %empty  */
#line 883 "compiler/parser.y"
                  {
        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 2957 "objects/codeIR/parser.tab.c"
    break;

  case 118: /* else_if_chain: ELSE LEFTPAR expression RIGHTPAR  */
#line 887 "compiler/parser.y"
                                       {
        fprintf(stderr, "Error: else cannot have a condition at line %d.\n", yylineno);
    }
#line 2965 "objects/codeIR/parser.tab.c"
    break;

  case 119: /* $@13: %empty  */
#line 890 "compiler/parser.y"
           {

        pushScope();
        
        ConditionalContext* current = top_cond_context();
        // Transforma o nextCondBB em bloco else
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 2978 "objects/codeIR/parser.tab.c"
    break;

  case 120: /* else_if_chain: ELSE $@13 LEFTKEYS program_locals RIGHTKEYS  */
#line 897 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 2990 "objects/codeIR/parser.tab.c"
    break;

  case 121: /* $@14: %empty  */
#line 904 "compiler/parser.y"
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
#line 3017 "objects/codeIR/parser.tab.c"
    break;

  case 122: /* $@15: %empty  */
#line 925 "compiler/parser.y"
                                        {

        popScope();

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3030 "objects/codeIR/parser.tab.c"
    break;

  case 123: /* else_if_chain: ELSEIF LEFTPAR expression RIGHTPAR $@14 LEFTKEYS program_locals RIGHTKEYS $@15 else_if_chain  */
#line 932 "compiler/parser.y"
                    {}
#line 3036 "objects/codeIR/parser.tab.c"
    break;

  case 124: /* $@16: %empty  */
#line 940 "compiler/parser.y"
                                                  {
        pushScope();
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-3].while_blocks).bodyBB, (yyvsp[-3].while_blocks).endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-3].while_blocks).bodyBB);
    }
#line 3052 "objects/codeIR/parser.tab.c"
    break;

  case 125: /* while: WHILE while_aux LEFTPAR expression RIGHTPAR $@16 LEFTKEYS program_locals RIGHTKEYS  */
#line 950 "compiler/parser.y"
                                        {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, (yyvsp[-7].while_blocks).condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).endWHILEBB);

        popScope();
    }
#line 3066 "objects/codeIR/parser.tab.c"
    break;

  case 126: /* while_aux: %empty  */
#line 962 "compiler/parser.y"
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
#line 3083 "objects/codeIR/parser.tab.c"
    break;

  case 127: /* $@17: %empty  */
#line 978 "compiler/parser.y"
                                            {
        // Pula direto para o bloco de condição após a declaração
        LLVMBuildBr(builder, (yyvsp[-2].while_blocks).condBB);

        // Posiciona no bloco condicional
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-2].while_blocks).condBB);
    }
#line 3095 "objects/codeIR/parser.tab.c"
    break;

  case 128: /* $@18: %empty  */
#line 985 "compiler/parser.y"
                                                {
        pushScope();
        if ((yyvsp[-3].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        // Condicional
        LLVMBuildCondBr(builder, (yyvsp[-3].number).llvm_value, (yyvsp[-7].while_blocks).bodyBB, (yyvsp[-7].while_blocks).endWHILEBB);

        // Corpo do for
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).bodyBB);
    }
#line 3112 "objects/codeIR/parser.tab.c"
    break;

  case 129: /* for: FOR for_aux LEFTPAR declaration_local $@17 expression DONE assignment_notfull RIGHTPAR $@18 LEFTKEYS program_locals RIGHTKEYS  */
#line 996 "compiler/parser.y"
                                        {
        // Volta para condicional
        LLVMBuildBr(builder, (yyvsp[-11].while_blocks).condBB);

        // Posiciona no final do for
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-11].while_blocks).endWHILEBB);

        popScope();
    }
#line 3126 "objects/codeIR/parser.tab.c"
    break;

  case 130: /* for_aux: %empty  */
#line 1008 "compiler/parser.y"
      {
        // Cria os blocos condicional, corpo e final
        (yyval.while_blocks).condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.cond");
        (yyval.while_blocks).bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.body");
        (yyval.while_blocks).endWHILEBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.end");
    }
#line 3137 "objects/codeIR/parser.tab.c"
    break;

  case 131: /* printf: PRINTF LEFTPAR STRING printf_args RIGHTPAR DONE  */
#line 1018 "compiler/parser.y"
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
#line 3160 "objects/codeIR/parser.tab.c"
    break;

  case 132: /* printf_args: %empty  */
#line 1039 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3166 "objects/codeIR/parser.tab.c"
    break;

  case 133: /* printf_args: COMMA expression printf_args  */
#line 1040 "compiler/parser.y"
                                   {
        (yyval.printf).values[0] = (yyvsp[-1].number).llvm_value;
        for (int i = 0; i < (yyvsp[0].printf).count; i++)
            (yyval.printf).values[i+1] = (yyvsp[0].printf).values[i];
        (yyval.printf).count = (yyvsp[0].printf).count + 1;
    }
#line 3177 "objects/codeIR/parser.tab.c"
    break;

  case 134: /* scanf: SCANF LEFTPAR STRING scanf_args RIGHTPAR DONE  */
#line 1050 "compiler/parser.y"
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
#line 3200 "objects/codeIR/parser.tab.c"
    break;

  case 135: /* scanf_args: %empty  */
#line 1071 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3206 "objects/codeIR/parser.tab.c"
    break;

  case 136: /* scanf_args: COMMA ADDRESS ID scanf_args  */
#line 1072 "compiler/parser.y"
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
#line 3223 "objects/codeIR/parser.tab.c"
    break;

  case 137: /* return: RETURN expression DONE  */
#line 1087 "compiler/parser.y"
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
#line 3239 "objects/codeIR/parser.tab.c"
    break;

  case 138: /* return: RETURN DONE  */
#line 1098 "compiler/parser.y"
                  {
        if(functionList->returnType != TYPE_VOID) {
            fprintf(stderr, "Error: function '%s' must return a value at line %d.\n", functionList->id, yylineno);
        } else {
            LLVMBuildRetVoid(builder);
        }
}
#line 3251 "objects/codeIR/parser.tab.c"
    break;

  case 139: /* expression: soma_sub  */
#line 1109 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3257 "objects/codeIR/parser.tab.c"
    break;

  case 140: /* expression: mult_div  */
#line 1110 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3263 "objects/codeIR/parser.tab.c"
    break;

  case 141: /* expression: LEFTPAR expression RIGHTPAR  */
#line 1111 "compiler/parser.y"
                                  { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; }
#line 3269 "objects/codeIR/parser.tab.c"
    break;

  case 142: /* expression: comparison  */
#line 1112 "compiler/parser.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3275 "objects/codeIR/parser.tab.c"
    break;

  case 143: /* expression: log_exp  */
#line 1113 "compiler/parser.y"
              { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3281 "objects/codeIR/parser.tab.c"
    break;

  case 144: /* expression: cast  */
#line 1114 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3287 "objects/codeIR/parser.tab.c"
    break;

  case 145: /* expression: call_function  */
#line 1115 "compiler/parser.y"
                    { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3293 "objects/codeIR/parser.tab.c"
    break;

  case 146: /* expression: term  */
#line 1116 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3299 "objects/codeIR/parser.tab.c"
    break;

  case 147: /* soma_sub: expression PLUS expression  */
#line 1120 "compiler/parser.y"
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
#line 3326 "objects/codeIR/parser.tab.c"
    break;

  case 148: /* soma_sub: expression MIN expression  */
#line 1142 "compiler/parser.y"
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
#line 3353 "objects/codeIR/parser.tab.c"
    break;

  case 149: /* mult_div: expression MULT expression  */
#line 1167 "compiler/parser.y"
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
#line 3380 "objects/codeIR/parser.tab.c"
    break;

  case 150: /* mult_div: expression DIV expression  */
#line 1189 "compiler/parser.y"
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
#line 3413 "objects/codeIR/parser.tab.c"
    break;

  case 151: /* comparison: expression LESS expression  */
#line 1220 "compiler/parser.y"
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
#line 3440 "objects/codeIR/parser.tab.c"
    break;

  case 152: /* comparison: expression GREAT expression  */
#line 1242 "compiler/parser.y"
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
#line 3467 "objects/codeIR/parser.tab.c"
    break;

  case 153: /* comparison: expression LEQUAL expression  */
#line 1264 "compiler/parser.y"
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
#line 3494 "objects/codeIR/parser.tab.c"
    break;

  case 154: /* comparison: expression GEQUAL expression  */
#line 1286 "compiler/parser.y"
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
#line 3521 "objects/codeIR/parser.tab.c"
    break;

  case 155: /* comparison: expression EQUAL expression  */
#line 1308 "compiler/parser.y"
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
#line 3552 "objects/codeIR/parser.tab.c"
    break;

  case 156: /* comparison: expression NEQUAL expression  */
#line 1334 "compiler/parser.y"
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
#line 3582 "objects/codeIR/parser.tab.c"
    break;

  case 157: /* log_exp: expression AND expression  */
#line 1362 "compiler/parser.y"
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
#line 3598 "objects/codeIR/parser.tab.c"
    break;

  case 158: /* log_exp: expression OR expression  */
#line 1373 "compiler/parser.y"
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
#line 3614 "objects/codeIR/parser.tab.c"
    break;

  case 159: /* log_exp: NOT expression  */
#line 1384 "compiler/parser.y"
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
#line 3630 "objects/codeIR/parser.tab.c"
    break;

  case 160: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1398 "compiler/parser.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3641 "objects/codeIR/parser.tab.c"
    break;

  case 161: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 1404 "compiler/parser.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
    }
#line 3652 "objects/codeIR/parser.tab.c"
    break;

  case 162: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1410 "compiler/parser.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3662 "objects/codeIR/parser.tab.c"
    break;

  case 163: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 1415 "compiler/parser.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
    }
#line 3672 "objects/codeIR/parser.tab.c"
    break;

  case 164: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1420 "compiler/parser.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3682 "objects/codeIR/parser.tab.c"
    break;

  case 165: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 1425 "compiler/parser.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
    }
#line 3692 "objects/codeIR/parser.tab.c"
    break;

  case 166: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1430 "compiler/parser.y"
                                                        {
        (yyval.number).value = ((yyvsp[-1].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[-1].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
    }
#line 3704 "objects/codeIR/parser.tab.c"
    break;

  case 167: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 1437 "compiler/parser.y"
                                 {
        (yyval.number).value = ((yyvsp[0].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        // Compara com zero para gerar i1
        LLVMValueRef zero = LLVMConstInt(LLVMTypeOf((yyvsp[0].number).llvm_value), 0, 0);
        (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
    }
#line 3716 "objects/codeIR/parser.tab.c"
    break;

  case 168: /* call_function: ID LEFTPAR call_parameters RIGHTPAR  */
#line 1448 "compiler/parser.y"
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
#line 3763 "objects/codeIR/parser.tab.c"
    break;

  case 169: /* call_parameters: %empty  */
#line 1493 "compiler/parser.y"
                  {}
#line 3769 "objects/codeIR/parser.tab.c"
    break;

  case 170: /* call_parameters: term call_parameter_list  */
#line 1494 "compiler/parser.y"
                               {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3779 "objects/codeIR/parser.tab.c"
    break;

  case 171: /* call_parameter_list: %empty  */
#line 1502 "compiler/parser.y"
                  {}
#line 3785 "objects/codeIR/parser.tab.c"
    break;

  case 172: /* call_parameter_list: COMMA term call_parameter_list  */
#line 1503 "compiler/parser.y"
                                     {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 3795 "objects/codeIR/parser.tab.c"
    break;

  case 173: /* term: NUMBER  */
#line 1511 "compiler/parser.y"
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
#line 3810 "objects/codeIR/parser.tab.c"
    break;

  case 174: /* term: ID  */
#line 1521 "compiler/parser.y"
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
#line 3842 "objects/codeIR/parser.tab.c"
    break;

  case 175: /* term: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 1548 "compiler/parser.y"
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
#line 3879 "objects/codeIR/parser.tab.c"
    break;

  case 176: /* term: CARACTERE  */
#line 1580 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 3889 "objects/codeIR/parser.tab.c"
    break;


#line 3893 "objects/codeIR/parser.tab.c"

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

#line 1587 "compiler/parser.y"


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

    yyparse( );

    // Imprime IR
    char *irstr = LLVMPrintModuleToString(module);
    printf("%s", irstr);
    LLVMDisposeMessage(irstr);

    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(module);
    LLVMContextDispose(context);
    
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}
