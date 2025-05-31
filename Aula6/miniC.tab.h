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

#ifndef YY_YY_MINIC_TAB_H_INCLUDED
# define YY_YY_MINIC_TAB_H_INCLUDED
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
    INT = 260,                     /* INT  */
    CHAR = 261,                    /* CHAR  */
    FLOAT = 262,                   /* FLOAT  */
    BOOL = 263,                    /* BOOL  */
    READ = 264,                    /* READ  */
    WRITE = 265,                   /* WRITE  */
    WHILE = 266,                   /* WHILE  */
    ID = 267,                      /* ID  */
    NUMBER = 268,                  /* NUMBER  */
    STRING = 269,                  /* STRING  */
    RECEIVE = 270,                 /* RECEIVE  */
    EQUAL = 271,                   /* EQUAL  */
    NEQUAL = 272,                  /* NEQUAL  */
    LESS = 273,                    /* LESS  */
    GREAT = 274,                   /* GREAT  */
    LEQUAL = 275,                  /* LEQUAL  */
    GEQUAL = 276,                  /* GEQUAL  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    PLUS = 280,                    /* PLUS  */
    MIN = 281,                     /* MIN  */
    MULT = 282,                    /* MULT  */
    DIV = 283,                     /* DIV  */
    LEFTPAR = 284,                 /* LEFTPAR  */
    RIGHTPAR = 285,                /* RIGHTPAR  */
    DONE = 286,                    /* DONE  */
    LEFTKEYS = 287,                /* LEFTKEYS  */
    RIGHTKEYS = 288                /* RIGHTKEYS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 177 "miniC.y"

    struct {
        double value;
        VarType type;
        LLVMValueRef llvm_value;
    } number;
    struct {
        LLVMBasicBlockRef ifBB, elseBB, endIFBB;
    } if_else_blocks;
    struct {
        LLVMBasicBlockRef condBB, bodyBB, endWHILEBB;
    } while_blocks;
    char* id;

#line 112 "miniC.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MINIC_TAB_H_INCLUDED  */
