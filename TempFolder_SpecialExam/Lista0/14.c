#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que leia dois números inteiros e determine qual dos dois é maior. Considere que
os dois números serão diferentes.
*/

int main(){
    
    int maior, a, b;
    printf("INSIRA O VALOR DE A E B: (a b)\n");
    scanf("%d %d", &a, &b);
    if(a > b)
        maior = a;
    else 
        maior = b;
    printf("MAIOR: %d", maior);
    
    return EXIT_SUCCESS;
}