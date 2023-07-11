#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    
    int **matriz_A, l_A, c_A;
    int **matriz_B, l_B, c_B;
    int **matriz_R;
    printf("INSIRA O TAMANHO DA MATRIZ A: (LINHAxCOLUNA)\n");
    scanf("%d %d", &l_A, &c_A);
    printf("INSIRA O TAMANHO DA MATRIZ B: (LINHAxCOLUNA)\n");
    scanf("%d %d", &l_B, &c_B);
    if(c_A != l_B){
        printf("AS COLUNAS DE A PRECISAM SER IGUAIS AS LINHAS DE B!\n");
        return 0;
    }
    //Declarando as linhas da minha matriz
    matriz_A = malloc(l_A * sizeof(int));
    matriz_B = malloc(l_B * sizeof(int));
    matriz_R = malloc(c_A * sizeof(int));

    //Declarando as colunas da minha matriz em um loop que percorre cada linha e aloca espaços para as colunas;
    for(int i = 0; i < l_A; i++){
        matriz_A[i] = malloc(c_A * sizeof(int));
    }
    for(int i = 0; i < l_B; i++){
        matriz_B[i] = malloc(c_B * sizeof(int));
    }
    for(int i = 0; i < c_A; i++){
        matriz_R[i] = malloc(l_B * sizeof(int));
    }

    //Populando matriz A com scanf
    for(int i = 0; i < l_A; i++){
        for(int j = 0; j < c_A; j++){
            printf("A[%d][%d]: ", i, j);
            int aux;
            scanf("%d", &aux);
            matriz_A[i][j] = aux;
        }
    }
    printf("\n");
    for(int i = 0; i < l_B; i++){
        for(int j = 0; j < c_B; j++){
            printf("B[%d][%d]: ", i, j);
            int aux;
            scanf("%d", &aux);
            matriz_B[i][j] = aux;
        }
    }
    printf("\n");
    //Lendo matriz
    printf("MATRIZ A -----\n");
    for(int i = 0; i < l_A; i++){
        for(int j = 0; j < c_A; j++){
            printf("%d ", matriz_A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("MATRIZ B -----\n");
    for(int i = 0; i < l_B; i++){
        for(int j = 0; j < c_B; j++){
            printf("%d ", matriz_B[i][j]);
        }
        printf("\n");
    }

    //Calculando a multiplicação
    for(int i = 0; i < l_A; i++){
        for(int j = 0; j < c_B; j++){
            int somaProd = 0;
            for(int k = 0; k < l_A; k++){
                somaProd += matriz_A[i][k] * matriz_B[k][j];
            }
            matriz_R[i][j] = somaProd;
        }
    }

    //Lendo matriz R
    printf("\n");
    printf("MATRIZ R -----\n");
    for(int i = 0; i < l_A; i++){
        for(int j = 0; j < c_B; j++){
            printf("%d ", matriz_R[i][j]);
        }
        printf("\n");
    }

    free(matriz_A);
    free(matriz_B);
    free(matriz_R);
    return 0;
}