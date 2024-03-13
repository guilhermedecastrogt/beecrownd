#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int *px, int *py) {
    int aux = *px;
    *px = *py;
    *py = aux;
}

void bubbleSort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] < vetor[j + 1]) {
                trocar(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

int main() {
    srand(time(NULL)); 

    int tamanho = 10;

    int vetor[tamanho];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor antes da ordenacao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    bubbleSort(vetor, tamanho);

    printf("\nVetor ordenado em ordem decrescente:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
