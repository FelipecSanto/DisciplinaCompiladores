int main() {
    int a = 5;
    float b = 2.5;
    int c = 10;

    // Pós-incremento
    a++;
    // Pós-decremento
    c--;

    // Incremento composto (+=)
    a += 3;
    // Decremento composto (-=)
    a -= 8;

    // Multiplicação composta (*=)
    a *= 2;

    // Divisão composta (/=)
    a /= 3;

    // Incremento e decremento com float
    b++;
    b += 7.53;
    b *= 2.0;
    b -= 0.75;
    b /= 2.0;

    // Teste com outra variável
    c += a;
    c -= b;
    c *= 2;
    c /= 5;

    printf("a = %d\n", a);
    printf("b = %f\n", b);
    printf("c = %d\n", c);

    return 0;
}