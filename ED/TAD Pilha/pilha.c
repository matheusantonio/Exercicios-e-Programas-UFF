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
    imprimirPilha(p);
}

void imprimirPilha(Pilha p)
{
    if(pilhaVazia(p))
    {
        printf("Pilha vazia!");
        return;
    }
    imprimirLista(p->l);
}

void removerPilha(Pilha p)
{
    if(pilhaVazia(p))
    {
        printf("Pilha vazia!");
        return;
    }
    p->l=removerLista(p->l);
    imprimirPilha(p);
}

int pilhaVazia(Pilha p)
{
    return listaVazia(p->l);
}
