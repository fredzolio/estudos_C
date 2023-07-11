#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    X = COMPLETO; X/2 = METADE COMPLETO; X/4 = MENOS DA METADE COMPLETO

    TODO:
        [X] Criar struct para VOO;
        [X] Criar struct para PASSAGEIRO;
        [X] Criar struct para PASSAGEM;
        Modificacoes nas listas:
            [X] Criar INSERIR VOO;
            [X] Criar ALTERAR VOO;
            [X] Criar EXCLUIR VOO;
            [X] Criar CONSULTA VOO;
            -
            [X] Criar INSERIR PASSAGEIRO;
            [X] Criar ALTERAR PASSAGEIRO;
            [X] Criar EXCLUIR PASSAGEIRO;
            [X] Criar CONSULTA PASSAGEIRO;
            -
            [X] Criar INSERIR PASSAGEM;
            [X] Criar ALTERAR PASSAGEM;
            [X] Criar EXCLUIR PASSAGEM;
            [X] Criar CONSULTA PASSAGEM;
        [X] Aloc. Dinamica --> 50 VOOS;
        [X] Aloc. Dinamica --> 100 PASSAGEIROS;
        [X] Aloc. Dinamica --> 100 PASSAGENS;
        [X] Criar RELATORIO;
        [X] Criar MENU PRINCIPAL;
        [X] Criar MENU VOO;
        [X] Criar MENU PASSAGEIROS;
        [X] Criar MENU PASSAGEM;
        [X] Popular MENU;
        Relatorio:
            [X] Quantidade de passagens vendidas por voo;
            [X] Quantidade de voos por empresa;
            [X] Lista de passageiros por voo;

*/

typedef struct data{
    int dia, mes, ano;
} DATA;

typedef struct hora{
    int hora;
    int min;
} HORARIO;

typedef struct voo{
    int id_voo;
    int id_aeronave;
    char empresa[30];
    char origem[50];
    char destino[50];
    DATA dataPartida;
    HORARIO horarioPartida;
    int qtdPassageiros;
    struct voo *proximo_voo;
} VOO;

typedef struct passageiro{
    int id_passageiro;
    char nome[38];
    char identidade[12];
    char endereco[70];
    char telefone[12];
    char sexo[30];
    struct passageiro *proximo_passageiro;
} PASSAGEIRO;

typedef struct passagem{
    int id_passagem;
    int id_DoPassageiro;
    int id_DoVoo;
    double valor;
    DATA dataVenda;
    struct passagem *proxima_passagem;
} PASSAGEM;


////////////////////////////////////////////////////////////////
////////////////////FUNCOES E PROCEDIMENTOS/////////////////////

void incluirVOO(VOO ****lista){
    VOO *novo = malloc(sizeof(VOO));
    int id_voo, id_aeronave, qtdPassageiros;
    char empresa[30], origem[50], destino[50];
    DATA dataPartida;
    HORARIO horarioPartida;
    printf("INSIRA ID DO VOO:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    printf("INSIRA ID DA AERONAVE:\n");
    scanf("%d", &id_aeronave);
    fflush(stdin);
    printf("INSIRA O NOME DA EMPRESA:\n");
    fgets(empresa, 30, stdin);
    fflush(stdin);
    printf("INSIRA A ORIGEM DO VOO:\n");
    fgets(origem, 50, stdin);
    fflush(stdin);
    printf("INSIRA O DESTINO DO VOO:\n");
    fgets(destino, 50, stdin);
    fflush(stdin);
    printf("INSIRA A DATA DE PARTIDA(DD MM AAAA):\n");
    scanf("%d %d %d", &dataPartida.dia, &dataPartida.mes, &dataPartida.ano);
    fflush(stdin);
    printf("INSIRA O HORARIO DE PARTIDA(HH MM):\n");
    scanf("%d %d", &horarioPartida.hora, &horarioPartida.min);
    fflush(stdin);
    //printf("INSIRA A QUANTIDADE DE PASSAGEIROS NO VOO:\n");
    //scanf("%d", &qtdPassageiros);
    //fflush(stdin);

    if(novo){
        novo->id_voo = id_voo;
        novo->id_aeronave = id_aeronave;
        strcpy(novo->empresa, empresa);
        strcpy(novo->origem, origem);
        strcpy(novo->destino, destino);
        novo->dataPartida.dia = dataPartida.dia;
        novo->dataPartida.mes = dataPartida.mes;
        novo->dataPartida.ano = dataPartida.ano;
        novo->horarioPartida.hora = horarioPartida.hora;
        novo->horarioPartida.min = horarioPartida.min;
        //novo->qtdPassageiros = qtdPassageiros;
        novo->qtdPassageiros = 0;
        novo->proximo_voo = ***lista;
        ***lista = novo;
    }else{
        printf("\t\tERRO --> NAO FOI POSSIVEL ALOCAR MEMORIA!\n\n\n");
    }
}

void consultarVOO(VOO ****lista){
    VOO *consulta = NULL;
    int id_voo;
    printf("INSIRA ID DO VOO PARA EFETUAR A BUSCA:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_voo == id_voo){
            consulta = ***lista;
            printf("\t------------------VOO %d------------------\n", id_voo);
            printf("\t\t   ID DA AERONAVE: %d\n", consulta->id_aeronave);
            printf("\t\t   EMPRESA: %s", consulta->empresa);
            printf("\t\t   ORIGEM: %s", consulta->origem);
            printf("\t\t   DESTINO: %s", consulta->destino);
            printf("\t\t   DATA DE PARTIDA: %d/%d/%d\n", consulta->dataPartida.dia, consulta->dataPartida.mes, consulta->dataPartida.ano);
            printf("\t\t   HORARIO DE PARTIDA: %d:%d\n", consulta->horarioPartida.hora, consulta->horarioPartida.min);
            printf("\t\t   QTD. PASSAGEIROS: %d\n", consulta->qtdPassageiros);
        } else{
            consulta = ***lista;
            while(consulta->proximo_voo && consulta->proximo_voo->id_voo != id_voo){
                consulta = consulta->proximo_voo;
            }
            if(consulta->proximo_voo){
                printf("\t------------------VOO %d----------------------\n", id_voo);
                printf("\t\t   ID DA AERONAVE: %d\n", consulta->proximo_voo->id_aeronave);
                printf("\t\t   EMPRESA: %s", consulta->proximo_voo->empresa);
                printf("\t\t   ORIGEM: %s", consulta->proximo_voo->origem);
                printf("\t\t   DESTINO: %s", consulta->proximo_voo->destino);
                printf("\t\t   DATA DE PARTIDA: %d/%d/%d\n", consulta->proximo_voo->dataPartida.dia, consulta->proximo_voo->dataPartida.mes, consulta->proximo_voo->dataPartida.ano);
                printf("\t\t   HORARIO DE PARTIDA: %d:%d\n", consulta->proximo_voo->horarioPartida.hora, consulta->proximo_voo->horarioPartida.min);
                printf("\t\t   QTD. PASSAGEIROS: %d\n", consulta->proximo_voo->qtdPassageiros);
            }else{
                printf("\t--------------VOO %d NAO ENCONTRADO--------------\n", id_voo);
            }
        }
    } else{
        printf("\t--------------VOO %d NAO ENCONTRADO--------------\n", id_voo);
    }
}

