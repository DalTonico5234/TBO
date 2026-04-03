#include "pilha.h"
#include <stdlib.h>
#include <string.h>

typedef struct no {
  void *dado;
  struct no *prox;
} No;

struct pilha {
  No *topo;
  size_t tam_elem;
};

Pilha *criaPilha(size_t tam_elem) {
  Pilha *sonic = (Pilha *)malloc(sizeof(Pilha));

  sonic->tam_elem = tam_elem;

  sonic->topo = NULL;

  return sonic;
}

void empilha(Pilha *sonic, void *dado) {
  No *novo = (No *)malloc(sizeof(No));
  
  novo->dado = malloc (sonic->tam_elem);

  memcpy(novo->dado, dado, sonic->tam_elem);

  novo->prox = sonic->topo;
  sonic->topo = novo;
}

void desempilha(Pilha *sonic, void *destino) {
  No *morto = sonic->topo;

  memcpy(destino, morto->dado, sonic->tam_elem);

  sonic->topo = sonic->topo->prox;

  free(morto->dado);
  free(morto);
}

int ehPilhaVazia(Pilha *sonic)
{
  return (sonic->topo == NULL);
}

void topo(Pilha *sonic, void *destino)
{
  memcpy(destino, sonic->topo->dado, sonic->tam_elem);
}

void destroiPilha(Pilha *sonic) {
  if (sonic->topo != NULL) {

    No *atual = sonic->topo;
    No *prox = atual->prox;

    for (atual = sonic->topo; atual != NULL; atual = prox) {
      prox = atual->prox;
      free(atual->dado);
      free(atual);
    }
  }

  free(sonic);
}
