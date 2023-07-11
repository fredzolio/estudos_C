#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que calcule o fatorial de um número. Se o número for menor do que zero, então o
programa deverá informar ao usuário que o valor é inválido.
*/

int main(){

    int num, aux = 0;
    scanf("%d", &num);
    if(num < 0){
        printf("Valor invalido!!\n");
        return EXIT_FAILURE;
    }
    for(int i = num - 1; i > 0; i--){
        num *= i;
    }
    printf("FATORIAL =  %d\n", num);

    return EXIT_SUCCESS;
}