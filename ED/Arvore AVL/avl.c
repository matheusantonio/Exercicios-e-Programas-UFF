/*
Repetir o trabalho de arvore binaria de busca para arvore avl fazendo as seguintes modificacoes:
1) ao ler a arvore do arquivo, verificar se a arvore esta ordenada e tambem balanceada
2) ao inserir ou remover um elemento, verificar se a arvore desbalanceou. Se a arvore desbalanceou,
uma mensagem de arvore desbalanceada deve ser escrita na tela e o algoritmo de balanceamento
deve ser executado.

1- Ler arvore de um arquivo e verificar se esta ordenada
2- Inserir um elemento na arvore
3- Remover um elemento da arvore
4- Imprimir arvore (em ordem ou em notacao de parenteses)
5- Calcular altura da arvore
6- Imprimir os elementos entre x e y
7- Imprimir elementos ou menores que x ou maiores que y
8- sair e destruir a arvore
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    int info;
    struct arvore *esq;
    struct arvore *dir;
} arvore;

int calcularAltura(arvore *a);

//======================================
//Checar se arvore esta balanceada
//======================================
int balanceada(arvore *a)
{
    if(a!=NULL)
    {
        int he, hd;
        he = calcularAltura(a->esq);
        hd = calcularAltura(a->dir);
        if(he-hd > 1)
            return 0;
        else if(hd-he > 1)
            return 0;
        else
            return 1*balanceada(a->esq) * balanceada(a->dir);
    }
    return 1;
}



//======================================
//Ler arvore
//======================================
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
        a=NULL;
    }
    fscanf(arq, "%c", &symb);
    return a;
}

//======================================
//Inserir elemento na arvore
//======================================
arvore * inserirElemento(arvore *a, int elem)
{
    if(a!=NULL)
    {
        if(elem>a->info)
            a->dir = inserirElemento(a->dir, elem);
        else
            a->esq =inserirElemento(a->esq, elem);
    }
    else
    {
        a = (arvore*)malloc(sizeof(arvore));
        a->info = elem;
        a->dir=NULL;
        a->esq=NULL;
    }
    return a;
}

//======================================
//Imprimir em ordem
//======================================
void imprimirEmOrdem(arvore *a)
{
    if(a!=NULL)
    {
        imprimirEmOrdem(a->esq);
        printf("%d |", a->info);
        imprimirEmOrdem(a->dir);
    }
}

//======================================
//Calcular altura da arvore
//======================================
int calcularAltura(arvore *a)
{
    if(a!= NULL)
    {
        int he, hd;
        he = calcularAltura(a->esq);
        hd = calcularAltura(a->dir);
        if(he > hd)
            return 1 + he;
        else
            return 1 + hd;
    }
    return 0;
}

int menu(){
    fflush(stdin);
    getchar();
	system("cls");
	int op;
	printf("\n1-Receber arvore de arquivo");
	printf("\n2-Adicionar elemento a arvore");
	printf("\n3-Remover elemento da arvore");
	printf("\n4-Imprimir arvore");
	printf("\n5-Calcular altura da arvore");
	printf("\n6-Imprimir os elementos entre x e y");
	printf("\n7-Imprimir os elementos ou menores que x ou maiores que y");
	printf("\n8-Sair e destruir arvore\n");
	scanf("%d", &op);
	return op;
}

int main()
{
    arvore *a = NULL;
    int op=0, elem;
    FILE *arq;
    char fileName[50];

    while(op!=8)
    {
        op = menu();
        switch(op)
        {
        case 1:
            scanf("%s", fileName);
            arq = fopen(fileName, "r");
            a = lerArvore(a, arq);
            fclose(arq);
            if(balanceada(a))
                printf("Arvore esta balanceada\n");
            else
                printf("Arvore nao esta balanceada\n");
            break;
        case 2:
            scanf("%d", &elem);
            a = inserirElemento(a, elem);
            break;
        case 4:
            imprimirEmOrdem(a);
            break;
        case 5:
            printf("A arvore tem altura %d\n", calcularAltura(a));
            break;
        }
    }
    return 0;

}
