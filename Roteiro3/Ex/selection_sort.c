#include "selection_sort.h"

void sort(Item *a, int lo, int hi)
{
    int iMin = 0;
    for (int i=lo; i <= hi; i++)
    {
        iMin = i;
        for (int j=i+1; j <= hi; j++)
        {
            if (less(a[j], a[iMin]))
            {
                iMin = j;
            }
        }
        exch(a[i], a[iMin]);
    }
}