//
// Created by Matheus Antonio on 10/05/2018.
//
#include<stdint.h>
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

raiz ini_Arvore();

void criarSoma(raiz r, int x, int y, uint8_t cx, uint8_t cy);

void criar_NoEsquerda(raiz r, int x, uint8_t c);

void criar_NoDireita(raiz r, int x, uint8_t c);

void inserir_SomaEsq(raiz r, raiz soma);

void inserir_SomaDir(raiz r, raiz soma);

void imprimirRaiz(raiz r);

char * lerCodigo(raiz r, uint8_t num);

int getSomaNo(raiz r);

#endif //T2PAQ_ARVORE_H
