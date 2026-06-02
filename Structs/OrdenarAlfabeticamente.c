#include <stdio.h>
#include <string.h> 

typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[20];
} Pessoas; 

void Ordenar(Pessoas p[5]) {
    int i, j;
    Pessoas temp;

    for (i = 0; i < 5 - 1; i++) {
        for (j = 0; j < 5 - i - 1; j++) {
            // Compara os nomes
            if (strcmp(p[j].nome, p[j+1].nome) > 0) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

int main() {
    Pessoas p[5]; 
    int i;


    for (i = 0; i < 5; i++) {
        printf("\n--- Dados da %d° Pessoas ---", i + 1);
        printf("\nNome: ");
        scanf(" %[^\n]s", p[i].nome);
        
        printf("Endereco: ");
        scanf(" %[^\n]s", p[i].endereco);
        
        printf("Telefone: ");
        scanf(" %[^\n]s", p[i].telefone);
    }

    Ordenar(p);

    printf("\n\n--- Lista Ordenada por Nome ---");
    for (i = 0; i < 5; i++) {
        printf("\nNome: %-15s | Endereco: %-15s | Tel: %-10s", 
                p[i].nome, p[i].endereco, p[i].telefone);
    }

    printf("\n");
    return 0;
}