//
// Created by Matheus Antonio on 13/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "huffman.h"
#include "arvore.h"
#include "fila.h"


// Funcao que gera a arvore
raiz gerarArvore(raiz t, raiz a, vetorArvore f, int topo)
{
    int i=0;
    while(treeGetTop(f)!=1)
    {
        a=gerarTree(a, f);

        insertTree(f, a);

        removeElem(f, codePosArvore(f, i));
        removeElem(f, codePosArvore(f, i));
    }

    trcpy(t, f);
    return t;
}

void gerarArquivoComprimido(raiz t, char *nomeArq)
{
    FILE *entrada, *saida;

    uint8_t numE;
    char *aux=(char*)malloc((strlen(nomeArq)+4)*sizeof(char));
    char *codigo=(char*)malloc(sizeof(char));
    codigo[0] = '\0';

    strcpy(aux, nomeArq);
    strcat(aux, ".txt");

    entrada = fopen(aux, "rb");

    strcpy(aux, nomeArq);
    strcat(aux, ".dat");

    saida = fopen(aux, "wb");

    while(1)
    {
        fread(&numE, 1, 1, entrada);
        if(feof(entrada))
            break;
        codigo = lerCodigo(t, numE);
        fwrite(codigo, sizeof(char), strlen(codigo), saida);
    }

    fclose(entrada);
    fclose(saida);
}
