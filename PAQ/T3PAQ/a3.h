#include "a4.h"
#include "a5.h"
#ifndef __A3__
#define __A3__

typedef struct _lista3 *Lista3;

Lista3 inicializar3();

void InserirLista3(Lista3 l, int primaria, char estrangeira[50]);

void ordenarLista3(Lista3 l);

void imprimirFuncionarios3(Lista3 l);

void criarArquivoA4(Lista3 l, Lista4 l4);

void CriarArquivoA5(Lista3 l3,Lista5 l5);

#endif // __A3__
