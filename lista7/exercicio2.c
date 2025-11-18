/*
2. Faca um programa que cadastre em uma pilha vários números. A entrada deles será 
finalizada com a digitação de um número menor ou igual a zero. Posteriormente, o programa
deve gerar duas filas, a primeira com os números pares e a segunda com os números impares. 
A saída do programa deve apresentar a pilhadigitada e as filas geradas. 
Caso alguma das filas seja vazia, deve-se mostrar a mensagem.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM_PILHA 100
#define TAM_FILA 100
#define TRUE 1
#define FALSE 0

typedef struct {
    int numeros[TAM_PILHA];
    int topo;
} Pilha;

typedef struct {
    int numeros[TAM_FILA];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int empilhar(Pilha *pilha, int numero) {
    if (pilha->topo >= TAM_PILHA - 1) {
        return FALSE;
    }
    pilha->topo++;
    pilha->numeros[pilha->topo] = numero;
    return TRUE;
}

int desempilhar(Pilha *pilha, int *numeroRemovido) {
    if (pilha->topo < 0) {
        return FALSE;
    }
    *numeroRemovido = pilha->numeros[pilha->topo];
    pilha->topo--;
    return TRUE;
}

int pilhaVazia(Pilha *pilha) {
    return (pilha->topo < 0);
}

void exibirPilha(Pilha *pilha) {
    if (pilha->topo < 0) {
        printf("Pilha vazia!\n");
        return;
    }
        
    printf("Pilha (do topo para a base): ");
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%d ", pilha->numeros[i]);
    }
    printf("\n");
}

void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int enfileirar(Fila *fila, int numero) {
    if (fila->quantidade >= TAM_FILA) {
        return FALSE;
    }
    fila->numeros[fila->fim] = numero;
    fila->fim = (fila->fim + 1) % TAM_FILA;
    fila->quantidade++;
    return TRUE;
}

int desenfileirar(Fila *fila, int *numeroRemovido) {
    if (fila->quantidade <= 0) {
        return FALSE;
    }
    *numeroRemovido = fila->numeros[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_FILA;
    fila->quantidade--;
    return TRUE;
}

int filaVazia(Fila *fila) {
    return (fila->quantidade == 0);
}

void exibirFila(Fila *fila, char *nomeFila) {
    if (filaVazia(fila)) {
        printf("%s: Fila vazia!\n", nomeFila);
        return;
    }
    
    printf("%s: ", nomeFila);
    int pos = fila->inicio;
    for (int i = 0; i < fila->quantidade; i++) {
        printf("%d ", fila->numeros[pos]);
        pos = (pos + 1) % TAM_FILA;
    }
    printf("\n");
}

void processarPilhaParaFilas(Pilha *pilha, Fila *filaPares, Fila *filaImpares) {
    for (int i = 0; i <= pilha->topo; i++) {
        int numero = pilha->numeros[i];
        
        if (numero % 2 == 0) {
            enfileirar(filaPares, numero);
        } else {
            enfileirar(filaImpares, numero);
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Pilha pilha;
    Fila filaPares, filaImpares;
    inicializarPilha(&pilha);
    inicializarFila(&filaPares);  
    inicializarFila(&filaImpares);

    int opc, numero;
    
    while (1) {
        printf("\nMENU\n");
        printf("1 - Cadastrar números na pilha.\n");
        printf("2 - Separar números em filas (pares e ímpares).\n");
        printf("3 - Exibir pilha.\n");
        printf("4 - Exibir filas.\n");
        printf("5 - Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1: {
                printf("Digite números positivos e digite um número menor ou igual a 0 para parar:\n"); 
                do {
                    printf("Número: ");
                    scanf("%d", &numero);
                    
                    if (numero > 0) {
                        if (empilhar(&pilha, numero)) {
                            printf("Número %d empilhado com sucesso!\n", numero);
                        } else {
                            printf("Pilha cheia! Não foi possível empilhar.\n");
                            break;
                        }
                    }
                } while (numero > 0);
                
                printf("Cadastro finalizado.\n");
                break;
            }
            
            case 2: {
                if (pilhaVazia(&pilha)) {
                    printf("Pilha vazia! Não há números para separar.\n");
                    break;
                }
                
                inicializarFila(&filaPares);
                inicializarFila(&filaImpares);
                
                processarPilhaParaFilas(&pilha, &filaPares, &filaImpares);
                
                printf("Separação concluída!\n");
                break;
            }
            
            case 3: {
                if (pilhaVazia(&pilha)) {
                    printf("Não há uma pilha cadastrada!");
                    break;
                } else {
                    exibirPilha(&pilha);
                    break;
                }
            }
            
            case 4: {
                if (filaVazia(&filaImpares) && filaVazia(&filaPares)) {
                    printf("Não há filas cadastradas!");
                    break;
                } else if (filaVazia(&filaImpares) && !filaVazia(&filaPares)) {
                    exibirFila(&filaPares, "Fila de Pares");
                    break;
                } else if (!filaVazia(&filaImpares) && filaVazia(&filaPares)) { 
                    exibirFila(&filaImpares, "Fila de Ímpares");
                    break;      
                } else {
                    printf("\nFilas:\n");
                    exibirFila(&filaPares, "Fila de Pares");
                    exibirFila(&filaImpares, "Fila de Ímpares");
                    break;
                }
            }
            
            case 5: {
                return 0;
            }
            
            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    }
}