#include "quick_v2.h"
#include <stdlib.h>

int partition(Item *a, int lo, int hi)
{
    int i = lo, j = hi + 1;
    Item v = a[lo];
    while (1)
    {
        while (less(a[++i], v)) // Encontra o item a esquerda para a troca
            if (i == hi)
                break;
        while (less(v, a[--j])) // Encontra o item a direita para a troca
            if (j == lo)
                break;
        if (i >= j)
            break; // Verifica se o ponteiros se cruzaram
        exch(a[i], a[j]);
    }
    exch(a[lo], a[j]); // Troca com o item do particionamento
    return j;          // O elemento que está na posição correta
}

void quick_sort(Item *a, int lo, int hi)
{
    if (hi - lo + 1 <= CUTOFF)
    {
        insertion_sort(a, lo, hi);
        return;
    }
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

void sort(Item *a, int lo, int hi)
{
    quick_sort(a, lo, hi);
}