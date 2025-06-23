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

int haveRet = 0;
int haveRetAll = 1;


#line 107 "objects/codeIR/parser.tab.c"

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
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_NUMBER = 18,                    /* NUMBER  */
  YYSYMBOL_ID = 19,                        /* ID  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_CARACTERE = 21,                 /* CARACTERE  */
  YYSYMBOL_RECEIVE = 22,                   /* RECEIVE  */
  YYSYMBOL_EQUAL = 23,                     /* EQUAL  */
  YYSYMBOL_NEQUAL = 24,                    /* NEQUAL  */
  YYSYMBOL_LESS = 25,                      /* LESS  */
  YYSYMBOL_GREAT = 26,                     /* GREAT  */
  YYSYMBOL_LEQUAL = 27,                    /* LEQUAL  */
  YYSYMBOL_GEQUAL = 28,                    /* GEQUAL  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_OR = 30,                        /* OR  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MIN = 33,                       /* MIN  */
  YYSYMBOL_MULT = 34,                      /* MULT  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_LEFTPAR = 36,                   /* LEFTPAR  */
  YYSYMBOL_RIGHTPAR = 37,                  /* RIGHTPAR  */
  YYSYMBOL_LEFTKEYS = 38,                  /* LEFTKEYS  */
  YYSYMBOL_RIGHTKEYS = 39,                 /* RIGHTKEYS  */
  YYSYMBOL_LEFTBRACKET = 40,               /* LEFTBRACKET  */
  YYSYMBOL_RIGHTBRACKET = 41,              /* RIGHTBRACKET  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_DONE = 43,                      /* DONE  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program_globals = 45,           /* program_globals  */
  YYSYMBOL_program_global_list = 46,       /* program_global_list  */
  YYSYMBOL_program_global = 47,            /* program_global  */
  YYSYMBOL_program_locals = 48,            /* program_locals  */
  YYSYMBOL_program_local_list = 49,        /* program_local_list  */
  YYSYMBOL_program_local = 50,             /* program_local  */
  YYSYMBOL_function = 51,                  /* function  */
  YYSYMBOL_int_function = 52,              /* int_function  */
  YYSYMBOL_53_1 = 53,                      /* $@1  */
  YYSYMBOL_54_2 = 54,                      /* $@2  */
  YYSYMBOL_float_function = 55,            /* float_function  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_char_function = 58,             /* char_function  */
  YYSYMBOL_59_5 = 59,                      /* $@5  */
  YYSYMBOL_60_6 = 60,                      /* $@6  */
  YYSYMBOL_bool_function = 61,             /* bool_function  */
  YYSYMBOL_62_7 = 62,                      /* $@7  */
  YYSYMBOL_63_8 = 63,                      /* $@8  */
  YYSYMBOL_void_function = 64,             /* void_function  */
  YYSYMBOL_65_9 = 65,                      /* $@9  */
  YYSYMBOL_66_10 = 66,                     /* $@10  */
  YYSYMBOL_parameters = 67,                /* parameters  */
  YYSYMBOL_parameter_list = 68,            /* parameter_list  */
  YYSYMBOL_parameter = 69,                 /* parameter  */
  YYSYMBOL_declaration_global = 70,        /* declaration_global  */
  YYSYMBOL_int_declaration_globals = 71,   /* int_declaration_globals  */
  YYSYMBOL_int_declaration_global_list = 72, /* int_declaration_global_list  */
  YYSYMBOL_int_declaration_global = 73,    /* int_declaration_global  */
  YYSYMBOL_array_global = 74,              /* array_global  */
  YYSYMBOL_float_declaration_globals = 75, /* float_declaration_globals  */
  YYSYMBOL_float_declaration_global_list = 76, /* float_declaration_global_list  */
  YYSYMBOL_float_declaration_global = 77,  /* float_declaration_global  */
  YYSYMBOL_char_declaration_globals = 78,  /* char_declaration_globals  */
  YYSYMBOL_char_declaration_global_list = 79, /* char_declaration_global_list  */
  YYSYMBOL_char_declaration_global = 80,   /* char_declaration_global  */
  YYSYMBOL_bool_declaration_globals = 81,  /* bool_declaration_globals  */
  YYSYMBOL_bool_declaration_global_list = 82, /* bool_declaration_global_list  */
  YYSYMBOL_bool_declaration_global = 83,   /* bool_declaration_global  */
  YYSYMBOL_array_values_global = 84,       /* array_values_global  */
  YYSYMBOL_term_const = 85,                /* term_const  */
  YYSYMBOL_declaration_local = 86,         /* declaration_local  */
  YYSYMBOL_int_declaration_locals = 87,    /* int_declaration_locals  */
  YYSYMBOL_int_declaration_local_list = 88, /* int_declaration_local_list  */
  YYSYMBOL_int_declaration_local = 89,     /* int_declaration_local  */
  YYSYMBOL_array_local = 90,               /* array_local  */
  YYSYMBOL_float_declaration_locals = 91,  /* float_declaration_locals  */
  YYSYMBOL_float_declaration_local_list = 92, /* float_declaration_local_list  */
  YYSYMBOL_float_declaration_local = 93,   /* float_declaration_local  */
  YYSYMBOL_char_declaration_locals = 94,   /* char_declaration_locals  */
  YYSYMBOL_char_declaration_local_list = 95, /* char_declaration_local_list  */
  YYSYMBOL_char_declaration_local = 96,    /* char_declaration_local  */
  YYSYMBOL_bool_declaration_locals = 97,   /* bool_declaration_locals  */
  YYSYMBOL_bool_declaration_local_list = 98, /* bool_declaration_local_list  */
  YYSYMBOL_bool_declaration_local = 99,    /* bool_declaration_local  */
  YYSYMBOL_array_values_local = 100,       /* array_values_local  */
  YYSYMBOL_comand = 101,                   /* comand  */
  YYSYMBOL_assignment = 102,               /* assignment  */
  YYSYMBOL_assignment_notfull = 103,       /* assignment_notfull  */
  YYSYMBOL_increment = 104,                /* increment  */
  YYSYMBOL_if_statement = 105,             /* if_statement  */
  YYSYMBOL_106_11 = 106,                   /* $@11  */
  YYSYMBOL_107_12 = 107,                   /* $@12  */
  YYSYMBOL_else_if_chain = 108,            /* else_if_chain  */
  YYSYMBOL_109_13 = 109,                   /* $@13  */
  YYSYMBOL_110_14 = 110,                   /* $@14  */
  YYSYMBOL_111_15 = 111,                   /* $@15  */
  YYSYMBOL_while = 112,                    /* while  */
  YYSYMBOL_113_16 = 113,                   /* $@16  */
  YYSYMBOL_while_aux = 114,                /* while_aux  */
  YYSYMBOL_for = 115,                      /* for  */
  YYSYMBOL_116_17 = 116,                   /* $@17  */
  YYSYMBOL_117_18 = 117,                   /* $@18  */
  YYSYMBOL_118_19 = 118,                   /* $@19  */
  YYSYMBOL_for_aux = 119,                  /* for_aux  */
  YYSYMBOL_do_while = 120,                 /* do_while  */
  YYSYMBOL_121_20 = 121,                   /* $@20  */
  YYSYMBOL_122_21 = 122,                   /* $@21  */
  YYSYMBOL_do_while_aux = 123,             /* do_while_aux  */
  YYSYMBOL_printf = 124,                   /* printf  */
  YYSYMBOL_printf_args = 125,              /* printf_args  */
  YYSYMBOL_scanf = 126,                    /* scanf  */
  YYSYMBOL_scanf_args = 127,               /* scanf_args  */
  YYSYMBOL_return = 128,                   /* return  */
  YYSYMBOL_expression = 129,               /* expression  */
  YYSYMBOL_soma_sub = 130,                 /* soma_sub  */
  YYSYMBOL_mult_div = 131,                 /* mult_div  */
  YYSYMBOL_comparison = 132,               /* comparison  */
  YYSYMBOL_log_exp = 133,                  /* log_exp  */
  YYSYMBOL_cast = 134,                     /* cast  */
  YYSYMBOL_call_function = 135,            /* call_function  */
  YYSYMBOL_call_function_notfull = 136,    /* call_function_notfull  */
  YYSYMBOL_call_parameters = 137,          /* call_parameters  */
  YYSYMBOL_call_parameter_list = 138,      /* call_parameter_list  */
  YYSYMBOL_term = 139                      /* term  */
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
#define YYLAST   584

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  391

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   122,   126,   127,   131,   132,   133,   138,
     139,   143,   144,   148,   149,   154,   155,   156,   157,   158,
     164,   166,   164,   205,   207,   205,   246,   248,   246,   287,
     289,   287,   329,   331,   329,   363,   364,   367,   368,   372,
     382,   392,   402,   416,   417,   418,   419,   423,   426,   427,
     430,   437,   444,   447,   461,   495,   498,   499,   502,   509,
     519,   522,   523,   526,   533,   543,   546,   547,   550,   557,
     568,   576,   585,   595,   603,   604,   605,   606,   610,   613,
     614,   617,   621,   641,   645,   659,   691,   694,   695,   698,
     702,   724,   727,   728,   731,   735,   752,   755,   756,   759,
     763,   780,   788,   796,   797,   798,   799,   800,   801,   802,
     803,   804,   805,   810,   814,   851,   885,   890,   938,   984,
    1032,  1081,  1117,  1157,  1181,  1157,  1209,  1213,  1216,  1216,
    1236,  1259,  1236,  1278,  1278,  1301,  1317,  1323,  1334,  1317,
    1355,  1365,  1370,  1365,  1391,  1404,  1425,  1426,  1436,  1457,
    1458,  1473,  1485,  1497,  1498,  1499,  1500,  1501,  1502,  1503,
    1504,  1508,  1530,  1555,  1577,  1608,  1630,  1652,  1674,  1696,
    1722,  1750,  1761,  1772,  1786,  1810,  1834,  1857,  1880,  1903,
    1926,  1953,  1983,  1987,  2032,  2033,  2041,  2042,  2050,  2060,
    2095,  2139
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
  "FOR", "DO", "VOID", "RETURN", "NUMBER", "ID", "STRING", "CARACTERE",
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
  "assignment_notfull", "increment", "if_statement", "$@11", "$@12",
  "else_if_chain", "$@13", "$@14", "$@15", "while", "$@16", "while_aux",
  "for", "$@17", "$@18", "$@19", "for_aux", "do_while", "$@20", "$@21",
  "do_while_aux", "printf", "printf_args", "scanf", "scanf_args", "return",
  "expression", "soma_sub", "mult_div", "comparison", "log_exp", "cast",
  "call_function", "call_function_notfull", "call_parameters",
  "call_parameter_list", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-169)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-117)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     250,  -169,   -16,     5,    22,    32,    41,    70,   333,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
      63,    36,  -169,   -20,    59,   104,    64,   132,    77,    94,
    -169,  -169,   333,   106,  -169,   106,   136,   102,   106,  -169,
     143,   108,   106,  -169,   147,   128,   106,  -169,   156,   154,
    -169,  -169,  -169,  -169,  -169,   201,   149,    -9,    36,  -169,
    -169,   201,   157,    59,  -169,  -169,   201,   183,    64,  -169,
    -169,   201,   189,    77,  -169,   201,   193,   194,   197,   200,
    -169,   184,   206,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,   196,   201,  -169,   192,   198,
     208,   215,   217,   222,   184,   106,   223,   224,   225,   226,
     313,  -169,   131,  -169,   313,   313,   313,   313,   195,   234,
     249,   251,   253,   237,   238,  -169,  -169,  -169,    -1,    12,
     236,   313,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   235,
     246,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,   252,
    -169,   106,   240,   255,   257,   259,    38,    14,   266,  -169,
     212,   271,   275,   272,   293,   283,   297,   309,   241,   295,
    -169,  -169,   113,  -169,    38,    19,  -169,    88,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,    38,     7,    44,   314,   315,
      54,    38,  -169,  -169,   313,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,   327,    38,    38,   234,   292,    38,   249,   300,
      38,   251,   301,    38,   253,   302,   296,   304,    38,   216,
     310,    38,  -169,   321,   326,   336,   341,   342,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
    -169,   477,    38,  -169,    38,  -169,    38,    38,   307,   351,
     361,   214,  -169,  -169,   477,   258,   266,  -169,   477,   271,
    -169,   477,   272,  -169,   477,   283,  -169,    38,   356,   396,
     381,   357,  -169,   313,   277,    62,   129,   181,   185,  -169,
     503,   503,   503,   503,   503,   503,   516,   490,   126,   126,
    -169,  -169,   477,   477,   477,   477,  -169,    54,  -169,   401,
     395,   416,  -169,  -169,  -169,  -169,   159,   405,   434,   420,
    -169,    38,   429,  -169,    38,  -169,    38,  -169,    38,  -169,
      38,  -169,   361,    38,   313,   440,  -169,  -169,   304,  -169,
     445,   109,  -169,   372,   387,   402,   417,  -169,   477,   454,
      38,  -169,   313,  -169,   485,  -169,  -169,  -169,  -169,  -169,
     138,   477,   469,   501,   496,   191,  -169,    38,  -169,   124,
    -169,  -169,    38,   497,   498,  -169,   477,   484,   432,    38,
     507,    38,   508,   504,   447,   313,   462,   313,  -169,  -169,
     513,  -169,   514,  -169,   517,  -169,   313,   515,  -169,   191,
    -169
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
       0,     0,     0,     0,     0,   135,   140,   144,     0,     0,
       0,    11,    14,    74,    75,    76,    77,    13,   103,     0,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
      54,     0,     0,     0,     0,     0,     0,    81,    79,    83,
      94,    92,    89,    87,    99,    97,     0,     0,     0,     0,
     141,   188,   189,   191,     0,     0,   152,     0,   153,   154,
     156,   157,   158,   159,   160,     0,     0,     0,     0,     0,
     184,     0,    22,    10,    11,   113,   182,    71,    28,    25,
      31,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,   149,     0,     0,
       0,     0,   173,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,   114,     0,   121,     0,   122,     0,     0,   189,     0,
     186,     0,    12,   123,    82,     0,    79,    78,    95,    92,
      91,    90,    87,    86,   100,    97,    96,     0,     0,     0,
       0,     0,   136,     9,     0,     0,     0,     0,     0,   155,
     169,   170,   165,   166,   167,   168,   171,   172,   161,   162,
     163,   164,   117,   118,   119,   120,   183,     0,   185,     0,
       0,    84,    80,    93,    88,    98,   146,     0,     0,     0,
     133,     0,     0,   190,     0,   175,     0,   179,     0,   177,
       0,   181,   186,     0,     9,     0,   147,   145,   149,   148,
       0,     0,   142,     0,     0,     0,     0,   187,   115,     0,
       0,   150,     9,   137,     0,   174,   178,   176,   180,   124,
       0,   101,     0,     0,     0,   126,    85,     0,   134,     0,
     138,   116,     0,   128,     0,   125,   102,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,     9,   143,   127,
       0,   130,     0,   129,     0,   139,     9,     0,   131,   126,
     132
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -169,  -169,   524,   557,  -106,   364,  -130,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,    -8,   455,   464,  -169,  -169,   505,   525,
    -169,  -169,   494,   520,  -169,   502,   526,  -169,   495,   519,
    -169,   -23,   350,  -169,   316,   365,  -169,  -169,   311,   360,
    -169,   317,   366,  -169,   312,   367,  -169,  -169,  -169,   227,
     229,  -169,  -169,  -169,   186,  -169,  -169,  -169,  -169,  -169,
    -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,  -169,
    -169,   273,  -169,   256,  -169,  -142,  -169,  -169,  -169,  -169,
    -169,  -169,  -110,  -169,   261,  -168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     7,    31,    32,   130,   193,   131,     9,    10,    55,
      95,    11,    66,   100,    12,    61,    99,    13,    71,   101,
      14,    75,   102,    80,    97,    81,    15,    16,    37,    21,
      22,    17,    45,    26,    18,    41,    24,    19,    49,    28,
     112,    54,   132,   133,   206,   158,   159,   134,   212,   163,
     135,   209,   161,   136,   215,   165,   350,   137,   138,   139,
     140,   141,   300,   355,   365,   370,   384,   389,   142,   330,
     168,   143,   311,   353,   367,   169,   144,   220,   344,   170,
     145,   268,   146,   270,   147,   177,   178,   179,   180,   181,
     182,   148,   183,   249,   298,   184
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     149,   194,    38,    20,   149,   149,   149,   149,   152,   153,
     154,   155,    56,    33,   202,    60,    39,   171,   172,    65,
     173,   149,   250,    70,    23,   223,   224,   225,   226,   242,
     174,    35,   222,   227,   185,   175,   203,   171,   172,   243,
     173,    25,   176,   241,   186,   187,   188,   189,   190,   251,
     174,    27,   191,    84,   204,   175,   171,   172,    86,   173,
      29,   254,   255,    88,   194,   258,   244,    90,   261,   174,
      30,   264,   171,   248,   175,   173,   271,   245,    36,   274,
     171,   248,   113,   173,   149,    33,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   314,    34,
     292,    40,   293,    35,   294,   295,    44,   315,   317,   319,
     321,   228,   229,   230,   231,   232,   233,   234,   235,    48,
     236,   237,   238,   239,    52,   306,    42,    53,   197,   322,
      50,   240,   228,   229,   230,   231,   232,   233,   234,   235,
      43,   236,   237,   238,   239,    59,   185,   171,   248,   190,
     173,    64,   343,   221,    46,    57,   186,   187,   188,   189,
     238,   239,    62,   149,   191,   316,    67,   312,    47,   331,
     150,    69,   333,   151,   334,    72,   335,   356,   336,    38,
     357,   338,   228,   229,   230,   231,   232,   233,   234,   235,
      82,   236,   237,   238,   239,   363,   364,    74,   351,   171,
     248,   267,   173,   171,   248,    42,   173,    76,    77,    78,
      79,    46,    91,    92,   149,   366,    93,   318,   339,    94,
     368,   320,   119,   120,   121,   122,    96,   374,    98,   376,
     105,   156,   149,   103,   207,   106,   352,   228,   229,   230,
     231,   232,   233,   234,   235,   107,   236,   237,   238,   239,
      -2,     1,   108,   157,   109,   299,     2,     3,     4,     5,
     110,   114,   115,   116,   117,   149,     6,   149,   160,   380,
     162,   382,   164,   166,   167,   192,   149,   218,   195,   198,
     387,   228,   229,   230,   231,   232,   233,   234,   235,  -116,
     236,   237,   238,   239,   199,   196,   200,   210,   201,   301,
     228,   229,   230,   231,   232,   233,   234,   235,   205,   236,
     237,   238,   239,   208,   211,   213,   118,   216,   313,   119,
     120,   121,   122,   123,   124,   214,   125,   126,   127,   217,
     128,   219,   129,    -4,     1,   257,   246,   247,   267,     2,
       3,     4,     5,   260,   263,   266,   269,   221,   273,     6,
     228,   229,   230,   231,   232,   233,   234,   235,   275,   236,
     237,   238,   239,   276,   253,   228,   229,   230,   231,   232,
     233,   234,   235,   277,   236,   237,   238,   239,   278,   279,
     228,   229,   230,   231,   232,   233,   234,   235,   296,   236,
     237,   238,   239,   307,   310,   228,   229,   230,   231,   232,
     233,   234,   235,   297,   236,   237,   238,   239,   308,   345,
     228,   229,   230,   231,   232,   233,   234,   235,   309,   236,
     237,   238,   239,   323,   346,   228,   229,   230,   231,   232,
     233,   234,   235,   324,   236,   237,   238,   239,   325,   347,
     228,   229,   230,   231,   232,   233,   234,   235,   327,   236,
     237,   238,   239,   328,   348,   228,   229,   230,   231,   232,
     233,   234,   235,   329,   236,   237,   238,   239,   332,   373,
     228,   229,   230,   231,   232,   233,   234,   235,   340,   236,
     237,   238,   239,   342,   379,   228,   229,   230,   231,   232,
     233,   234,   235,   349,   236,   237,   238,   239,   354,   381,
     228,   229,   230,   231,   232,   233,   234,   235,   358,   236,
     237,   238,   239,   228,   229,   230,   231,   232,   233,   234,
     359,   372,   236,   237,   238,   239,  -117,  -117,  -117,  -117,
    -117,  -117,   362,   369,   371,   236,   237,   238,   239,   228,
     229,   230,   231,   232,   233,   375,   377,   378,   236,   237,
     238,   239,   383,   385,   388,   386,    51,     8,   252,   111,
     104,    58,    87,    83,    68,    85,    63,    73,    89,   272,
     256,   262,   302,   304,   259,   390,   303,   305,     0,   326,
     360,   265,   361,   337,   341
};

