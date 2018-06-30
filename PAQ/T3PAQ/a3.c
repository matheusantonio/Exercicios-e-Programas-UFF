#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a3.h"

//O arquivo A4 seria o arquivo A3 ordenado, logo, o arquivo A3 fara o papel do A3 e do A4

typedef struct _funcionario3
{
    int PK;
    char ChaveEstrangeira[50];
} Funcionario3;

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

void InserirLista3(Lista3 l, int primaria, char estrangeira[50])
{
    strcpy(l->f[l->topo].ChaveEstrangeira, estrangeira);
    l->f[l->topo].PK = primaria;
    l->topo++;
}

void imprimirFuncionarios3(Lista3 l)
{
    int i;
    for(i=0;i<l->topo;i++)
        printf("%d: %s\n", l->f[i].PK, l->f[i].ChaveEstrangeira);
    printf("\n");
}
