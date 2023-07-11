#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
“char *strstr (char *str1, char *str2)” que retorna o endereço de str1 em que ocorre pela
primeira vez a substring str2. Caso não exista, retorna NULL.
*/

char *strstrd (char *str_prin, char *str_sub){
    int cont = 0, tamSub = strlen(str_sub) - 1;
    char *aux = NULL;
    while(*str_sub != '\n' && *str_prin != '\n'){
        if(*str_sub == *str_prin){
            aux = str_prin;
            str_sub++;
            str_prin++;
            cont++;
        }else{
            str_prin++;
        }
    }
    if(cont == tamSub){
        return aux;
    }else{
        return NULL;
    }
}

int main(){

    char *s, *ss;
    s = malloc(100 * (sizeof(char)));
    ss = malloc(100 * (sizeof(char)));
    printf("INSIRA A PALAVRA/FRASE PRINCIPAL:\n");
    fgets(s, 100, stdin);
    fflush(stdin);
    printf("INSIRA A PALAVRA/FRASE SUB:\n");
    fgets(ss, 100, stdin);
    fflush(stdin);
    printf("ENDERECO DA OCORRENCIA: [%p]\n", strstrd(s, ss));

    return EXIT_SUCCESS;
}