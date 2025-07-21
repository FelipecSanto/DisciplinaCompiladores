/* ============================================================================== */
/*                  Implementação do algoritmo Bubble Sort                        */
/* ============================================================================== */

// Implementação de um algoritmo real utilizado para ordenação de vetores

int main(){
    // Vetor desordenado de tamanho 5
    int v[5] = {5, 3, 4, 1, 2};
    int temp;

    for (int i = 0; i < 5 - 1; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    return 0;
}