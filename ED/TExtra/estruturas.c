#include <stdio.h>
#include <stdlib.h>
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
tInt criarInteiro()
{
    tInt novo = (tInt)malloc(sizeof(struct _tipoInteiro));
    printf("Insira um valor inteiro: ");
    scanf("%d", &novo->infoInt);
    return novo;
}

//======================================================
tChar criarChar()
{
    tChar novo = (tChar)malloc(sizeof(struct _tipoChar));
    printf("Insira um valor char: ");
    scanf(" %s", novo->infoChar);
    return novo;
}

//======================================================
tFloat criarFloat()
{
    tFloat novo = (tFloat)malloc(sizeof(struct _tipoFloat));
    printf("Insira um valor float: ");
    scanf("%f", &novo->infoFloat);
    return novo;
}

//======================================================
void imprimirInteiro(tInt i)
{
    printf("Valor: %d\n", i->infoInt);
}

void imprimirChar(tChar c)
{
    printf("Valor: %s\n", c->infoChar);
}

void imprimirFloat(tFloat f)
{
    printf("Valor: %f\n", f->infoFloat);
}