VOO *excluirVOO(VOO ****lista){
    VOO *remover = NULL;
    VOO *aux;
    int id_voo;
    printf("INSIRA ID DO VOO A SER DELETADO:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_voo == id_voo){
            remover = ***lista;
            ***lista = remover->proximo_voo;
        }else{
            aux = ***lista;
            while(aux->proximo_voo && aux->proximo_voo->id_voo != id_voo){
                aux = aux->proximo_voo;
            }
            if(aux->proximo_voo){
                remover = aux->proximo_voo;
                aux->proximo_voo = remover->proximo_voo;
            }
        }
    }else{
        printf("\t\tERRO --> A LISTA ESTA VAZIA!\n\n\n");
    }
    return remover;
}

void alterarVOO(VOO ****lista){
    VOO *alterar = NULL, *listaT;
    listaT = ***lista;
    int id_voo, id_aeronave, qtdPassageiros;
    char empresa[30], origem[50], destino[50];
    DATA dataPartida;
    HORARIO horarioPartida;
    printf("INSIRA ID DO VOO A SER MODIFICADO:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    if(***lista){
        if(listaT->id_voo == id_voo){
            printf("\t----------------ALTERANDO VOO %d----------------\n", id_voo);
            printf("\t\t   ID DA AERONAVE: %d\n", listaT->id_aeronave);
            printf("\t\t   EMPRESA: %s", listaT->empresa);
            printf("\t\t   ORIGEM: %s", listaT->origem);
            printf("\t\t   DESTINO: %s", listaT->destino);
            printf("\t\t   DATA DE PARTIDA: %d/%d/%d\n", listaT->dataPartida.dia, listaT->dataPartida.mes, listaT->dataPartida.ano);
            printf("\t\t   HORARIO DE PARTIDA: %d:%d\n", listaT->horarioPartida.hora, listaT->horarioPartida.min);
            printf("\t\t   QTD. PASSAGEIROS: %d\n", listaT->qtdPassageiros);
            printf("\n");
            printf("INSIRA O NOVO ID DA AERONAVE:\n");
            scanf("%d", &id_aeronave);
            fflush(stdin);
            printf("INSIRA O NOVO NOME DA EMPRESA:\n");
            fgets(empresa, 30, stdin);
            fflush(stdin);
            printf("INSIRA A NOVA ORIGEM DO VOO:\n");
            fgets(origem, 50, stdin);
            fflush(stdin);
            printf("INSIRA O NOVO DESTINO DO VOO:\n");
            fgets(destino, 50, stdin);
            fflush(stdin);
            printf("INSIRA A NOVA DATA DE PARTIDA(DD MM AAAA):\n");
            scanf("%d %d %d", &dataPartida.dia, &dataPartida.mes, &dataPartida.ano);
            fflush(stdin);
            printf("INSIRA O NOVO HORARIO DE PARTIDA(HH MM):\n");
            scanf("%d %d", &horarioPartida.hora, &horarioPartida.min);
            fflush(stdin);
            //printf("INSIRA A NOVA QUANTIDADE DE PASSAGEIROS NO VOO:\n");
            //scanf("%d", &qtdPassageiros);
            //fflush(stdin);
            listaT->id_voo = id_voo;
            listaT->id_aeronave = id_aeronave;
            strcpy(listaT->empresa, empresa);
            strcpy(listaT->origem, origem);
            strcpy(listaT->destino, destino);
            listaT->dataPartida.dia = dataPartida.dia;
            listaT->dataPartida.mes = dataPartida.mes;
            listaT->dataPartida.ano = dataPartida.ano;
            listaT->horarioPartida.hora = horarioPartida.hora;
            listaT->horarioPartida.min = horarioPartida.min;
            //listaT->qtdPassageiros = qtdPassageiros;
        }else{
            while(listaT->id_voo != id_voo && listaT){
                listaT = listaT->proximo_voo;
            }
            if(listaT){
                if(listaT->id_voo == id_voo){
                    printf("\t----------------ALTERANDO VOO %d----------------\n", id_voo);
                    printf("\t\t   ID DA AERONAVE: %d\n", listaT->id_aeronave);
                    printf("\t\t   EMPRESA: %s", listaT->empresa);
                    printf("\t\t   ORIGEM: %s", listaT->origem);
                    printf("\t\t   DESTINO: %s", listaT->destino);
                    printf("\t\t   DATA DE PARTIDA: %d/%d/%d\n", listaT->dataPartida.dia, listaT->dataPartida.mes, listaT->dataPartida.ano);
                    printf("\t\t   HORARIO DE PARTIDA: %d:%d\n", listaT->horarioPartida.hora, listaT->horarioPartida.min);
                    printf("\t\t   QTD. PASSAGEIROS: %d\n", listaT->qtdPassageiros);
                    printf("\n");
                    printf("INSIRA O NOVO ID DA AERONAVE:\n");
                    scanf("%d", &id_aeronave);
                    fflush(stdin);
                    printf("INSIRA O NOVO NOME DA EMPRESA:\n");
                    fgets(empresa, 30, stdin);
                    fflush(stdin);
                    printf("INSIRA A NOVA ORIGEM DO VOO:\n");
                    fgets(origem, 50, stdin);
                    fflush(stdin);
                    printf("INSIRA O NOVO DESTINO DO VOO:\n");
                    fgets(destino, 50, stdin);
                    fflush(stdin);
                    printf("INSIRA A NOVA DATA DE PARTIDA(DD MM AAAA):\n");
                    scanf("%d %d %d", &dataPartida.dia, &dataPartida.mes, &dataPartida.ano);
                    fflush(stdin);
                    printf("INSIRA O NOVO HORARIO DE PARTIDA(HH MM):\n");
                    scanf("%d %d", &horarioPartida.hora, &horarioPartida.min);
                    fflush(stdin);
                    //printf("INSIRA A NOVA QUANTIDADE DE PASSAGEIROS NO VOO:\n");
                    //scanf("%d", &qtdPassageiros);
                    //fflush(stdin);
                    listaT->id_voo = id_voo;
                    listaT->id_aeronave = id_aeronave;
                    strcpy(listaT->empresa, empresa);
                    strcpy(listaT->origem, origem);
                    strcpy(listaT->destino, destino);
                    listaT->dataPartida.dia = dataPartida.dia;
                    listaT->dataPartida.mes = dataPartida.mes;
                    listaT->dataPartida.ano = dataPartida.ano;
                    listaT->horarioPartida.hora = horarioPartida.hora;
                    listaT->horarioPartida.min = horarioPartida.min;
                    //listaT->qtdPassageiros = qtdPassageiros;
                }
            }
        }
    }else{
        printf("\t--------------VOO %d NAO ENCONTRADO--------------\n", id_voo);
    }
}

