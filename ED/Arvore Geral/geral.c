//=======================================================
// 1) Ler uma arvore de um arquivo
// 2) Imprimir (notacao parentese e em largura)
// 3) Altura da arvore
// 4) Contar o numero de folhas
// 5) Imprimir os nos internos
// 6) Imprimir o nivel de um no
// 7) Inserir um no X como filho de um no y -
// - primeiro verificar a existencia de y, se sim, inserir
// 8) Sair
//=========================================================
#include<stdio.h>
#include<stdlib.h>

typedef struct arvore
{
    int info;
    struct arvore *filho;
    struct arvore *irmao;
} arvore;

//====================================================
// 1) ler arvore
//====================================================
arvore *lerArvore(arvore *a, FILE* arq)
{
    int num;
    char symb;
    fscanf(arq, "%c", &symb);
    fscanf(arq, "%d", &num);
    if(num!=-1)
    {
        a=malloc(sizeof(arvore));
        a->info=num;
        a->filho=lerArvore(a->filho, arq);
        a->irmao=lerArvore(a->irmao, arq);
    }
    else
        a=NULL;
    fscanf(arq, "%c", &symb);
    return a;
}

//====================================================
// 2a) Imprimir em notacao de parenteses
//====================================================
void imprimirNotacao(arvore *a)
{
    if(a!=NULL)
    {
        printf("(%d", a->info);
        imprimirNotacao(a->filho);
        imprimirNotacao(a->irmao);
    }
    else
        printf("(-1");
    printf(")");
}

//====================================================
// 2b) Imprimir em niveis (verificar se esta certinha
//====================================================
void imprimirNiveis(arvore *a, int nivel, int atual)
{
    if(a!=NULL)
    {
        if(atual==nivel)
        {
            printf("%d |", a->info);
            imprimirNiveis(a->irmao, nivel, atual);
        }
        else
        {
            imprimirNiveis(a->filho, nivel, atual+1);
            imprimirNiveis(a->irmao, nivel, atual);
        }
        if(atual==0){
            if(altura(a)!=nivel)
            {
                printf("\n");
                imprimirNiveis(a, nivel+1, atual);
            }
        }
    }
}

//===================================================
// 3) Calcular altura da arvore
//===================================================
int altura(arvore *a)
{
    if(a!=NULL)
    {
        int hi, hf;
        hi = altura(a->irmao);
        hf = 1 + altura(a->filho);
        if(hf > hi)
            return hf;
        else
            return hi;
    }
    return 0;
}

//==========================================
// 4) Numero de folhas
//==========================================
int numFolhas(arvore *a)
{
    if(a!=NULL)
    {
        if(a->filho==NULL)
            return 1 + numFolhas(a->irmao);
        else
            return numFolhas(a->filho) + numFolhas(a->irmao);
    }
    return 0;
}

//==========================================
// 5) Imprimir os nos internos
//==========================================
void imprimirNosInternos(arvore *a)
{
    if(a!= NULL)
    {
        if(!(a->filho==NULL))
        {
            printf("%d |", a->info);
        }
        imprimirNosInternos(a->filho);
        imprimirNosInternos(a->irmao);
    }
}

//==========================================
// 6) Imprimir Nivel de um no
//==========================================
int nivelNo(arvore *a, int elem, int nivel)
{
    if(a!=NULL)
    {
        if(a->info==elem)
            return nivel;
        else
        {
            int nf, ni;
            ni = nivelNo(a->irmao, elem, nivel);
            if(ni != 0)
                return ni;
            nf = nivelNo(a->filho, elem, nivel+1);
            if(nf != 0)
                return nf;
        }
    }
    return 0;
}

//======================================================
// 7) Inserir X como filho de Y
//======================================================
int procurarNo(arvore *a, int busca)
{
    if(a!=NULL)
    {
        if(a->info==busca)
            return 0;
        else
            return procurarNo(a->filho, busca)*procurarNo(a->irmao, busca);
    }
    return 1;
}

arvore * adicionarNoEmY(arvore *a, int X, int Y)
{
    if(a!=NULL)
    {
        if(a->info==Y)
        {
            arvore *aux=(arvore*)malloc(sizeof(arvore));
            aux->info=X;
            aux->irmao=a->filho;
            aux->filho=NULL;
            a->filho=aux;
        }
        else
        {
            a->filho=adicionarNoEmY(a->filho, X, Y);
            a->irmao=adicionarNoEmY(a->irmao, X, Y);
        }
    }
    return a;
}

//===================================
// Destruir arvore
//===================================
arvore *destruirArvore(arvore *a)
{
    if(a!=NULL)
    {
        a->irmao=destruirArvore(a->irmao);
        a->filho=destruirArvore(a->filho);
        free(a);
    }
    return NULL;
}


int menu()
{
    int op;
    system("cls");
    printf("1)Ler arvore de um arquivo.\n");
    printf("2a)Imprimir em notacao de parenteses.\n");
    printf("2b)Imprimir por niveis.\n");
    printf("3)Calcular altura da arvore.\n");
    printf("4)Contar o numero de folhas.\n");
    printf("5)Imprimir nos internos.\n");
    printf("6)Imprimir o nivel de um no.\n");
    printf("7)Inserir um no X como filho de Y.\n");
    printf("8)Sair.\n");
    scanf("%d", &op);
    return op;
}


int main()
{
    FILE *arq;
    arvore *a=NULL;
    int op=0, busca, X;
    char arquivo[50], op2;
    while(op!=8)
    {
        op = menu();
        switch(op)
        {
        case 1:
            printf("Digite o nome do arquivo:");
            scanf("%s", arquivo);
            arq=fopen(arquivo, "r");
            a = lerArvore(a, arq);
            fclose(arq);
            break;
        case 2:
            printf("a) Em notacao b) Em niveis\n");
            fflush(stdin);
            scanf("%c", &op2);
            switch(op2)
            {
            case 'a':
                imprimirNotacao(a);
                break;
            case 'b':
                imprimirNiveis(a, 0, 0);
                break;
            }
            fflush(stdin);
            getchar();
            break;
        case 3:
            printf("A arvore tem altura %d\n", altura(a));
            fflush(stdin);
            getchar();
            break;
        case 4:
            printf("A arvore tem %d folhas.\n", numFolhas(a));
            fflush(stdin);
            getchar();
            break;
        case 5:
            imprimirNosInternos(a);
            fflush(stdin);
            getchar();
            break;
        case 6:
            printf("Qual elemento deseja buscar?\n");
            scanf("%d", &busca);
            printf("O elemento esta no nivel %d.\n", nivelNo(a, busca, 1));
            fflush(stdin);
            getchar();
            break;
        case 7:
            printf("Abaixo de qual elemento voce deseja inserir?\n");
            scanf("%d", &busca);
            if(procurarNo(a, busca))
            {
                printf("O elemento nao existe!\n");
                fflush(stdin);
                getchar();
                break;
            }
            else{
                printf("Digite o valor a ser adicionado:\n");
                scanf("%d", &X);
                a=adicionarNoEmY(a, X, busca);
                fflush(stdin);
                getchar();
                break;
            }
        case 8:
            a=destruirArvore(a);
            break;
        }
    }


}
