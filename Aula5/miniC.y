%{
#include "VarType.h"
int yylex();
extern int yylineno;
%}

%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define HASH_SIZE 100

typedef struct Symbol {
    char* id;
    double value;
    VarType type;
    struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
    Symbol* table[HASH_SIZE];
    struct SymbolTable* prev; // points to the previous scope
} SymbolTable;

SymbolTable* currentScope = NULL;

unsigned int hash(const char* id) {
    unsigned int h = 0;
    for (; *id; id++) {
        h = (h << 4) + *id;
    }
    return h % HASH_SIZE;
}

Symbol* findSymbol(const char* id) {
    SymbolTable* scope = currentScope;
    while (scope != NULL) {
        Symbol* sym = scope->table[hash(id)];
        while (sym != NULL) {
            if (strcmp(sym->id, id) == 0) return sym;
            sym = sym->next;
        }
        scope = scope->prev;
    }
    return NULL;
}

void insertSymbol(const char* id, double value, VarType type) {
    unsigned int index = hash(id);
    Symbol* sym = findSymbol(id);
    if (sym != NULL) {
        sym->value = value;
        sym->type = type;
    } else {
        sym = malloc(sizeof(Symbol));
        sym->id = strdup(id);
        sym->value = value;
        sym->type = type;
        sym->next = currentScope->table[index];
        currentScope->table[index] = sym;
    }
}

void pushScope() {
    SymbolTable* newScope = malloc(sizeof(SymbolTable));
    for (int i = 0; i < HASH_SIZE; i++) {
        newScope->table[i] = NULL;
    }
    newScope->prev = currentScope;
    currentScope = newScope;
}

void popScope() {
    if (currentScope == NULL) exit(1);
    for (int i = 0; i < HASH_SIZE; i++) {
        Symbol* sym = currentScope->table[i];
        while (sym != NULL) {
            Symbol* temp = sym;
            sym = sym->next;
            free(temp->id);
            free(temp);
        }
    }
    SymbolTable* tempScope = currentScope;
    currentScope = currentScope->prev;
    free(tempScope);
}

void freeSymbolTable(SymbolTable* table) {
    while (table != NULL) {
        for (int i = 0; i < HASH_SIZE; i++) {
            Symbol* sym = table->table[i];
            while (sym != NULL) {
                Symbol* temp = sym;
                sym = sym->next;
                free(temp->id);
                free(temp);
            }
        }
        SymbolTable* temp = table;
        table = table->prev;
        free(temp);
    }
}

int yywrap( );
void yyerror(const char* str);

int if_condition = 1;
int if_else_condition = 0;

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

/* declare precedence and associativity of operators */
%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

/* declare non-terminals */
%type <number> expression soma_sub mult_div term comparison log_exp
%type program declaration comand assignment if else write


/* give us more detailed errors */
%define parse.error verbose

%%


program: /* empty */ {}
       | comand program {}
       | declaration program {}
       | error program { yyerrok; yyclearin; }
       ;



declaration: INT ID DONE {
                if(if_condition == 1) {
                    insertSymbol($2, 0.0, TYPE_INT);
                }
           }
           | FLOAT ID DONE { 
                if(if_condition == 1) {
                    insertSymbol($2, 0.0, TYPE_FLOAT);
                }
           }
           | CHAR ID DONE { 
                if(if_condition == 1) {
                    insertSymbol($2, 0.0, TYPE_CHAR);
                }
           }
           | BOOL ID DONE { 
                if(if_condition == 1) {
                    insertSymbol($2, 0.0, TYPE_BOOL);
                }
           }
           ;




comand: assignment {}
      | if {}
      | write {}
      | read {}
      ;



assignment: ID RECEIVE expression DONE { 
                if(if_condition == 1) {
                    Symbol* symbol = findSymbol($1);
                    if (symbol != NULL) {
                        if (symbol->type == $3.type) {
                            insertSymbol($1, $3.value, symbol->type);
                        } else if(symbol->type == TYPE_INT && $3.type == TYPE_FLOAT) {
                            int value = (int)$3.value;
                            insertSymbol($1, (double)value, symbol->type);
                        } else if (symbol->type == TYPE_FLOAT && $3.type == TYPE_INT) {
                            insertSymbol($1, $3.value, symbol->type);
                        } else {
                            fprintf(stderr, "Error: type mismatch in assignment at line %d.\n", yylineno);
                        }
                    } else {
                        fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
                    }
                }
		  }
	      ;




