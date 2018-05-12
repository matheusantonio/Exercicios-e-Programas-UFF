//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
#include <stdint.h>

typedef struct arvore
{
    int soma;
    struct arvore *esq;
    struct arvore *dir;
} *arvore;

struct raiz
{
    arvore a;
};

raiz ini_Arvore()
{
    raiz r = malloc(sizeof(raiz));
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
    arvore aux = malloc(sizeof(arvore));
    aux->soma = x + a->soma;
    aux->dir=a;
    aux->esq = malloc(sizeof(arvore));
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