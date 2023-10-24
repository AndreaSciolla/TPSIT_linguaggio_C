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

void scambio(int *x, int *y){
    int a; 
    a = *x;
    *x = *y;
    *y = a;
}

void bubbleSort3(int vett[], int n) {
    int k,sup,sca;
    sup = n-1 ;
    while ( sup>0 ) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (*(vett + k) > *(vett + k + 1)) {
                scambio(&*(vett + k), &*(vett + k + 1));
                sca = k ;
            }
        }
        sup = sca;
    }
}

void stampaVett(int vett[], int n){
    printf("il vettore ordinato e':");
    for(int k = 0; k < n; k++){
        printf("\t%d", *(vett + k));
    }
}

int main(){
    int vett[DIM]={2, 7, 8, 3, 5, 1, 6, 7, 2, 9};
    bubbleSort3(vett, DIM);
    stampaVett(vett, DIM);
    return 0;
}