#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Escreva um programa que solicita ao usuário um valor entre 3 e 18. Este valor representa a soma
dos valores do lançamento de 3 dados. Em seguida, o programa deve imprimir todas as
possibilidades de que no lançamento dos 3 dados a soma de seus valores seja igual ao valor
informado pelo usuário. Por exemplo, caso o usuário digite o valor 10, o programa deverá exibir:
6,3,1; 1,6,3; 6,2,2; 5,3,2 etc. Você pode exibir sequências iguais em dados diferentes, por exemplo,
as sequências 6,3,1 e 1,6,3 possuem os mesmos números, mas em dados diferentes.
*/

int main(){

    int valor;
    printf("INSIRA UM VALOR:\n");
    scanf("%d", &valor);
    for(int i = 1; i <= 6; i++){
        for(int j = 1; j <= 6; j++){
            for(int k = 1; k <= 6; k++){
                if((i + j + k) == valor)
                    printf("%d, %d, %d\n", i, j, k);
            }
        }
    }
    

    return EXIT_SUCCESS;
}