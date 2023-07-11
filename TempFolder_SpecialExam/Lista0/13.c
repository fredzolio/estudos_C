#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Escreva o seguinte código utilizando apenas um “if”
if (x==0)
    if (y<=32)
        printf(“Sucesso!!!”);
*/

int main(){
    int x, y;
    if(x == 0 && y <= 32)
        printf("Sucesso!!!");

    return EXIT_SUCCESS;
}