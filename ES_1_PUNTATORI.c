/*
author:Andrea Sciolla
date:02/10/2023
es:es 1 sui puntatori
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIM 10

int calcolaSomma(int dim, int vett[]){
    int somma = 0;
    for(int k = 0; k < dim; k++){
        somma += *(vett + k);
    }
    return (somma);
}

int main(){
    int vett[DIM]={2, 7, 8, 3, 5, 1, 6, 7, 2, 9};
    int somma;
    somma = calcolaSomma(DIM, vett);
    printf("la somma del vettore e': %d", somma);
    return 0;
}