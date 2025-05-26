%{
#include "VarType.h"
int yylex();
extern int yylineno;
%}

%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <signal.h>
#include <unistd.h>

#define MAX_TAC 1000

typedef struct TAC {
    char* op;       // Operação (e.g., "IF", "GOTO", "+", "-", etc.)
    char* arg1;     // Primeiro argumento
    char* arg2;     // Segundo argumento (se aplicável)
    char* result;   // Resultado ou label
} TAC;

TAC tacBuffer[MAX_TAC];
int tacIndex = 0;
int labelCount = 0; // Para gerar labels únicos
char label[10];
char label0[10];

void addTAC(const char* op, const char* arg1, const char* arg2, const char* result) {
    if (tacIndex >= MAX_TAC) {
        fprintf(stderr, "Error: TAC buffer overflow.\n");
        exit(1);
    }
    tacBuffer[tacIndex].op = op ? strdup(op) : NULL;
    tacBuffer[tacIndex].arg1 = arg1 ? strdup(arg1) : NULL;
    tacBuffer[tacIndex].arg2 = arg2 ? strdup(arg2) : NULL;
    tacBuffer[tacIndex].result = result ? strdup(result) : NULL;
    tacIndex++;
}

void printTAC() {
    printf("\nThree-Address Code:\n");
    for (int i = 0; i < tacIndex; i++) {
        if (tacBuffer[i].op &&
            strcmp(tacBuffer[i].op, "+") != 0 &&
            strcmp(tacBuffer[i].op, "-") != 0 &&
            strcmp(tacBuffer[i].op, "*") != 0 &&
            strcmp(tacBuffer[i].op, "/") != 0 &&
            strcmp(tacBuffer[i].op, ">") != 0 &&
            strcmp(tacBuffer[i].op, "<") != 0 &&
            strcmp(tacBuffer[i].op, ">=") != 0 &&
            strcmp(tacBuffer[i].op, "<=") != 0 &&
            strcmp(tacBuffer[i].op, "==") != 0 &&
            strcmp(tacBuffer[i].op, "!=") != 0 &&
            strcmp(tacBuffer[i].op, "&&") != 0 &&
            strcmp(tacBuffer[i].op, "||") != 0 &&
            strcmp(tacBuffer[i].op, "!") != 0 &&
            strcmp(tacBuffer[i].op, "(int)") != 0 &&
            strcmp(tacBuffer[i].op, "(float)") != 0 &&
            strcmp(tacBuffer[i].op, "(char)") != 0 &&
            strcmp(tacBuffer[i].op, "(bool)") != 0){
            
            if(strcmp(tacBuffer[i].arg1, ":") != 0) {
                printf("\t%s %s %s %s\n",
                    tacBuffer[i].op,
                    tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "",
                    tacBuffer[i].arg2 ? tacBuffer[i].arg2 : "",
                    tacBuffer[i].result ? tacBuffer[i].result : "");
            } else {
                printf("%s%s",
                    tacBuffer[i].op,
                    tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "");
            }
        } else {
            printf("\t%s = %s %s %s\n",
                tacBuffer[i].result ? tacBuffer[i].result : "",
                tacBuffer[i].arg1 ? tacBuffer[i].arg1 : "",
                tacBuffer[i].op ? tacBuffer[i].op : "",
                tacBuffer[i].arg2 ? tacBuffer[i].arg2 : "");
        }
    }
    printf("\n");
}

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
    Symbol* sym = findSymbol(id);
    if (sym != NULL) {
        sym->value = value;
        sym->type = type;
    } else {
        unsigned int index = hash(id);
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
        char* result;
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

/* declare precedence and associativity of operators */
%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

/* declare non-terminals */
%type <number> expression soma_sub mult_div term comparison log_exp cast
%type program declaration comand assignment if else write while


/* give us more detailed errors */
%define parse.error verbose

%%


program: /* empty */ {}
       | comand program {}
       | declaration program {}
       | error program { yyerrok; yyclearin; }
       ;



declaration: INT ID DONE {
                addTAC("declare", "int", $2, NULL);
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_INT);
                }
           }
           | FLOAT ID DONE {
                addTAC("declare", "float", $2, NULL);
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_FLOAT);
                }
           }
           | CHAR ID DONE {
                addTAC("declare", "char", $2, NULL);
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_CHAR);
                }
           }
           | BOOL ID DONE {
                addTAC("declare", "bool", $2, NULL);
                if(if_condition == 1) {
                    insertSymbol($2, -DBL_MAX, TYPE_BOOL);
                }
           }
           ;




comand: assignment {}
      | if {}
      | write {}
      | read {}
      | while {}
      ;



