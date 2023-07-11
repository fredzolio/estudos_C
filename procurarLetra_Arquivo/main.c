#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*void maisFrequente(){
    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    rewind(arquivo);
    int maior;
    char letra;

    printf("\nO caracter '%c' eh o que mais aparece, sendo %d vezes.\n", letra, maior);
    fclose(arquivo);
}*/

int main(){
    int i, cont = 0;
    char ch, letra;
    printf("Insira a letra que voce quer procurar:\n");
    scanf("%c", &ch);
    fflush(stdin);
    FILE *arquivo;
    arquivo = fopen("teste.txt", "r");
    while(!feof(arquivo)){
        letra = fgetc(arquivo);
        if (letra == ch){
            cont++;
        }
    }
    fclose(arquivo);
    printf("A letra [%c] foi vista %d vezes.\n", ch, cont);
    //maisFrequente();
    return 0;
}