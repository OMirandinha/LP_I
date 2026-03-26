#include <stdio.h>
#include <string.h>

int main() {
    int n, i;
    char palavra[21]; // Máximo de 20 caracteres + '\0'

    // Lê a quantidade de palavras
    if (scanf("%d", &n) != 1) return 0;

    for (i = 0; i < n; i++) {
        // Lê cada palavra individualmente
        scanf("%s", palavra);

        // Verifica se a palavra tem exatamente 3 letras
        if (strlen(palavra) == 3) {
            // Se começar com "OB", a última letra vira 'I'
            if (palavra[0] == 'O' && palavra[1] == 'B') {
                palavra[2] = 'I';
            }
            // Se começar com "UR", a última letra vira 'I'
            else if (palavra[0] == 'U' && palavra[1] == 'R') {
                palavra[2] = 'I';
            }
        }

        // Imprime a palavra corrigida (ou original)
        // Adiciona um espaço se não for a última palavra, caso contrário pula linha
        if (i < n - 1) {
            printf("%s ", palavra);
        } else {
            printf("%s\n", palavra);
        }
    }

    return 0;
}