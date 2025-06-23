// Exemplo abrangente de funções

// Variáveis globais
int g1 = 10;
float g2 = 3.5;
char g3 = 'A';
bool g4 = true;

// Função que soma dois inteiros
int soma(int a, int b) {
    int resultado = a + b;
    return resultado;
}

// Função que calcula a média de dois floats
float media(float x, float y) {
    float m = (x + y) / 2.0;
    return m;
}

// Função que retorna o maior de dois inteiros
int maior(int x, int y) {
    if (x > y) {
        return x;
    } else {
        y = y + 1; // Incrementa y se for menor
    }

    return y; // Retorna o maior ou o incrementado
}

// Função que inverte um booleano
bool inverte(bool b) {
    return !b;
}

// Função sem retorno (void)
void imprimeMensagem() {
    printf("Executando imprimeMensagem");
}

// Função que usa variáveis globais e locais
int calculaTudo(int x, float y) {
    int s = soma(x, g1);
    float m = media(g2, 2.5);
    char c = g3;
    bool b = inverte(g4);

    printf("Soma: %d, Media: %.2f, Caractere: %c, Invertido: %d\n", s, m, c, b);

    return s + (int)m + (int)c + (int)b;
}

int main() {
    int a = 5, b = 7;
    float f1 = 4.0, f2 = 6.0;
    bool flag = false;

    int resultadoSoma = soma(a, b);
    float resultadoMedia = media(f1, f2);
    int resultadoMaior = maior(a, b);
    bool resultadoInverte = inverte(flag);

    printf("Resultado da soma: %d\n", resultadoSoma);
    printf("Resultado da media: %.2f\n", resultadoMedia);
    printf("Maior valor: %d\n", resultadoMaior);
    printf("Inverte booleano: %d\n", resultadoInverte);

    imprimeMensagem();

    int resultadoFinal = calculaTudo(20, 3.5);
    printf("Resultado final do calculaTudo: %d\n", resultadoFinal);

    return 0;
}