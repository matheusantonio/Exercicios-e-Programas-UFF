/*
1)
Criar um arquivo A2 com as chaves secundarias que se deseja indexar e os enderecos de disco da tabela
A2: [Endereco de disco, chave primaria, chaves secundarias...]

2)
Criar um arquivo A3 para cada chave secundaria, contendo o endereco de disco, a chave primaria
e a respectiva chave secundaria
A3: [ED, CP, CS 1], [Endereco de disco, chave primaria, chave secundaria 2], ...

3)
Ordenar todos os arquivos A3 de acordo com as chaves secundarias, criando arquivos A4
(verificar se os A3 serao utilizados depois, se nao, apagar)
A4: [ED, CP, CS 1], [Endereco de disco, chave primaria, chave secundaria 2], ...

4)
Gerar um arquivo A5 que identifica a quantidade de registros de cada chave secundaria
e o valor de disco da primeira ocasiao de cada chave
A5: [CS1, Quantidade, Prim], [Cs2, Quantidade, Prim],...

5)
Gerar arquivos A6 a partir do A4 que identificam qual eh o proximo registro que possui a mesma
chave secundaria
A6: [ED, CP, CS1, Prox], [ED, CP, Cs2, Prox] ...

6)
Ordenar os arquivos A6 pela chave primaria, gerando os arquivos A7
A7: [ED, CP, CS1, Prox], [ED, CP, Cs2, Prox] ...

7)
Juntar o arquivo A1 com todos os arquivos A7, criando o arquivo A8. Os arquivos de
indice passarao a ser os A5
[Todos os nomes originais do A1,
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
        char nome[30], sobrenome[50], cidade[30], estado[30], data[10], empresa[30], civil[15];
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
        inserirLista(l, cont, nome, sobrenome, cidade, estado, data, empresa, civil, salario);
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
    Lista3 A3[4];

    // Arquivo A3 criado a partir do A2
    int i;
    for(i=0;i<4;i++)
    {
        A3[i] = inicializar3();
        criarArquivoA3(A2, A3[i], i);
        ordenarLista3(A3[i]);
    }

    Lista4 A4[4];

    for(i=0;i<4;i++)
    {
        A4[i] = inicializarLista4();
        criarArquivoA4(A3[i], A4[i]);
        // token eh o vetor de strings que armazena os nomes
        // das tabelas. Para que a funcao pudesse ser chamada
        // num for, utilizamos ele para dar o nome aos arquivos
        // A4 (A5 do slide) que terao a primeira ocorerncia
        // de uma chave e a quantidade de ocorrencias da mesma
        if(i>2) gerarTabela(A4[i], token[i+3]);
        else gerarTabela(A4[i], token[i+2]);
    }

    Lista5 A5[4];

    for(i=0;i<4;i++)
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
