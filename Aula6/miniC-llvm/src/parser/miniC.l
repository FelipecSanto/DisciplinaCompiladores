%{
#include <stdio.h>
#include <stdlib.h>
#include "VarType.h"

int yylex();
void yyerror(const char* s);
%}

%option noyywrap

%%

// Keywords
WHILE       "while"
IF          "if"
ELSE        "else"
READ        "read"
WRITE       "write"

// Data types
INT         "int"
FLOAT       "float"
CHAR        "char"
BOOL        "bool"

// Operators
PLUS        "\\+"
MIN         "-"
MULT        "\\*"
DIV         "/"
EQUAL       "="
NEQUAL      "!="
LESS        "<"
GREAT       ">"
LEQUAL      "<="
GEQUAL      ">="
AND         "&&"
OR          "\\|\\|"
NOT         "!"

// Delimiters
LEFTPAR     "\\("
RIGHTPAR    "\\)"
LEFTKEYS    "\\{"
RIGHTKEYS   "\\}"
DONE        ";"

// Identifiers and literals
[0-9]+      { yylval.number.value = atof(yytext); yylval.number.type = TYPE_INT; return NUMBER; }
\"[^\"]*\"  { yylval.id = strdup(yytext); return STRING; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.id = strdup(yytext); return ID; }

// Whitespace
[ \t\n]+    { /* ignore whitespace */ }

// Error handling
.           { fprintf(stderr, "Unknown character: %s\n", yytext); }

%%