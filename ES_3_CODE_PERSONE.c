#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct persona{ // Nodo della coda che rappresenta una persona
    char* nome;
    char* cognome;
    int eta;
    struct persona* next;
}Persona;

int is_empty(Persona* head){
    return head == NULL;
}

void inserisciInCoda(Persona** head, Persona** tail, Persona* elem){
    //enqueue
    if(is_empty(*head)){
        *head = elem;
    }
    else{
        (*tail)->next = elem;
    }
    *tail = elem;
    elem->next = NULL;
}

Persona* rimuoviDallaCoda(Persona** head, Persona** tail){
    //dequeue
    Persona* ret = *head;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        *head = ret->next;
    }
    if(*head == NULL){
        *tail = NULL;
    }
    return ret;
}


void visualizzaCoda(Persona *head)
{
    Persona *h = head;
    printf("Coda: \n");
    while (h != NULL)
    {
        printf("%s, %s, %d\n", h->nome, h->cognome, h->eta);
        h = h->next;
    }
}

void uscitaProgramma(Persona *head){
    if(head->next != NULL){
        uscitaProgramma(head->next);
    }
        free(head);
}

int main() {
    Persona* head = (Persona*)malloc(sizeof(Persona));
    Persona* tail = (Persona*)malloc(sizeof(Persona));
    Persona* elemento = (Persona*)malloc(sizeof(Persona));
    Persona* elemento2 = (Persona*)malloc(sizeof(Persona));
    Persona* temp;

    head = NULL;
    tail = NULL;
    elemento->cognome = "Bergia";
    elemento->nome = "Benedetta";
    elemento->eta = 18;
    elemento->next = NULL;
    inserisciInCoda(&head, &tail, elemento);

    elemento2->cognome = "Rossi";
    elemento2->nome = "Benedetta";
    elemento2->eta = 18;
    elemento2->next = NULL;

    inserisciInCoda(&head, &tail, elemento2);
    visualizzaCoda(head);

    temp = rimuoviDallaCoda(&head, &tail);

    visualizzaCoda(head);
    uscitaProgramma(elemento);
    return 0;
}
