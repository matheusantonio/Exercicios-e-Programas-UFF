#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a5.h"

//Como o arquivo A4 faz o papel do arquivo A5, o arquivo A5 fara o papel do arquivo A6.
// Ja que o arquivo A7 eh o arquivo A6 ordenado, o arquivo A5 fara o papel do A6 e do A7

typedef struct _funcionario5
{
    int id;
    char Chave_Estrangeira[50];
    int Prox;
} Funcionario5;

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
    l->f[l->topo].id = id;
    strcpy(l->f[l->topo].Chave_Estrangeira, chave);
    l->f[l->topo].Prox = prox;
    l->topo++;
}
