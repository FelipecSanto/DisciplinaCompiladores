/*  Definições */
%option noyywrap

%{
    #include <stdio.h>
    #include <math.h>
    #include <stdlib.h>

    typedef struct Pilha {
        double* elementos;
        int topo;
        int tamanho;
    } Pilha;

    void inicializarPilha(Pilha* p, int tamanho) {
        p->topo = -1;
        p->tamanho = tamanho;
        p->elementos = (double*) malloc(tamanho * sizeof(double));
        if (p->elementos == NULL) {
            printf("Erro: Falha ao alocar memória!\n");
            exit(EXIT_FAILURE);
        }
    }

    void empilhar(Pilha* p, double valor) {
        p->topo++;
        p->elementos[p->topo] = valor;
    }

    double desempilhar(Pilha* p) {
        double valor = p->elementos[p->topo];
        p->topo--;
        return valor;
    }

    double topo(Pilha* p) {
        return p->elementos[p->topo];
    }

    void estaCheia(Pilha* p) {
        if (p->topo == p->tamanho - 1) {
            printf("Pilha cheia!\n");
        } else {
            printf("Pilha não cheia!\n");
        }
    }

    void estaVazia(Pilha* p) {
        if (p->topo == -1) {
            printf("Pilha vazia!\n");
        } else {
            printf("Pilha não vazia!\n");
        }
    }

    void destruirPilha(Pilha* p) {
        free(p->elementos);
    }

    Pilha pilha;
    double num1, num2, resultado;
%}

REAIS -?[0-9]+(\.[0-9]+)? 
OPERANDOS [\+\-\*\/]

/* ------------------------------------------------------------------------------------------------------------------------------------------------------ */
/* Regras de Produção */
%%


{REAIS} {
    resultado = atof(yytext); 
    empilhar(&pilha, resultado);
}

{OPERANDOS} {
    num1 = topo(&pilha);
    desempilhar(&pilha);
    num2 = topo(&pilha);
    desempilhar(&pilha);

    switch(yytext[0]) {
        case '+':
            resultado = num2 + num1;
            break;
        case '-':
            resultado = num2 - num1;
            break;
        case '*':
            resultado = num2 * num1;
            break;
        case '/':
            resultado = num2 / num1;
            break;
    }

    empilhar(&pilha, resultado);
}

\-\- { printf("\n"); }

\n {
    if (topo(&pilha) == (int)topo(&pilha)) {
        printf("\n\tResultado: %d\n", (int)topo(&pilha));
    } else {
        printf("\n\tResultado: %f\n", topo(&pilha));
    }
    desempilhar(&pilha);
}


.|\t|\ |\r {/* Ignora qualquer caractere não reconhecido */}
%%
/* ------------------------------------------------------------------------------------------------------------------------------------------------------ */


/* Código */
int main() {
    inicializarPilha(&pilha, 100);

    printf("\n\nIniciando analisador...\n");
    yylex();
    
    if (topo(&pilha) == (int)topo(&pilha)) {
        printf("\n\tResultado: %d\n", (int)topo(&pilha));
    } else {
        printf("\n\tResultado: %f\n", topo(&pilha));
    }
    printf("\n\nAnalisador finalizado.\n\n\n");

    destruirPilha(&pilha);
    return 0;
}