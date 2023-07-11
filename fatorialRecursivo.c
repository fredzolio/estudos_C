#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fat(int num){
    if(num <= 1){
        return 1;
    }else{
        return (num * fat(num - 1));
    }
}

int main(){
    
    int num, res;
    printf("INSIRA UM NUMERO PARA CALCULAR O SEU FATORIAL:\n");
    scanf("%d", &num);
    res = fat(num);
    printf("%d! = %d\n", num, res);

    return 0;
}