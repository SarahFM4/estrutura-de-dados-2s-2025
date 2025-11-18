#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
    struct no* ant;
} NO;

void criarLista (NO* inicio) {
    (*inicio).prox = NULL;
    (*inicio).ant = NULL;
}

void inserirInicio(int valor, NO* inicio) {
    NO* novo = (NO*)malloc(sizeof(NO));
    (*novo).valor = valor;
    (*novo).prox = NULL;

    if((*inicio).prox == NULL) {
        (*inicio).prox = novo;
    } else {
        (*novo).prox = (*inicio).prox;
        (*inicio).prox = novo;
    } 
}

NO* acessar(int pos, NO* inicio) {
    int i = 0;
    NO* aux = (*inicio).prox;

    while(aux!=NULL) {
        if (i==pos) {
            return aux;
        } else {
            aux = (*aux).prox;
            i++;
        }
    }
    return NULL;
}

/* 
void inserirFinal(int valor, NO* prox) {
    NO* novo = (NO*)malloc(sizeof(NO));
    (*novo).valor = valor;
    (*novo).prox = NULL;

    if((*prox).prox == NULL) {
        (*prox).prox = novo;
    } else {
        (*novo).prox = (*prox).prox;
        (*prox).prox = novo;
    } 
} 
*/

/* void exibirLista(NO* inicio) {
    int pos = 0;
    NO* aux = acessar(pos, inicio);
    printf("Lista (do inicio ao fim): ");
    for (int i = (*aux).prox; i >= 0; i++) {
        printf("%d ", (*inicio).valor);
        acessar(i, inicio);
    }
    printf("\n");
} */

int main() {
    NO* inicio = (NO*)malloc(sizeof(NO));
    criarLista(inicio);

    inserirInicio(9, inicio);
    inserirInicio(3, inicio);
    acessar(2, inicio);


}
