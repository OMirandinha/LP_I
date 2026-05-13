#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Adicionado para toupper()

struct Horario{
	int hora;
	int minutos;
	int segundos;
};

typedef struct{
	int dia;
	int mes;
	int ano;
} Data;

struct Compromisso{
	char compromisso[100];
	char dataComp[15];
	char horarioComp[15];
};

int main(){
	struct Horario h;
	Data d;
	struct Compromisso c;
	
	char res;
	while (1){
		printf("\nDeseja adicionar um compromisso? (S/N)");
		scanf(" %c", &res);
		
		  if (toupper(res) != 'S') {
			printf("\nPrograma finalizado");
			return 1;
		}
		
		printf("\nDigite a data do compromisso: ");
		scanf("%d %d %d", &d.dia, &d.mes, &d.ano);
		
		sprintf(c.dataComp, "%d/%d/%d", d.dia, d.mes, d.ano);
        
        printf("\nDigite o horário do compromisso: ");
		scanf("%d %d %d", &h.hora, &h.minutos, &h.segundos);
		
		sprintf(c.horarioComp, "%d:%d:%d", h.hora, h.minutos, h.segundos);
		
		
		printf("\n Qual é o compromisso?");
		getchar();  
		fgets(c.compromisso, sizeof(c.compromisso), stdin);
		
		printf("%s", c.compromisso);
		printf(" foi agendado para às %s de %s", c.horarioComp, c.dataComp);
	}
}