#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça uma função que receba os endereços de memória de três números inteiros X, Y e Z e troque
os seus valores de forma que, ao retornar, o valor em X seja o menor, o valor em Y seja o
intermediário e o valor em Z seja o maior dos três. Faça também uma função main para testar a sua
função.
*/

void troca(int *x, int *y, int *z){
    int temp;
    if(*x > *y){
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if(*y > *z){
        temp = *y;
        *y = *z;
        *z = temp;
    }
    if(*x > *y){
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

int main(){

    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("(X): %d\n(Y): %d\n(Z): %d\n", x, y, z);
    int *ptr_x, *ptr_y, *ptr_z;
    ptr_x = &x;
    ptr_y = &y;
    ptr_z = &z;
    troca(ptr_x, ptr_y, ptr_z);
    printf("MENOR (X): %d\nMEIO (Y): %d\nMAIOR (Z): %d\n", x, y, z);


    return EXIT_SUCCESS;
}