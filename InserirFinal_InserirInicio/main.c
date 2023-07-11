#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct main
{
    int num;
    struct main *proximo;
} NUM;

void insereFinal(NUM **lista, int num){
    NUM *aux, *novo = malloc(sizeof(NUM));
    if(novo){
        novo->num = num;
        novo->proximo = NULL;
        if(*lista == NULL){
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    } else{
        printf("\tERRO -->\tNao foi possivel alocar memoria!\n");
    }
}

void insereInicio(NUM **lista, int num){
    NUM *novo = malloc(sizeof(NUM));
    if(novo){
        novo->num = num;
        novo->proximo = *lista;
        *lista = novo;
    } else{
        printf("\tERRO -->\tNao foi possivel alocar memoria!\n");
    }
}

void imprimir(NUM **lista){
    NUM *aux;
    aux = *lista;
    if(aux){
        while(aux->proximo){
            printf("%d", aux->num);
            aux = aux->proximo;
        }
    }
}

void remover(NUM **lista, int x){
    NUM *rem = NULL, *aux;
    if(*lista){
        if((*lista)->num == x){
            rem = *lista;
            *lista = rem->proximo;
        } else{
            aux = *lista;
            while(aux->proximo && aux->proximo->num != x){
                aux = aux->proximo;
            }
            if(aux->proximo){
                rem = aux->proximo;
                aux->proximo = rem->proximo;
            }
        }
    }
    free(rem);
}

int main(){
    NUM *lista = NULL;
    int opcao;
    fflush(stdin);
    do{
        printf("\n\t---------------------------------------------------------------------\n");
        printf("\n\tMENU(digite a opcao e tecle ENTER) | 0 --> SAIR |:\n\n\t1 --> Inserir Numero\n\t2 --> Excluir Numero\n\t3 --> Listar tudo\n");
        fflush(stdin);
        scanf("%d", &opcao);
        printf("\n\t----------------------------------------------------------------\n");
        fflush(stdin);
        switch (opcao){
            case 1:
                printf("\n\n\tInsira o numero: ");
                fflush(stdin);
                int num;
                scanf("%d", &num);
                if(num % 2 == 0){
                    insereFinal(&lista, num);
                } else{
                    insereInicio(&lista, num);
                }
                break;
            case 2:
                int remNum;
                printf("\n\nQual numero voce quer retirar da lista?\n");
                scanf("%d", &remNum);
                remover(&lista, remNum);
                break;
            case 3:
                imprimir(&lista);
                printf("\n");
                break;
            default:
                if(opcao != 0){
                    printf("\tOpcao invalida!\n");
                }
        }
    }while(opcao != 0);
    return 0;
}

