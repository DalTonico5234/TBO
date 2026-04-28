#include "merge_v2.h"
#include "insertion_sort.h"
#include <stdlib.h>

#define CUTOFF 17

void merge(Item *a, Item *aux, int lo, int mid, int hi)
{
    for (int k=lo; k <= hi; k++) // Copiar o array para o auxiliar
    {
        aux[k] = a[k]; 
    }
    int i=lo, j = mid+1;
    for (int k=lo; k <= hi; k++)
    {
        if (i > mid) a[k] = aux[j++]; // Todos os elementos da esquerda são menores (roubar os da direita)
        else if (j > hi) a[k] = aux[i++]; // Todos os elementos da direita são menores (roubar os da esquerda)
        else if (less(aux[j], aux[i]))  a[k] = aux[j++]; // elemento j é menor (roubar ele)
        else a[k] = aux[i++]; // elemento i é menor (roubar ele)
    }
}

void merge_sort(Item *a, Item *aux, int lo, int hi)
{
    /* Se o array tem menos que CUTOFF elementos, é
    mais rápido fazer insertion_sort*/
    if (hi - lo + 1 <= CUTOFF)
    {
      insertion_sort(a, lo, hi);
      return;  
    }
    int mid = lo + (hi - lo)/2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);
}

void sort(Item *a, int lo, int hi)
{
    int n = (hi - lo) + 1;
    Item *aux = (Item *) calloc (n, sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);
}