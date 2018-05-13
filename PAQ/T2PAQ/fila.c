//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fila.h"

typedef struct byte
{
    uint8_t valor;
    int quantidade;
} byte;

struct _fila
{
    byte ocorr[40];
    int topo;
};

fila fila_Inicializar()
{
    fila f=(fila)malloc(sizeof(struct _fila));
    f->topo=0;
    return f;
}

int fila_Procurar(fila f, uint8_t busca)
{
    int i;
    for(i=0;i<f->topo;i++)
    {
        if(f->ocorr[i].valor == busca)
            return i;
    }
    return -1;
}

void fila_Inserir(fila f, uint8_t valor)
{
    int pos = fila_Procurar(f, valor);

    if(pos==-1)
    {
        f->ocorr[f->topo].valor = valor;
        f->ocorr[f->topo].quantidade=1;
        f->topo++;
    }
    else
    {
        f->ocorr[pos].quantidade++;
    }

    ordenar(f);
}

void fila_Imprimir(fila f)
{
    int i;
    for(i=0;i<f->topo;i++)
        printf("%hu %d\n", f->ocorr[i].valor, f->ocorr[i].quantidade);
    printf("\n");
}

int cmp(const void *ptr1, const void *ptr2)
{
    const byte *b1 = ptr1, *b2=ptr2;
    if(b1->quantidade>b2->quantidade)
        return 1;
    else if(b1->quantidade<b2->quantidade)
        return -1;
    else
        return 0;
}

void ordenar(fila f)
{
    qsort(f->ocorr, f->topo, sizeof(byte), cmp);
}

int elempos(fila f, int pos)
{
    return f->ocorr[pos].quantidade;
}

int getTop(fila f)
{
    return f->topo;
}