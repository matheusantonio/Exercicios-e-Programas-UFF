
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a1.h"
#include "a2.h"

typedef struct _funcionario{
    int id;
    char Nome[15];
    char Sobrenome[15];
    char Cidade[30];
    char Estado[30];
    char Data_Nascimento[10];
    char Empresa[30];
    char Estado_Civil[20];
    float Salario;
} Funcionario;

struct _lista{
    Funcionario f[1000]; //usamos 1000 pois sabemos que eh o tamanho da tabela
    int topo;
};

//==================================================
Lista inicializarLista()
{
    Lista l = (Lista)malloc(sizeof(struct _lista));
    l->topo=0;
    return l;
}

//==================================================
void inserirLista(Lista l, int id, char *nome, char *sobrenome, char *cidade, char *estado, char* data, char*empresa, char*civil, float salario)
{
    l->f[l->topo].id = id;
    strcpy(l->f[l->topo].Nome, nome);
    strcpy(l->f[l->topo].Sobrenome, sobrenome);
    strcpy(l->f[l->topo].Cidade, cidade);
    strcpy(l->f[l->topo].Estado, estado);
    strcpy(l->f[l->topo].Data_Nascimento, data);
    strcpy(l->f[l->topo].Empresa, empresa);
    strcpy(l->f[l->topo].Estado_Civil, civil);
    l->f[l->topo].Salario = salario*1000;  //Por causa do padrao diferente, o ponto que separa a casa do milhar esta sendo lido como ponto flutuante
    l->topo++;
}

//==================================================
void imprimirFuncionarios(Lista l)
{
    int i;
    for(i=0 ; i<l->topo ; i++)
        printf("%d: %s %s %s %.2f\n", l->f[i].id, l->f[i].Nome, l->f[i].Cidade, l->f[i].Data_Nascimento, l->f[i].Salario);
}

//==================================================
// Insere, para cada linah em A1, uma nova linha em
// A2 contendo os elementos que serao considerados
// chaves secundarias
void criarArquivoA2(Lista l, Lista2 l2)
{
    int i;
    for(i=0;i<l->topo;i++)
    {
        InserirLista2(l2, l->f[i].id, l->f[i].Cidade, l->f[i].Estado, l->f[i].Empresa, l->f[i].Estado_Civil);
    }
}

//==================================================
// Essa funcao gera o arquivo final A8.
// Primeiro, sao impressos no arquivo os nomes das
// colunas, sendo adicionados os nomes das colunas
// que indicam a proxima ocorrencia das chaves
// secundarias.
// Em seguida, sao impressas todas as informacoes da
// tabela A1 e, para cada chave secundaria, sua proxima
// ocorrencia, retornada em uma funcao que verifica o
// valor Prox da tabela A5 (A7 do slide) na linha atual
void gerarTabelaA8(Lista l, Lista5 *l5)
{
    FILE *arq = fopen("saidaA8.csv", "w");

    fprintf(arq, "Nome,Sobrenome,Cidade,Estado,Data_Nascimento,Empresa,Estado_Civil,Salario,");
    fprintf(arq, "Prox_Cidade,Prox_Estado,Prox_Empresa,Prox_Estado_Civil\n");

    int i;
    for(i=0;i<l->topo;i++)
    {
        fprintf(arq, "%s,%s,%s,%s,%s,%s,%s,R$%.2f,", l->f[i].Nome, l->f[i].Sobrenome, l->f[i].Cidade, l->f[i].Estado, l->f[i].Data_Nascimento, l->f[i].Empresa, l->f[i].Estado_Civil, l->f[i].Salario);
        fprintf(arq, "%d,%d,%d,%d\n", proximo(l5[0], i), proximo(l5[1], i), proximo(l5[2], i), proximo(l5[3], i));
    }

    fclose(arq);
}
