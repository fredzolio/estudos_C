#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Questoes 2

/*
    TODO:
            [X] Criar Lista
            [X] Inserir Usuario
            [X] Remover Usuario
            [X] Buscar por CPF
            [X] Listar o total de alunos por curso
            OBS: Arquivos em binario NA QUESTAO 3...
            [ ] Gravar lista em arquivo
            [ ] Ler lista de um arquivo
            [ ] Listar usuarios de um arquivo
            [ ] Contar do arquivo quantos alunos de Eng. da Computacao estão cadastrados

*/

typedef struct node {
    char nome[30];
    long long int cpf;
    char curso[30];
    struct node *proximo;
} NODE;

void inserirUser_InserirInicio(NODE **lista){
    NODE *novo = malloc(sizeof(NODE));
    char nomeTMP[30];
    long long int cpf;
    char curso[30];
    fflush(stdin);
    printf("\n\tInsira o nome do usuario:\n");
    fgets(nomeTMP, 30, stdin);
    fflush(stdin);
    printf("\n\tInsira o CPF do usuario:\n");
    scanf("%lld", &cpf);
    printf("\n\tInsira o curso do usuario:\n");
    fflush(stdin);
    fgets(curso, 30, stdin);
    fflush(stdin);
    if(novo){
        strcpy(novo->nome, nomeTMP);
        novo->cpf = cpf;
        strcpy(novo->curso, curso);
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("\tERRO-->\tNao foi possivel alocar memoria!\n");
    }
}

NODE *excluirUserPorCPF(NODE **lista){
    NODE *aux, *remover = NULL;
    printf("\tDigite o CPF do usuario a ser excluido: ");
    long long int cpfR;
    scanf("%lld", &cpfR);
    fflush(stdin);
    if(*lista){
        if((*lista)->cpf == cpfR){
            remover = *lista;
            *lista = remover->proximo;
        }else{
            aux = *lista;
            while(aux->proximo && aux->proximo->cpf != cpfR){
                aux = aux->proximo;
            }
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

void buscarCPF(NODE **lista){
    NODE *buscar = NULL;
    printf("\tDigite o CPF do usuario para buscar seus dados: ");
    long long int cpfB;
    fflush(stdin);
    scanf("%lld", &cpfB);
    fflush(stdin);
    if(*lista){
        if((*lista)->cpf == cpfB){
            buscar = *lista;
            printf("\t\nDados do usuario:\n\nNome: %sCPF: %lld\nCurso: %s", buscar->nome, cpfB, buscar->curso);
        }else{
            buscar = *lista;
            while(buscar->proximo && buscar->proximo->cpf != cpfB){
                buscar = buscar->proximo;
            }
            if(buscar->proximo){
                printf("\t\nDados do usuario:\n\nNome: %sCPF: %lld\nCurso: %s", buscar->proximo->nome, cpfB, buscar->proximo->curso);
            }else{
                printf("\t\n\tCPF nao encontrado!\n");
            }
        }
    }
}

void totalCurso(NODE **lista){
    NODE *total = NULL;
    total = *lista;
    char curso[30], cursoAUX[30];
    int i = 0, cont = 0;
    printf("\tDigite o curso o qual deseja contar a quantidade de usuarios: ");
    fflush(stdin);
    fgets(curso, 30, stdin);
    fflush(stdin);
    while(total){
        if(strcmp(total->curso, curso) == 0){
            cont++;
            total = total->proximo;
        }else{
            total = total->proximo;
        }
    }
    printf("\n\tO curso informado tem %d alunos cadastrados.\n", cont);
}

int main(){
    NODE *lista = NULL;
    int opcao;
    fflush(stdin);
    do{
        printf("\n\t---------------------------------------------------------------------\n");
        printf("\n\tEscolha a opcao desejada:\n\n\t1 --> Inserir Usuario\n\t2 --> Excluir Usuario (Por CPF)\n\t3 --> Buscar (Por CPF)\n\t4 --> Contar o total (Por curso)\n\t5 --> Gravar lista de usuarios\n\t6 --> Ler lista de usuarios de um arquivo\n\t7 --> Exibir total de alunos de Eng. Computacao de um arquivo\n\n\t0 --> Cancelar e encerrar programa\n\n");
        fflush(stdin);
        scanf("%d", &opcao);
        printf("\n");
        fflush(stdin);
        switch (opcao){
            case 1:
                inserirUser_InserirInicio(&lista);
                break;
            case 2:
                NODE *remover;
                remover = excluirUserPorCPF(&lista);
                if(remover){
                printf("\tUsuario a ser removido:\n\n\tNome: %s\tCurso: %s", remover->nome, remover->curso);
                free(remover);
                }
                break;
            case 3:
                buscarCPF(&lista);
                break;
            case 4:
                totalCurso(&lista);
                break;
            default:
                if(opcao != 0){
                    printf("\tOpcao invalida!\n");
                }
        }
    }while(opcao != 0);

    return 0;
}