#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Faça um algoritmo que simule uma calculadora com as quarto operações básicas (+,-,*,/). O
algoritmo deve solicitar ao usuário a entrada de dois operandos e da operação a ser executada, na
forma de menu. Dependendo da opção escolhida, deve ser executada a operação solicitada e escrito
seu resultado. Utilize uma variável do tipo caractere para armazenar a operação e utilize o comando
caso para escolher a operação a partir do operador.
*/

void soma(double num1, double num2){
    double resultado = (num1 + num2);
    printf("\n----------------------\n   Resultado: %.2lf\n----------------------\n", resultado);
}
void sub(double num1, double num2){
    double resultado = (num1 - num2);
    printf("\n----------------------\n   Resultado: %.2lf\n----------------------\n", resultado);
}
void mult(double num1, double num2){
    double resultado = (num1 * num2);
    printf("\n----------------------\n   Resultado: %.2lf\n----------------------\n", resultado);
}
void divi(double num1, double num2){
    double resultado = (num1 / num2);
    printf("\n----------------------\n   Resultado: %.2lf\n----------------------\n", resultado);
}

int main(){
    
    double num1, num2;
    char oper;
    printf("INSIRA 2 VALORES: (num1 num2)\n");
    fflush(stdin);
    scanf("%lf %lf", &num1, &num2);
    fflush(stdin);
    do {
        printf("QUAL OPERACAO QUER REALIZAR?\n");
        fflush(stdin);
        scanf("%c", &oper);
        fflush(stdin);
        switch (oper)
        {
        case '+':
            soma(num1, num2);
            break;
        case '-':
            sub(num1, num2);
            break;
        case '*':
            mult(num1, num2);
            break;
        case '/':
            divi(num1, num2);
            break;
        default:
            if(oper != 'c'){
                printf("Opcao invalida\n");
            }
            break;
        }
    } while (oper != 'c');



    return EXIT_SUCCESS;
}