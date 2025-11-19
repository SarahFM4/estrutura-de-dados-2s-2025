// árvore  

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* dir;
    struct no* esq;
} NO;

typedef NO* raiz;

void inserir(NO* raiz, int valor) {
    NO* novo = (NO*)malloc(sizeof(NO));
    (*novo).valor = valor;
    (*novo).dir = NULL;
    (*novo).esq = NULL;

    if (raiz == NULL) {
        raiz = novo;
    } else {
        NO* aux = raiz;
    // ou valor <= (*aux).valor || valor >= (*aux).valor ?
        while (1) {
            if (valor < (*aux).valor) {
                if ((*aux).esq == NULL) {
                    (*aux).esq = novo;
                    break;
                } else {
                    aux = (*aux).esq;
                }
            } else {
                if ((*aux).dir == NULL) {
                    (*aux).dir = novo;
                    break;
                } else {
                    aux = (*aux).dir;
                }
            }
            }
    }
}

int remover(NO* raiz, int valor) {
    NO* aux = raiz;
    NO* ant;

    while (1) {
        if (valor < (*aux).valor) {
            ant = aux;
            aux = (*aux).esq;
        } else if (valor > (*aux).valor) {
            ant = aux;
            aux = (*aux).dir;
        } else {
            if(aux == (*ant).dir) {
                (*aux).dir = NULL;
                free(aux);
                break;
            } else {
                (*aux).esq = NULL;
                free(aux);
                break;
            }
        }
    }
}

void imprimir(NO* raiz) {
    printf("Árvore em pré-ordem: ");

    /*
    NO* raiz = (*raiz).esq;

    while (atual != NULL) {
        printf("%d ", (*atual).valor);
        atual = (*atual).prox;
    }
    printf("\n");
    
    */


}

int main() {
    NO* raiz = NULL;

    inserir(raiz, 37);
    inserir(raiz, 20);
    inserir(raiz, 10);
    inserir(raiz, 30);
    inserir(raiz, 80);
    inserir(raiz,5);


}
