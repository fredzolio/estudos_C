#include <stdio.h>
#include <stdlib.h>

int pot(int x, int n){
    if(n == 0)
        return 1;
    else
        return x * pot(x, n - 1);
}

int main () {

    int n, x;

    printf("Digite o valor para X e para N: (x^n)\n");
    scanf("%d %d", &x, &n);

    printf("Resultado de %d elevado a %d: %d\n", x, n, pot(x, n));

    return 0;
}