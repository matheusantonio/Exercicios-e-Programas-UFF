//=============================================================
// 1) Inserir uma aresta (perguntar quantos nos tem no grafo)
// So deve ser inserido de nao existir.
// 2) remover uma aresta
// 3) Imprimir o grafo (Ex: 1: 2|2.5, 3|3, ...)
// 4) Calcular grau de um vertice (especificar os 3)
// 5) verificafr se o grafo eh espa�o
// 6) Sair e destruir
//=============================================================
#include<stdio.h>
#include<stdlib.h>

typedef struct Grafo
{
    int destino;
    float custo;
    struct Grafo *prox;
} Grafo;

Grafo ** iniGrafo(int n)
{
    Grafo **g=(Grafo**)malloc((n+1)*sizeof(Grafo*));
    int i;
    for(i=0;i<=n;i++)
    {
        g[i] = NULL;
    }
    return g;
}

Grafo* inserir(Grafo *g, int origem, int destino, float custo)
{
    Grafo *novo = (Grafo*)malloc(sizeof(Grafo));
    novo->destino=destino;
    novo->custo=custo;
    if(g == NULL)
    {
        g = novo;
        g->prox=NULL;
    }
    else
    {
        novo->prox = g;
        g = novo;
    }
    return g;
}

Grafo* remover(Grafo *g, int destino)
{
    Grafo *busca = g, *aux=NULL;
    if(g->prox == NULL)
    {
        free(g);
        g = NULL;
        return g;
    }
    while(busca->destino != destino)
    {
        aux = busca;
        busca = busca->prox;
    }
    if(aux==NULL)
    {
        aux = busca->prox;
        free(busca);
        return aux;
    }
    else
    {
        aux->prox = busca->prox;
        free(busca);
        return g;
    }
}

void imprimir(Grafo **g, int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("%d-> ", i);
        Grafo *aux = g[i];
        while(aux!=NULL)
        {
            printf("(%d:%.2f), ", aux->destino, aux->custo);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int procurar(Grafo *g, int destino)
{
    while(g!=NULL)
    {
        if(g->destino == destino)
            return 1;
        g = g->prox;
    }
    return 0;
}

int contGrafo(Grafo *g, int origem)
{
    int cont=0;
    while(g!=NULL)
    {
        if(g->destino == origem)
            cont++;
        g = g->prox;
    }
    return cont;
}

int contGrafo2(Grafo *g)
{
    int cont=0;
    while(g!=NULL)
    {
        cont++;
        g = g->prox;
    }
    return cont;
}

int grauVertice(Grafo **g, int origem, int n)
{
    int cont=0;
    cont = contGrafo2(g[origem]);
    int i;
    for(i=0;i<=n;i++)
    {
        if(i!=origem)
        {
            cont = cont + contGrafo(g[i], origem);
        }
    }
    return cont;
}

int espaco(Grafo **g, int n)
{
    Grafo *aux;
    int cont = 0, i;
    for(i=1;i<=n;i++)
    {
        aux = g[i];
        while(aux!=NULL)
        {
            cont++;
            aux=aux->prox;
        }
    }
    int tot = n*(n-1);
    if((cont*100/tot) > 30)
        return 0;
    else
        return 1;
}

Grafo* destruirAresta(Grafo *g)
{
    if(g!=NULL)
    {
        destruirAresta(g->prox);
        free(g);
        return NULL;
    }
    return NULL;
}

Grafo ** destruir(Grafo **g, int n)
{
    int i;
    for(i=1;i<=n;i++)
        g[i]=destruirAresta(g[i]);
    free(g);
    g = NULL;
    return g;
}

int main()
{
    int n, op=0, origem, destino;
    float custo;
    printf("Quantos nos tem o grafo?\n");
    scanf("%d", &n);

    Grafo **g = iniGrafo(n);

    g[1] = inserir(g[1], 1, 3, 2.5);
    g[1] = inserir(g[1], 1, 2, 3.5);
    g[2] = inserir(g[2], 2, 5, 1.5);
    g[3] = inserir(g[3], 3, 4, 1);
    g[3] = inserir(g[3], 3, 1, 6);
    g[4] = inserir(g[4], 4, 3, 1.75);
    g[5] = inserir(g[5], 5, 1, 2.5);
    g[5] = inserir(g[5], 5, 2, 1.4);
    g[5] = inserir(g[5], 5, 4, 2.25);

    while(op!=6)
    {
        system("cls");
        printf("1)Inserir aresta\n2)Remover aresta\n3)Imprimir grafo\n4)Grau de um no\n5)Verifica se grafo eh espaco\n6)Sair\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Insira origem: ");
            scanf("%d", &origem);
            printf("Insira destino: ");
            scanf("%d", &destino);
            if(procurar(g[origem], destino))
            {
                printf("Aresta ja existe!");
                break;
            }
            printf("Insira o custo: ");
            scanf("%f", &custo);
            g[origem] = inserir(g[origem], origem, destino, custo);
            break;
        case 2:
            printf("Insira origem: ");
            scanf("%d", &origem);
            printf("Insira destino: ");
            scanf("%d", &destino);
            if(!procurar(g[origem], destino))
            {
                printf("Aresta nao existe!");
                break;
            }
            g[origem] = remover(g[origem], destino);
            break;
        case 3:
            imprimir(g, n);
            break;
        case 4:
            printf("Indique a oridem: ");
            scanf("%d", &origem);
            printf("Esse vertice tem grau %d.",grauVertice(g, origem, n));
            break;
        case 5:
            if(espaco(g, n))
                printf("Grafo eh espaco.\n");
            else
                printf("Grafo nao eh espaco.\n");
            break;
        case 6:
            g = destruir(g, n);
            break;
        }
        fflush(stdin);
        getchar();
    }
    return 0;
}
