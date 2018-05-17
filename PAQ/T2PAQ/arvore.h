//
// Created by Matheus Antonio on 10/05/2018.
//
#include<stdint.h>
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

typedef struct _vetArv * vetArv;

raiz ini_Arvore();

vetArv ini_vetArvore();

void imprimirRaiz(raiz r);

int alturaRaiz(raiz r);

char* gerarCodigo(raiz r, char *bit);

char * lerCodigo(raiz r, uint8_t num);

int getSomaNo(raiz r);

void criarVetOcorr(vetArv vA, int soma, uint8_t codigo);

void imprimirVetOcorr(vetArv vA);

void imprimirAllTrees(vetArv vA);

void removeElem(vetArv vA, uint8_t codigo);

void insertTree(vetArv vA, raiz r);

int quantiPosArvore(vetArv v, int pos);

uint8_t codePosArvore(vetArv v, int pos);

int treeGetTop(vetArv aV);

void trcpy(raiz r, vetArv aV);

raiz gerarTree(raiz r, vetArv v);

void descompact(raiz r, char *nomeArq);

#endif //T2PAQ_ARVORE_H
