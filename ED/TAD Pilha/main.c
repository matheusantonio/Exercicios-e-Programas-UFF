#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha p=iniPilha();

    int op=0, elem;

    while(op!=4)
    {
        printf("1)Inserir elemento na pilha.\n2)Remover elemento da pilha.\n3)Imprimir pilha.\n4)Sair.\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Digite o elemento que deseja inserir:");
            scanf("%d", &elem);
            inserirPilha(p, elem);
            break;
        case 2:
            removerPilha(p);
            break;
        case 3:
            imprimirPilha(p);
            break;
        case 4:
            printf("Saindo...");
            break;
        }
        fflush(stdin);
        getchar();
        system("cls");
    }
    return 0;
}