static const yytype_int16 yycheck[] =
{
     110,   131,    22,    19,   114,   115,   116,   117,   114,   115,
     116,   117,    35,    22,   156,    38,    36,    18,    19,    42,
      21,   131,   190,    46,    19,     6,     7,     8,     9,    22,
      31,    40,   174,   175,    22,    36,    22,    18,    19,    32,
      21,    19,    43,   185,    32,    33,    34,    35,    36,   191,
      31,    19,    40,    61,    40,    36,    18,    19,    66,    21,
      19,   203,   204,    71,   194,   207,    22,    75,   210,    31,
       0,   213,    18,    19,    36,    21,   218,    33,    42,   221,
      18,    19,   105,    21,   194,    22,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,    36,    36,
     242,    42,   244,    40,   246,   247,    42,   275,   276,   277,
     278,    23,    24,    25,    26,    27,    28,    29,    30,    42,
      32,    33,    34,    35,    18,   267,    22,    21,   151,   297,
      36,    43,    23,    24,    25,    26,    27,    28,    29,    30,
      36,    32,    33,    34,    35,    43,    22,    18,    19,    36,
      21,    43,    43,    40,    22,    19,    32,    33,    34,    35,
      34,    35,    19,   273,    40,    36,    19,   273,    36,   311,
      39,    43,   314,    42,   316,    19,   318,    39,   320,    22,
      42,   323,    23,    24,    25,    26,    27,    28,    29,    30,
      41,    32,    33,    34,    35,     4,     5,    43,   340,    18,
      19,    42,    21,    18,    19,    22,    21,     6,     7,     8,
       9,    22,    19,    19,   324,   357,    19,    36,   324,    19,
     362,    36,     6,     7,     8,     9,    42,   369,    22,   371,
      38,    36,   342,    37,    22,    37,   342,    23,    24,    25,
      26,    27,    28,    29,    30,    37,    32,    33,    34,    35,
       0,     1,    37,    19,    37,    41,     6,     7,     8,     9,
      38,    38,    38,    38,    38,   375,    16,   377,    19,   375,
      19,   377,    19,    36,    36,    39,   386,    36,    43,    39,
     386,    23,    24,    25,    26,    27,    28,    29,    30,    43,
      32,    33,    34,    35,    39,    43,    39,    22,    39,    41,
      23,    24,    25,    26,    27,    28,    29,    30,    42,    32,
      33,    34,    35,    42,    42,    22,     3,    20,    41,     6,
       7,     8,     9,    10,    11,    42,    13,    14,    15,    20,
      17,    36,    19,     0,     1,    43,    22,    22,    42,     6,
       7,     8,     9,    43,    43,    43,    42,    40,    38,    16,
      23,    24,    25,    26,    27,    28,    29,    30,    37,    32,
      33,    34,    35,    37,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    37,    32,    33,    34,    35,    37,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    37,    32,
      33,    34,    35,    37,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    42,    32,    33,    34,    35,    12,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    37,    32,
      33,    34,    35,    22,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    38,    32,    33,    34,    35,    22,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    43,    32,
      33,    34,    35,    19,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    43,    32,    33,    34,    35,    39,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    38,    32,
      33,    34,    35,    38,    37,    23,    24,    25,    26,    27,
      28,    29,    30,    39,    32,    33,    34,    35,    13,    37,
      23,    24,    25,    26,    27,    28,    29,    30,    39,    32,
      33,    34,    35,    23,    24,    25,    26,    27,    28,    29,
      19,    37,    32,    33,    34,    35,    23,    24,    25,    26,
      27,    28,    36,    36,    36,    32,    33,    34,    35,    23,
      24,    25,    26,    27,    28,    38,    38,    43,    32,    33,
      34,    35,    39,    39,    39,    38,    32,     0,   194,   104,
      96,    36,    68,    58,    44,    63,    40,    48,    73,   219,
     205,   211,   256,   262,   208,   389,   259,   265,    -1,   306,
     353,   214,   353,   322,   328
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     6,     7,     8,     9,    16,    45,    47,    51,
      52,    55,    58,    61,    64,    70,    71,    75,    78,    81,
      19,    73,    74,    19,    80,    19,    77,    19,    83,    19,
       0,    46,    47,    22,    36,    40,    42,    72,    22,    36,
      42,    79,    22,    36,    42,    76,    22,    36,    42,    82,
      36,    46,    18,    21,    85,    53,    85,    19,    73,    43,
      85,    59,    19,    80,    43,    85,    56,    19,    77,    43,
      85,    62,    19,    83,    43,    65,     6,     7,     8,     9,
      67,    69,    41,    72,    67,    79,    67,    76,    67,    82,
      67,    19,    19,    19,    19,    54,    42,    68,    22,    60,
      57,    63,    66,    37,    69,    38,    37,    37,    37,    37,
      38,    68,    84,    85,    38,    38,    38,    38,     3,     6,
       7,     8,     9,    10,    11,    13,    14,    15,    17,    19,
      48,    50,    86,    87,    91,    94,    97,   101,   102,   103,
     104,   105,   112,   115,   120,   124,   126,   128,   135,   136,
      39,    42,    48,    48,    48,    48,    36,    19,    89,    90,
      19,    96,    19,    93,    19,    99,    36,    36,   114,   119,
     123,    18,    19,    21,    31,    36,    43,   129,   130,   131,
     132,   133,   134,   136,   139,    22,    32,    33,    34,    35,
      36,    40,    39,    49,    50,    43,    43,    85,    39,    39,
      39,    39,   129,    22,    40,    42,    88,    22,    42,    95,
      22,    42,    92,    22,    42,    98,    20,    20,    36,    36,
     121,    40,   129,     6,     7,     8,     9,   129,    23,    24,
      25,    26,    27,    28,    29,    30,    32,    33,    34,    35,
      43,   129,    22,    32,    22,    33,    22,    22,    19,   137,
     139,   129,    49,    37,   129,   129,    89,    43,   129,    96,
      43,   129,    93,    43,   129,    99,    43,    42,   125,    42,
     127,   129,    86,    38,   129,    37,    37,    37,    37,    37,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,    37,    42,   138,    41,
     106,    41,    88,    95,    92,    98,   129,    37,    12,    37,
      37,   116,    48,    41,    36,   139,    36,   139,    36,   139,
      36,   139,   139,    22,    38,    22,   125,    43,    19,    43,
     113,   129,    39,   129,   129,   129,   129,   138,   129,    48,
      38,   127,    38,    43,   122,    37,    37,    37,    37,    39,
     100,   129,    48,   117,    13,   107,    39,    42,    39,    19,
     103,   104,    36,     4,     5,   108,   129,   118,   129,    36,
     109,    36,    37,    37,   129,    38,   129,    38,    43,    37,
      48,    37,    48,    39,   110,    39,    38,    48,    39,   111,
     108
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    45,    46,    46,    47,    47,    47,    48,
      48,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      53,    54,    52,    56,    57,    55,    59,    60,    58,    62,
      63,    61,    65,    66,    64,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    70,    71,    72,    72,
      73,    73,    73,    74,    74,    75,    76,    76,    77,    77,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    86,    86,    87,    88,
      88,    89,    89,    89,    90,    90,    91,    92,    92,    93,
      93,    94,    95,    95,    96,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   102,   103,   103,   103,   104,   104,   104,
     104,   104,   104,   106,   107,   105,   108,   108,   109,   108,
     110,   111,   108,   113,   112,   114,   116,   117,   118,   115,
     119,   121,   122,   120,   123,   124,   125,   125,   126,   127,
     127,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   132,   132,   132,
     132,   133,   133,   133,   134,   134,   134,   134,   134,   134,
     134,   134,   135,   136,   137,   137,   138,   138,   139,   139,
     139,   139
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
       1,     1,     1,     2,     3,     6,     1,     4,     4,     4,
       4,     3,     3,     0,     0,    10,     0,     4,     0,     5,
       0,     0,    10,     0,     9,     0,     0,     0,     0,    14,
       0,     0,     0,    12,     0,     6,     0,     3,     6,     0,
       4,     3,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     6,     4,     6,     4,     6,     4,
       6,     4,     2,     4,     0,     2,     0,     3,     1,     1,
       4,     1
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
#line 121 "compiler/parser.y"
                  {}
#line 1831 "objects/codeIR/parser.tab.c"
    break;

  case 3: /* program_globals: program_global program_global_list  */
#line 122 "compiler/parser.y"
                                         {}
#line 1837 "objects/codeIR/parser.tab.c"
    break;

  case 4: /* program_global_list: %empty  */
#line 126 "compiler/parser.y"
                  {}
#line 1843 "objects/codeIR/parser.tab.c"
    break;

  case 5: /* program_global_list: program_global program_global_list  */
#line 127 "compiler/parser.y"
                                         {}
#line 1849 "objects/codeIR/parser.tab.c"
    break;

  case 6: /* program_global: function  */
#line 131 "compiler/parser.y"
               {}
#line 1855 "objects/codeIR/parser.tab.c"
    break;

  case 7: /* program_global: declaration_global  */
#line 132 "compiler/parser.y"
                         {}
#line 1861 "objects/codeIR/parser.tab.c"
    break;

  case 8: /* program_global: error  */
#line 133 "compiler/parser.y"
            { yyerrok; yyclearin; }
#line 1867 "objects/codeIR/parser.tab.c"
    break;

  case 9: /* program_locals: %empty  */
#line 138 "compiler/parser.y"
                  {}
#line 1873 "objects/codeIR/parser.tab.c"
    break;

  case 10: /* program_locals: program_local program_local_list  */
#line 139 "compiler/parser.y"
                                       {}
#line 1879 "objects/codeIR/parser.tab.c"
    break;

  case 11: /* program_local_list: %empty  */
#line 143 "compiler/parser.y"
                  {}
#line 1885 "objects/codeIR/parser.tab.c"
    break;

  case 12: /* program_local_list: program_local program_local_list  */
#line 144 "compiler/parser.y"
                                       {}
#line 1891 "objects/codeIR/parser.tab.c"
    break;

  case 13: /* program_local: comand  */
#line 148 "compiler/parser.y"
             {}
#line 1897 "objects/codeIR/parser.tab.c"
    break;

  case 14: /* program_local: declaration_local  */
#line 149 "compiler/parser.y"
                        {}
#line 1903 "objects/codeIR/parser.tab.c"
    break;

  case 15: /* function: int_function  */
#line 154 "compiler/parser.y"
                   {}
#line 1909 "objects/codeIR/parser.tab.c"
    break;

  case 16: /* function: float_function  */
#line 155 "compiler/parser.y"
                     {}
#line 1915 "objects/codeIR/parser.tab.c"
    break;

  case 17: /* function: char_function  */
#line 156 "compiler/parser.y"
                    {}
#line 1921 "objects/codeIR/parser.tab.c"
    break;

  case 18: /* function: bool_function  */
#line 157 "compiler/parser.y"
                    {}
#line 1927 "objects/codeIR/parser.tab.c"
    break;

  case 19: /* function: void_function  */
#line 158 "compiler/parser.y"
                    {}
#line 1933 "objects/codeIR/parser.tab.c"
    break;

  case 20: /* $@1: %empty  */
#line 164 "compiler/parser.y"
                     {
        pushScope();
    }
#line 1941 "objects/codeIR/parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 166 "compiler/parser.y"
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

        haveRet = 0;
    }
