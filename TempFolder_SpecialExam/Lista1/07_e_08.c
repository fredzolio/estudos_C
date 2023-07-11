#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um programa que leia um número inteiro positivo e determine se este é primo ou não. Por
definição, um número é primo quando é divisível somente por si próprio e por 1.
 
Otimize o programa anterior com base nas seguintes considerações:
• Números pares (com exceção do 2) não podem ser primos, visto que são divisíveis por 2. Se um
número não for divisível por 2, não será divisível por nenhum outro número par. Portanto, com
excecão do número 2, somente é necessário testar números ímpares.
• É mais fácil que um número seja divisível por um número pequeno do que por um número maior.
Portanto, se iniciarmos a procura do divisor de baixo para cima, ao invés de cima para baixo teremos
chance de encontrar o número muito antes.
• Nenhum número pode ser divisível por outro número maior que a metade dele. Portanto, não
precisamos testar a divisibilidade dos números na faixa entre a metade e o próprio número.
*/

int main(){

    int num, check = 0;
    printf("INSIRA UM VALOR INTEIRO E POSITIVO:\n");
    scanf("%d", &num);
    if(num != 2 && num % 2 == 0){
        printf("NAO EH PRIMO!\n");
        return EXIT_SUCCESS;
    }
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            check++;
        }
    }
    if(check == 2){
        printf("EH PRIMO\n");
    }

    return EXIT_SUCCESS;
}