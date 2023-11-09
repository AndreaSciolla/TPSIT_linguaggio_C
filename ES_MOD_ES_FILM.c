/*
author:Andrea Sciolla
date: 18/09/2023
es:1C
testo:La videoteca "Ciak film" necessita di un programma che carichi la lista film
      in un array di struttura e che stampi a video i 5 campi : numero, titolo film, genere, anno di uscita, disponibilit� film
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
    Film* p = lista;
    fp = fopen("listafilm.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
    } else {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga

            p->numero = atoi(strtok(riga, ",")); //con strtok prendo le parole fino alla ','; con atoi trasformo la stringa in una variabile intera
            strcpy(p->titolo, strtok(NULL, ","));
            strcpy(p->genere, strtok(NULL, ","));
            p->anno = atoi(strtok(NULL, ","));
            strcpy(p->dispo, strtok(NULL, ","));
            p++;
        }
    }
    fclose(fp);
}

void stampaFilm(Film lis[], int dim) {

    for(Film*p = lis; p < p + dim; p++) {
        printf("%d %s %s %d %s", p->numero, p->titolo, p->genere, p->anno, p->dispo);
    }
}

int main(){

    Film tab_film[DIM];
    leggiFilm(DIM, tab_film);
    stampaFilm(tab_film, DIM);
    return 0;
}
