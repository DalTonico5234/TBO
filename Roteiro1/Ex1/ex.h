#ifndef ex
#define ex

#include <stdio.h>
#include <stdlib.h>

typedef struct sieve Sieve;

Sieve *construct(int N);

void marcar_numeros(Sieve *sieve);

void print_primos(Sieve *sieve);

void destruct(Sieve *sieve);

#endif