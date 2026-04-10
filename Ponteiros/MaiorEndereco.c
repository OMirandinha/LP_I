/* Escreva um programa que contenha duas variaveis inteiras. Compare seus enderec¸os e ´
exiba o maior enderec¸o. */

#include <stdio.h>

int main() {
    int n1 = 10, n2 = 20;
    int *p1 = &n1;   // p1 aponta para n1
    int *p2 = &n2;   // p2 aponta para n2

    // Comparando os endereços armazenados nos ponteiros
    if (p1 > p2) {
        printf("Maior endereço: %p\n", (void*)p1);
    } else {
        printf("Maior endereço: %p\n", (void*)p2);
    }

    return 0;
}