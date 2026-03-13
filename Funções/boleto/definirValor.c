#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void processarValor(char *linhaLimpa) {
    int tam = strlen(linhaLimpa);
    char strValor[11];
    
    // Pega os últimos 10 caracteres
    strncpy(strValor, &linhaLimpa[tam - 10], 10);
    strValor[10] = '\0';

    double valorOriginal = atof(strValor) / 100.0;
    double multa = valorOriginal * 0.10;
    double valorFinal = valorOriginal + multa;

    printf("Valor Original: R$ %.2f\n", valorOriginal);
    printf("Multa (10%%): R$ %.2f\n", multa);
    printf("Total c/ Multa: R$ %.2f\n", valorFinal);
}