#include <stdio.h>
#include <stdlib.h>

// Função de pesquisa binária
int pesquisaBinaria(int arr[], int esquerda, int direita, int alvo) {
    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        
        // Verifica se o elemento do meio é o alvo
        if (arr[meio] == alvo)
            return meio;
        
        // Se o alvo for maior, ignora a metade esquerda
        if (arr[meio] < alvo)
            esquerda = meio + 1;
        // Se o alvo for menor, ignora a metade direita
        else
            direita = meio - 1;
    }
    
    // Elemento não encontrado
    return -1;
}

// Função para ler números de um arquivo
int* lerArquivo(const char* nomeArquivo, int* tamanho) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return NULL;
    }
    
    // Primeiro, conta quantos números estão no arquivo
    int capacidade = 10;
    int* numeros = (int*)malloc(capacidade * sizeof(int));
    *tamanho = 0;
    
    while (fscanf(arquivo, "%d", &numeros[*tamanho]) == 1) {
        (*tamanho)++;
        
        // Se necessário, aumenta o array dinamicamente
        if (*tamanho >= capacidade) {
            capacidade *= 2;
            numeros = (int*)realloc(numeros, capacidade * sizeof(int));
            if (numeros == NULL) {
                printf("Erro de alocação de memória\n");
                fclose(arquivo);
                return NULL;
            }
        }
    }
    
    fclose(arquivo);
    return numeros;
}

// Função para ordenar o array (necessário para pesquisa binária)
void ordenarArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    const char* nomeArquivo = "dados.txt";
    int tamanho = 0;
    int* numeros = lerArquivo(nomeArquivo, &tamanho);
    
    if (numeros == NULL || tamanho == 0) {
        printf("Não foi possível ler os dados do arquivo\n");
        return 1;
    }
    
    printf("Números lidos do arquivo: ");
    imprimirArray(numeros, tamanho);
    
    // Ordena o array (necessário para pesquisa binária)
    ordenarArray(numeros, tamanho);
    printf("Array ordenado: ");
    imprimirArray(numeros, tamanho);
    
    // Realiza a pesquisa binária
    int alvo;
    printf("\nDigite o número que deseja buscar: ");
    scanf("%d", &alvo);
    
    int resultado = pesquisaBinaria(numeros, 0, tamanho - 1, alvo);
    
    if (resultado != -1) {
        printf("Elemento %d encontrado na posição %d do array ordenado!\n", alvo, resultado);
    } else {
        printf("Elemento %d não encontrado no array!\n", alvo);
    }
    
    free(numeros);
    return 0;
}