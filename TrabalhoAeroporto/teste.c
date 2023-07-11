#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
TODO:
    OK -> estrutura Aluno {char nome[100], int matricula};
    OK -> lista dinamica de ate 40 alunos;
    OK -> inserirAluno();
    OK -> removerAluno();
    alterarAluno();
    consultarAluno() -> por matricula;
    consultarAluno() -> por nome;
    OK -> listarAlunos();
    contarAlunos();
*/

typedef struct node{
    char nome[100];
    char matricula[30];
    struct node *proximo;
} ALUNO;

void inserirAluno(ALUNO **lista){
    ALUNO *novo = malloc(sizeof(ALUNO));
    if(novo){
        printf("INSIRA O NOME DO ALUNO:\n");
        scanf("%99[^\n]", novo->nome);
        fflush(stdin);
        printf("INSIRA A MATRICULA DO ALUNO:\n");
        scanf("%29[^\n]", novo->matricula);
        fflush(stdin);
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("NAO FOI POSSIVEL ALOCAR A LISTA!\n");
    }
}

void listarAlunos(ALUNO **lista){
    if(*lista){
        ALUNO *exibir = NULL;
        exibir = *lista;
        while(exibir){
            printf("| ALUNO:  %s\n", exibir->nome);
            printf("| MATRICULA:  %s\n\n", exibir->matricula);
            exibir = exibir->proximo;
        }
    }else{
        printf("Lista vazia!\n");
    }
}

void removerAluno(ALUNO **lista){
    ALUNO *remover = NULL, *aux;
    if(*lista){
        char matricula[30];
        printf("QUAL A MATRICULA DO ALUNO QUE DESEJA REMOVER?\n");
        scanf("%29[^\n]", matricula);
        //printf("---------------------> %s\n", matricula);
        fflush(stdin);
        if(strcmp((*lista)->matricula, matricula) == 0){
            remover = *lista;
            *lista = remover->proximo;
        }else{
            aux = *lista;
            while(aux->proximo && strcmp(aux->proximo->matricula, matricula) != 0){
                aux = aux->proximo;
            }
            if(strcmp(aux->proximo->matricula, matricula) == 0){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
        free(remover);
    }else{
        printf("Lista vazia!\n");
    }
}

void contarAlunos(ALUNO **lista){
    int cont = 0;
    if(*lista){
        ALUNO *contar = NULL;
        contar = *lista;
        while(contar){
            cont++;
            contar = contar->proximo;
        }
        printf("A LISTA TEM %d ALUNOS\n", cont);
    }else{
        printf("Lista vazia!\n");
    }
}

void consultarAlunos_PorNome(ALUNO **lista){
    ALUNO *consulta = NULL, *aux;
    if(*lista){
        char nome[100];
        printf("QUAL O NOME DO ALUNO QUE DESEJA CONSULTAR?\n");
        scanf("%99[^\n]", nome);
        fflush(stdin);
        if(strcmp((*lista)->nome, nome) == 0){
            printf("\n\n| ALUNO:  %s\n", (*lista)->nome);
            printf("| MATRICULA:  %s\n\n", (*lista)->matricula);
        }else{
            aux = *lista;
            while(aux->proximo && strcmp(aux->proximo->nome, nome) != 0){
                aux = aux->proximo;
            }
            if(strcmp(aux->proximo->nome, nome) == 0){
                printf("\n\n| ALUNO:  %s\n", aux->proximo->nome);
                printf("| MATRICULA:  %s\n\n", aux->proximo->matricula);
            }else{
                printf("NAO CONSTA\n");
            }
        }
    }else{
        printf("Lista vazia!\n");
    }
}

int main(){

    int tamLista = 0;
    ALUNO *lista = NULL;
    int opcao;
    do{
        printf("\n\nESCOLHA UMA OPCAO:\n0 - Sair\n1 - INSERIR\n2 - LISTAR\n3 - REMOVER\n4 - CONTAR ALUNOS\n5 - CONSULTAR ALUNOS POR NOME\n");
        scanf("%d", &opcao);
        fflush(stdin);
        printf("\n\n");
        switch (opcao){
        case 1:
            if(tamLista <= 4){
                inserirAluno(&lista);
                tamLista++;
            }else{
                printf("LISTA CHEIA!");
            }
            break;
        case 2:
            listarAlunos(&lista);
            break;
        case 3:
            removerAluno(&lista);
            break;
        case 4:
            contarAlunos(&lista);
            break;
        case 5:
            consultarAlunos_PorNome(&lista);
            break;
        default:
            if(opcao != 0){
                printf("OPCAO INVALIDA!\n");
            }
        }
    }while(opcao != 0);

    return 0;
}