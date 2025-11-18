/*
    1. Escreva uma versão do exemplo feito em sala Parênteses e Colchetes que aloque a 
    pilha dinamicamente (Utilizando structs e alocação dinâmica de memória).
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 100
#define TRUE 1
#define FALSE 0

typedef struct pilha {
    int valor;
    struct pilha *prox;
} pilha;

void criarPilha(pilha* topo) {
    (*topo).prox = NULL;
}

void empilhar(int valor, pilha* topo) {
    pilha* novo = (pilha*)malloc(sizeof(pilha));
    if (novo == NULL) {
        printf("Erro: memória insuficiente!\n");
        return;
    }
    (*novo).valor = valor;
    (*novo).prox = (*topo).prox;
    (*topo).prox = novo;
}

int desempilhar(pilha* topo) {
    if ((*topo).prox == NULL) {
        printf("Pilha vazia!\n");
        return FALSE; 
    }

    pilha* aux = (*topo).prox;
    int valor = (*aux).valor;

    (*topo).prox = (*aux).prox;
    free(aux);

    return TRUE;
}

void imprimir(pilha* topo) {
    pilha* atual = (*topo).prox;

    while (atual != NULL) {
        printf("%d ", (*atual).valor);
        atual = (*atual).prox;
    }
    printf("\n");
}

int main() {
    pilha* topo = (pilha*)malloc(sizeof(pilha));
    criarPilha(topo);

    int opc, valor;
    
    while (1) {
        printf("MENU\n");
        printf("1 - Empilhar.\n");
        printf("2 - Desempilhar.\n");
        printf("3 - Imprimir.\n");
        printf("0 - Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: 
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                printf("\n");

                empilhar(valor, topo);
                break;
            case 2:
                if (desempilhar(topo) == TRUE) {
                    printf("O topo foi removido!");
                } else {
                    printf("Não foi possível desempilhar.");
                }
                break;
            case 3: 
                imprimir(topo);
                break;
            case 0: 
                return 0;
            default:
                printf("\nOpção inválida!\n");
        }
    }
}
