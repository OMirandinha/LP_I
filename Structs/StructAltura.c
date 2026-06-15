#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int mes;
    int ano;
    int dia;
} Data;

typedef struct {
    char nome[100];
    double altura;
    Data d;
} Pessoa;

void CriaData(Data *D) {
    D->mes = 1 + (rand() % 12);
    D->ano = 1950 + (rand() % 50); 
    D->dia = 1 + (rand() % 30);
}

void Listardados(Pessoa *p) {
    printf("\n--- LISTAGEM DE TODOS OS DADOS ---\n");
    for(int i = 0; i < 10; i++) {
        printf("Nome: %-15s | Altura: %.2lf | Data: %02d/%02d/%d\n", 
                p[i].nome, p[i].altura, p[i].d.dia, p[i].d.mes, p[i].d.ano);
    }
}

void PesquisarAntesData(Pessoa *p, Data limite) {
    int encontrou = 0;
    printf("\n--- PESSOAS QUE NASCERAM ANTES DE %02d/%02d/%d ---\n", limite.dia, limite.mes, limite.ano);
    
    for(int i = 0; i < 10; i++) {
        if (p[i].d.ano < limite.ano || 
           (p[i].d.ano == limite.ano && p[i].d.mes < limite.mes) || 
           (p[i].d.ano == limite.ano && p[i].d.mes == limite.mes && p[i].d.dia < limite.dia)) {
            
            printf("Nome: %-15s | Data: %02d/%02d/%d\n", p[i].nome, p[i].d.dia, p[i].d.mes, p[i].d.ano);
            encontrou = 1;
        }
    }
    
    if (!encontrou) {
        printf("Nenhuma pessoa encontrada nascida antes desta data.\n");
    }
}

int main() {
    srand(time(NULL));

    Pessoa p[10];
    Data dataBusca;
    
    for(int i = 0; i < 10; i++) {
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", p[i].nome);
        
        printf("Digite a altura: ");
        scanf("%lf", &p[i].altura);
        
        CriaData(&p[i].d);
    }
    
    Listardados(p);

    printf("\n--- PESQUISA ---\n");
    printf("Digite uma data limite para busca (dia mes ano): ");
    scanf("%d %d %d", &dataBusca.dia, &dataBusca.mes, &dataBusca.ano);

    PesquisarAntesData(p, dataBusca);

    return 0;
}