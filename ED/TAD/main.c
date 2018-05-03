#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main()
{
    Fila f;
    int x;

    f = Inicializar();

    Inserir(f, 10);
    imprimir(f);
    printf("\n");
    Inserir(f, 20);
    imprimir(f);
    printf("\n");

    x = remover(f);
    printf("%d", x);
    printf("\n");
    imprimir(f);
    printf("\n");

    f=Destruir(f);
    imprimir(f);

    return 0;
}
