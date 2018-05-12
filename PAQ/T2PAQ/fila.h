//
// Created by Matheus Antonio on 10/05/2018.
//

#ifndef T2PAQ_FILA_H
#define T2PAQ_FILA_H

typedef struct _fila *fila;

fila fila_Inicializar();

void ordenar(fila f);

int fila_Procurar(fila f, uint8_t busca);

void fila_Inserir(fila f, uint8_t valor);

void fila_Imprimir(fila f);

int elempos(fila f, int pos);

int getTop(fila f);

#endif //T2PAQ_FILA_H