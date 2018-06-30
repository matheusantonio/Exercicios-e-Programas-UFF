#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2.h"

struct _funcionario2{
    int id;
    char Cidade[30];
    char Estado[30];
    char Empresa[30];
    char Estado_Civil[10];
};

struct _lista2{
    Funcionario2 f[1000]; //usamos 1000 pois sabemos que eh o tamanho da tabela
    int topo;
};

Lista2 InicializarLista2()
{
    Lista2 l=(Lista2)malloc(sizeof(struct _lista2));
    l=NULL;
    l->topo=0;
    return l;
}

void InserirLista2(Lista2 l, int id, char *cidade, char *estado, char*empresa, char *civil)
{
    Funcionario2 f=(Funcionario2)malloc(sizeof(struct _funcionario2));
    f->id = id;
    strcpy(f->Cidade, cidade);
    strcpy(f->Estado, estado);
    strcpy(f->Empresa, empresa);
    strcpy(f->Estado_Civil, civil);
    l->f[l->topo] = f;
    l->topo++;
}

