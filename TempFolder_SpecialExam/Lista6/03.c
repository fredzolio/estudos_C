#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que grave um string (seu nome, por exemplo) em um arquivo
binário.
*/

int main(){

    FILE *arquivo = fopen("arquivoB_03.bin", "wb");
    char str[100];
    if(arquivo){
        printf("DIGITE O QUE VOCE QUER GRAVAR:\n");
        scanf("%99[^\n]", str);
        fwrite(&str, (strlen(str) * sizeof(char)), 1, arquivo);
    }else{
        printf("NAO FOI POSSIVEL CRIAR O ARQUIVO!\n");
    }
    fclose(arquivo);

    return EXIT_SUCCESS;
}