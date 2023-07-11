#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //PARTE 1
    int tam = 0;
    char *str;
    str = (char *) malloc(100 * sizeof(char));
    printf("\tDigite uma frase:\n\n");
    for(int i = 0; i < 100; i++){
        char aux;
        scanf("%c", &aux);
        if(aux == '\n'){
            str[i] = '\0';
            break;
        }
        str[i] = aux;
        tam++;
    }
    fflush(stdin);
    str = (char *) realloc(str, tam * sizeof(char));

    //PARTE 2
    char *str_2;
    str_2 = str;
    printf("\n\tFrase sem espacos:\n");
    for (int i = 0; i < tam; i++){
        if(str_2[i] == ' '){
            
        }else{
            printf("%c", str_2[i]);
        }
    }
    free(str);
    free(str_2);
    return 0;
}