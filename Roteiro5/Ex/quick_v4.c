#include "quick_v4.h"
#include <stdlib.h>
#include <time.h>

int median_of_3(Item *a, int lo, int hi)
{
    srand(time(NULL));

    int idx1 = (rand() % (hi - lo + 1)) + lo;
    int idx2 = (rand() % (hi - lo + 1)) + lo;
    int idx3 = (rand() % (hi - lo + 1)) + lo;

    int a1 = a[idx1];
    int a2 = a[idx2];
    int a3 = a[idx3];

    if ((a1 <= a2 && a2 <= a3) || (a3 <= a2 && a2 <= a1))
        return idx2;
    else if ((a2 <= a1 && a1 <= a3) || (a3 <= a1 && a1 <= a2))
        return idx1;
    else
        return idx3;
}

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
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    int j = partition(a, lo, hi);
    quick_sort(a, lo, j - 1);
    quick_sort(a, j + 1, hi);
}

void sort(Item *a, int lo, int hi)
{
    quick_sort(a, lo, hi);
}