// Exemplo com escopo

// Variáveis globais -- Podem ser usados em qualquer escopo do arquivo
int g1 = 14;

int soma(int v1, int v2){
    // Variáveis vindo da função
    int r1 = v1 + v2;

    // Erro -- variáveis do escopo main
    int r2 = a + b;

    // Variável global funcionando
    int r3 = v1 + g1;

    return r1;
}

int main() {
    // Escopo -- main
    int a = 3, b = 5;

    if (a > 2) {
        // Variável no escopo do if externo
        int c = a + g1;
        if(b > 3){
            // Variável no escopo do if interno
            int d = c + 4;
        }
        // Erro -- d não existe no escopo
        c = d - g1;
    }

    if(b < 10){
        // Erro -- c não existe no escopo
        c = 2;
    }

    int r = soma(a, b);

    // Erro -- r1 existe apenas na função soma
    int e = r1;

    return 0;
}