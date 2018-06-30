#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a3.h"

//O arquivo A4 seria o arquivo A3 ordenado, logo, o arquivo A3 fara o papel do A3 e do A4

struct _funcionario3
{
    int PK;
    char ChaveEstrangeira[50];
};

struct _lista3
{
    Funcionario3 f[1000];
    int topo;
};

Lista3 inicializar3()
{
    Lista3 l = (Lista3)malloc(sizeof(struct _lista3));
    l->topo=0;
    return l;
}

void InserirLista3(Lista3 l, char estrangeira[50], int primaria)
{
    Funcionario3 f = (Funcionario3)malloc(sizeof(struct _funcionario3));
    strcpy(f->ChaveEstrangeira, estrangeira);
    f->PK = primaria;
    l->f[l->topo] = f;
    l->topo++;
}
