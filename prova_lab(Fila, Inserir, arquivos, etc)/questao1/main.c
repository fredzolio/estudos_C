#include <stdio.h>
#include <string.h>

#define MAX_NOME 100

int main() {
    FILE *entrada = fopen("ci.txt", "r");
    if (entrada == NULL) {
        return 1;
    }
    
    FILE *saida = fopen("totais.txt", "w");
    if (saida == NULL) {
        return 1;
    }
    
    double total_geral = 0;
    
    char nome[MAX_NOME];
    double num_chamadas, duracao, total_individual;
    while (fscanf(entrada, "%s %lf", nome, &num_chamadas) == 2) {
        total_individual = 0;
        for (int i = 0; i < num_chamadas; i++) {
            fscanf(entrada, "%lf", &duracao);
            total_individual += duracao;
        }
    
        fprintf(saida, "%s %lf\n", nome, total_individual);
        
        total_geral += total_individual;
    }
    
    fprintf(saida, "Total %lf\n", total_geral);
    
    fclose(entrada);
    fclose(saida);
    
    return 0;
}
