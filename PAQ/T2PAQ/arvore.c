//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <stdint.h>

typedef struct _arvore
{
    int soma;
    struct _arvore *esq;
    struct _arvore *dir;
} *arvore;

struct _raiz
{
    arvore a;
};

raiz ini_Arvore()
{
    raiz r = (raiz)malloc(sizeof(struct _raiz));
    r->a = NULL;
    return r;
}

arvore InserirPrimeiro(arvore a, int x, int y)
{
    a = malloc(sizeof(arvore));
    a->soma=x + y;
    a->esq=malloc(sizeof(arvore));
    a->esq->soma = x;
    a->esq->esq=NULL;
    a->esq->dir=NULL;
    a->dir = malloc(sizeof(arvore));
    a->dir->soma = y;
    a->dir->esq=NULL;
    a->dir->dir=NULL;
    return a;
}

void insereRaizPrimeiro(raiz r, int x, int y)
{
    r->a=InserirPrimeiro(r->a, x, y);
}

arvore inserir_No(arvore a, int x)
{
    arvore aux = (arvore)malloc(sizeof(struct _arvore));
    aux->soma = x + a->soma;
    aux->dir=a;
    aux->esq = (arvore)malloc(sizeof(struct _arvore));
    aux->esq->soma = x;
    aux->esq->esq = NULL;
    aux->esq->dir = NULL;
    return aux;
}

void inserir_Arvore(raiz r, int x)
{
    r->a=inserir_No(r->a, x);
}

void imprimirArvore(arvore a)
{
    if(a!=NULL)
    {
        imprimirArvore(a->esq);
        printf("%d |", a->soma);
        imprimirArvore(a->dir);
    }
}

void imprimirRaiz(raiz r)
{
    imprimirArvore(r->a);
}