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

    //Arvore onde serao armazenadas as frequencias de cada byte para implementacao do algoritmo
    raiz huff = ini_Arvore();

    //Funcao para inserir as duas primeiras frequencias
    insereRaizPrimeiro(huff, elempos(contagem, 0), elempos(contagem, 1));

    int i;
    for(i=2; i<getTop(contagem); i++)
    {
        //Insercao do resto das frequencias
        inserir_Arvore(huff, elempos(contagem, i));
    }

    imprimirRaiz(huff);

    return 0;
}