void incluirPASSAGEM(PASSAGEM ****lista, VOO ****lista_voo){
    PASSAGEM *novo = malloc(sizeof(PASSAGEM));
    int id_passagem, id_passageiro, id_voo;
    double valor;
    DATA dataVenda;
    printf("INSIRA ID/NUMERO DA PASSAGEM:\n");
    scanf("%d", &id_passagem);
    fflush(stdin);
    printf("INSIRA ID DO PASSAGEIRO:\n");
    scanf("%d", &id_passageiro);
    fflush(stdin);
    printf("INSIRA ID DO VOO DA PASSAGEM:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    printf("INSIRA A DATA DA VENDA DA PASSAGEM(DD MM AAAA):\n");
    scanf("%d %d %d", &dataVenda.dia, &dataVenda.mes, &dataVenda.ano);
    fflush(stdin);
    printf("INSIRA O VALOR DA PASSAGEM(R$):\n");
    scanf("%lf", &valor);
    fflush(stdin);
    
    VOO *vooIncluirP = NULL, *lista_voo_local = ***lista_voo;
    if(lista_voo_local->id_voo == id_voo){
        vooIncluirP = lista_voo_local;
        vooIncluirP->qtdPassageiros++;
    } else{
        vooIncluirP = lista_voo_local;
        while(vooIncluirP->proximo_voo && vooIncluirP->proximo_voo->id_voo != id_voo){
            vooIncluirP = vooIncluirP->proximo_voo;
        }
        if(vooIncluirP->proximo_voo){
            vooIncluirP->qtdPassageiros++;
        }else{
            printf("\t\n\tERRO --> O VOO '%d' AINDA NAO EXISTE, INCLUA-O ANTES DE ADICIONAR PASSAGENS A ELE!\n\n\n", id_voo);
            return;
        }
    }

    if(novo){
        novo->id_passagem = id_passagem;
        novo->id_DoPassageiro = id_passageiro;
        novo->id_DoVoo = id_voo;
        novo->dataVenda.dia = dataVenda.dia;
        novo->dataVenda.mes = dataVenda.mes;
        novo->dataVenda.ano = dataVenda.ano;
        novo->valor = valor;
        novo->proxima_passagem = ***lista;
        ***lista = novo;
    }else{
        printf("\t\tERRO --> NAO FOI POSSIVEL ALOCAR MEMORIA!\n\n\n");
    }
}

void consultarPASSAGEM(PASSAGEM ****lista){
    PASSAGEM *consulta = NULL;
    int id_passagem;
    printf("INSIRA ID/NUMERO DA PASSAGEM PARA EFETUAR A BUSCA:\n");
    scanf("%d", &id_passagem);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_passagem == id_passagem){
            consulta = ***lista;
            printf("\t------------------PASSAGEM %d------------------\n", id_passagem);
            printf("\t\t   ID DO PASSAGEIRO: %d\n", consulta->id_DoPassageiro);
            printf("\t\t   ID DO VOO: %d\n", consulta->id_DoVoo);
            printf("\t\t   DATA DA VENDA DA PASSAGEM: %d/%d/%d\n", consulta->dataVenda.dia, consulta->dataVenda.mes, consulta->dataVenda.ano);
            printf("\t\t   VALOR DA PASSAGEM: R$%.2lf\n", consulta->valor);
        } else{
            consulta = ***lista;
            while(consulta->proxima_passagem && consulta->proxima_passagem->id_passagem != id_passagem){
                consulta = consulta->proxima_passagem;
            }
            if(consulta->proxima_passagem){
                printf("\t------------------PASSAGEM %d------------------\n", id_passagem);
                printf("\t\t   ID DO PASSAGEIRO: %d\n", consulta->id_DoPassageiro);
                printf("\t\t   ID DO VOO: %d\n", consulta->id_DoVoo);
                printf("\t\t   DATA DA VENDA DA PASSAGEM: %d/%d/%d\n", consulta->dataVenda.dia, consulta->dataVenda.mes, consulta->dataVenda.ano);
                printf("\t\t   VALOR DA PASSAGEM: R$%.2lf\n", consulta->valor);
            }else{
                printf("\t--------------PASSAGEM %d NAO ENCONTRADA--------------\n", id_passagem);
            }
        }
    } else{
        printf("\t--------------PASSAGEM %d NAO ENCONTRADA--------------\n", id_passagem);
    }
}

