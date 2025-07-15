/* ============================================================================== */
/*              Implementação do algoritmo do Crivo de Erastótenes                */
/* ============================================================================== */

// Implementação de um algoritmo real utilizado para verificação de primos

int main(){
    // Vetor de até 100 primos. Se no final tiver o valor 1, é primo, caso contrário, não é primo
    int primos[100];

    // 0 e 1 não são primos
    primos[0] = 0;
    primos[1] = 0;

    // Coloca o restante do vetor como primo
    for(int i = 2; i < 100; i++){
        primos[i] = 1;
    }

    // n vai ser usado para tirar os primos
    int n = 2;
    
    // Limite é a raiz quadrada do número que queremos verificar (100)
    while(n <= 10){
        // Se o número n for primo, utiliza para retirar do vetor
        if(primos[1] == 1){
            for(int i = 2 * n; i < 100; i += n){
                primos[i] = 0;
            }
        }
        n++;
    }
        
    return 0;
}
