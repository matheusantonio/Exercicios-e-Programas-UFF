//
// Created by Matheus Antonio on 10/05/2018.
//
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

raiz ini_Arvore();

void criarSoma(raiz r, int x, int y);

void criar_NoEsquerda(raiz r, int x);

void criar_NoDireita(raiz r, int x);

void inserir_SomaEsq(raiz r, raiz soma);

void inserir_SomaDir(raiz r, raiz soma);

void imprimirRaiz(raiz r);

int getSomaNo(raiz r);

#endif //T2PAQ_ARVORE_H