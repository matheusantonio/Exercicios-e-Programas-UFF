#ifndef __ESTRUTURA__
#define __ESTRUTURA__

//======================================================
typedef struct _tipoInteiro *tInt;

//======================================================
typedef struct _tipoChar *tChar;

//======================================================
typedef struct _tipoFloat *tFloat;

//======================================================
tInt criarInteiro();

//======================================================
tChar criarChar();

//======================================================
tFloat criarFloat();

//======================================================
void imprimirInteiro(tInt i);

//======================================================
void imprimirChar(tChar c);

//======================================================
void imprimirFloat(tFloat f);

#endif // __ESTRUTURA__
