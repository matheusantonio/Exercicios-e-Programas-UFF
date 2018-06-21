#ifndef __ESTRUTURA__
#define __ESTRUTURA__

//======================================================
typedef struct _tipoInteiro *tInt;

//======================================================
typedef struct _tipoChar *tChar;

//======================================================
typedef struct _tipoFloat *tFloat;

//======================================================
tInt criarInteiro(int v);

//======================================================
tChar criarChar(char *v);

//======================================================
tFloat criarFloat(float v);

//======================================================
void imprimirInteiro(void *i);

//======================================================
void imprimirChar(void *i);

//======================================================
void imprimirFloat(void *i);

#endif // __ESTRUTURA__
