#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que calcule a multiplicação de 2 números inteiros sem utilizar o operador “*”.
Em vez disso, utilize apenas o operador de adição “+”.
*/

int main(){

    int valor1, valor2, aux = 0;
    scanf("%d %d", &valor1, &valor2);
    for(int i = 0; i < valor2; i++){
        aux += valor1;
    }
    printf("\nRESULTADO:\n%d", aux);


    return EXIT_SUCCESS;
}