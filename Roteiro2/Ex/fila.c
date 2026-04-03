#include "fila.h"
#include <string.h>
#include <stdlib.h>

typedef struct no
{
    void *dado;
    struct no *prox;
} No;

struct fila
{
    No *primeiro;
    No *ultimo;
    size_t tam_elem;
};

Fila *criaFila(size_t tam_elem)
{
    Fila *posto = (Fila *)malloc(sizeof(Fila));

    posto->tam_elem = tam_elem;

    posto->primeiro = posto->ultimo = NULL;

    return posto;
}

void entra(Fila *posto, void *dado)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->dado = malloc(posto->tam_elem);
    memcpy(novo->dado, dado, posto->tam_elem);
    novo->prox = NULL;

    if (posto->primeiro == NULL)
    {
        posto->primeiro = posto->ultimo = novo;
    }
    else
    {
        posto->ultimo->prox = novo;
        posto->ultimo = novo;
    }
}

void sai(Fila *posto, void *destino)
{
    if (posto->primeiro != NULL)
    {
        No *morto = posto->ultimo;
        memcpy(destino, morto->dado, posto->tam_elem);

        No *prox = posto->primeiro->prox;
        free(posto->primeiro);
        posto->primeiro = prox;

        if (posto->primeiro == NULL)
            posto->ultimo = NULL;
    }
}

int ehFilaVazia(Fila *posto)
{
    return (posto->primeiro == NULL);
}

void primeiro(Fila *posto, void *destino)
{
    memcpy(destino, posto->primeiro->dado, posto->tam_elem);
}

void destroiFila(Fila *posto)
{
    if (posto->primeiro != NULL)
    {

        No *atual = posto->primeiro;
        No *prox = atual->prox;

        for (atual = posto->primeiro; atual != NULL; atual = prox)
        {
            prox = atual->prox;
            free(atual->dado);
            free(atual);
        }
    }

    free(posto);
}