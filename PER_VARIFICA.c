#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int valore;
    struct node* next;
}Node;

int FirstEven(Node* l) {
int k = 0;
bool trovato = false;
 while (l != NULL && trovato == false) {
       if (l->valore % 2 == 0){
        trovato = true;
       }           
        else{
            l = l->next;
            k++;
        }
           
     }
     if(trovato==false){
        k=-1;
     }
     return k;
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

int is_empty(Node*head){
    if(head==NULL)return 1;
    else return 0;
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
        printf("%d ",p->valore);
        p=p->next;
    }
}

void push(Node**head, Node*element){  //aggiunge prima degli altri
    if(is_empty(*head)){
        *head = element;
        element->next=NULL;
    }else{
        element->next=*head;
        *head = element;
    }
}

int main(){
    int n;
    Node* head = NULL;
    do{
        printf("Inserisci un numero naturale o -1 per terminare: ");
        scanf("%d",&n);
        if(n>=0)
        {
            Node * element = (Node*)malloc(sizeof(Node));
            element->valore = n;
            push(&head, element);
        }
        
    }while(n>=0);
    stampaPila(head);
    printf("Faccio una pop: ");
    Node*removed = pop(&head);
    printf("%d \n", removed->valore);
    stampaPila(head);
    return 0;
}