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

#define HASH_SIZE 211

typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_BOOL } VarType;

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
    if (currentScope == NULL) return;
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

SymbolTable* currentScope = NULL;

%}

%union {
    double number;
    char* id;
    struct {
        char* id
        double value;
        VarType type;
    } expr;
}


%token IF 
%token ELSE
%token INT CHAR FLOAT BOOL
%token READ
%token WRITE
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
%type <expr> expression soma_sub mult_div term
%type <number> comparison log_exp
%type program declarations declaration comands comand assignment if else write jump


/* give us more detailed errors */
%define parse.error verbose

%%


program: /* empty */ {}
       | declarations comands program {}
       | error comands program { yyerrok; yyclearin; }
       | declarations error program { yyerrok; yyclearin; }
       | error program { yyerrok; yyclearin; }
       | JUMP program {}



declarations: /* empty */ {}
            | declaration {}
            | declaration declarations {}
            | error declarations { yyerrok; yyclearin; }
            | declaration error { yyerrok; yyclearin; }

declaration: INT ID DONE { 
                insertSymbol($2, 0.0, TYPE_INT);
           }
           | FLOAT ID DONE { 
                insertSymbol($2, 0.0, TYPE_FLOAT);
           }
           | CHAR ID DONE { 
                 insertSymbol($2, 0.0, TYPE_CHAR);
           }
           | BOOL ID DONE { 
                 insertSymbol($2, 0.0, TYPE_BOOL);
           }
           | error DONE { yyerrok; yyclearin; }
           ;



comands: /* empty */ {}
       | comand {}
       | comand comands {}
       | error comands { yyerrok; yyclearin; }
       | comand error { yyerrok; yyclearin; }
       ;

comand: assignments {}
      | if {}
      | write {}
      | read {}
      ;



assignments: /* empty */ {} 
           | assignment {}
           | assignment assignments {}
           | error assignments { yyerrok; yyclearin; }
           | assignment error { yyerrok; yyclearin; }
           ;

assignment: ID RECEIVE expression DONE { 
                Symbol* symbol = findSymbol($1);
                if (symbol != NULL) {
                    symbol->value = $3.value;
                    symbol->type = $3.type;
                } else {
                    fprintf(stderr, "Error: undefined variable '%s' at line %d.\n", $1, yylineno);
                }
		  }
		  | ID RECEIVE error DONE { yyerrok; yyclearin; }
	      ;



if: IF LEFTPAR expression RIGHTPAR {
        pushScope();
    } jump LEFTKEYS program RIGHTKEYS {
        popScope();
    } else {}
    | IF LEFTPAR error RIGHTPAR jump LEFTKEYS program RIGHTKEYS else { yyerrok; yyclearin; }
    | IF LEFTPAR expression RIGHTPAR jump LEFTKEYS error RIGHTKEYS else { yyerrok; yyclearin; }
    | IF LEFTPAR expression RIGHTPAR jump LEFTKEYS program RIGHTKEYS error { yyerrok; yyclearin; }
    ;

else: /* empty */ {}
    | ELSE jump LEFTKEYS { 
        pushScope();
    } program RIGHTKEYS {
        popScope();
    }
    ;



write: WRITE LEFTPAR expression RIGHTPAR DONE { 
        /* Print the value of the expression */
     }
     | WRITE LEFTPAR error RIGHTPAR DONE { yyerrok; yyclearin; }
     ;


read: READ LEFTPAR expression RIGHTPAR DONE { 
        printf("Enter value for %lf: ", $3);
        if ($3.type == TYPE_INT) {
            int value;
            scanf("%d", &value);
            insertSymbol($3.id, value, TYPE_INT);
        } else if ($3.type == TYPE_FLOAT) {
            double value;
            scanf("%lf", &value);
            insertSymbol($3.id, value, TYPE_FLOAT);
        } else if ($3.type == TYPE_CHAR) {
            char value;
            scanf(" %c", &value);
            insertSymbol($3.id, value, TYPE_CHAR);
        } else if ($3.type == TYPE_BOOL) {
            double value;
            scanf("%lf", &value);
            insertSymbol($3.id, value ? 1.0 : 0.0, TYPE_BOOL);
        } else {
            fprintf(stderr, "Error: unsupported type for variable '%s' at line %d.\n", $3.id, yylineno);
        }
        insertSymbol($3, value, $3.type);
    }
    | READ LEFTPAR error RIGHTPAR DONE { yyerrok; yyclearin; }
    ;



expression: soma_sub { $$ = $1; }
		  | mult_div { $$ = $1; }
          | LEFTPAR expression RIGHTPAR { $$ = $2; }
          | comparison { $$ = $1; }
          | log_exp { $$ = $1; }
		  | term { $$ = $1; }
		  ;

soma_sub: expression PLUS expression { $$ = $1 + $3; }
    	| expression MIN  expression { $$ = $1 - $3; }
		;

mult_div: expression MULT expression { $$ = $1 * $3; }
		| expression DIV  expression { 
			if ($3 == 0) {
				fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
				$$ = -1;
			} else {
				$$ = $1 / $3;
			}
		}
		;

comparison: expression LESS   expression { $$ = $1 < $3;  }
          | expression GREAT  expression { $$ = $1 > $3;  }
          | expression LEQUAL expression { $$ = $1 <= $3; }
          | expression GEQUAL expression { $$ = $1 >= $3; }
          | expression EQUAL  expression { $$ = $1 == $3; }
          | expression NEQUAL expression { $$ = $1 != $3; }
          ;

log_exp: expression AND expression { $$ = $1 && $3; }
       | expression OR  expression { $$ = $1 || $3; }
       | NOT expression { $$ = !$2; }
       ;

term: NUMBER { $$.id = ""; $$.value = $1; $$.type = TYPE_FLOAT; }
    | ID { 
        Symbol* sym = findSymbol($1);
        if (!sym) {
            fprintf(stderr, "Undeclared variable '%s' at line %d\n", $1, yylineno);
            $$.value = -1;
        } else {
            $$.id = sym->id;
            $$.value = sym->value;
            $$.type = sym->type;
        }
    }
	;

jump : /* empty */ {}
     | JUMP jump {}
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
                switch (sym->type) {
                    case TYPE_INT: typeStr = "INT"; break;
                    case TYPE_FLOAT: typeStr = "FLOAT"; break;
                    case TYPE_CHAR: typeStr = "CHAR"; break;
                    case TYPE_BOOL: typeStr = "BOOL"; break;
                    default: typeStr = "UNKNOWN"; break;
                }
                printf("| %-10s | %-10.2lf | %-10s |\n", sym->id, sym->value, typeStr);
                sym = sym->next;
            }
        }
        table = table->prev;
    }
    printf("-------------------------------------------------\n\n");
}

int main( ) {
    pushScope(); // Initialize the first scope
    symb
    yyparse( );
    
    return 0;
}
