#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    
    srand(time(NULL));
    int **matriz, l, c;
    printf("INSIRA O TAMANHO DA MATRIZ: (LINHAxCOLUNA)\n");
    scanf("%d %d", &l, &c);
    //Declarando as linhas da minha matriz
    matriz = malloc(l * sizeof(int));

    //Declarando as colunas da minha matriz em um loop que percorre cada linha e aloca espaços para as colunas;
    for(int i = 0; i < l; i++){
        matriz[i] = malloc(c * sizeof(int));
    }

    //Populando aleatoriamente os espaços da minha matriz
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            matriz[i][j] = rand() % 10;
        }
    }
    
    //Lendo a matriz
    printf("MATRIZ NORMAL -----\n");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    ////////CRIANDO A MATRIZ QUE SERA A ORIGINAL TRANSPOSTA
    int **m_transposta;
    m_transposta = malloc(l * sizeof(int));
    for(int i = 0; i < l; i++){
        m_transposta[i] = malloc(c * sizeof(int));
    }
    ////////

    //Transpor matriz
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            m_transposta[j][i] = matriz[i][j];
        }
    }

    //Lendo matriz transposta
    printf("MATRIZ TRANSPOSTA -----\n");
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", m_transposta[i][j]);
        }
        printf("\n");
    }

    free(matriz);
    return 0;
}