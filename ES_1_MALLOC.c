/*
author:Andrea Sciolla
date: 23/10/2023
es:1 con funzione malloc
testo:
Scrivi un programma in linguaggio C che consenta all'utente di creare un array dinamico
di interi. Il programma dove avere una dimensione array specificata, usando la
funzione malloc per allocare in modo dinamico gli interi.
L’utente deve poter inserire valori interi, che verranno stampati. Assicurarsi di liberare la
memoria allocata dinamicamente utilizzando la funzione free alla fine del
programma per evitare perdite di memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30 //numero di film presenti nella lista

int leggiInteri(int* v, int dim) {
    int num = 0;
    int k = 0;
        printf("inserisci i numeri: (-1 per interrompere)\n");
        scanf("%d", &num);
        while(num != -1) {
            *v = num;
            v++;
            k++;
            scanf("%d", &num);
        }
        return k;
    }
void stampaVett(int* v, int dim) {
    int* v1 = v;
    for(v; v < v1 + dim; v++) {
        printf("%d", *v);
    }
}

int main(){
    int* vett;
    vett = (int*) malloc(DIM*sizeof(int));
    int dim = leggiInteri(vett, DIM);
    stampaVett(vett, dim);
    free(vett);
    return 0;
}