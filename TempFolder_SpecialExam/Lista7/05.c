#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>


/*
Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe
esse vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o
vetor preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a
área de memória alocada.
*/

void ler(int *vetor, int tam){
    printf("_________________\n");
    for(int i = 0; i < tam; i++){
        printf("|\t%d\t|\n", vetor[i]);
        printf("|---------------|\n");
    }
}

int main(){

    srand(time(NULL));
    int n;
    printf("INSIRA O TAMANHO DO VETOR:\n");
    scanf("%d[^\n]", &n);
    int *vetor = calloc(n, sizeof(int));
    ler(vetor, n);
    for(int i = 0; i < n; i++){
        *(vetor + i) = rand() % 100;
    }
    printf("\n\n\n");
    ler(vetor, n);

    return EXIT_SUCCESS;
}