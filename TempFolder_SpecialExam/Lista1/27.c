#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Na matemática, um número perfeito é um número inteiro para o qual a soma de todos os
seus divisores positivos próprios (excluindo ele mesmo) é igual ao próprio número. Por
exemplo o número 6 é perfeito, pois 1+2+3 é igual a 6. Sua tarefa é escrever um programa
que imprima se um determinado número é perfeito ou não.
Exemplos:
6 → perfeito
5 → nao é perfeito
28 → é perfeito
*/

int main(){

    int soma = 0, num; 
    scanf("%d", &num);
    for(int i = num - 1; i > 0; i--){
        if(num % i == 0){
            soma += i;
        }
    }
    if(soma == num){
        printf("%d PERFEITO", num);
    }else{
        printf("%d NAO EH PERFEITO", num);
    }

    return EXIT_SUCCESS;
}