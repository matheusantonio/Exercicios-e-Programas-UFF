//=====================================================
// Construir um TAD fila generico.
// Inicializar, destruir, verificar se esta cheio,
// verificar se esta vazio, inserir, remover
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct _tipo1
{
    int info1;
} tipo1;

typedef struct _tipo2
{
    char info2[10];
} tipo2;

typedef struct _tipo3
{
    float tipo3;
} tipo3;

int main()
{
    fila f = filaInicializar();



    return 0;
}
