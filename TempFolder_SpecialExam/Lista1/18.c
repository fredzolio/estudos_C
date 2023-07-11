#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*

*/

int main(){


    int numero, maior = 0;
    int contador=0;
    do{
    contador=contador+1;
    printf("Digite o %d numero: ",contador);
    scanf("%d",&numero);
    
    if(numero > maior)
        maior = numero;

    }while(contador<10);

    printf("MAIOR: %d\n", maior);


    return EXIT_SUCCESS;
}