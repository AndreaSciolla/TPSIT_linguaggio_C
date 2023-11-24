#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    int valore;
    struct node* next;
}Node;

int calcolaLungRic(Node* head){  //funzione ricorsiva che conta il numero di elementi
    int lung = 1;
    Node* l;
    l = head;
    if(l->next != NULL)
        lung += calcolaLungRic(l->next);
    return lung;
}

int calcolaLungRic2(Node* head){    //funzione ricorsiva + ottimizzata che conta il numero di elementi
    if(head->next != NULL)
        return 1 + calcolaLungRic2(head->next);
    return 1;
}

void stampaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d\n", l->valore);
        stampaRicorsiva(l->next);
    }
}

void aggiungiElementoFine(Node** lista, int n){
    Node* l = *lista;
    while(l->next != NULL){ 
        l = l->next;
    }
    l->next = (Node*) malloc(sizeof(Node));
    l = l->next;
    l->valore = n;
    l->next = NULL;
}

void aggiungiElementoInizio(Node** lista, int n){
    Node* head;
    head = (Node*) malloc(sizeof(Node));
    head->next = *lista;
    head->valore = n;
    *lista = head;
}

void eliminaUltimoElemento(Node** lista){
    Node *l = *lista;
    Node *l2 = l;
    while(l->next != NULL){
        l2 = l;
        l = l->next;
    }
    l2->next = NULL;
}

int main(){

    Node* lista = NULL;
    Node* l;
    int n;
    do{
        printf("inserisci un valore (-1 per interrompere): ");
        scanf("%d", &n);
        if(n >= 0){
            if(lista == NULL){
                lista = (Node*) malloc(sizeof(Node));
                l = lista;
            }
            else{
                l->next = (Node*) malloc(sizeof(Node)); 
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    }while(n >= 0);
    l = lista;
    while (l!= NULL){
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    int elementi = calcolaLungRic2(lista);
    printf("\n\nla lista ha %d elementi\n", elementi);

    stampaRicorsiva(lista);
    printf("inserisci un nuovo elemento: ");
    scanf("%d", &n);
    aggiungiElementoFine(&lista, n);
    printf("inserisci un nuovo elemento: ");
    scanf("%d", &n);
    aggiungiElementoInizio(&lista, n);
    eliminaUltimoElemento(&lista);
    stampaRicorsiva(lista);
    

    return 0;
}