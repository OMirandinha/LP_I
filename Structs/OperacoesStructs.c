#include <stdio.h>

typedef struct{
	double w;
	double z;
}numeros;

typedef struct{
	double soma;
	double subtracao;
	double multiplicacao;
	double divisao;
}resultados;

void Operacoes(numeros num, resultados res){
	res.soma = num.w + num.z;
	res.subtracao = num.w - num.z;
	res.multiplicacao = num.w * num.z;
	res.divisao = num.w / num.z;
	
	printf("\nSoma: %.2lf || Subtração: %.2lf || Multiplicação: %.2lf || Divisão: %.2lf", res.soma, res.subtracao, res.multiplicacao, res.divisao);
	
}

int main(){
	numeros n;
	resultados r;
	
	printf("\nDigite o primeiro número real");
	scanf("%lf", &n.w);
	printf("\nDigite o segundo número real");
	scanf("%lf", &n.z);
	
	Operacoes(n, r);

}