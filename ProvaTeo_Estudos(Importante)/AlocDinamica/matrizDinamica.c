#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprimir(int **mat, int l, int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int **mat, l, c;
    printf("Informe o tamanho da matriz no formato: LINHA x COLUNA\n");
    scanf("%d %d", &l, &c);
    srand(time(NULL));
    //inicializar matriz
    mat = malloc(l * sizeof(int*));
    for(int i = 0; i < l; i++){
        mat[i] = malloc(c * sizeof(int));
    }
    //popula matriz com numeros
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            mat[i][j] = rand() % 100;
        }
    }
    
    //imprimir matriz
    imprimir(mat, l, c);

    return 0;
}