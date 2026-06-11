#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    char endereco[100];
    char nasc[15];
    char cidade[50];
    char cep[15];
    char email[100];
} Dados;

int validarEmail(char email[]) {
    if (strchr(email, '@')) return 1;
    return 0;
}

int validarCEP(char cep[]) {
    if (strlen(cep) >= 8) return 1;
    return 0;
}

int validarData(char data[]) {
    if (strlen(data) == 10 && data[2] == '/' && data[5] == '/') return 1;
    return 0;
}

int main() {
    Dados d;
    int erro = 0;

    printf("Nome: ");
    scanf(" %[^\n]s", d.nome);

    printf("Endereco: ");
    scanf(" %[^\n]s", d.endereco);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", d.nasc);

    printf("Cidade: ");
    scanf(" %[^\n]s", d.cidade);

    printf("CEP: ");
    scanf("%s", d.cep);

    printf("Email: ");
    scanf("%s", d.email);

    printf("\n--- Resultado ---\n");

    if (!validarData(d.nasc)) {
        printf("A data de nascimento esta errada.\n");
        erro = 1;
    }

    if (!validarCEP(d.cep)) {
        printf("O CEP esta errado.\n");
        erro = 1;
    }

    if (!validarEmail(d.email)) {
        printf("O email esta errado.\n");
        erro = 1;
    }

    if (erro == 0) {
        printf("Todas as informacoes estao corretas!\n");
        printf("Nome: %s\nEndereco: %s\nNascimento: %s\nCidade: %s\nCEP: %s\nEmail: %s\n", 
                d.nome, d.endereco, d.nasc, d.cidade, d.cep, d.email);
    } else {
        printf("Algumas informacoes precisam ser corrigidas.\n");
    }

    return 0;
}