PASSAGEM *excluirPASSAGEM(PASSAGEM ****lista){
    PASSAGEM *remover = NULL;
    PASSAGEM *aux;
    int id_passagem;
    printf("INSIRA ID DA PASSAGEM A SER DELETADA:\n");
    scanf("%d", &id_passagem);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_passagem == id_passagem){
            remover = ***lista;
            ***lista = remover->proxima_passagem;
        }else{
            aux = ***lista;
            while(aux->proxima_passagem && aux->proxima_passagem->id_passagem != id_passagem){
                aux = aux->proxima_passagem;
            }
            if(aux->proxima_passagem){
                remover = aux->proxima_passagem;
                aux->proxima_passagem = remover->proxima_passagem;
            }
        }
    }else{
        printf("\t\tERRO --> A LISTA ESTA VAZIA!\n\n\n");
    }
    return remover;
}

void alterarPASSAGEM(PASSAGEM ****lista, VOO ****lista_voo){
    PASSAGEM *alterar = NULL, *listaT;
    listaT = ***lista;
    int id_passagem, id_passageiro, id_voo;
    double valor;
    DATA dataVenda;
    printf("INSIRA ID/NUMERO DA PASSAGEM A SER MODIFICADA:\n");
    scanf("%d", &id_passagem);
    fflush(stdin);
    if(***lista){
        if(listaT->id_passagem == id_passagem){
            printf("\t----------------ALTERANDO PASSAGEM %d----------------\n", id_passagem);
            printf("\t\t   ID DO PASSAGEIRO: %d\n", listaT->id_DoPassageiro);
            printf("\t\t   ID DO VOO: %d\n", listaT->id_DoVoo);
            printf("\t\t   DATA DA VENDA DA PASSAGEM: %d/%d/%d\n", listaT->dataVenda.dia, listaT->dataVenda.mes, listaT->dataVenda.ano);
            printf("\t\t   VALOR DA PASSAGEM: R$%.2lf\n", listaT->valor);
            printf("\n");
            printf("INSIRA O NOVO ID DO PASSAGEIRO:\n");
            scanf("%d", &id_passageiro);
            fflush(stdin);
            printf("INSIRA O NOVO ID DO VOO DA PASSAGEM:\n");
            scanf("%d", &id_voo);
            fflush(stdin);
            VOO *vooP = NULL, *lista_voo_local = ***lista_voo;
            if(listaT->id_DoVoo == id_voo){
                
            }else{
                if(lista_voo_local->id_voo == listaT->id_DoVoo){
                vooP = lista_voo_local;
                vooP->qtdPassageiros--;
                } else{
                    vooP = lista_voo_local;
                    while(vooP->proximo_voo && vooP->proximo_voo->id_voo != listaT->id_DoVoo){
                        vooP = vooP->proximo_voo;
                    }
                    if(vooP->proximo_voo){
                        vooP->qtdPassageiros++;
                    }else{
                        printf("\t\n\tERRO --> O VOO '%d' AINDA NAO EXISTE, INCLUA-O ANTES DE REMOVER PASSAGENS DELE!\n\n\n", listaT->id_DoVoo);
                        return;
                    }
                }
                if(lista_voo_local->id_voo == id_voo){
                vooP = lista_voo_local;
                vooP->qtdPassageiros++;
                } else{
                    vooP = lista_voo_local;
                    while(vooP->proximo_voo && vooP->proximo_voo->id_voo != id_voo){
                        vooP = vooP->proximo_voo;
                    }
                    if(vooP->proximo_voo){
                        vooP->qtdPassageiros++;
                    }else{
                        printf("\t\n\tERRO --> O VOO '%d' AINDA NAO EXISTE, INCLUA-O ANTES DE ADICIONAR PASSAGENS A ELE!\n\n\n", id_voo);
                        return;
                    }
                }
            }
            printf("INSIRA A NOVA DATA DA VENDA DA PASSAGEM(DD MM AAAA):\n");
            scanf("%d %d %d", &dataVenda.dia, &dataVenda.mes, &dataVenda.ano);
            fflush(stdin);
            printf("INSIRA O NOVO VALOR DA PASSAGEM(R$):\n");
            scanf("%lf", &valor);
            fflush(stdin);
            listaT->id_DoPassageiro = id_passageiro;
            listaT->id_DoVoo = id_voo;
            listaT->dataVenda.dia = dataVenda.dia;
            listaT->dataVenda.mes = dataVenda.mes;
            listaT->dataVenda.ano = dataVenda.ano;
            listaT->valor = valor;
        }else{
            while(listaT->id_passagem != id_passagem && listaT){
                listaT = listaT->proxima_passagem;
            }
            if(listaT){
                if(listaT->id_passagem == id_passagem){
                    printf("\t----------------ALTERANDO PASSAGEM %d----------------\n", id_passagem);
                    printf("\t\t   ID DO PASSAGEIRO: %d\n", listaT->id_DoPassageiro);
                    printf("\t\t   ID DO VOO: %d\n", listaT->id_DoVoo);
                    printf("\t\t   DATA DA VENDA DA PASSAGEM: %d/%d/%d\n", listaT->dataVenda.dia, listaT->dataVenda.mes, listaT->dataVenda.ano);
                    printf("\t\t   VALOR DA PASSAGEM: R$%.2lf\n", listaT->valor);
                    printf("\n");
                    printf("INSIRA O NOVO ID DO PASSAGEIRO:\n");
                    scanf("%d", &id_passageiro);
                    fflush(stdin);
                    printf("INSIRA O NOVO ID DO VOO DA PASSAGEM:\n");
                    scanf("%d", &id_voo);
                    fflush(stdin);
                    VOO *vooP = NULL, *lista_voo_local = ***lista_voo;
                    if(listaT->id_DoVoo == id_voo){
                        
                    }else{
                        if(lista_voo_local->id_voo == listaT->id_DoVoo){
                        vooP = lista_voo_local;
                        vooP->qtdPassageiros--;
                        } else{
                            vooP = lista_voo_local;
                            while(vooP->proximo_voo && vooP->proximo_voo->id_voo != listaT->id_DoVoo){
                                vooP = vooP->proximo_voo;
                            }
                            if(vooP->proximo_voo){
                                vooP->qtdPassageiros++;
                            }else{
                                printf("\t\n\tERRO --> O VOO '%d' AINDA NAO EXISTE, INCLUA-O ANTES DE REMOVER PASSAGENS DELE!\n\n\n", listaT->id_DoVoo);
                                return;
                            }
                        }
                        if(lista_voo_local->id_voo == id_voo){
                        vooP = lista_voo_local;
                        vooP->qtdPassageiros++;
                        } else{
                            vooP = lista_voo_local;
                            while(vooP->proximo_voo && vooP->proximo_voo->id_voo != id_voo){
                                vooP = vooP->proximo_voo;
                            }
                            if(vooP->proximo_voo){
                                vooP->qtdPassageiros++;
                            }else{
                                printf("\t\n\tERRO --> O VOO '%d' AINDA NAO EXISTE, INCLUA-O ANTES DE ADICIONAR PASSAGENS A ELE!\n\n\n", id_voo);
                                return;
                            }
                        }
                    }
                    printf("INSIRA A NOVA DATA DA VENDA DA PASSAGEM(DD MM AAAA):\n");
                    scanf("%d %d %d", &dataVenda.dia, &dataVenda.mes, &dataVenda.ano);
                    fflush(stdin);
                    printf("INSIRA O NOVO VALOR DA PASSAGEM(R$):\n");
                    scanf("%lf", &valor);
                    fflush(stdin);
                    listaT->id_DoPassageiro = id_passageiro;
                    listaT->id_DoVoo = id_voo;
                    listaT->dataVenda.dia = dataVenda.dia;
                    listaT->dataVenda.mes = dataVenda.mes;
                    listaT->dataVenda.ano = dataVenda.ano;
                    listaT->valor = valor;
                }
            }
        }
    }else{
        printf("\t--------------PASSAGEM %d NAO ENCONTRADA--------------\n", id_passagem);
    }
}

