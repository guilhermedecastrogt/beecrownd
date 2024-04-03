#include <stdio.h>
#include <stdlib.h>

void mudanca_de_base(int numero, int base) {
    int vetor_pilha[100];
    int topo = -1;

    while (numero > 0) {
        int resto = numero % base;
        vetor_pilha[++topo] = resto;
        numero = numero / base;
    }

    printf("Novo número na base %d: ", base);
    while (topo != -1) {
        printf("%d", vetor_pilha[topo--]);
    }
}

int main() {
    int numero, base;
    printf("Digite o número a ser convertido: ");
    scanf("%d", &numero);
    printf("Digite a base para conversão: ");
    scanf("%d", &base);

    mudanca_de_base(numero, base);

    return 0;
}
