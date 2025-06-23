// Teste completo de if, elseif e else
int main() {
    int a = 5;
    int b = 10;
    int c = 0;

    // if simples, sem else
    if (a < b) {
        a = a + 1;
    }

    // if com else
    if (a > b) {
        a = a - 1;
    } else {
        a = a + 2;
    }

    // if com elseif
    if (a == 10) {
        b = b + 1;
    } else if (a == 7) {
        b = b + 2;
    }

    // if com múltiplos elseif e else
    if (a == 1) {
        c = 1;
    } else if (a == 2) {
        c = 2;
    } else if (a == 3) {
        c = 3;
    } else {
        c = 99;
    }

    // if aninhado com else
    if (b > 5) {
        if (a < 10) {
            c = c + 1;
        } else {
            c = c + 2;
        }
    } else {
        c = c - 1;
    }

    // if aninhado dentro de elseif
    if (a > 0) {
        c = 10;
    } else if (b > 0) {
        if (c == 0) {
            c = 20;
        }
    } else {
        c = 30;
    }

    a = 10;
    b = 20;
    c = 30;
    return 0;
}