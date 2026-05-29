#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func-sub.c"

// Criar as seguintes funcionalidades

   // 1-Mostrar todas as faturas ordenadas por nome de produto
   // Criar função que ordene por nome (por inserção)
   // Criar função que mostre as faturas (uma fatura por linha)

   // 2- Realizar pesquisa binária por número de fatura. Criar função
   // que peça ao usuário um número de fatura para pesquisa. Caso encontre,
   // mostrar os dados encontrados, senão emitir mensagem de erro.
   // Criar função para pesquisa binária

   // 3- Pesquisar uma fatura e mostrar todos os seus produtos.
   // Criar função para realizar uma pesquisa sequencial

typedef struct fatura
{
    int numFatura;
    int codProduto;
    char nomeProduto[32];
    int qtde;
    double vrunit;
    double vrfrete;
    int codforn;
} Fatura;

int LeArquivo(Fatura *vetor)
{
    char linha[200];
    char aux[40];
    FILE *arq;
    Fatura vfatura;
    int qtde = 0;

    arq = fopen("fatura.txt","r");

    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        return -1;
    }

    fgets(linha,200,arq);

    while(!feof(arq))
    {
        substr(linha,aux,1,5);
        vfatura.numFatura = atoi(aux);

        substr(linha,aux,5,7);
        vfatura.codProduto = atoi(aux);

        substr(linha,aux,8,40);
        strcpy(vfatura.nomeProduto,rtrim(aux));

        substr(linha,aux,41,44);
        vfatura.qtde = atoi(aux);

        substr(linha,aux,45,54);
        vfatura.vrunit = atoi(aux)/100.0;

        substr(linha,aux,55,64);
        vfatura.vrfrete = atoi(aux)/100.0;

        substr(linha,aux,65,68);
        vfatura.codforn = atoi(aux);

        vetor[qtde] = vfatura;
        qtde++;

        fgets(linha,200,arq);
    }

    fclose(arq);
    return qtde;
}

void MostrarFaturas(Fatura *vetor, int qtde)
{
    int i;

    for(i=0;i<qtde;i++)
    {
        printf("%d | %d | %s | %d | %.2lf | %.2lf | %d\n",
               vetor[i].numFatura,
               vetor[i].codProduto,
               vetor[i].nomeProduto,
               vetor[i].qtde,
               vetor[i].vrunit,
               vetor[i].vrfrete,
               vetor[i].codforn);
    }
}

void OrdenarInsercao(Fatura *vetor, int qtde)
{
    int i, j;
    Fatura chave;

    for(i=1;i<qtde;i++)
    {
        chave = vetor[i];
        j = i-1;

        while(j>=0 && strcmp(vetor[j].nomeProduto, chave.nomeProduto) > 0)
        {
            vetor[j+1] = vetor[j];
            j--;
        }

        vetor[j+1] = chave;
    }
}

void PesquisaBinaria(Fatura *vetor, int qtde)
{
    int numero;
    int inicio=0, fim=qtde-1, meio;

    printf("\nDigite numero da fatura: ");
    scanf("%d",&numero);

    while(inicio<=fim)
    {
        meio = (inicio+fim)/2;

        if(vetor[meio].numFatura == numero)
        {
            printf("\nFATURA ENCONTRADA\n");

            printf("%d | %d | %s | %d | %.2f | %.2f | %d\n",
                   vetor[meio].numFatura,
                   vetor[meio].codProduto,
                   vetor[meio].nomeProduto,
                   vetor[meio].qtde,
                   vetor[meio].vrunit,
                   vetor[meio].vrfrete,
                   vetor[meio].codforn);

            return;
        }

        if(numero < vetor[meio].numFatura)
            fim = meio-1;
        else
            inicio = meio+1;
    }

    printf("\nFatura nao encontrada!\n");
}

void PesquisaSequencial(Fatura *vetor, int qtde)
{
    int numero;
    int i, encontrou=0;

    printf("\nDigite numero da fatura: ");
    scanf("%d",&numero);

    printf("\nProdutos da fatura %d:\n",numero);

    for(i=0;i<qtde;i++)
    {
        if(vetor[i].numFatura == numero)
        {
            encontrou = 1;

            printf("%s | Qtde:%d | Valor: %.2lf\n",
                   vetor[i].nomeProduto,
                   vetor[i].qtde,
                   vetor[i].vrunit);
        }
    }

    if(!encontrou)
        printf("Fatura nao encontrada!\n");
}

int main()
{
    Fatura vetorFatura[20];
    int qtde;

    qtde = LeArquivo(vetorFatura);

    printf("\n--- Faturas Ordenadas por Produto ---\n");

    OrdenarInsercao(vetorFatura, qtde);
    MostrarFaturas(vetorFatura, qtde);

    printf("\n--- Pesquisa Binaria ---\n");
    PesquisaBinaria(vetorFatura, qtde);

    printf("\n--- Pesquisa Sequencial ---\n");
    PesquisaSequencial(vetorFatura, qtde);

    return 0;
}
