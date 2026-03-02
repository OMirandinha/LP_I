#include <stdio.h>

int main() {
    int N;
    char linha[15]; // Array para armazenar cada linha
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%s", linha); // Lê a linha inteira
        
        int n1 = (linha[2] - '0') * 10 + (linha[3] - '0');           // posições 2 e 3: "23" do exemplo
        int n2 = (linha[5] - '0') * 100 + (linha[6] - '0') * 10 + (linha[7] - '0'); // posições 5-7: "249" do exemplo
        int n3 = (linha[11] - '0') * 10 + (linha[12] - '0');         // posições 11-12: "21" do exemplo
        
        int resultado = n1 + n2 + n3;
        
        printf("%d\n", resultado);
    }
    
    return 0;
}
