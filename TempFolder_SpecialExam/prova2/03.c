#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

void ler(int matriz[][4]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void remRep(int matriz[][4]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            for(int k = i + 1; i < 3; i++){
                if(matriz[i][j] == matriz[i][j + 1]){
                    matriz[i][j + 1] = rand() % 13;
                }
                for(int z = j + 1; j < 4; j++){
                    if(matriz[i][j] == matriz[k][z]){
                        matriz[k][z]= rand() % 13;
                    }
                }
            }
        }
    }
}

int main(){

    srand(time(NULL));
    int matriz[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            matriz[i][j] = rand() % 13;
        }
    }
    ler(matriz);
    remRep(matriz);
    printf("\n");
    ler(matriz);

    return EXIT_SUCCESS;
}