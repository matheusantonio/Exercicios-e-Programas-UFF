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

int IsSorted(arvore *a)
{
    if(a->esq != NULL && a->dir != NULL)
    {
        if(a->esq->info<a->info && a->dir->info>a->info)
            return 1*IsSorted(a->esq)*IsSorted(a->dir);
        else
            return 0;
    }
    if(a->esq != NULL)
    {
        if(a->esq->info<a->info)
            return 1*IsSorted(a->esq);
        else
            return 0;
    }
    if(a->dir != NULL)
    {
        if(a->dir->info>a->info)
            return 1*IsSorted(a->dir);
        else
            return 0;
    }
    return 1;

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
//3

//======================================
//4a
void imprimirArvore(arvore*a)
{
    if(a!=NULL)
    {
        imprimirArvore(a->esq);
        printf("%d |", a->info);
        imprimirArvore(a->dir);
    }
}

//======================================
//4b
void imprimirNotacao(arvore *a)
{
    if(a!=NULL)
    {
        printf("(%d", a->info);
        imprimirNotacao(a->esq);
        imprimirNotacao(a->dir);
    }
    else
        printf("(-1");
    printf(")");
}

//======================================
//5
int calcularAltura(arvore *a)
{
    int h1, h2;
    if(a!=NULL)
    {
        h1 = calcularAltura(a->esq);
        h2 = calcularAltura(a->dir);
        if(h1>h2)
            return 1 + h1;
        else
            return 1 + h2;
    }
    return 0;
}

//======================================
//6
void imprimirEntreXeY(arvore *a, int x, int y)
{
    if(a!=NULL)
    {
        if(a->info>x)
            imprimirEntreXeY(a->esq, x, y);
        if(a->info>=x && a->info<=y)
            printf("%d |", a->info);
        if(a->info<y)
            imprimirEntreXeY(a->dir, x, y);
    }
}

//======================================
//7
void imprimirOuMenores(arvore *a, int x, int y)
{
    if(a!=NULL)
    {

        if(a->info<=x)
            imprimirOuMenores(a->esq, x, y);

        if(a->info<x || a->info>y)
            printf("%d |", a->info);

        imprimirOuMenores(a->dir, x, y);
    }
}

//======================================
//8
arvore * destruirArvore(arvore *a)
{
    if(a!=NULL)
    {
        destruirArvore(a->esq);
        destruirArvore(a->dir);
        free(a);
    }
    return NULL;
}

//======================================
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

//======================================
int main()
{
    arvore *a = NULL;
    int op=0, elem, x, y;
    char nomeArquivo[40], op2;
    FILE *arq;

    while(op!=8)
    {
        op = menu();
        switch(op)
        {
        case 1:
            printf("Insira nome do arquivo a ser aberto.\n");
            scanf("%s", nomeArquivo);
            arq = fopen(nomeArquivo, "r");
            a = lerArvore(a, arq);
            fclose(arq);
            if(IsSorted(a))
                printf("A Arvore eh ordenada.\n");
            else
                printf("A arvore nao eh ordenada.\n");
            break;
        case 2:
            printf("Insira o elemento a ser adicionado.");
            scanf("%d", &elem);
            a = inserirElemento(a, elem);
            break;
        case 4:
            printf("a)Em ordem b)Em notacao de parenteses.\n");
            fflush(stdin);
            scanf("%c", &op2);
            switch(op2)
            {
            case 'a':
                imprimirArvore(a);
                break;
            case 'b':
                imprimirNotacao(a);
                break;
            }
            break;
        case 5:
            printf("A arvore tem altura %d.\n", calcularAltura(a));
            break;
        case 6:
            printf("Informe X:");
            scanf("%d", &x);
            printf("Informe Y:");
            scanf("%d", &y);
            imprimirEntreXeY(a, x, y);
            break;
        case 7:
            printf("Informe X:");
            scanf("%d", &x);
            printf("Informe Y:");
            scanf("%d", &y);
            imprimirOuMenores(a, x, y);
            break;
        case 8:
            a = destruirArvore(a);
            break;
        }
    }



    return 0;
}