#line 1975 "objects/codeIR/parser.tab.c"
    break;

  case 22: /* int_function: INT ID LEFTPAR $@1 parameters $@2 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 194 "compiler/parser.y"
                                                 {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", (yyvsp[-8].id), yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
#line 1988 "objects/codeIR/parser.tab.c"
    break;

  case 23: /* $@3: %empty  */
#line 205 "compiler/parser.y"
                       {
            pushScope();
        }
#line 1996 "objects/codeIR/parser.tab.c"
    break;

  case 24: /* $@4: %empty  */
#line 207 "compiler/parser.y"
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
        
        haveRet = 0;
    }
#line 2030 "objects/codeIR/parser.tab.c"
    break;

  case 25: /* float_function: FLOAT ID LEFTPAR $@3 parameters $@4 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 235 "compiler/parser.y"
                                                 {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", (yyvsp[-8].id), yylineno);
            LLVMValueRef ret_value = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
            LLVMBuildRet(builder, ret_value); // Retorna 0.0 por padrão
        }
        popScope();
    }
#line 2043 "objects/codeIR/parser.tab.c"
    break;

  case 26: /* $@5: %empty  */
#line 246 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2051 "objects/codeIR/parser.tab.c"
    break;

  case 27: /* $@6: %empty  */
#line 248 "compiler/parser.y"
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
        
        haveRet = 0;
    }
