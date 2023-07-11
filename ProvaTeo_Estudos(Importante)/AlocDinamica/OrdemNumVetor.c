#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void OrdenaElementos(int *vetor, int tam){
    printf("INSIRA %d ELEMENTOS INTEIROS:\n", tam);
    for(int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }
    for(int i = 0; i < tam; i++){
        for(int j = i; j < tam; j++){
            if(vetor[i] > vetor[j]){
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}


int main(){
    
    int tam;
    printf("TAMANHO DO VETOR:\n");
    scanf("%d", &tam);
    int *vetor;
    vetor = calloc(tam, sizeof(int));
    OrdenaElementos(vetor, tam);
    for(int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    free(vetor);
    return EXIT_SUCCESS;
}