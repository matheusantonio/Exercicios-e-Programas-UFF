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

struct _vetorArvore
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

vetorArvore ini_vetArvore()
{
    vetorArvore v = (vetorArvore)malloc(sizeof(struct _vetorArvore));
    v->topo=0;
    return v;
}

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

void salvarArvore(arvore a, FILE *arq)
{
    char *string=(char*)malloc(sizeof(char));
    string[0]='\0';
    if(a!=NULL)
    {
        sprintf(string, "(%c", a->code);
        fwrite(string, sizeof(char), strlen(string), arq);
        salvarArvore(a->esq, arq);
        salvarArvore(a->dir, arq);
    }
    else
    {
        sprintf(string, "(0");
        fwrite(string, sizeof(char), strlen(string), arq);
    }
    sprintf(string, ")");
    fwrite(string, sizeof(char), 1, arq);
}

void salvarRaiz(raiz t, FILE *arq)
{
    salvarArvore(t->a, arq);
}

arvore lerArvore(arvore a, FILE *arq)
{
    char *symb=(char*)malloc(sizeof(char)), *code=(char*)malloc(sizeof(char));
    fread(symb, sizeof(char), 1, arq);
    fread(code, sizeof(char), 1, arq);
    if(*code != '0')
    {
        a = (arvore)malloc(sizeof(struct _arvore));
        a->code = *code;
        a->soma = 0;
        a->esq = lerArvore(a->esq, arq);
        a->dir = lerArvore(a->dir, arq);
    }
    else
    {
        a = NULL;
    }
    fread(symb, sizeof(char), 1, arq);
    return a;
}

void lerRaiz(raiz r, FILE *arq)
{
    r->a = lerArvore(r->a, arq);
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

raiz gerarTree(raiz r, vetorArvore v)
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
void descompactar(raiz r, char *nomeArq)
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
void criarVetOcorr(vetorArvore v, int soma, uint8_t codigo)
{
    v->a[v->topo] = (arvore)malloc(sizeof(struct _arvore));
    v->a[v->topo]->soma = soma;
    v->a[v->topo]->code = codigo;
    v->a[v->topo]->dir=NULL;
    v->a[v->topo]->esq=NULL;
    v->topo++;
}

void imprimirVetOcorr(vetorArvore v)
{
    int i;
    for(i=0;i<v->topo;i++)
    {
        printf("%c %d |", v->a[i]->code, v->a[i]->soma);
    }
}

void imprimirAllTrees(vetorArvore v)
{
    int i;
    for(i=0;i<v->topo;i++)
    {
        imprimirArvore(v->a[i]);
    }
}

void removeElem(vetorArvore v, uint8_t codigo)
{
    int i;
    for(i=0;i<v->topo; i++)
    {
        if(v->a[i]->code == codigo)
        {
            int j;
            for(j=i;j<v->topo;j++)
            {
                v->a[j] = v->a[j+1];
            }
            break;
        }
    }
    v->topo--;
}

void _insertTree(vetorArvore v, arvore a)
{
    int i;
    for(i=0;i<v->topo;i++)
    {
        if(a->soma <= v->a[i]->soma)
        {
            int j;
            for(j=v->topo;j>i;j--)
            {
                v->a[j] = v->a[j-1];
            }
            v->a[i] = a;
            break;
        }
    }
    if(i==v->topo)
        v->a[i] = a;
    v->topo++;
}

void insertTree(vetorArvore v, raiz r)
{
    _insertTree(v, r->a);
}

int quantiPosArvore(vetorArvore v, int pos)
{
    return v->a[pos]->soma;
}

uint8_t codePosArvore(vetorArvore v, int pos)
{
    return v->a[pos]->code;
}

int treeGetTop(vetorArvore v)
{
    return v->topo;
}

void trcpy(raiz r, vetorArvore v)
{
    r->a = v->a[0];
}

arvore getTreePos(vetorArvore v, int pos)
{
    return v->a[pos];
}
