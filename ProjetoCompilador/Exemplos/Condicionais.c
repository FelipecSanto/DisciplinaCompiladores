// Teste completo de if, elseif e else

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
} elseif (a == 7) {
    b = b + 2;
}

// if com múltiplos elseif e else
if (a == 1) {
    c = 1;
} elseif (a == 2) {
    c = 2;
} elseif (a == 3) {
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

int a = 5;
int b = 8;

if (a > 3) {
    a = 1;

    if (a > 1) {
        a = a + 2;
    } elseif (a == 1) {
        a = a + 10;
    } else {
        a = a - 1;
    }
}
elseif (a > 10) {
    a = 5;

    if (b < 10) {
        b = b * 2;
    } else {
        b = b / 2;
    }
}
else {
    a = 23;

    if (a == 23) {
        b = 100;
    } elseif (a == 0) {
        b = 0;
    } else {
        b = -1;
    }
}

// if aninhado dentro de elseif
if (a > 0) {
    c = 10;
} elseif (b > 0) {
    if (c == 0) {
        c = 20;
    }
} else {
    c = 30;
}

a = 10;
b = 20;
c = 30;