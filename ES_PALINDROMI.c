//chiedere una stringa e con una pila verificare se e palindroma o no
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG_MAX  100

typedef struct node{
    char c;
    struct node* next;
}Node;


int is_empty(Node*head){
    if(head==NULL)return 1;
    else return 0;
}


void push(Node**head, Node*element){
    if(is_empty(*head)){
        *head = element;
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

void stampaPila(Node* head){
    Node* p = head;
    while(p!=NULL){
        printf("%c ",p->c);
        p=p->next;
    }
}

int main(){


    int n;
    Node* head = NULL;
    char* stringa = (char*) malloc(LUNG_MAX*sizeof(char));
    printf("Inserisci una stringa: ");
    fflush(stdin);
    scanf("%s", stringa);
    printf("la stringa: %s\n", stringa);
    for(int k = 0; k < strlen(stringa); k++){
        Node* el = (Node*)malloc(sizeof(Node));
        el->c = stringa[k];
        push(&head, el);
    }
    bool avanti = true;
    int k = 0;
    Node* p = head;
    while(k < strlen(stringa)/2 && avanti){
        if(stringa[k] != p->c)
            avanti = false;
        k++;
        p = p->next;
    }
    if (avanti)
        printf("la parola inserita e' palindroma");
    else
        printf("la parola inserita non e' palindroma");

}