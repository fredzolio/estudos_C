#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void trocaValores(int **x, int **y, int **z){
    int temp;
        if (*(*x) > *(*y)) {
        temp = *(*x);
        *(*x) = *(*y);
        *(*y) = temp;
        }

        if (*(*y) > *(*z)) {
            temp = *(*y);
            *(*y) = *(*z);
            *(*z) = temp;
        }

        if (*(*x) > *(*y)) {
            temp = *(*x);
            *(*x) = *(*y);
            *(*y) = temp;
        }

}


int main(){
    
    srand(time(NULL));
    int *x, *y, *z;
    x = calloc(1, sizeof(int));
    y = calloc(1, sizeof(int));
    z = calloc(1, sizeof(int));
    *x = rand() % 100;
    *y = rand() % 100;
    *z = rand() % 100;

    printf("VALORES ANTES:\nx = %d\ny = %d\nz = %d\n", *x, *y, *z);
    printf("------------------");
    trocaValores(&x, &y, &z);
    printf("\nVALORES DEPOIS:\nx = %d\ny = %d\nz = %d\n", *x, *y, *z);
    return 0;
}