%{

#include <llvm-c/Core.h>
#include <llvm-c/Analysis.h>
#include <llvm-c/Target.h>
#include <llvm-c/ExecutionEngine.h>
#include <stdio.h>
#include <string.h>
#include "VarType.h"
#include "parser.tab.h"

%}

%option noyywrap
%option yylineno

%%

[iI][fF]					{ return IF; }
[eE][lL][sS][eE][iI][fF]    { return ELSEIF; }
[eE][lL][sS][eE]			{ return ELSE; }

[iI][nN][tT]				{ return INT; }
[cC][hH][aA][rR]			{ return CHAR; }
[fF][lL][oO][aA][tT]        { return FLOAT; }
[bB][oO][oO][lL]            { return BOOL; }

[Pp][rR][iI][nN][tT][fF]	{ return PRINTF; }
[Ss][cC][aA][nN][fF]	    { return SCANF; }

[wW][hH][iI][lL][eE]	    { return WHILE; }
[fF][oO][rR]	            { return FOR; }

[tT][rR][uU][eE]			{ yylval.number.value = 1; yylval.number.type = TYPE_BOOL; return NUMBER; }
[fF][aA][lL][sS][eE]		{ yylval.number.value = 0; yylval.number.type = TYPE_BOOL; return NUMBER; }

"-"?[0-9]+		            { yylval.number.value = atof(yytext); yylval.number.type = TYPE_INT; return NUMBER; }

"-"?[0-9]+(\.[0-9]+)?		{ yylval.number.value = atof(yytext); yylval.number.type = TYPE_FLOAT; return NUMBER; }

[a-zA-Z\_]([a-zA-Z0-9\_])*	{ yylval.id = strdup(yytext); return ID; }

\".*\"				        { yylval.id = strdup(yytext); return STRING; }

\'.\'					    { yylval.caractere = yytext[1]; return CARACTERE; }


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
"/*"(.|\n)*"*/"             {}

"+"							{ return PLUS; }
"-"							{ return MIN; }
"*"							{ return MULT; }
"/"							{ return DIV; }

"("							{ return LEFTPAR; }
")"							{ return RIGHTPAR; }

"{"							{ return LEFTKEYS; }
"}"							{ return RIGHTKEYS; }

"["							{ return LEFTBRACKET; }
"]"							{ return RIGHTBRACKET; }

","							{ return COMMA; }

";"							{ return DONE; }

[\t\f\n ]					{}

.							{ fprintf(stderr, "Error: invalid character on line %d: '%s'\n", yylineno, yytext); }

%%