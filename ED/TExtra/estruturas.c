#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "estruturas.h"

//======================================================
struct _tipoInteiro
{
    int infoInt;
};

//======================================================
struct _tipoChar
{
    char infoChar[10];
};

//======================================================
struct _tipoFloat
{
    float infoFloat;
};

//======================================================
tInt criarInteiro(int v)
{
    tInt novo = (tInt)malloc(sizeof(struct _tipoInteiro));
    novo->infoInt = v;
    return novo;
}

//======================================================
tChar criarChar(char *v)
{
    tChar novo = (tChar)malloc(sizeof(struct _tipoChar));
    strcpy(novo->infoChar, v);
    return novo;
}

//======================================================
tFloat criarFloat(float v)
{
    tFloat novo = (tFloat)malloc(sizeof(struct _tipoFloat));
    novo->infoFloat=v;
    return novo;
}

//======================================================
void imprimirInteiro(void* i)
{
    tInt t = (tInt)i;
    printf("Valor: %d\n", t->infoInt);
}

void imprimirChar(void *i)
{
    tChar t = (tChar)i;
    printf("Valor: %s\n", t->infoChar);
}

void imprimirFloat(void *i)
{
    tFloat t = (tFloat)i;
    printf("Valor: %f\n", t->infoFloat);
}
