// Teste de printf e scanf para todos os tipos

int main() {
    int a = 0;
    float b = 0.0;
    char c = 'a';
    bool d = false;

    printf("Digite um inteiro:\n");
    scanf("%d", &a);
    printf("Voce digitou o inteiro: %d\n", a);

    printf("Digite um float:\n");
    scanf("%f", &b);
    printf("Voce digitou o float: %f\n", b);

    printf("Digite um caractere:\n");
    scanf("%c", &c);
    printf("Voce digitou o caractere: %c\n", c);

    printf("Digite um booleano (0 ou 1):\n");
    scanf("%d", &d);
    printf("Voce digitou o booleano: %d\n", d);
}