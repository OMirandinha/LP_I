#include <stdio.h>

int main() {
    int N;
    int elementos[1000];
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &elementos[i]);
    }
    
    int total = 1; 
    int diff_anterior = elementos[1] - elementos[0];
    
    
    for(int i = 1; i < N-1; i++) {
        int diff_atual = elementos[i+1] - elementos[i];
        
        
        if(diff_atual != diff_anterior) {
            total++;
            diff_anterior = diff_atual;
        }
       
    }
    
    printf("%d\n", total);
    
    return 0;
}