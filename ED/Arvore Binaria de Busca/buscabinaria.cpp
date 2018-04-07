/*
1- Ler arvore de um arquivo e verificar se esta ordenada
2- Inserir um elemento na arvore
3- Remover um elemento da arvore
4- Imprimir arvore (em ordem ou em notacao de parenteses)
5- Calcular altura da arvore
6- Imprimir os elementos entre x e y
7- Imprimir elementos ou menores que x ou maiores que y
8- sair e destruir a arvore
*/
#include<stdio.h>
#include<stdlib.h>


//======================================
typedef struct arvore
{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} arvore;


//======================================
//1
arvore * lerArvore(arvore *a, FILE *arq)
{
    int num;
    char symb;
    fscanf(arq, "%c", &symb);
    fscanf(arq, "%d", &num);
    if(num != -1)
    {
        a = (arvore*)malloc(sizeof(arvore));
        a->info = num;
        a->esq = lerArvore(a->esq, arq);
        a->dir = lerArvore(a->dir, arq);
    }
    else{
        a = NULL;
    }
    fscanf(arq, "%c", &symb);
    return a;
}

//======================================
//2
arvore * inserirElemento(arvore*a, int elem)
{
    if(a!=NULL)
    {
        if(a->info>elem)
            a->esq = inserirElemento(a->esq, elem);
        else
            a->dir = inserirElemento(a->dir, elem);
    }
    else
    {
        a = (arvore*)malloc(sizeof(arvore));
        a->info=elem;
        a->esq=NULL;
        a->dir=NULL;
    }
    return a;
}

//======================================
//4
void imprimirArvore(arvore*a)
{
    if(a!=NULL)
    {
        imprimirArvore(a->esq);
        printf("%d |", a->info);
        imprimirArvore(a->dir);
    }
}


int main()
{
    arvore *a = NULL;
    int op, elem;
    char nomeArquivo[40];
    FILE *arq;

    while(op!=8)
    {
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Insira nome do arquivo a ser aberto.\n");
            scanf("%s", nomeArquivo);
            arq = fopen(nomeArquivo, "r");
            a = lerArvore(a, arq);
            fclose(arq);
            break;
        case 2:
            printf("Insira o elemento a ser adicionado.");
            scanf("%d", &elem);
            a = inserirElemento(a, elem);
            break;
        case 4:
            imprimirArvore(a);
            break;
        }
    }



    return 0;
}

