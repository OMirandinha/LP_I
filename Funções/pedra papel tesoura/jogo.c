#include <stdio.h>

void jogo(int partidas, char *jogador1, char *jogador2){
	for(int i = 0; i < partidas; i++){
		printf("Rodada n° %i\n", i+1);
		
		printf("jogador 1: \n");
		scanf("%s", jogador1);
		
		printf("Jogador 2: \n");
		scanf("%s", jogador2);
		
			 if (strcmp(jogador1, jogador2) == 0) {
            printf("Resultado: Empate!\n");
        } 
        else if ((strcmp(jogador1, "pedra") == 0 && strcmp(jogador2, "tesoura") == 0) ||
                 (strcmp(jogador1, "tesoura") == 0 && strcmp(jogador2, "papel") == 0) ||
                 (strcmp(jogador1, "papel") == 0 && strcmp(jogador2, "pedra") == 0)) {
            
            printf("Resultado: Jogador 1 venceu!\n");
        } 
        else {
            printf("Resultado: Jogador 2 venceu!\n");
        }
	}
}