#include <stdio.h>
#include "cripto.c"

int main()
{
	char texto1[9], texto2[9], texto3[9] ;
	printf( "Informe um texto de até 8 caracteres:" ) ;
	scanf( "%[^\n]", texto1 ) ;
	Cripto( texto1, texto2 ) ;
	Cripto( texto2, texto3 ) ;
	printf( "O texto criptografado é: \n%s\n e descriptografado é: \n%s\n", texto2, texto3 ) ;
	return 0 ;
}