#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    int num;
    char matricula[10];  
    char curso[100];
} aluno;

void EntradaDados(aluno a[], int tamanho){        
    for(int i = 0; i < tamanho; i++){
        printf("\n--- Aluno %d ---", i+1);
        
        while(getchar() != '\n');
        
        printf("\nDigite o nome do aluno %d: ", i+1);
        fgets(a[i].nome, 100, stdin);
        a[i].nome[strcspn(a[i].nome, "\n")] = 0;
        
        printf("\nDigite o número do aluno: ");
        scanf("%d", &a[i].num);
        
        printf("\nDigite a matrícula do aluno: ");
        while(getchar() != '\n');
        fgets(a[i].matricula, 10, stdin);
        a[i].matricula[strcspn(a[i].matricula, "\n")] = 0;
        
        printf("\nDigite o curso do aluno: ");
        fgets(a[i].curso, 100, stdin);
        a[i].curso[strcspn(a[i].curso, "\n")] = 0;
    }
}

int main(){
    aluno a[5];
    
    EntradaDados(a, 5);
    
    printf("\n\n=== Dados dos Alunos ===\n");
    for(int i = 0; i < 5; i++){
        printf("\n--- Aluno %d ---", i+1);
        printf("\nNome: %s", a[i].nome);
        printf("\nNúmero: %d", a[i].num);
        printf("\nMatrícula: %s", a[i].matricula); 
        printf("\nCurso: %s\n", a[i].curso);
    }
    
    return 0;
}