#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

int main () {
    char palavra[25], *p_str;
    fgets(palavra, 25, stdin);
    int sTam = strlen(palavra) - 2;
    p_str = palavra;
    while (*p_str != '\n'){
        p_str++;
    }
    p_str--;
    for (int i = sTam; i >= 0; i--){
        putchar(*p_str--);
    }
    return 0;
}