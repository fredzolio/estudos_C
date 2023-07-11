#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void sub1(char str[], int tam){
    int inicio = 0, fim = 0;
    while(fim <= tam){
        for(int i = inicio; i <= fim; i++){
            putchar(str[i]);
        }
        printf(" ");
        fim++;
    }

    inicio = 0; fim = tam - 1;
    while(fim >= 0){
        for(int i = inicio; i <= fim; i++){
            putchar(str[i]);
        }
        printf(" ");
        fim--;
    }

}

int main() {

    char str[100];
    fgets(str, 100, stdin);
    int tam = strlen(str) - 2;
    sub1(str, tam);

    return 0;
}





#include <stdio.h>
#include <string.h>

int countSubstrings(const char *str, const char *sub) {
    int count = 0;
    int subLength = strlen(sub);
    int strLength = strlen(str);

    if (subLength > strLength) {
        return 0;  // Substring é maior do que a palavra/frase
    }

    for (int i = 0; i <= strLength - subLength; i++) {
        if (strncmp(&str[i], sub, subLength) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];
    char sub[100];

    printf("Digite a palavra ou frase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';  // Remover a nova linha do final da string

    printf("Digite a substring: ");
    fgets(sub, sizeof(sub), stdin);
    sub[strcspn(sub, "\n")] = '\0';  // Remover a nova linha do final da string

    int result = countSubstrings(str, sub);
    printf("Número de substrings encontradas: %d\n", result);

    return 0;
}
















#include <stdio.h>
#include <string.h>

int countSubstrings(const char *str) {
    int count = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j <= length; j++) {
            printf("%.*s\n", j - i, &str[i]);
            count++;
        }
    }

    return count;
}

int main() {
    char str[100];

    printf("Digite a palavra ou frase: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    int result = countSubstrings(str);
    printf("Número de substrings encontradas: %d\n", result);

    return 0;
}
