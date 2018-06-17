#ifndef __GENERICA__
#define __GENERICA___

typedef struct _generica *generica;

generica genericaInicializar();

generica genericaDestruir(generica g);

int genericaCheia(generica g);

int genericaVazia(generica g);

generica genericaInserir(generica g, void* i, int t);

generica genericaRemover(generica g);

void genericaImprimir(generica g);
#endif // __FILA__
