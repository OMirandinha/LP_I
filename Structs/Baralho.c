#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *naipe;
    char *valor;
} Carta;

typedef struct {
    char nome[50];
    Carta mao[5];
} Jogador;

void inicializar_baralho(Carta baralho[]);
void embaralhar(Carta baralho[]);
void distribuir_cartas(Carta baralho[], Jogador *j1, Jogador *j2);
void exibir_mao(Jogador j);

int main() {
    Carta baralho[52];
    Jogador jogador1 = {"Jogador 1"};
    Jogador jogador2 = {"Jogador 2"};

    srand(time(NULL));

    inicializar_baralho(baralho);
    embaralhar(baralho);
    distribuir_cartas(baralho, &jogador1, &jogador2);

    printf("--- DISTRIBUICAO DE CARTAS ---\n\n");
    exibir_mao(jogador1);
    printf("\n");
    exibir_mao(jogador2);

    return 0;
}

void inicializar_baralho(Carta baralho[]) {
    char *naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};
    char *valores[] = {"As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Dama", "Rei"};

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            baralho[k].naipe = naipes[i];
            baralho[k].valor = valores[j];
            k++;
        }
    }
}

void embaralhar(Carta baralho[]) {
    for (int i = 51; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }
}

void distribuir_cartas(Carta baralho[], Jogador *j1, Jogador *j2) {
    for (int i = 0; i < 5; i++) {
        j1->mao[i] = baralho[i];
        j2->mao[i] = baralho[i + 5];
    }
}

void exibir_mao(Jogador j) {
    printf("Mao do %s:\n", j.nome);
    for (int i = 0; i < 5; i++) {
        printf("[%d] %s de %s\n", i + 1, j.mao[i].valor, j.mao[i].naipe);
    }
}