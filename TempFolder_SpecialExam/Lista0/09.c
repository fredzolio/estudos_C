#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Num triângulo retângulo, segundo Pitágoras, o quadrado da hipotenusa (a) é igual a soma dos
quadrados dos catetos (b e c). Faça um algoritmo que recebe o valor dos catetos e imprime o valor da
hipotenusa.
*/

double hipotenusa(int a, int b){
    return (sqrt((a * a)+(b * b)));
}

int main(){
    int a, b;
    printf("INSIRA OS VALORES DO Cateto 1 e Cateto 2:\n");
    scanf("%d %d", &a, &b);
    printf("HIPOTENUSA: %.2lf\n", hipotenusa(a, b));

    return EXIT_SUCCESS;
}