#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int num_matricula;
    int nota;
    int cod_disciplina;
    struct node *proximo;
} NODE;

void inserir(NODE **lista, int num_matricula, int nota, int cod_disciplina){
    NODE *novo = malloc(sizeof(NODE));
    fflush(stdin);
    if(novo){
        novo->num_matricula = num_matricula;
        novo->nota = nota;
        novo->cod_disciplina = cod_disciplina;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("\nNAO FOI POSSIVEL ALOCAR MEMORIA\n");
    }
}


void excluir(NODE **lista, int matricula){
    NODE *aux, *remover = NULL;
        if(*lista){
        if((*lista)->num_matricula == matricula){
            remover = *lista;
            *lista = remover->proximo;
        }else{
            aux = *lista;
            while(aux->proximo && aux->proximo->num_matricula != matricula){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    free(remover);
}

void exibirTudo(NODE **lista){
    if(*lista){
        NODE *exibir = NULL;
        exibir = *lista;
        while(exibir){
            printf("\nNUMERO MATRICULA: %d\nNOTA: %d\nCOD DISCIPLINA: %d\n\n", exibir->num_matricula, exibir->nota, exibir->cod_disciplina);
            exibir = exibir->proximo;
        }
    } else{
        printf("\nLISTA VAZIA\n");
    }
}

void buscaPorDisciplina(NODE **lista, int disciplina){
    if(*lista){
        NODE *exibir = NULL;
        exibir = *lista;
        while(exibir){
            if(exibir->cod_disciplina == disciplina){
                printf("\nNUMERO MATRICULA: %d\nNOTA: %d\n\n", exibir->num_matricula, exibir->nota);
            }
            exibir = exibir->proximo;
        }
    } else{
        printf("\nLISTA VAZIA\n");
    }
}


int main(){
    NODE *lista = NULL;
    inserir(&lista, 1, 6, 1);
    exibirTudo(&lista);
    inserir(&lista, 2, 7, 2);
    exibirTudo(&lista);
    inserir(&lista, 3, 8, 1);
    exibirTudo(&lista);
    inserir(&lista, 4, 9, 3);
    exibirTudo(&lista);
    inserir(&lista, 5, 10, 1);
    exibirTudo(&lista);
    inserir(&lista, 2, 11, 2);
    exibirTudo(&lista);
    inserir(&lista, 4, 12, 2);
    exibirTudo(&lista);
    printf("---------------\n");
    buscaPorDisciplina(&lista, 1);
    buscaPorDisciplina(&lista, 2);
    printf("---------------\n");
    excluir(&lista, 4);
    excluir(&lista, 4);
    exibirTudo(&lista);
    printf("---------------\n");
    excluir(&lista, 1);
    exibirTudo(&lista);
    return 0;
}