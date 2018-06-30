#ifndef __A4__
#define __A4__

typedef struct _lista4 *Lista4;

Lista4 inicializarLista4();

void inserirLista4(Lista4 l, char* chave, int qtd, int prim);

void imprimirFuncionarios4(Lista4 l);

void gerarTabela(Lista4 l, char *nome);

#endif // __A4__
