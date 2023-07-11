#include <stdio.h>
#include <stdlib.h>


int main(){

    FILE *arquivo;
    char letra;
    
    arquivo = fopen("arquivoReal.txt", "w");

    if (arquivo){
        printf("Digite um texto e aperte ENTER ao finalizar:");
        scanf("%c", &letra);
        while (letra != '\n'){
            fputc(letra, arquivo);
            scanf("%c", &letra);
        }
        fclose(arquivo);

    } else {
        printf("\n\tERRO --> O arquivo nao pode ser aberto!\n");
    }

    return 0;
}
