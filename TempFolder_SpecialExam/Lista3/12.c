#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente uma função que conta e retorna a quantidade de caracteres existente em um
string passado como parâmetro.
*/

int contaStr(char str[]){
    int i;
    for(i = 0; str[i] != '\0'; i++){}
    return i;
}

int main(){

    char str[] = {"Frederico"};
    printf("A STRING TEM '%d' CARACTERES\n", contaStr(str));

    return EXIT_SUCCESS;
}