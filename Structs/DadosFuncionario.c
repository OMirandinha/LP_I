#include <stdio.h>
#include <string.h>
#include <ctype.h> 

typedef struct {
    char nome[100];
    int idade;
    char sexo;
    char cpf[15];
    char nasc[11];
    int codSetor;
    char cargo[30];
    double salario;
} funcionario;

void Print_Struct(funcionario f) {
    printf("\n--- Dados do Funcionario ---");
    printf("\nNome: %s", f.nome);
    printf("\nIdade: %d", f.idade);
    printf("\nSexo: %c", f.sexo); 
    printf("\nCPF: %s", f.cpf);    
    printf("\nData de Nascimento: %s", f.nasc);
    printf("\nCodigo do Setor: %d", f.codSetor); 
    printf("\nCargo: %s", f.cargo);
    printf("\nSalario: R$ %.2lf\n", f.salario);
}

int main() {
    funcionario f; 

    printf("Digite o nome completo: ");
    scanf(" %[^\n]s", f.nome);

    printf("Digite a idade: ");
    scanf("%d", &f.idade);

    printf("Digite o sexo (M/F): ");
    scanf(" %c", &f.sexo); 

    printf("Digite o CPF: ");
    scanf("%s", f.cpf);

    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%s", f.nasc);

    printf("Digite o codigo do setor (0-99): ");
    scanf("%d", &f.codSetor);

    printf("Digite o cargo: ");
    scanf(" %[^\n]s", f.cargo);

    printf("Digite o salario: ");
    scanf("%lf", &f.salario); 
    Print_Struct(f);

    return 0;
}