if: IF LEFTPAR expression RIGHTPAR {
        pushScope();
        if ($3.type == TYPE_BOOL) {
            if_condition = $3.value;
            if_else_condition = $3.value;
        } else {
            fprintf(stderr, "Error: condition is not boolean at line %d.\n", yylineno);
            if_condition = 0;
        }
    } LEFTKEYS program RIGHTKEYS {
        if (if_condition == 0) {
            popScope();
            if_condition = 1;
        }
    } else {}
    ;

else: /* empty */ {}
    | ELSE LEFTKEYS {
        pushScope();
        if (if_else_condition == 1) {
            if_condition = 0;
        } 
    } program RIGHTKEYS {
        if (if_condition == 0) {
            if_condition = 1;
        }

        if(if_else_condition == 1) {
            popScope();
        }
    }
    ;




write: WRITE LEFTPAR ID RIGHTPAR DONE {
        if (if_condition == 1) {
            Symbol* sym = findSymbol($3);
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            }
            if (sym->type == TYPE_INT) {
                printf("%s = %d (Type == INT)\n", $3, (int)sym->value);
            } else if (sym->type == TYPE_BOOL) {
                printf("%s = %d (Type == BOOL)\n", $3, (int)sym->value);
            } else if (sym->type == TYPE_FLOAT) {
                printf("%s = %.2lf (Type == FLOAT)\n", $3, sym->value);
            } else if (sym->type == TYPE_CHAR) {
                printf("%s = %c (Type == CHAR)\n", $3, (char)sym->value);
            } else {
                fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3, yylineno);
                
            }
        }
     }
     | WRITE LEFTPAR NUMBER RIGHTPAR DONE {
        if (if_condition == 1) {
            if ($3.type == TYPE_INT) {
                printf("%d (Type == INT)\n", (int)$3.value);
            } else if ($3.type == TYPE_FLOAT) {
                printf("%lf (Type == FLOAT)\n", $3.value);
            } else if ($3.type == TYPE_CHAR) {
                printf("%c (Type == CHAR)\n", (char)$3.value);
            } else {
                fprintf(stderr, "Error: unsupported type for number at line %d.\n", yylineno);
            }
        }
     }
     | WRITE LEFTPAR STRING RIGHTPAR DONE { 
        if (if_condition == 1) {
            printf("%s\n", $3);
        }
        free($3); // Free the string after printing
     }
     ;


read: READ LEFTPAR ID RIGHTPAR DONE {
        if (if_condition == 1) {
            Symbol* sym = findSymbol($3);
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            }
            printf("Enter value for variable '%s': ", $3);
            if (sym->type == TYPE_INT) {
                int value;
                scanf("%d", &value);
                insertSymbol(sym->id, value, TYPE_INT);
            } else if (sym->type == TYPE_FLOAT) {
                double value;
                scanf("%lf", &value);
                insertSymbol(sym->id, value, TYPE_FLOAT);
            } else if (sym->type == TYPE_CHAR) {
                char value;
                scanf(" %c", &value);
                insertSymbol(sym->id, value, TYPE_CHAR);
            } else if (sym->type == TYPE_BOOL) {
                double value;
                scanf("%lf", &value);
                insertSymbol(sym->id, value ? 1.0 : 0.0, TYPE_BOOL);
            } else {
                fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", sym->id, yylineno);
            }
        }
    }
    ;




expression: soma_sub { $$.value = $1.value; $$.type = $1.type; }
		  | mult_div { $$.value = $1.value; $$.type = $1.type; }
          | LEFTPAR expression RIGHTPAR { $$.value = $2.value; $$.type = $2.type; }
          | comparison { $$.value = $1.value; $$.type = $1.type; }
          | log_exp { $$.value = $1.value; $$.type = $1.type; }
		  | term { $$.value = $1.value; $$.type = $1.type; }
		  ;

soma_sub: expression PLUS expression { 
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value + $3.value;
                    $$.type = TYPE_INT;
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && $3.type == TYPE_FLOAT)
                        || ($1.type == TYPE_FLOAT && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    $$.value = $1.value + $3.value;
                    $$.type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for addition at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }   
        }
    	| expression MIN  expression { 
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value - $3.value;
                    $$.type = TYPE_INT;
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && $3.type == TYPE_FLOAT)
                        || ($1.type == TYPE_FLOAT && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    $$.value = $1.value - $3.value;
                    $$.type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for subtraction at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
        }
		;

