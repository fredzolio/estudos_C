#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Implemente o procedimento void imprime_sobrenome (char nome_completo[ ]) que
recebe o nome completo de uma pessoa e imprime o último nome. Por exemplo, para o nome
completo “Jose Maria da Silva”, o programa deve exibir: “Silva”.
*/

void lastName(char nome[]){
    char *ptr;
    ptr = nome;
    while(*ptr != '\0'){
        ptr++;
    }
    while(*ptr != ' '){
        ptr--;
    }
    ptr++;
    printf("ULTIMO NOME: ");
    while(*ptr != '\0'){
        printf("%c", *ptr++);
    }
    
}

int main(){

    char nome[] = {"Frederico Zolio Gonzaga Diniz"};
    lastName(nome);

    return EXIT_SUCCESS;
}