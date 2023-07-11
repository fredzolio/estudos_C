#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*
Duração em minutos dado entrada de inicio e termino
*/

typedef struct horas{
    int hora;
    int min;
}HORAS;


int main(){

    HORAS inicio, final;
    int minTOTAL = 0;
    printf("INICIO: \n");
    scanf("%d:%d", &inicio.hora, &inicio.min);
    getchar();
    printf("FIM: \n");
    scanf("%d:%d", &final.hora, &final.min);

    int inicioMIN = (inicio.hora * 60) + inicio.min;
    int finalMIN = (final.hora * 60) + final.min;

    for(int i = inicioMIN; i != finalMIN; i++){
        minTOTAL++;
        if(i == 1440){
            i = 0;
        }
    }
    printf("DURACAO (MIN): %dmins\n", minTOTAL);

    return EXIT_SUCCESS;
}