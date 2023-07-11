#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    FILE *arquivo = fopen("numeros.txt", "rw");
    while(!feof(arquivo)){
        int aux;
        fscanf(arquivo, int)        
    }
    fclose(arquivo);

    return 0;
}