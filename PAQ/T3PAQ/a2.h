#ifndef __A2__
#define __A2__

typedef struct _lista2 *Lista2;

Lista2 InicializarLista2();

void InserirLista2(Lista2 l, int id, char *cidade, char *estado, char*empresa, char *civil);

void imprimirFuncionarios2(Lista2 l);

#endif // __A2__
