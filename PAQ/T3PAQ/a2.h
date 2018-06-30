#ifndef __A2__
#define __A2__

typedef struct _funcionario2 *Funcionario2;

typedef struct _lista2 *Lista2;

Lista2 InicializarLista2();

void InserirLista2(Lista2 l, int id, char *cidade, char *estado, char*empresa, char *civil);

#endif // __A2__
