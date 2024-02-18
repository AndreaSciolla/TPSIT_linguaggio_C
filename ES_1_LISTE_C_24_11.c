#include <stdio.h>
#include <stdlib.h>

typedef struct El
{
    int dato;
    struct El* next;
}El;


int sommaLista(El* lista, int x){
    int somma=0;
    El*l=lista;
    if(l==NULL){
        return -1;
    }
    while(l!=NULL){
        if(l->dato%x==0){
            somma=somma+l->dato;
        }
        l=l->next;
    }
    return somma;
}


int main(){
    int lung=0;
    El* lista = NULL;
    El* l;
    int n;
    do{
        printf("Inserisci un numero: -1 per terminare: ");
        scanf("%d",&n);
        if(n>=0){
            if(lista==NULL){
                lista=(El*)malloc(sizeof(El));
                l = lista;
            }else{
                l->next=(El*)malloc(sizeof(El));
                l= l->next;
            }
            l->dato=n;
            l->next=NULL;
        }
    }while(n>=0);
    printf("la somma vale: %d",sommaLista(lista,2));
    return 0;
}
