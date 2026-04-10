/* Escreva um programa que contenha duas variaveis inteiras. Leia essas vari ´ aveis do ´
teclado. Em seguida, compare seus enderec¸os e exiba o conteudo do maior enderec¸o. */

#include <stdio.h>

int main() {
    int n1, n2;
    scanf("%i", &n1);
    scanf("%i", &n2);

    int *p1 = &n1, *p2 = &n2;

    if (p1 > p2) {
        printf("%i\n", *p1); 
    } else {
        printf("%i\n", *p2);
    }
    return 0;
}