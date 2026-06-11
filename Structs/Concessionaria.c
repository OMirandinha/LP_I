#include <stdio.h>

typedef struct {
    char marca[16];
    int ano;
    double preco;
} Carro;

void Filtrar(Carro c[], double orcamento) {
    int encontrou = 0;
    for(int i = 0; i < 5; i++) {
        if(c[i].preco <= orcamento) {
            printf("\nCarro %d -> Marca: %s | Ano: %d | Preco: %.2f", i + 1, c[i].marca, c[i].ano, c[i].preco);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("\nNenhum carro encontrado nessa faixa de preco.");
    }
    printf("\n");
}

int main() {
    Carro c[5];
    double p;

    for(int i = 0; i < 5; i++) {
        printf("Digite a marca do carro %d: ", i + 1);
        scanf("%s", c[i].marca);
        
        printf("Digite o ano do carro %d: ", i + 1);
        scanf("%d", &c[i].ano);
        
        printf("Digite o preco do carro %d: ", i + 1);
        scanf("%lf", &c[i].preco);
        printf("\n");
    }

    do {
        printf("\nDigite um valor de orcamento (ou 0 para sair): ");
        scanf("%lf", &p);

        if (p > 0) {
            Filtrar(c, p);
        }

    } while (p != 0);

    return 0;
}