/*
1. Faça um programa que apresente o menu de opções abaixo: 

MENU
1 - Cadastrar aluno
2 - Cadastrar nota 
3 - Calcular média de um aluno
4 - Listar os nomes dos alunos sem notas 
5 - Excluir aluno
6 - Excluir nota
7 - Sair

Observacões: 

a) Na opcão 1 deve ser cadastrado um aluno (número e nome) de cada vez em uma
pilha.
b) Na opcão 2 deve ser cadastrada uma nota (número do aluno e nota) de cada vez em
uma fila. Uma nota só pode ser cadastrada se pertencer a um aluno cadastrado na pilha de alunos
c) Na opcão 3 o usuário deve digitar o número de um aluno e o programa deve mostrar o nome 
dele e a média aritmética das notas desse aluno.
d) Na opção 5 um aluno da pilha de alunos deve ser excluído, respeitando duas regras: 
a) um aluno só pode ser excluído se não possuir notas; b) o usuário não deve
escolher o aluno a ser excluído, pois a exclusão deve obedecer as regras de 
funcionamento de uma estrutura de dados do tipo pilha. 
e) Na opção 6 uma nota deve ser excluída, respeitando as regras de funcionamento de
uma estrutura do tipo fila. 
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
    int numero;
    char nome[50];
} Aluno;

typedef struct {
    Aluno alunos[TAM_PILHA];
    int topo;
} PilhaAlunos;

typedef struct {
    int numeroAluno;
    float valorNota;
} Nota;

typedef struct {
    Nota notas[TAM_FILA];
    int inicio;
    int fim;
    int quantidade;
} FilaNotas;

void inicializarPilha(PilhaAlunos *pilha) {
    pilha->topo = -1;
}

int empilharAluno(PilhaAlunos *pilha, Aluno aluno) {
    if (pilha->topo >= TAM_PILHA - 1) {
        return FALSE;
    }
    pilha->topo++;
    pilha->alunos[pilha->topo] = aluno;
    return TRUE;
}

int desempilharAluno(PilhaAlunos *pilha, Aluno *alunoRemovido) {
    if (pilha->topo < 0) {
        return FALSE;
    }
    *alunoRemovido = pilha->alunos[pilha->topo];
    pilha->topo--;
    return TRUE;
}

int pilhaVazia(PilhaAlunos *pilha) {
    return (pilha->topo < 0);
}

Aluno* buscarAluno(PilhaAlunos *pilha, int numero) {
    for (int i = pilha->topo; i >= 0; i--) {
        if (pilha->alunos[i].numero == numero) {
            return &(pilha->alunos[i]);
        }
    }
    return NULL;
}

void inicializarFila(FilaNotas *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->quantidade = 0;
}

int enfileirarNota(FilaNotas *fila, Nota nota) {
    if (fila->quantidade >= TAM_FILA) {
        return FALSE;
    }
    fila->notas[fila->fim] = nota;
    fila->fim = (fila->fim + 1) % TAM_FILA;
    fila->quantidade++;
    return TRUE;
}

int desenfileirarNota(FilaNotas *fila, Nota *notaRemovida) {
    if (fila->quantidade <= 0) {
        return FALSE;
    }
    *notaRemovida = fila->notas[fila->inicio];
    fila->inicio = (fila->inicio + 1) % TAM_FILA;
    fila->quantidade--;
    return TRUE;
}

int filaVazia(FilaNotas *fila) {
    return (fila->quantidade == 0);
}

int alunoTemNotas(FilaNotas *fila, int numeroAluno) {
    int i, pos;
    for (i = 0, pos = fila->inicio; i < fila->quantidade; i++, pos = (pos + 1) % TAM_FILA) {
        if (fila->notas[pos].numeroAluno == numeroAluno) {
            return TRUE;
        }
    }
    return FALSE;
}

float calcularMediaAluno(FilaNotas *fila, int numeroAluno) {
    int i, pos;
    float soma = 0;
    int count = 0;
    for (i = 0, pos = fila->inicio; i < fila->quantidade; i++, pos = (pos + 1) % TAM_FILA) {
        if (fila->notas[pos].numeroAluno == numeroAluno) {
            soma += fila->notas[pos].valorNota;
            count++;
        }
    }
    if (count == 0) {
        return 0.0; 
    }
    return soma / count;
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    PilhaAlunos pilhaAlunos;
    FilaNotas filaNotas;
    inicializarPilha(&pilhaAlunos);
    inicializarFila(&filaNotas);

    int opcao;
    while (1) {
        printf("\nMENU\n");
        printf("1 - Cadastrar aluno.\n");
        printf("2 - Cadastrar nota.\n");
        printf("3 - Calcular média de um aluno.\n");
        printf("4 - Listar os nomes dos alunos sem notas.\n");
        printf("5 - Excluir aluno.\n");
        printf("6 - Excluir nota.\n");
        printf("7 - Sair.\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Aluno novoAluno;
                printf("Digite o número do aluno: ");
                scanf("%d", &novoAluno.numero);
                printf("Digite o nome do aluno: ");
                scanf("%s", novoAluno.nome);
                if (empilharAluno(&pilhaAlunos, novoAluno)) {
                    printf("Aluno cadastrado com sucesso!\n");
                } else {
                    printf("Erro: Pilha de alunos cheia!\n");
                }
                break;
            }
            case 2: {
                int numeroAluno;
                float nota;
                printf("Digite o número do aluno: ");
                scanf("%d", &numeroAluno);
                Aluno *aluno = buscarAluno(&pilhaAlunos, numeroAluno);
                if (aluno == NULL) {
                    printf("Erro: Aluno não encontrado!\n");
                } else {
                    printf("Digite a nota: ");
                    scanf("%f", &nota);
                    Nota novaNota;
                    novaNota.numeroAluno = numeroAluno;
                    novaNota.valorNota = nota;
                    if (enfileirarNota(&filaNotas, novaNota)) {
                        printf("Nota cadastrada com sucesso!\n");
                    } else {
                        printf("Erro: Fila de notas cheia!\n");
                    }
                }
                break;
            }
            case 3: {
                int numeroAluno;
                printf("Digite o número do aluno: ");
                scanf("%d", &numeroAluno);
                Aluno *aluno = buscarAluno(&pilhaAlunos, numeroAluno);
                if (aluno == NULL) {
                    printf("Aluno não encontrado!\n");
                } else {
                    float media = calcularMediaAluno(&filaNotas, numeroAluno);
                    printf("Aluno: %s\n", aluno->nome);
                    printf("Média: %.2f\n", media);
                }
                break;
            }
            case 4: {
                printf("Alunos sem notas:\n");
                for (int i = pilhaAlunos.topo; i >= 0; i--) {
                    int numero = pilhaAlunos.alunos[i].numero;
                    if (!alunoTemNotas(&filaNotas, numero)) {
                        printf("%s\n", pilhaAlunos.alunos[i].nome);
                    }
                }
                break;
            }
            case 5: {
                if (pilhaVazia(&pilhaAlunos)) {
                    printf("Pilha vazia, nenhum aluno para excluir.\n");
                } else {
                    int numeroTopo = pilhaAlunos.alunos[pilhaAlunos.topo].numero;
                    if (alunoTemNotas(&filaNotas, numeroTopo)) {
                        printf("O aluno no topo da pilha tem notas e não pode ser excluido.\n");
                    } else {
                        Aluno alunoRemovido;
                        desempilharAluno(&pilhaAlunos, &alunoRemovido);
                        printf("Aluno %s removido.\n", alunoRemovido.nome);
                    }
                }
                break;
            }
            case 6: {
                Nota notaRemovida;
                if (desenfileirarNota(&filaNotas, &notaRemovida)) {
                    printf("Nota removida: Aluno %d, Nota %.2f\n", notaRemovida.numeroAluno, notaRemovida.valorNota);
                } else {
                    printf("Fila de notas vazia, nenhuma nota para remover.\n");
                }
                break;
            }
            case 7:
                return 0;
            default:
                printf("Opção inválida!\n");
        }
    }
    return 0;
}
