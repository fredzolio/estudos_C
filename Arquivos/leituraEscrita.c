#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *arquivo;
    char letra;
    
    arquivo = fopen("arquivoReal.txt", "r+");

    if (arquivo){
        printf("Texto lido do arquivo:\n");
        while (!feof(arquivo)){
            letra = fgetc(arquivo);
            putchar(letra);
        }
        printf("\n");
        rewind(arquivo);
        printf("Digite o novo texto a ser colocado no arquivo e aperte ENTER:\n");
        do{
            scanf("%c", &letra);
            fputc(letra, arquivo);
        } while (letra != '\n');
        fclose(arquivo);
    } else {
        printf("\n\tERRO --> O arquivo nao pode ser aberto!\n");
    }

    return 0;
}
