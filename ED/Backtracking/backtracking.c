//====================================================================
// MATHEUS ANTONIO OLIVEIRA CARDOSO E JOAO VICTOR SOARES GOMES
//====================================================================
#include<stdio.h>
#include<stdlib.h>

//=====================================================================
// 1) Imprimir todas as combinações de 7, 17, 55 e 61 em que a soma
// seja inferior a 150. (perguntar tamanho N)
//=====================================================================
void combNum(int *vet, int pos, int n)
{
    int num[4] = {7, 17, 55, 61};
    if(pos==n)
    {
        int soma = 0;
        int i;
        for(i=0;i<n;i++)
            soma+=vet[i];

        if(soma<150)
        {
            for(i=0;i<n;i++)
            {
                printf("%d ", vet[i]);
            }
            printf("\n");
        }
    }
    else
    {
        int i;
        for(i=0;i<4;i++)
        {
            vet[pos] = num[i];
            combNum(vet, pos+1, n);
        }
    }
}

//=====================================================================
// 2) Todas as combinações de A, E, I, O, U de tamanho N (perguntar N)
// sem repetição
//=====================================================================
void combChar(char *vet, int pos, int n)
{
    if(pos==n)
    {
        int i, j, flag=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(vet[i] == vet[j]){
                    flag = 1;
                    j=n;
                    i=n;
                }
            }
        }
        if(flag!=1)
        {
            for(i=0;i<n;i++)
                printf("%c ", vet[i]);
            printf("\n");
        }
    }
    else
    {
        int i;
        for(i=0;i<5;i++)
        {
            switch(i)
            {
            case 0:
                vet[pos] = 'a'; break;
            case 1:
                vet[pos] = 'e'; break;
            case 2:
                vet[pos] = 'i'; break;
            case 3:
                vet[pos] = 'o'; break;
            case 4:
                vet[pos] = 'u'; break;
            }
            combChar(vet, pos+1, n);
        }
    }
}

//=====================================================================
// 3) Conte o numero de combinações de 0s e 1s de tamanho N (perguntar)
// em que o numerode 1s seja pelo menos o dobro do numero de 0s
//=====================================================================
int numComb(int *vet, int pos, int n)
{
    static cont = 0;
    if(pos==n)
    {
        int i, cont1 = 0, cont0 = 0;
        for(i=0;i<n;i++)
        {
            if(vet[i] == 1)
                cont1++;
        }
        cont0 = n - cont1;
        if(cont1 >= 2*cont0)
        {
            cont++;
        }
    }
    else
    {
        int i;
        for(i=0;i<=1;i++)
        {
            vet[pos] = i;
            numComb(vet, pos+1, n);
        }
    }
    return cont;
}

//=====================================================================
// 4) Suponha que vocês estão trabalhando com moedas de 1, 5, 10, 25 e
// 50 centavos. Recebendo um valor X como entrada, imprima na tela todas
// as combinações de moedas que totalizam o valor X.
//=====================================================================
void combMoedas(int *vet, int pos, int X)
{
    int aux[5] = {1, 5, 10, 25, 50};
    if(pos==5)
    {
        int soma=0;
        int i;
        for(i=0;i<5;i++)
            soma += vet[i]*aux[i];

        if(soma==X)
        {
            for(i=0;i<5;i++)
                printf("%d: %d, ", aux[i], vet[i]);
            printf("\n");
        }
    }
    else
    {
        int y = X / aux[pos];
        int i;
        for(i=0;i<=y;i++)
        {
            vet[pos] = i;
            combMoedas(vet, pos+1, X);
        }
    }
}

//=====================================================================
int main()
{
    int op=0, N;

    char *vogais;
    int *vet;
    int moedas[5];

    while(op!=5)
    {
        printf("1)Combinacoes de 7, 17, 55 e 61 com soma inferior a 150\n");
        printf("2)Combinacoes de vogais de tamanho N sem repeticoes\n");
        printf("3)Combinacoes de 0s e 1s cuja quantidade de 1s seja o dobro da de 0s\n");
        printf("4)Combinacoes de moedas que totalizem X\n");
        printf("5)Sair\n");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Qual a quantidade de numeros?\n");
            scanf("%d", &N);
            vet = (int*)malloc(N * sizeof(int));
            combNum(vet, 0, N);
            free(vet);
            break;
        case 2:
            printf("Qual a quantidade de letras?\n");
            scanf("%d", &N);
            vogais = (char*)malloc(N* sizeof(char));
            combChar(vogais, 0, N);
            free(vogais);
            break;
        case 3:
            printf("Qual a quantidade de numeros?\n");
            scanf("%d", &N);
            vet = (int*)malloc(N * sizeof(int));
            printf("Num = %d\n", numComb(vet, 0, N));
            free(vet);
            break;
        case 4:
            printf("Qual o valor total?\n");
            scanf("%d", &N);
            combMoedas(moedas, 0, N);
            break;
        }
        fflush(stdin);
        getchar();
        system("cls");
    }
}
