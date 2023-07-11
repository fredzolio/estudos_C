#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

/*
Faça um programa para calcular o número de vértices de um cubo com 6 faces e 12 arestas. A
relação entre vértices, arestas e faces de um objeto geométrico é dada por:
vértices + faces = arestas + 2.
*/

int calcCubeVertices(int faces, int arestas){
    return (arestas - faces + 2);
}

int main(){

    printf("%d", calcCubeVertices(6, 12));

    return EXIT_SUCCESS;
}