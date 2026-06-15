#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct No {
    int chave;
    struct No *esquerda;
    struct No *direita;
};

// Função para criar um novo nó
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->chave = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Função para inserir um valor na árvore (necessário para testar a busca)
struct No* inserir(struct No* no, int valor) {
    // Se a árvore estiver vazia, retorna um novo nó
    if (no == NULL) return criarNo(valor);

    // Caso contrário, percorre a árvore
    if (valor < no->chave)
        no->esquerda = inserir(no->esquerda, valor);
    else if (valor > no->chave)
        no->direita = inserir(no->direita, valor);

    return no;
}

// FUNÇÃO DE PESQUISA
struct No* buscar(struct No* raiz, int alvo) {
    // Caso base: raiz é nula ou a chave está presente na raiz
    if (raiz == NULL || raiz->chave == alvo)
        return raiz;

    // Se o valor alvo for maior que a chave da raiz, busca na direita
    if (alvo > raiz->chave)
        return buscar(raiz->direita, alvo);

    // Se o valor alvo for menor que a chave da raiz, busca na esquerda
    return buscar(raiz->esquerda, alvo);
}

int main() {
    struct No* raiz = NULL;
    int valorBusca;

    // Criando uma árvore de exemplo
    //       50
    //      /  \
    //     30   70
    //    /  \ /  \
    //   20  40 60  80
    raiz = inserir(raiz, 50);
    inserir(raiz, 30);
    inserir(raiz, 20);
    inserir(raiz, 40);
    inserir(raiz, 70);
    inserir(raiz, 60);
    inserir(raiz, 80);

    printf("Digite um valor para buscar na árvore: ");
    scanf("%d", &valorBusca);

    struct No* resultado = buscar(raiz, valorBusca);

    if (resultado != NULL) {
        printf("Elemento %d encontrado na árvore!\n", resultado->chave);
    } else {
        printf("Elemento %d não encontrado.\n", valorBusca);
    }

    return 0;
}