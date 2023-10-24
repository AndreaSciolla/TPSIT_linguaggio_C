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
        for (int* p = vett; p < vett+n; p++) {
            if (*p > *(p+1)) { //bisogna mettere gli * altrimenti confronta gli indirizzi
                scambio(p, p+1);
                sca = p - vett;
            }
        }
        sup = sca;
    }
}


void selectionSort1(int v[],int n) {
    /*Si cerca il minimo ad ogni ciclo e si fa al massimo un solo scambio a ciclo.
    Quando sistemo il penultimo elemento automaticamente è sistemato l’ultimo*/
    int k,kmin,j;
    for(k = 0; k < n-1; k++) {
        kmin = k;
        for(j = k+1; j < n; j++) {
            if(v[kmin] > v[j]) // confronti
                kmin = j;

        }
        if(kmin != k)
            scambio(&v[k], &v[kmin]); //scambi
    }
    return;
}

void selectionSort(int v[], int n) {
    /*Si cerca il minimo ad ogni ciclo e si fa al massimo un solo scambio a ciclo.
    Quando sistemo il penultimo elemento automaticamente è sistemato l’ultimo*/
    int* k, *kmin, *j;
    for(k = v; k < v+n-1; k++) {
        kmin = k;
        for(j = k+1; j < v+n; j++) {
            if(*kmin > *j) // confronti
                kmin = j;

        }
        if(kmin != k)
            scambio(k, kmin); //scambi
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
    selectionSort(vett, DIM);
    stampaVett(vett, DIM);
    return 0;
}