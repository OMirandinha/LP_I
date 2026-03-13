#include <string.h>

void substituir(char strArquivo[50]) {
    int tam = strlen(strArquivo);

    for (int i = tam - 1; i >= 0; i--) {
        if (strArquivo[i] == '.') {
            strcpy(&strArquivo[i], ".gif");
            break;
        }
    }
}