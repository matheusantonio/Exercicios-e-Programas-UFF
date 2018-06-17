#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "generica.h"

struct _fila
{
    generica g;
};

//======================================================
fila filaInicializar()
{
    fila f = (fila)malloc(sizeof(struct _fila));
    f->g = genericaInicializar();
    return f;
}

//======================================================
fila filaDestruir(fila f)
{
    f->g = genericaDestruir(f->g);
    free(f);
    return NULL;
}

//======================================================
int filaCheia(fila f)
{
    return genericaCheia(f->g);
}

//======================================================
int filaVazia(fila f)
{
    return genericaVazia(f->g);
}

//======================================================
fila filaInserir(fila f, void* i, int t)
{
    f->g = genericaInserir(f->g, i, t);
    return f;
}

//======================================================
fila filaRemover(fila f)
{
    f->g = genericaRemover(f->g);
    return f;
}

//======================================================
void filaImprimir(fila f)
{
    genericaImprimir(f->g);
}
