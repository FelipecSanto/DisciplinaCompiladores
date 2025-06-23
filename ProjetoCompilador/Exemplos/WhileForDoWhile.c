int main(){

    int a = 2;
    int b = 3;

    // Estrutura de repetição for
    for(int i = 0; i < 5; i++){
        b = a + b;
    }

    int c = 10;

    // Estrutura de repetição while
    while (c > 5)
    {
        c = c - 1;
    }

    c = 5;
    do {
        printf("%d\n", c);
        c--;
    } while (c > 0);

    for (int i = 0; i < 3; i = i + 1) {
        for (int j = 0; j < 2; j = j + 1) {
            printf("i = %d, j = %d\n", i, j);
        }
    }

    for (int i = 0; i < 3; i = i + 1) {
        int x = i;
        while (x > 0) {
            printf("i = %d, x = %d\n", i, x);
            x = x - 1;
        }
    }

    int k = 2;
    while (k > 0) {
        for (int m = 0; m < 3; m = m + 1) {
            printf("k = %d, m = %d\n", k, m);
        }
        k--;
    }

    int z = 4;
    do {
        if (z / 2 == 0) {
            printf("%d é par\n", z);
        } else {
            printf("%d é ímpar\n", z);
        }
        z--;
    } while (z > 0);

    a = 2;
    do {
        b = 1;
        do {
            printf("a = %d, b = %d\n", a, b);
            b++;
        } while (b <= 2);
        a--;
    } while (a > 0);


    int z = 2;

    return 0;
}