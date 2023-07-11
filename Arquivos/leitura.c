#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *arquivo;
    char letra;
    
    arquivo = fopen("arquivoReal.txt", "r");

    if (arquivo){
        printf("Texto lido do arquivo:\n");
        while (!feof(arquivo)){
            letra = fgetc(arquivo);
            putchar(letra);
        }
        fclose(arquivo);
    } else {
        printf("\n\tERRO --> O arquivo nao pode ser aberto!\n");
    }

    return 0;
}
