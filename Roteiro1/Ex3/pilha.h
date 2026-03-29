#ifndef pilha_h
#define pilha_h

typedef struct pilha Pilha;

Pilha *criaPilha();

void empilha(Pilha *sonic, void *dado);

void* desempilha(Pilha *sonic);

void destroiPilha(Pilha *sonic);

#endif