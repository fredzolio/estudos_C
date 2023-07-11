#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    FILE *arquivo = fopen("teste.txt", "r");
    printf("INSIRA A PALAVRA QUE QUER PROCURAR:\n");
    char palavra[50], str[100];
    scanf("%59[^\n]", palavra);
    for(int i = 0; !feof(arquivo); i++){
        fgets(str, 100, arquivo);
    }
    
    char *pt;
    pt = strtok(str, " ");
    int cont = 0;
    while(pt){
        if(strcmp(pt, palavra) == 0) cont++;
        pt = strtok(NULL, " ");
    }
    printf("A PALAVRA [%s], APARECEU [%d] VEZES.\n", palavra, cont);
    fclose(arquivo);
    return 0;
}