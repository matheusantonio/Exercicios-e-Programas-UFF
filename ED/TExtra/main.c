//=====================================================
// Construir um TAD fila generico.
// Inicializar, destruir, verificar se esta cheio,
// verificar se esta vazio, inserir, remover
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include "fila.h"

//======================================================
typedef struct _tipo1
{
    int info1;
} tipo1;

//======================================================
typedef struct _tipo2
{
    char info2[10];
} tipo2;

//======================================================
typedef struct _tipo3
{
    float tipo3;
} tipo3;

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

                printf("1) Tipo 1\n2)Tipo 2\n3) Tipo3\n");
                scanf("%d", &op2);

                switch(op2)
                {
                    //======================================================
                    case 1:
                        ;
                        tipo1 *t1 = (tipo1*)malloc(sizeof(tipo1));
                        printf("Insira um inteiro: ");
                        scanf("%d", &t1->info1);
                        f = filaInserir(f, t1, op2);
                    break;

                    //======================================================
                    case 2:
                        ;
                        tipo2 *t2 = (tipo2*)malloc(sizeof(tipo2));
                        printf("Insira uma string (max 10 caracteres): ");
                        scanf(" %s", t2->info2);
                        f = filaInserir(f, t2, op2);
                    break;
                    //======================================================
                    case 3:
                        ;
                        tipo3 *t3 = (tipo3*)malloc(sizeof(tipo3));
                        printf("Insira um float: ");
                        scanf("%f", &t3->tipo3);
                        f = filaInserir(f, t3, op2);
                    break;

                }
            break;

            //======================================================
            case 2:
                f = filaRemover(f);
            break;

            //======================================================
            case 3:
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