#line 2085 "objects/codeIR/parser.tab.c"
    break;

  case 28: /* char_function: CHAR ID LEFTPAR $@5 parameters $@6 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 276 "compiler/parser.y"
                                                 {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", (yyvsp[-8].id), yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
#line 2098 "objects/codeIR/parser.tab.c"
    break;

  case 29: /* $@7: %empty  */
#line 287 "compiler/parser.y"
                      {
        pushScope();
    }
#line 2106 "objects/codeIR/parser.tab.c"
    break;

  case 30: /* $@8: %empty  */
#line 289 "compiler/parser.y"
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
        
        haveRet = 0;
    }
#line 2140 "objects/codeIR/parser.tab.c"
    break;

  case 31: /* bool_function: BOOL ID LEFTPAR $@7 parameters $@8 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 317 "compiler/parser.y"
                                                 {
        if(haveRet == 0) {
            fprintf(stderr, "Warning: function '%s' does not have a return statement at line %d.\n", (yyvsp[-8].id), yylineno);
            LLVMValueRef ret_value = LLVMConstInt(LLVMInt1TypeInContext(context), 0, 0);
            LLVMBuildRet(builder, ret_value); // Retorna 0 por padrão
        }
        popScope();
    }
#line 2153 "objects/codeIR/parser.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 329 "compiler/parser.y"
                      {
            pushScope();
    }
#line 2161 "objects/codeIR/parser.tab.c"
    break;

  case 33: /* $@10: %empty  */
#line 331 "compiler/parser.y"
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
#line 2191 "objects/codeIR/parser.tab.c"
    break;

  case 34: /* void_function: VOID ID LEFTPAR $@9 parameters $@10 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 355 "compiler/parser.y"
                                                 {
        LLVMBuildRetVoid(builder);
        popScope();
    }
#line 2200 "objects/codeIR/parser.tab.c"
    break;

  case 36: /* parameters: parameter parameter_list  */
#line 364 "compiler/parser.y"
                               {}
#line 2206 "objects/codeIR/parser.tab.c"
    break;

  case 38: /* parameter_list: COMMA parameter parameter_list  */
#line 368 "compiler/parser.y"
                                     {}
#line 2212 "objects/codeIR/parser.tab.c"
    break;

  case 39: /* parameter: INT ID  */
#line 372 "compiler/parser.y"
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
#line 2227 "objects/codeIR/parser.tab.c"
    break;

  case 40: /* parameter: FLOAT ID  */
#line 382 "compiler/parser.y"
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
#line 2242 "objects/codeIR/parser.tab.c"
    break;

  case 41: /* parameter: CHAR ID  */
#line 392 "compiler/parser.y"
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
#line 2257 "objects/codeIR/parser.tab.c"
    break;

  case 42: /* parameter: BOOL ID  */
#line 402 "compiler/parser.y"
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
#line 2272 "objects/codeIR/parser.tab.c"
    break;

  case 43: /* declaration_global: int_declaration_globals  */
#line 416 "compiler/parser.y"
                              {}
#line 2278 "objects/codeIR/parser.tab.c"
    break;

  case 44: /* declaration_global: float_declaration_globals  */
#line 417 "compiler/parser.y"
                                {}
#line 2284 "objects/codeIR/parser.tab.c"
    break;

  case 45: /* declaration_global: char_declaration_globals  */
#line 418 "compiler/parser.y"
                               {}
#line 2290 "objects/codeIR/parser.tab.c"
    break;

  case 46: /* declaration_global: bool_declaration_globals  */
#line 419 "compiler/parser.y"
                               {}
#line 2296 "objects/codeIR/parser.tab.c"
    break;

  case 47: /* int_declaration_globals: INT int_declaration_global int_declaration_global_list DONE  */
#line 423 "compiler/parser.y"
                                                                  {}
#line 2302 "objects/codeIR/parser.tab.c"
    break;

  case 50: /* int_declaration_global: ID  */
#line 430 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2314 "objects/codeIR/parser.tab.c"
    break;

  case 51: /* int_declaration_global: ID RECEIVE term_const  */
#line 437 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_INT);
        LLVMTypeRef type = LLVMInt32TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2326 "objects/codeIR/parser.tab.c"
    break;

  case 52: /* int_declaration_global: array_global  */
#line 444 "compiler/parser.y"
                   {}
#line 2332 "objects/codeIR/parser.tab.c"
    break;

  case 53: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET  */
#line 447 "compiler/parser.y"
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
#line 2351 "objects/codeIR/parser.tab.c"
    break;

  case 54: /* array_global: ID LEFTBRACKET term_const RIGHTBRACKET RECEIVE LEFTKEYS array_values_global RIGHTKEYS  */
#line 461 "compiler/parser.y"
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
                LLVMValueRef array_ptr = LLVMBuildGEP2(
                    builder,
                    LLVMArrayType(LLVMInt32TypeInContext(context), size),
                    var,
                    indices,
                    2,
                    ""
                );
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
#line 2385 "objects/codeIR/parser.tab.c"
    break;

  case 55: /* float_declaration_globals: FLOAT float_declaration_global float_declaration_global_list DONE  */
#line 495 "compiler/parser.y"
                                                                        {}
#line 2391 "objects/codeIR/parser.tab.c"
    break;

  case 58: /* float_declaration_global: ID  */
#line 502 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstReal(type, 0.0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2403 "objects/codeIR/parser.tab.c"
    break;

  case 59: /* float_declaration_global: ID RECEIVE term_const  */
#line 509 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_FLOAT);
        LLVMTypeRef type = LLVMDoubleTypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2415 "objects/codeIR/parser.tab.c"
    break;

  case 60: /* char_declaration_globals: CHAR char_declaration_global char_declaration_global_list DONE  */
#line 519 "compiler/parser.y"
                                                                     {}
#line 2421 "objects/codeIR/parser.tab.c"
    break;

  case 61: /* char_declaration_global_list: %empty  */
#line 522 "compiler/parser.y"
                  {}
#line 2427 "objects/codeIR/parser.tab.c"
    break;

  case 62: /* char_declaration_global_list: COMMA char_declaration_global char_declaration_global_list  */
#line 523 "compiler/parser.y"
                                                                 {}
#line 2433 "objects/codeIR/parser.tab.c"
    break;

  case 63: /* char_declaration_global: ID  */
#line 526 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2445 "objects/codeIR/parser.tab.c"
    break;

  case 64: /* char_declaration_global: ID RECEIVE term_const  */
#line 533 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_CHAR);
        LLVMTypeRef type = LLVMInt8TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2457 "objects/codeIR/parser.tab.c"
    break;

  case 65: /* bool_declaration_globals: BOOL bool_declaration_global bool_declaration_global_list DONE  */
#line 543 "compiler/parser.y"
                                                                     {}
#line 2463 "objects/codeIR/parser.tab.c"
    break;

  case 66: /* bool_declaration_global_list: %empty  */
#line 546 "compiler/parser.y"
                  {}
#line 2469 "objects/codeIR/parser.tab.c"
    break;

  case 67: /* bool_declaration_global_list: COMMA bool_declaration_global bool_declaration_global_list  */
#line 547 "compiler/parser.y"
                                                                 {}
#line 2475 "objects/codeIR/parser.tab.c"
    break;

  case 68: /* bool_declaration_global: ID  */
#line 550 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[0].id));
        LLVMSetInitializer(global, LLVMConstInt(type, 0, 0)); // valor padrão
        setVarLLVM((yyvsp[0].id), global); // Função que associa o nome ao LLVMValueRef global
    }
#line 2487 "objects/codeIR/parser.tab.c"
    break;

  case 69: /* bool_declaration_global: ID RECEIVE term_const  */
#line 557 "compiler/parser.y"
                            {
        insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, TYPE_BOOL);
        LLVMTypeRef type = LLVMInt1TypeInContext(context);
        LLVMValueRef global = LLVMAddGlobal(module, type, (yyvsp[-2].id));
        LLVMSetInitializer(global, (yyvsp[0].number).llvm_value);
        setVarLLVM((yyvsp[-2].id), global);
    }
#line 2499 "objects/codeIR/parser.tab.c"
    break;

  case 70: /* array_values_global: term_const  */
#line 568 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2512 "objects/codeIR/parser.tab.c"
    break;

  case 71: /* array_values_global: array_values_global COMMA term_const  */
#line 576 "compiler/parser.y"
                                           {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
    }
#line 2522 "objects/codeIR/parser.tab.c"
    break;

  case 72: /* term_const: NUMBER  */
#line 585 "compiler/parser.y"
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
#line 2537 "objects/codeIR/parser.tab.c"
    break;

  case 73: /* term_const: CARACTERE  */
#line 595 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 2547 "objects/codeIR/parser.tab.c"
    break;

  case 74: /* declaration_local: int_declaration_locals  */
#line 603 "compiler/parser.y"
                             {}
#line 2553 "objects/codeIR/parser.tab.c"
    break;

  case 75: /* declaration_local: float_declaration_locals  */
#line 604 "compiler/parser.y"
                               {}
#line 2559 "objects/codeIR/parser.tab.c"
    break;

  case 76: /* declaration_local: char_declaration_locals  */
#line 605 "compiler/parser.y"
                              {}
#line 2565 "objects/codeIR/parser.tab.c"
    break;

  case 77: /* declaration_local: bool_declaration_locals  */
#line 606 "compiler/parser.y"
                              {}
