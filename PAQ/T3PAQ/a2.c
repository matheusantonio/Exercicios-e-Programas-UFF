#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a2.h"
#include "a3.h"

typedef struct _funcionario2{
    int id;
    char Cidade[30];
    char Estado[30];
    char Empresa[30];
    char Estado_Civil[15];
} Funcionario2;

struct _lista2{
    Funcionario2 f[1000]; //usamos 1000 pois sabemos que eh o tamanho da tabela
    int topo;
};

Lista2 InicializarLista2()
{
    Lista2 l=(Lista2)malloc(sizeof(struct _lista2));
    l->topo=0;
    return l;
}

void InserirLista2(Lista2 l, int id, char *cidade, char *estado, char*empresa, char *civil)
{
    l->f[l->topo].id = id;
    strcpy(l->f[l->topo].Cidade, cidade);
    strcpy(l->f[l->topo].Estado, estado);
    strcpy(l->f[l->topo].Empresa, empresa);
    strcpy(l->f[l->topo].Estado_Civil, civil);
    l->topo++;
}

void imprimirFuncionarios2(Lista2 l)
{
    int i;
    for(i=0 ; i<l->topo ; i++)
        printf("%d: %s %s\n", l->f[i].id, l->f[i].Cidade, l->f[i].Empresa);
}

void criarArquivoA3(Lista2 l2, Lista3 l3, int chave)
{
    int i;
    for(i=0;i<l2->topo;i++)
    {
        if(chave==0)
            InserirLista3(l3, l2->f[i].id, l2->f[i].Cidade);
        else if(chave==1)
            InserirLista3(l3, l2->f[i].id, l2->f[i].Estado);
        else if(chave==2)
            InserirLista3(l3, l2->f[i].id, l2->f[i].Empresa);
        else if(chave==3)
            InserirLista3(l3, l2->f[i].id, l2->f[i].Estado_Civil);
    }
}


