#include <stdio.h>
#include <string.h>

#include "identificador.c"
#include "definirValor.c"
#include "limparLinha.c"


void limparLinha(char *entrada, char *saida);
void identificarBanco(char *linhaLimpa);
void processarValor(char *linhaLimpa);

int main() {
    char entrada[100];
    char linhaLimpa[100];

    while (1) {
        printf("\nDigite a linha digitavel (ou 'FIM' para sair):\n");
        fgets(entrada, 100, stdin);
        entrada[strcspn(entrada, "\n")] = 0; // Remove o enter

        if (strcmp(entrada, "FIM") == 0 || strcmp(entrada, "fim") == 0) {
            break;
        }

        limparLinha(entrada, linhaLimpa);

        if (strlen(linhaLimpa) < 13) {
            printf("Erro: Linha muito curta!\n");
            continue;
        }

        identificarBanco(linhaLimpa);
        processarValor(linhaLimpa);
        
        printf("------------------------------------------\n");
    }

    printf("Programa encerrado.\n");
    return 0;
}