#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char palavra[] = {"Ola Fred voce vai passar na prova de hoje!"};
    char *pt;
    int cont = 0;
    pt = strtok(palavra, " ");
    while(pt){
        printf("token: %s \n", pt);
        pt = strtok(NULL, " ");
        cont++;
    }
    printf("%d", cont);

    return 0;
}