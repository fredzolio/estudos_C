#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Escreva um programa para determinar a quantidade de litros de combustível gastos em uma viagem
por um automóvel que faz 12 km/litro. Para isso, sabe-se que o tempo gasto na viagem é T=35 min e
a velocidade média do automóvel é V = 80 km/h.
*/

double gastoCombu(int tempo, int vm){
    double dist = (tempo*vm)/60;
    return (dist/12);
}

int main(){
    int tempo, vm;
    printf("INSIRA O TEMPO GASTO E A VELO. MEDIA DO VEICULO: (min km/h)\n");
    scanf("%d %d", &tempo, &vm);
    printf("O GASTO DE COMBUSTIVEL EM LITROS, FOI DE: %.2lf", gastoCombu(tempo, vm));

    return EXIT_SUCCESS;
}