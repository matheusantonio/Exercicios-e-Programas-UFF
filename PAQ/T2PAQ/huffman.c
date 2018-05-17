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
raiz gerarArvore2(raiz t, raiz a, vetArv f, int topo)
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
        printf("%c ", numE);
        codigo = lerCodigo(t, numE);
        fwrite(codigo, sizeof(char), strlen(codigo), saida);
        //printf("%s", codigo);
    }

    fclose(entrada);
    fclose(saida);
}

void gerarArquivoDescomprimido(raiz t, char *nomeArq)
{
    FILE *teste = fopen("saida.txt", "r");
    if(teste != NULL)
    {
        fclose(teste);
        remove("saida.txt");
    }
    else
        free(teste);

    char *aux = (char*)malloc((strlen(nomeArq)+4)*sizeof(char));
    strcpy(aux, nomeArq);
    strcat(aux, ".dat");

    FILE *entrada = fopen(aux, "rb");

    int tam = alturaRaiz(t), tamAtual=0, tamAlocado;
    char v[tam], text[tam];

    while(1)
    {
        if(feof(entrada))
            break;
        if(tamAtual < tam)
        {
            tamAlocado=tam-tamAtual;
        }

        fread(text, sizeof(char), tamAlocado, entrada);

        v[tamAtual] = '\0';
        strcat(v, text);

        *v = (char)gerarCodigo(t, v);

        tamAtual = strlen(v);
    }

    fclose(entrada);
}
