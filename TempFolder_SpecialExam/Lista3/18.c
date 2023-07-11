#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX 100

/*
Implemente o void eliminar(char v [ ], char ch) que elimina todas as ocorrências do
caractere“ch” no vetor de caracteres “v”. Ao eliminar um caractere, os outros elementos do vetor
devem ser movidos para esquerda. Por exemplo: v = “programacao de computadores” e ch = 'a'. Ao
final do procedimento o conteúdo de “v” deverá ser “progrmco de computadores”. Você não pode
utilizar um vetor auxiliar para implementar o procedimento.
*/

void eliminar(char str[], char ch){
    int tamStr = strlen(str);
    for(int i = 0; i < tamStr; i++){
        if(str[i] == ch){
            for(int j = i; j < tamStr; j++){
                str[j] = str[j + 1];
            }
        }
    }
    printf("%s\n", str);
}

int main(){

    char ch, str[MAX];
    printf("INSIRA A PALAVRA: \n");
    fgets(str, MAX, stdin);
    fflush(stdin);
    printf("INSIRA A LETRA PARA ELIMINAR:\n");
    scanf("%c", &ch);
    getchar();
    eliminar(str, ch);

    return EXIT_SUCCESS;
}