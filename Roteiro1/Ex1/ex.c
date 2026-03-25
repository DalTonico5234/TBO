#include "ex.h"

struct sieve
{
    int *marcadores;
    int N;
};

Sieve *construct(int N)
{
    Sieve *new = (Sieve *)malloc(sizeof(Sieve));

    new->N = N;
    new->marcadores = (int *)calloc(N + 1, sizeof(int));

    for (int i = 2; i <= new->N; i++)
    {
        new->marcadores[i] = 0;
    }

    return new;
}

void marcar_numeros(Sieve *sieve)
{
    for (int i = 2; i <= sieve->N; i++)
    {
        if (!sieve->marcadores[i])
        {
            for (int j = 2 * i; j <= sieve->N; j += i)
            {
                if (!(j % i)) // multiplo
                {
                    sieve->marcadores[j] = 1;
                }
            }
        }
    }
}

void print_primos(Sieve *sieve)
{
    for (int i = 2; i <= sieve->N; i++)
    {
        if (!(sieve->marcadores[i]))
        {
            printf("Primo: %d\n", i);
        }
    }
}

void destruct(Sieve *sieve)
{
    free(sieve->marcadores);
    free(sieve);
}
