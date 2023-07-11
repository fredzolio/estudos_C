#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que grave um string (seu nome, por exemplo) em um arquivo
texto.
*/

int main(){

    FILE *arquivo;
    arquivo = fopen("arquivo01.txt", "w");
    char str[] = {"Frederico Lico Lico Abacaxi Xi Xi"};

    fputs(str, arquivo);

    fclose(arquivo);

    return EXIT_SUCCESS;
}