/*
Considerate una sequenza di interi letti da input e definite una funzione C che li stampa
in modo tale che tutti i pari precedono i dispari, nello stesso ordine in cui vengono letti.
Ad esempio, se la sequenza è:
1 , 20 , 35 , 40 , 62 , 51 , 66
La stampa che si vuole ottenere e'
20 , 40 , 62 , 66 , 1 , 35 , 51
La funzione deve utilizzare come struttura dati di appoggio una pila o una coda.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct numero{
    int num;
    struct numero* next;
}Numero;

bool is_empty(Numero* head){
    return head == NULL;
}

void push(Numero **head, Numero *element){
    if(is_empty(*head)){
        *head = element;
        element->next = NULL;
    }
    else{
        element->next = *head;
        *head = element;
    }
}

Numero* pop(Numero **head){
    Numero* stack;
    if(is_empty(*head)){
        return NULL;
    }
    else{
        stack = *head;
        *head = stack->next;
    }
    return stack;
}

Numero* pila_pari_dispari(Numero* head){
    Numero* p;
    while(head->next != NULL){
        p = (Numero*)malloc(sizeof(Numero));
        if(head->num % 2 == 0)
            push(&p, head);
        head = head->next;
    }
    while(head->next != NULL){
        p = (Numero*)malloc(sizeof(Numero));
        if(head->num % 2 != 0)
            push(&p, head);
        head = head->next;
    }
    return p;
}

void print_stack(Numero* head){
    Numero* s = head;
    while(s != NULL){
        printf("%d ", s->num);
        s = s->next;
    }
}

int main(){
    Numero* head;
    Numero* el;
    Numero* pila_finale;
    char car = 'n';
    int n;
    while(car == 'n'){
        head = (Numero*)malloc(sizeof(Numero));
        el = (Numero*)malloc(sizeof(Numero));
        printf("inserisci un numero: ");
        scanf("%d", &n);
        el->num = n;
        push(&head, el);
        head = head->next;
        printf("vuoi fermare? (s o n): ");
        fflush(stdin);
        scanf("%c", &car);
    }
    pila_finale = pila_pari_dispari(head);
    print_stack(pila_finale);
    free(head); free(el); free(pila_finale);
    return 0;
}
