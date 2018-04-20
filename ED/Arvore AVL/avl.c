/*
Repetir o trabalho de arvore binaria de busca para arvore avl fazendo as seguintes modificacoes:
1) ao ler a arvore do arquivo, verificar se a arvore esta ordenada e tambem balanceada
2) ao inserir ou remover um elemento, verificar se a arvore desbalanceou. Se a arvore desbalanceou, <-
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

//===============================================================
//Checar se arvore esta balanceada
//===============================================================
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

arvore *removerElemento(arvore*a, int elem);

arvore *inserirElemento(arvore *a, int elem);

//===============================================================
//Balancear arvore
//===============================================================
arvore *balancearArvore(arvore *a)
{
    if(a!=NULL)
    {
        int he, hd;
        a->esq = balancearArvore(a->esq);
        a->dir = balancearArvore(a->dir);

        he = calcularAltura(a->esq);
        hd = calcularAltura(a->dir);

        if(he - hd > 1)
        {
            int x;
            arvore *aux = a->esq;
            while(aux->dir!=NULL) aux = aux->dir;
            x = a->info;
            a->info=aux->info;
            a->esq = removerElemento(a->esq, aux->info);
            a->dir = inserirElemento(a->dir, x);
            a = balancearArvore(a);
        }
        else if(hd - he > 1)
        {
            int x;
            arvore *aux = a->dir;
            while(aux->esq!=NULL) aux=aux->esq;
            x = a->info;
            a->info = aux->info;
            a->dir = removerElemento(a->dir, aux->info);
            a->esq = inserirElemento(a->esq, x);
            a = balancearArvore(a);
        }
        //a->esq=balancearArvore(a->esq);
        //a->dir=balancearArvore(a->dir);
    }
    return a;
}

//===============================================================
//Checar se a arvore esta ordenada
//===============================================================
int encontrarMaior(arvore *a, int elem);

int encontrarMenor(arvore *a, int elem);

int ordenada(arvore *a)
{
    if(a!=NULL)
    {
        if(!encontrarMaior(a->esq, a->info) || !encontrarMenor(a->dir, a->info))
            return 0;
        else
            return ordenada(a->esq) * ordenada(a->dir);
    }
    return 1;
}

int encontrarMaior(arvore *a, int elem)
{
    if(a!=NULL)
    {
        if(a->info>elem)
            return 0;
        else
            return encontrarMaior(a->esq, elem) * encontrarMaior(a->dir, elem);
    }
    return 1;
}

int encontrarMenor(arvore *a, int elem)
{
    if(a!=NULL)
    {
        if(a->info<elem)
            return 0;
        else
            return encontrarMenor(a->esq, elem) * encontrarMenor(a->dir, elem);
    }
    return 1;
}

//===============================================================
// (1) Ler arvore
//===============================================================
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

//===============================================================
// (2) Inserir elemento na arvore
//===============================================================
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

//===============================================================
// (3) Remover elemento da arvore
//===============================================================
arvore *removerElemento(arvore *a, int elem)
{
    if(a!=NULL)
    {
        if(a->info == elem)
        {
            //caso 1: eh folha
            if(a->dir==NULL && a->esq==NULL)
            {
                free(a);
                return NULL;
            }
            //caso apenas um dos lados seja nulo
            else if(a->dir==NULL || a->esq==NULL)
            {
                arvore *aux;
                if(a->esq==NULL)
                    aux=a->dir;
                else if(a->dir==NULL)
                    aux=a->esq;
                free(a);
                return aux;
            }
            else
            {
                arvore *aux = a->dir;
                while(aux->dir != NULL) aux = aux->dir;
                a->info = aux->info;
                a->dir = removerElemento(aux, aux->info);
                return a;
            }
        }
        else
        {
            if(elem > a->info)
                a->dir = removerElemento(a->dir, elem);
            else
                a->esq = removerElemento(a->esq, elem);
        }

    }
    return a;
}

//===============================================================
// (4a)Imprimir em ordem
//===============================================================
void imprimirEmOrdem(arvore *a)
{
    if(a!=NULL)
    {
        imprimirEmOrdem(a->esq);
        printf("%d |", a->info);
        imprimirEmOrdem(a->dir);
    }
}

//===============================================================
// (4a)Imprimir em ordem
//===============================================================
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

//===============================================================
//(5) Calcular altura da arvore
//===============================================================
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

//===============================================================
// (6) Imprimir os elementos entre X e Y
//===============================================================
void imprimirEntre(arvore *a, int X, int Y)
{
    if(a!=NULL)
    {
        if(a->info>X)
            imprimirEntre(a->esq, X, Y);

        if(a->info>X && a->info<Y)
            printf("%d |", a->info);

        if(a->info<Y)
            imprimirEntre(a->dir, X, Y);
    }
}

//===============================================================
// (7) Imprimir os elementos ou menores que X ou maiores que Y
//===============================================================
void imprimirMenoresMaiores(arvore *a, int X, int Y)
{
    if(a!=NULL)
    {
        imprimirMenoresMaiores(a->esq, X, Y);
        if(a->info<X || a->info>Y)
            printf("%d |", a->info);
        imprimirMenoresMaiores(a->dir, X, Y);
    }
}

//===============================================================
//(8) Destruir a arvore
//===============================================================
arvore * destruirArvore(arvore *a)
{
    if(a!=NULL)
    {
        a->esq = destruirArvore(a->esq);
        a->dir = destruirArvore(a->dir);
        free(a);
    }
    return NULL;
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
    int op=0, elem, X, Y;
    FILE *arq;
    char fileName[50], op2;

    while(op!=8)
    {
        op = menu();
        switch(op)
        {
        case 1:
            printf("Entre com o nome do arquivo:");
            scanf("%s", fileName);
            arq = fopen(fileName, "r");
            a = lerArvore(a, arq);
            fclose(arq);
            if(balanceada(a))
                printf("Arvore esta balanceada\n");
            else
            {
                printf("Arvore nao esta balanceada\n");
                a = destruirArvore(a);
                return 0;
            }
            if(ordenada(a))
                printf("A arvore esta ordenada\n");
            else
            {
                printf("A arvore nao esta ordenada.\n");
                a = destruirArvore(a);
                return 0;
            }
            break;
        case 2:
            printf("Entre com o elemento a ser inserido:");
            scanf("%d", &elem);
            a = inserirElemento(a, elem);
            if(!balanceada(a))
            {
                printf("A arvore foi desbalanceada!\nBalanceando...\n");
                a = balancearArvore(a);
            }
            break;
        case 3:
            printf("Entre com o elemento a ser removido:");
            scanf("%d", &elem);
            a = removerElemento(a, elem);
            if(!balanceada(a))
            {
                printf("A arvore foi desbalanceada!\nBalanceando...\n");
                a = balancearArvore(a);
            }
            break;
        case 4:
            printf("a) Imprimir em ordem b)Imprimir em notacao de parenteses\n");
            fflush(stdin);
            scanf("%c", &op2);
            switch(op2)
            {
                case 'a':
                    imprimirEmOrdem(a);
                    break;
                case 'b':
                    imprimirNotacao(a);
                    break;
            }
            break;
        case 5:
            printf("A arvore tem altura %d\n", calcularAltura(a));
            break;
        case 6:
            printf("Insira X:");
            scanf("%d", &X);
            printf("Insira Y:");
            scanf("%d", &Y);
            imprimirEntre(a, X, Y);
            break;
        case 7:
            printf("Insira X:");
            scanf("%d", &X);
            printf("Insira Y:");
            scanf("%d", &Y);
            imprimirMenoresMaiores(a, X, Y);
            break;
        case 8:
            a = destruirArvore(a);
            return 0;
        }
    }
    return 0;
}
