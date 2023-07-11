#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int num, res = 1;
    printf("INSIRA UM NUMERO PARA CALCULAR O SEU FATORIAL:\n");
    scanf("%d", &num);
    for(int i = num; i > 0; i--){
        res *= i;
    }
    printf("%d! = %d\n", num, res);

    return 0;
}