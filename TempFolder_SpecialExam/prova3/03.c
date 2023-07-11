#include <stdio.h>
#include <stdlib.h>

/*
TODO:
    OK -> estrutura Aluno {char nome[100], int matricula};
    OK -> lista dinamica de ate 40 alunos;
    inserirAluno();
    removerAluno();
    alterarAluno();
    consultarAluno() -> por matricula;
    consultarAluno() -> por nome;
    listarAlunos();
    contarAlunos();
*/

typedef struct node{
    char nome[100];
    char matricula[30];
    struct node *proximo;
} ALUNO;

void inserirAluno(ALUNO *lista){
    ALUNO *novo = malloc(sizeof(ALUNO));
    if(novo){
        printf("INSIRA O NOME DO ALUNO:\n");
        scanf("%99[^\n]", novo->nome);
        printf("INSIRA A MATRICULA DO ALUNO:\n");
        scanf("%29[^\n]", novo->matricula);
        novo->proximo = lista;
        lista = novo;
    }else{
        printf("NAO FOI POSSIVEL ALOCAR A LISTA!\n");
    }
}

int main(){

    ALUNO *lista = malloc(50 * sizeof(ALUNO));
    //inserirAluno(lista);

    return 0;
}