#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main () {
    int **mat, i, j;
    mat = malloc(4 * sizeof(int*)); //4 linhas;
    for (i = 0; i < 4; i++){ 
        mat[i] = malloc(3 * sizeof(int)); //Cria um loop para colocar dinamicamente mais espaço dentro de cada linha, no caso 3 colunas
    }
    srand(time(NULL));
    for (i = 0; i < 4; i++){
        for (j = 0; j < 3; j++){
            mat[i][j] = rand() % 100;
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}