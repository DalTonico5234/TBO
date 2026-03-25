#include "ex1.h"

struct sieve
{
    char *marcadores;
    int N;
};

Sieve *construct(int N)
{
    Sieve *new = (Sieve*) malloc (sizeof(Sieve));

    new->N = N;
    new->marcadores = (char *) calloc (N+1, sizeof(char));

    for (int i=2; i <= new->N; i++)
    {
        new->marcadores[i] = 0;
    }

    return new;
}

void marcar_numeros(Sieve *sieve)
{
    for (int i=2; i <= sieve->N; i++)
    {
        for (int j=i+1; j <= sieve->N; j++)
        {
            if (!(j % i)) //multiplo
            {
                sieve->marcadores[j] = 1;
            }
        }
    }
}

void print_primos(Sieve *sieve)
{
    for (int i=2; i <= sieve->N; i++)
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

