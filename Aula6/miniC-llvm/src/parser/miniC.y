%{
#include "VarType.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Value.h>
#include <llvm/Support/raw_ostream.h>

extern int yylex();
extern int yylineno;
extern LLVMContext TheContext;
extern Module* TheModule;
extern IRBuilder<> Builder;

void generateCodeForExpression(double value, VarType type);
void generateCodeForAssignment(const char* id, double value, VarType type);
void generateCodeForPrint(const char* id);
%}

%union {
    struct {
        double value;
        VarType type;
    } number;
    char* id;
}

%token IF 
%token ELSE
%token INT CHAR FLOAT BOOL
%token READ
%token WRITE
%token WHILE
%token <id> ID 
%token <number> NUMBER
%token <id> STRING
%token RECEIVE
%token EQUAL
%token NEQUAL
%token LESS
%token GREAT
%token LEQUAL
%token GEQUAL
%token AND
%token OR
%token NOT
%token PLUS 
%token MIN
%token MULT
%token DIV
%token LEFTPAR 
%token RIGHTPAR
%token DONE
%token LEFTKEYS
%token RIGHTKEYS

%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

%type <number> expression soma_sub mult_div term comparison log_exp
%type program declaration comand assignment if else write while

%%


program: /* empty */ {}
       | comand program {}
       | declaration program {}
       | error program { yyerrok; yyclearin; }
       ;

declaration: INT ID DONE {
                insertSymbol($2, -DBL_MAX, TYPE_INT);
           }
           | FLOAT ID DONE { 
                insertSymbol($2, -DBL_MAX, TYPE_FLOAT);
           }
           | CHAR ID DONE { 
                insertSymbol($2, -DBL_MAX, TYPE_CHAR);
           }
           | BOOL ID DONE { 
                insertSymbol($2, -DBL_MAX, TYPE_BOOL);
           }
           ;

comand: assignment {}
      | if {}
      | write {}
      | read {}
      | while {}
      ;

assignment: ID RECEIVE expression DONE { 
                Symbol* symbol = findSymbol($1);
                if (symbol != NULL) {
                    if (symbol->type == $3.type) {
                        generateCodeForAssignment($1, $3.value, symbol->type);
                    } else {
                        fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                    }
                } else {
                    fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
                }
            }
	      ;

if: IF LEFTPAR expression RIGHTPAR {
        if ($3.type == TYPE_BOOL) {
            // Handle true condition
        } else {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
        }
    } LEFTKEYS program RIGHTKEYS {
        // Handle end of if block
    } else {}
    ;

else: /* empty */ {}
    | ELSE LEFTKEYS {
        // Handle else block
    } program RIGHTKEYS {
        // Handle end of else block
    }
    ;

write: WRITE LEFTPAR ID RIGHTPAR DONE {
        Symbol* sym = findSymbol($3);
        if (sym != NULL) {
            generateCodeForPrint($3);
        } else {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
        }
    }
    | WRITE LEFTPAR NUMBER RIGHTPAR DONE {
        // Handle writing a number
    }
    | WRITE LEFTPAR STRING RIGHTPAR DONE { 
        // Handle writing a string
    }
    ;

read: READ LEFTPAR ID RIGHTPAR DONE {
        Symbol* sym = findSymbol($3);
        if (sym != NULL) {
            // Handle reading into variable
        } else {
            fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
        }
    }
    ;

while: WHILE LEFTPAR expression RIGHTPAR LEFTKEYS program RIGHTKEYS {
        // Handle while loop
    }

expression: soma_sub { $$.value = $1.value; $$.type = $1.type; }
          | mult_div { $$.value = $1.value; $$.type = $1.type; }
          | LEFTPAR expression RIGHTPAR { $$.value = $2.value; $$.type = $2.type; }
          | comparison { $$.value = $1.value; $$.type = $1.type; }
          | log_exp { $$.value = $1.value; $$.type = $1.type; }
          | term { $$.value = $1.value; $$.type = $1.type; }
          ;

soma_sub: expression PLUS expression { 
                // Handle addition
            }
          | expression MIN expression { 
                // Handle subtraction
            }
          ;

mult_div: expression MULT expression { 
                // Handle multiplication
            }
          | expression DIV expression { 
                // Handle division
            }
          ;

comparison: expression LESS expression { 
                // Handle less than comparison
            }
          | expression GREAT expression { 
                // Handle greater than comparison
            }
          | expression LEQUAL expression { 
                // Handle less than or equal comparison
            }
          | expression GEQUAL expression { 
                // Handle greater than or equal comparison
            }
          | expression EQUAL expression { 
                // Handle equality comparison
            }
          | expression NEQUAL expression { 
                // Handle inequality comparison
            }
          ;

log_exp: expression AND expression { 
            // Handle logical AND
        }
       | expression OR expression { 
            // Handle logical OR
        }
       | NOT expression { 
            // Handle logical NOT
        }
       ;

term: NUMBER { $$.value = $1.value; $$.type = $1.type; }
    | ID { 
        Symbol* sym = findSymbol($1);
        if (sym) {
            $$.value = sym->value;
            $$.type = sym->type;
        } else {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
        }
    }
    ;

%% 

int yywrap() {
    return 1;
}

void yyerror(const char* str) {
    fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);
}