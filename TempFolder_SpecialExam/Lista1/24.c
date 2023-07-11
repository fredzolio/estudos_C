#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente um programa que solicita ao usuário um valor real com duas casas decimais.
Este valor representa um valor monetário. A seguir, calcule o menor número de notas e
moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100,
50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre
a relação de notas necessárias.
*/

int main(){

    double valor;
    int cem = 0, cinq = 0, vinte = 0, dez = 0, cinco = 0, dois = 0, um = 0, cinq_centavos = 0, vinte_cinco_centavos = 0, dez_centavos = 0, cinco_centavos = 0, um_centavo = 0;
    scanf("%lf", &valor);
    //getchar();
    
    while(valor >= 100){
        valor -= 100;
        cem++;
    }
    while(valor >= 50){
        valor -= 50;
        cinq++;
    }
    while(valor >= 20){
        valor -= 20;
        vinte++;
    }
    while(valor >= 10){
        valor -= 10;
        dez++;
    }
    while(valor >= 5){
        valor -= 5;
        cinco++;
    }
    while(valor >= 2){
        valor -= 2;
        dois++;
    }
    while(valor >= 1){
        valor -= 1;
        um++;
    }
    while(valor >= 0.5){
        valor -= 0.5;
        cinq_centavos++;
    }
    while(valor >= 0.25){
        valor -= 0.25;
        vinte_cinco_centavos++;
    }
    while(valor >= 0.10){
        valor -= 0.10;
        dez_centavos++;
    }
    while(valor >= 0.05){
        valor -= 0.05;
        cinco_centavos++;
    }
    while(valor >= 0.01){
        valor -= 0.01;
        um_centavo++;
    }
    
    printf("NOTAS:\n%d Notas de R$100\n%d Notas de R$50\n%d Notas de R$20\n%d Notas de R$10\n%d Notas de R$5\n%d Notas de R$2\n", cem, cinq, vinte, dez, cinco, dois);
    printf("MOEDAS:\n%d Moedas de R$1\n%d Moedas de R$0.50\n%d Moedas de R$0.25\n%d Moedas de R$0.10\n%d Moedas de R$0.05\n%d Moedas de R$0.01\n", um, cinq_centavos, vinte_cinco_centavos, dez_centavos, cinco_centavos, um_centavo);

    return EXIT_SUCCESS;
}