#line 2571 "objects/codeIR/parser.tab.c"
    break;

  case 78: /* int_declaration_locals: INT int_declaration_local int_declaration_local_list DONE  */
#line 610 "compiler/parser.y"
                                                                {}
#line 2577 "objects/codeIR/parser.tab.c"
    break;

  case 79: /* int_declaration_local_list: %empty  */
#line 613 "compiler/parser.y"
                  {}
#line 2583 "objects/codeIR/parser.tab.c"
    break;

  case 80: /* int_declaration_local_list: COMMA int_declaration_local int_declaration_local_list  */
#line 614 "compiler/parser.y"
                                                             {}
#line 2589 "objects/codeIR/parser.tab.c"
    break;

  case 81: /* int_declaration_local: ID  */
#line 617 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_INT);
        allocaVars((yyvsp[0].id), TYPE_INT);
    }
#line 2598 "objects/codeIR/parser.tab.c"
    break;

  case 82: /* int_declaration_local: ID RECEIVE expression  */
#line 621 "compiler/parser.y"
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
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        }
    }
#line 2623 "objects/codeIR/parser.tab.c"
    break;

  case 84: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 645 "compiler/parser.y"
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
#line 2642 "objects/codeIR/parser.tab.c"
    break;

  case 85: /* array_local: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE LEFTKEYS array_values_local RIGHTKEYS  */
#line 659 "compiler/parser.y"
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
                LLVMValueRef array_ptr = LLVMBuildGEP2(
                    builder,
                    LLVMArrayType(LLVMInt32TypeInContext(context), size),
                    var,
                    indices,
                    2,
                    ""
                );
                LLVMValueRef val = LLVMConstInt(LLVMInt32TypeInContext(context), (int)vals[i], 0);
                LLVMBuildStore(builder, val, array_ptr);
            }
        }
        free(vals);
        vals = NULL; // Libera o array de valores
        array_value_count = 0;
    }
#line 2676 "objects/codeIR/parser.tab.c"
    break;

  case 86: /* float_declaration_locals: FLOAT float_declaration_local float_declaration_local_list DONE  */
#line 691 "compiler/parser.y"
                                                                      {}
#line 2682 "objects/codeIR/parser.tab.c"
    break;

  case 87: /* float_declaration_local_list: %empty  */
#line 694 "compiler/parser.y"
                  {}
#line 2688 "objects/codeIR/parser.tab.c"
    break;

  case 88: /* float_declaration_local_list: COMMA float_declaration_local float_declaration_local_list  */
#line 695 "compiler/parser.y"
                                                                 {}
#line 2694 "objects/codeIR/parser.tab.c"
    break;

  case 89: /* float_declaration_local: ID  */
#line 698 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_FLOAT);
        allocaVars((yyvsp[0].id), TYPE_FLOAT);
    }
#line 2703 "objects/codeIR/parser.tab.c"
    break;

  case 90: /* float_declaration_local: ID RECEIVE expression  */
#line 702 "compiler/parser.y"
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
#line 2727 "objects/codeIR/parser.tab.c"
    break;

  case 91: /* char_declaration_locals: CHAR char_declaration_local char_declaration_local_list DONE  */
#line 724 "compiler/parser.y"
                                                                   {}
#line 2733 "objects/codeIR/parser.tab.c"
    break;

  case 92: /* char_declaration_local_list: %empty  */
#line 727 "compiler/parser.y"
                  {}
#line 2739 "objects/codeIR/parser.tab.c"
    break;

  case 93: /* char_declaration_local_list: COMMA char_declaration_local char_declaration_local_list  */
#line 728 "compiler/parser.y"
                                                               {}
#line 2745 "objects/codeIR/parser.tab.c"
    break;

  case 94: /* char_declaration_local: ID  */
#line 731 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_CHAR);
        allocaVars((yyvsp[0].id), TYPE_CHAR);
    }
#line 2754 "objects/codeIR/parser.tab.c"
    break;

  case 95: /* char_declaration_local: ID RECEIVE expression  */
#line 735 "compiler/parser.y"
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
#line 2773 "objects/codeIR/parser.tab.c"
    break;

  case 96: /* bool_declaration_locals: BOOL bool_declaration_local bool_declaration_local_list DONE  */
#line 752 "compiler/parser.y"
                                                                   {}
#line 2779 "objects/codeIR/parser.tab.c"
    break;

  case 97: /* bool_declaration_local_list: %empty  */
#line 755 "compiler/parser.y"
                  {}
#line 2785 "objects/codeIR/parser.tab.c"
    break;

  case 98: /* bool_declaration_local_list: COMMA bool_declaration_local bool_declaration_local_list  */
#line 756 "compiler/parser.y"
                                                               {}
#line 2791 "objects/codeIR/parser.tab.c"
    break;

  case 99: /* bool_declaration_local: ID  */
#line 759 "compiler/parser.y"
         {
        insertSymbol((yyvsp[0].id), -DBL_MAX, TYPE_BOOL);
        allocaVars((yyvsp[0].id), TYPE_BOOL);
    }
#line 2800 "objects/codeIR/parser.tab.c"
    break;

  case 100: /* bool_declaration_local: ID RECEIVE expression  */
#line 763 "compiler/parser.y"
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
#line 2819 "objects/codeIR/parser.tab.c"
    break;

  case 101: /* array_values_local: expression  */
#line 780 "compiler/parser.y"
                 {
        if(vals) {
            free(vals);
        }
        vals = malloc(sizeof(double));
        vals[0] = (yyvsp[0].number).value;
        array_value_count = 1;
    }
#line 2832 "objects/codeIR/parser.tab.c"
    break;

  case 102: /* array_values_local: array_values_local COMMA expression  */
#line 788 "compiler/parser.y"
                                          {
        vals = realloc(vals, sizeof(double) * (array_value_count + 1));
        vals[array_value_count] = (yyvsp[0].number).value;
        array_value_count++;
}
#line 2842 "objects/codeIR/parser.tab.c"
    break;

  case 103: /* comand: assignment  */
#line 796 "compiler/parser.y"
                 {}
#line 2848 "objects/codeIR/parser.tab.c"
    break;

  case 104: /* comand: increment  */
#line 797 "compiler/parser.y"
                {}
#line 2854 "objects/codeIR/parser.tab.c"
    break;

  case 105: /* comand: if_statement  */
#line 798 "compiler/parser.y"
                   {}
#line 2860 "objects/codeIR/parser.tab.c"
    break;

  case 106: /* comand: while  */
#line 799 "compiler/parser.y"
            {}
#line 2866 "objects/codeIR/parser.tab.c"
    break;

  case 107: /* comand: for  */
#line 800 "compiler/parser.y"
          {}
#line 2872 "objects/codeIR/parser.tab.c"
    break;

  case 108: /* comand: do_while  */
#line 801 "compiler/parser.y"
               {}
#line 2878 "objects/codeIR/parser.tab.c"
    break;

  case 109: /* comand: printf  */
#line 802 "compiler/parser.y"
             {}
#line 2884 "objects/codeIR/parser.tab.c"
    break;

  case 110: /* comand: scanf  */
#line 803 "compiler/parser.y"
            {}
#line 2890 "objects/codeIR/parser.tab.c"
    break;

  case 111: /* comand: return  */
#line 804 "compiler/parser.y"
             {}
#line 2896 "objects/codeIR/parser.tab.c"
    break;

  case 112: /* comand: call_function  */
#line 805 "compiler/parser.y"
                    {}
#line 2902 "objects/codeIR/parser.tab.c"
    break;

  case 114: /* assignment_notfull: ID RECEIVE expression  */
#line 814 "compiler/parser.y"
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
                insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, symbol->type);
            }
            // Cast se necessário
            else if (symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                value = LLVMBuildSIToFP(builder, value, llvm_type, "inttofloat");
                LLVMBuildStore(builder, value, var);
                insertSymbol((yyvsp[-2].id), (yyvsp[0].number).value, symbol->type);
            }
            else if (symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
                value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
                LLVMBuildStore(builder, value, var);
                insertSymbol((yyvsp[-2].id), (int)(yyvsp[0].number).value, symbol->type);
            } else {
                fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
            }
        } else {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
        }
    }
#line 2944 "objects/codeIR/parser.tab.c"
    break;

  case 115: /* assignment_notfull: ID LEFTBRACKET expression RIGHTBRACKET RECEIVE expression  */
#line 851 "compiler/parser.y"
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
        LLVMValueRef array_ptr = LLVMBuildGEP2(
            builder,
            LLVMArrayType(LLVMInt32TypeInContext(context), symbol->size),
            var,
            indices,
            2,
            "arrayptr"
        );
        
        // Armazena o valor no array
        if ((yyvsp[0].number).type == TYPE_INT) {
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-5].id), (yyvsp[0].number).value, (int)(yyvsp[-3].number).value);
        } else if ((yyvsp[0].number).type == TYPE_FLOAT) {
            fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-5].id), yylineno);
            value = LLVMBuildFPToSI(builder, value, llvm_type, "floattoint");
            LLVMBuildStore(builder, value, array_ptr);
            insertValueArraySymbol((yyvsp[-5].id), (int)(yyvsp[0].number).value, (int)(yyvsp[-3].number).value);
        } else {
            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
        }
    }
#line 2983 "objects/codeIR/parser.tab.c"
    break;

  case 116: /* assignment_notfull: increment  */
#line 885 "compiler/parser.y"
                {}
#line 2989 "objects/codeIR/parser.tab.c"
    break;

  case 117: /* increment: ID PLUS RECEIVE expression  */
#line 890 "compiler/parser.y"
                                 {
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef incremented_value;
            
            if(symbol->type == (yyvsp[0].number).type) {
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value + (yyvsp[0].number).value, symbol->type);
                // Incrementa o valor
                if (symbol->type == TYPE_INT) {
                    incremented_value = LLVMBuildAdd(builder, current_value, (yyvsp[0].number).llvm_value, "incremented_value");
                } else {
                    incremented_value = LLVMBuildFAdd(builder, current_value, (yyvsp[0].number).llvm_value, "incremented_value");
                }
            }
            else if(symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, llvm_type, "floattoint");
                incremented_value = LLVMBuildAdd(builder, current_value, float_to_int, "incremented_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value + (int)(yyvsp[0].number).value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, llvm_type, "inttofloat");
                incremented_value = LLVMBuildFAdd(builder, current_value, int_to_float, "incremented_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value + (yyvsp[0].number).value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, incremented_value, var);
        } else {
            fprintf(stderr, "Error: cannot increment variable '%s' of type %d at line %d.\n", (yyvsp[-3].id), symbol->type, yylineno);
        }
    }
#line 3042 "objects/codeIR/parser.tab.c"
    break;

  case 118: /* increment: ID MIN RECEIVE expression  */
