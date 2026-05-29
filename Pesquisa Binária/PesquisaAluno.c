#include <stdio.h>
#include <string.h>

#define TAM 6

// 1) Estrutura Aluno
struct Aluno {
    int ra;
    char nome[50];
    int faltas;
    float nota;
};

// 2) Função OrdenaPorNome (Bubble Sort)
void ordenaPorNome(struct Aluno alunos[], int n) {
    struct Aluno temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compara as strings dos nomes
            if (strcmp(alunos[j].nome, alunos[j + 1].nome) > 0) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

// Função auxiliar para ordenar por RA (necessário para a Pesquisa Binária)
void ordenaPorRA(struct Aluno alunos[], int n) {
    struct Aluno temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (alunos[j].ra > alunos[j + 1].ra) {
                temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

// 3) Função Calcula Média
float calculaMedia(struct Aluno alunos[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i].nota;
    }
    return soma / n;
}

// 4) Função Pesquisa Binária
int pesquisaBinaria(struct Aluno alunos[], int n, int raPesquisado) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (alunos[meio].ra == raPesquisado) {
            return meio; // Retorna o índice se encontrado
        } else if (alunos[meio].ra < raPesquisado) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Retorna -1 se não encontrado
}

void exibirAlunos(struct Aluno alunos[], int n) {
    printf("\n--- Lista de Alunos ---\n");
    for (int i = 0; i < n; i++) {
        printf("RA: %d | Nome: %-15s | Nota: %.2f | Faltas: %d\n", 
               alunos[i].ra, alunos[i].nome, alunos[i].nota, alunos[i].faltas);
    }
}

int main() {
    struct Aluno turma[TAM];
    int i, raBusca, resultadoBusca;

    // Entrada de dados
    printf("Cadastro de %d alunos:\n", TAM);
    for (i = 0; i < TAM; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("RA: ");
        scanf("%d", &turma[i].ra);
        getchar(); // Limpar buffer do teclado
        printf("Nome: ");
        fgets(turma[i].nome, 50, stdin);
        turma[i].nome[strcspn(turma[i].nome, "\n")] = 0; // Remove o \n do fgets
        printf("Faltas: ");
        scanf("%d", &turma[i].faltas);
        printf("Nota: ");
        scanf("%float", &turma[i].nota);
    }

    // Ordenação por Nome e exibição
    ordenaPorNome(turma, TAM);
    printf("\nAlunos ordenados por NOME:");
    exibirAlunos(turma, TAM);

    // Média da turma
    printf("\nMedia Geral da Turma: %.2f\n", calculaMedia(turma, TAM));

    // Pesquisa Binária (necessita ordenar por RA primeiro)
    printf("\nDigite um RA para pesquisar: ");
    scanf("%d", &raBusca);
    
    ordenaPorRA(turma, TAM); // Preparando para a pesquisa binária
    resultadoBusca = pesquisaBinaria(turma, TAM, raBusca);

    if (resultadoBusca != -1) {
        printf("Aluno encontrado!\n");
        printf("Nome: %s | Nota: %.2f | Faltas: %d\n", 
               turma[resultadoBusca].nome, 
               turma[resultadoBusca].nota, 
               turma[resultadoBusca].faltas);
    } else {
        printf("Aluno com RA %d nao encontrado.\n", raBusca);
    }

    return 0;
}