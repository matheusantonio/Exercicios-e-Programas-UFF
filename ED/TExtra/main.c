//=====================================================
// Construir um TAD fila generico.
// Inicializar, destruir, verificar se esta cheio,
// verificar se esta vazio, inserir, remover
//=====================================================

#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include "generica.h"
#include "estruturas.h"

int verificarOpcao()
{
    system("clear");
    int op=0;
    printf("1)Inserir\n2)Remover\n3)Imprimir\n4)Cheia\n5)Vazia\n6)Sair\n");
    scanf("%d", &op);
    return op;
}

int verificarTipo()
{
    int op=0;
    printf("1) Tipo Inteiro\n2)Tipo Char\n3) Tipo Float\n");
    scanf("%d", &op);
    return op;
}

//======================================================
int main()
{
    int op=0, op2=0;
    generica ints = filaInicializar(), nms = filaInicializar(), flt = filaInicializar();

    while(op!=6)
    {
        op = verificarOpcao();
        switch(op)
        {
            //======================================================
            case 1:

                op2 = verificarTipo();

                switch(op2)
                {
                    //======================================================
                    case 1:
                        printf("Insira um valor inteiro: ");
                        int vlrI;
                        scanf("%d", &vlrI);
                        ints = filaInserir(ints, criarInteiro(vlrI));
                    break;

                    //======================================================
                    case 2:
                        printf("Insira um valor char: ");
                        char *vlrC = (char*)malloc(sizeof(char));
                        scanf(" %s", vlrC);
                        nms = filaInserir(nms, criarChar(vlrC));
                    break;

                    //======================================================
                    case 3:
                        printf("Insira um valor float: ");
                        float vlrF;
                        scanf("%f", &vlrF);
                        flt = filaInserir(flt, criarFloat(vlrF));
                    break;
                }
            break;

            //======================================================
            case 2:
                op2 = verificarTipo();
                switch(op2)
                {
                    //======================================================
                    case 1:
                        ints = filaRemover(ints);
                    break;

                    //======================================================
                    case 2:
                        nms = filaRemover(nms);
                    break;

                    //======================================================
                    case 3:
                        flt = filaRemover(flt);
                    break;
                }
            break;

            //======================================================
            case 3:
                op2 = verificarTipo();
                switch(op2)
                {
                    //======================================================
                    case 1:
                        filaImprimir(ints, imprimirInteiro);
                    break;

                    //======================================================
                    case 2:
                        filaImprimir(nms, imprimirChar);
                    break;

                    //======================================================
                    case 3:
                        filaImprimir(flt, imprimirFloat);
                    break;
                }
            break;

            //======================================================
            case 4:

                //======================================================
                if(filaCheia(ints))
                    printf("Fila de inteiros esta cheia\n");
                else
                    printf("Fila de inteiros nao esta cheia\n");

                //======================================================
                if(filaCheia(nms))
                    printf("Fila de nomes esta cheia\n");
                else
                    printf("Fila de nomes nao esta cheia\n");

                //======================================================
                if(filaCheia(flt))
                    printf("Fila de floats esta cheia\n");
                else
                    printf("Fila de floats nao esta cheia\n");
            break;

            //======================================================
            case 5:
                //======================================================
                if(filaVazia(ints))
                    printf("Fila de inteiros esta vazia\n");
                else
                    printf("Fila de inteiros nao esta vazia\n");

                //======================================================
                if(filaVazia(nms))
                    printf("Fila de nomes esta vazia\n");
                else
                    printf("Fila de nomes nao esta vazia\n");

                //======================================================
                if(filaVazia(flt))
                    printf("Fila de floats esta vazia\n");
                else
                    printf("Fila de floats nao esta vazia\n");
            break;

            //======================================================
            case 6:
                ints = filaDestruir(ints);
                nms = filaDestruir(nms);
                flt = filaDestruir(flt);
            break;

        }
        __fpurge(stdin);
        getchar();
    }
    return 0;
}
