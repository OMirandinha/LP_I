#include <stdio.h>
#include <string.h>  
typedef struct{
    char nome[100];
    char matricula[100];
    double p1;     
    double p2;    
    double p3;     
    double media;  
} aluno;

void Aprovado(double media){
    if(media >= 6)
        printf("APROVADO");
    else
        printf("REPROVADO");
}

void MaiorMenor(aluno a[], int tamanho){
    double maiorP1 = a[0].p1;
    double maiorMedia = a[0].media;
    double menorMedia = a[0].media;
    
    for(int i = 1; i < tamanho; i++){
        if(a[i].p1 > maiorP1)
            maiorP1 = a[i].p1;
        if(a[i].media > maiorMedia)
            maiorMedia = a[i].media;
        if(a[i].media < menorMedia)
            menorMedia = a[i].media;
    }
    
    printf("\n\n=== RESULTADOS DA TURMA ===");
    printf("\nMaior nota da P1: %.2f", maiorP1);
    printf("\nMaior média da turma: %.2f", maiorMedia);
    printf("\nMenor média da turma: %.2f", menorMedia);
}

void Entrada(aluno a[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\n\n--- Aluno %d ---", i+1);
        
        while(getchar() != '\n');
        
        printf("Digite o nome do aluno: ");
        fgets(a[i].nome, 100, stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = 0;
        
        printf("Digite a matrícula do aluno: ");
        fgets(a[i].matricula, 100, stdin);
        a[i].matricula[strcspn(a[i].matricula, "\n")] = 0;
        
        printf("Digite a nota da primeira prova: ");
        scanf("%lf", &a[i].p1);
        
        printf("Digite a nota da segunda prova: ");
        scanf("%lf", &a[i].p2);
        
        printf("Digite a nota da terceira prova: ");
        scanf("%lf", &a[i].p3);
        
        a[i].media = (a[i].p1 + a[i].p2 + a[i].p3) / 3;
        
        printf("\nMédia: %.2f - ", a[i].media);
        Aprovado(a[i].media);
    }
}

int main(){
    aluno a[5];
	
    Entrada(a, 5);
    
    MaiorMenor(a, 5);
    
    printf("\n\n=== RELATÓRIO FINAL ===\n");
    for(int i = 0; i < 5; i++){
        printf("\nAluno: %s", a[i].nome);
        printf("\nMatrícula: %s", a[i].matricula);
        printf("\nNotas: %.2f, %.2f, %.2f", a[i].p1, a[i].p2, a[i].p3);
        printf("\nMédia: %.2f - ", a[i].media);
        Aprovado(a[i].media);
        printf("\n------------------------");
    }
    
    return 0;
}