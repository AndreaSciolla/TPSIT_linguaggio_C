/*
author:Andrea Sciolla
date: 17/10/2023
es: SINTESI VERIFICA
testo:-Creare un file .csv con COGNOME, NOME, NASCITA (annomesegiorno in formato INT)
-scorrere il file con la funzione FGETS e STRTOK
-stampare in ordine DECRESCENTE (dal più grande al più piccolo)
 utilizzando i puntatori e allocazione dinamica (MALLOC)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 300

typedef struct{
    int anno;
    int mese;
    int giorno;
}Data;

typedef struct {
    char nome[LUNG];
    char cognome[LUNG];
    Data data;
} Persona;

int contaRighe() {
    FILE *fp;
    char riga[LUNG];  //variabile che salva una riga intera del csv
    int k = 0;
    fp = fopen("es_sintesi.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
    } else {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga
        k++;
        }
    }
    fclose(fp);
    return k;
}

void leggiPersone(int dim, Persona* p) {
    FILE *fp;
    char riga[LUNG];  //variabile che salva una riga intera del csv
    fp = fopen("es_sintesi.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
    } else {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga
            strcpy(p->cognome, strtok(riga, ",")); //con strtok prendo le parole fino alla ','; con atoi trasformo la stringa in una variabile intera
            strcpy(p->nome, strtok(NULL, ","));
            p->data.anno = atoi(strtok(NULL, ","));
            p->data.mese = atoi(strtok(NULL, ","));
            p->data.giorno = atoi(strtok(NULL, ","));
            p++;
        }
    }
    fclose(fp);
}

void scambio(Persona *x, Persona *y){
    Persona a; 
    a = *x;
    *x = *y;
    *y = a;
}

void ordinaDecre(Persona p[], int n){
    int k,sup,sca;
    sup = n-1 ;
    while ( sup>0 ) {
        sca = 0;
        for (Persona* p1 = p ; p1 < p+sup; p1++) {
            if ((p1->data.anno) < ((p1+1)->data.anno)) {
                scambio(p1, p1+1);
                sca = p - p;
            }
        }
        sup = sca;
}
}

void stampaPersone(Persona* p, int dim) {
    Persona* p1;
    p1 = p;
    for(p; p < p1 + dim; p++) {
        printf("\n%s %s %d/%d/%d", p->cognome, p->nome, p->data.anno, p->data.mese, p->data.giorno);
    }
}

int main(){
    int dim = contaRighe();
    Persona* p, *p1;
    p = (Persona*) malloc(dim*sizeof(Persona));
    p1 = p;
    leggiPersone(dim, p);
    ordinaDecre(p1, dim);
    stampaPersone(p1, dim);
    return 0;
}