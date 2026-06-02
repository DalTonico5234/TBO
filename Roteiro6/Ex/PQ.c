#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "event.h"
#include "PQ.h"
#include "bin_heap.h"

struct pq
{
    Heap *heap;
};

/*
 * Cria uma nova fila de prioridade mínima com o limite de elementos informado.
 */
PQ *PQ_create(int max_N)
{
    PQ *pq = (PQ *)malloc(sizeof(PQ));

    pq->heap = create_heap(max_N, compare);

    return pq;
}

/*
 * Libera a memória da fila.
 */
void PQ_destroy(PQ *pq)
{
    while (!is_empty_heap(pq->heap))
    {
       heap_remove(pq->heap);
    }
    destroy_heap(pq->heap);
    free(pq);
}

/*
 * Insere o evento na fila segundo o seu tempo.
 */
void PQ_insert(PQ *pq, Event *e)
{
    heap_insert(pq->heap, e);
}

/*
 * Remove e retorna o evento mais próximo.
 */
Event *PQ_delmin(PQ *pq)
{

    return (Event *) heap_remove(pq->heap);
}

/*
 * Testa se a fila está vazia.
 */
bool PQ_is_empty(PQ *pq)
{
    return (is_empty_heap(pq->heap));
}

/*
 * Retorna o tamanho da fila.
 */
int PQ_size(PQ *pq)
{
    return (heap_size(pq->heap));
}