void incluirPASSAGEIRO(PASSAGEIRO ****lista){
    PASSAGEIRO *novo = malloc(sizeof(PASSAGEIRO));
    if(novo){
        printf("INSIRA O ID DO PASSAGEIRO:\n");
        scanf("%d", &novo->id_passageiro);
        fflush(stdin);
        printf("INSIRA O NOME DO PASSAGEIRO:\n");
        fgets(novo->nome, 38, stdin);
        fflush(stdin);
        printf("INSIRA O DOCUMENTO (IDENTIDADE) DO PASSAGEIRO:\n");
        fgets(novo->identidade, 12, stdin);
        fflush(stdin);
        printf("INSIRA O ENDERECO DO PASSAGEIRO:\n");
        fgets(novo->endereco, 70, stdin);
        fflush(stdin);
        printf("INSIRA O TELEFONE DO PASSAGEIRO:\n");
        fgets(novo->telefone, 12, stdin);
        fflush(stdin);
        printf("INSIRA O SEXO DO PASSAGEIRO:\n");
        fgets(novo->sexo, 30, stdin);
        fflush(stdin);
        novo->proximo_passageiro = ***lista;
        ***lista = novo;
    }else{
        printf("\t\tERRO --> NAO FOI POSSIVEL ALOCAR MEMORIA!\n\n\n");
    }
}

void consultarPASSAGEIRO(PASSAGEIRO ****lista){
    PASSAGEIRO *consulta = NULL;
    int id_passageiro;
    printf("INSIRA ID DO PASSAGEIRO PARA EFETUAR A BUSCA:\n");
    scanf("%d", &id_passageiro);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_passageiro == id_passageiro){
            consulta = ***lista;
            printf("\t------------------PASSAGEIRO %d------------------\n", id_passageiro);
            printf("\t\t  NOME DO PASSAGEIRO: %s", consulta->nome);
            printf("\t\t  DOCUMENTO DO PASSAGEIRO: %s", consulta->identidade);
            printf("\t\t  ENDERECO DO PASSAGEIRO: %s", consulta->endereco);
            printf("\t\t  TELEFONE DO PASSAGEIRO: %s\n", consulta->telefone);
            printf("\t\t  SEXO DO PASSAGEIRO: %s\n", consulta->sexo);
        } else{
            consulta = ***lista;
            while(consulta->proximo_passageiro && consulta->proximo_passageiro->id_passageiro != id_passageiro){
                consulta = consulta->proximo_passageiro;
            }
            if(consulta->proximo_passageiro){
                printf("\t------------------PASSAGEIRO %d------------------\n", id_passageiro);
                printf("\t\t  NOME DO PASSAGEIRO: %s", consulta->nome);
                printf("\t\t  DOCUMENTO DO PASSAGEIRO: %s", consulta->identidade);
                printf("\t\t  ENDERECO DO PASSAGEIRO: %s", consulta->endereco);
                printf("\t\t  TELEFONE DO PASSAGEIRO: %s\n", consulta->telefone);
                printf("\t\t  SEXO DO PASSAGEIRO: %s\n", consulta->sexo);
            }else{
                printf("\t--------------PASSAGEIRO %d NAO ENCONTRADO--------------\n", id_passageiro);
            }
        }
    } else{
        printf("\t--------------PASSAGEIRO %d NAO ENCONTRADO--------------\n", id_passageiro);
    }
}

