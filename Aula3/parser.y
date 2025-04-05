%{
int yylex();
extern int yylineno;
%}

%{

  #include <stdio.h>
  #include <string.h>
  #include <math.h>
  #include <stdlib.h>

  typedef struct Pilha {
      double* elementos;
      int topo;
      int tamanho;
  } Pilha;
  
  int estaCheia(Pilha* p) {
      if (p->topo == p->tamanho - 1)
          return 1;
      return 0;
  }

  int estaVazia(Pilha* p) {
      if (p->topo == -1)
          return 1;
      return 0;
  }

  void inicializarPilha(Pilha* p, int tamanho) {
      p->topo = -1;
      p->tamanho = tamanho;
      p->elementos = (double*) malloc(tamanho * sizeof(double));
      if (p->elementos == NULL) {
          printf("ERRO::inicializarPilha::Falha ao alocar memória!\n");
          exit(1);
      }
  }

  void empilhar(Pilha* p, double valor) {
      if (estaCheia(p)) {
          printf("ERRO::empilhar::Pilha cheia!\n");
          exit(1);
      }
      p->topo++;
      p->elementos[p->topo] = valor;
  }

  double desempilhar(Pilha* p) {
      if (estaVazia(p)) {
          printf("ERRO::desempilhar::Pilha vazia!\n");
          exit(1);
      }
      double valor = p->elementos[p->topo];
      p->topo--;
      return valor;
  }

  double topo(Pilha* p) {
      if (estaVazia(p)) {
          printf("ERRO::topo::Pilha vazia!\n");
          exit(1);
      }
      return p->elementos[p->topo];
  }


  int tamanhoPilha(Pilha* p) {
      return p->topo + 1;
  }

  void destruirPilha(Pilha* p) {
      free(p->elementos);
  }

  Pilha pilha;

  int yywrap( );
  void yyerror(const char* str);

  /* the result variable */
  double termLeft, termRight;
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
    | CLEAR DONE{
        for (int i = 0; i < 26; i++) {
            symb[i] = 0;
        }
        printf("All variables cleared.\n");
    }
    ;

line: VARIABLE EQUAL expr DONE { 
    if (!hasError) {
        symb[$1] = $3;
        empilhar(&pilha, $3);
        printf("Result of %c = %lf\n", 'a' + $1, $3);
    } else {
        hasError = 0;
    } 
    }
    | VARIABLE EQUAL expr error { yyerrok; yyclearin; }
    | VARIABLE EQUAL error DONE { yyerrok; yyclearin; }
    | VARIABLE error expr DONE { yyerrok; yyclearin; }
    | error EQUAL expr DONE { yyerrok; yyclearin; }
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
    inicializarPilha(&pilha, tamanho);
    yyparse( );
    printf("\nFinal result: %lf\n\n", desempilhar(&pilha));
    destruirPilha(&pilha);
    return 0;
}