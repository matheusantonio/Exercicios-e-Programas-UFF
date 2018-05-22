#include<stdint.h>
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

typedef struct _vetorArvore * vetorArvore;

//==========================================================
raiz ini_Arvore();

vetorArvore ini_vetArvore();

//==========================================================
int alturaRaiz(raiz r);

int getSomaNo(raiz r);

int quantiPosArvore(vetorArvore v, int pos);

uint8_t codePosArvore(vetorArvore v, int pos);

int treeGetTop(vetorArvore v);

//==========================================================
void imprimirRaiz(raiz r);

void imprimirVetOcorr(vetorArvore v);

void imprimirAllTrees(vetorArvore v);

//==========================================================
void salvarRaiz(raiz t, FILE *arq);

void lerRaiz(raiz r, FILE *arq);

//==========================================================
void criarVetOcorr(vetorArvore v, int soma, uint8_t codigo);

raiz gerarTree(raiz r, vetorArvore v);

void removeElem(vetorArvore v, uint8_t codigo);

void insertTree(vetorArvore v, raiz r);

void copiarArvore(raiz r, vetorArvore v);

//==========================================================
char * lerCodigo(raiz r, uint8_t num);

char* gerarCodigo(raiz r, char *bit);

//==========================================================
void descompactar(raiz r, char *nomeArq);

#endif //T2PAQ_ARVORE_H
