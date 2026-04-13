/*  Elaborar um programa que leia dois valores inteiros (A e B). Em seguida fac¸a uma func¸˜ ao
queretorne a soma do dobro dos doi sn´umeros lidos. Afunc¸˜ ao dever´ a armazenar o dobro
de A na pr´ opria vari´ avel A e o dobro de B na pr´ opria vari´ avel B */

#include <stdio.h>

int SomaDobro(int *a, int *b){
	*a = *a * 2;
	*b = *b * 2;
	
	return(*a + *b);
}

int main(){
		int a, b;
		printf("Digite dois valores inteiros: ");
		scanf("\n%i", &a);
		scanf("\n%i", &b);
		
		int resultado = SomaDobro(&a, &b);
		
		printf("\nNovo valor de a: %i", a);
		printf("\nNovo valor de b: %i", b);
		printf("\nSoma dos dobros: %i", resultado);

		

}