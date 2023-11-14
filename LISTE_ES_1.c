#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    float valore;
    struct node* next;
}Node;

int calcolaLungRic(Node* head){
    lung = 1;
    Node* l;
    l = head;
    if(l->next != NULL)
        lung += calcolaLung(l->next, lung);
    return lung;
}

int main(){

    Node* lista = NULL;
    Node* l;
    float n;
    do{
        printf("inserisci un valore (-1 per interrompere): ");
        scanf("%f", &n);
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
        printf("%.2f - %p \n", l->valore, l->next);
        l = l->next;
    }
    int elementi = calcolaLung(lista, 0);
    printf("\n\nla lista ha %d elementi", elementi);
    return 0;
}