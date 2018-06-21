#include <stdio.h>
#include <stdlib.h>
#include "generica.h"

struct _generica
{
    void *info;
    struct _generica *prox;
};

//======================================================
generica filaInicializar()
{
    return NULL;
}

//======================================================
generica filaDestruir(generica g)
{
    if(g!=NULL)
    {
        free(g->info);
        filaDestruir(g->prox);
        free(g);
    }
    return g;
}

//======================================================
int filaCheia(generica g)
{
    return (!filaVazia(g));
}

//======================================================
int filaVazia(generica g)
{
    return (g==NULL);
}

//======================================================
generica filaInserir(generica g, void *i)
{
    generica novo = (generica)malloc(sizeof(struct _generica));
    novo->info = i;
    if(g==NULL)
    {
        g = novo;
        g->prox = NULL;
        return g;
    }
    generica aux=g;
    while(aux->prox!=NULL) aux = aux->prox;
    aux->prox = novo;
    novo->prox = NULL;
    return g;
}

//======================================================
generica filaRemover(generica g)
{
    if(g==NULL)
    {
        printf("Fila vazia!\n");
        return g;
    }
    generica aux = g->prox;
    free(g->info);
    free(g);
    return aux;
}

//======================================================
void filaImprimir(generica g, void (*cb)(void*))
{
    if(g!=NULL)
    {
        cb(g->info);
        filaImprimir(g->prox, cb);
    }
}
