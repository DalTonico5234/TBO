#ifndef pilha_h
#define pilha_h

#include <stddef.h>

typedef struct pilha Pilha;

Pilha *criaPilha(size_t tam_elem);

void empilha(Pilha *sonic, void *dado);

void desempilha(Pilha *sonic, void *destino);

void destroiPilha(Pilha *sonic);

#endif