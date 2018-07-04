#include "a3.h"

#ifndef __A2__
#define __A2__

typedef struct _lista2 *Lista2;

Lista2 InicializarLista2();

void InserirLista2(Lista2 l, int id, char *cidade, char *estado, char*empresa, char *civil, char* salario);

void imprimirFuncionarios2(Lista2 l);

void criarArquivoA3(Lista2 l2, Lista3 l3, int chave);

#endif // __A2__
