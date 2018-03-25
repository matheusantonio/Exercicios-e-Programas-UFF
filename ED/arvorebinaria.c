/*
1-Ler árvore de um arquivo (precisa fornecer o nome do arquivo para o caso de querer ler árvores diferentes)
2- Imprimir árvore das seguintes maneiras (criar um submenu):
	a) pré ordem
	b) em ordem
	c) pós ordem
	d) em largura (por niveis)
	e) Na notação de parênteses usada ao ler de um arquivo
3- Verificar se um elemento existe na árvore
4- Calcular a altura de uma árvore
5- Contar o número de ocorrências de um determinado elemento em uma árvore
----Abaixo, as funções não são obrigatórias para a próxima entrega
6- Imprimir as folhas da árvore
7- Contar o número de nós internos da árvore
8- Verificar o nível de um nó na árvore (primeira ocorrência)
9- Verificar se a árvore é cheia
----
10- Sair e destruir a estrutura (de forma recursiva)
*/


//ESSE COMENT�RIO � UM TESTE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arvore
{
	int info;
	struct arvore *esq;
	struct arvore *dir;
} arvore;

//1
arvore * lerArvore(arvore *a, FILE *arq)
{
	char symb;
	int valor;
	fscanf(arq, "%c", &symb);
	fscanf(arq, "%d", &valor);
	if(valor != -1)
	{
		a = malloc(sizeof(arvore));
		a->info = valor;
		a->esq=lerArvore(a->esq, arq);
		a->dir=lerArvore(a->dir, arq);
	}
	else
	{
		a = NULL;
	}
	fscanf(arq, "%c", &symb);
	return a;
}

//2a
void imprimirPreordem(arvore *a)
{
	if(a != NULL)
	{
		printf("%d |", a->info);
		imprimirPreordem(a->esq);
		imprimirPreordem(a->dir);
	}
}

//2b
void imprimirEmOrdem(arvore *a)
{
	if(a != NULL)
	{
		imprimirEmOrdem(a->esq);
		printf("%d |", a->info);
		imprimirEmOrdem(a->dir);
	}
}

//2c
void imprimirPosOrdem(arvore *a)
{
	if(a != NULL)
	{
		imprimirPosOrdem(a->esq);
		imprimirPosOrdem(a->dir);
		printf("%d |", a->info);
	}
}

//3d
void imprimirEmNiveis(arvore *a, int nivel, int vez)
{
	if(a!=NULL)
	{
		if(nivel == vez)
		{
			printf("%d |", a->info);
			imprimirEmNiveis(a->esq, nivel-1, vez-1);
			imprimirEmNiveis(a->dir, nivel-1, vez-1);

		}
		else
		{
			imprimirEmNiveis(a->esq, nivel-1, vez);
			imprimirEmNiveis(a->dir, nivel-1, vez);
			
		}
		
	}
}

