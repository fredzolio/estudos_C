#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que solicite ao usuário dois números inteiros diferentes “n1” e “n2” e calcule a
soma de todos os números ímpares dentro do intervalo definidor por [n1,...,n2]. Considere que n1 é
sempre menor do que n2.
*/

int main(){

    int n1, n2, soma = 0;
    printf("INSIRA DOIS VALORES, N1 E N2:\n");
    scanf("%d %d", &n1, &n2);
    for(int i = n1; i <= n2; i++){
        if(i % 2 != 0){
            soma+= i;
        }
    }
    printf("SOMA: %d", soma);

    return EXIT_SUCCESS;
}