//================================================================
// Faca um programa que manipule uma lista generica de veiculos:
// Carro-> renavam, placa, modelo e potencia
// Moto-> Placa, quilometragem, cor
// 1) Inserir um veiculo
// 2) Remover um veiculo (pela placa)
// 3) Imprimir a lista
// 4) Contar as motos de uma determinada cor
// 5) Imprime o carro de maior potencia
// 6) Sair e destruir
//================================================================
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<string.h>

typedef struct _carro
{
    char renavam[9];
    char placa[7];
    char modelo[30];
    float potencia;
} carro;

typedef struct _moto
{
    char placa[7];
    float km;
    char cor[15];
} moto;

typedef struct _generica
{
    int tipo;
    void* valor;
} generica;

//================================================================
void inicializar(generica *g, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        g[i].valor = NULL;
        g[i].tipo = -1;
    }
}


//================================================================
void insereCarro(generica *g, int *n, carro *c)
{
    g[*n].valor = c;
    g[*n].tipo = 1;
    *n+=1;
}

void insereMoto(generica *g, int *n, moto *m)
{
    g[*n].valor = m;
    g[*n].tipo = 2;
    *n+=1;
}

void insere(generica *g, int *n)
{
    char op;
    printf("O que deseja inserir?\na)Carro    b)Moto\n");
    scanf(" %c", &op);
    if(op=='a' || op=='A')
    {
        carro *c = (carro*)malloc(sizeof(struct _carro));
        printf("Entre com a placa: ");
        scanf(" %s", c->placa);
        printf("Entre com o renavam: ");
        scanf(" %s", c->renavam);
        printf("Entre com o modelo: ");
        scanf(" %s", c->modelo);
        printf("Entre com a potencia: ");
        scanf("%f", &c->potencia);
        insereCarro(g, n, c);
    }
    else if(op=='b' || op=='B')
    {
        moto *m = (moto*)malloc(sizeof(struct _moto));
        printf("Entre com a placa: ");
        scanf(" %s", m->placa);
        printf("Entre com a quilometragem: ");
        scanf("%f", &m->km);
        printf("Entre com a cor: ");
        scanf(" %s", m->cor);
        insereMoto(g, n, m);
    }
    else
    {
        printf("Entrada nao reconhecida.\n");
    }
}

//================================================================

void remover(generica *g, int *n, char *placa)
{
    int i, posrm = *n;
    for(i=0;i<*n;i++)
    {
        if(g[i].tipo == 1)
        {
            carro *c = (carro*)g[i].valor;
            if(!strcmp(c->placa, placa))
            {
                posrm = i;
                break;
            }
        }
        else if(g[i].tipo == 2)
        {
            moto *m = (moto*)g[i].valor;
            if(!strcmp(m->placa, placa))
            {
                posrm = i;
                break;
            }
        }
    }
    for(i=posrm;i<*n;i++)
    {
        g[i] = g[i+1];
    }
    if(posrm != *n) *n-=1;
}


//================================================================
void imprimir(generica *g, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(g[i].tipo == 1)
        {
            carro *c = (carro*)g[i].valor;
            printf("Tipo: carro | placa: %s |",  c->placa);
            printf(" renavam: %s |", c->renavam);
            printf(" modelo: %s |", c->modelo);
            printf(" potencia: %f\n", c->potencia);
        }
        else
        {
            moto *m = (moto*)g[i].valor;
            printf("Tipo: moto | placa: %s |", m->placa);
            printf(" quilometragem: %f |", m->km);
            printf(" cor: %s\n", m->cor);
        }
    }
}

//================================================================

int motosDaCor(generica *g, int n, char *cor)
{
    int i, cont=0;
    for(i=0;i<n;i++)
    {
        if( g[i].tipo == 2)
        {
            moto *m = (moto*)g[i].valor;
            if(!strcmp(m->cor, cor))
                cont++;
        }
    }
    return cont;
}

//================================================================

void maiorPotencia(generica *g, int n)
{
    int i, posMaior;
    float maior = __FLT_MIN__;
    for(i=0;i<n;i++)
    {
        if( g[i].tipo == 1 )
        {
            carro *c = (carro*)g[i].valor;
            if(c->potencia > maior)
            {
                maior = c->potencia;
                posMaior = i;
            }
        }
    }
    carro *aux = (carro*)g[posMaior].valor;
    printf("O carro de maior potencia eh o carro com a placa %s de potencia %f.\n", aux->placa, aux->potencia);
}
//================================================================

void destruir(generica *g, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        free( g[i].valor );
    }
    free(g);
}

//================================================================
int main()
{
    int op, n=0;
    char *busca = (char*)malloc(sizeof(char));

    generica g[15];

    while(op!=6)
    {
        system("clear");
        printf("1)Inserir um veiculo\n2)Remover um veiculo\n3)Imprimir a lista\n4)Contar motos de uma cor\n5)Imprime o carro de maior potencia\n6)Sair e destruir\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
                insere(g, &n);
                break;
            case 2:
                printf("Qual placa deseja remover? ");
                scanf(" %s", busca);
                remover(g, &n, busca);
                break;
            case 3:
                imprimir(g, n);
                break;
            case 4:
                printf("Qual cor voce deseja? ");
                scanf("%s", busca);
                motosDaCor(g, n, busca);
                break;
            case 5:
                maiorPotencia(g, n);
                break;
            case 6:
                destruir(g, n);
                break;
        }
    __fpurge(stdin);
    getchar();
    }
    return 0;
}
