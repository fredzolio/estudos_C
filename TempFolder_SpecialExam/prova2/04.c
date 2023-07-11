#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
preenche vetor aleatoriamente e depois exclui os rep. e le antes e depois.
*/

void ler(int *vetor, int n){
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            printf("%d\n", *(vetor + i));
        }else{
            printf("%d, ", *(vetor + i));
        }
    }
}

int remRep(int *vetor, int n1){
    int n = n1, cont = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(*(vetor + j) == *(vetor + i)){
                for(int k = j; k < n; k++){
                    *(vetor + k) = *(vetor + k + 1);
                }
                n--;
                cont++;
            }
        }
    }
    return cont;
}

int main(){

    srand(time(NULL));
    int n; 
    printf("INSIRA O TAMANHO DO VETOR:\n");
    scanf("%d[^\n]", &n);
    int *vetor = calloc(n, sizeof(int));
    for(int i = 0; i < n; i++){
        *(vetor + i) = rand() % 100;
    }
    ler(vetor , n);
    n -= remRep(vetor, n);
    ler(vetor, n);
    

    return EXIT_SUCCESS;
}