#ifndef fila_h
#define fila_h

#include <stddef.h>

typedef struct fila Fila;

Fila *criaFila(size_t tam_elem);

void entra(Fila *posto, void *dado);

void sai(Fila *posto, void *destino);

int ehFilaVazia(Fila *posto);

void primeiro(Fila *posto, void *destino);

void destroiFila(Fila *posto);

#endif