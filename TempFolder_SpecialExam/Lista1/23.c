#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que solicita ao usuário um valor inteiro correspondente à idade
de uma pessoa em dias e informea
em anos, meses e dias.
*/

int main(){

    int ano = 0, mes = 0, dia = 0, x;
    printf("INSIRA OS DIAS: \n");
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        dia++;
        if(dia == 30){
            dia = 0;
            mes++;
        }
        if(mes == 12){
            mes = 0;
            ano++;
        }
    }
    printf("%d Ano(s), %d Mes(es), %d Dia(s)\n", ano, mes, dia);

    return EXIT_SUCCESS;
}