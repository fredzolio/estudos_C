#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que compara o tamanho de 2 arquivos e informa qual possui a
maior quantidade de bytes.
*/

int determinaTamArq(){
    FILE *arq;
    char file_path[40];
    printf("INFORME O NOME/CAMINHO DE UM ARQUIVO:\n");
    scanf("%39[^\n]", file_path);
    fflush(stdin);
    if(strstr(file_path, ".txt")){
        arq = fopen(file_path, "r");
    }else if(strstr(file_path, ".bin") || strstr(file_path, ".dat")){
        arq = fopen(file_path, "rb");
    }else{
        printf("O ARQUIVO INFORMADO NAO EXISTE!\n");
        return 0;
    }
    if(arq){
        fseek(arq, 0, SEEK_END);
        return ftell(arq);
    }else{
        printf("O ARQUIVO INFORMADO NAO EXISTE!\n");
        return 0;
    }

    fclose(arq);
}

int main(){

    int tamArq1 = determinaTamArq(), tamArq2 = determinaTamArq();
    if(tamArq1 > tamArq2){
        printf("O TAMANHO DO ARQUIVO 1 EH MAIOR!\n");
    }else if(tamArq1 == tamArq2){
        printf("O TAMANHO DOS ARQUIVOS SAO IGUAIS!\n");
    }else{
        printf("O TAMANHO DO ARQUIVO 2 EH MAIOR!\n");
    }


    return EXIT_SUCCESS;
}