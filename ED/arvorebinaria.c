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

typedef struct arvore{
	int info;
	struct arvore *esq;
	struct arvore *dir;
} arvore;

//1
arvore * lerArvore(arvore *a, FILE *arq){
	char symb;
	int valor;
	fscanf(arq, "%c", &symb);
	fscanf(arq, "%d", &valor);
	if(valor != -1){
		a = malloc(sizeof(arvore));
		a->info = valor;
		a->esq=lerArvore(a->esq, arq);
		a->dir=lerArvore(a->dir, arq);
	}
	else{
		a = NULL;
	}
	fscanf(arq, "%c", &symb);
	return a;
}

//2a
void imprimirPreordem(arvore *a){
	if(a != NULL){
		printf("%d |", a->info);
		imprimirPreordem(a->esq);
		imprimirPreordem(a->dir);
	}
}

//2b
void imprimirEmOrdem(arvore *a){
	if(a != NULL){
		imprimirEmOrdem(a->esq);
		printf("%d |", a->info);
		imprimirEmOrdem(a->dir);
	}
}

//2c
void imprimirPosOrdem(arvore *a){
	if(a != NULL){
		imprimirPosOrdem(a->esq);
		imprimirPosOrdem(a->dir);
		printf("%d |", a->info);
	}
}

//3
int verificarElemento(arvore *a, int elem){
	if(a!=NULL){
		if(a->info == elem){
			return 1;
		}
		else{
			if(verificarElemento(a->esq, elem) || verificarElemento(a->dir,elem))
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

//4
int calcularAltura(arvore *a){
	if(a!=NULL){
		if(calcularAltura(a->esq) > calcularAltura(a->dir)){
			return 1 + calcularAltura(a->esq);
		}
		else{
			return 1 + calcularAltura(a->dir);
		}
	}
	return 0;
}

//5
int contarOcorrencia(arvore *a, int elem){
	if(a!=NULL){
		if(a->info == elem){
			return 1 + contarOcorrencia(a->esq, elem) + contarOcorrencia(a->dir, elem);
		}
		else{
			return contarOcorrencia(a->esq, elem) + contarOcorrencia(a->dir, elem);
		}
	}
	return 0;
}

//6
arvore * imprimirFolhas(arvore *a){
	if(a != NULL && (imprimirFolhas(a->esq) == NULL) && (imprimirFolhas(a->dir) == NULL))
		printf("%d |", a->info);
	return a;
}

int main(){
	FILE *arq;
	int op;
	int busca;
	char printop;
	char arquivo[30];
	arvore *a;
	while(op!=10){
		printf("\n1-Receber arvore de arquivo\n2-Imprimir arvore\n3-Verificar existencia de elemento\n4-Calcular altura da arvore\n5-Contar o numero de ocorrencias de um elemento\n6-Imprimir as folhas da arvore\n10-Sair\n");
		scanf("%d", &op);
		switch(op){
			case 1:
				printf("Digite o nome do arquivo contendo a arvore.");
				fflush(stdin);
				gets(arquivo);
				arq = fopen(arquivo, "r");
				a = lerArvore(a, arq);
				fclose(arq);
				break;
			case 2:
				printf("\nImprimir em:\na)pre ordem\nb)em ordem\nc)pos ordem\nd)em largura (por niveis)\ne)Na notacao de parenteses\n");
				fflush(stdin);
				scanf("%c", &printop);
				printf("\n");
				switch(printop){
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
					break;
					case 'e':
					break;
				}
				printf("\n");
				break;
			case 3:
				scanf("%d", &busca);
			    if(verificarElemento(a, busca))
					printf("\nElemento encontrado\n");
				else
					printf("\nElemento nao encontrado\n");
				break;
			case 4:
				printf("\nA arvore tem altura %d\n", calcularAltura(a));
				break;
			case 5:
				scanf("%d", &busca);
				printf("\nO elemento ocorre %d vezes\n", contarOcorrencia(a, busca));
				break;
			case 6:
				printf("\n");
				imprimirFolhas(a);
				printf("\n");
				break;
		}
	}
}
