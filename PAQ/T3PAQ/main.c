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

typedef struct _funcionario{
    char Nome[15];
    char Sobrenome[15];
    char Cidade[30];
    char Estado[30];
    char Data_Nascimento[8];
    char Empresa[30];
    char Estado_Civil[10];
    float Salario;
} Funcionario;

void gerarA2()
{
}

void gerarA3()
{
}

void gerarA4()
{
}

void gerarA5()
{
}

void gerarA6()
{
}

void gerarA7()
{
}

void gerarA8()
{
}

int main()
{

}
