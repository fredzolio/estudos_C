#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Dado o valor de E, calcular S=1 + 1/2 + 1/4 +1/6 + … até que um termo da série seja menor do que
E. O valor de E deverá ser digitado pelo usuário.
Resposta. Para E=0.00001 S=6.698
*/

int main(){

    double e, s = 0;
    int i = 1;
    scanf("%lf", &e);
    while(i > e){
        s += i;
        i /= 2;
    }
    printf("%lf", s);

    return EXIT_SUCCESS;
}