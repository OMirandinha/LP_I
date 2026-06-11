#include <stdio.h>
#include <string.h>

// Primeira estrutura para a data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Segunda estrutura que contém a primeira
typedef struct {
    char texto[61];
    Data d; // Struct aninhada
} Compromisso;

int main() {
    Compromisso agenda[5];
    int M, A;

    // 1. Leitura dos 5 compromissos
    for (int i = 0; i < 5; i++) {
        printf("\n--- Cadastro do Compromisso %d ---", i + 1);
        
        printf("\nDescricao (max 60 letras): ");
        scanf(" %[^\n]", agenda[i].texto);
        
        printf("Digite a data (dia mes ano separados por espaco): ");
        // Note que acessamos agenda[i].d.dia (vetor.struct_compromisso.struct_data.variavel)
        scanf("%d %d %d", &agenda[i].d.dia, &agenda[i].d.mes, &agenda[i].d.ano);
    }

    // 2. Loop de pesquisa
    do {
        printf("\n--- Pesquisa de Compromissos ---");
        printf("\nDigite o mes (M) e o ano (A) para buscar (ou 0 no mes para sair): ");
        scanf("%d", &M);

        if (M == 0) {
            break; // Sai do loop imediatamente
        }

        scanf("%d", &A);

        printf("\nCompromissos encontrados em %02d/%d:", M, A);
        int encontrou = 0;

        for (int i = 0; i < 5; i++) {
            if (agenda[i].d.mes == M && agenda[i].d.ano == A) {
                printf("\n-> %02d/%02d/%d: %s", 
                        agenda[i].d.dia, agenda[i].d.mes, agenda[i].d.ano, agenda[i].texto);
                encontrou = 1;
            }
        }

        if (!encontrou) {
            printf("\nNenhum compromisso agendado para este periodo.");
        }
        
        printf("\n");

    } while (M != 0);

    printf("\nPrograma encerrado.\n");

    return 0;
}