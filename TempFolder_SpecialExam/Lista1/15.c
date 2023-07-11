#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Cada novo termo da sequência de Fibonacci é gerado pela adição dos 2 termos anteriores. Ao iniciar
a sequência com 1 e 2, os dez primeiros termos são: 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, … Faça um
programa que encontre a soma dos números pares da sequência de Fibonacci cujo termo não exceda
4 milhões.
Resposta: 4613732
*/


int main(){
    
    long int fibo[4000000];
    int somaPar = 0;
    fibo[0] = 0;
    fibo[1] = 1;
    for(long int i = 2; i < 4000000; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
        printf("\n%ld\n", fibo[i]);
    }
    
    for(long int i = 0; i < 4000000; i++){
        if(fibo[i] % 2 == 0){
            somaPar += fibo[i];
        }
    }
    printf("\n%d\n", somaPar);

    return EXIT_SUCCESS;
}