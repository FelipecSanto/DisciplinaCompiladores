int a;
int b;

a = 5;
b = 3;

if (a > 3) {
    int c;
    c = a + b;
}

if(b < 10){
    // Erro, c não existe no escopo.
    c = 2;
}
