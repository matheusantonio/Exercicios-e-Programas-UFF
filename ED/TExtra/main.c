//=====================================================
// Construir um TAD fila generico.
// Inicializar, destruir, verificar se esta cheio,
// verificar se esta vazio, inserir, remover
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include "fila.h"
#include "estruturas.h"

//======================================================
int main()
{
    int op=0;
    int op2=0;
    fila f = filaInicializar();

    while(op!=6)
    {
        printf("1)Inserir\n2)Remover\n3)Imprimir\n4)Cheia\n5)Vazia\n6)Sair\n");
        scanf("%d", &op);
        switch(op)
        {
            //======================================================
            case 1:

                printf("1) Tipo Inteiro\n2)Tipo Char\n3) Tipo Float\n");
                scanf("%d", &op2);

                switch(op2)
                {
                    //======================================================
                    case 1:
                        f = filaInserir(f, criarInteiro(), op2);
                    break;

                    //======================================================
                    case 2:
                        f = filaInserir(f, criarChar(), op2);
                    break;
                    //======================================================
                    case 3:
                        f = filaInserir(f, criarFloat(), op2);
                    break;

                }
            break;

            //======================================================
            case 2:
                f = filaRemover(f);
            break;

            //======================================================
            case 3:
                filaImprimir(f);
            break;

            //======================================================
            case 4:
                if(filaCheia(f))
                    printf("Fila esta cheia\n");
                else
                    printf("Fila nao esta cheia\n");
            break;

            //======================================================
            case 5:
                if(filaVazia(f))
                    printf("Fila esta vazia\n");
                else
                    printf("Fila nao esta vazia\n");
            break;

            //======================================================
            case 6:
                f = filaDestruir(f);
            break;

        }
        __fpurge(stdin);
        getchar();
    }
    return 0;
}
