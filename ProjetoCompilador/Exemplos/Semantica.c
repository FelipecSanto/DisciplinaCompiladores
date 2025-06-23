int main(){

    char c = 'a', d = 'b', e;
    int x;
    int y[3] = {1, 2, 3};
    bool flag1 = true, flag2 = false;

    // Erro semântico: variável 'c' não pode ser usada como inteiro
    x = c + 2;

    // Erro semântico: não é possível somar um inteiro com um array
    x = y + 5;

    // Erro semântico: não é possível somar dois caracteres diretamente
    e = c + d;
    
    // O mesmo vai valer para booleanos
    x = flag1 + 1;
    flag2 = flag1 + flag2;
    flag2 = flag1 + y;

    // Erro lêxico: % não é e nem faz parte de um token conhecido
    int %a = 5;

    return 0;
}