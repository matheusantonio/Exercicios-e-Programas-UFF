//
// Created by Matheus Antonio on 13/05/2018.
//
#include "fila.h"
#include "arvore.h"
#ifndef T2PAQ_HUFFMAN_H
#define T2PAQ_HUFFMAN_H

raiz gerarArvoreHuffman(raiz t, raiz a, fila f, int topo);

void gerarArquivoComprimido(raiz t, char *nomeArq);

#endif //T2PAQ_HUFFMAN_H
