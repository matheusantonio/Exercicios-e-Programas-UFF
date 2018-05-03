#include<stdio.h>
#include<stdlib.h>
#include "fila.h"

typedef struct lista
{
    int x;
    struct lista *prox;
} Lista;

struct fila
{
    Lista * l;
    int topo;
};

Fila Inicializar()
{
    Fila f = (Fila)malloc(sizeof(Fila));
    f->l = NULL;
    f->topo = 0;
    return f;
}

Fila Destruir(Fila f)
{
    Lista *aux;
    while(f->l!=NULL)
    {
        aux=f->l;
        f->l=aux->prox;
        free(aux);
    }
    return f;
}

int vazia(Fila f)
{
    return f->l==NULL;
}

int cheia(Fila f)
{
    return f->topo==100;
}

void Inserir(Fila f, int x)
{
    Lista*aux;
    if(!vazia(f))
    {
        aux = f->l;
        while(aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        Lista*novo = malloc(sizeof(Lista));
        novo->prox=NULL;
        novo->x=x;
        aux->prox=novo;
    }
    else
    {
        f->l = malloc(sizeof(Lista));
        f->l->prox = NULL;
        f->l->x = x;
    }
    f->topo++;
}

int remover(Fila f)
{
    int x;
    if(f->l==NULL)
        return 0;
    Lista*aux = f->l;
    f->l = f->l->prox;
    x = aux->x;
    free(aux);
    return x;
}

void imprimir(Fila f)
{
    Lista*aux=f->l;
    while(aux!=NULL)
    {
        printf("%d |", aux->x);
        aux = aux->prox;
    }
}
