#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "a3.h"

//==================================================
// O arquivo A4 seria o arquivo A3 ordenado, logo, o
// arquivo A3 fara o papel do A3 e do A4

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

//==================================================
Lista3 inicializar3()
{
    Lista3 l = (Lista3)malloc(sizeof(struct _lista3));
    l->topo=0;
    return l;
}

//==================================================
void InserirLista3(Lista3 l, int primaria, char estrangeira[50])
{
    strcpy(l->f[l->topo].ChaveEstrangeira, estrangeira);
    l->f[l->topo].PK = primaria;
    l->topo++;
}

//==================================================
// O arquivo A3 eh ordenado para que faca o papel
// do arquivo A4 do slide
int cmp3(const void *a, const void *b)
{
     Funcionario3 *Funcionario3A = (Funcionario3 *)a;
     Funcionario3 *Funcionario3B = (Funcionario3 *)b;
    return strcmp(Funcionario3A->ChaveEstrangeira, Funcionario3B->ChaveEstrangeira);
}

void ordenarLista3(Lista3 l)
{
    qsort(l->f, l->topo, sizeof(Funcionario3), cmp3);
}

//==================================================
void imprimirFuncionarios3(Lista3 l)
{
    int i;
    for(i=0;i<l->topo;i++)
        printf("%d: %s\n", l->f[i].PK, l->f[i].ChaveEstrangeira);
    printf("\n");
}

//==================================================
// Essa funcao cria o arquivo A4 (A5 do slide) a
// partir do A3 ordenado (A4 do slide). Ela pega
// uma chave secundaria, armazena sua posicao,
// conta quantas chaves secundarias iguais existem
// e passa por parametro essas duas informacoes
// para a funcao que insere valores no arquivo a4
void criarArquivoA4(Lista3 l, Lista4 l4)
{
    int cont=1, prim, i;
    char atual[50] = {' '};
    for(i=0;i<=l->topo;i++)
    {
        if(i==l->topo)
            inserirLista4(l4, atual, cont, prim);
        else if(!strcmp(atual, l->f[i].ChaveEstrangeira))
            cont++;
        else
        {
            if(strcmp(atual, " ")) inserirLista4(l4, atual, cont, prim);
            cont=1;
            prim=l->f[i].PK;
            strcpy(atual, l->f[i].ChaveEstrangeira);
        }
    }
}

//====================================================
// Essa funcao usa o arquivo A3 ordenado (A4 do slide)
// para gerar o arquivo A5 (A6 do slide). Ela percorre
// a lista ordenada inserindo a chave das proximas
// ocorrencias de uma mesma chave secundaria, como estamos
// contando os enderecos a partir de 0, a ultima chave
// recebe -1 como proxima ocorrencia.
void CriarArquivoA5(Lista3 l3,Lista5 l5)
{
    int i,prox=0,id=0, j;
    char Atual[50]={' '};
    for(i=0;i<l3->topo;i++)
    {
        strcpy(Atual,l3->f[i].ChaveEstrangeira);
        for(j=i+1;j<=l3->topo;j++)
        {
            if(j==l3->topo)
                prox=-1;
            if(!strcmp(Atual,l3->f[j].ChaveEstrangeira))
               {
                   prox=l3->f[j].PK;
                   break;
               }
        }
        id=l3->f[i].PK;
        InserirLista5(l5,id,Atual,prox);
    }
}
