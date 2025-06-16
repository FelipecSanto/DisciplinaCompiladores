// Teste de operações com vetor de inteiros

// Declaração de vetor sem inicialização
int v[5];

// Declaração de vetor com inicialização direta
int w[3] = {1, 2, 3};

// Declaração de múltiplos vetores, um inicializado e outro não
int x[2] = {10, 20}, y[4];

// Variáveis auxiliares
int a, b, c, d, e;

// Atribuição direta
v[0] = 10;
v[1] = 20;
v[2] = 30;
v[3] = 40;
v[4] = 50;

// Atribuição usando expressão
v[0] = v[1] + v[2];
v[1] = v[2] - v[3];
v[2] = v[3] * v[4];
v[3] = v[4] / 2;
v[4] = v[0] + v[1] * v[2] - v[3] / 2;

// Atribuição de vetor para variável simples
a = v[0];
b = v[1];
c = v[2];
d = v[3];
e = v[4];

// Operações entre elementos do vetor e variáveis
a = v[0] + b;
b = v[1] - c;
c = v[2] * d;
d = v[3] / 2;
e = v[4] + a * b - c / d;

// Comparações e condicionais com vetor
if (v[0] > v[1]) {
    printf("v[0] > v[1]");
}
if (v[2] == v[3]) {
    printf("v[2] == v[3]");
}
if (v[4] != 0) {
    printf("v[4] diferente de zero");
}