PASSAGEIRO *excluirPASSAGEIRO(PASSAGEIRO ****lista){
    PASSAGEIRO *remover = NULL;
    PASSAGEIRO *aux;
    int id_passageiro;
    printf("INSIRA ID DO PASSAGEIRO A SER DELETADO:\n");
    scanf("%d", &id_passageiro);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_passageiro == id_passageiro){
            remover = ***lista;
            ***lista = remover->proximo_passageiro;
        }else{
            aux = ***lista;
            while(aux->proximo_passageiro && aux->proximo_passageiro->id_passageiro != id_passageiro){
                aux = aux->proximo_passageiro;
            }
            if(aux->proximo_passageiro){
                remover = aux->proximo_passageiro;
                aux->proximo_passageiro = remover->proximo_passageiro;
            }
        }
    }else{
        printf("\t\tERRO --> A LISTA ESTA VAZIA!\n\n\n");
    }
    return remover;
}

void alterarPASSAGEIRO(PASSAGEIRO ****lista){
    PASSAGEIRO *alterar = NULL, *listaT;
    listaT = ***lista;
    int id_passageiro;
    printf("INSIRA ID DO PASSAGEIRO A SER MODIFICADO:\n");
    scanf("%d", &id_passageiro);
    fflush(stdin);
    if(***lista){
        if(listaT->id_passageiro == id_passageiro){
            printf("\t----------------ALTERANDO PASSAGEIRO %d----------------\n", id_passageiro);
            printf("\t\t  NOME DO PASSAGEIRO: %s", listaT->nome);
            printf("\t\t  DOCUMENTO DO PASSAGEIRO: %s", listaT->identidade);
            printf("\t\t  ENDERECO DO PASSAGEIRO: %s", listaT->endereco);
            printf("\t\t  TELEFONE DO PASSAGEIRO: %s\n", listaT->telefone);
            printf("\t\t  SEXO DO PASSAGEIRO: %s\n", listaT->sexo);
            printf("\n");
            printf("INSIRA O NOVO NOME DO PASSAGEIRO:\n");
            fgets(listaT->nome, 38, stdin);
            fflush(stdin);
            printf("INSIRA O NOVO DOCUMENTO (IDENTIDADE) DO PASSAGEIRO:\n");
            fgets(listaT->identidade, 12, stdin);
            fflush(stdin);
            printf("INSIRA O NOVO ENDERECO DO PASSAGEIRO:\n");
            fgets(listaT->endereco, 70, stdin);
            fflush(stdin);
            printf("INSIRA O NOVO TELEFONE DO PASSAGEIRO:\n");
            fgets(listaT->telefone, 12, stdin);
            fflush(stdin);
            printf("INSIRA O NOVO SEXO DO PASSAGEIRO:\n");
            fgets(listaT->sexo, 30, stdin);
            fflush(stdin);
        }else{
            while(listaT->id_passageiro != id_passageiro && listaT){
                listaT = listaT->proximo_passageiro;
            }
            if(listaT){
                if(listaT->id_passageiro == id_passageiro){
                    printf("\t----------------ALTERANDO PASSAGEIRO %d----------------\n", id_passageiro);
                    printf("\t\t  NOME DO PASSAGEIRO: %s", listaT->nome);
                    printf("\t\t  DOCUMENTO DO PASSAGEIRO: %s", listaT->identidade);
                    printf("\t\t  ENDERECO DO PASSAGEIRO: %s", listaT->endereco);
                    printf("\t\t  TELEFONE DO PASSAGEIRO: %s\n", listaT->telefone);
                    printf("\t\t  SEXO DO PASSAGEIRO: %s\n", listaT->sexo);
                    printf("\n");
                    printf("INSIRA O NOVO NOME DO PASSAGEIRO:\n");
                    fgets(listaT->nome, 38, stdin);
                    fflush(stdin);
                    printf("INSIRA O NOVO DOCUMENTO (IDENTIDADE) DO PASSAGEIRO:\n");
                    fgets(listaT->identidade, 12, stdin);
                    fflush(stdin);
                    printf("INSIRA O NOVO ENDERECO DO PASSAGEIRO:\n");
                    fgets(listaT->endereco, 70, stdin);
                    fflush(stdin);
                    printf("INSIRA O NOVO TELEFONE DO PASSAGEIRO:\n");
                    fgets(listaT->telefone, 12, stdin);
                    fflush(stdin);
                    printf("INSIRA O NOVO SEXO DO PASSAGEIRO:\n");
                    fgets(listaT->sexo, 30, stdin);
                    fflush(stdin);
                }
            }
        }
    }else{
        printf("\t--------------PASSAGEIRO %d NAO ENCONTRADO--------------\n", id_passageiro);
    }
}

