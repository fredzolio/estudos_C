#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Altere o programa anterior de tal maneira que quando o usuário digitar um intervalo inválido
(n1>n2), o programa irá solicitar novos valores para n1 e n2.
*/

int main(){

    int n1, n2, soma = 0;
    do{
        printf("INSIRA DOIS VALORES, N1 E N2:\n");
        scanf("%d %d", &n1, &n2);
        if(n1 > n2)
            printf("INSIRA VALORES VALIDOS! N1 < N2\n");
    } while(n1 > n2);
    for(int i = n1; i <= n2; i++){
        if(i % 2 != 0){
            soma+= i;
        }
    }
    printf("SOMA: %d", soma);

    return EXIT_SUCCESS;
}