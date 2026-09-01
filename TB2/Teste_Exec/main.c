#include "sistema.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Insira os argumentos de entrada adequados\n");
        exit(3);
    }

    Sistema *system = createSistema(argv[1]);

    leStopWords(system);
    lePaginas(system);
    lePalavras(system);
    leGraph(system);

    calculaPageRanks(system);
    
    roda_consultas(system);

    liberaSistema(system);
}