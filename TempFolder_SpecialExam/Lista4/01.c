#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
“char * strchar (char *s, char ch)” que retorna o endereço da primeira ocorrência de “ch” em
“s”; caso não exista, retorna NULL (NULL é uma constante simbólica que indica que o ponteiro não
aponta para nenhuma variável). Implemente a função principal (“main”) para testar a função
strchar.
*/

char *strchar(char *s, char ch){
    char *ptr;
    ptr = s;
    while(*ptr != ch){
        ptr++;
    }
    if(*ptr == ch){
        return ptr;
    }else{
        return NULL;
    }
}

int main(){

    char *s, ch;
    s = malloc(30 * (sizeof(char)));
    printf("INSIRA A PALAVRA/FRASE:\n");
    fgets(s, 30, stdin);
    while(1){
        fflush(stdin);
        printf("INSIRA A LETRA PARA PROCURAR:\n");
        scanf("%c", &ch);
        fflush(stdin);
        printf("ENDERECO DA OCORRENCIA: [%p]\n", strchar(s, ch));
    }

    return EXIT_SUCCESS;
}