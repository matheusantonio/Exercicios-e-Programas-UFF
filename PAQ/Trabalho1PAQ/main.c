/* PRIMEIRO TRABALHO DE PROGRAMAÇÃO EM ARQUIVOS
Objetivo: analisar a frequencia com que os valores inteiros (bytes consecutivos) aparecem em arquivos de diversos formatos
Escolher arquivos com o formato BMP, JPEG, (pode ser o BMP anterior convertido), DOC (ou outro arquivo Office), AVI, MP3, HTML
Cada arquivo deve ser compactado (ZIP ou RAR), não precisam ser muito grandes, mas também nao podem ser pequenos

Criar um programa que abra esses arquivos (de maneira original e compactada) na forma binaria e ler 2 a 2 os bytes dos arquivos (short int - 16 bits)
O programa deve ter um contador para cada possivel numero de 16 bits (256*256)
Sempre que for lido um short int de 16 bits, seu contador deve ser incrementado
O programa deve escrever um arquivo (texto) de resultado contendo o valor dos contadores para todos os numeros de 16 bits (0 - 65535)

Com o arquivo de resultado, fazer um grafico (no Excel) de colunas, mostrando a quantidade de cada numero de 16 bits
Deve ser feito um grafico para cada arquivo original e outro para cada arquivo compactado

Preparar um pequeno relatorio contendo:
*o codigo fonte do programa
*os graficos (lado a lado) de cada arquivo original e compactado
*uma pequena analise do comportamento dos graficos
*os arquivos devem ser enviados para marcos_quinet@id.uff.br
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//====================================================
typedef struct ocorrencia
{
    unsigned short valorBinario;
    int quantidade;
    struct ocorrencia *prox;
} ocorrencia;


//====================================================
ocorrencia* buscaValor(ocorrencia *o, unsigned short busca)
{
    ocorrencia *buscador = o;
    while(buscador != NULL){
        if(buscador->valorBinario == busca)
            return buscador;
        else
            buscador = buscador->prox;
    }
    return NULL;
}


//====================================================
ocorrencia * criarTabela(ocorrencia *o, unsigned short valor)
{
    ocorrencia *novaOcorrencia = buscaValor(o, valor);

    if (novaOcorrencia != NULL)
    {
        novaOcorrencia->quantidade += 1;
    }
    else
    {
        novaOcorrencia=malloc(sizeof(ocorrencia));

        novaOcorrencia->valorBinario=valor;
        novaOcorrencia->quantidade=1;
        novaOcorrencia->prox=o;
        o = novaOcorrencia;

        //printf("Entrei aqui\n");

        /*
        ocorrencia *buscador = o;

        if(buscador != NULL){
            while(buscador->prox != NULL && buscador->prox->valorBinario < valor) buscador = buscador->prox;
            if(buscador->prox == NULL && buscador->valorBinario < valor) buscador = buscador->prox;
        }

        novaOcorrencia = malloc(sizeof(ocorrencia));
        novaOcorrencia->valorBinario = valor;
        novaOcorrencia->quantidade = 1;

        if(buscador == NULL)
        {
            novaOcorrencia->prox=o;
            o = novaOcorrencia;
        }
        else
        {
            novaOcorrencia->prox=buscador->prox;
            buscador->prox=novaOcorrencia;
        }
        */
    }

    return o;
}


void imprimirTabela(ocorrencia *o)
{
    if(o != NULL)
    {
        printf("%hu ocorre %d vezes|\n", o->valorBinario, o->quantidade);
        imprimirTabela(o->prox);
    }
}


void salvarEmArquivo(ocorrencia *o){
    char nomeArq[50];
    FILE *arq;
    printf("Insira o nome do arquivo (sem a extensao)\n");
    fflush(stdin);
    gets(nomeArq);
    arq = fopen(strcat(nomeArq, ".csv"), "w");
    fprintf(arq, "bit,quantidade\n");
    while(o != NULL){
        fprintf(arq, "%hu,%d\n", o->valorBinario, o->quantidade);
        o=o->prox;
    }
    fclose(arq);
}


ocorrencia * criarTabelaII(ocorrencia *o, unsigned short valor)
{
    ocorrencia *novo=malloc(sizeof(ocorrencia));
    novo->valorBinario = valor;
    novo->quantidade=1;
    novo->prox=o;
    return novo;
}


int main()
{
    FILE *arq;
    ocorrencia *o=NULL;
    char nomeArquivo[50];
    unsigned short valor;

    printf("Insira o nome do arquivo a ser aberto:");
    fflush(stdin);
    gets(nomeArquivo);

    arq = fopen(nomeArquivo, "rb");


    while(!feof(arq)){
        fread(&valor, 2, 1, arq);
        o = criarTabela(o, valor);
    }

    fclose(arq);

    //imprimirTabela(o);

    salvarEmArquivo(o);

    return 0;
}