void passagemPorVoo(VOO ****lista){
    VOO *consulta = NULL;
    int id_voo;
    printf("INSIRA ID DO VOO PARA GERAR O RELATORIO:\n");
    scanf("%d", &id_voo);
    fflush(stdin);
    if(***lista){
        if((***lista)->id_voo == id_voo){
            consulta = ***lista;
            printf("\t------------------VOO %d------------------\n", id_voo);
            printf("\t\t QTD. PASSAGENS VENDIDAS: %d\n", consulta->qtdPassageiros);
        }else{
            consulta = ***lista;
            while(consulta->proximo_voo && consulta->proximo_voo->id_voo != id_voo){
                consulta = consulta->proximo_voo;
            }
            if(consulta->proximo_voo){
                printf("\t------------------VOO %d----------------------\n", id_voo);
                printf("\t\t QTD. PASSAGENS VENDIDAS: %d\n", consulta->qtdPassageiros);
            }else{
                printf("\t--------------VOO %d NAO ENCONTRADO--------------\n", id_voo);
            }
        }
    }else{
        printf("\t--------------VOO %d NAO ENCONTRADO--------------\n", id_voo);
    }
}

void vooPorEmpresa(VOO ****lista) {
    VOO *consulta = NULL;
    int cont = 0;
    char empresa[30];
    printf("INSIRA A EMPRESA A SER PESQUISADA:\n");
    fgets(empresa, 30, stdin);
    fflush(stdin);
    if(***lista){
        consulta = ***lista;
        if(strcmp(consulta->empresa, empresa) == 0){
            cont++;
        }
        while(consulta->proximo_voo){
            consulta = consulta->proximo_voo;
            if(strcmp(consulta->empresa, empresa) == 0){
                cont++;
            }
        }
        if(cont == 0){
            printf("\t------------------------------------------\n");
            printf("\t\tNAO CONSTA VOOs NESSA EMPRESA\n");
        }else{
            char empresa1[30];
            strcpy(empresa1, empresa);
            char *strptr = empresa1;
            while(*strptr != '\n'){
                strptr++;
            }
            *strptr = '\0';
            printf("\t------------------------------------------\n");
            printf("\t   QTD. VOOs NA '%s': %d\n", empresa1, cont);
        }
    }
}

void listaPassageirosPorVoo(PASSAGEM ****lista_passagem, PASSAGEIRO ****lista_passageiro) {
    int id_voo;
    printf("INSIRA ID DO VOO PARA LISTAR OS PASSAGEIROS:\n");
    scanf("%d", &id_voo);
    for (PASSAGEM *p = ***lista_passagem; p != NULL; p = p->proxima_passagem) {
        PASSAGEM *passagem = p;
        if (passagem->id_DoVoo == id_voo) {
            PASSAGEIRO *passageiro = NULL;
            for (PASSAGEIRO *q = ***lista_passageiro; q != NULL; q = q->proximo_passageiro) {
                passageiro = q;
                if (passageiro->id_passageiro == passagem->id_DoPassageiro) {
                    printf("\t------------------PASSAGEIRO %d------------------\n", passageiro->id_passageiro);
                    printf("\t\t NOME DO PASSAGEIRO: %s", passageiro->nome);
                    printf("\t\t DOCUMENTO DO PASSAGEIRO: %s", passageiro->identidade);
                    printf("\t\t ENDERECO DO PASSAGEIRO: %s", passageiro->endereco);
                    printf("\t\t TELEFONE DO PASSAGEIRO: %s", passageiro->telefone);
                    printf("\t\t SEXO DO PASSAGEIRO: %s\n", passageiro->sexo);
                    break;
                }
            }
            if (passageiro == NULL || passageiro->id_passageiro != passagem->id_DoPassageiro) {
                printf("\t--------------PASSAGEIRO %d NAO ENCONTRADO--------------\n", passagem->id_DoPassageiro);
            }
        }
    }
}

////////////////////FUNCOES E PROCEDIMENTOS/////////////////////
////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////
///////////////////////////MENUS////////////////////////////////

void menuVOO(VOO ***lista_voo){
    int opcao;
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tVOOs\n\n");
        printf("\t\t     0 -> Voltar\n");
        printf("\t\t     1 -> Incluir\n");
        printf("\t\t     2 -> Alterar\n");
        printf("\t\t     3 -> Excluir\n");
        printf("\t\t     4 -> Consultar\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao)
        {
        case 1:
            incluirVOO(&lista_voo);
            break;
        case 2:
            alterarVOO(&lista_voo);
            break;
        case 3:
            VOO *remover;
            remover = excluirVOO(&lista_voo);
            if(remover){
                printf("\t------------------VOO %d DELETADO------------------\n", remover->id_voo);
                printf("\t\t   ID DA AERONAVE: %d\n", remover->id_aeronave);
                printf("\t\t   EMPRESA: %s", remover->empresa);
                printf("\t\t   ORIGEM: %s", remover->origem);
                printf("\t\t   DESTINO: %s", remover->destino);
                printf("\t\t   DATA DE PARTIDA: %d/%d/%d\n", remover->dataPartida.dia, remover->dataPartida.mes, remover->dataPartida.ano);
                printf("\t\t   HORARIO DE PARTIDA: %d:%d\n", remover->horarioPartida.hora, remover->horarioPartida.min);
                printf("\t\t   QTD. PASSAGEIROS: %d\n", remover->qtdPassageiros);
                free(remover);
            } else{
                printf("\t\tERRO --> NAO FOI POSSIVEL DELETAR O VOO '%d'\n\n\n", remover->id_voo);
            }
            break;
        case 4:
            consultarVOO(&lista_voo);
            break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }

    }while(opcao != 0);
}

