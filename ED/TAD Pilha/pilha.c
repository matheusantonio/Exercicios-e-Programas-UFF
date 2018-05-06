#include<stdio.h>
#include<stdlib.h>
#include "pilha.h"
#include "lista.h"

struct pilha
{
    Lista l;
};

Pilha iniPilha()
{
    Pilha p = (Pilha)malloc(sizeof(Pilha));
    p->l=iniLista();
    return p;
}

void inserirPilha(Pilha p, int x)
{
    p->l=inserirLista(p->l, x);
    imprimirLista(p->l);
}

void imprimirPilha(Pilha p)
{
    imprimirLista(p->l);
}

void removerPilha(Pilha p)
{
    p->l=removerLista(p->l);
    imprimirLista(p->l);
}
