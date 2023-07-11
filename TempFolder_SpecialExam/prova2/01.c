#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

int contido(int vetor1[], int vetor2[]);
 
int main(){

    int vetor1[] = {1,2,3,4,5};
    int vetor2[] = {2,1,6,4,5,3,7,8};
    if(contido(vetor1, vetor2) == 1){
        printf("contido\n");
    }else{
        printf("nao contido\n");
    }
    return EXIT_SUCCESS;
}

int contido(int vetor1[], int vetor2[]){
    int cont = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 8; j++){
            if(vetor1[i] == vetor2[j]){
                cont++;
            }
        }
    }
    if(cont == 5){
        return 1;
    }else{
        return 0;
    }
}