#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que abra o arquivo texto criado no exercício anterior e
conte quantas vezes a letra “a” aparece no nome.
*/

int main(){

    FILE *arquivo = fopen("arquivo01.txt", "r");
    char aux, ch;
    printf("QUAL LETRA QUER PROCURAR?\n");
    scanf("%c", &ch);
    int cont = 0;
    if(arquivo){
        while(!feof(arquivo)){
            aux = fgetc(arquivo);
            if(tolower(aux) == tolower(ch)){
                cont++;
            }
        }
    }else{
        printf("NAO FOI POSSIVEL ABRIR O ARQUIVO\n");
    }
    
    printf("A LETRA [%c] APARECE [%d] vezes!\n", ch, cont);
    fclose(arquivo);

    return EXIT_SUCCESS;
}