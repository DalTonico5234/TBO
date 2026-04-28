#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("ERRO: parâmetros insuficientes\n");
        return 1;
    }
    
    int N = atoi(argv[argc-1]);
    
    Item *array = (Item *) calloc (N, sizeof(Item));

    for (int i=0; i < N; i++)
    {
        scanf("%d\n", &array[i]);
    }

    clock_t inicio = clock();
    sort(array, 0, N-1);
    clock_t fim = clock();
    double tempo = (double)((double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%.4lf\n", tempo);

    // for (int i=0; i < N; i++)
    // {
    //     printf("%d\n", array[i]);
    // }

    free(array);

    return 0;
}