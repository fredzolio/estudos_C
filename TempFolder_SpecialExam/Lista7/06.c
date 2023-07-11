#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que faça a soma de todos os números de um vetor de números inteiros de
qualquer tamanho escolhido pelo usuário. Os números do vetor serão digitados pelo usuário
também. Faça a alocação dinâmica do vetor.
*/

void ler(int *vetor, int tam){
    printf("_________________\n");
    for(int i = 0; i < tam; i++){
        printf("|\t%d\t|\n", vetor[i]);
        printf("|---------------|\n");
    }
}

int main(){
    int n, soma = 0;;
    printf("TAMANHO DO VETOR:\n");
    scanf("%d[^\n]", &n);
    int *v = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d[^\n]", &x);
        *(v + i) = x;
        soma+=x;
    }
    ler(v, n);
    printf("\nSOMA: %d\n", soma);
    free(v);

    return EXIT_SUCCESS;
}