#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a4.h"

//O arquivo A4 seria o arquivo A3 ordenado, logo, o arquivo A4 fara o papel do arquivo A5

typedef struct _funcionario4
{
    char Chave_Estrangeira[50];
    int qtd;
    int Prim;
} Funcionario4;

struct _lista4
{
    Funcionario4 f[1000];
    int topo;
};

Lista4 inicializarLista4()
{
    Lista4 l = (Lista4)malloc(sizeof(struct _lista4));
    l->topo=0;
    return l;
}

void inserirLista4(Lista4 l, char* chave, int qtd, int prim)
{
    strcpy(l->f[l->topo].Chave_Estrangeira, chave);
    l->f[l->topo].qtd = qtd;
    l->f[l->topo].Prim = prim;
    l->topo++;
}
