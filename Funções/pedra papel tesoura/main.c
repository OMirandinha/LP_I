#include <stdio.h>
#include "jogo.c"

int main(){
	int partidas;
	char jogador1[20], jogador2[20];
	
	printf("Quantas partidas deseja realizar? \n");
	scanf("%i", &partidas);
	
	jogo(partidas, jogador1, jogador2);

}
