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

raiz gerarArvoreHuffman(raiz t, raiz a, fila f, int topo)
{
    int i=0;
    while(i<topo)
    {
        if(i==0)
        {
            criarSoma(t, elempos(f, i), elempos(f, i+1), getCode(f, i), getCode(f, i+1));
            i = i+2;
        }
        else if(i==topo-1)
        {
            if(elempos(f, i) > getSomaNo(t))
            {
                criar_NoDireita(t, elempos(f, i), getCode(f, i));
            }
            else
            {
                criar_NoEsquerda(t, elempos(f, i), getCode(f, i));
            }
            i++;
        }
        else if(elempos(f, i) > getSomaNo(t))
        {
            //A soma ainda eh a menor frequencia
            if(i!=topo-1)
            {
                //adiciona dois
                criarSoma(a, elempos(f, i), elempos(f, i+1), getCode(f, i), getCode(f, i+1));

                //adicionar soma a direita
                inserir_SomaDir(t, a);

                i = i+2;
            }
            else
            {
                //adiciona o ultimo
                //criar um novo valor e adicionar a direita
                criar_NoDireita(t, elempos(f, i), getCode(f, i));

                i++;
            }
        }
        else if(elempos(f, i+1) <= getSomaNo(t))
        {
            //dois menores, adicionar nova soma a esquerda
            criarSoma(a, elempos(f, i), elempos(f, i+1), getCode(f, i), getCode(f, i+1));

            //adicionar soma a esquerda
            inserir_SomaEsq(t, a);

            i=i+2;
        }
        else
        {
            printf("else elempos <= getsoma\n");
            //apenas um menor, adicionar novo valor a soma a esquerda
            //criar um novo valor e adicionar a esquerda
            criar_NoEsquerda(t, elempos(f, i), getCode(f, i));

            i++;
        }
    }
    return t;
}

void gerarArquivoComprimido(raiz t, char *nomeArq)
{
    FILE *entrada, *saida;

    uint8_t numE;
    char *aux="";

    entrada = fopen("arquivo.txt", "rb");
    saida = fopen("arquivo.zip", "wb");



    while(!feof(entrada))
    {
        fread(&numE, 1, 1, entrada);
        aux = lerCodigo(t, numE);
        fwrite(&aux, 1, 1, saida);
        printf("%hu %s\n", numE, aux);
    }

    fclose(entrada);
    fclose(saida);
}
