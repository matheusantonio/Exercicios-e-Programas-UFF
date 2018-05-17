//
// Created by Matheus Antonio on 13/05/2018.
//
#include "fila.h"
#include "arvore.h"
#ifndef T2PAQ_HUFFMAN_H
#define T2PAQ_HUFFMAN_H

raiz gerarArvore2(raiz t, raiz a, vetArv f, int topo);

void gerarArquivoComprimido(raiz t, char *nomeArq);

void gerarArquivoDescomprimido(raiz t, char *nomeArq);

#endif //T2PAQ_HUFFMAN_H
