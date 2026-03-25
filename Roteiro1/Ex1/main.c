#include "ex.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    Sieve *sieve = construct(atoi(argv[1]));

    marcar_numeros(sieve);

    // print_primos(sieve);

    destruct(sieve);
}