#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que solicite um nome de arquivo ao usuário e conte a quantidade
de bytes do arquivo informado. Teste seu programa com os arquivos criados nos exercícios
anteriores.
*/

int main(){

    FILE *arq;
    char file_path[40];
    printf("INFORME O NOME/CAMINHO DE UM ARQUIVO:\n");
    scanf("%39[^\n]", file_path);
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
        printf("O ARQUIVO TEM [%d]bytes", ftell(arq));
    }else{
        printf("O ARQUIVO INFORMADO NAO EXISTE!\n");
        return 0;
    }

    fclose(arq);

    return EXIT_SUCCESS;
}