#line 938 "compiler/parser.y"
                                {
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");
            
            LLVMValueRef decremented_value;

            if(symbol->type == (yyvsp[0].number).type) {
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value - (yyvsp[0].number).value, symbol->type);
                // Decrementa o valor
                if (symbol->type == TYPE_INT) {
                    decremented_value = LLVMBuildSub(builder, current_value, (yyvsp[0].number).llvm_value, "decremented_value");
                } else {
                    decremented_value = LLVMBuildFSub(builder, current_value, (yyvsp[0].number).llvm_value, "decremented_value");
                }
            }
            else if(symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, llvm_type, "floattoint");
                decremented_value = LLVMBuildSub(builder, current_value, float_to_int, "decremented_value");
                insertSymbol((yyvsp[-3].id), symbol->value - (int)(yyvsp[0].number).value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, llvm_type, "inttofloat");
                decremented_value = LLVMBuildFSub(builder, current_value, int_to_float, "decremented_value");
                insertSymbol((yyvsp[-3].id), symbol->value - (yyvsp[0].number).value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, decremented_value, var);
        } else {
            fprintf(stderr, "Error: cannot decrement variable '%s' of type %d at line %d.\n", (yyvsp[-3].id), symbol->type, yylineno);
        }
    }
#line 3093 "objects/codeIR/parser.tab.c"
    break;

  case 119: /* increment: ID MULT RECEIVE expression  */
#line 984 "compiler/parser.y"
                                 {
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
        }
        else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef multiplied_value;
            
            if(symbol->type == (yyvsp[0].number).type) {
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value * (yyvsp[0].number).value, symbol->type);
                // Multiplica o valor
                if (symbol->type == TYPE_INT) {
                    multiplied_value = LLVMBuildMul(builder, current_value, (yyvsp[0].number).llvm_value, "multiplied_value");
                } else {
                    multiplied_value = LLVMBuildFMul(builder, current_value, (yyvsp[0].number).llvm_value, "multiplied_value");
                }
            }
            else if(symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, llvm_type, "floattoint");
                multiplied_value = LLVMBuildMul(builder, current_value, float_to_int, "multiplied_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value * (int)(yyvsp[0].number).value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, llvm_type, "inttofloat");
                multiplied_value = LLVMBuildFMul(builder, current_value, int_to_float, "multiplied_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value * (yyvsp[0].number).value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, multiplied_value, var);
        } else {
            fprintf(stderr, "Error: cannot multiply variable '%s' of type %d at line %d.\n", (yyvsp[-3].id), symbol->type, yylineno);
        }
    }
#line 3146 "objects/codeIR/parser.tab.c"
    break;

  case 120: /* increment: ID DIV RECEIVE expression  */
#line 1032 "compiler/parser.y"
                                {
        Symbol* symbol = findSymbol((yyvsp[-3].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
        } else if ((yyvsp[0].number).value == 0.0) {
            fprintf(stderr, "Error: division by zero for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
        } else if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-3].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef divided_value;
            
            if(symbol->type == (yyvsp[0].number).type) {
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value / (yyvsp[0].number).value, symbol->type);
                // Divide o valor
                if (symbol->type == TYPE_INT) {
                    divided_value = LLVMBuildUDiv(builder, current_value, (yyvsp[0].number).llvm_value, "divided_value");
                } else {
                    divided_value = LLVMBuildFDiv(builder, current_value, (yyvsp[0].number).llvm_value, "divided_value");
                }
            }
            else if(symbol->type == TYPE_INT && (yyvsp[0].number).type == TYPE_FLOAT) {
                fprintf(stderr, "Warning: casting float to int for variable '%s' at line %d.\n", (yyvsp[-3].id), yylineno);
                LLVMValueRef float_to_int = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, llvm_type, "floattoint");
                divided_value = LLVMBuildUDiv(builder, current_value, float_to_int, "divided_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value / (int)(yyvsp[0].number).value, symbol->type);
            } else if(symbol->type == TYPE_FLOAT && (yyvsp[0].number).type == TYPE_INT) {
                LLVMValueRef int_to_float = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, llvm_type, "inttofloat");
                divided_value = LLVMBuildFDiv(builder, current_value, int_to_float, "divided_value");
                // Atualiza a tabela de símbolos
                insertSymbol((yyvsp[-3].id), symbol->value / (yyvsp[0].number).value, symbol->type);
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, divided_value, var);
        } else {
            fprintf(stderr, "Error: cannot divide variable '%s' of type %d at line %d.\n", (yyvsp[-3].id), symbol->type, yylineno);
        }
    }
#line 3200 "objects/codeIR/parser.tab.c"
    break;

  case 121: /* increment: ID PLUS PLUS  */
#line 1081 "compiler/parser.y"
                   {
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
        }
        
        if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef incremented_value;

            if (symbol->type == TYPE_INT) {
                // Incrementa o valor
                incremented_value = LLVMBuildAdd(builder, current_value, LLVMConstInt(llvm_type, 1, false), "incremented_value");
            } else {
                // Incrementa o valor
                incremented_value = LLVMBuildFAdd(builder, current_value, LLVMConstReal(llvm_type, 1.0), "incremented_value");
            }
            // Armazena o novo valor
            LLVMBuildStore(builder, incremented_value, var);
            
            // Atualiza a tabela de símbolos
            insertSymbol((yyvsp[-2].id), symbol->value + 1, symbol->type);
        } else {
            fprintf(stderr, "Error: cannot increment variable '%s' of type %d at line %d.\n", (yyvsp[-2].id), symbol->type, yylineno);
        }
    }
#line 3241 "objects/codeIR/parser.tab.c"
    break;

  case 122: /* increment: ID MIN MIN  */
#line 1117 "compiler/parser.y"
                 {
        Symbol* symbol = findSymbol((yyvsp[-2].id));
        if (!symbol) {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", (yyvsp[-2].id), yylineno);
        }
        if(symbol->type == TYPE_INT || symbol->type == TYPE_FLOAT) {
            LLVMValueRef var = getVarLLVM((yyvsp[-2].id));
            LLVMTypeRef llvm_type;
            switch (symbol->type) {
                case TYPE_INT:   llvm_type = LLVMInt32TypeInContext(context); break;
                case TYPE_FLOAT: llvm_type = LLVMDoubleTypeInContext(context); break;
                default:         llvm_type = LLVMInt32TypeInContext(context); break;
            }

            // Carrega o valor atual
            LLVMValueRef current_value = LLVMBuildLoad2(builder, llvm_type, var, "current_value");

            LLVMValueRef decremented_value;

            if (symbol->type == TYPE_INT) {
                // Decrementa o valor
                decremented_value = LLVMBuildSub(builder, current_value, LLVMConstInt(llvm_type, 1, false), "decremented_value");
            } else {
                // Decrementa o valor
                decremented_value = LLVMBuildFSub(builder, current_value, LLVMConstReal(llvm_type, 1.0), "decremented_value");
            }

            // Armazena o novo valor
            LLVMBuildStore(builder, decremented_value, var);
            
            // Atualiza a tabela de símbolos
            insertSymbol((yyvsp[-2].id), symbol->value - 1, symbol->type);
        } else {
            fprintf(stderr, "Error: cannot decrement variable '%s' of type %d at line %d.\n", (yyvsp[-2].id), symbol->type, yylineno);
        }
    }
#line 3282 "objects/codeIR/parser.tab.c"
    break;

  case 123: /* $@11: %empty  */
#line 1157 "compiler/parser.y"
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

        haveRetAll = 1;

        haveRet = 0;
    }
#line 3312 "objects/codeIR/parser.tab.c"
    break;

  case 124: /* $@12: %empty  */
#line 1181 "compiler/parser.y"
                                        {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3329 "objects/codeIR/parser.tab.c"
    break;

  case 125: /* if_statement: IF LEFTPAR expression RIGHTPAR $@11 LEFTKEYS program_locals RIGHTKEYS $@12 else_if_chain  */
#line 1192 "compiler/parser.y"
                    {
        // Finaliza este contexto
        ConditionalContext current = pop_cond_context();
        LLVMPositionBuilderAtEnd(builder, current.endBB);
        
        LLVMBasicBlockRef endBB = LLVMAppendBasicBlockInContext(context, currentFunc, "endif");
        LLVMBuildBr(builder, endBB);

        LLVMPositionBuilderAtEnd(builder, endBB);

        if(haveRetAll == 1) {
            LLVMBuildUnreachable(builder);
        }
    }
#line 3348 "objects/codeIR/parser.tab.c"
    break;

  case 126: /* else_if_chain: %empty  */
#line 1209 "compiler/parser.y"
                  {
        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 3357 "objects/codeIR/parser.tab.c"
    break;

  case 127: /* else_if_chain: ELSE LEFTPAR expression RIGHTPAR  */
#line 1213 "compiler/parser.y"
                                       {
        fprintf(stderr, "Error: else cannot have a condition at line %d.\n", yylineno);
    }
#line 3365 "objects/codeIR/parser.tab.c"
    break;

  case 128: /* $@13: %empty  */
#line 1216 "compiler/parser.y"
           {

        pushScope();
        
        ConditionalContext* current = top_cond_context();
        // Transforma o nextCondBB em bloco else
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);

        haveRet = 0;
    }
#line 3380 "objects/codeIR/parser.tab.c"
    break;

  case 129: /* else_if_chain: ELSE $@13 LEFTKEYS program_locals RIGHTKEYS  */
#line 1225 "compiler/parser.y"
                                        {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
    }
#line 3396 "objects/codeIR/parser.tab.c"
    break;

  case 130: /* $@14: %empty  */
#line 1236 "compiler/parser.y"
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

        haveRet = 0;
    }
#line 3425 "objects/codeIR/parser.tab.c"
    break;

  case 131: /* $@15: %empty  */
#line 1259 "compiler/parser.y"
                                        {

        popScope();

        if(haveRet == 0) {
            haveRetAll = 0;
        }

        ConditionalContext* current = top_cond_context();
        LLVMBuildBr(builder, current->endBB);
        LLVMPositionBuilderAtEnd(builder, current->nextCondBB);
    }
#line 3442 "objects/codeIR/parser.tab.c"
    break;

  case 132: /* else_if_chain: ELSEIF LEFTPAR expression RIGHTPAR $@14 LEFTKEYS program_locals RIGHTKEYS $@15 else_if_chain  */
#line 1270 "compiler/parser.y"
                    {}
#line 3448 "objects/codeIR/parser.tab.c"
    break;

  case 133: /* $@16: %empty  */
#line 1278 "compiler/parser.y"
                                                  {
        pushScope();
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        // Gera branch condicional
        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-3].while_blocks).bodyBB, (yyvsp[-3].while_blocks).endWHILEBB);

        // Corpo do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-3].while_blocks).bodyBB);
    }
