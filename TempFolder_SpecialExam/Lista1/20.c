#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Qual o menor número inteiro entre 1 e 10000 que possui a maior quantidade de divisores?
Quantos e quais são os divisores? Implemente um programa para encontrar a resposta.
Resposta: menor número 7560 com 64 divisores. Exiba os divisores.
*/

int main(){

    int divisores = 0, menor = 0, aux = 0;
    for(int i = 10000; i > 0; i--){
        for(int j = 1; j < 10000; j++){
            if(i % j == 0)
                aux++;
        }
        if(aux >= divisores){
            divisores = aux;
            menor = i;
        }
        aux = 0;
    }

    printf("MENOR: %d\nDIVISORES: %d\n", menor, divisores);

    return EXIT_SUCCESS;
}