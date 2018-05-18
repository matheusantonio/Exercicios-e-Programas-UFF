//
// Created by Matheus Antonio on 10/05/2018.
//
#include<stdint.h>
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

typedef struct _vetorArvore * vetorArvore;

raiz ini_Arvore();

vetorArvore ini_vetArvore();

void imprimirRaiz(raiz r);

int alturaRaiz(raiz r);

char* gerarCodigo(raiz r, char *bit);

char * lerCodigo(raiz r, uint8_t num);

int getSomaNo(raiz r);

void criarVetOcorr(vetorArvore v, int soma, uint8_t codigo);

void imprimirVetOcorr(vetorArvore v);

void imprimirAllTrees(vetorArvore v);

void removeElem(vetorArvore v, uint8_t codigo);

void insertTree(vetorArvore v, raiz r);

int quantiPosArvore(vetorArvore v, int pos);

uint8_t codePosArvore(vetorArvore v, int pos);

int treeGetTop(vetorArvore v);

void trcpy(raiz r, vetorArvore v);

raiz gerarTree(raiz r, vetorArvore v);

void descompactar(raiz r, char *nomeArq);

#endif //T2PAQ_ARVORE_H
