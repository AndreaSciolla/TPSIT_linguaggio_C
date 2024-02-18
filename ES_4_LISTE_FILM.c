#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct film{
    char* genere;
    char* titolo;
    int anno;
    struct film* next;
}Film;


typedef struct Node{
    Film f;
    struct Node* next;
}Node;

int is_empty(Node*head){
    if(head==NULL)return 1;
    else return 0;
}

void push(Node**head, Node* element){
    if(is_empty(*head)){
        *head=element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head = element;
    }       
}

Node* pop(Node**head){
    Node * ret = *head;
    if(is_empty(*head)){
        return NULL;
    }else{
        *head = ret->next;
    }
    return ret;
}


int main() {
    Film film1 = {"azione", "Sborgis", 2010, NULL};
    Film film2 = {"Avventura", "Jumanji", 2015, NULL};
    Film film3 = {"horror", "Annabel", 2018, NULL};

    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->f = film1;
    node1->next = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->f = film2;
    node2->next = NULL;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->f = film3;
    node3->next = NULL;

    Node* head = NULL;

    push(&head, node1);
    push(&head, node2);
    push(&head, node3);
    while (!is_empty(head)) {
        Node* temp = pop(&head);
        printf("Titolo: %s, Genere: %s, anno: %d\n", temp->f.titolo, temp->f.genere, temp->f.anno);
        free(temp);
    }
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
