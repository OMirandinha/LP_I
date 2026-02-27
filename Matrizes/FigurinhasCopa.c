#include <stdio.h>

int main(){
    int N, M, C;
    int i, j, totFigurinhas;
    int X[100];  // carimbadas
    int Y[300];  // compradas
    
    scanf("%d %d %d", &N, &C, &M);
    
    // Lê as figurinhas carimbadas
    for(i = 0; i < C; i++){
        scanf("%d", &X[i]);
    }
    
    // Lê as figurinhas compradas
    for(i = 0; i < M; i++){
        scanf("%d", &Y[i]);
    }
    
    // Inicialmente, todas as carimbadas faltam
    totFigurinhas = C;
    
    // Para cada figurinha carimbada
    for(i = 0; i < C; i++){
        // Verifica se ela está entre as compradas
        for(j = 0; j < M; j++){
            if(X[i] == Y[j]){
                totFigurinhas--;  // Encontrou uma carimbada
                break;            // Para de procurar esta figurinha
            }
        }
    }
    
    printf("%d\n", totFigurinhas);
    
    return 0;
}