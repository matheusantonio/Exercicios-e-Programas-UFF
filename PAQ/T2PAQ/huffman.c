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
    char *aux=(char*)malloc((strlen(nomeArq)+4)*sizeof(char));
    char *codigo=(char*)malloc(sizeof(char));
    codigo[0] = '\0';

    strcpy(aux, nomeArq);
    strcat(aux, ".txt");

    entrada = fopen(aux, "rb");

    strcpy(aux, nomeArq);
    strcat(aux, ".dat");

    saida = fopen(aux, "wb");

    while(!feof(entrada))
    {
        fread(&numE, 1, 1, entrada);
        codigo = lerCodigo(t, numE);
        fwrite(codigo, sizeof(char), strlen(codigo), saida);
        //printf("%s", codigo);
    }

    fclose(entrada);
    fclose(saida);
}

void gerarArquivoDescomprimido(raiz t, char *nomeArq)
{
    char *aux = (char*)malloc((strlen(nomeArq)+4)*sizeof(char));
    strcpy(aux, nomeArq);
    strcat(aux, ".dat");

    FILE *entrada = fopen(aux, "rb");

    char v;

    while(!feof(entrada))
    {
        fread(&v, sizeof(char), 1, entrada);
        printf("%c", v);
    }

    fclose(entrada);
}

