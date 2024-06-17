#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto {
    char nome[100];
    float preco;
    char tamanho[10];
    struct Produto *prev;
    struct Produto *next;
} Produto;

Produto* criarProduto(char* nome, float preco, char* tamanho) {
    Produto* novo = (Produto*)malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->preco = preco;
    strcpy(novo->tamanho, tamanho);
    novo->prev = NULL;
    novo->next = NULL;
    return novo;
}

void inserirProduto(Produto** head, Produto* novo) {
    if (*head == NULL) {
        *head = novo;
        return;
    }
    Produto* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = novo;
    novo->prev = temp;
}

void exibirProdutos(Produto* head, int ordem) {
    Produto* temp = head;
    if (ordem == 1) {
        while (temp != NULL) {
            printf("Nome: %s, Preco: %.2f, Tamanho: %s\n", temp->nome, temp->preco, temp->tamanho);
            temp = temp->next;
        }
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        while (temp != NULL) {
            printf("Nome: %s, Preco: %.2f, Tamanho: %s\n", temp->nome, temp->preco, temp->tamanho);
            temp = temp->prev;
        }
    }
}

Produto* buscarProduto(Produto* head, char* nome) {
    Produto* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removerProduto(Produto** head, char* nome) {
    Produto* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->nome, nome) == 0) {
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            free(temp);
            return;
        }
        temp = temp->next;
    }
}

void lerArquivo(Produto** head, const char* nomeArquivo) {
    FILE* file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Arquivo nao encontrado. Criando um novo arquivo...\n");
        file = fopen(nomeArquivo, "w");
        if (!file) {
            printf("Erro ao criar o arquivo.\n");
            return;
        }
        fclose(file);
        return;
    }
    char nome[100];
    float preco;
    char tamanho[10];
    while (fscanf(file, "%s %f %s", nome, &preco, tamanho) != EOF) {
        Produto* produto = criarProduto(nome, preco, tamanho);
        inserirProduto(head, produto);
    }
    fclose(file);
}

void menu(Produto** head) {
    int opcao;
    char nome[100];
    float preco;
    char tamanho[10];
    Produto* produto;
    
    do {
        printf("\nMenu:\n");
        printf("1) Inserir um novo produto\n");
        printf("2) Exibir os produtos em ordem crescente\n");
        printf("3) Exibir os produtos em ordem decrescente\n");
        printf("4) Buscar um produto pelo nome\n");
        printf("5) Remover um produto pelo nome\n");
        printf("6) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Preco: ");
                scanf("%f", &preco);
                printf("Tamanho: ");
                scanf("%s", tamanho);
                produto = criarProduto(nome, preco, tamanho);
                inserirProduto(head, produto);
                break;
            case 2:
                exibirProdutos(*head, 1);
                break;
            case 3:
                exibirProdutos(*head, 0);
                break;
            case 4:
                printf("Nome: ");
                scanf("%s", nome);
                produto = buscarProduto(*head, nome);
                if (produto) {
                    printf("Produto encontrado: Nome: %s, Preco: %.2f, Tamanho: %s\n", produto->nome, produto->preco, produto->tamanho);
                } else {
                    printf("Produto nao encontrado.\n");
                }
                break;
            case 5:
                printf("Nome: ");
                scanf("%s", nome);
                removerProduto(head, nome);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 6);
}

int main() {
    Produto* head = NULL;
    lerArquivo(&head, "produtos.txt");
    menu(&head);
    return 0;
}


/*

arquivo.txt

Camiseta 49.90 M
Calca 99.90 G
Sapato 149.90 42
Vestido 129.90 P
Blusa 59.90 M
Short 69.90 G
Tenis 199.90 41
Saia 89.90 M
Jaqueta 199.90 G
Moletom 149.90 GG

*/