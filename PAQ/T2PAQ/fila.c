//
// Created by Matheus Antonio on 10/05/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fila.h"


// Struct que representa um byte (valor) e a quantidade de vezes
// que foi lido no arquivo.
typedef struct byte
{
    uint8_t valor;
    int quantidade;
} byte;

// Struct que armazena o vetor com os bytes encontrados.
// Topo representa o topo atual do vetor, ou seja, a quantidade
// de bytes encontrados ate o momento, que indica o fim do vetor.
struct _fila
{
    byte ocorr[255];
    int topo;
};

//==========================================================
// Funcao que inicializa a fila, alocando espaco para a
// struct fila.
fila fila_Inicializar()
{
    fila f=(fila)malloc(sizeof(struct _fila));
    f->topo=0;
    return f;
}

//==========================================================
// Funcao para verificar se um dado valor ja existe na fila
// Caso exista, retorna sua posicao no veotr, caso nao
// exista, retorna -1
int fila_Procurar(fila f, uint8_t busca)
{
    int i;
    for(i=0;i<f->topo;i++)
    {
        if(f->ocorr[i].valor == busca)
            return i;
    }
    return -1;
}

//==========================================================
// Funcao que recebe um dado valor e verifica se ele ja
// existe na fila. Caso nao exista (procurar retorna -1),
// ele cria um novo espaco no vetor para esse elemento.
// Caso exista (procurar retorna a posicao dele), acessa
// sua posicao e adiciona +1 em "quantidade".
void fila_Inserir(fila f, uint8_t valor)
{
    int pos = fila_Procurar(f, valor);

    if(pos==-1)
    {
        f->ocorr[f->topo].valor = valor;
        f->ocorr[f->topo].quantidade=1;
        f->topo++;
    }
    else
    {
        f->ocorr[pos].quantidade++;
    }

    ordenar(f);
}

//==========================================================
// Uma funcao simples para imprimir os elementos de fila.
// Foi usada apenas para testes.
void fila_Imprimir(fila f)
{
    int i;
    for(i=0;i<f->topo;i++)
        printf("%c %d\n", f->ocorr[i].valor, f->ocorr[i].quantidade);
    printf("\n");
}

//==========================================================
// CMP eh a funcao usada para qsort comparar dois elementos
// arbitrarios do vetor.
int cmp(const void *ptr1, const void *ptr2)
{
    const byte *b1 = ptr1, *b2=ptr2;
    if(b1->quantidade>b2->quantidade)
        return 1;
    else if(b1->quantidade<b2->quantidade)
        return -1;
}

void ordenar(fila f)
{
    qsort(f->ocorr, f->topo, sizeof(byte), cmp);
}

//==========================================================
// recebe uma posicao e retorna a quantidade de vezes que
// o elemento representado por essa posicao foi lido
int elempos(fila f, int pos)
{
    return f->ocorr[pos].quantidade;
}

//==========================================================
// Retorna o tamanho do vetor de bytes
int getTop(fila f)
{
    return f->topo;
}

//==========================================================
// Recebe uma posicao e retorna o valor byte representado
// por essa posicao no vetor.
uint8_t getCode(fila f, int pos)
{
    return f->ocorr[pos].valor;
}
