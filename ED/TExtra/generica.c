#include <stdio.h>
#include <stdlib.h>
#include "generica.h"
#include "estruturas.h"

struct _generica
{
    int tipo;
    void *info;
    struct _generica *prox;
};

//======================================================
generica genericaInicializar()
{
    return NULL;
}

//======================================================
generica genericaDestruir(generica g)
{
    if(g!=NULL)
    {
        free(g->info);
        genericaDestruir(g->prox);
        free(g);
    }
    return g;
}

//======================================================
int genericaCheia(generica g)
{
    return (!genericaVazia(g));
}

//======================================================
int genericaVazia(generica g)
{
    return (g==NULL);
}

//======================================================
generica genericaInserir(generica g, void *i, int t)
{
    generica novo = (generica)malloc(sizeof(struct _generica));
    novo->tipo=t;
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
generica genericaRemover(generica g)
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
void genericaImprimir(generica g)
{
    if(g!=NULL)
    {
        if(g->tipo == 1)
        {
            tInt i = (tInt)g->info;
            imprimirInteiro(i);
        }
        else if(g->tipo == 2)
        {
            tChar c = (tChar)g->info;
            imprimirChar(c);
        }
        else if(g->tipo ==3)
        {
            tFloat f = (tFloat)g->info;
            imprimirFloat(f);
        }
        genericaImprimir(g->prox);
    }
}
