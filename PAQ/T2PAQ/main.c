//==================================================================
// Implementar o algoritmo de compressao e descompressao de Huffman
// Perguntar qual arquivo deve ser compactado
// Converter o arquivo em uma string de 0 e 1 salva em um arquivo temporario que ser usado como fonte de dados para compressao
// ->Leitura de cada byte do arquivo original, sua transformaçao em char str[8] e posterior gravacao no arquivo temporario
// ->O programa deve mostrar se conseguiu realizar a compressao e qual foi a taxa de compressao
// Na decompressao, informar qual o nome do arquivo compactado e o nome original
// fazer a leitura da sequencia de bits do arquivo e produzir um arquivo temporario com a sequencia dos bits descompactados
// Depois, esse grupo de bits (char) deve ser agrupado e transformado no arquivo original
//
// O programa deve permitir ao usuario escolher o nome do arquivo compactado, e ao descompacta-lo, recupere seu nome original
// sem que o usuario precise o informar
//==================================================================

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<string.h>

typedef struct freq{
    char *byte;
    int quant;
    struct freq *esq;
    struct freq *dir;
}freq;

void lerArquivo(FILE *arq)
{
    uint8_t num;
    char *a;
    FILE *exit = fopen("temp.txt", "w");
    while(!feof(arq))
    {
        a = malloc(8*sizeof(char));
        fread(&num, 1, 1, arq);
        itoa(num, a, 2);
        fprintf(exit, "%s\n", a);
        free(a);
    }
    fclose(exit);
}

freq *removerElemento(freq*f, char*byte, int quantidade);

freq * inserirRepetido(freq *f, char *byte, int quantidade);

int calcularAltura(freq *f)
{
    if(f!=NULL)
    {
        int hd, he;
        he = calcularAltura(f->esq);
        hd = calcularAltura(f->dir);
        if(he > hd)
            return 1 + he;
        else
            return 1 + hd;
    }
    return 0;
}

int balanceada(freq *f)
{
    if(f!=NULL)
    {
        int he, hd;
        he = calcularAltura(f->esq);
        hd = calcularAltura(f->dir);
        if(he - hd > 1)
            return 0;
        else if(hd - he > 1)
            return 0;
        else
            return 1*balanceada(f->esq)*balanceada(f->dir);
    }
    return 1;
}


freq * balancearArvore(freq *f)
{
    if(f!=NULL)
    {
        int h1, hd;
        h1 = calcularAltura(f->esq);
        hd = calcularAltura(f->dir);
        if(h1 - hd > 1)
        {
            freq *aux = f->esq;
            while(aux->dir!=NULL) aux = aux->dir;
            f->dir=inserirRepetido(f->dir, f->byte, f->quant);
            strcpy(f->byte, aux->byte);
            f->quant=aux->quant;
            f->esq = removerElemento(f->esq, aux->byte, aux->quant);
        }
        else
        {
            freq*aux = f->dir;
            while(aux->esq!=NULL) aux=aux->esq;
            f->esq=inserirRepetido(f->esq, f->byte, f->quant);
            strcpy(f->byte, aux->byte);
            f->quant=aux->quant;
            f->dir=removerElemento(f->dir, aux->byte, aux->quant);
        }
    }
    return f;
}

freq * inserirRepetido(freq *f, char *byte, int quantidade)
{
    if(f!=NULL)
    {
        if(quantidade<f->quant)
            f->esq = inserirRepetido(f->esq, byte, quantidade);
        if(quantidade>f->quant)
            f->dir = inserirRepetido(f->dir, byte, quantidade);
    }
    else
    {
        printf("\n\n\n\n\nInserindo %s\n\n\n\n\n", byte);
        f = (freq*)malloc(sizeof(freq));
        f->byte = (char*)malloc(8*sizeof(char));
        strcpy(f->byte, byte);
        f->quant=quantidade;
        f->esq=NULL;
        f->dir=NULL;
    }
    return f;
}

freq * removerElemento(freq *f, char *byte, int quantidade)
{
    if(f!=NULL)
    {
        if(strcmp(f->byte, byte))
        {
            if(f->esq==NULL && f->dir==NULL)
            {
                free(f);
                f = NULL;
            }
            else if(f->esq==NULL || f->dir==NULL)
            {
                freq *aux;
                if(f->esq==NULL)
                    aux = f->dir;
                if(f->dir==NULL)
                    aux = f->esq;
                free(f);
                f = aux;
            }
            else
            {
                freq *aux = f->dir;
                while(aux->esq!=NULL) aux = aux->esq;
                strcpy(f->byte, aux->byte);
                f->quant = aux->quant;
                f->dir=removerElemento(aux, aux->byte, aux->quant);
            }
        }
        else
        {
            if(f->quant < quantidade)
                f->esq = removerElemento(f->esq, byte, quantidade);
            if(f->quant > quantidade)
                f->dir = removerElemento(f->dir, byte, quantidade);
        }
    }
    return f;
}

int buscarElemento(freq *f, char *busca)
{
    if(f!=NULL)
    {
        if(strcmp(f->byte, busca))
        {
            return 0;
        }
        else
        {
            return buscarElemento(f->esq, busca) * buscarElemento(f->dir, busca);
        }
    }
    return 1;
}

freq * verificarRepeticao(freq *f, char *busca, freq *ini)
{
    if(f!=NULL)
    {
        if(strcmp(f->byte, busca))
        {
            f->quant++;
            ini = inserirRepetido(ini, f->byte, f->quant);
            ini = removerElemento(ini, f->byte, f->quant);
        }
        f->esq = verificarRepeticao(f->esq, busca, ini);
        f->dir = verificarRepeticao(f->dir, busca, ini);
    }
    return f;
}

freq * inserirNovo(freq *f, char *byte)
{
    if(f!=NULL)
    {
        //printf("Indo pra esquerda\n");
        f->esq = inserirNovo(f->esq, byte);
    }
    else
    {
        printf("\n\n\n\nInserindo %s\n\n\n\n", byte);
        f = (freq*)malloc(sizeof(freq));
        f->quant=1;
        f->byte=(char*)malloc(8*sizeof(char));
        strcpy(f->byte, byte);
        f->esq=NULL;
        f->dir=NULL;
    }
    return f;
}

void imprimir(freq *f)
{
    if(f!=NULL)
    {
        imprimir(f->esq);
        printf("%s ocorreu %d vezes\n", f->byte, f->quant);
        imprimir(f->dir);
    }
}

int main()
{
    FILE *arq;
    freq*f =NULL;
    char nomeArq[50], byte[8];
    scanf("%s", nomeArq);
    arq = fopen(nomeArq, "rb");
    lerArquivo(arq);
    fclose(arq);

    //printf("Gerei o arquivo temp.\n\n");

    arq = fopen("temp.txt", "r");

    //printf("Lerei temp.\n\n");
    while(!feof(arq))
    {
        //printf("Lendo os bytes.");

        fscanf(arq, "%s\n", byte);
        printf("\n\n%s\n\n", byte);

        if(!buscarElemento(f, byte))
        {
            //printf("\n\nEncontrei repeticao!!!\n\n");
            f = verificarRepeticao(f, byte, f);
        }
        else
        {
            f = inserirNovo(f, byte);
        }
        printf("Vou ver se ta balanceada\n");
        if(!balanceada(f)){
            printf("Vou balancear\n");
            f = balancearArvore(f);
        }

        //imprimir(f);

    }
    fclose(arq);

    printf("\n\nVou imprimir\n\n");

    imprimir(f);

    printf("\n\nTeje impresso\n\n");

    return 0;
}
