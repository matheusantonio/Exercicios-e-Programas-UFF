#include "a2.h"
#ifndef __A1__
#define __A1__

typedef struct _lista *Lista;

Lista inicializarLista();

void inserirLista(Lista l, int id, char *nome, char *sobrenome, char *cidade, char *estado, char* data, char*empresa, char*civil, char* salario);

void imprimirFuncionarios(Lista l);

void criarArquivoA2(Lista l, Lista2 l2);

void gerarTabelaA8(Lista l, Lista5 *l5);

#endif
