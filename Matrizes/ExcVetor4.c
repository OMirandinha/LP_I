/*O número de lâmpadas necessárias para cada cômodo de uma casa é determinado pela
potência mínima de iluminação exigida por metro quadrado, conforme a classe de
utilização do cômodo. Imagine que essas classes são identificadas por inteiros de 1 a 5
e que a potência mínima exigida (em Watts) por metro quadrado para cada classe de
cômodo é dada pela seguinte tabela:

Classe 		Watts/m2
1 			10
2 			15
3 			18
4 			20
5 			25

Supondo que só serão usadas lâmpadas de 60W, elabore um programa que calcule e
mostre:

Para cada cômodo:
- A área do cômodo
- A potência da iluminação
- O número de lâmpadas necessárias

Para toda a residência:
- O total de lâmpadas
- O total de potência de iluminação

Observe que o número de cômodos da residência, a classe de cada cômodo e suas
dimensões (em metros) devem ser solicitados pelo usuário */

#include <stdio.h>

int main(){
	  int tabWatts[5][2] = {
        {1, 10},
        {2, 15},
        {3, 18},
        {4, 20},
        {5, 25}
    };
    
	int numComodos, classe, largura, altura, areaComododo, areaComodo, lampadasComodo, totLampadas, potencia, potenciaComodo, potenciaTotal;
	
	totLampadas = 0;
	potenciaTotal = 0;
	
	printf("Digite o total de cômodos na sua casa:\n");
	scanf("%d", &numComodos);
	
	for(int i = 0; i < numComodos; i++){
		lampadasComodo = 0;
		potenciaComodo = 0;
		
		printf("Digite os dados do cômodo %d:\n", i+1);
		printf("Classe: \n");
		scanf("%d", &classe);
		
		printf("altura: (em metros)\n");
		scanf("%d", &altura);
		
		printf("largura: (em metros)\n");
		scanf("%d", &largura);
		
		 // Buscando a potência na matriz baseado na classe
        if(classe >= 1 && classe <= 5){
            for(int j = 0; j < 5; j++){
                if(tabWatts[j][0] == classe){
                    potencia = tabWatts[j][1];
                    break;
                }
            }
        } else {
            printf("Classe inválida! Usando classe 1 como padrão.\n");
            potencia = tabWatts[0][1];  // classe 1 como padrão
        }
		
		areaComodo = altura * largura;
		printf("A área do cômodo %d é %d\n", i+1, areaComodo);
		
		potenciaComodo = areaComodo * potencia;
		printf("A potência total do cômodo é %d watts \n", potenciaComodo);
		
		lampadasComodo = potenciaComodo / 60;
		printf("O total de lâmpadas do cômodo é %d", lampadasComodo);
		
		totLampadas += lampadasComodo;
		potenciaTotal += potenciaComodo;
	}
	
	printf("O total de lâmpadas para a sua residência será %d\n", totLampadas);
	printf("E a potencia total será %d watts\n", potenciaTotal);
	
	return 0;

}