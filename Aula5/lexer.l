%{

#include <stdio.h>
#include <string.h>
#include "VarType.h"
#include "miniC.tab.h"


%}

%option noyywrap
%option yylineno

%%

[iI][fF]					{ return IF; }
[eE][lL][sS][eE]			{ return ELSE; }

[iI][nN][tT]				{ return INT; }
[cC][hH][aA][rR]			{ return CHAR; }
[fF][lL][oO][aA][tT]        { return FLOAT; }
[bB][oO][oO][lL]            { return BOOL; }

[Rr][Ee][Aa][Dd]            { return READ; }
[wW][rR][iI][tT][eE]		{ return WRITE; }

[tT][rR][uU][eE]			{ yylval.number.value = 1; yylval.number.type = TYPE_BOOL; return NUMBER; }
[fF][aA][lL][sS][eE]		{ yylval.number.value = 0; yylval.number.type = TYPE_BOOL; return NUMBER; }

[a-zA-Z\_]([a-zA-Z0-9\_])*	{ yylval.id = strdup(yytext); return ID; }

"-"?[0-9]+		            { yylval.number.value = atof(yytext); yylval.number.type = TYPE_INT; return NUMBER; }
"-"?[0-9]+(\.[0-9]+)?		{ yylval.number.value = atof(yytext); yylval.number.type = TYPE_FLOAT; return NUMBER; }
\'.\'					    { yylval.number.value = (double)yytext[1]; yylval.number.type = TYPE_CHAR; return NUMBER; }

\".*\"				        { yylval.id = strdup(yytext); return STRING; }

"="						    { return RECEIVE; }

"=="						{ return EQUAL; }
"!="						{ return NEQUAL; }
"<"							{ return LESS; }
">"							{ return GREAT; }
"<="                        { return LEQUAL; }
">="                        { return GEQUAL; }

"&&"						{ return AND; }
"||"						{ return OR; }
"!"						    { return NOT; }

"//".*                      {}

"+"							{ return PLUS; }
"-"							{ return MIN; }
"*"							{ return MULT; }
"/"							{ return DIV; }

"("							{ return LEFTPAR; }
")"							{ return RIGHTPAR; }
";"							{ return DONE; }

"{"							{ return LEFTKEYS; }
"}"							{ return RIGHTKEYS; }

[\t\f\n ]					{}

.							{ fprintf(stderr, "Error: invalid character on line %d: '%s'\n", yylineno, yytext); }

%%