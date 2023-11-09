/*
author:Andrea Sciolla
date: 03/11/2023
es:VERIFICA TPSIT
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 100
#define TOT_QUOTE 2200
#define QUOTA 100

typedef struct{
    char data[LUNG];
    char cognome[LUNG];
    int quota;
}Persona;

typedef struct{
    char cognome[LUNG];
    int quota;
}Cognome;

int contarighe(){
    FILE *fp;
    int k = 0;
    char *riga = (char *)malloc(LUNG * sizeof(char));
    fp = fopen("4AROB_GITA.csv", "r");
    if (fp == NULL)
    {
        printf("Errore nell'apertura del file.\n");
        exit(1);
    }
    while (fgets(riga, LUNG, fp))
    {
        k++;
    }
    fclose(fp);
    free(riga);
    return k;
}

void calcolaQuote(Persona* p) {
    FILE *fp;
    int quote_tot = 0;
    char *riga = (char *)malloc(LUNG * sizeof(char));//variabile che salva una riga intera del csv
    fp = fopen("4AROB_GITA.csv", "r");
    if(fp == NULL) {
        printf("file inesistente");
        exit(1);
    } 
    else
     {
        while(fgets(riga, LUNG, fp)) {//salvo la riga del csv in riga
            strcpy(p->data, strtok(riga, ";")); //con strtok prendo le parole fino alla ','; con atoi trasformo la stringa in una variabile intera
            strcpy(p->cognome, strtok(NULL, ";"));
            p->quota = atoi(strtok(NULL, ";"));
            quote_tot += p->quota;
            p++;
        }
    }
    fclose(fp);
    free(riga);
    if(quote_tot == TOT_QUOTE){
        printf("sono stati incassati tutti i soldi: %d euro", quote_tot);
    }else{
        printf("sono stati incassati: %d euro; mancano: %d euro", quote_tot, TOT_QUOTE-quote_tot);
    }
}

int cercaQuotaPers(Persona* persone, char* nome, int dim) {

    Persona* p1 = persone;
    bool tro = false;
    while (persone < dim + p1 && !tro) {
        if(strcmp(nome, persone->cognome)==0){
            tro = true;
        }    
        else
            persone++;
    }
    if(!tro){
        return -1;
    }
    return persone->quota;
}

void cercaPersona(Persona* persone, int dim){
    char *nome = (char *)malloc(LUNG * sizeof(char));
    Cognome per;
    printf("\n\ninserisci il nome da cercare: ");
    gets(nome);
    strcpy(per.cognome, nome);
    per.quota = cercaQuotaPers(persone, per.cognome, dim);
    if(per.quota != -1){
    printf("%d", per.quota);
    if(per.quota == QUOTA){
        printf("\nla persona %s ha pagato tutta la quota: %d euro", per.cognome, per.quota);
    }else{
        printf("\nla persona %s ha pagato: %d euro; mancano ancora: %d euro", per.cognome, per.quota, QUOTA - per.quota);
    }
    }else{
        printf("non eseiste questa persona");
    }
}

void stampaReport(Persona* p, int dim) {
    Persona* p1;
    char *messaggio = (char *)malloc(LUNG * sizeof(char));
    strcpy(messaggio, "--DA CONTROLLARE");
    p1 = p;
    for(p; p < p1 + dim; p++) {
        if(p->quota == QUOTA)
        printf("\n%s %s %d", p->data, p->cognome, p->quota);
        else
        printf("\n%s %s %d %s", p->data, p->cognome, p->quota, messaggio);
    }
}

int main(){

    int dim = contarighe(); //conta le righe del file
    Persona* pers = (Persona*) malloc(dim*sizeof(Persona));
    Persona* p1 = pers; //dopo la prima funzione la cella puntata da pers sarà diversa, quindi la salvo in un altro puntatore a Persona
    Persona* p2 = pers; //dopo la seconda funzione la cella puntata da pers sarà diversa, quindi la salvo in un altro puntatore a Persona
    calcolaQuote(pers); //calcola la somma delle quote versate;
    cercaPersona(p1, dim);
    stampaReport(p2, dim);

    return 0;
}