#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
TODO:
    OK -> Função com 2 parâmetros (vetor(v1) e um inteiro denominado quantidade -> de elementos do vetor);
    A função deve solicitar um novo valor n;
    Inserir o valores de v1 em v2;
    Enquanto n for maior que n(antigo), continuar pedindo valor de n;
    v2 tem que ser exibido em main();
    usar realloc para novo tamanho de vetor;
    do while;
    se n for maior que n(anterior) tambem ler novo valor para a posição nova do vetor;

*/

int realocar_E_preencher(int *v1, int n1, int *v2){
    int n_antigo = n1, n = n1, tam = n1;
    for(int i = 0; i < n1; i++){
        *(v2 + i) = *(v1 + i);
    }
    do{
        n_antigo = n;
        printf("INSIRA O NOVO VALOR DE N:\n");
        scanf("%d", &n);
        if(n > n_antigo){
            int diff = n - n_antigo;
            v2 = realloc(v2, n);
            for(int i = n_antigo; i < n; i++){
                printf("INSIRA UM VALOR PARA V2[%d]:\n", i);
                int temp;
                scanf("%d", &temp);
                *(v2 + i) = temp;
                tam++;
            }
        }
    }while(n > n_antigo);
    return tam;
}

int main(){

    int n;
    printf("INSIRA O TAMANHO DE V1:\n");
    scanf("%d[^\n]", &n);
    int *v1 = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("INSIRA UM VALOR PARA V1[%d]:\n", i);
        int temp;
        scanf("%d[^\n]", &temp);
        *(v1 + i) = temp;
    }
    int *v2 = malloc(n * sizeof(int));
    int tamV2 = realocar_E_preencher(v1, n, v2);
    printf("%d\n", tamV2);
    for(int i = 0; i < tamV2; i++){
        printf("%d\n", *(v2 + i));
    }
    


    return EXIT_SUCCESS;
}