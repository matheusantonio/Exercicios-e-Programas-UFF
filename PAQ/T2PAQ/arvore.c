//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "arvore.h"
#include <stdint.h>

typedef struct _arvore
{
    int soma;
    uint8_t code;
    struct _arvore *esq;
    struct _arvore *dir;
} *arvore;

struct _raiz
{
    arvore a;
};

//==========================================================

raiz ini_Arvore()
{
    raiz r = (raiz)malloc(sizeof(struct _raiz));
    r->a = NULL;
    return r;
}

//==========================================================

arvore arvoreCriarSoma(arvore a, int x, int y, uint8_t cx, uint8_t cy) //adicionar codigos aqui
{

    a = (arvore)malloc(sizeof(struct _arvore));
    a->soma=x + y;
    a->code = -1;
    a->esq=(arvore)malloc(sizeof(struct _arvore));
    a->esq->soma = x;
    a->esq->code = cx;
    a->esq->esq=NULL;
    a->esq->dir=NULL;
    a->dir = (arvore)malloc(sizeof(struct _arvore));
    a->dir->soma = y;
    a->dir->code = cy;
    a->dir->esq=NULL;
    a->dir->dir=NULL;
    return a;
}

void criarSoma(raiz r, int x, int y, uint8_t cx, uint8_t cy) // adicioanr codigos aqui
{
    r->a=arvoreCriarSoma(r->a, x, y, cx, cy);
}

//==========================================================

void imprimirArvore(arvore a)
{
    if(a!=NULL)
    {
        if(a->dir==NULL && a->esq==NULL)
            printf("|%d %hu|\n", a->soma, a->code);
        imprimirArvore(a->esq);
        imprimirArvore(a->dir);
    }
}

void imprimirRaiz(raiz r)
{
    imprimirArvore(r->a);
}

//==========================================================

int alturaArvore(arvore a)
{
    if(a!=NULL)
    {
        int he, hd;
        he = 1 + alturaArvore(a->esq);
        hd = 1 + alturaArvore(a->dir);
        if(he > hd)
            return he;
        else
            return hd;
    }
    return 0;
}

//==========================================================

int checkString(char *aux)
{
    int i;
    for(i=0;i<strlen(aux);i++)
    {
        if(aux[i]=='X')
            return 0;
    }
    return 1;
}

char * ArvoreLerCodigo(arvore a, uint8_t num)
{
    if(a!=NULL)
    {
        if(a->esq==NULL &&a->dir==NULL)
        {
            if(a->code == num)
            {
                return "";
            }
            else
            {
                return "X";
            }
        }
        else
        {
            char *aux, *retorno;
            retorno = (char*)malloc(alturaArvore(a)*sizeof(char));
            aux = ArvoreLerCodigo(a->esq, num);
            if(checkString(aux))
            {
                retorno[0] = '0';
                retorno[1] = '\0';
                strcat(retorno, aux);
                return retorno;
            }
            aux = ArvoreLerCodigo(a->dir, num);
            if(checkString(aux))
            {
                retorno[0] = '1';
                retorno[1] = '\0';
                strcat(retorno, aux);
                return retorno;
            }
            return "X";
        }
    }
    return "X";
}

char *lerCodigo(raiz r, uint8_t num)
{
    return ArvoreLerCodigo(r->a, num);
}

//==========================================================

int getSomaNo(raiz r)
{
    return r->a->soma;
}

//==========================================================

arvore arvoreCriarNo(arvore a, int x, uint8_t c, char dire) // adicionar codigo aqui
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
    novo->code = c;
    soma->soma=a->soma+novo->soma;
    soma->code = -1;
    return soma;
}

void criar_NoEsquerda(raiz r, int x, uint8_t c)
{
    r->a = arvoreCriarNo(r->a, x, c, 'e');
}

void criar_NoDireita(raiz r, int x, uint8_t c)
{
    r->a = arvoreCriarNo(r->a, x, c, 'd');
}

//==========================================================

arvore inserir_Arvore(arvore a, arvore b, char dire) //inserir codigo aqui
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

