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
        return l;
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
        return novo;
    }
}
