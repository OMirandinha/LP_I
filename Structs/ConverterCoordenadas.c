#include <stdio.h>
#include <math.h>

typedef struct {
    double raio;
    double argumento;
} coordenadaPolar;

typedef struct {
    double x;
    double y;
} coordenadaCartesiana;

void Converter(coordenadaPolar c) {
    coordenadaCartesiana final;
    
    final.x = c.raio * cos(c.argumento);
    final.y = c.raio * sin(c.argumento);
    
    printf("\nAs coordenadas (r: %.2f, theta: %.2f rad) em polares sao (x: %.2f, y: %.2f) em cartesianas.\n", 
            c.raio, c.argumento, final.x, final.y);
}

int main() {
    coordenadaPolar c1;
    
    printf("Digite o raio e argumento (em radianos) da coordenada polar: ");
    
    scanf("%lf %lf", &c1.raio, &c1.argumento);
    
    Converter(c1);

    return 0; 
}