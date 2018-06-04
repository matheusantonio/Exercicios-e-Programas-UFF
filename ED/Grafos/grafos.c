//=============================================================
// 1) Inserir uma aresta (perguntar quantos nos tem no grafo)
// So deve ser inserido de nao existir.
// 2) remover uma aresta
// 3) Imprimir o grafo (Ex: 1: 2|2.5, 3|3, ...)
// 4) Calcular grau de um vertice (especificar os 3)
// 5) verificafr se o grafo eh espa�o
// 6) Imprimir todos os caminhos entre uma origem e um destino
// que passam por um no intermediario
// 7) Imprimir o custo e o caminho de menor custo entre uma 
// origem e um destino
// 8) Imprimir todos os ciclos hamiltonianos que existem no 
// grafo, partindo do no x (Dizemos que existe um ciclo
// hamiltoniano a partir de x se existe um caminho com origem
// e destino em x que passa por todos os nos)
// 9) Sair e destruir
//=============================================================
#include<stdio.h>
#include<stdio_ext.h>
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

int grauSaida(Grafo *g)
{
    int cont=0;
    while(g!=NULL)
    {
        cont++;
        g = g->prox;
    }
    return cont;
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

int grauEntrada(Grafo **g, int origem, int n)
{
    int cont=0, i;
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


int existirVetor(int *vet, int pos, int destino)
{
    int i;
    for(i=0;i<pos;i++)
    {
        if(vet[i] == destino)
            return 1;
    }
    return 0;
}


void imprimirCaminhos(int *vet, Grafo **g, int destino, int pos, int node)
{
    if(vet[pos-1] == destino)
    {
        int i;
        if(existirVetor(vet, pos, node))
        {
            for(i=0;i<pos;i++)
            {
                printf("%d", vet[i]);
            }
            printf("\n");
        }
    }
    else
    {
        Grafo *l = g[vet[pos-1]];
        while(l!=NULL)
        {
            if(existirVetor(vet, pos, l->destino)==0)
            {
                vet[pos] = l->destino;
                imprimirCaminhos(vet, g, destino, pos+1, node);
            }
            l = l->prox;
        }
    }

}

float somaCusto(int *vet, Grafo **g, int pos)
{
    int i;
    float soma=0;
    for(i=1;i<pos;i++)
    {
        Grafo *l = g[vet[i-1]];
        while(l->destino!=vet[i])
            l=l->prox;
        soma+=l->custo;
    }
    return soma;
}

float menorCusto(int *vet, Grafo **g, int pos, int destino, float sumAtual, float sumMenor)
{
    int *v;
    float somateste;
    if(vet[pos-1]==destino)
    {
        int somaAtual = somaCusto(v, g, pos);
        if(sumAtual < sumMenor)
        {
            return sumAtual;
        }
    }
    else
    {
        Grafo *l = g[vet[pos-1]];
        float soma=0;
        while(l!=NULL)
        {
            if(!existirVetor(v, pos, l->destino))
            {
                vet[pos] = l->destino;
                soma+=l->custo;
                somateste = menorCusto(vet, g, pos+1, destino, soma, sumMenor);
            }
            l = l->prox;
        }
    }
    printf("Soma teste = %f\n", somateste);
}

void imprimirHamiltonianos(int *vet, Grafo **g, int pos, int n)
{

    if(vet[pos-1] == vet[0] && pos!=1)
    {
        if(pos-1 == n)
        {
           int i; 
            for(i=0;i<pos;i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");
        }
    }
    else
    {
        Grafo *l = g[vet[pos-1]];
        while(l!=NULL)
        {
            if(!existirVetor(vet, pos, l->destino) || l->destino == vet[0])
            {
                vet[pos] = l->destino;
                imprimirHamiltonianos(vet, g, pos+1, n);
            }
            l = l->prox;
        }
    }

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
    int n, op=0, origem, destino, *v, node;
    float custo;
    printf("Quantos nos tem o grafo?\n");
    scanf("%d", &n);

    Grafo **g = iniGrafo(n);
    v=malloc((n+1)*sizeof(int));

    g[1] = inserir(g[1], 1, 3, 2.5);
    g[1] = inserir(g[1], 1, 2, 3.5);
    g[2] = inserir(g[2], 2, 5, 1.5);
    g[2] = inserir(g[2], 2, 3, 1.5);
    g[3] = inserir(g[3], 3, 4, 1);
    g[3] = inserir(g[3], 3, 1, 6);
    g[4] = inserir(g[4], 4, 3, 1.75);
    g[4] = inserir(g[4], 4, 5, 1.7);
    g[5] = inserir(g[5], 5, 1, 2.5);
    g[5] = inserir(g[5], 5, 2, 1.4);
    g[5] = inserir(g[5], 5, 4, 2.25);

    while(op!=9)
    {
        system("clear");
        printf("1)Inserir aresta\n2)Remover aresta\n3)Imprimir grafo\n4)Grau de um no\n5)Verifica se grafo eh espaco\n");
        printf("6)Imprimir todos os caminhos entre origem e destino que passam por um no intermediario.\n");
        printf("7)Imprimir o caminho de menor custo.\n8)Imprimir todos os ciclos hamiltonianos.\n9)Sair\n");
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
            printf("Indique a origem: ");
            scanf("%d", &origem);
            printf("Grau de entrada: %d\nGrau de saida: %d\n Grau do vertice: %d\n", grauEntrada(g, origem, n), grauSaida(g[origem]), grauEntrada(g, origem, n) + grauSaida(g[origem]));
            break;
        case 5:
            if(espaco(g, n))
                printf("Grafo eh espaco.\n");
            else
                printf("Grafo nao eh espaco.\n");
            break;
        case 6:
            printf("Insira origem: ");
            scanf("%d", &origem);
            printf("Insira destino: ");
            scanf("%d", &destino);
            printf("Indique o no pelo qual o caminho deve passar: ");
            scanf("%d", &node);
            v[0] = origem;
            imprimirCaminhos(v, g, destino, 1, node);
            break;
        case 7:
            printf("Insira origem: ");
            scanf("%d", &origem);
            printf("Insira destino: ");
            scanf("%d", &destino);
            v[0] = origem;
            somaCusto(v, g, 1);
            break;
        case 8:
            printf("Insira origem: ");
            scanf("%d", &origem);
            v[0] = origem;
            imprimirHamiltonianos(v, g, 1, n);
            break;
        case 9:
            g = destruir(g, n);
            break;
        }
         __fpurge(stdin);
         getchar();
    }
    return 0;
}
