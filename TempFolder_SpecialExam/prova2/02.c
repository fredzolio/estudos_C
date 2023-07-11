#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

void estatistica(char str[]){
    int tam = strlen(str);
    for(int i = 0; i < tam; i++){
        int aux = 0;
        char tmp = str[i];
        for(int j = 0; j < tam; j++){
            if(str[j] == tmp){
                aux++;
                for(int k = j; k < tam; k++){
                    str[k] = str[k + 1];
                }
                tam--;
            }
        }
        printf("%c = %d\n", tmp, aux);
    }
}

int main(){

    char str[50];
    scanf("%49[^\n]", str);
    estatistica(str);

    return EXIT_SUCCESS;
}