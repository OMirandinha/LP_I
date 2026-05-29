#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 100

// 1) Estrutura Aluno
typedef struct {
    int ra;
    char nome[50];
    float nota;
} Aluno;

// 2) Função de Ordenação (Bubble Sort por RA)
// Necessário ordenar pelo RA para que a Pesquisa Binária funcione
void ordenarPorRA(Aluno alunos[], int n) {
    Aluno temp;
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

// 3) Função de Pesquisa Binária
int pesquisaBinaria(Aluno alunos[], int n, int raBusca) {
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (alunos[meio].ra == raBusca) {
            return meio; // Encontrou
        }
        if (alunos[meio].ra < raBusca) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Não encontrado
}

int main() {
    Aluno turma[MAX_ALUNOS];
    int totalAlunos = 0;
    FILE *arquivo;

    // 4) Leitura de Arquivo
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo 'alunos.txt'!\n");
        printf("Certifique-se de que o arquivo existe na pasta do programa.\n");
        return 1;
    }

    // Lendo os dados formatados (RA, Nome, Nota)
    // O formato %[^,] lê tudo até encontrar uma vírgula
    while (fscanf(arquivo, "%d,%[^,],%f\n", 
           &turma[totalAlunos].ra, 
           turma[totalAlunos].nome, 
           &turma[totalAlunos].nota) != EOF) {
        totalAlunos++;
    }
    fclose(arquivo);

    printf("Arquivo carregado com sucesso! %d alunos lidos.\n", totalAlunos);

    // Ordenar é obrigatório antes da pesquisa binária
    ordenarPorRA(turma, totalAlunos);

    // Menu simples
    int opcao, raProcurado;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Listar alunos (Ordenados por RA)\n");
        printf("2. Pesquisar Aluno por RA\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            printf("\nRA\t%-15s\tNota\n", "Nome");
            for (int i = 0; i < totalAlunos; i++) {
                printf("%d\t%-15s\t%.2f\n", turma[i].ra, turma[i].nome, turma[i].nota);
            }
        } 
        else if (opcao == 2) {
            printf("Digite o RA para busca: ");
            scanf("%d", &raProcurado);
            
            int indice = pesquisaBinaria(turma, totalAlunos, raProcurado);
            
            if (indice != -1) {
                printf("\nALUNO ENCONTRADO:\n");
                printf("Nome: %s\nNota: %.2f\n", turma[indice].nome, turma[indice].nota);
            } else {
                printf("\nAluno com RA %d nao encontrado.\n", raProcurado);
            }
        }
    } while (opcao != 0);

    return 0;
}