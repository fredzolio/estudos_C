#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    FILE *arquivo = fopen("teste.txt", "r");
    
    int cont = 0;
    char ch;
    printf("QUAL 'caracter' voce quer procurar?\n");
    scanf("%c", &ch);
    if(arquivo){
        while (!feof(arquivo)){
            char temp = tolower(fgetc(arquivo));
            if(temp == ch){
                cont++;
            }
        }
    }else printf("\nFALHA\n");
    printf("\nA letra [%c] foi vista [%d] vezes\n", ch, cont);
    fclose(arquivo);

    return 0;
}