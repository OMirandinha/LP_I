#include <stdio.h>
#include <stdbool.h>

#define TAM 10

typedef struct {
    int inicio;
    int Dados[TAM];
    int Aux[TAM];
} ListaEncadeadaComVetor;

// Inicializa a lista configurando todos os espaços como livres (-1)
void inicializaLista(ListaEncadeadaComVetor *L) {
    L->inicio = -1; // -1 no início indica lista vazia
    for (int i = 0; i < TAM; i++) {
        L->Aux[i] = -1; // -1 no Aux indica posição livre
    }
}

// Busca a posição do primeiro espaço livre no vetor Aux
int achaPosLivre(ListaEncadeadaComVetor L) {
    for (int i = 0; i < TAM; i++) {
        if (L.Aux[i] == -1) return i;
    }
    return -1; // Lista cheia
}

// Busca a posição do último elemento percorrendo a lista a partir do 'inicio'
int achaPosUltimo(ListaEncadeadaComVetor L) {
    if (L.inicio == -1) return -1;
    int pos = L.inicio;
    while (L.Aux[pos] != -2) {
        pos = L.Aux[pos];
    }
    return pos;
}

// Insere um dado no primeiro espaço livre, mas o encadeia no final da lista
int insereDado(ListaEncadeadaComVetor *L, int D) {
    int livre = achaPosLivre(*L);
    
    if (livre == -1) return 0; // Não há espaço

    L->Dados[livre] = D;
    L->Aux[livre] = -2; // Novo elemento será o último

    if (L->inicio == -1) {
        // Se a lista estava vazia, este é o primeiro
        L->inicio = livre;
    } else {
        // Se não, encontra o último e aponta para o novo
        int ultimo = achaPosUltimo(*L);
        L->Aux[ultimo] = livre;
    }
    return 1;
}

// Remove um elemento procurando pelo valor
int removeDado(ListaEncadeadaComVetor *L, int D) {
    if (L->inicio == -1) return 0;

    int atual = L->inicio;
    int anterior = -1;

    while (atual != -2) {
        if (L->Dados[atual] == D) {
            // Se for o primeiro da lista
            if (anterior == -1) {
                // Se era o único elemento
                if (L->Aux[atual] == -2) L->inicio = -1;
                else L->inicio = L->Aux[atual];
            } else {
                // Se estiver no meio ou fim, o anterior pula o atual
                L->Aux[anterior] = L->Aux[atual];
            }
            
            L->Aux[atual] = -1; // Marca posição como livre no vetor
            return 1;
        }
        anterior = atual;
        atual = L->Aux[atual];
        if (atual == -2) break;
    }
    return 0; // Não encontrou
}

void imprimeLista(ListaEncadeadaComVetor L) {
    if (L.inicio == -1) {
        printf("Lista Vazia.\n");
        return;
    }
    
    int pos = L.inicio;
    printf("Lista: ");
    while (pos != -2) {
        printf("%d (pos:%d)", L.Dados[pos], pos);
        pos = L.Aux[pos];
        if (pos != -2) printf(", ");
    }
    printf("\n");
}

int main() {
    ListaEncadeadaComVetor minhaLista;
    inicializaLista(&minhaLista);

    // Teste de inserção
    insereDado(&minhaLista, 9);
    insereDado(&minhaLista, 10);
    insereDado(&minhaLista, 11);
    insereDado(&minhaLista, 1);
    insereDado(&minhaLista, 34);

    imprimeLista(minhaLista);

    // Teste de remoção
    int valor;
    printf("\nQual elemento deseja remover? ");
    scanf("%d", &valor);

    if (removeDado(&minhaLista, valor)) {
        printf("Removido com sucesso!\n");
    } else {
        printf("Valor nao encontrado.\n");
    }

    imprimeLista(minhaLista);

    return 0;
}