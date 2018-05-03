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
    char byte[9];
    int quant;
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

int repetido(freq *f, char *byte,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(!strcmp(f[i].byte, byte))
        {
            return i;
        }
    }
    return -1;
}

int compar(const void *ptr1, const void *ptr2)
{
    const freq *f1 = ptr1, *f2 = ptr2;
    if(f1->quant<f2->quant)
        return 1;
    if(f1->quant>f2->quant)
        return -1;
    else
        return 0;
}

void imprimir(freq *f, int tam)
{
    int i;
    for(i =0;i<tam;i++)
    {
        printf("%s %d\n", f[i].byte, f[i].quant);
    }
}

void imprimirSoma(freq *f, int tam)
{
    int i, soma=0;
    for(i =0;i<tam;i++)
    {
        soma = soma + f[i].quant;
    }
    printf("\n\n%d\n\n", soma);
}

int main()
{
    FILE *arq;

    freq*f =NULL;
    int tam=0, p, cont=0;
    char nomeArq[50], byte[9], aux;
    scanf("%s", nomeArq);
    arq = fopen(nomeArq, "rb");
    lerArquivo(arq);
    fclose(arq);

    arq = fopen("temp.txt", "r");

    while(!feof(arq))
    {
        fscanf(arq, "%s[^\n]", byte);
        p = repetido(f, byte, tam);
        if(p==-1)
        {
            if(f==NULL)
                f = malloc(sizeof(freq));
            else
                f = realloc(f, (tam + 1) * sizeof(freq));
            f[tam].quant=1;
            strcpy(f[tam].byte, byte);
            //printf("%s\n\n", f[tam].byte);
            tam = tam + 1;
        }
        else
        {
            f[p].quant++;
        }

        fscanf(arq, "%c", &aux);
    }
    fclose(arq);

    qsort(f, tam, sizeof(freq), compar);

    imprimir(f, tam);

    imprimirSoma(f, tam);


    return 0;
}
