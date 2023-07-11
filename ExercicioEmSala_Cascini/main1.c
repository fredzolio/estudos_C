//Outro exercicio anterior ao exercicio que fiz em main.c

/* 

1. [ ] Crie um programa que multiplica duas matrizes quadradas do tipo double lidas do teclado. 
2. [ ] Seu programa deve ler a dimensão n da matriz, em seguida alocar dinamicamente duas matrizes n × n. 
3. [ ] Depois ler os dados das duas matrizes e imprimir a matriz resultante da soma destas.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


int main () {

    srand(time(NULL));
    double **mat1, **mat2;
    int n, i, j, k;
    puts("Insira o tamanho das matrizes:");
    scanf("%d", &n);
    const int N = n; 
    //Cria matriz 1:
    mat1 = malloc(n * sizeof(double));
    for(i = 0; i < n; i++){
        mat1[i] = malloc(n * sizeof(double));
    }
    //Cria matriz 2:
    mat2 = malloc(n * sizeof(double));
    for(i = 0; i < n; i++){
        mat2[i] = malloc(n * sizeof(double));
    }
    //Popula matriz 1:
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat1[i][j]
        }
    }
    //Popula matriz 2:
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("MATRIZ 2 -> Valor de a[%d][%d]: ", i, j);
            scanf("%lf", &mat2[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d", mat1[i][j]);
        }
        printf("\n");
    }
    //printf("\t");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d", mat2[i][j]);
        }
        printf("\n");
    }
    //Faz mat1 x mat2:
    /* double **matRes;
    matRes = malloc(n * sizeof(double));
    for(i = 0; i < n; i++){
        matRes[i] = malloc(n * sizeof(double));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matRes[i][j] = 0;
            for(k = 0; k < n; k++){
                matRes[i][j] = matRes[i][j] + (mat1[i][k]*mat2[k][j]);
            }
        }
    }

    //Imprime as matrizes:
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\t");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d", mat2[i][j]);
        }
        printf("\n");
    }
    printf("\t");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d", matRes[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}