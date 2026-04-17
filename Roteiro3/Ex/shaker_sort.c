#include "shaker_sort.h"

void sort(Item *a, int lo, int hi)
{
    char swapped = 1;

    while (swapped)
    {
        swapped = 0;
        for (int i=0; i < hi; i++)
        {
            if(less(a[i+1], a[i]))
            {
                exch(a[i], a[i+1]);
                swapped = 1;
            }
        }

        if (!swapped)
        {
            break;
        }

        hi--;
        swapped = 0;

        for (int i = hi-1; i >= lo; i--)
        {
            if(less(a[i+1], a[i]))
            {
                exch(a[i], a[i+1]);
                swapped = 1;
            }
        }

        lo++;
    }
}