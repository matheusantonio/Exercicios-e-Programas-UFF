//=============================================================
// 1) Inserir uma aresta (perguntar quantos nos tem no grafo)
// So deve ser inserido de nao existir.
// 2) remover uma aresta
// 3) Imprimir o grafo (Ex: 1: 2|2.5, 3|3, ...)
// 4) Calcular grau de um vertice (especificar os 3)
// 5) verificafr se o grafo eh espaço
// 6) Sair e destruir
//=============================================================
#include<stdio.h>
#include<stdlib.h>

typedef struct aresta
{
    int destino;
    float custo;
    struct aresta *prox;
} Aresta;

typedef struct grafo
{
    Aresta *a;
} Grafo;





int main()
{

    return 0;
}