mult_div: expression MULT expression { 
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value * $3.value;
                    $$.type = TYPE_INT;
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && $3.type == TYPE_FLOAT)
                        || ($1.type == TYPE_FLOAT && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    $$.value = $1.value * $3.value;
                    $$.type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for multiplication at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
        }
		| expression DIV  expression { 
                if ($3.value == 0.0) {
                        fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
                        $$.value = -1;
                        $$.type = TYPE_UNKNOWN;
                }
                if ($1.type == TYPE_INT && $3.type == TYPE_INT) {
                    $$.value = $1.value / $3.value;
                    $$.type = TYPE_INT;
                } else if ((($1.type == TYPE_FLOAT || $1.type == TYPE_INT) && $3.type == TYPE_FLOAT)
                        || ($1.type == TYPE_FLOAT && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT))) {
                    $$.value = $1.value / $3.value;
                    $$.type = TYPE_FLOAT;
                } else {
                    fprintf(stderr, "Error: incompatible types for division at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
		}
		;

comparison: expression LESS   expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT)) {
                    $$.value = $1.value < $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
          }
          | expression GREAT  expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT)) {
                    $$.value = $1.value > $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
          }
          | expression LEQUAL expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT)) {
                    $$.value = $1.value <= $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
          }
          | expression GEQUAL expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT)) {
                    $$.value = $1.value >= $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
          }
          | expression EQUAL  expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT || $1.type == TYPE_BOOL) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT || $3.type == TYPE_BOOL)) {
                    $$.value = $1.value == $3.value;
                    $$.type = TYPE_BOOL;
                }
                else if ($1.type == TYPE_CHAR && $3.type == TYPE_CHAR) {
                    $$.value = $1.value == $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
          }
          | expression NEQUAL expression { 
                if(($1.type == TYPE_INT || $1.type == TYPE_FLOAT || $1.type == TYPE_BOOL) && ($3.type == TYPE_INT || $3.type == TYPE_FLOAT || $3.type == TYPE_BOOL)) {
                    $$.value = $1.value != $3.value;
                    $$.type = TYPE_BOOL;
                }
                else if ($1.type == TYPE_CHAR && $3.type == TYPE_CHAR) {
                    $$.value = $1.value != $3.value;
                    $$.type = TYPE_BOOL;
                }
                else {
                    fprintf(stderr, "Error: comparison between incompatible types at line %d.\n", yylineno);
                    $$.value = -1;
                    $$.type = TYPE_UNKNOWN;
                }
           }
          ;

log_exp: expression AND expression { 
            if ($1.type == TYPE_BOOL && $3.type == TYPE_BOOL) {
                $$.value = $1.value && $3.value;
                $$.type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical AND between incompatible types at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
       }
       | expression OR  expression { 
            if ($1.type == TYPE_BOOL && $3.type == TYPE_BOOL) {
                $$.value = $1.value || $3.value;
                $$.type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical OR between incompatible types at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
       }
       | NOT expression { 
            if ($2.type == TYPE_BOOL) {
                $$.value = !$2.value;
                $$.type = TYPE_BOOL;
            } else {
                fprintf(stderr, "Error: logical NOT on incompatible type at line %d.\n", yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
            }
        }
       ;

term: NUMBER { $$.value = $1.value; $$.type = $1.type; }
    | ID { 
        Symbol* sym = findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
            $$.value = -1;
            $$.type = TYPE_UNKNOWN;
        } else {
            $$.value = sym->value;
            $$.type = sym->type;
        }
    }
	;


%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);
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
                const char* typeStr;
                if(sym->value >= INT_MAX - 10 || sym->value <= INT_MIN + 10) {
                    printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "UNKNOWN");
                }
                else {
                    switch (sym->type) {
                        case TYPE_INT: typeStr = "INT"; printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, typeStr); break;
                        case TYPE_BOOL: typeStr = "BOOL"; printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, typeStr); break;
                        case TYPE_FLOAT: typeStr = "FLOAT"; printf("| %-10s | %-10.2lf | %-10s |\n", sym->id, sym->value, typeStr); break;
                        case TYPE_CHAR: typeStr = "CHAR"; printf("| %-10s | %-10c | %-10s |\n", sym->id, (char)sym->value, typeStr); break;
                        default: typeStr = "UNKNOWN"; break;
                    }
                }
                sym = sym->next;
            }
        }
        table = table->prev;
    }
    printf("-------------------------------------------------\n\n");
}

int main( ) {
    pushScope(); // Initialize the first scope
    yyparse( );
    printSymbolTable(currentScope); // Print the symbol table
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}