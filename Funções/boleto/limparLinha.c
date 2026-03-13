#include <ctype.h>

void limparLinha(char *entrada, char *saida) {
    int j = 0;
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (isdigit(entrada[i])) {
            saida[j] = entrada[i];
            j++;
        }
    }
    saida[j] = '\0';
}