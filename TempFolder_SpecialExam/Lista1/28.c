#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Leia um conjunto não determinado de pares de valores M e N (parar quando algum dos
valores for menor ou igual a zero). Para cada par lido, mostre a sequência do menor até o
maior e a soma dos inteiros consecutivos entre eles (incluindo o N e M).
Exemplos:
5 2 > 2 3 4 5 Soma=14
6 3 > 3 4 5 6 Soma=18
5 0 > Terminar o programa
*/

int main(){

    int a, b;
    do{
        int soma = 0;
        scanf("%d %d", &a, &b);
        if(a == 0 || b == 0){
            return 0;
        }
        if(a > b){
            int aux = a;
            a = b;
            b = aux;
        }
        for(int i = a; i <= b; i++){
            soma += i;
        }
        printf("SOMA: %d\n", soma);

    } while(a != 0 && b != 0);

    return EXIT_SUCCESS;
}