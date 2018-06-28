#ifndef __A1__
#define __A1__

typedef struct _funcionario *Funcionario;

typedef struct _lista *Lista;

Lista inicializarLista();

void inserirLista(Lista l, char *nome, char *sobrenome, char *cidade, char *estado, char* data, char*empresa, char*civil, float salario);

void imprimirFuncionarios(Lista l);

#endif
