#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct _fila
{
    int tipo;
    void *info;
    struct _fila *prox;
};

//======================================================
fila filaInicializar()
{
    return NULL;
}

//======================================================
fila filaDestruir(fila f)
{
    if(f!=NULL)
    {
        free(f->info);
        filaDestruir(f->prox);
        free(f);
    }
    return f;
}

//======================================================
int filaCheia(fila f)
{
    return (!filaVazia(f));
}

//======================================================
int filaVazia(fila f)
{
    return (f==NULL);
}

//======================================================
fila filaInserir(fila f, void *i, int t)
{
    fila novo = (fila)malloc(sizeof(struct _fila));
    novo->tipo=t;
    novo->info = i;
    fila aux=f;
    while(aux->prox!=NULL) aux = aux->prox;
    aux->prox = novo;
    novo->prox = NULL;
    return f;
}

//======================================================
fila filaRemover(fila f)
{
    fila aux = f->prox;
    free(f->info);
    free(f);
    return aux;
}

//======================================================
void filaImprimir(fila f)
{
    if(f!=NULL)
    {
        if(f->tipo == 1)
        {
            printf("Tipo1\n");
        }
        else if(f->tipo == 2)
        {
            printf("Tipo2\n");
        }
        else if(f->tipo ==3)
        {
            printf("Tipo3\n");
        }
        filaImprimir(f->prox);

    }
}

