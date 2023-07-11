#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Uma empresa tem registrado em uma tabela os consumos mensais de energia elétrica dos
anos de 2003 até 2010. Cada linha representa um ano e cada coluna representa um mês.
Considerando esses dados, faça um algoritmo para processar a tabela e produzir as seguintes
informações:
1.
Consumo médio em cada um dos meses;
2.
Mês/ano em que houve o maior gasto com energia.
*/

int main(){

    srand(time(NULL));
    int matriz[8][13];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j <= 12; j++){
            matriz[i][j] = rand() % 50;
        }
    }

    for(int i = 0; i <= 12; i++){
        int soma = 0, consMedio = 0;
        for(int j = 0; j < 8; j++){
            soma += matriz[j][i];
        }
        consMedio = soma / 7;
        printf("CONSUMO MEDIO DO MES [%d] FOI DE: %d\n", i, consMedio);
    }
    int maior = matriz[0][0];
    for(int i = 0; i < 8; i++){
        for(int j = 0; j <= 12; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
    }
    printf("MAIOR NUMERO: %d\n", maior);


    return EXIT_SUCCESS;
}