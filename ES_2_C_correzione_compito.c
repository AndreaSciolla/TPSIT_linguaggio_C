/*
author:Andrea Sciolla
date:
es:VERSIONE SPIEGATA DAL PROF ES 1
testo:in questa versione dell'esercizio 1 non ci sono procedure e funzioni
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define DIM_RIGA 200
#define NUM_RIGHE 20000

typedef struct{
    int numero;
    char* titolo;
    char* genere;
    int anno;
    char* disponibilita;
} film;

int main(){

    char filename[] ="listafilm.csv";
    char riga[DIM_RIGA];
    FILE *fp;
    char* campo;
    film array_film[NUM_RIGHE];
    int counter = 0;

    fp = fopen(filename, "r");
    if( fp == NULL){
        printf("il file non esiste");
        exit(1); //interrompe il programma e ritorna 1
    }
    while(fgets(riga, DIM_RIGA, fp)){
        campo = strtok(riga, ",");
        array_film[counter].numero = atoi(campo);   //per i float si usa atof

        campo = strtok(NULL, ",");
        array_film[counter].titolo = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].genere = strdup(campo);

        campo = strtok(NULL, ",");
        array_film[counter].anno = atoi(campo);

        campo = strtok(NULL, ",");
        array_film[counter].disponibilita = strdup(campo);

        counter++;
    }
    fclose(fp);
    for(int k = 0; k < counter; k++){
        printf("%d %s %s %d %s", array_film[k].numero, array_film[k].titolo, array_film[k].genere, array_film[k].anno, array_film[k].disponibilita);
    }
return 0;
}
