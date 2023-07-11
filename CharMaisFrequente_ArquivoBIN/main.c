#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 256 // Define o número máximo de caracteres possíveis (256 na tabela ASCII)

int main() {
    FILE *fp;
    int freq[MAX_CHAR] = {0}; // Vetor de frequência de cada caracter
    int max_freq = 0; // Frequência máxima encontrada
    int i, c;

    fp = fopen("arquivo.bin", "rb"); // Abre o arquivo binário para leitura em modo binário

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê cada caracter do arquivo e atualiza o vetor de frequência
    while ((c = fgetc(fp)) != EOF) {
        freq[c]++;
    }

    // Encontra a frequência máxima e atualiza a variável max_freq
    for (i = 0; i < MAX_CHAR; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }

    // Exibe o(s) caracter(es) com frequência máxima
    printf("Caracter(es) que apareceu/ram mais: ");
    for (i = 0; i < MAX_CHAR; i++) {
        if (freq[i] == max_freq) {
            printf("%c ", i);
        }
    }
    printf("\n");

    // Fecha o arquivo
    fclose(fp);

    return 0;
}
