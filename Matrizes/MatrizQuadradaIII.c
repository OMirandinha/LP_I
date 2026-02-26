#include <stdio.h>

int main(){
    int N;
    
    while(1){
        scanf("%d", &N);
        
        if(N == 0){
            break;
        }
        
        int mat[N][N];
        mat[0][0] = 1;  
        
        // Preenche a primeira linha
        for(int j = 1; j < N; j++) {
            mat[0][j] = mat[0][j-1] * 2; 
        }
        
        // Preenche o resto da matriz
        for(int i = 1; i < N; i++) {
            for(int j = 0; j < N; j++) {
                mat[i][j] = mat[i-1][j] * 2;  
            }
        }
        
        // Calcula o maior valor (canto inferior direito)
        int maiorValor = mat[N-1][N-1];
        
        // Calcula quantos dígitos tem o maior valor (T)
        int T = 1;
        int temp = maiorValor;
        while(temp >= 10) {
            temp /= 10;
            T++;
        }
        
        // Imprime a matriz
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(j > 0) {
                    printf(" ");
                }
                printf("%*d", T, mat[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    
    return 0;
}