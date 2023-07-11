#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa capaz de identificar se um número é um ano bissexto. Considere que para o ano
ser bissexto basta que seja divisível por 400. Caso contrário, precisa ser divisível por 4 e não ser
divisível por 100. Faça uma condição composta que englobe todas as regras para a definição do ano
bissexto.
*/

int main(){
    
    int ano;
    printf("INSIRA UM ANO PARA IDENTIFICAR SE EH BISSEXTO OU NAO:\n");
    scanf("%d", &ano);
    if ((ano % 400 == 0) || ((ano % 4 == 0) && (ano % 100 != 0))){
        printf("%d eh bissexto", ano);
    } else{
        printf("%d NAO eh bissexto", ano);
    }

    
    return EXIT_SUCCESS;
}