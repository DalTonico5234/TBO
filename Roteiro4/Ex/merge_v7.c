#include "merge_v7.h"
#include "insertion_sort.h"
#include <stdlib.h>

#define CUTOFF 17

#define SZ2 (sz + sz)
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k = lo; k <= hi; k++) // Copiar o array para o auxiliar
    {
        aux[k] = a[k];
    }
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
            a[k] = aux[j++]; // Todos os elementos da esquerda são menores (roubar os da direita)
        else if (j > hi)
            a[k] = aux[i++]; // Todos os elementos da direita são menores (roubar os da esquerda)
        else if (less(aux[j], aux[i]))
            a[k] = aux[j++]; // elemento j é menor (roubar ele)
        else
            a[k] = aux[i++]; // elemento i é menor (roubar ele)
    }
}

void sort(Item *a, int lo, int hi)
{
    int N = (hi - lo) + 1;
    int y = N - 1;
    Item *aux = calloc(N, sizeof(Item));

    // Percorre o array fatiando-o em pedaços de tamanho CUTOFF e aplicando insertion_sort
    for (int i = lo; i <= hi; i += CUTOFF)
    {
        int end = i + CUTOFF - 1;
        insertion_sort(a, i, MIN(end, hi));
    }

    for (int sz = CUTOFF; sz < N; sz = SZ2) // Merge_sort em si
    {
        for (int i = lo; i <= N - sz; i += SZ2)
        {
            int mid = i + sz - 1;
            if (less(a[mid], a[mid + 1])) // Merge skip
                continue;
            int x = i + SZ2 - 1;
            merge(a, aux, i, i + sz - 1, MIN(x, y));
        }
    }

    free(aux);
}
