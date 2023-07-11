#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que leia dois inteiros: X e Z (devem ser lidos tantos valores para Z
quantos necessários, até que seja digitado um valor maior do que X para ele). Conte quantos
números inteiros devem ser somados em sequência (considerando o X nesta soma) para que
a soma ultrapasse a Z o mínimo possível. Escreva o valor final da contagem.

A entrada pode conter, por exemplo, os valores 21 21 15 30. Neste caso, é então assumido o
valor 21 para X enquanto os valores 21 e 15 devem ser desconsiderados pois são menores ou
iguais a X. Como o valor 30 está dentro da especificação (maior do que X) ele será válido e
então devese processar os cálculos para apresentar na saída o valor 2, pois é a quantidade
de valores somados para se produzir um valor maior do que 30 (21 + 22).
Exemplo para teste:
3 1 20 → 5
*/

int main(){

    int x, z;
    scanf("%d", &x);
    do{
        scanf("%d", &z);
    }while(z < x || z == x);
    int soma = x, aux = 1;
    for(int i = x; soma < z; i++){
        soma += i;
        aux++;
    }
    printf("\nSAIDA: %d\n", aux);

    return EXIT_SUCCESS;
}