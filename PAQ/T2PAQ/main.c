#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<string.h>
#include "fila.h"
#include "arvore.h"
#include "huffman.h"

int main()
{
    char nomeArq[50], fileName[50];

    scanf("%s", nomeArq);

    fileName[0]='\0';
    strcat(fileName, nomeArq);

    strcat(fileName, ".txt");

    //Le o arquivo texto que sera usado para implementar o algoritmo

    //printf("%s\n", fileName);

    FILE *arq = fopen(fileName, "rb");

    //Tipo fila que armazenara os bytes lidos e a quantidade de vezes que eles aparecem
    fila contagem = fila_Inicializar();

    uint8_t num;

    do{
        //Para cada byte lido, aidiciona ele ordenado a fila
        fread(&num, 1, 1, arq);
        if(feof(arq))
            break;
        //printf("%c", num);
        fila_Inserir(contagem, num);
    }while(1);

    printf("\n");

    fclose(arq);

    //Imprime a fila de bytes lidos
    //fila_Imprimir(contagem);

    //Recebe o tamanho da fila de bytes
    int tamTree = getTop(contagem);

    //Compressao comeca aqui

    vetorArvore test = ini_vetArvore();

    int i;
    for(i=0;i<tamTree;i++)
    {
        criarVetOcorr(test, elempos(contagem, i), getCode(contagem, i));
    }

    raiz tree = ini_Arvore();
    raiz aux = ini_Arvore();

    tree = gerarArvore(tree, aux, test, tamTree);

    //imprimirRaiz(tree);

    gerarArquivoComprimido(tree, nomeArq);

    descompactar(tree, nomeArq);

    return 0;
}
