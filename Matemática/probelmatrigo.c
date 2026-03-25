#include <stdio.h>
#include <math.h>

int main() {
	int casos, tabuleiro;
    unsigned long long kg; 
    
    scanf("%i", &casos);

    for(int i = 0; i < casos; i++) {
        scanf("%d", &tabuleiro);
        kg = pow(2, tabuleiro) / 12000;
        
        printf("%llu kg\n", kg);
    }
    
    return 0;
}