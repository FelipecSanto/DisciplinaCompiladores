%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"

%}

%option noyywrap
%option yylineno

%%

"+"                 {return PLUS;}
"-"                 {return MIN;}
"/"                 {return DIV;}
"*"                 {return MULT;}
"="		            {return EQUAL;}
[a-z]               {yylval.valueInt=(int)(yytext[0])- 97; return VARIABLE;}
[0-9]+(\.[0-9]+)?   {yylval.value = atof(yytext); return NUM;}
[ \t]               {}
"\n"                {return DONE;}
"//".*              {return DONE;}
"CLEAR"             {return CLEAR;}
.                   {fprintf(stderr, "Error: invalid character on line %d: '%s'\n", yylineno, yytext); exit(1);}

%%