assignment: ID RECEIVE expression DONE {
                addTAC(NULL, $3.result, NULL, $1);
                if(if_condition == 1) {
                    Symbol* symbol = findSymbol($1);
                    if (symbol != NULL) {
                        if (symbol->type == $3.type) {
                            insertSymbol($1, $3.value, symbol->type);
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

        char labelTrue[10], labelFalse[10];
        sprintf(labelTrue, "L%d", labelCount++);
        sprintf(labelFalse, "L%d", labelCount++);

        // Gera TAC para a condição
        addTAC("if", $3.result, "goto", labelTrue);
        addTAC("goto", labelFalse, NULL, NULL);

        // Label para o bloco "if"
        addTAC(labelTrue, ":", NULL, NULL);

        strcpy(label, labelFalse);
    } LEFTKEYS program RIGHTKEYS {
        if (if_condition == 0) {
            popScope();
            if_condition = 1;
        }
    } else {}
    ;

else: /* empty */ {}
    | ELSE {
        pushScope();
        if (if_else_condition == 1) {
            if_condition = 0;
        } 

        char labelEnd[10];
        sprintf(labelEnd, "L%d", labelCount++);
        addTAC("goto", labelEnd, NULL, NULL);

        // Label para o bloco "else" ou saída
        addTAC(label, ":", NULL, NULL);

        strcpy(label, labelEnd);
    } LEFTKEYS program RIGHTKEYS {
        // Gera TAC para o bloco "else"
        addTAC(label, ":", NULL, NULL);

        if (if_condition == 0) {
            if_condition = 1;
        }

        if(if_else_condition == 1) {
            popScope();
        }
    }
    ;




write: WRITE LEFTPAR ID RIGHTPAR DONE {
        addTAC("write", $3, NULL, NULL);
        if (if_condition == 1) {
            Symbol* sym = findSymbol($3);
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            }
            else if(sym->value == -DBL_MAX) {
                fprintf(stderr, "Error: variable '%s' is uninitialized at line %d.\n", $3, yylineno);
            }
            else {
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
     }
     | WRITE LEFTPAR NUMBER RIGHTPAR DONE {
        char temp[16];
        sprintf(temp, "%lf", $3.value);
        addTAC("write", temp, NULL, NULL);
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
        addTAC("write", $3, NULL, NULL);
        if (if_condition == 1) {
            printf("%s\n", $3);
        }
        free($3); // Free the string after printing
     }
     ;


read: READ LEFTPAR ID RIGHTPAR DONE {
        addTAC("read", $3, NULL, NULL);
        if (if_condition == 1) {
            Symbol* sym = findSymbol($3);
            if (sym == NULL) {
                fprintf(stderr, "Error: variable '%s' not declared at line %d.\n", $3, yylineno);
            }
            else {
                FILE* input = fopen("/dev/tty", "r");
                if (input == NULL) {
                    fprintf(stderr, "Error: unable to read from keyboard.\n");
                    exit(1);
                }
                switch (sym->type) {
                        case TYPE_INT: printf("Enter value for variable '%s with Type == INT': ", $3); break;
                        case TYPE_BOOL: printf("Enter value for variable '%s with Type == BOOL': ", $3); break;
                        case TYPE_FLOAT: printf("Enter value for variable '%s with Type == FLOAT': ", $3); break;
                        case TYPE_CHAR: printf("Enter value for variable '%s with Type == CHAR': ", $3); break;
                        default: break;
                }
                if (sym->type == TYPE_INT) {
                    int value = 0;
                    fscanf(input, "%d", &value);
                    insertSymbol(sym->id, (double)value, TYPE_INT);
                } else if (sym->type == TYPE_FLOAT) {
                    double value = 0.0;
                    fscanf(input, "%lf", &value);
                    insertSymbol(sym->id, value, TYPE_FLOAT);
                } else if (sym->type == TYPE_CHAR) {
                    char value = 'a';
                    fscanf(input, " %c", &value);
                    insertSymbol(sym->id, value, TYPE_CHAR);
                } else if (sym->type == TYPE_BOOL) {
                    double value = 0.0;
                    fscanf(input, "%lf", &value);
                    insertSymbol(sym->id, value ? 1.0 : 0.0, TYPE_BOOL);
                } else {
                    fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", sym->id, yylineno);
                }
                fclose(input);
            }
        }
    }
    ;



while: WHILE LEFTPAR expression RIGHTPAR {
            char labelStart[10], labelLoop[10], labelEnd[10];
            sprintf(labelStart, "L%d", labelCount++);
            sprintf(labelLoop, "L%d", labelCount++);
            sprintf(labelEnd, "L%d", labelCount++);

            // Label para o início do loop
            addTAC(labelStart, ":", NULL, NULL);

            // Gera TAC para a condição
            addTAC("if", $3.result, "goto", labelLoop);
            addTAC("goto", labelEnd, NULL, NULL);

            // Label para o fim do loop
            addTAC(labelLoop, ":", NULL, NULL);

            strcpy(label, labelEnd);
            strcpy(label0, labelStart);
     } LEFTKEYS program RIGHTKEYS {
            // Gera TAC para voltar ao início do loop
            addTAC("goto", label0, NULL, NULL);

            // Label para o fim do loop
            addTAC(label, ":", NULL, NULL);
     }
     ;



expression: soma_sub { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
		  | mult_div { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
          | LEFTPAR expression RIGHTPAR { $$.value = $2.value; $$.type = $2.type; $$.result = $2.result; }
          | comparison { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
          | log_exp { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
          | cast { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
		  | term { $$.value = $1.value; $$.type = $1.type; $$.result = $1.result; }
		  ;

soma_sub: expression PLUS expression { 
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("+", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("-", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("*", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("/", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("<", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC(">", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("<=", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC(">=", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("==", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
                char temp[16];
                sprintf(temp, "t%d", tacIndex);
                addTAC("!=", $1.result, $3.result, temp);
                $$.result = strdup(temp);
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
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("&&", $1.result, $3.result, temp);
            $$.result = strdup(temp);
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
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("||", $1.result, $3.result, temp);
            $$.result = strdup(temp);
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
            char temp[16];
            sprintf(temp, "t%d", tacIndex);
            addTAC("!", NULL, $2.result, temp);
            $$.result = strdup(temp);
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

cast: LEFTPAR INT RIGHTPAR LEFTPAR expression RIGHTPAR {
        int temp = (int) $5.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(int)", NULL, $5.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR INT RIGHTPAR term {
        int temp = (int) $4.value;
        $$.value = (double) temp;
        $$.type = TYPE_INT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(int)", NULL, $4.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR FLOAT RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = $5.value;
        $$.type = TYPE_FLOAT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(float)", NULL, $5.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR FLOAT RIGHTPAR term {
        $$.value = $4.value;
        $$.type = TYPE_FLOAT;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(float)", NULL, $4.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR CHAR RIGHTPAR LEFTPAR expression RIGHTPAR {
        $$.value = (double) ((char) $5.value);
        $$.type = TYPE_CHAR;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(char)", NULL, $5.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR CHAR RIGHTPAR term {
        $$.value = (double) ((char) $4.value);
        $$.type = TYPE_CHAR;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(char)", NULL, $4.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR BOOL RIGHTPAR LEFTPAR expression RIGHTPAR {
        if($5.value != 0.0) {
            $$.value = 1.0;
        } else {
            $$.value = 0.0;
        }
        $$.type = TYPE_BOOL;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(bool)", NULL, $5.result, tempStr);
        $$.result = strdup(tempStr);
    }
    | LEFTPAR BOOL RIGHTPAR term {
        if($4.value != 0.0) {
            $$.value = 1.0;
        } else {
            $$.value = 0.0;
        }
        $$.type = TYPE_BOOL;
        char tempStr[16];
        sprintf(tempStr, "t%d", tacIndex);
        addTAC("(bool)", NULL, $4.result, tempStr);
        $$.result = strdup(tempStr);
    }
    ;

term: NUMBER { 
        $$.value = $1.value; 
        $$.type = $1.type; 
        char temp[16];
        sprintf(temp, "%g", $1.value);
        $$.result = strdup(temp);
    }
    | ID { 
        Symbol* sym = findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
            $$.value = -1;
            $$.type = TYPE_UNKNOWN;
            $$.result = "";
        } else {
            if (sym->value == -DBL_MAX) {
                fprintf(stderr, "Uninitialized variable '%s' at line %d\n", $1, yylineno);
                $$.value = -1;
                $$.type = TYPE_UNKNOWN;
                $$.result = NULL;
            } else {
                $$.value = sym->value;
                $$.type = sym->type;
                $$.result = strdup(sym->id);
            }
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

void handleSegfault(int sig) {
    fprintf(stderr, "Segmentation fault (signal %d). Exiting gracefully.\n", sig);
    exit(1);
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
                if(sym->value >= INT_MAX - 10 || sym->value <= INT_MIN + 10) {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "CHAR"); break;
                        default: break;
                    }
                }
                else {
                    switch (sym->type) {
                        case TYPE_INT: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "INT"); break;
                        case TYPE_BOOL: printf("| %-10s | %-10d | %-10s |\n", sym->id, (int)sym->value, "BOOL"); break;
                        case TYPE_FLOAT: printf("| %-10s | %-10.2lf | %-10s |\n", sym->id, sym->value, "FLOAT"); break;
                        case TYPE_CHAR: printf("| %-10s | %-10c | %-10s |\n", sym->id, (char)sym->value, "CHAR"); break;
                        case TYPE_UNKNOWN: printf("| %-10s | %-10s | %-10s |\n", sym->id, "UNKNOWN", "UNKNOWN"); break;
                        default: break;
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
    signal(SIGSEGV, handleSegfault); // Handle segmentation faults
    pushScope(); // Initialize the first scope
    yyparse( );
    printTAC(); // Imprime o código de três endereços
    /* printSymbolTable(currentScope); // Print the symbol table */
    freeSymbolTable(currentScope); // Free the symbol table
    return 0;
}