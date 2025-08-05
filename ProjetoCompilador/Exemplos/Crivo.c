/* ============================================================================== */
/*              Implementação do algoritmo do Crivo de Erastótenes                */
/* ============================================================================== */

// Implementação de um algoritmo real utilizado para verificação de primos

int TAM = 100;

int main(){
    // Vetor de primos. Se no final tiver valor 0, não é primo, caso contrário, é primo
    int primos[TAM];

    // Inicializa e coloca o vetor como primo
    for(int i = 2; i < TAM; i++){
        primos[i] = i;
    }

    // 0 e 1 não são primos
    primos[0] = 0;
    primos[1] = 0;

    // n vai ser usado para tirar os primos
    int n = 2;
    
    // Limite é a raiz quadrada do número que queremos verificar (arredondado para cima)
    while(n * n < TAM){
        // Se o número n for primo, utiliza para retirar do vetor
        int p = primos[n];
        if(p != 0){
            for(int i = n * n; i < TAM; i += n){
                primos[i] = 0;
            }
        }
        n++;
    }

    return 0;
}
