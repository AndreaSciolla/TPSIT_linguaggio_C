/*
author:Andrea Sciolla
date:
es:VERSIONE SPIEGATA DAL PROF ES 1
testo:in questa versione dell'esercizio 1 non ci sono procedure e funzioni
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 200 //lunghezza massima delle stringhe
#define DIM 30 //numero di film presenti nella lista

typedef struct {
    int numero;
    char titolo[LUNG];
    char genere[LUNG];
    int anno;
    char dispo[LUNG];
} Film;

void leggiFilm(int dim, Film lista[]) {
    FILE *fp;
    char riga[LUNG];  //variabile che salva una riga intera del csv
    int k = 0;
    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
    } else {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga

            lista[k].numero = atoi(strtok(riga, ",")); //con strtok prendo le parole fino alla ','; con atoi trasformo la stringa in una variabile intera
            strcpy(lista[k].titolo, strtok(NULL, ","));
            strcpy(lista[k].genere, strtok(NULL, ","));
            lista[k].anno = atoi(strtok(NULL, ","));
            strcpy(lista[k].dispo, strtok(NULL, ","));
            k++;
        }
    }
    fclose(fp);
}

void stampaFilm(Film lis[], int dim) {

    for(int k = 0; k < dim; k++) {
        printf("%d %s %s %d %s", lis[k].numero, lis[k].titolo, lis[k].genere, lis[k].anno, lis[k].dispo);
    }
}

int chiediAnno(){
    int anno;
    printf("inserisci l'anno dei film che vuoi vedere: ");
    scanf("%d", &anno);
    return (anno);
}

void stampaFilmAnno(Film lis[], int dim, int anno){

    for(int k = 0; k < dim; k++){
        if(lis[k].anno == anno){
            printf("%d %s %s %d %s", lis[k].numero, lis[k].titolo, lis[k].genere, lis[k].anno, lis[k].dispo);
        }
    }
}

int main(){

    Film tab_film[DIM];
    leggiFilm(DIM, tab_film);
    //stampaFilm(tab_film, DIM);
    int anno = chiediAnno();
    stampaFilmAnno(tab_film, DIM, anno);
    return 0;
}
