#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char matricula[20];
    double mediaFinal;
} Aluno;

void Separar(Aluno listaTotal[10]) {
    Aluno aprovados[10];
    Aluno reprovados[10];
    int contA = 0;
    int contR = 0;

    for(int i = 0; i < 10; i++) {
        if(listaTotal[i].mediaFinal >= 5.0) {
            aprovados[contA] = listaTotal[i];
            contA++;
        } else {
            reprovados[contR] = listaTotal[i];
            contR++;
        }
    }

    printf("\n--- ALUNOS APROVADOS ---");
    for(int i = 0; i < contA; i++) {
        printf("\nNome: %-15s | Matricula: %-10s | Media: %.2f", 
               aprovados[i].nome, aprovados[i].matricula, aprovados[i].mediaFinal);
    }

    printf("\n\n--- ALUNOS REPROVADOS ---");
    for(int i = 0; i < contR; i++) {
        printf("\nNome: %-15s | Matricula: %-10s | Media: %.2f", 
               reprovados[i].nome, reprovados[i].matricula, reprovados[i].mediaFinal);
    }
    printf("\n");
}

int main() {
    Aluno a[10];

    for(int i = 0; i < 10; i++) {
        printf("\nDigite os dados do aluno %d: ", i + 1);
        printf("\nNome: ");
        scanf(" %[^\n]s", a[i].nome);
        printf("Matricula: ");
        scanf("%s", a[i].matricula);
        printf("Media Final: ");
        scanf("%lf", &a[i].mediaFinal);
    }

    Separar(a);

    return 0;
}