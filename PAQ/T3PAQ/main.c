/*
João Victor Soares Gomes
Gabriel Nascimento
Matheus Antonio Oliveira Cardoso
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
#include "a1.h"
#include "a2.h"
#include "a3.h"
#include "a4.h"
#include "a5.h"

//==========================================

void lerArquivo(FILE *arq, Lista l)
{
    // Usaremos um cont para gerar nosso indice
    int cont = 0;
    while(!feof(arq))
    {
        if(cont==1000) return;
        char nome[30], sobrenome[50], cidade[30], estado[30], data[10], empresa[30], civil[15], salariochar[10];
        float salario;
        fgetc(arq); //o primeiro fgetc serve para ler o caracter de quebra de linha
        fscanf(arq, "%[^;]", nome);
        fgetc(arq); // os fgetc subsequentes, para ler o caracter separador
        fscanf(arq, "%[^;]", sobrenome);
        fgetc(arq);
        fscanf(arq, "%[^;]", cidade);
        fgetc(arq);
        fscanf(arq, "%[^;]", estado);
        fgetc(arq);
        fscanf(arq, "%[^;]", data);
        fgetc(arq);
        fscanf(arq, "%[^;]", empresa);
        fgetc(arq);
        fscanf(arq, "%[^;]", civil);
        fgetc(arq);// 3 fgetc para ler o caracter separador e o R$
        fgetc(arq);
        fgetc(arq);
        fscanf(arq, "%f", &salario);
        salario *= 1000;
        if(salario >= 7000)
        {
            sprintf(salariochar, "R$%.2f", salario);
            inserirLista(l, cont, nome, sobrenome, cidade, estado, data, empresa, civil, salariochar);
        }
        cont++;
    }
}

int main()
{
    Lista A1 = inicializarLista();

    Lista2 A2 = InicializarLista2();


    FILE *arq = fopen("bd_paq.txt", "r");

    //=============================================================
    // Essa parte consiste em ler a primeira linha do arquivo, que
    // contem somente os nomes das colunas
    char token[10][50];

    fscanf(arq, "%[^;]", token[0]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[1]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[2]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[3]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[4]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[5]);
    fgetc(arq);
    fscanf(arq, "%[^;]", token[6]);
    fgetc(arq);
    fscanf(arq, "%[^\n]", token[7]);
    //=============================================================

    lerArquivo(arq, A1);

    fclose(arq);

    // Arquivo A2 criado a partir do A1
    criarArquivoA2(A1, A2);

    //=============================================================
    // Como teremos varios arquivos A3, ele e um vetor de arquivos A3
    Lista3 A3[5];

    // Arquivo A3 criado a partir do A2
    int i;
    for(i=0;i<5;i++)
    {
        A3[i] = inicializar3();
        criarArquivoA3(A2, A3[i], i);
        ordenarLista3(A3[i]);
    }

    Lista4 A4[5];

    for(i=0;i<5;i++)
    {
        A4[i] = inicializarLista4();
        criarArquivoA4(A3[i], A4[i]);
        // token eh o vetor de strings que armazena os nomes
        // das tabelas. Para que a funcao pudesse ser chamada
        // num for, utilizamos ele para dar o nome aos arquivos
        // A4 (A5 do slide) que terao a primeira ocorerncia
        // de uma chave e a quantidade de ocorrencias da mesma
        if(i>=2) gerarTabela(A4[i], token[i+3]);
        else gerarTabela(A4[i], token[i+2]);
    }

    Lista5 A5[5];

    for(i=0;i<5;i++)
    {
        A5[i] = inicializarLista5();
        CriarArquivoA5(A3[i], A5[i]);
        ordenarLista5(A5[i]);
    }

    // A funcao que gera a tabela final recebe o arquivo A1 inicial
    // e o vetor de arquivos A5 (A7 do slide) para concatena-los
    // criando as colunas Prox que vemos no arquivo final A8
    gerarTabelaA8(A1, A5);

    return 0;
}
