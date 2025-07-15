/* ============================================================================== */
/*                  Implementação do algoritmo Bubble Sort                        */
/* ============================================================================== */

// Implementação de um algoritmo real utilizado para ordenação de vetores

int main(){
    // Vetor desordenado de tamanho 5
    int v[5] = {5, 3, 4, 1, 2};
    int i, j, temp;

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado: ");
    for (i = 0; i < 5; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}