void menuPASSAGENS(PASSAGEM ***lista_passagem, VOO ***lista_voo){
    int opcao;
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tPASSAGENS\n\n");
        printf("\t\t     0 -> Voltar\n");
        printf("\t\t     1 -> Incluir\n");
        printf("\t\t     2 -> Alterar\n");
        printf("\t\t     3 -> Excluir\n");
        printf("\t\t     4 -> Consultar\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao)
        {
        case 1:
            incluirPASSAGEM(&lista_passagem, &lista_voo);
            break;
        case 2:
            alterarPASSAGEM(&lista_passagem, &lista_voo);
            break;
        case 3:
            PASSAGEM *remover;
            remover = excluirPASSAGEM(&lista_passagem);
            if(remover){
                printf("\t------------------PASSAGEM %d DELETADA------------------\n", remover->id_passagem);
                printf("\t\t   ID DO PASSAGEIRO: %d\n", remover->id_DoPassageiro);
                printf("\t\t   ID DO VOO: %d\n", remover->id_DoVoo);
                printf("\t\t   DATA DA VENDA DA PASSAGEM: %d/%d/%d\n", remover->dataVenda.dia, remover->dataVenda.mes, remover->dataVenda.ano);
                printf("\t\t   VALOR DA PASSAGEM: R$%.2lf\n", remover->valor);
                VOO *vooRemoverP = NULL, *lista_voo_local = **lista_voo;
                if(lista_voo_local->id_voo == remover->id_DoVoo){
                    vooRemoverP = lista_voo_local;
                    vooRemoverP->qtdPassageiros--;
                } else{
                    vooRemoverP = lista_voo_local;
                    while(vooRemoverP->proximo_voo && vooRemoverP->proximo_voo->id_voo != remover->id_DoVoo){
                        vooRemoverP = vooRemoverP->proximo_voo;
                    }
                    if(vooRemoverP->proximo_voo){
                        vooRemoverP->qtdPassageiros--;
                    }
                }
                free(remover);
            } else{
                printf("\t\tERRO --> NAO FOI POSSIVEL DELETAR A PASSAGEM '%d'\n\n\n", remover->id_passagem);
            }
            break;
        case 4:
            consultarPASSAGEM(&lista_passagem);
            break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }

    }while(opcao != 0);
}

void menuPASSAGEIROS(PASSAGEIRO ***lista_passageiro){
    int opcao;
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tPASSAGEIROs\n\n");
        printf("\t\t     0 -> Voltar\n");
        printf("\t\t     1 -> Incluir\n");
        printf("\t\t     2 -> Alterar\n");
        printf("\t\t     3 -> Excluir\n");
        printf("\t\t     4 -> Consultar\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao)
        {
        case 1:
            incluirPASSAGEIRO(&lista_passageiro);
            break;
        case 2:
            alterarPASSAGEIRO(&lista_passageiro);
            break;
        case 3:
            PASSAGEIRO *remover;
            remover = excluirPASSAGEIRO(&lista_passageiro);
            if(remover){
                printf("\t------------------PASSAGEIRO %d DELETADO------------------\n", remover->id_passageiro);
                printf("\t\t  NOME DO PASSAGEIRO: %s", remover->nome);
                printf("\t\t  DOCUMENTO DO PASSAGEIRO: %s", remover->identidade);
                printf("\t\t  ENDERECO DO PASSAGEIRO: %s", remover->endereco);
                printf("\t\t  TELEFONE DO PASSAGEIRO: %s\n", remover->telefone);
                printf("\t\t  SEXO DO PASSAGEIRO: %s\n", remover->sexo);
                free(remover);
            } else{
                printf("\t\tERRO --> NAO FOI POSSIVEL DELETAR O PASSAGEIRO '%d'\n\n\n", remover->id_passageiro);
            }
            break;
        case 4:
            consultarPASSAGEIRO(&lista_passageiro);
            break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }

    }while(opcao != 0);
}

void relatorios(VOO ***lista_voo, PASSAGEIRO ***lista_passageiro, PASSAGEM ***lista_passagem){
    int opcao;
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tRELATORIOs\n\n");
        printf("\t0 -> Voltar\n");
        printf("\t1 -> Quantidade de PASSAGENS vendidas por VOO\n");
        printf("\t2 -> Quantidade de VOOs por EMPRESA\n");
        printf("\t3 -> Lista de PASSAGEIROS por VOO\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao){
        case 1:
            passagemPorVoo(&lista_voo);
            break;
        case 2:
            vooPorEmpresa(&lista_voo);
            break;
        case 3:
            listaPassageirosPorVoo(&lista_passagem, &lista_passageiro);
            break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }
    }while(opcao != 0);
}

void menu(VOO **lista_voo, PASSAGEIRO **lista_passageiro, PASSAGEM **lista_passagem){
    int opcao;
    do{
        printf("\t------------------------------------------\n");
        printf("\t\t\tMenu\n\n");
        printf("\t\t     0 -> Sair\n");
        printf("\t\t     1 -> Voos\n");
        printf("\t\t     2 -> Passagens\n");
        printf("\t\t     3 -> Passageiros\n");
        printf("\t\t     4 -> Relatorios\n");
        printf("\t------------------------------------------\n");
        printf("\t\t\n");
        fflush(stdin);
        scanf("%d", &opcao);
        fflush(stdin);

        ///OPCOES
        switch (opcao)
        {
        case 1:
            menuVOO(&lista_voo);
            break;
        case 2:
            menuPASSAGENS(&lista_passagem, &lista_voo);
            break;
        case 3:
            menuPASSAGEIROS(&lista_passageiro);
            break;
        case 4:
            relatorios(&lista_voo, &lista_passageiro, &lista_passagem);
            break;
        default:
            if(opcao != 0) printf("\t\tERRO --> Opcao Invalida!\n\n\n");
        }
        ///OPCOES

    }while(opcao != 0);

    printf("\t<3 Obrigado por usar o sistema Aeroporto! <3\n\t    Desenvolvido por: Frederico Zolio e Gustavo Alcantara\n\n");
}

///////////////////////////MENUS////////////////////////////////
////////////////////////////////////////////////////////////////


int main(){

    VOO *lista_voos = malloc(50 * sizeof(VOO));
    PASSAGEIRO *lista_passageiros = malloc(100 * sizeof(PASSAGEIRO));
    PASSAGEM *lista_passagens = malloc(100 * sizeof(PASSAGEM));

    menu(&lista_voos, &lista_passageiros, &lista_passagens);

    return EXIT_SUCCESS;
}