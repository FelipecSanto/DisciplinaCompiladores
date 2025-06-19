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

#ifndef YY_YY_OBJECTS_PARSER_TAB_H_INCLUDED
# define YY_YY_OBJECTS_PARSER_TAB_H_INCLUDED
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
    WHILE = 267,                   /* WHILE  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    NUMBER = 270,                  /* NUMBER  */
    ID = 271,                      /* ID  */
    STRING = 272,                  /* STRING  */
    CARACTERE = 273,               /* CARACTERE  */
    RECEIVE = 274,                 /* RECEIVE  */
    EQUAL = 275,                   /* EQUAL  */
    NEQUAL = 276,                  /* NEQUAL  */
    LESS = 277,                    /* LESS  */
    GREAT = 278,                   /* GREAT  */
    LEQUAL = 279,                  /* LEQUAL  */
    GEQUAL = 280,                  /* GEQUAL  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    NOT = 283,                     /* NOT  */
    PLUS = 284,                    /* PLUS  */
    MIN = 285,                     /* MIN  */
    MULT = 286,                    /* MULT  */
    DIV = 287,                     /* DIV  */
    LEFTPAR = 288,                 /* LEFTPAR  */
    RIGHTPAR = 289,                /* RIGHTPAR  */
    LEFTKEYS = 290,                /* LEFTKEYS  */
    RIGHTKEYS = 291,               /* RIGHTKEYS  */
    LEFTBRACKET = 292,             /* LEFTBRACKET  */
    RIGHTBRACKET = 293,            /* RIGHTBRACKET  */
    COMMA = 294,                   /* COMMA  */
    DONE = 295                     /* DONE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "compiler/parser.y"

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

#line 122 "objects/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OBJECTS_PARSER_TAB_H_INCLUDED  */
