#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} NO;

void criarLista (NO* inicio) {
    (*inicio).prox = NULL;
}

void inserir(int valor, NO* inicio) {
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

void remover(NO* no) {
    NO* aux = (*no).prox;
    (*no).prox = (*aux).prox;
    free(aux);
}

void exibirLista(NO* inicio) {
    NO* aux = (*inicio).prox;  

    printf("Lista (do inicio ao fim): ");
    while(aux!=NULL) {
        printf("%d ", (*aux).valor);
        aux = (*aux).prox;
    }

}


int main() {
    NO* inicio = (NO*)malloc(sizeof(NO));
    criarLista(inicio);

    int opc, pos, valor;
    
    while (1) {
        printf("\nMENU\n");
        printf("1 - Adicionar.\n");
        printf("2 - Inserir.\n");
        printf("3 - Remover.\n");
        printf("4 - Exibir.\n");
        printf("0 - Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: 
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);

                inserir(valor, inicio);
                break;
            case 2:
                printf("Em qual posição deseja inserir?");
                scanf("%d", &pos);

                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);

                NO* aux = acessar(pos, inicio);
                inserir(valor, aux);
            case 3: 
                printf("Digite a posição que deseja excluir: ");
                scanf("%d", pos);

                NO* removido = acessar(pos-1, inicio);
                remover(removido);
                break;
            case 4:
                exibirLista(inicio);
            case 0: 
                return 0;
            default:
                printf("\nOpção inválida!\n");
        }
    }
}