#line 3465 "objects/codeIR/parser.tab.c"
    break;

  case 134: /* while: WHILE while_aux LEFTPAR expression RIGHTPAR $@16 LEFTKEYS program_locals RIGHTKEYS  */
#line 1289 "compiler/parser.y"
                                        {
        // Ao final do corpo, volta para o condicional
        LLVMBuildBr(builder, (yyvsp[-7].while_blocks).condBB);

        // Posiciona o builder no bloco de saída do while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].while_blocks).endWHILEBB);

        popScope();
    }
#line 3479 "objects/codeIR/parser.tab.c"
    break;

  case 135: /* while_aux: %empty  */
#line 1301 "compiler/parser.y"
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
#line 3496 "objects/codeIR/parser.tab.c"
    break;

  case 136: /* $@17: %empty  */
#line 1317 "compiler/parser.y"
                                            {
        // Pula direto para o bloco de condição após a declaração
        LLVMBuildBr(builder, (yyvsp[-2].for_blocks).condBB);

        // Posiciona no bloco condicional
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-2].for_blocks).condBB);
    }
#line 3508 "objects/codeIR/parser.tab.c"
    break;

  case 137: /* $@18: %empty  */
#line 1323 "compiler/parser.y"
                      {
        pushScope();
        if ((yyvsp[-1].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }

        // Condicional
        LLVMBuildCondBr(builder, (yyvsp[-1].number).llvm_value, (yyvsp[-5].for_blocks).bodyBB, (yyvsp[-5].for_blocks).endFORBB);

        // Incremento do for
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-5].for_blocks).incBB);
    }
#line 3525 "objects/codeIR/parser.tab.c"
    break;

  case 138: /* $@19: %empty  */
#line 1334 "compiler/parser.y"
                         {
        // Posiciona o builder no bloco de corpo
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-7].for_blocks).bodyBB);
    }
#line 3534 "objects/codeIR/parser.tab.c"
    break;

  case 139: /* for: FOR for_aux LEFTPAR declaration_local $@17 expression DONE $@18 assignment_notfull $@19 RIGHTPAR LEFTKEYS program_locals RIGHTKEYS  */
#line 1338 "compiler/parser.y"
                                               {
        // Ao final do corpo, volta para o incremento
        LLVMBuildBr(builder, (yyvsp[-12].for_blocks).incBB);

        LLVMPositionBuilderAtEnd(builder, (yyvsp[-12].for_blocks).incBB);

        // Ao final do incremento, volta para a condição
        LLVMBuildBr(builder, (yyvsp[-12].for_blocks).condBB);

        // Posiciona no final do for
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-12].for_blocks).endFORBB);

        popScope();
    }
#line 3553 "objects/codeIR/parser.tab.c"
    break;

  case 140: /* for_aux: %empty  */
#line 1355 "compiler/parser.y"
      {
        // Cria os blocos condicional, corpo e final
        (yyval.for_blocks).condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.cond");
        (yyval.for_blocks).bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.body");
        (yyval.for_blocks).incBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.inc");
        (yyval.for_blocks).endFORBB = LLVMAppendBasicBlockInContext(context, currentFunc, "for.end");
    }
#line 3565 "objects/codeIR/parser.tab.c"
    break;

  case 141: /* $@20: %empty  */
#line 1365 "compiler/parser.y"
                      {
        pushScope();

        // Posiciona o builder no corpo do do-while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[0].while_blocks).bodyBB);
    }
#line 3576 "objects/codeIR/parser.tab.c"
    break;

  case 142: /* $@21: %empty  */
#line 1370 "compiler/parser.y"
                                        {
        // Ao final do corpo, volta para a condição
        LLVMBuildBr(builder, (yyvsp[-4].while_blocks).condBB);

        // Posiciona o builder no bloco de condição
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-4].while_blocks).condBB);
    }
#line 3588 "objects/codeIR/parser.tab.c"
    break;

  case 143: /* do_while: DO do_while_aux $@20 LEFTKEYS program_locals RIGHTKEYS $@21 WHILE LEFTPAR expression RIGHTPAR DONE  */
#line 1376 "compiler/parser.y"
                                             {
        if ((yyvsp[-2].number).type != TYPE_BOOL) {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
        // Gera branch condicional
        LLVMBuildCondBr(builder, (yyvsp[-2].number).llvm_value, (yyvsp[-10].while_blocks).bodyBB, (yyvsp[-10].while_blocks).endWHILEBB);

        // Posiciona o builder no final do do-while
        LLVMPositionBuilderAtEnd(builder, (yyvsp[-10].while_blocks).endWHILEBB);

        popScope();
    }
#line 3605 "objects/codeIR/parser.tab.c"
    break;

  case 144: /* do_while_aux: %empty  */
#line 1391 "compiler/parser.y"
      {
        // Cria blocos para o corpo e condicional do do-while
        (yyval.while_blocks).bodyBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.body");
        (yyval.while_blocks).condBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.cond");
        (yyval.while_blocks).endWHILEBB = LLVMAppendBasicBlockInContext(context, currentFunc, "do.end");

        // Gera branch para o corpo do do-while
        LLVMBuildBr(builder, (yyval.while_blocks).bodyBB);
    }
#line 3619 "objects/codeIR/parser.tab.c"
    break;

  case 145: /* printf: PRINTF LEFTPAR STRING printf_args RIGHTPAR DONE  */
#line 1404 "compiler/parser.y"
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
#line 3642 "objects/codeIR/parser.tab.c"
    break;

  case 146: /* printf_args: %empty  */
#line 1425 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3648 "objects/codeIR/parser.tab.c"
    break;

  case 147: /* printf_args: COMMA expression printf_args  */
#line 1426 "compiler/parser.y"
                                   {
        (yyval.printf).values[0] = (yyvsp[-1].number).llvm_value;
        for (int i = 0; i < (yyvsp[0].printf).count; i++)
            (yyval.printf).values[i+1] = (yyvsp[0].printf).values[i];
        (yyval.printf).count = (yyvsp[0].printf).count + 1;
    }
#line 3659 "objects/codeIR/parser.tab.c"
    break;

  case 148: /* scanf: SCANF LEFTPAR STRING scanf_args RIGHTPAR DONE  */
#line 1436 "compiler/parser.y"
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
#line 3682 "objects/codeIR/parser.tab.c"
    break;

  case 149: /* scanf_args: %empty  */
#line 1457 "compiler/parser.y"
                  { (yyval.printf).count = 0; }
#line 3688 "objects/codeIR/parser.tab.c"
    break;

  case 150: /* scanf_args: COMMA ADDRESS ID scanf_args  */
#line 1458 "compiler/parser.y"
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
#line 3705 "objects/codeIR/parser.tab.c"
    break;

  case 151: /* return: RETURN expression DONE  */
#line 1473 "compiler/parser.y"
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
        haveRet = 1;
    }
#line 3722 "objects/codeIR/parser.tab.c"
    break;

  case 152: /* return: RETURN DONE  */
#line 1485 "compiler/parser.y"
                  {
        if(functionList->returnType != TYPE_VOID) {
            fprintf(stderr, "Error: function '%s' must return a value at line %d.\n", functionList->id, yylineno);
        } else {
            LLVMBuildRetVoid(builder);
        }
        haveRet = 1;
}
#line 3735 "objects/codeIR/parser.tab.c"
    break;

  case 153: /* expression: soma_sub  */
#line 1497 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3741 "objects/codeIR/parser.tab.c"
    break;

  case 154: /* expression: mult_div  */
