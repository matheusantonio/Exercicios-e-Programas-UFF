
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a1.h"

struct _funcionario{
    int id;
    char Nome[15];
    char Sobrenome[15];
    char Cidade[30];
    char Estado[30];
    char Data_Nascimento[8];
    char Empresa[30];
    char Estado_Civil[10];
    float Salario;
};

struct _lista{
    Funcionario f[1000]; //usamos 1000 pois sabemos que eh o tamanho da tabela
    int topo;
};

Lista inicializarLista()
{
    Lista l = (Lista)malloc(sizeof(struct _lista));
    l->topo=0;
    return l;
}

void inserirLista(Lista l, int id, char *nome, char *sobrenome, char *cidade, char *estado, char* data, char*empresa, char*civil, float salario)
{
    Funcionario f = (Funcionario)malloc(sizeof(struct _funcionario));
    f->id = id;
    strcpy(f->Nome, nome);
    strcpy(f->Sobrenome, sobrenome);
    strcpy(f->Cidade, cidade);
    strcpy(f->Estado, estado);
    strcpy(f->Data_Nascimento, data);
    strcpy(f->Empresa, empresa);
    strcpy(f->Estado_Civil, civil);
    f->Salario = salario*1000;  //Por causa do padrao diferente, o ponto que separa a casa do milhar esta sendo lido como ponto flutuante
    l->f[l->topo] = f;
    l->topo++;
}

void imprimirFuncionarios(Lista l)
{
    int i;
    for(i=0 ; i<l->topo ; i++)
        printf("%d: %s %.2f\n", l->f[i]->id, l->f[i]->Nome, l->f[i]->Salario);
}
