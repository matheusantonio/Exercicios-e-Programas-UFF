#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fila.h"
#include "arvore.h"














int main() {

    //Le o arquivo texto que sera usado para implementar o algoritmo
    FILE *arq = fopen("arquivo.txt", "rb");

    //Tipo fila que armazenara os bytes lidos e a quantidade de vezes que eles aparecem
    fila contagem = fila_Inicializar();

    uint8_t num;

    while(!feof(arq))
    {
        //Para cada byte lido, aidiciona ele a fila
        fread(&num, 1, 1, arq);
        fila_Inserir(contagem, num);
    }

    fclose(arq);

    fila_Imprimir(contagem);

    int tamTree = getTop(contagem);

    //Compressao comeca aqui

    raiz tree = ini_Arvore();
    raiz aux = ini_Arvore();

    int i=0;
    while(i<tamTree)
    {
        if(i==0)
        {
            criarSoma(tree, elempos(contagem, i), elempos(contagem, i+1));
            i = i+2;
        }
        else if(i==tamTree-1)
        {
            if(elempos(contagem, i) > getSomaNo(tree))
            {
                criar_NoDireita(tree, elempos(contagem, i));
            }
            else
            {
                criar_NoEsquerda(tree, elempos(contagem, i));
            }
            i++;
        }
        else if(elempos(contagem, i) > getSomaNo(tree))
        {
            //A soma ainda eh a menor frequencia
            if(i!=tamTree-1)
            {
                //adiciona dois
                criarSoma(aux, elempos(contagem, i), elempos(contagem, i+1));

                //adicionar soma a direita
                inserir_SomaDir(tree, aux);

                i = i+2;
            }
            else
            {
                //adiciona o ultimo

                //criar um novo valor e adicionar a direita
                criar_NoDireita(tree, elempos(contagem, i));

                i++;
            }
        }
        else if(elempos(contagem, i+1) <= getSomaNo(tree))
        {
            //dois menores, adicionar nova soma a esquerda
            criarSoma(aux, elempos(contagem, i), elempos(contagem, i+1));

            //adicionar soma a esquerda
            inserir_SomaEsq(tree, aux);

            i=i+2;
        }
        else
        {
            //apenas um menor, adicionar novo valor a soma a esquerda

            //criar um novo valor e adicionar a esquerda
            criar_NoEsquerda(tree, elempos(contagem, i));

            i++;
        }
    }

    imprimirRaiz(tree);

    return 0;
}