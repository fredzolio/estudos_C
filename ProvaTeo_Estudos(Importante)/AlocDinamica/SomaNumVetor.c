#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void lerElementos(int *vetor, int tam){
    printf("INSIRA %d ELEMENTOS INTEIROS:\n", tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
}


int main(){
    
    int tam, cont = 0;
    printf("TAMANHO DO VETOR:\n");
    scanf("%d", &tam);
    int *vetor;
    vetor = calloc(tam, sizeof(int));
    lerElementos(vetor, tam);
    for(int i = 0; i < tam; i++){
        cont+= vetor[i];
    }
    printf("%d", cont);
    free(vetor);
    return EXIT_SUCCESS;
}