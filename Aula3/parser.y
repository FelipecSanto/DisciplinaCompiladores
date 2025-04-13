%{
int yylex();
extern int yylineno;
%}

%{

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Stack {
        double* elements;
        int top;
        int size;
} Stack;

int isFull(Stack* s) {
        if (s->top == s->size - 1)
                return 1;
        return 0;
}

int isEmpty(Stack* s) {
        if (s->top == -1)
                return 1;
        return 0;
}

void initializeStack(Stack* s, int size) {
        s->top = -1;
        s->size = size;
        s->elements = (double*) malloc(size * sizeof(double));
        if (s->elements == NULL) {
                printf("ERROR::initializeStack::Failed to allocate memory!\n");
                exit(1);
        }
}

void push(Stack* s, double value) {
        if (isFull(s)) {
                printf("ERROR::push::Stack is full!\n");
                exit(1);
        }
        s->top++;
        s->elements[s->top] = value;
}

double pop(Stack* s) {
        if (isEmpty(s)) {
                printf("ERROR::pop::Stack is empty!\n");
                exit(1);
        }
        double value = s->elements[s->top];
        s->top--;
        return value;
}

double peek(Stack* s) {
        if (isEmpty(s)) {
                printf("ERROR::peek::Stack is empty!\n");
                exit(1);
        }
        return s->elements[s->top];
}

int stackSize(Stack* s) {
        return s->top + 1;
}

void destroyStack(Stack* s) {
        free(s->elements);
}

Stack stack;

int yywrap( );
void yyerror(const char* str);

/* the result variable */
double symb[26];
int hasError = 0;

%}

/* declare type possibilities of symbols */
%union {
  double value;
  int valueInt;
}

/* declare tokens (default is typeless) */
%token <value> NUM
%token PLUS
%token MIN
%token DIV
%token MULT
%token DONE
%token CLEAR
%token <valueInt> VARIABLE
%token EQUAL

/* declare precedence and associativity of operators */
%left PLUS MIN
%left MULT DIV

/* declare non-terminals */
%type <value> line expr program

/* give us more detailed errors */
%define parse.error verbose

%%

program: /* empty */ {}
    | error DONE program { yyerrok; yyclearin; }
    | line program {}
    | DONE program {}
    ;

line: VARIABLE EQUAL expr DONE { 
    if (!hasError) {
        symb[$1] = $3;
        if(isFull(&stack)) {
            int size = stackSize(&stack);
            destroyStack(&stack);
            initializeStack(&stack, size);
            push(&stack, $3);
        }
        else {
            push(&stack, $3);
        }
    } else {
        hasError = 0;
    } 
    }
    | VARIABLE EQUAL expr error { yyerrok; yyclearin; }
    | VARIABLE EQUAL error DONE { yyerrok; yyclearin; }
    | VARIABLE error expr DONE { yyerrok; yyclearin; }
    | error EQUAL expr DONE { yyerrok; yyclearin; }
    | CLEAR DONE {
        for (int i = 0; i < 26; i++) {
            symb[i] = 0;
        }
        printf("All variables cleared.\n");
    }
;

expr: NUM { $$ = $1; }
    | VARIABLE { $$ = symb[$1]; }
    | expr expr PLUS { $$ = $1 + $2; }
    | expr expr MIN { $$ = $1 - $2; }
    | expr expr MULT { $$ = $1 * $2; }
    | expr expr DIV { 
        if ($2 == 0) {
            fprintf(stderr, "Error: division by zero at line %d.\n", yylineno);
            hasError = 1;
            $$ = 0;
        } else {
            $$ = $1 / $2;
        }
    }

%%

int yywrap( ) {
  return 1;
}

void yyerror(const char* str) {
    if (strstr(str, "syntax error, unexpected DONE") != NULL)
        fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno - 1, str);
    else
        fprintf(stderr, "Compilation error at line %d: '%s'.\n", yylineno, str);    
    hasError = 1;
}

int main( ) {
    int tamanho = 100;
    initializeStack(&stack, tamanho);
    yyparse( );
    printf("\nFinal result: %lf\n\n", pop(&stack));
    destroyStack(&stack);
    return 0;
}