/*

Este código irá gerar um grande vetor de números aleatórios e medir o tempo gasto para ordená-lo 
usando Insertion Sort e Selection Sort. Você pode ajustar a constante SIZE para aumentar ou diminuir 
o tamanho do vetor e, assim, observar o comportamento dos algoritmos em diferentes escalas. 
Os resultados serão úteis para determinar qual algoritmo é mais eficiente em termos de tempo de execução.

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000 

void gerarNumerosAleatorios(int vetor[]) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = rand() % 100; 
    }
}

void exibirVetor(int vetor[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void insertionSort(int vetor[]) {
    int i, j, key;
    for (i = 1; i < SIZE; i++) {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

void selectionSort(int vetor[]) {
    int i, j, min_index;
    for (i = 0; i < SIZE-1; i++) {
        min_index = i;
        for (j = i+1; j < SIZE; j++) {
            if (vetor[j] < vetor[min_index]) {
                min_index = j;
            }
        }
        int temp = vetor[min_index];
        vetor[min_index] = vetor[i];
        vetor[i] = temp;
    }
}

int main() {
    int vetor[SIZE];
    clock_t inicio, fim;
    double tempo_insertion, tempo_selection;

    gerarNumerosAleatorios(vetor);

    inicio = clock();
    insertionSort(vetor);
    fim = clock();
    tempo_insertion = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto para ordenação usando Insertion Sort: %f segundos\n", tempo_insertion);

    gerarNumerosAleatorios(vetor);

    inicio = clock();
    selectionSort(vetor);
    fim = clock();
    tempo_selection = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto para ordenação usando Selection Sort: %f segundos\n", tempo_selection);

    return 0;
}
