#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que solicita ao usuário 10 valores inteiros. Apresente o maior
valor lido e a posição dentre os 10 valores lidos.
*/

typedef struct no{
    int valor;
    int posicao;
}no;

int main(){

    int vetor[10];
    for(int i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }
    no diff;
    diff.valor = vetor[0];
    diff.posicao = 0;
    for(int i = 0; i < 10; i++){
        if(vetor[i] > diff.valor){
            diff.valor = vetor[i];
            diff.posicao = i;
        }
    }
    printf("MAIOR VALOR: %d\nPOSICAO NO VETOR: %d\n", diff.valor, diff.posicao);
    return EXIT_SUCCESS;
}