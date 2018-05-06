#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

struct lista
{
    int x;
    Lista *prox;
};

Lista iniLista()
{
    Lista l = NULL;
    return l;
}

Lista inserirLista(Lista l, int x)
{
    if(l==NULL)
    {
        l = malloc(sizeof(Lista));
        l->x=x;
        l->prox=NULL;
    }
    else
    {
        Lista aux=l;
        while(aux->prox!=NULL)
            aux=aux->prox;
        Lista novo = malloc(sizeof(Lista));
        aux->prox=novo;
        novo->x=x;
        novo->prox=NULL;
    }
    return l;
}

void imprimirLista(Lista l)
{
    Lista aux = l;
    printf("\n");
    while(aux!=NULL)
    {
        printf("%d |", aux->x);
        aux =aux->prox;
    }
    printf("\n");
}

Lista removerLista(Lista l)
{
    Lista aux = l, aux2=l;
    while(aux->prox!=NULL)
        aux = aux->prox;
    if(aux==l)
    {
        free(aux);
        return NULL;
    }
    while(aux2->prox!=aux)
        aux2 = aux2->prox;
    free(aux);
    aux2->prox=NULL;
    return l;
}
