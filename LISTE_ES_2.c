#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int valore;
    struct node *next;
} Node;

void stampaRicorsiva(Node* lista){
    Node* l = lista;
    if(l != NULL){
        printf("%d\n", l->valore);
        stampaRicorsiva(l->next);
    }
}

int somma(Node *head, int M)
{
    if (head == NULL)
    {
        return -1;
    }
    int somma_M = 0;
    Node *l = head;

    while (l != NULL)
    {
        if (l->valore % M == 0)
        {
            somma_M += l->valore;
        }
        l = l->next;
    }
    return somma_M;
}

int main()
{
    Node *lista = NULL;
    Node *l;
    int n;
    do
    {
        printf("inserisci un valore (-1 per interrompere): ");
        scanf("%d", &n);
        if (n >= 0)
        {
            if (lista == NULL)
            {
                lista = (Node *)malloc(sizeof(Node));
                l = lista;
            }
            else
            {
                l->next = (Node *)malloc(sizeof(Node));
                l = l->next;
            }
            l->valore = n;
            l->next = NULL;
        }
    } while (n >= 0);
    l = lista;
    while (l != NULL)
    {
        printf("%d - %p \n", l->valore, l->next);
        l = l->next;
    }
    stampaRicorsiva(lista);
    printf("\ninserisci un numero di cui cercare i multipli: ");
    scanf("%d", &n);
    int sommaMult = somma(lista , n);
    printf("la somma dei multiplo e %d", sommaMult);



}