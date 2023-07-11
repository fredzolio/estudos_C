#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
O número 2520 é divisível (resto zero) por todos números inteiros de 1 a 10. Faça um programa, em
linguagem C, que encontre o menor número inteiro positivo divisível por todos os inteiros de 1 a 20.
Resposta: 232792560
*/

int main(){

    long int num = 1;
    while (1){
        if(num % 1 == 0 && num % 2 == 0 && num % 3 == 0 && num % 4 == 0 && num % 5 == 0 && num % 6 == 0 && num % 7 == 0 && num % 8 == 0 && num % 9 == 0 && num % 10 == 0 && num % 11 == 0 && num % 12 == 0 && num % 13 == 0 && num % 14 == 0 && num % 15 == 0 && num % 16 == 0 && num % 17 == 0 && num % 18 == 0 && num % 19 == 0 && num % 20 == 0)
            break;
        else
            num++;
    }
    printf("\n%ld\n", num);
    

    return EXIT_SUCCESS;
}