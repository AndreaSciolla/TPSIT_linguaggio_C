#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct El
{
    int dato;
    struct El* next;
}El;


int FirstEven(El* l) {
int k = 0;
bool trovato = false;
 while (l != NULL && trovato == false) {
       if (l->dato % 2 == 0){
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
    printf("la posizione del primo numero pari e': %d",FirstEven(lista));
    free(lista);
    return 0;
}