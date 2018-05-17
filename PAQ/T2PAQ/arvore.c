//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "arvore.h"
#include <stdint.h>

// Arvore binaria que guarda as frequencias.
// Nos nos internos, estao a soma das frequencias de seus
// nos filhos.
// Nas folhas, estao as frequencias de cada caracter lido.
// A arvore armazena o valor do byte nas folhas na variavel
// code, caso nao seja folha, armazena -1
typedef struct _arvore
{
    int soma;
    uint8_t code;
    struct _arvore *esq;
    struct _arvore *dir;
} *arvore;

struct _raiz
{
    arvore a;
};

struct _vetArv
{
    arvore a[255];
    int topo;
};

//==========================================================
// Inicializa a arvore, alocando espaco para a struct
// raiz e setando a arvore associada como NULL (arvore vazia)
raiz ini_Arvore()
{
    raiz r = (raiz)malloc(sizeof(struct _raiz));
    r->a = NULL;
    return r;
}

vetArv ini_vetArvore()
{
    vetArv vA = (vetArv)malloc(sizeof(struct _vetArv));
    vA->topo=0;
    return vA;
}

//==========================================================


//==========================================================
// Funcao recursiva simples que retorna a altura de uma arvore
int alturaArvore(arvore a)
{
    if(a!=NULL)
    {
        int he, hd;
        he = 1 + alturaArvore(a->esq);
        hd = 1 + alturaArvore(a->dir);
        if(he > hd)
            return he;
        else
            return hd;
    }
    return 0;
}

int alturaRaiz(raiz r)
{
    return alturaArvore(r->a);
}

//==========================================================
// funcao recursiva simples para imprimir uma arvore
void imprimirArvore(arvore a)
{
    if(a!=NULL)
    {
        if(a->dir==NULL && a->esq==NULL)
            printf("|%c %d|\n", a->code, a->soma);
        imprimirArvore(a->esq);
        imprimirArvore(a->dir);
    }
}

void imprimirNiveis(arvore a, int atual, int vez)
{
    if(a!=NULL)
    {
        if(atual == vez)
        {
            if(a->esq==NULL && a->dir==NULL)
                printf("|%c  %d|", a->code, a->soma);
            else
                printf("|-|");
        }
        else
        {
            imprimirNiveis(a->esq, atual+1, vez);
            imprimirNiveis(a->dir, atual+1, vez);
        }
        if(atual==0 && vez !=alturaArvore(a))
        {
            printf("\n");
            imprimirNiveis(a, atual, vez+1);
        }
    }
}

void imprimirRaiz(raiz r)
{
    imprimirNiveis(r->a, 0, 0);
}

//==========================================================
// Essa funcao verifica se existe um caracter "X" em uma string
int checkString(char *aux)
{
    int i;
    for(i=0;i<strlen(aux);i++)
    {
        if(aux[i]=='X')
            return 0;
    }
    return 1;
}

// Essa eh uma funcao recursiva que decifra o codigo
// em bits de um determinado valor. Ela percorre a arvore
// binaria procurando pelo valor num. Caso encontre ele,
// ela concatena uma string vazia, que eh retornada pela
// funcao recursiva que foi chamada no no acima da folha
// que concatena um bit 1 ou 0, dependendo de a chamada
// ter sido feita para o filho da esquerda ou da direita.
// Caso o ponteiro chegue a uma folha que nao representa
// num, ele concatena um "X". A string resultante eh
// verificada e descartada se contiver um X, ou seja,
// se chegou a uma folha que nao contem num
char * ArvoreLerCodigo(arvore a, uint8_t num)
{
    if(a!=NULL)
    {
        if(a->esq==NULL &&a->dir==NULL)
        {
            if(a->code == num)
            {
                return "";
            }
            else
            {
                return "X";
            }
        }
        else
        {
            char *aux, *retorno;
            retorno = (char*)malloc(alturaArvore(a)*sizeof(char));
            aux = ArvoreLerCodigo(a->esq, num);
            if(checkString(aux))
            {
                retorno[0] = '0';
                retorno[1] = '\0';
                strcat(retorno, aux);
                return retorno;
            }
            aux = ArvoreLerCodigo(a->dir, num);
            if(checkString(aux))
            {
                retorno[0] = '1';
                retorno[1] = '\0';
                strcat(retorno, aux);
                return retorno;
            }
            return "X";
        }
    }
    return "X";
}

char *lerCodigo(raiz r, uint8_t num)
{
    return ArvoreLerCodigo(r->a, num);
}

