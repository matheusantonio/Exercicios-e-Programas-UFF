#ifndef __FILA__
#define __FILA___

typedef struct _fila *fila;

fila filaInicializar();

fila filaDestruir(fila f);

int filaCheia(fila f);

int filaVazia(fila f);

fila filaInserir(fila f, void* i, int t);

fila filaRemover(fila f);

void filaImprimir(fila f);
#endif // __FILA__
