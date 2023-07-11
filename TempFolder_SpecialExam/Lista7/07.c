#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que ordene um vetor de números inteiros de qualquer tamanho escolhido pelo
usuário. Os números do vetor serão digitados pelo usuário também. Faça a alocação dinâmica do
vetor.
*/

void ler(int *vetor, int tam){
    printf("_________________\n");
    for(int i = 0; i < tam; i++){
        printf("|\t%d\t|\n", vetor[i]);
        printf("|---------------|\n");
    }
}

int main(){

    int n;
    printf("TAMANHO DO VETOR:\n");
    scanf("%d[^\n]", &n);
    int *v = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d[^\n]", &x);
        *(v + i) = x;
    }
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int temp;
            if(v[j] < v[i]){
                temp = v[j];
                v[j] = v[i];
                v[i] = temp;
            }
        }
    }
    ler(v, n);
    free(v);
    return EXIT_SUCCESS;
}