#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que abra o arquivo binário criado no exercício anterior e
conte quantas vezes a letra “a” aparece no nome.
*/

int main(){

    FILE *arquivo = fopen("arquivoB_03.bin", "rb");

    if(arquivo){
        int cont = 0;
        char ch = 'e';
        while(!feof(arquivo)){
            char letra;
            fread(&letra, sizeof(char), 1, arquivo);
            if(tolower(letra) == tolower(ch)){
                cont++;
            }
        }
        printf("A LETRA [%c], FOI VISTA [%d] VEZES.\n", ch, cont);
    }else{
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO!\n");
    }
    fclose(arquivo);

    return EXIT_SUCCESS;
}