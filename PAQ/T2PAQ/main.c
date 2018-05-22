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
    char nomeArq[50], fileName[50];
    FILE *teste;


    printf("1)Comprimir arquivo txt\n2)Descomprimir arquivo txt\n3)Sair\n");
    scanf("%d", &op);

    if(op==3) return 0;

    printf("Entre com o nome do arquivo:");
    scanf("%s", nomeArq);
    fileName[0]='\0';

    if(op==1)
    {
        strcat(fileName, nomeArq);
        strcat(fileName, ".txt");

        FILE *arq = fopen(fileName, "rb");
        if(arq ==NULL)
        {
            printf("Arquivo inexistente!");
            return 0;
        }

        fila contagem = fila_Inicializar();

        uint8_t num;

        do{
            fread(&num, 1, 1, arq);
            if(feof(arq))
                break;
            fila_Inserir(contagem, num);
        }while(1);

        fclose(arq);

        int tamTree = getTop(contagem);

        vetorArvore test = ini_vetArvore();

        int i;
        for(i=0;i<tamTree;i++)
        {
            criarVetOcorr(test, elempos(contagem, i), getCode(contagem, i));
        }

        raiz tree = ini_Arvore();
        raiz aux = ini_Arvore();

        tree = gerarArvore(tree, aux, test, tamTree);

        teste = fopen("arquivo.tree", "wb");

        salvarRaiz(tree, teste);

        fclose(teste);

        gerarArquivoComprimido(tree, nomeArq);
    }
    else if(op == 2)
    {
        raiz tentativa = ini_Arvore();

        teste = fopen("arquivo.tree", "rb");
        if(teste == NULL)
        {
            printf("Arquivo inexistente!");
            return 0;
        }

        lerRaiz(tentativa, teste);

        fclose(teste);

        descompactar(tentativa, nomeArq);
    }
    return 0;
}
