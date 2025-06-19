// Teste de cast entre tipos e operações
int main() {
    int a = 10;
    float b = 3.7;
    char c = 'A';
    bool d = true;

    // int para float e soma
    float soma1 = (float)a + b;
    printf(soma1);

    // float para int e subtração
    int sub1 = (int)b - a;
    printf(sub1);

    // int para char e multiplicação
    char mult1 = (char) (a * 2);
    printf(mult1);

    // char para int e divisão
    int div1 = (int)c / 2;
    printf(div1);

    // int para bool e operação lógica
    bool log1 = (bool)a && d;
    printf(log1);

    // bool para int e soma
    int soma2 = (int)d + a;
    printf(soma2);

    // float para bool e operação lógica
    bool log2 = (bool)b || d;
    printf(log2);

    // bool para float e soma
    float soma3 = (float)d + b;
    printf(soma3);
}