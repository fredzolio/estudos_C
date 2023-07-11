//Usando Realloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main() {

    int vet[] = {3, 6, 14, 1, -55, 53, -12, 19, 22, 4, 6};
    int tam = (sizeof(vet) / sizeof(int)), *menor;
    menor = (vet + tam - 1);
    while (tam != 0){
        if(*menor > *(menor - tam)){
        menor--;
        }
        tam--;
    }
    printf("O menor numero eh: %d\n", *menor);
    return 0;
}