#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a5.h"

//Como o arquivo A4 faz o papel do arquivo A5, o arquivo A5 fara o papel do arquivo A6.
// Ja que o arquivo A7 eh o arquivo A6 ordenado, o arquivo A5 fara o papel do A6 e do A7

struct _funcionario5
{
    int id;
    char Chave_Estrangeira[50];
    int Prox;
};

struct _lista5
{
    Funcionario5 f[1000];
    int topo;
};

Lista5 inicializarLista5()
{
    Lista5 l = (Lista5)malloc(sizeof(struct _lista5));
    l->topo = 0;
    return l;
}

void InserirLista5(Lista5 l, int id, char *chave, int prox)
{
    Funcionario5 f = (Funcionario5)malloc(sizeof(struct _funcionario5));
    f->id = id;
    strcpy(f->Chave_Estrangeira, chave);
    f->Prox = prox;
    l->f[l->topo] = f;
    l->topo++;
}

