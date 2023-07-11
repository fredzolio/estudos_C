#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que leia um número inteiro de 4 dígitos e escreva-o invertido. Por exemplo, se o
número lido for 2548, o resultado será 8452. Dica: utilize o comando “ % ” que retorna resto da
divisão entre 2 números inteiros.
*/

int main(){
    
    int numero;
    scanf("%d", &numero);
    int dig1 = numero % 10;
    numero /= 10;
    int dig2 = numero % 10;
    numero /= 10;
    int dig3 = numero % 10;
    numero /= 10;
    int dig4 = numero % 10;
    printf("%d%d%d%d", dig1, dig2, dig3, dig4);

    return EXIT_SUCCESS;
}