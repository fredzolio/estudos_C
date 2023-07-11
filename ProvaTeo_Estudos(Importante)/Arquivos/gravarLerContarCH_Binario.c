#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    FILE *arquivoB = fopen("teste.bin", "wb");
    FILE *arquivo = fopen("teste.txt", "r");
    char str[100];
    while(!feof(arquivo)){
        fgets(str, 100, arquivo);
    }
    fwrite(&str, strlen(str) * sizeof(char), 1, arquivoB);
    fclose(arquivo);
    fclose(arquivoB);
    FILE *arquivoB1 = fopen("teste.bin", "rb");
    char strB[100];
    int cont = 0;
    char ch;
    printf("QUAL LETRA VOCE PROCURA?\n");
    scanf("%c", &ch);
    fread(&strB, strlen(str) * sizeof(char), 1, arquivoB1);
    for(int i = 0; strB[i] != '\0'; i++){
        if(tolower(strB[i]) == ch) cont++;
    }
    printf("\nA letra [%c] foi vista [%d] vezes\n", ch, cont);
    fclose(arquivoB1);
    return 0;
}