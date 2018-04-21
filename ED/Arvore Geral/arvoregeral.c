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

typedef struct arvore {
    int info;
    struct arvore *irmao;
    struct arvore *filho;
} arvore;

//============================================
// 1)Ler arvore de um arquivo
//============================================
arvore * lerArvore(arvore*a, FILE*arq)
{
    int num;
    char symb;
    fscanf(arq, "%c", &symb);
    fscanf(arq, "%d", &num);
    if(num!=-1)
    {
        a = (arvore*)malloc(sizeof(arvore));
        a->info=num;
        printf("%d |", a->info);
        getchar();
        a->filho=lerArvore(a->filho, arq);
        a->irmao=lerArvore(a->irmao, arq);
    }
    else
        a = NULL;
    fscanf(arq, "%c", &symb);
    return a;
}


//============================================
// 2) Imprimir arvore (notacao de parenteses)
//============================================
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

//==========================================
// 3) Imprimir por nivel
//==========================================
void imprimirNivel(arvore *a, int nivel, int atual)
{
    if(a!=NULL)
    {
        if(nivel == atual)
        {
            printf("%d |", a->info);
            imprimirNivel(a->irmao, nivel, atual);
            imprimirNivel(a->filho, nivel, atual+1);
        }
        else
        {
            imprimirNivel(a->filho, nivel, atual +1);
        }
        imprimirNivel(a, nivel+1, atual);
    }
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
    int op=0;
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
            scanf("%c", &op2);
            switch(op2)
            {
            case 'a':
                imprimirNotacao(a);
                break;
            case 'b':
                imprimirNivel(a, 0, 0);
                break;
            }
            getchar();
            break;
        case 3:
            break;
        }
    }


}
