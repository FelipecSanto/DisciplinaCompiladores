%{
/*
 * tiny.l
 * Autor: Clayton Kossoski
 * Mestrando CPGEI - UTFPR - Campus Curitiba
 */

#include <stdio.h>
#include <string.h>
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

[a-zA-Z\_]([a-zA-Z0-9\_])*	{ yylval.id = strdup(yytext); return ID; }
"-"?[0-9]+(.[0-9]+)?		{ yylval.number = atof(yytext); return NUMBER; }

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
"/*".*"*/"                  {}

"+"							{ return PLUS; }
"-"							{ return MIN; }
"*"							{ return MULT; }
"/"							{ return DIV; }

"("							{ return LEFTPAR; }
")"							{ return RIGHTPAR; }
";"							{ return DONE; }

"{"							{ return LEFTKEYS; }
"}"							{ return RIGHTKEYS; }

"\n"						{ return JUMP; }

[\t\f ]					    {}

.							{ fprintf(stderr, "Error: invalid character on line %d: '%s'\n", yylineno, yytext); exit(1); }

%%