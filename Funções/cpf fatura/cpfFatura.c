#include <stdio.h>
#include <string.h>
#include <ctype.h> 

void extrair_cpf(char *dadosCliente, char *dadosFormatados) {
    int i, j = 0;
    // Percorre a string até o fim ou até achar 11 dígitos
    for (i = 0; *(dadosCliente + i) != '\0'; i++) {
        if (isdigit(*(dadosCliente + i)) && j < 11) {
            *(dadosFormatados + j) = *(dadosCliente + i);
            j++;
        }
    }
    *(dadosFormatados + j) = '\0'; // Finaliza a string do CPF
}

double calcularSomaFaturas(char *dadosCliente) {
    int i, j = 0;
    double somaTotal = 0, valorAtual = 0;

    // 1. Primeiro pulamos os 11 dígitos do CPF
    for (i = 0; *(dadosCliente + i) != '\0' && j < 11; i++) {
        if (isdigit(*(dadosCliente + i))) {
            j++;
        }
    }

    // 2. Agora processamos o que restou para somar as faturas
    for (; *(dadosCliente + i) != '\0'; i++) {
        if (isdigit(*(dadosCliente + i))) {
            // Monta o número (ex: se ler '1' e depois '2', vira 12)
            valorAtual = (valorAtual * 10) + (*(dadosCliente + i) - '0');
        } 
        else if (*(dadosCliente + i) == '.') {
            // Se achar o ponto, pega os 2 próximos dígitos como centavos
            double centavos = (*(dadosCliente + i + 1) - '0') * 0.10;
            centavos += (*(dadosCliente + i + 2) - '0') * 0.01;
            
            somaTotal += valorAtual + centavos;
            valorAtual = 0; // Reinicia para a próxima fatura
            i += 2;         // Pula os dígitos dos centavos que já lemos
        }
    }
    
    // Soma qualquer valor que sobrou no final (faturas sem centavos)
    return somaTotal + valorAtual;
}

int main() {
    int totCliente;
    char dadosCliente[61], cpf[12];
    
    // Lê a quantidade de clientes
    if (scanf("%d", &totCliente) != 1) return 0;
    
    for (int i = 0; i < totCliente; i++) {
        scanf("%s", dadosCliente);
        
        extrair_cpf(dadosCliente, cpf);
        double soma = calcularSomaFaturas(dadosCliente);
        
        // Exibe o CPF e a soma com duas casas decimais
        printf("CPF: %s Soma: %.2f\n", cpf, soma);
    }

    return 0;
}