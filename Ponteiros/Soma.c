/*  Crie um programa que contenha uma func¸˜ ao que permita passar por parˆ ametro dois
n´umeros inteiros A e B. A func¸˜ ao dever´ a calcular a soma entre estes dois n´umeros e
armazenar o resultado na vari´ avel A. Esta func¸˜ ao n˜ ao dever´ a possuir retorno, mas dever´ a
modificar o valor do primeiro par˜ ametro. Imprima os valores de A e B na func¸˜ ao principal. */

#include <stdio.h>

void Soma(int *val1, int *val2){
	*val1 += *val2;
}

int main(){
	int a, b;
	
	printf("Digite dois valores inteiros");
	scanf("\n%i", &a);
	scanf("\n%i", &b);
	
	Soma(&a, &b);
	
	printf("\nNovo valor de A: %i", a);
	printf("\nvalor de B: %i", b);
}