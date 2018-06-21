#ifndef __GENERICA__
#define __GENERICA___

typedef struct _generica *generica;

generica filaInicializar();

generica filaDestruir(generica g);

int filaCheia(generica g);

int filaVazia(generica g);

generica filaInserir(generica g, void* i);

generica filaRemover(generica g);

void filaImprimir(generica g, void (*cb)(void*));
#endif // __FILA__
