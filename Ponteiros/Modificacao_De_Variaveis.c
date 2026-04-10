/*Escreva um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real, e char. Associe as variaveis aos ponteiros (use &). Modifique os valores de ´
cada variavel usando os ponteiros. Imprima os valores das vari ´ aveis antes e ap ´ os a ´
modificac¸ao. */

#include <stdio.h>

int main(){
	//Declaração de variáveis e ponteiros
	int num = 7, *pn = &num;
	float real = 9.75, *pr = &real;
	char caracter = 'D', *pd = &caracter;
	
	printf("\n%i", num);
	printf("\n%.2f", real);
	printf("\n %c", caracter);
	
	//Modificando através dos ponteiros 
	*pn += 4;
	*pr -= 3;
	*pd = 'R'; 
	
	printf("\n%i", num);
	printf("\n%.2f", real);
	printf("\n %c", caracter);
}