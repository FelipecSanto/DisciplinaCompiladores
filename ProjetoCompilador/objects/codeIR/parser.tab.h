/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OBJECTS_CODEIR_PARSER_TAB_H_INCLUDED
# define YY_YY_OBJECTS_CODEIR_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    ELSEIF = 260,                  /* ELSEIF  */
    INT = 261,                     /* INT  */
    CHAR = 262,                    /* CHAR  */
    FLOAT = 263,                   /* FLOAT  */
    BOOL = 264,                    /* BOOL  */
    PRINTF = 265,                  /* PRINTF  */
    SCANF = 266,                   /* SCANF  */
    ADDRESS = 267,                 /* ADDRESS  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    DO = 270,                      /* DO  */
    VOID = 271,                    /* VOID  */
    RETURN = 272,                  /* RETURN  */
    NUMBER = 273,                  /* NUMBER  */
    ID = 274,                      /* ID  */
    STRING = 275,                  /* STRING  */
    CARACTERE = 276,               /* CARACTERE  */
    RECEIVE = 277,                 /* RECEIVE  */
    EQUAL = 278,                   /* EQUAL  */
    NEQUAL = 279,                  /* NEQUAL  */
    LESS = 280,                    /* LESS  */
    GREAT = 281,                   /* GREAT  */
    LEQUAL = 282,                  /* LEQUAL  */
    GEQUAL = 283,                  /* GEQUAL  */
    AND = 284,                     /* AND  */
    OR = 285,                      /* OR  */
    NOT = 286,                     /* NOT  */
    PLUS = 287,                    /* PLUS  */
    MIN = 288,                     /* MIN  */
    MULT = 289,                    /* MULT  */
    DIV = 290,                     /* DIV  */
    LEFTPAR = 291,                 /* LEFTPAR  */
    RIGHTPAR = 292,                /* RIGHTPAR  */
    LEFTKEYS = 293,                /* LEFTKEYS  */
    RIGHTKEYS = 294,               /* RIGHTKEYS  */
    LEFTBRACKET = 295,             /* LEFTBRACKET  */
    RIGHTBRACKET = 296,            /* RIGHTBRACKET  */
    COMMA = 297,                   /* COMMA  */
    DONE = 298                     /* DONE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "compiler/parser.y"

    struct {
        double value;
        VarType type;
        LLVMValueRef llvm_value;
    } number;

    char* id;
    char caractere;

    struct {
        LLVMBasicBlockRef ifBB, elseBB, endIFBB;
    } if_else_blocks;
    struct {
        LLVMBasicBlockRef condBB, bodyBB, endWHILEBB;
    } while_blocks;
    struct {
        LLVMBasicBlockRef condBB, bodyBB, incBB, endFORBB;
    } for_blocks;

    struct {
        LLVMValueRef values[10];
        int count;
    } printf;

#line 133 "objects/codeIR/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OBJECTS_CODEIR_PARSER_TAB_H_INCLUDED  */
