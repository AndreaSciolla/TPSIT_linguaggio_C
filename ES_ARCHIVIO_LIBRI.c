/*
Scrivi un programma in linguaggio C che
gestisca un archivio di libri. Il programma deve utilizzare una struttura Libro per rappresentare ciascun libro, con le seguenti
informazioni:
-Titolo (massimo 100 caratteri)
-Autore (massimo 100 caratteri)
-Anno di pubblicazione
Il programma deve consentire all'utente
di eseguire le seguenti operazioni:
-Stampare l'archivio dei libri:
-Stampa tutte le informazioni sui libri presenti nell'archivio.
-Stampa l’archivio dei libri pubblicati in un certo anno.
-Stampa tutti i libri pubblicati in ordine di anno.
Assicurati che il programma gestisca
correttamente la memoria dinamica e che non ci siano perdite di memoria.
Inoltre, gestisci eventuali errori nell'apertura del file CSV.
Ricorda di fornire un'interfaccia utente
chiara e intuitiva per consentire all'utente di eseguire queste operazioni.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100


typedef struct
{
    char titolo[LUNG];
    char autore[LUNG];
    int anno;
}Libro;

int contaRighe(){
    FILE* fp;
    int k = 0;
    char riga[1000];
    if((fp = fopen("archivio_libri.csv", "r")) != NULL){
        while(fgets(riga, 1000, fp)){
            k++;
        }
    }else{
        printf("problema nell'apertura del file");
    }
    fclose(fp);
    return k;
}

void stampaArchivio(){
    FILE* fp;
    char riga[1000];
    if((fp = fopen("archivio_libri.csv", "r")) != NULL){
        while(fgets(riga, 1000, fp)){
            printf("%s", riga);
        }
    }else{
        printf("problema nell'apertura del file");
    }
}
void stampaArchivioAnno(int anno){
    FILE* fp;
    char riga[1000];
    char titolo[LUNG];
    char nome[LUNG];
    int anno1;
    if((fp = fopen("archivio_libri.csv", "r")) != NULL){
        while(fgets(riga, 1000, fp)){
            strcpy(titolo, strtok(riga, ","));
            strcpy(nome, strtok(NULL, ","));
            anno1 = atoi(strtok(NULL, ","));
            if(anno1 == anno){
                printf("%s", riga);
            }
        }
    }else{
        printf("problema nell'apertura del file");
    }
    fclose(fp);
}

int main(){

    int dim = contaRighe();
    printf("il file contiene %d libri\n", dim);
    Libro* p, *p1;
    p = (Libro*) malloc(dim*sizeof(Libro));
    p1 = p;
    stampaArchivio();
    int anno;
    printf("quale anno vuoi cercare: ");
    scanf("%d", anno);
    stampaArchivioAnno(anno);
    return 0;
}
