%{
int yylex();
extern int yylineno;
%}

%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

// Estrutura de dados (lista) para a tabela de símbolos
typedef struct SymbolTable {
    char* id;
    double value;
    struct SymbolTable* next;
} SymbolTable;


SymbolTable* findSymbol(SymbolTable* table, const char* id) {
    while (table != NULL) {
        if (strcmp(table->id, id) == 0) {
            return table;
        }
        table = table->next;
    }
    return NULL;
}

void insertSymbol(SymbolTable** table, const char* id, double value) {
    SymbolTable* symbol = findSymbol(*table, id);
    if (symbol != NULL) {
        symbol->value = value;
    } else {
        SymbolTable* newSymbol = (SymbolTable*)malloc(sizeof(SymbolTable));
        newSymbol->id = strdup(id); // Allocates memory for the identifier
        newSymbol->value = value;
        newSymbol->next = *table;
        *table = newSymbol;
    }
}

SymbolTable* copySymbolTable(SymbolTable* source) {
    SymbolTable* newTable = NULL;
    SymbolTable* current = source;

    while (current != NULL) {
        insertSymbol(&newTable, current->id, current->value);
        current = current->next;
    }

    return newTable;
}

void freeSymbolTable(SymbolTable* table) {
    while (table != NULL) {
        SymbolTable* temp = table;
        table = table->next;
        free(temp->id);
        free(temp);
    }
}

int yywrap( );
void yyerror(const char* str);

SymbolTable* symb = NULL;
SymbolTable* aux_table = NULL;
int hasError = 0;
int ifElse = 0; // Flag to check if we are in an if-else block

%}

%union {
	double number;
    char* id;
}


%token IF 
%token ELSE 
%token <id> ID 
%token <number> NUMBER
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
%token JUMP

/* declare precedence and associativity of operators */
%left OR
%left AND
%nonassoc LESS GREAT LEQUAL GEQUAL EQUAL NEQUAL
%left PLUS MIN
%left MULT DIV
%right NOT

/* declare non-terminals */
%type <number> expression soma_sub mult_div term
%type <number> expr_log
%type program line assignment if jump else


/* give us more detailed errors */
%define parse.error verbose

%%

program: /* empty */ {}
     | error JUMP program { yyerrok; yyclearin; }
     | line program {}
     | JUMP program {}
    ;

line: assignment
	| if
	;

assignment: ID RECEIVE expression DONE { 
				if (!hasError) {
                    insertSymbol(&symb, $1, $3);
                } else {
                    hasError = 0;
                }
			}
            // To catch all errors
		  	| ID RECEIVE expression error { yyerrok; yyclearin; }
			| ID RECEIVE error DONE { yyerrok; yyclearin; }
			| ID error expression DONE { yyerrok; yyclearin; }
			| error RECEIVE expression DONE { yyerrok; yyclearin; }
			;

expression: soma_sub { $$ = $1; }
		  | mult_div { $$ = $1; }
          | LEFTPAR expression RIGHTPAR { $$ = $2; }
		  | term { $$ = $1; }
		  ;

soma_sub: expression PLUS expression { $$ = $1 + $3; }
    	| expression MIN  expression { $$ = $1 - $3; }
		;

mult_div: expression MULT expression { $$ = $1 * $3; }
		| expression DIV  expression { 
			if ($3 == 0) {
				fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
				hasError = 1;
				$$ = -1;
			} else {
				$$ = $1 / $3;
			}
		}
		;

term: NUMBER { $$ = $1; }
	| ID { 
		SymbolTable* symbol = findSymbol(symb, $1);
        if (symbol != NULL) {
            $$ = symbol->value;
        } else {
            fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
            hasError = 1;
            $$ = -1;
        }
	}
	;


if: IF LEFTPAR expr_log RIGHTPAR {
        ifElse = $3;
        if(!ifElse) {
            aux_table = copySymbolTable(symb);
        }
    } jump LEFTKEYS program RIGHTKEYS else {}
    ;

else: /* empty */ {}
    | ELSE jump LEFTKEYS { 
        if(ifElse) {
            aux_table = copySymbolTable(symb);
        }
        else {
            freeSymbolTable(symb);
            symb = copySymbolTable(aux_table);
            freeSymbolTable(aux_table);
            aux_table = NULL;
        }
    } program RIGHTKEYS {
        if(ifElse) {
            freeSymbolTable(symb);
            symb = copySymbolTable(aux_table);
            freeSymbolTable(aux_table);
            aux_table = NULL;
        }
    }
    ;

jump : /* empty */ {}
     | JUMP jump {}
     ;


expr_log: expression LESS   expression { $$ = $1 < $3;  }
        | expression GREAT  expression { $$ = $1 > $3;  }
        | expression LEQUAL expression { $$ = $1 <= $3; }
        | expression GEQUAL expression { $$ = $1 >= $3; }
        | expression EQUAL  expression { $$ = $1 == $3; }
        | expression NEQUAL expression { $$ = $1 != $3; }
        | expr_log AND expr_log { $$ = $1 && $3; }
        | expr_log OR  expr_log { $$ = $1 || $3; }
        |          NOT expr_log {    $$ = !$2;   }
        | expression { 
            if ($1 == 0.0) {
                $$ = 0.0;
            } else {
                $$ = 1.0;
            }
        }
		;

%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    if (strstr(str, "syntax error, unexpected JUMP") != NULL)
        fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno - 1, str);
    else
        fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);    
    hasError = 1;
}

void printSymbolTable(SymbolTable* table) {
    printf("\nSymbol Table:\n");
    printf("----------------------------\n");
    printf("| %-10s | %-10s |\n", "Identifier", "Value");
    printf("----------------------------\n");
    while (table != NULL) {
        printf("| %-10s | %-10.2lf |\n", table->id, table->value);
        table = table->next;
    }
    printf("----------------------------\n\n");
}

int main( ) {
    yyparse( );
    printSymbolTable(symb);
	freeSymbolTable(symb);
    return 0;
}
