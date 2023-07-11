#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

char *concat(char *str1, char *str2){
    int tam_Str1 = strlen(str1), tam_Str2 = strlen(str2), tam_Str_Resultado = tam_Str1 + tam_Str2;
    char *str3 = malloc(tam_Str_Resultado * sizeof(char));
    int i, j;
    for(i = 0; i < tam_Str1; i++){
        *(str3 + i) = *(str1 + i);
    }

    for(j = 0; j < tam_Str2; j++){
        *(str3 + i) = *(str2 + j);
        i++;
    }
    *(str3 + i) = '\0';
    return str3;
}

int main(){
    char tecla, *str1 = malloc(sizeof(char)), *str2 = malloc(sizeof(char));
    printf("INSIRA A PRIMEIRA STRING:\n");
    int auxTam = 0;
    do{
        scanf("%c", &tecla);
        if(tecla == '\n') break;
        str1 = realloc(str1, auxTam + 1);
        *(str1 + auxTam) = tecla;
        auxTam++;
    }while(tecla != '\n');
    *(str1 + auxTam) = '\0';

    printf("INSIRA A SEGUNDA STRING:\n");
    auxTam = 0;
    do{
        scanf("%c", &tecla);
        if(tecla == '\n') break;
        str2 = realloc(str2, auxTam + 1);
        *(str2 + auxTam) = tecla;
        auxTam++;
    }while(tecla != '\n');
    *(str2 + auxTam) = '\0';

    char *str3 = concat(str1, str2);
    printf("VOCE DESEJA VER AS DUAS STRINGS JUNTAS? (S ou N)\n");
    char ask;
    scanf("%c", &ask);
    if(tolower(ask) == 's'){
        printf("STRINGs JUNTAS: %s\n", str3);
    }    

    return EXIT_SUCCESS;
}