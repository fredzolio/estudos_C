#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, k;
    double **matriz1, **matriz2, **resultado;

    printf("Digite a dimensao n da matriz: ");
    scanf("%d", &n);

    // alocando dinamicamente as matrizes
    matriz1 = (double**) malloc(n * sizeof(double*));
    matriz2 = (double**) malloc(n * sizeof(double*));
    resultado = (double**) malloc(n * sizeof(double*));

    for(i = 0; i < n; i++) {
        matriz1[i] = (double*) malloc(n * sizeof(double));
        matriz2[i] = (double*) malloc(n * sizeof(double));
        resultado[i] = (double*) malloc(n * sizeof(double));
    }

    // lendo os dados das duas matrizes
    printf("Digite os dados da primeira matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &matriz1[i][j]);
        }
    }

    printf("Digite os dados da segunda matriz:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &matriz2[i][j]);
        }
    }

    // multiplicando as matrizes
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            resultado[i][j] = 0;
            for(k = 0; k < n; k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    // imprimindo a matriz resultante
    printf("A matriz resultante da multiplicacao eh:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%.1lf ", resultado[i][j]);
        }
        printf("\n");
    }

    // liberando a memória alocada pelas matrizes
    for(i = 0; i < n; i++) {
        free(matriz1[i]);
        free(matriz2[i]);
        free(resultado[i]);
    }
    free(matriz1);
    free(matriz2);
    free(resultado);

    return 0;
}
