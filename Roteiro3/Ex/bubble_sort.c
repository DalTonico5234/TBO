#include "bubble_sort.h"

void sort(Item *a, int lo, int hi)
{
    for (int i=lo; i <= hi; i++)
    {
        char swapped = 0;
        for (int j=hi; j > i; j--)
        {
            if (less(a[j], a[j-1]))
            {
                exch(a[j], a[j-1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
}