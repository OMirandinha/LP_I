#include <stdio.h>

void extrair(char digito, char *num, char *corrigido) {
    int j = 0;
    
    // Percorre a string original até o fim (\0)
    for (int i = 0; num[i] != '\0'; i++) {
        // Se o dígito atual não for o defeituoso, copia para o novo array
        if (num[i] != digito) {
            corrigido[j] = num[i];
            j++;
        }
    }
    
    corrigido[j] = '\0';
}