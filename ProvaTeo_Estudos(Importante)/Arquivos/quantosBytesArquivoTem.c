#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    
    char arq_path[] = {"teste.txt"};
    FILE *arquivo = fopen(arq_path, "r");
    fseek(arquivo, 0, SEEK_END);
    printf("%d", ftell(arquivo));
    return 0;
}