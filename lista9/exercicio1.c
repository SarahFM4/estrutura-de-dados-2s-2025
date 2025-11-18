/*
Escreva um algoritmo que use uma pilha para inverter a ordem das letras de cada palavra de
uma string ASCII, preservando a ordem das palavras. Por exemplo, para a string ESTE EXERCICIO E
MUITO FACIL o resultado deve ser ETSE OICICREXE E OTIUM LICAF .
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
