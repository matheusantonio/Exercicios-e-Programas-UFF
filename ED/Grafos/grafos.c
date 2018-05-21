//=============================================================
// 1) Inserir uma aresta (perguntar quantos nos tem no grafo)
// So deve ser inserido de nao existir.
// 2) remover uma aresta
// 3) Imprimir o grafo (Ex: 1: 2|2.5, 3|3, ...)
// 4) Calcular grau de um vertice (especificar os 3)
// 5) verificafr se o grafo eh espaço
// 6) Sair e destruir
//=============================================================
#include<stdio.h>
#include<stdlib.h>

typedef struct aresta
{
    int destino;
    float custo;
    struct aresta *prox;
} Aresta;

typedef struct grafo
{
    Aresta **a;
} Grafo;

Grafo *iniGrafo(int n)
{
    Grafo *g = malloc(sizeof(struct grafo));
    g->a = malloc(n * sizeof(struct aresta));
    int i;
    for(i=0;i<n;i++)
    {
        g->a[i] = NULL;
    }
    return g;
}

int buscarAresta(Grafo *g, int origem, int destino)
{
    Aresta *aux = g->a[origem];
    while(aux!=NULL)
    {
        if(aux->destino==destino)
            return 1;
        aux=aux->prox;
    }
    return 0;
}

void inserirAresta(Grafo *g, int origem, int destino, float custo)
{
    Aresta *a = malloc(sizeof(struct aresta));
    a->destino = destino;
    a->custo = custo;
    a->prox = NULL;
    printf("%d %d %f\n", origem, a->destino, a->custo);
    if(g->a[origem] == NULL)
    {
        g->a[origem] = a;
    }
    else
    {
        Aresta *aux = g->a[origem];
        while(aux->prox!=NULL) aux = aux->prox;
        aux->prox = a;
    }
}

void removerAresta(Grafo *g, int origem, int destino)
{
    Aresta *aux = g->a[origem], *del = NULL;
    while(aux!=NULL)
    {
        if(aux->destino==destino)
        {
            if(del==NULL)
                g->a[origem] = aux->prox;
            else
                del->prox = aux->prox;
            free(aux);
            return;
        }
        del = aux;
        aux = aux->prox;
    }
}

void imprimirGrafo(Grafo *g, int n)
{
    Aresta *aux;
    int i;
    for(i=1;i<n;i++)
    {
        aux = g->a[i];
        printf("%d: ", i);
        while(aux!=NULL)
        {
            printf("%d|%.2f, ", g->a[i]->destino, g->a[i]->custo);
            aux=aux->prox;
        }
        printf("\n");
    }
}

int main()
{
    int n, op=0, origem, destino;
    float custo;
    printf("Indique o numero de nos do grafo:\n");
    scanf("%d", &n);
    n++;
    Grafo *g = iniGrafo(n);

    while(op!=6)
    {
        system("cls");
        printf("1)Inserir aresta\n2)Remover aresta\n3)Imprimir grafo\n4)Calcular grau de um vertice\n5)Verificar se eh espaco\n6)Sair\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Insira origem:");
            scanf("%d", &origem);
            printf("Insira destino:");
            scanf("%d", &destino);
            if(buscarAresta(g, origem, destino))
            {
                printf("Essa aresta ja existe!\n");
                break;
            }
            printf("Insira custo:");
            scanf("%f", &custo);
            inserirAresta(g, origem, destino, custo);
            break;
        case 2:
            printf("Insira origem:");
            scanf("%d", &origem);
            printf("Insira destino:");
            scanf("%d", &destino);
            if(!buscarAresta(g, origem, destino))
            {
                printf("Essa aresta nao existe!\n");
                break;
            }
            removerAresta(g, origem, destino);
            break;
        case 3:
            imprimirGrafo(g, n);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
        fflush(stdin);
        getchar();
    }

    return 0;
}
