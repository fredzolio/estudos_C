#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
NO PDF LISTA 2 - Parte de vetores;
*/

int pares(int v[15]){
    int pares = 0;
    for(int i = 0; i < 15; i++){
        if(v[i] % 2 == 0){
            pares++;
        }
    }
    return pares;
}

int somaImpares(int v[15]){
    int soma = 0;
    for(int i = 0; i < 15; i++){
        if(v[i] % 2 != 0){
            soma += v[i];
        }
    }
    return soma;
}

int maiorQueAMedia(int v[15]){
    int media = 0, aux = 0;
    for(int i = 0; i < 15; i++){
        media += v[i];
    }
    media /= 2;
    for(int i = 0; i < 15; i++){
        if(v[i] > media){
            aux++;
        }
    }
    return aux;
}

int maior(int v[15]){
    int maior = v[0];
    for(int i = 0; i < 15; i++){
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

void ordenaCres(int v[15]){
    for(int i = 0; i < 15; i++){
        for(int j = i; j < 15; j++){
            if(v[j] < v[i]){
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    printf("VETOR EM ORDEM CRESCENTE: ");
    for(int i = 0; i < 15; i++){
        if(i == 14)
            printf("%d\n", v[i]);
        else
            printf("%d, ", v[i]);
    }
}

void terceiro_maior(int v[]){
    int maior = v[0];
    for(int i = 0; i < 15; i++){
        if(v[i] > maior)
            maior = v[i];
    }
    int maior2 = v[0];
    for(int i = 0; i < 15; i++){
        if(v[i] > maior2)
            if(v[i] == maior){
                continue;
            }else{
                maior2 = v[i];
            }
    }
    int maior3 = v[0];
    for(int i = 0; i < 15; i++){
        if(v[i] > maior3)
            if(v[i] == maior2 || v[i] == maior){
                continue;
            }else{
                maior3 = v[i];
            }
    }

    printf("TERCEIRO MAIOR: %d\n", maior3);
}

void removeIguais(int v[]){
    for(int i = 0; i < 15; i++){
        for(int j = i + 1; j < 15; j++){
            if(v[i] == v[j]){
                v[j] = rand() % 100;
            }
        }
    }
    printf("IGUAIS REMOVIDOS: ");
    for(int i = 0; i < 15; i++){
        if(i == 14)
            printf("%d\n", v[i]);
        else
            printf("%d, ", v[i]);
    }
}

int maiorEntreN(int v[15]){
    int maior = v[0];
    printf("ESCOLHA ATE ONDE QUE PROCURAR O MAIOR:\n");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if(v[i] > maior)
            maior = v[i];
    }
    return maior;
}

int main(){
    //////////////////////////
    srand(time(NULL));
    int vetor[15];
    for(int i = 0; i < 15; i++){
        vetor[i] = rand() % 100;
    }
    for(int i = 0; i < 15; i++){
        if(i == 14)
            printf("%d\n", vetor[i]);
        else
            printf("%d, ", vetor[i]);
    }
    //////////////////////////

    printf("QTDE. PARES: %d\n", pares(vetor));
    printf("SOMA IMPARES: %d\n", somaImpares(vetor));
    printf("QTDE DE VALORES MAIORES QUE A MEDIA: %d\n", maiorQueAMedia(vetor));
    printf("MAIOR VALOR: %d\n", maior(vetor));
    ordenaCres(vetor);
    terceiro_maior(vetor);
    removeIguais(vetor);
    printf("MAIOR VALOR ENTRE X ELEMENTOS: %d\n", maiorEntreN(vetor));
    
    

    return EXIT_SUCCESS;
}