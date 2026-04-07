#include <stdio.h>
#include <string.h>

int main() {
    char entrada[101];

    while (scanf("%s", entrada) != EOF) {
        int tamanho = strlen(entrada);

        // O loop 'i' controla as linhas do triângulo
        for (int i = 0; i < tamanho; i++) {
            
            // 1. Imprime os espaços iniciais da linha
            // Na linha 0 tem 0 espaços, na linha 1 tem 1 espaço, etc.
            for (int j = 0; j < i; j++) {
                printf(" ");
            }

            // 2. Imprime as letras da palavra
            // A cada linha 'i', imprimimos 'tamanho - i' letras
            for (int j = 0; j < tamanho - i; j++) {
                printf("%c", entrada[j]);
                
                // Só imprime espaço se NÃO for a última letra da linha
                if (j < tamanho - i - 1) {
                    printf(" ");
                }
            }

            // Pula para a próxima linha do triângulo
            printf("\n");
        }
        
        // 3. Imprime uma linha em branco após cada caso de teste
        printf("\n");
    }

    return 0;
}