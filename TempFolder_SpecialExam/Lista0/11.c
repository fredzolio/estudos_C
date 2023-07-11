#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Média de 4 numeros
*/

int main(){
    
    double a, b, c, d;
    printf("INSIRA 4 VALORES: (a b c d)\n");
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    double media = (a+b+c+d)/4;
    printf("A MEDIA DOS VALORES EH: %.2lf", media);

    return EXIT_SUCCESS;
}