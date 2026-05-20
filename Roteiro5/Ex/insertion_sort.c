#include "insertion_sort.h"

void insertion_sort(Item *a, int lo, int hi)
{
    for (int i=hi; i > lo; i--)
    {
        if (less(a[i], a[i-1]))
        {
            exch(a[i], a[i-1]);
        }
    }
    for (int i=lo+2; i <= hi; i++)
    {
        int j=i;
        Item saved = a[i];
        while(less(saved, a[j-1]))
        {
            a[j] = a[j-1];
            j--;
        }
        a[j] = saved;
    }
}