#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Ordenar 3 numeros inteiros 
*/

int main(){

    int a, b, c;    
    printf("INSIRA 3 NUMEROS: (a b c)\n");
    scanf("%d %d %d", &a, &b, &c);
    if (a > c) {
        int tmp = c;
        c = a;
        a = tmp;
    }
    if (a > b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
    if (b > c) {
        int tmp = c;
        c = b;
        b = tmp;
    }
    printf("%d %d %d", a, b, c);

    return EXIT_SUCCESS;
}