#line 1498 "compiler/parser.y"
               { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3747 "objects/codeIR/parser.tab.c"
    break;

  case 155: /* expression: LEFTPAR expression RIGHTPAR  */
#line 1499 "compiler/parser.y"
                                  { (yyval.number).value = (yyvsp[-1].number).value; (yyval.number).type = (yyvsp[-1].number).type; (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; }
#line 3753 "objects/codeIR/parser.tab.c"
    break;

  case 156: /* expression: comparison  */
#line 1500 "compiler/parser.y"
                 { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3759 "objects/codeIR/parser.tab.c"
    break;

  case 157: /* expression: log_exp  */
#line 1501 "compiler/parser.y"
              { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3765 "objects/codeIR/parser.tab.c"
    break;

  case 158: /* expression: cast  */
#line 1502 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3771 "objects/codeIR/parser.tab.c"
    break;

  case 159: /* expression: call_function_notfull  */
#line 1503 "compiler/parser.y"
                            { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3777 "objects/codeIR/parser.tab.c"
    break;

  case 160: /* expression: term  */
#line 1504 "compiler/parser.y"
           { (yyval.number).value = (yyvsp[0].number).value; (yyval.number).type = (yyvsp[0].number).type; (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; }
#line 3783 "objects/codeIR/parser.tab.c"
    break;

  case 161: /* soma_sub: expression PLUS expression  */
#line 1508 "compiler/parser.y"
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
#line 3810 "objects/codeIR/parser.tab.c"
    break;

  case 162: /* soma_sub: expression MIN expression  */
#line 1530 "compiler/parser.y"
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
#line 3837 "objects/codeIR/parser.tab.c"
    break;

  case 163: /* mult_div: expression MULT expression  */
#line 1555 "compiler/parser.y"
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
#line 3864 "objects/codeIR/parser.tab.c"
    break;

  case 164: /* mult_div: expression DIV expression  */
#line 1577 "compiler/parser.y"
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
#line 3897 "objects/codeIR/parser.tab.c"
    break;

  case 165: /* comparison: expression LESS expression  */
#line 1608 "compiler/parser.y"
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
#line 3924 "objects/codeIR/parser.tab.c"
    break;

  case 166: /* comparison: expression GREAT expression  */
#line 1630 "compiler/parser.y"
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
#line 3951 "objects/codeIR/parser.tab.c"
    break;

  case 167: /* comparison: expression LEQUAL expression  */
#line 1652 "compiler/parser.y"
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
#line 3978 "objects/codeIR/parser.tab.c"
    break;

  case 168: /* comparison: expression GEQUAL expression  */
#line 1674 "compiler/parser.y"
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
#line 4005 "objects/codeIR/parser.tab.c"
    break;

  case 169: /* comparison: expression EQUAL expression  */
#line 1696 "compiler/parser.y"
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
#line 4036 "objects/codeIR/parser.tab.c"
    break;

  case 170: /* comparison: expression NEQUAL expression  */
#line 1722 "compiler/parser.y"
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
#line 4066 "objects/codeIR/parser.tab.c"
    break;

  case 171: /* log_exp: expression AND expression  */
#line 1750 "compiler/parser.y"
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
#line 4082 "objects/codeIR/parser.tab.c"
    break;

  case 172: /* log_exp: expression OR expression  */
#line 1761 "compiler/parser.y"
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
#line 4098 "objects/codeIR/parser.tab.c"
    break;

  case 173: /* log_exp: NOT expression  */
#line 1772 "compiler/parser.y"
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
#line 4114 "objects/codeIR/parser.tab.c"
    break;

  case 174: /* cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1786 "compiler/parser.y"
                                                       {
        int temp = (int) (yyvsp[-1].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        switch ((yyvsp[-1].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; // Já é int
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = LLVMBuildSExt(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildZExt(builder, (yyvsp[-1].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to int at line %d.\n", typeToString((yyvsp[-1].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4143 "objects/codeIR/parser.tab.c"
    break;

  case 175: /* cast: LEFTPAR INT RIGHTPAR term  */
#line 1810 "compiler/parser.y"
                                {
        int temp = (int) (yyvsp[0].number).value;
        (yyval.number).value = (double) temp;
        (yyval.number).type = TYPE_INT;
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; // Já é int
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = LLVMBuildSExt(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildZExt(builder, (yyvsp[0].number).llvm_value, LLVMInt32TypeInContext(context), "castint");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to int at line %d.\n", typeToString((yyvsp[0].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4172 "objects/codeIR/parser.tab.c"
    break;

  case 176: /* cast: LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1834 "compiler/parser.y"
                                                         {
        (yyval.number).value = (yyvsp[-1].number).value;
        (yyval.number).type = TYPE_FLOAT;
        switch ((yyvsp[-1].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; // Já é float
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[-1].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to float at line %d.\n", typeToString((yyvsp[-1].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4200 "objects/codeIR/parser.tab.c"
    break;

  case 177: /* cast: LEFTPAR FLOAT RIGHTPAR term  */
#line 1857 "compiler/parser.y"
                                  {
        (yyval.number).value = (yyvsp[0].number).value;
        (yyval.number).type = TYPE_FLOAT;
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; // Já é float
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildSIToFP(builder, (yyvsp[0].number).llvm_value, LLVMDoubleTypeInContext(context), "castfloat");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to float at line %d.\n", typeToString((yyvsp[0].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4228 "objects/codeIR/parser.tab.c"
    break;

  case 178: /* cast: LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1880 "compiler/parser.y"
                                                        {
        (yyval.number).value = (double) ((char) (yyvsp[-1].number).value);
        (yyval.number).type = TYPE_CHAR;
        switch ((yyvsp[-1].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; // Já é char
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildZExt(builder, (yyvsp[-1].number).llvm_value, LLVMInt8TypeInContext(context), "castbool");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to char at line %d.\n", typeToString((yyvsp[-1].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4256 "objects/codeIR/parser.tab.c"
    break;

  case 179: /* cast: LEFTPAR CHAR RIGHTPAR term  */
#line 1903 "compiler/parser.y"
                                 {
        (yyval.number).value = (double) ((char) (yyvsp[0].number).value);
        (yyval.number).type = TYPE_CHAR;
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:
                (yyval.number).llvm_value = LLVMBuildTrunc(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_FLOAT:
                (yyval.number).llvm_value = LLVMBuildFPToSI(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castchar");
                break;
            case TYPE_CHAR:
                (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; // Já é char
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = LLVMBuildZExt(builder, (yyvsp[0].number).llvm_value, LLVMInt8TypeInContext(context), "castbool");
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to char at line %d.\n", typeToString((yyvsp[0].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4284 "objects/codeIR/parser.tab.c"
    break;

  case 180: /* cast: LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR  */
#line 1926 "compiler/parser.y"
                                                        {
        (yyval.number).value = ((yyvsp[-1].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        LLVMValueRef zero;
        switch ((yyvsp[-1].number).type) {
            case TYPE_INT:
                zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
                (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
                break;
            case TYPE_FLOAT:
                zero = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
                (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
                break;
            case TYPE_CHAR:
                zero = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
                (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[-1].number).llvm_value, zero, "castbool");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = (yyvsp[-1].number).llvm_value; // Já é bool
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to bool at line %d.\n", typeToString((yyvsp[-1].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4316 "objects/codeIR/parser.tab.c"
    break;

  case 181: /* cast: LEFTPAR BOOL RIGHTPAR term  */
#line 1953 "compiler/parser.y"
                                 {
        (yyval.number).value = ((yyvsp[0].number).value != 0.0) ? 1.0 : 0.0;
        (yyval.number).type = TYPE_BOOL;
        LLVMValueRef zero;
        switch ((yyvsp[0].number).type) {
            case TYPE_INT:
                zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
                (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
                break;
            case TYPE_FLOAT:
                zero = LLVMConstReal(LLVMDoubleTypeInContext(context), 0.0);
                (yyval.number).llvm_value = LLVMBuildFCmp(builder, LLVMRealUNE, (yyvsp[0].number).llvm_value, zero, "castbool");
                break;
            case TYPE_CHAR:
                zero = LLVMConstInt(LLVMInt8TypeInContext(context), 0, 0);
                (yyval.number).llvm_value = LLVMBuildICmp(builder, LLVMIntNE, (yyvsp[0].number).llvm_value, zero, "castbool");
                break;
            case TYPE_BOOL:
                (yyval.number).llvm_value = (yyvsp[0].number).llvm_value; // Já é bool
                break;
            default:
                fprintf(stderr, "Error: cannot cast type %s to bool at line %d.\n", typeToString((yyvsp[0].number).type), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
                (yyval.number).llvm_value = NULL;
        }
    }
#line 4348 "objects/codeIR/parser.tab.c"
    break;

  case 182: /* call_function: call_function_notfull DONE  */
#line 1983 "compiler/parser.y"
                                 {}
#line 4354 "objects/codeIR/parser.tab.c"
    break;

  case 183: /* call_function_notfull: ID LEFTPAR call_parameters RIGHTPAR  */
#line 1987 "compiler/parser.y"
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
#line 4401 "objects/codeIR/parser.tab.c"
    break;

  case 184: /* call_parameters: %empty  */
#line 2032 "compiler/parser.y"
                  {}
#line 4407 "objects/codeIR/parser.tab.c"
    break;

  case 185: /* call_parameters: term call_parameter_list  */
#line 2033 "compiler/parser.y"
                               {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 4417 "objects/codeIR/parser.tab.c"
    break;

  case 186: /* call_parameter_list: %empty  */
#line 2041 "compiler/parser.y"
                  {}
#line 4423 "objects/codeIR/parser.tab.c"
    break;

  case 187: /* call_parameter_list: COMMA term call_parameter_list  */
#line 2042 "compiler/parser.y"
                                     {
        param_call[param_call_count].value = (yyvsp[-1].number).value;
        param_call[param_call_count].type = (yyvsp[-1].number).type;
        param_call[param_call_count++].llvm_value = (yyvsp[-1].number).llvm_value;
    }
#line 4433 "objects/codeIR/parser.tab.c"
    break;

  case 188: /* term: NUMBER  */
#line 2050 "compiler/parser.y"
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
#line 4448 "objects/codeIR/parser.tab.c"
    break;

  case 189: /* term: ID  */
#line 2060 "compiler/parser.y"
         {
        Symbol* sym = findSymbol((yyvsp[0].id));
        ArraySymbol* array_sym = findArraySymbol((yyvsp[0].id));
        if (!sym) {
            if (!array_sym) {
                fprintf(stderr, "Undeclared variable '%s' at line %d\n", (yyvsp[0].id), yylineno);
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_UNKNOWN;
            } else {
                // É um vetor, retorna ponteiro para o array
                (yyval.number).value = -1;
                (yyval.number).type = TYPE_POINTER;
                (yyval.number).llvm_value = getVarLLVM((yyvsp[0].id)); // Ponteiro para o array
            }
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
#line 4488 "objects/codeIR/parser.tab.c"
    break;

  case 190: /* term: ID LEFTBRACKET expression RIGHTBRACKET  */
#line 2095 "compiler/parser.y"
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
                        LLVMValueRef var = getVarLLVM((yyvsp[-3].id)); // ponteiro para o array
                        LLVMValueRef idxs[2] = {
                            LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0),
                            (yyvsp[-1].number).llvm_value // índice dinâmico
                        };
                        LLVMValueRef elem_ptr = LLVMBuildGEP2(
                            builder,
                            LLVMArrayType(LLVMInt32TypeInContext(context), array_sym->size),
                            var,
                            idxs,
                            2,
                            "arrayelem"
                        );
                        LLVMTypeRef llvm_type = LLVMInt32TypeInContext(context);
                        (yyval.number).llvm_value = LLVMBuildLoad2(builder, llvm_type, elem_ptr, "loadtmp");
                    }
                }
            }
        }
    }
#line 4537 "objects/codeIR/parser.tab.c"
    break;

  case 191: /* term: CARACTERE  */
#line 2139 "compiler/parser.y"
                {
        (yyval.number).value = (double) (yyvsp[0].caractere);
        (yyval.number).type = TYPE_CHAR;
        (yyval.number).llvm_value = LLVMConstInt(LLVMInt8TypeInContext(context), (yyvsp[0].caractere), 0);
}
#line 4547 "objects/codeIR/parser.tab.c"
    break;


#line 4551 "objects/codeIR/parser.tab.c"

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

#line 2146 "compiler/parser.y"


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

    // Adiciona declare void @exit(i32)
    LLVMTypeRef exit_arg_types[] = { LLVMInt32TypeInContext(context) };
    LLVMTypeRef exit_type = LLVMFunctionType(LLVMVoidTypeInContext(context), exit_arg_types, 1, 0);
    LLVMAddFunction(module, "exit", exit_type);

    // Cria a função _start
    LLVMTypeRef start_type = LLVMFunctionType(LLVMVoidTypeInContext(context), NULL, 0, 0);
    LLVMValueRef start_func = LLVMAddFunction(module, "_start", start_type);
    LLVMBasicBlockRef entry = LLVMAppendBasicBlockInContext(context, start_func, "entry");
    LLVMPositionBuilderAtEnd(builder, entry);

    // Chama main()
    LLVMValueRef main_func = LLVMGetNamedFunction(module, "main");
    LLVMTypeRef main_type = LLVMFunctionType(LLVMInt32TypeInContext(context), NULL, 0, 0);
    if (main_func) {
        LLVMValueRef *args = NULL; // Ponteiro nulo para argumentos
        LLVMBuildCall2(builder, main_type, main_func, args, 0, "");
    }

    // Chama exit(0)
    LLVMValueRef zero = LLVMConstInt(LLVMInt32TypeInContext(context), 0, 0);
    LLVMValueRef exit_func = LLVMGetNamedFunction(module, "exit");
    LLVMValueRef exit_args[] = { zero };
    LLVMBuildCall2(builder, exit_type, exit_func, exit_args, 1, "");

    LLVMBuildUnreachable(builder);

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
