#include "ex.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    
    Jose *circulo = construct(N, M);

    int eliminado = 0;
    for (int i=0; i < N-1; i++)
    {
        eliminado = elimina_pessoa(circulo);
        // printf("%d\n", eliminado);
    }

    destruct(circulo);
}