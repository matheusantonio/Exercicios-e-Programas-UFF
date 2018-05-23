#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include<string.h>
#include "fila.h"
#include "arvore.h"
#include "huffman.h"

int main()
{
    int op;
    char nomeArq[50], nomeArqExt[50], nomeArqTree[50];
    FILE *arqArvore;

    //Menu de opcoes
    printf("1)Comprimir arquivo txt\n2)Descomprimir arquivo txt\n3)Sair\n");
    scanf("%d", &op);

    if(op==3) return 0;

    printf("Entre com o nome do arquivo:");
    scanf("%s", nomeArq);
    nomeArqExt[0]='\0';

    if(op==1)
    {
        //Adiciona extensao .txt ao nome recebido pelo usuario
        strcat(nomeArqExt, nomeArq);
        strcat(nomeArqExt, ".txt");

        //Abre o arquivo desejado e verifica se ele existe
        FILE *arq = fopen(nomeArqExt, "rb");
        if(arq ==NULL)
        {
            printf("Arquivo inexistente!");
            return 0;
        }

        //Cria uma estrutura do tipo fila, onde serao armazenados
        // os bytes do arquivo
        fila contagem = fila_Inicializar();

        uint8_t num; //Armazenara cada byte lido

        do{
            fread(&num, 1, 1, arq);
            if(feof(arq))
                break;
            fila_Inserir(contagem, num); //Chama funcao que insere um valor na fila criada
        }while(1);

        fclose(arq);

        //Cria uma estrutura do tipo arvore binaria
        int tamArvore = getTop(contagem);

        //Cria uma estrutura do tipo vetor de arvores binarias
        vetorArvore filaArvores = ini_vetArvore();

        //Interacao para armazenar cada byte lido, com sua frequencia, no
        // vetor de arvore binarias. Cada elemento da fila torna-se uma
        // arvore sem filhos.
        int i;
        for(i=0;i<tamArvore;i++)
        {
            criarVetOcorr(filaArvores, elempos(contagem, i), getCode(contagem, i));
        }

        //Arvore tree recebera a arvore de huffman final. Arvore aux servira como auxiliar
        raiz aHuffman = ini_Arvore();

        // Funcao que gera a arvore de huffman
        aHuffman = gerarArvore(aHuffman, filaArvores);

        strcat(nomeArqTree, nomeArq);
        strcat(nomeArqTree, ".tree");

        arqArvore = fopen(nomeArqTree, "wb");

        //Aqui, a arvore e salva em um arquivo .tree
        salvarRaiz(aHuffman, arqArvore);

        fclose(arqArvore);

        //Funcao que gera o arquivo comprimido
        gerarArquivoComprimido(aHuffman, nomeArq);
    }
    else if(op == 2)
    {
        //Arvore que recebera a arvore de huffman de um arquivo
        raiz aHuffman = ini_Arvore();

        //Adiciona extensao .tree ao nome recebido pelo usuario
        strcat(nomeArqExt, nomeArq);
        strcat(nomeArqExt, ".tree");

        //Abertura do arquivo que contem a arvore e verificacao se ele existe
        arqArvore = fopen(nomeArqExt, "rb");
        if(arqArvore == NULL)
        {
            printf("Arquivo inexistente!");
            return 0;
        }

        //Funcao que le o arquivo e recebe a arvore
        lerRaiz(aHuffman, arqArvore);

        fclose(arqArvore);

        //Funcao que descompacta o arquivo comprimido e gera o arquivo "saida.txt"
        descompactar(aHuffman, nomeArq);
    }
    return 0;
}
