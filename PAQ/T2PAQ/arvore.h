//
// Created by Matheus Antonio on 10/05/2018.
//
#ifndef T2PAQ_ARVORE_H
#define T2PAQ_ARVORE_H

typedef struct _raiz *raiz;

raiz ini_Arvore();

void insereRaizPrimeiro(raiz r, int x, int y);

void inserir_Arvore(raiz r, int x);

void imprimirRaiz(raiz r);

#endif //T2PAQ_ARVORE_H