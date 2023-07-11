#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define M 4
#define N 3

/*
Implemente um programa que preenche com valores aleatórios uma matriz MxN e:
    1. armazena em um vetor v1 o maior elemento cadastrado em cada coluna da matriz;
    2. armazena em um vetor v2 o menor elemento cadastrado em cada coluna da matriz;
Ao final, o programa deve exibir: a matriz original, o vetor dos maiores elementos e o vetor dos
menores elementos.
Obs.:
Os valores de M e N devem ser definidos por meio da diretiva “#define”
Você pode utilizar no máximo dois comandos “for” para encontrar os menores e maiores elementos das colunas.
A solução deve ser implementada no programa principal (“main”), sem utilizar funções.
*/

int main(){

    srand(time(NULL));
    int matriz[M][N];
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            matriz[i][j] = rand() % 100;
        }
    }

    int vMaior[1][N];
    int vMenor[1][N];
    vMaior[0][0] = matriz[0][0];
    vMenor[0][0] = matriz[0][0];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(matriz[i][j] > vMaior[0][j])
                vMaior[0][j] = matriz[i][j];
            if(matriz[i][j] < vMenor[0][j])
                vMenor[0][j] = matriz[i][j];
        }
    }

    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(int i = 0; i < N; i++){
        printf("%d ", vMaior[0][N]);
    }

    printf("\n");

    for(int i = 0; i < N; i++){
        printf("%d ", vMenor[0][N]);
    }

    return EXIT_SUCCESS;
}