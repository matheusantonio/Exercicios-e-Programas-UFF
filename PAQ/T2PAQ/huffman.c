#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "huffman.h"
#include "arvore.h"
#include "fila.h"


//==========================================================
//      FUNCAO DE GERACAO DA ARVORE
//==========================================================
// Essa funcao recebe como parametro uma arvore binaria e um
// vetor de arvore binarias. Enquanto o vetor possuir mais de
// um elemento, ele gera uma arvore onde os nos da direita e
// da esquerda sao as duas primeiras arvores do vetor. Em seguida,
// essa nova arvore eh adicionada ao vetor e as duas arvores usadas
// para gera-la sao removidas. A arvore que sobrar desse processo
// eh a arvore de Huffman.
raiz gerarArvore(raiz t, vetorArvore f)
{
    int i=0;
    while(treeGetTop(f)!=1)
    {
        t=gerarTree(t, f);

        insertTree(f, t);

        removeElem(f, codePosArvore(f, i));
        removeElem(f, codePosArvore(f, i));
    }

    copiarArvore(t, f);
    return t;
}

//==========================================================
//      FUNCAO DE GERACAO DO ARQUIVO
//==========================================================
// Essa funcao le novamente o arquivo original byte a byta
// e, para cada byte lido, retorna seu codigo comprimido.
// O codigo eh escrito no arquivo comprimido.
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
