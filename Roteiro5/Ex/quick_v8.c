#include "quick_v8.h"
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

void quick_sort(Item *a, int lo, int hi)
{
    if (hi - lo + 1 <= CUTOFF)
    {
        insertion_sort(a, lo, hi);
        return;
    }
    int median = median_of_3(a, lo, hi);
    exch(a[lo], a[median]);
    Item v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt)
    {
        if (a[i] < v)
        {
            exch(a[lt], a[i]);
            lt++;
            i++;
        }
        else if (a[i] > v)
        {
            exch(a[i], a[gt]);
            gt--;
        }
        else
        {
            i++;
        }
    }
    quick_sort(a, lo, lt - 1);
    quick_sort(a, gt + 1, hi);
}

void sort(Item *a, int lo, int hi)
{
    quick_sort(a, lo, hi);
}