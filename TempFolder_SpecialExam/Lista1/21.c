#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa para calcular o mínimo múltiplo comum de dois número inteiros
utilizando o método da decomposição simultânea dos números em fatores primos.
MMC = 2 * 2 * 3 * 5 = 60.
*/

int main(){

    int divisor = 2, a, b, mmc = 1;
    
    printf("INSIRA 2 NUMEROS PARA TIRAR O MMC:\n");
    scanf("%d %d", &a, &b);
    while(a != 1 || b != 1){
        if(a % divisor == 0 || b % divisor == 0){
            if(a % divisor == 0){
                a = a / divisor;
            }
            if(b % divisor == 0){
                b = b / divisor;
            }
            mmc = mmc * divisor;
        }else{
            divisor++;
        }
    }
    printf("MMC: %d", mmc);

    return EXIT_SUCCESS;
}