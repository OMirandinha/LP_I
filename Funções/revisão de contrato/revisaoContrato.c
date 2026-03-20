#include <stdio.h>
#include <string.h>
#include "extrair.c" // Inclui o código da outra lógica

int main() {
    char numDigit;        // O dígito com defeito (um char)
    char numContrato[105]; // O número original (string)
    char corrigido[105];   // O número após a limpeza (string)

    while (1) {
        if (scanf(" %c %s", &numDigit, numContrato) != 2) break;

        // Condição de parada (D=0 e N=0)
        if (numDigit == '0' && strcmp(numContrato, "0") == 0) {
            break;
        }

        // Chama a função passando apenas os nomes dos arrays
        extrair(numDigit, numContrato, corrigido);

        // Trata o valor numérico (zeros à esquerda e vazio)
        if (corrigido[0] == '\0') {
            // Se a string ficou vazia
            printf("0\n");
        } else {
            // Remove zeros à esquerda
            int k = 0;
            // Enquanto for zero e não for o último caractere, pula
            while (corrigido[k] == '0' && corrigido[k + 1] != '\0') {
                k++;
            }
            printf("%s\n", &corrigido[k]);
        }
    }

    return 0;
}