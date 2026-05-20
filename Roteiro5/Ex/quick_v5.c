#include "quick_v5.h"
#include <stdlib.h>
#include <math.h>

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
    Stack *sonic = stack_init(2*log2(hi - lo + 1));
    push2(sonic, lo, hi);
    while (!stack_empty(sonic))
    {
        lo = pop(sonic);
        hi = pop(sonic);
        if (hi <= lo)
            continue; // Could add cutoff here.
        int i = partition(a, lo, hi);
        if (i - lo > hi - i)
        {                     // Test the size of sub-arrays.
            push2(sonic, lo, i - 1); // Push the larger one.
            push2(sonic, i + 1, hi); // Sort the smaller one first.
        }
        else
        {
            push2(sonic, i + 1, hi);
            push2(sonic, lo, i - 1);
        }
    }
    free_stack(sonic);
}

void sort(Item *a, int lo, int hi)
{
    quick_sort(a, lo, hi);
}