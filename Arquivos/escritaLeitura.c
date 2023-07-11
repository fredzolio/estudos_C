#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *arquivo;
    char letra;
    
    arquivo = fopen("arquivoReal.txt", "w+");

    if (arquivo){
        printf("Digite um texto e aperte ENTER ao finalizar:\n");
        scanf("%c", &letra);
        while (letra != '\n'){
            fputc(letra, arquivo);
            scanf("%c", &letra);
        }
        rewind(arquivo);
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
