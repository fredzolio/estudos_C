#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

typedef struct Produto
{
    char nome[30];
    int codigo;
    float preco;

} PRODUTO;
 

int main () {

    // A)
    PRODUTO mat[10];
    strcpy(mat[0].nome, "Pe de Moleque");
    mat[0].codigo = 13205;
    mat[0].preco = 0.20;
    strcpy(mat[1].nome, "Cocada Baiana");
    mat[1].codigo = 15202;
    mat[1].preco = 0.50;

    // B)
    PRODUTO *m;
    m = (PRODUTO *) malloc (10 * sizeof(PRODUTO));
    fflush(stdin); //limpa buffer do teclado;
    for (int i = 0; i < 10; i++){
        m[i] = mat[i];
    }

    // C)
    for (int i = 0; i < 2; i++){
        printf("Nome: ");
        puts(m[i].nome);
        printf("Codigo: %d\n", m[i].codigo);
        printf("Preco: %.2f\n", m[i].preco);
        printf("\n");
    }
    
    return 0;
}