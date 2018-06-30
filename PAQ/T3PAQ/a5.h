#ifndef __A5__
#define __A5__

typedef struct _lista5 *Lista5;

Lista5 inicializarLista5();

void InserirLista5(Lista5 l, int id, char *chave, int prox);

void ordenarLista5(Lista5 l);

void imprimirFuncionarios5(Lista5 l);

#endif // __A5__
