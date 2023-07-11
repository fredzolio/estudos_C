#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Os números naturais menores do que 10 e múltiplos de 3 ou 5 são: 3, 5, 6 e 9. A soma destes
múltiplos é 23. Faça um programa que encontre a soma de todos os múltiplos de 3 ou 5 menores do
que 1000.
Resposta: 233168
*/

int main(){

    int soma = 0;
    for(int i = 0; i < 1000; i++){
        if(i % 3 == 0 || i % 5 == 0){
            soma += i;
        }
    }
    printf("%d", soma);

    return EXIT_SUCCESS;
}