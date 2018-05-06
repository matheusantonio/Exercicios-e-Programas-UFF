#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    printf("Hello world!\n");

    Pilha p = iniPilha();

    int i;
    for(i=0;i<10;i++){
        inserirPilha(p, i);
        if(i%2==0) removerPilha(p);
    }

    removerPilha(p);

    inserirPilha(p, 15);
    inserirPilha(p, 20);
    inserirPilha(p, 25);

    removerPilha(p);

    return 0;
}
