#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//QUESTAO 3 - FREDERICO ZOLIO

/*
    TODO:
            [X] Criar Lista
            [X] Inserir Usuario
            [X] Remover Usuario
            [X] Buscar por CPF
            [X] Listar o total de alunos por curso
            OBS: Arquivos em binario
            [X] Gravar lista em arquivo
            [X] Ler lista de um arquivo
            [X] Listar usuarios de um arquivo ---> COM ERRO
            [X] Contar do arquivo quantos alunos de Eng. da Computacao estão cadastrados

*/

//PROFESSORA, NESSE CODIGO TEM TODAS A FUNCIONALIDADES PEDIDAS, BASTA SEGUIR O MENU;

typedef struct node {
    char nome[30];
    char cpf[12];
    char curso[30];
    struct node *proximo;
} NODE;

void inserirUser_InserirInicio(NODE **lista){
    NODE *novo = malloc(sizeof(NODE));
    char nomeTMP[30];
    char cpf[12];
    char curso[30];
    FILE *arquivo = fopen("biblioteca.bin", "ab");
    fflush(stdin);
    printf("Insira o nome do usuario:\n");
    fgets(nomeTMP, 30, stdin);
    fflush(stdin);
    printf("Insira o CPF do usuario:\n");
    fgets(cpf, 12, stdin);
    printf("Insira o curso do usuario:\n");
    fflush(stdin);
    fgets(curso, 30, stdin);
    fflush(stdin);
    if(novo){
        strcpy(novo->nome, nomeTMP);
        strcpy(novo->cpf, cpf);
        strcpy(novo->curso, curso);
        novo->proximo = *lista;
        *lista = novo;
        fwrite(novo, sizeof(NODE), 1, arquivo);
    }else{
        printf("\tERRO-->\tNao foi possivel alocar memoria!\n");
    }
    fclose(arquivo);
}

NODE *excluirUserPorCPF(NODE **lista){
    NODE *aux, *remover = NULL;
    printf("\tDigite o CPF do usuario a ser excluido: ");
    char cpfR[12];
    fgets(cpfR, 12, stdin);
    fflush(stdin);
    if(*lista){
        if(strcmp((*lista)->cpf, cpfR) == 0){  
            remover = *lista;
            *lista = remover->proximo;
        }else{
            aux = *lista;
            while(aux->proximo && (strcmp(aux->proximo->cpf, cpfR) != 0)){  
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
    char cpfB[12];
    fflush(stdin);
    fgets(cpfB, 12, stdin);
    fflush(stdin);
    if(*lista){
        if(strcmp((*lista)->cpf, cpfB) == 0){
            buscar = *lista;
            printf("\t\nDados do usuario:\n\nNome: %sCPF: %s\nCurso: %s", buscar->nome, cpfB, buscar->curso);
        }else{
            buscar = *lista;
            while(buscar->proximo && (strcmp(buscar->proximo->cpf, cpfB) != 0)){
                buscar = buscar->proximo;
            }
            if(buscar->proximo){
                printf("\t\nDados do usuario:\n\nNome: %sCPF: %s\nCurso: %s", buscar->proximo->nome, cpfB, buscar->proximo->curso);
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

void carregarArquivo(NODE **lista, char arq[]) {
    FILE *arquivo;
    arquivo = fopen(arq, "rb");
    
    if (arquivo) {
        NODE novo;
        while (fread(&novo, sizeof(NODE), 1, arquivo)) {
            NODE *novoNo = malloc(sizeof(NODE));
            if (novoNo) {
                strcpy(novoNo->nome, novo.nome);
                strcpy(novoNo->cpf, novo.cpf);
                strcpy(novoNo->curso, novo.curso);
                novoNo->proximo = *lista;
                *lista = novoNo;
            } else {
                printf("\n\tERRO ------> Nao foi possivel alocar memoria");
                break;
            }
        }
        fclose(arquivo);
    } else {
        printf("\n\tERRO ------> Nao foi possivel ler o arquivo");
    }
}


void lerArquivo(char arq[]){
    NODE c;
    FILE *arquivo = fopen(arq, "rb");
    int i = 1;
    if(arquivo){
        while(!feof(arquivo)){
            if(fread(&c, sizeof(NODE), 1, arquivo)){
                printf("\t\n\tID: %d\t\n\tNome: %s\tCPF: %s\t\n\tCurso: %s", i, c.nome, c.cpf, c.curso);
                printf("\n\t----------------------------------------------------------------\n");
                i++;
            }
        }
    }

    fclose(arquivo);
}

void exibirLista(NODE **lista) {
    NODE *c;
    int i = 1;
    
    if (*lista) {
        c = *lista;
        printf("\t\n\tID: %d\t\n\tNome: %s\tCPF: %s\t\n\tCurso: %s", i, c->nome, c->cpf, c->curso);
        printf("\n\t----------------------------------------------------------------\n");
        c = c->proximo;
    } else {
        printf("\n\tA lista esta vazia!\n");
        return;
    }
    while (c) {
        i++;
        printf("\t\n\tID: %d\t\n\tNome: %s\tCPF: %s\t\n\tCurso: %s", i, c->nome, c->cpf, c->curso);
        printf("\n\t----------------------------------------------------------------\n");
        c = c->proximo;
    }
}

void alunosComp(char arq[]){
    char curso[] = {"Eng. Computacao\n"};
    NODE c;
    int cont = 0;
    FILE *arquivo;
    arquivo = fopen(arq, "rb");
    if(arquivo){
        while(!feof(arquivo)){
            if(fread(&c, sizeof(NODE), 1, arquivo)){
                if(strcmp(c.curso, curso) == 0){
                    cont++;
                }
            }
        }
    }else{
        printf("\n\tERRO -------> Nao foi possivel ler o arquivo\n");
    }
    printf("\n\tO curso de [Eng. Computacao] tem '%d' alunos cadastrados!\n", cont);
    fclose(arquivo);
}

int main(){
    NODE *lista = NULL;
    char arq[] = {"biblioteca.bin"};
    int opcao;
    fflush(stdin);
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tMenu\n\n");
        printf("\t\t     0 -> Sair\n");
        printf("\t\t     1 -> Inserir Usuarios\n");
        printf("\t\t     2 -> Excluir Usuario (Por CPF)\n");
        printf("\t\t     3 -> Buscar (Por CPF)\n");
        printf("\t\t     4 -> Contar o total (Por curso)\n");
        printf("\t\t     5 -> Ler lista de usuarios de um arquivo\n");
        printf("\t\t     6 -> Exibir total de alunos de [Eng. Computacao] de um arquivo\n");
        printf("\t\t     7 -> Exibir toda a lista\n");
        printf("\t\t     8 -> Carregar arquivo\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao)
        {
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
            case 5:
                lerArquivo(arq);
                break;
            case 6:
                alunosComp(arq);
                break;
            case 7:
                exibirLista(&lista);
                break;
            case 8:
                carregarArquivo(&lista, arq);
                break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }
        ///OPCOES

    }while(opcao != 0);

    printf("\t<3 Obrigado por usar o sistema! <3\n\n");

    return 0;
}