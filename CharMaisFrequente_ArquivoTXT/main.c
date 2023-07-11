#include <stdio.h>
#include <stdlib.h>
#define MAX_CHARS 255

int main(void) {
    FILE *fp;
    char filepath[100];
    char ch;
    int count[MAX_CHARS] = {0};
    int max_freq = 0;
    char result;

    // Obtem o caminho do arquivo do usuário
    printf("Entre com o caminho do arquivo: ");
    scanf("%s", filepath);

    // Tenta abrir o arquivo
    fp = fopen(filepath, "r");

    // Verifica se houve falha na abertura do arquivo
    if (fp == NULL) {
        printf("Não foi possível abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    // Lê cada caracter do arquivo e incrementa a contagem
    while ((ch = fgetc(fp)) != EOF) {
        count[ch]++;
    }

    // Encontra o caracter que mais se repetiu
    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] > max_freq) {
            max_freq = count[i];
            result = (char) i;
        }
    }

    // Verifica se há outros caracteres que se repetem o mesmo número de vezes
    printf("O caracter que mais se repetiu foi '%c' (%d vezes).\n", result, max_freq);

    for (int i = 0; i < MAX_CHARS; i++) {
        if (count[i] == max_freq && i != result) {
            printf("Outro caracter que se repetiu %d vezes foi '%c'.\n", max_freq, (char) i);
        }
    }

    // Fecha o arquivo
    fclose(fp);

    return 0;
}