//3
int verificarElemento(arvore *a, int elem)
{
	if(a!=NULL)
	{
		if(a->info == elem)
		{
			return 1;
		}
		else
		{
			if(verificarElemento(a->esq, elem) || verificarElemento(a->dir,elem))
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

//4
int calcularAltura(arvore *a)
{
	if(a!=NULL)
	{
		if(calcularAltura(a->esq) > calcularAltura(a->dir))
		{
			return 1 + calcularAltura(a->esq);
		}
		else
		{
			return 1 + calcularAltura(a->dir);
		}
	}
	return 0;
}

//5
int contarOcorrencia(arvore *a, int elem)
{
	if(a!=NULL)
	{
		if(a->info == elem)
		{
			return 1 + contarOcorrencia(a->esq, elem) + contarOcorrencia(a->dir, elem);
		}
		else
		{
			return contarOcorrencia(a->esq, elem) + contarOcorrencia(a->dir, elem);
		}
	}
	return 0;
}

//6

/*
//Essa eh uma versao anterior da funcao de imprimir folhas, a nova esta menos gambiarra
int imprimirFolhas(arvore *a){
	if(a==NULL)
	{
		return 0;
	}
	else{
		int esq, dir;
		esq = imprimirFolhas(a->esq);
		dir = imprimirFolhas(a->dir);
		if( esq == 0 && dir == 0)
			printf("%d |", a->info);
		return 1;
	}
}*/

void imprimirFolhas(arvore *a)
{
	if(a!=NULL)
	{
		if(a->esq==NULL && a->dir == NULL)
		{
			printf("%d |", a->info);
		}
		else
		{
			imprimirFolhas(a->esq);
			imprimirFolhas(a->dir);
		}
	}
}

//7
int contarNosInternos(arvore *a)
{
	if(a==NULL)
	{
		return 0;
	}
	else
	{
		if(a->esq == NULL && a->dir ==NULL)
		{
			return 0;
		}
		else
		{
			return 1 + contarNosInternos(a->esq) + contarNosInternos(a->dir);
		}
	}
}

//8 (falta terminar)
int nivelDeUmNo(arvore *a, int elem)
{
	if(a != NULL)
	{
		if(a->info == elem)
		{
			return 1;
		}
		else
		{
			if(nivelDeUmNo(a->esq, elem) == nivelDeUmNo(a->dir, elem))
			{
				return 1 + nivelDeUmNo(a->esq, elem);
			}
			else
			{
				return 1 + nivelDeUmNo(a->dir, elem);
			}
		}
	}
	return 0;
}

//9
int arvoreCheia(arvore *a, int nivel)
{
	if(a!=NULL)
	{
		if(a->esq == NULL && a->dir == NULL && nivel == 1)
		{
			return 1;
		}
		else
		{
			if(arvoreCheia(a->esq, nivel-1) && arvoreCheia(a->dir, nivel-1))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	return 0;
}

//10
void destruirArvore(arvore *a)
{
	if(a != NULL)
	{
		destruirArvore(a->esq);
		destruirArvore(a->dir);
		free(a);
	}
}



int menu(){
	system("cls");
	int op;
	printf("\n1-Receber arvore de arquivo");
	printf("\n2-Imprimir arvore");
	printf("\n3-Verificar existencia de elemento");
	printf("\n4-Calcular altura da arvore");
	printf("\n5-Contar o numero de ocorrencias de um elemento");
	printf("\n6-Imprimir as folhas da arvore");
	printf("\n7-Conta o numero de nos internos");
	printf("\n8-Nivel onde se encontra um no");
	printf("\n9-Verifica se a arvore eh cheia");
	printf("\n10-Sair e destruir arvore\n");
	scanf("%d", &op);
	return op;
}

int main(){
	FILE *arq;
	int op;
	int busca;
	char printop;
	char arquivo[30];
	arvore *a = NULL;
	
	while(op!=10)
	{
		
		op = menu();
		switch(op)
		{
			
			case 1:
				printf("Digite o nome do arquivo contendo a arvore.");
				fflush(stdin);
				gets(arquivo);
				arq = fopen(arquivo, "r");
				a = lerArvore(a, arq);
				fclose(arq);
				fflush(stdin);
				getchar();
				break;
			
			case 2:
				printf("\nImprimir em:\na)pre ordem\nb)em ordem\nc)pos ordem\nd)em largura (por niveis)\ne)Na notacao de parenteses\n");
				fflush(stdin);
				scanf("%c", &printop);
				printf("\n");
				switch(printop)
				{	
					case 'a':
						imprimirPreordem(a);
						break;
					
					case 'b':
						imprimirEmOrdem(a);
						break;
					
					case 'c':
						imprimirPosOrdem(a);
						break;
					
					case 'd':
						imprimirEmNiveis(a, calcularAltura(a), calcularAltura(a));
						break;
					
					case 'e':
						break;
				}
				printf("\n");
				fflush(stdin);
				getchar();
			break;
			
			case 3:
				printf("\nDigite o elemento a ser buscado:");
				scanf("%d", &busca);
			    if(verificarElemento(a, busca))
					printf("\nElemento encontrado\n");
				else
					printf("\nElemento nao encontrado\n");
				
				fflush(stdin);
				getchar();
			break;
		
			case 4:
				printf("\nA arvore tem altura %d\n", calcularAltura(a));
				
				fflush(stdin);
				getchar();
			break;
	
			case 5:
				printf("\nDigite o elemento a ser buscado:");
				scanf("%d", &busca);
				printf("\nO elemento ocorre %d vezes\n", contarOcorrencia(a, busca));	
				
				fflush(stdin);
				getchar();
			break;
			
			case 6:
				printf("\n");
				imprimirFolhas(a);
				printf("\n");
				fflush(stdin);
				getchar();
			break;
			
			case 7:
				printf("\nO numero de nos internos e %d\n", contarNosInternos(a));
				fflush(stdin);
				getchar();
			break;
			
			case 8:
				printf("\nDigite o elemento a ser buscado:");
				scanf("%d", &busca);
				printf("\nO no esta no nivel %d\n", nivelDeUmNo(a, busca));
				fflush(stdin);
				getchar();
			break;
			
			case 9:
				if(arvoreCheia(a, calcularAltura(a)))
					printf("\nA arvore eh cheia\n");
				else
					printf("\nA arvore nao eh cheia\n");
					
				fflush(stdin);
				getchar();
			break;
			
			case 10:
				destruirArvore(a);
				printf("\nArvore destruida com sucesso.\nSaindo do programa...");
				fflush(stdin);
				getchar();
			break;
		}
	}
}
