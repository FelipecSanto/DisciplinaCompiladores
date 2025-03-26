/*  Definições */
%{
    #include <stdio.h>
    #include <math.h>
%}
d [0-9]
l [a-zA-Z]
s [ \t\n]
octeto (25[0-5]|2[0-4][0-9]|1[0-9]{2}|[1-9]?[0-9])
/* ------------------------------------------- */
/* Regras */
/* Ex 1: */
%%
\({d}{2}\){d}{5}-{d}{4}                                 printf("EX1 - Nro. de Telefone no Brasil encontrado: %s\n", yytext);    /* 1) Nros. de Telefones no Brasil: (xx)xxxxx-xxxx */
{l}{3}{d}{l}{d}{2}                                      printf("EX2 - Placa de Carro Brasileiro encontrada: %s\n", yytext);     /* 2) Placas de Carros Brasileiros: XXX1Y23 */

{d}{3}-{d}{1,5}-{d}{1,7}-{d}{1,6}-{d}{1} {
    int total_digits = 0;
    for (int i = 0; yytext[i] != '\0'; i++) {
        if (yytext[i] >= '0' && yytext[i] <= '9') {
            total_digits++;
        }                                                                                                                       /* 3) ISBN de um livro: ddd-ddddd-ddddddd-dddddd-d sempre com 13 dígitos */
    }
    if (total_digits == 13)
        printf("EX3 - ISBN de um livro válido encontrado: %s\n", yytext);
    else    
        printf("EX3 - ISBN de um livro INválido encontrado: %s Número de digitos encontrados: %d\n", yytext, total_digits);
}

{octeto}\.{octeto}\.{octeto}\.{octeto}                  printf("EX4 - Endereço IPv4 encontrado: %s\n", yytext);                 /* 4) Endereços IPv4: ddd.ddd.ddd.ddd */

M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})  printf("EX6 - Numero romano encontrado: %s\n", yytext);                 /* 6) Números romanos */
[\+\-]?{d}+(\.{d}+)?(E[\+\-]?{d}+)?                     printf("EX8 - Numero real encontrado: %s\n", yytext);                   /* 8) Números reais (qualquer notação, incluindo científica) */

\<({l}|{d})+({s}+[^>]+)?\>.*\<\/({l}|{d})+\> {
    char opening_tag[100], closing_tag[100];
    sscanf(yytext, "<%[^ >]", opening_tag); // Captura a tag de abertura
    sscanf(strrchr(yytext, '<'), "</%[^>]", closing_tag); // Captura a tag de fechamento

    if (strcmp(opening_tag, closing_tag) == 0) {
        printf("EX9 - Tags HTML (padrão) encontrada: %s\n", yytext);                                                            /* 9) Tags HTML (padrão): <tag .*> .* <\tag> */
    } else {
        printf("EX9 - Tag HTML INválida encontrada: %s\n", yytext);
    }
}

.|\n   {/* Ignora qualquer caractere não reconhecido */}
%%
/* ------------------------------------------- */
/* Código */
int main () {
    printf("\n\nIniciando analisador:\n\n");
    yylex(); 
    return 0;
}
/* Encerra ao chegar no final do arquivo */
int yywrap() {
    return 1;
}