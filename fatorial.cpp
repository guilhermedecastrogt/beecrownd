#include <stdio.h>

int fatorial (int n) {
    return (n > 0) ? n*fatorial(n-1) : 1;
}
/*
* Em uma escola, dos x alunos classificados para a OBMEP,
* n serão premiados por um sorteio realizado pela instituição.
* Os sorteados receberão uma cesta de café da manhã.
* De quantas maneiras distintas a dupla premiada pode ocorrer?
*
* Estamos calculando a combinação de x elementos tomados de n em n.
*/

int main() {
    int alunos, sorteados;
    int C;
    printf("Digite o numero de alunos que classificaram para a OBMEP: ");
    scanf("%d", &alunos);
    printf("\nDigite a quantidade de alunos a serem sorteados: ");
    scanf("%d", &sorteados);
    printf("\nAgora, vamos calcular de quantas maneiras destintas podemos sortear %d destes alunos.\n", sorteados);

    if (sorteados > alunos) {
        printf("O numero de sorteados nao pode ser maior que o numero de alunos! Reinicie o programa...");
        return 1;
    }

    C = fatorial(alunos)/(fatorial(sorteados)*fatorial(alunos-sorteados));

    printf("Considerando uma combinacao de %d tomados por %d a %d, temos que: %d\n", alunos, sorteados, sorteados, C);

    return 0;
}