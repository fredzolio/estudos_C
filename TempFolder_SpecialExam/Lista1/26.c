#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que solicita ao usuário um valor A e um valor N. Imprimir a soma dos N
números a partir de A(inclusive). Enquanto N for negativo ou ZERO, um novo N(apenas N)
deve ser lido.
*/

int main(){

    int a, n;
    scanf("%d %d", &a, &n);
    while (n <= 0){
        scanf("%d", &n);
    }
    int x = a;
    for(int i = 0; i < n; i++){
        a += x;
    }
    printf("%d", a);
    

    return EXIT_SUCCESS;
}