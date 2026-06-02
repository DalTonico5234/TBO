#ifndef BIN_HEAP_H
#define BIN_HEAP_H

typedef struct heap Heap;

#include <stdbool.h>

typedef char (*compareF)(void *a, void *b);

/**
 * @brief create a minHeap structure with MAX_N capacity of generic elements
 * @param MAX_N heap's capacity
 * @return minHeap allocated and empty
 */

Heap *create_heap(int MAX_N, compareF compare);

/**
 * @brief Insert an element in the heap and fix the array to be consistent
 * @param heap where to insert
 * @param element what to insert
 */
void heap_insert(Heap *heap, void *element);

/**
 * @brief Remove an element from the heap and fix the array to be consistent
 * @param heap where to remove
 * @return the element removed
 */
void *heap_remove(Heap *heap);

/**
 * @brief Fix the array, moving the element of index idx up until it reaches its correct position
 * @param heap the structure to fix
 * @param idx the index of the element out of position
 */
void heapifyUp(Heap *heap, int idx);

/**
 * @brief Fix the array, moving the element of index idx down until it reaches its correct position
 * @param heap the structure to fix
 * @param idx the index of the element out of position
 */
void heapifyDown(Heap *heap, int idx);

/**
 * @brief Verify if a heap structure has no elements
 * @param heap the structure to be verified
 * @return 1 case the heap is empty, else 0
 */
bool is_empty_heap(Heap *heap);

/**
 * @brief Return the number of elements in a heap
 * @param heap the heap structure
 * @return number of elements currently in heap
 */
int heap_size(Heap *heap);



/**
 * @brief free all the memory associated to the Heap structure (but not its elements)
 * @param heap structure to be freed
 */
void destroy_heap(Heap *heap);

#endif