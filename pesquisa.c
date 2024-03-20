#include <stdio.h>

int buscaBinaria(int lista[], int tamanho, int chave) {
    int inicio = 0, fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (lista[meio] == chave)
            return meio;
        
        if (lista[meio] < chave)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }
    
    return -1;
}

int main() {
    int pacotes[] = {102, 205, 307, 409, 512, 615, 718, 821, 924, 1027};
    int tamanho = sizeof(pacotes) / sizeof(pacotes[0]);
    int codigo_rastreamento = 615;
    int posicao = buscaBinaria(pacotes, tamanho, codigo_rastreamento);
    
    if (posicao != -1)
        printf("O pacote com o código de rastreamento %d foi encontrado na posição %d.\n", codigo_rastreamento, posicao);
    else
        printf("O pacote com o código de rastreamento %d não foi encontrado.\n", codigo_rastreamento);
    
    return 0;
}