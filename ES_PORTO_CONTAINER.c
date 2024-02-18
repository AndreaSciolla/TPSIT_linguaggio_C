#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct container{
    char* codice;
    int peso;
    int tara;
    struct container* next;
}Container;

typedef struct Node{
    Container c;
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

    Container cont1 = {"1023a", 450, 35, NULL};
    Container cont2 = {"1024a", 430, 40, NULL};
    Container cont3 = {"1025a", 410, 45, NULL};

    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->c = cont1;
    node1->next = NULL;

    Node* node2 = (Node*)malloc(sizeof(Node));
    node2->c = cont2;
    node2->next = NULL;

    Node* node3 = (Node*)malloc(sizeof(Node));
    node3->c = cont3;
    node3->next = NULL;

    Node* head = NULL;

    push(&head, node1);
    push(&head, node2);
    push(&head, node3);
    while (!is_empty(head)) {
        Node* temp = pop(&head);
        printf("codice: %s, peso: %d, tara: %d\n", temp->c.codice, temp->c.peso, temp->c.tara);
        free(temp);
    }

    return 0;
}
