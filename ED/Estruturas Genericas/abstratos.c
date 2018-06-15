#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio_ext.h>

typedef struct _carro{
    char *placa;
    char *renavam;
    char *modelo;
    float potencia;
} carro;

typedef struct _moto{
    char *placa;
    float km;
    char *cor;
} moto;

typedef struct _generica{
    int tipo;
    void *info;
    struct _generica *prox;
} generica;

//===============================================
generica *Inserir(generica *g, int tipo)
{
    generica*novo = (generica*)malloc(sizeof(struct _generica));

    if(tipo==1)
    {
        carro *c = (carro*)malloc(sizeof(struct _carro));
        c->placa = (char*)malloc(sizeof(char));
        c->renavam = (char*)malloc(sizeof(char));
        c->modelo = (char*)malloc(sizeof(char));
        printf("Insira a placa: ");
        scanf(" %s", c->placa);
        printf("Insira o renavam: ");
        scanf(" %s", c->renavam);
        printf("Insira o modelo: ");
        scanf(" %s", c->modelo);
        printf("Insira a potencia ");
        scanf(" %f", &c->potencia);
        novo->info = c;
    }
    else if(tipo==2)
    {
        moto *m = (moto*)malloc(sizeof(struct _moto));
        m->placa = (char*)malloc(sizeof(char));
        m->cor = (char*)malloc(sizeof(char));

        printf("Insira a placa: ");
        scanf(" %s", m->placa);
        printf("Insira a quilometragem: ");
        scanf(" %f", &m->km);
        printf("Insira a cor: ");
        scanf(" %s", m->cor);

        novo->info = m;
    }
    novo->tipo = tipo;
    novo->prox = g;
    return novo;
}

//===============================================
generica *remover(generica *g, char*placa)
{
    generica*aux=g, *anterior=NULL;
    while(aux!=NULL)
    {
        if(aux->tipo==1)
        {
            carro *c = (carro*)aux->info;
            if(!strcmp(c->placa, placa))
            {
                break;
            }
        }
        else if(aux->tipo == 2)
        {
            moto *m = (moto*)aux->info;
            if(!strcmp(m->placa, placa))
            {
                break;
            }
        }
        anterior = aux;
        aux = aux->prox;
    }
    if(aux!=NULL)
    {
        if(anterior != NULL)
        {
            anterior->prox = aux->prox;
            free(aux);
        }
        else
        {
            g = aux->prox;
            free(aux);
        }
    }
    return g;
}

//===============================================
void Imprimir(generica *g)
{
    generica *aux = g;
    while(aux!=NULL)
    {
        if(aux->tipo == 1)
        {
            carro *c = (carro*)aux->info;
            printf("Placa: %s | Renavam: %s | Modelo: %s | Potencia: %f\n", c->placa, c->renavam, c->modelo, c->potencia);

        }
        else if(aux->tipo == 2)
        {
            moto *m = (moto*)aux->info;
            printf("Placa: %s | Quilometragem: %f | Cor: %s\n", m->placa, m->km, m->cor);
        }
        aux = aux->prox;
    }
}

int quantidadeMotos(generica *g, char *cor)
{
    int count = 0;
    generica *aux = g;
    while(aux!=NULL)
    {
        if(aux->tipo == 2)
        {
            moto *m = (moto*)aux->info;
            if(!strcmp(m->cor, cor))
                count++;
        }
        aux = aux->prox;
    }
    return count;
}

void maiorPotencia(generica*g)
{
    float maior = __FLT_MIN__;
    generica *aux = g;
    carro* cMaior = NULL;

    while(aux!=NULL)
    {
        if(aux->tipo == 1)
        {
            carro*c = (carro*)aux->info;
            if(c->potencia > maior)
            {
                cMaior = c;
                maior = c->potencia;
            }
        }
        aux = aux->prox;
    }
    printf("Placa: %s | Renavam: %s | Modelo: %s | Potencia: %f\n", cMaior->placa, cMaior->renavam, cMaior->modelo, cMaior->potencia);
}

//================================================================
generica *destruir(generica *g)
{
    if(g!=NULL)
    {
        free(g->info);
        free(g);
    }
    return NULL;
}

//================================================================
int main()
{
    int op, charop;
    char *busca = (char*)malloc(sizeof(char));

    generica *g = NULL;

    while(op!=6)
    {
        system("clear");
        printf("1)Inserir um veiculo\n2)Remover um veiculo\n3)Imprimir a lista\n4)Contar motos de uma cor\n5)Imprime o carro de maior potencia\n6)Sair e destruir\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                printf("1) carro  2) moto\n");
                scanf("%d", &charop);
                g = Inserir(g, charop);
                break;
            case 2:
                printf("Qual placa deseja remover? ");
                scanf(" %s", busca);
                g = remover(g, busca);
                break;
            case 3:
                Imprimir(g);
                break;
            case 4:
                printf("Qual cor voce deseja? ");
                scanf(" %s", busca);
                printf("Existem %d motos da cor %s.\n", quantidadeMotos(g, busca), busca);
                break;
            case 5:
                maiorPotencia(g);
                break;
            case 6:
                g = destruir(g);
                break;
        }
    __fpurge(stdin);
    getchar();
    }
    return 0;
}
