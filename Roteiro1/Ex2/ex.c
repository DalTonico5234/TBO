#include "ex.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct no No;

struct no
{
    int pessoa;
    No *proximo;
};

struct circulo
{
    No *atual;
    int M;
};

/**
 * @brief Constrói um objeto do tipo Círculo, guardando também o valor de M
 * @param N número inicial de pessoas
 * @param M ordem da pessoa eliminada
 * @return Círculo alocado e inicializado
 */
Jose *construct(int N, int M)
{
    Jose *circulo = (Jose *)malloc(sizeof(Jose));

    circulo->M = M;
   
    No *first = (No *) malloc (sizeof(No));
    No *atual = first;
    int i =0;
    for (i; i < N-1; i++)
    {
        atual->proximo = (No *) malloc (sizeof(No));
        atual->pessoa = i+1;
        atual = atual->proximo;
    }

    atual->proximo = first;
    atual->pessoa = i+1;

    circulo->atual = first;

    return circulo;
}

/**
 * @brief Retira uma pessoa do círculo e a retorna
 * @param circulo O círculo com os candidatos
 * @return Pessoa eliminada
 */
int elimina_pessoa(Jose *circulo)
{
    for (int i = 0; i < circulo->M - 2; i++)
    {
        circulo->atual = circulo->atual->proximo;
    }
    No *eliminado = circulo->atual->proximo;
    int pessoa = eliminado->pessoa;

    circulo->atual->proximo = circulo->atual->proximo->proximo;

    circulo->atual = circulo->atual->proximo;

    free(eliminado);

    return pessoa;
}

/**
 * @brief Passa por todas as pessoas do círculo, eliminando cada uma e determinando o vencedor
 * @param circulo O círculo com os candidatos
 * @return Pessoa eleita
 */
// int eleicao(Jose *circulo)
// {

// }

void imprimeCirculo(Jose *circulo)
{
    No *first = circulo->atual;
    printf("%d ", first->pessoa);
    for (No *atual = first->proximo; atual != first; atual = atual->proximo)
    {
        printf("%d ", atual->pessoa);
    }
    printf("\n");
}

/**
 * @brief Desaloca a memória de um círculo
 * @param circulo O círculo a ser desalocado
 */
void destruct(Jose *circulo)
{
    free(circulo->atual);
    free(circulo);
}