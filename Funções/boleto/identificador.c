#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* obterNomeBanco(int codigo) {
    switch(codigo) {
        case 1:   return "Banco do Brasil";
        case 33:  return "Santander";
        case 104: return "Caixa Economica Federal";
        case 341: return "Itau";
        case 745: return "Citibank";
        default:  return "Banco nao identificado";
    }
}

void identificarBanco(char *linhaLimpa) {
    char extraido[4];
    strncpy(extraido, linhaLimpa, 3);
    extraido[3] = '\0';

    int codNumerico = atoi(extraido);
    printf("Banco: %s\n", obterNomeBanco(codNumerico));
}