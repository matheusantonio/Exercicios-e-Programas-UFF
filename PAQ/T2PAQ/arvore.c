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

arvore arvoreCriarSoma(arvore a, int x, int y)
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

void criarSoma(raiz r, int x, int y)
{
    r->a=arvoreCriarSoma(r->a, x, y);
}



void imprimirArvore(arvore a)
{
    if(a!=NULL)
    {
        if(a->dir==NULL && a->esq==NULL)
            printf("%d |", a->soma);
        imprimirArvore(a->esq);
        imprimirArvore(a->dir);
    }
}

void imprimirRaiz(raiz r)
{
    imprimirArvore(r->a);
}

int getSomaNo(raiz r)
{
    return r->a->soma;
}













arvore arvoreCriarNo(arvore a, int x, char dire)
{
    arvore novo = (arvore)malloc(sizeof(struct _arvore));
    arvore soma = (arvore)malloc(sizeof(struct _arvore));
    if(dire == 'e')
    {
        soma->esq=novo;
        soma->dir=a;
    }
    else if(dire == 'd')
    {
        soma->esq=a;
        soma->dir=novo;
    }
    novo->esq=NULL;
    novo->dir=NULL;
    novo->soma=x;
    soma->soma=a->soma+novo->soma;
    return soma;
}

void criar_NoEsquerda(raiz r, int x)
{
    r->a = arvoreCriarNo(r->a, x, 'e');
}

void criar_NoDireita(raiz r, int x)
{
    r->a = arvoreCriarNo(r->a, x, 'd');
}

arvore inserir_Arvore(arvore a, arvore b, char dire)
{
    arvore novo = (arvore)malloc(sizeof(struct _arvore));
    if(dire == 'e')
    {
        novo->dir = a;
        novo->esq = b;
    }
    else if(dire == 'd')
    {
        novo->esq = a;
        novo->dir = b;
    }
    novo->soma = a->soma + b->soma;
    return novo;
}

void inserir_SomaEsq(raiz r, raiz soma)
{
    r->a = inserir_Arvore(r->a, soma->a, 'e');
}

void inserir_SomaDir(raiz r, raiz soma)
{
    r->a = inserir_Arvore(r->a, soma->a, 'd');
}