//==========================================================
// Retorna o valor soma da raiz de uma arvore
uint8_t getValueTree(arvore a)
{
    return a->code;
}

int getSomaNo(raiz r)
{
    return r->a->soma;
}

raiz gerarTree(raiz r, vetArv v)
{
    arvore novo = (arvore)malloc(sizeof(struct _arvore));
    novo->esq = v->a[1];
    novo->dir = v->a[0];
    novo->code=-1;
    novo->soma = v->a[0]->soma + v->a[1]->soma;
    r->a = novo;
    return r;
}

//==========================================================
char* gerarCodigo(raiz r, char *bit)
{
    FILE *arq = fopen("saida.txt", "ab");
    arvore aux = r->a;
    int i=0;

    for(i=0;i<strlen(bit);i++)
    {
        if(aux->esq == NULL && aux->dir == NULL)
            break;

        if(bit[i] == '0'){
            aux = aux->esq;
        }
        else
        {
            aux = aux->dir;
        }
    }

    uint8_t val = getValueTree(aux);

    fwrite(&val, sizeof(uint8_t), 1, arq);

    int j=0, k=i+1;

    for(;j!=k;j++)
    {
        bit[j] = bit[i+j];
    }
    bit[j]='\0';

    fclose(arq);
    return bit;
}


void descompact(raiz r, char *nomeArq)
{
    FILE *teste = fopen("saida.txt", "r");
    if(teste != NULL)
    {
        fclose(teste);
        remove("saida.txt");
    }
    else
        free(teste);

    char *aux = (char*)malloc((strlen(nomeArq)+4)*sizeof(char));
    strcpy(aux, nomeArq);
    strcat(aux, ".dat");

    char bit;

    FILE *entrada = fopen(aux, "rb");

    FILE *arq = fopen("saida.txt", "wb");
    arvore codif = r->a;

    while(1)
    {
        fread(&bit, sizeof(char), 1, entrada);
        if(feof(entrada))
            break;
        if(bit == '0')
            codif = codif->esq;
        else
            codif = codif->dir;

        if(codif->esq==NULL && codif->dir==NULL)
        {
            char c = codif->code;
            fwrite(&c, sizeof(char), 1, arq);
            codif = r->a;
        }

    }
    fclose(arq);

    fclose(entrada);
}



//==========================================================
void criarVetOcorr(vetArv vA, int soma, uint8_t codigo)
{
    vA->a[vA->topo] = (arvore)malloc(sizeof(struct _arvore));
    vA->a[vA->topo]->soma = soma;
    vA->a[vA->topo]->code = codigo;
    vA->a[vA->topo]->dir=NULL;
    vA->a[vA->topo]->esq=NULL;
    vA->topo++;
}

void imprimirVetOcorr(vetArv vA)
{
    int i;
    for(i=0;i<vA->topo;i++)
    {
        printf("%c %d |", vA->a[i]->code, vA->a[i]->soma);
    }
}

void imprimirAllTrees(vetArv vA)
{
    int i;
    for(i=0;i<vA->topo;i++)
    {
        imprimirArvore(vA->a[i]);
    }
}

void removeElem(vetArv vA, uint8_t codigo)
{
    int i;
    for(i=0;i<vA->topo; i++)
    {
        if(vA->a[i]->code == codigo)
        {
            int j;
            for(j=i;j<vA->topo;j++)
            {
                vA->a[j] = vA->a[j+1];
            }
            break;
        }
    }
    vA->topo--;
}

void _insertTree(vetArv vA, arvore a)
{
    int i;
    for(i=0;i<vA->topo;i++)
    {
        if(a->soma <= vA->a[i]->soma)
        {
            int j;
            for(j=vA->topo;j>i;j--)
            {
                vA->a[j] = vA->a[j-1];
            }
            vA->a[i] = a;
            break;
        }
    }
    if(i==vA->topo)
        vA->a[i] = a;
    vA->topo++;
}

void insertTree(vetArv vA, raiz r)
{
    _insertTree(vA, r->a);
}

int quantiPosArvore(vetArv v, int pos)
{
    return v->a[pos]->soma;
}

uint8_t codePosArvore(vetArv v, int pos)
{
    return v->a[pos]->code;
}

int treeGetTop(vetArv aV)
{
    return aV->topo;
}

void trcpy(raiz r, vetArv aV)
{
    r->a = aV->a[0];
}

arvore getTreePos(vetArv vA, int pos)
{
    return vA->a[pos];
}
