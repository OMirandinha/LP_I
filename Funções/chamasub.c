#include <stdio.h>
#include "Funcao.c"

int main(){
    char str1[21], str2[21];
    int inicio, fim, i, j;

    printf("Informe uma string \n");
    scanf("%[^\n]", str1);

    printf("\nInforme o início: ");
    scanf("%i", &inicio);

    printf("\nInforme o fim: ");
    scanf("%i", &fim);

    substring(str1, str2, inicio, fim);

    printf("\nSub: %s", str2);
}
