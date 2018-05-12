#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fila.h"
#include "arvore.h"

int main() {

    FILE *arq = fopen("arquivo.txt", "rb");

    fila contagem = fila_Inicializar();

    uint8_t num;

    while(!feof(arq))
    {
        fread(&num, 1, 1, arq);
        fila_Inserir(contagem, num);
    }

    fclose(arq);

    fila_Imprimir(contagem);

    raiz huff = ini_Arvore();

    insereRaizPrimeiro(huff, elempos(contagem, 0), elempos(contagem, 1));

    int i;
    for(i=2; i<getTop(contagem); i++)
    {
        inserir_Arvore(huff, elempos(contagem, i));
    }

    imprimirRaiz(huff);

    return 0;
}