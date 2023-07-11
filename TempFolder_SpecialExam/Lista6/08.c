#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que conta quantas vezes uma certa palavra aparece em um
arquivo texto.
*/

int main(){

    char file[] = {"arquivo01.txt"};
    FILE *arq = fopen(file, "r");
    if(arq){
        char palavra[50], texto[100];
        scanf("%49[^\n]", palavra);
        while(!feof(arq)){
            fgets(texto, 100, arq);
        }
        char *pt;
        pt = strtok(texto, " ");
        int cont = 0;
        while(pt){
            if(strcmp(pt, palavra) == 0) cont++;
            pt = strtok(NULL, " ");
        }
        printf("A PALAVRA APARECE [%d] VEZES", cont);
    }else{
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO!\n");
    }
    fclose(arq);

    return EXIT_SUCCESS;
}