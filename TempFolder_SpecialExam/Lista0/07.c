#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/*
Sabe-se que o valor de cada 1000 litros de água corresponde a 2% do salário mínimo. Faça um
programa para receber o valor do salário mínimo e a quantidade de água consumida em uma
residência por mês.
O algoritmo deverá calcular e mostrar: 
a) o valor da conta de água. 
b) o valor a ser pago com desconto de 15%.
*/

int main(){

    int salaMin, litAgua;
    printf("DIGITE O SALARIO MINIMO E O CONSUMO DE AGUA (R$ L):\n");
    scanf("%d %d", &salaMin, &litAgua);
    double conta = ((litAgua * 0.02)/1000) * salaMin;
    printf("VALOR A SER PAGO: %.2lf\nCOM DESCONTO DE 15 PORCENTO: %.2lf\n", conta, conta*0.85);

    return EXIT_SUCCESS;
}