#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<string.h>
#include "fila.h"
#include "arvore.h"
#include "huffman.h"

int main() {

    char *nomeArq=(char*)malloc(sizeof(char)), *fileName=(char*)malloc(sizeof(char));

    fileName[0]='\0';

    scanf("%s", nomeArq);

//    printf("%s\n", nomeArq);

    strcat(fileName, nomeArq);

    printf("%s\n", fileName);
    strcat(fileName, ".txt");

    //Le o arquivo texto que sera usado para implementar o algoritmo
    FILE *arq = fopen(fileName, "rb");

    //Tipo fila que armazenara os bytes lidos e a quantidade de vezes que eles aparecem
    fila contagem = fila_Inicializar();

    uint8_t num;

    while(!feof(arq))
    {
        //Para cada byte lido, aidiciona ele ordenado a fila
        fread(&num, 1, 1, arq);
        fila_Inserir(contagem, num);
    }

    fclose(arq);

    //Imprime a fila de bytes lidos
    //fila_Imprimir(contagem);

    //Recebe o tamanho da fila de bytes
    int tamTree = getTop(contagem);

    //Compressao comeca aqui

    raiz tree = ini_Arvore();
    raiz aux = ini_Arvore();

    tree = gerarArvoreHuffman(tree, aux, contagem, tamTree);

    //imprimirRaiz(tree);

    gerarArquivoComprimido(tree, nomeArq);

    gerarArquivoDescomprimido(tree, nomeArq);

    return 0;
}
