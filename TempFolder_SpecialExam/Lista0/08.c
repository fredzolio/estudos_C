#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/*
Faça um programa que recebe dois valores na variáveis A e B e, em seguida, troca o conteúdo destas
variáveis. Por exemplo, se o usuário digitar A=5 e B=3, o programa deverá trocar os valores de tal
maneira que A seja igual a 3 e B igual a 5.
*/

int main(){

    int A, B, aux;
    printf("DIGITE O VALOR DE A E B:\nformato -- > (A B) \n");
    scanf("%d %d", &A, &B);
    aux = A;
    A = B;
    B = aux;
    printf("A: %d\nB: %d", A, B);

    return EXIT_SUCCESS;
}