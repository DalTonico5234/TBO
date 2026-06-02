#include "bin_heap.h"
#include <stdlib.h>

struct heap
{
    void **array;
    int MAX;
    int N;
    compareF compare;
};

Heap *create_heap(int MAX_N, compareF compare)
{
    Heap *heap = (Heap *)malloc(sizeof(Heap));

    heap->compare = compare;

    heap->MAX = MAX_N;
    heap->N = 0;
    heap->array = (void **)calloc(heap->MAX, sizeof(void *));

    return heap;
}

void heap_insert(Heap *heap, void *element)
{
    if (heap->N >= heap->MAX)
        return;

    heap->array[(heap->N)++] = element;

    heapifyUp(heap, heap->N - 1);
}

void *heap_remove(Heap *heap)
{
    if (heap->N == 0)
        return NULL;
    
    void *min = heap->array[0];

    heap->array[0] = heap->array[--heap->N];    

    if (heap->N > 0)
        heapifyDown(heap, 0);

    return min;
}

void heapifyUp(Heap *heap, int idx)
{
    int idfather = (idx - 1) / 2;

    while (idx > 0 && (heap->compare(heap->array[idfather], heap->array[idx]) < 0))
    {
        void *temp = heap->array[idx];
        heap->array[idx] = heap->array[idfather];
        heap->array[idfather] = temp;
        idx = idfather;
        idfather = (idx - 1) / 2;
    }
}

void heapifyDown(Heap *heap, int idx)
{
    int id_left_child;
    while ((id_left_child = (2 * idx + 1)) < heap->N)
    {
        if (id_left_child + 1 < heap->N &&
            (heap->compare(heap->array[id_left_child], heap->array[id_left_child + 1]) < 0))
            id_left_child++;

        if ((heap->compare(heap->array[idx], heap->array[id_left_child]) >= 0))
            break;

        void *temp = heap->array[idx];
        heap->array[idx] = heap->array[id_left_child];
        heap->array[id_left_child] = temp;
        idx = id_left_child;
    }
}

bool is_empty_heap(Heap *heap)
{
    return (heap->N == 0);
}

int heap_size(Heap *heap)
{
    return heap->N;
}

void destroy_heap(Heap *heap)
{
    free(heap->array);
    free(heap);
}