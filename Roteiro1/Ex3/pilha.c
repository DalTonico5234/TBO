#include "pilha.h"
#include <stdlib.h>

typedef struct no {
  void *dado;
  struct no *prox;
} No;

struct pilha {
  No *topo;
};

Pilha *criaPilha() {
  Pilha *sonic = (Pilha *)malloc(sizeof(Pilha));

  sonic->topo = NULL;

  return sonic;
}

void empilha(Pilha *sonic, void *dado) {
  No *novo = (No *)malloc(sizeof(No));
  novo->dado = dado;

  novo->prox = sonic->topo;
  sonic->topo = novo;
}

void *desempilha(Pilha *sonic) {
  No *morto = sonic->topo;
  void *dado = sonic->topo->dado;

  sonic->topo = sonic->topo->prox;

  free(morto);

  return dado;
}

void destroiPilha(Pilha *sonic) {
  if (sonic->topo != NULL) {

    No *atual = sonic->topo;
    No *prox = atual->prox;

    for (atual; atual != NULL; atual = prox) {
      prox = atual->prox;
      free(atual);
    }
  }

  free(sonic);
}
