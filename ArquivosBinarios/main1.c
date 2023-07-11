#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato
{
    char nome[50];
    int dia, mes, ano;
} CONTATO;

void escrever(char arq[]){
    CONTATO c;
    FILE *arquivo = fopen(arq, "ab");

    if(arquivo){
        printf("\nDigite o NOME e a DATA DE NASCIMENTO no formato DD MM AAAA:\n");
        scanf("%49[^\n]%d%d%d", c.nome, &c.dia, &c.mes, &c.ano);
        fwrite(&c, sizeof(CONTATO), 1, arquivo);
        fclose(arquivo);
    }else{
        printf("\nErro ao abrir o arquivo!\n");
    }
}

void ler(char arq[]){
    CONTATO c;
    FILE *arquivo = fopen(arq, "rb");
    
    if(arquivo){
        while(!feof(arquivo)){
            if(fread(&c, sizeof(CONTATO), 1, arquivo)){
                printf("\nNome: %s\nData: %d/%d/%d\n", c.nome, c.dia, c.mes, c.ano);
            }
        }
    }else{
        printf("\nNao foi possivel abrir o arquivo\n");
    }
    fclose(arquivo);
}

int main(){
    char arquivo[] = {"agenda.dat"};
    //escrever(arquivo);
    ler(arquivo);
    return 0;
}
