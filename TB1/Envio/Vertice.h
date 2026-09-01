#ifndef _VERTICE_H
#define _VERTICE_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Trabalho 1 TBO - Minimum Spanning Tree
 * Trabalho desenvolvido pelos alunos João Arthur Subtil, Leonardo Roxo e Mateo Chisté
 * da turma de Técnicas de Busca e Ordenação 26/1 - Eng. Comp
 * 
 * Data: 15/05/2026
 */

/**
 * @brief Estrutura que representa um vértice no espaço métrico.
 */
typedef struct Vertice Vertice;


/**
 * @brief Aloca e inicializa um novo vértice com o ID, coordenadas e
 * dimensão fornecidos. O vértice é inicializado como sua própria raiz,
 * com tamanho de árvore igual a 1.
 *
 * @param id String identificadora do vértice.
 * @param coord Vetor de coordenadas do vértice no espaço m-dimensional.
 * @param m Número de dimensões do espaço.
 * @return Um ponteiro para o Vertice recém-criado.
 */
Vertice *criaVertice(char *id, double *coord, int m);


/**
 * @brief Imprime o ID do vértice na saída padrão.
 *
 * @param v O vértice a ser impresso.
 */
void imprimeId(Vertice *v);


/**
 * @brief Retorna o vetor de coordenadas do vértice.
 *
 * @param v O vértice consultado.
 * @return Ponteiro para o vetor de coordenadas do vértice.
 */
double *getCoord(Vertice *v);


/**
 * @brief Retorna o ID do vértice.
 *
 * @param v O vértice consultado.
 * @return Ponteiro para o ID do vértice.
 */
char *getId(Vertice *v);


/**
 * @brief Encontra a raiz do conjunto ao qual o vértice pertence, aplicando
 * compressão de caminho para otimizar buscas futuras.
 *
 * @param v O vértice de partida da busca.
 * @return Um ponteiro para o vértice raiz do conjunto.
 */
Vertice* encontraRaiz(Vertice* v);


/**
 * @brief Une os conjuntos de dois vértices utilizando união por tamanho.
 * O conjunto menor é anexado ao maior. Em caso de empate, o segundo é
 * anexado ao primeiro. O campo `primeiro` da raiz resultante é atualizado
 * para manter o ID lexicograficamente menor do conjunto.
 *
 * @param pai Vértice cujo conjunto será o destino da união.
 * @param filho Vértice cujo conjunto será anexado.
 */
void uneVertices(Vertice* pai, Vertice* filho);


/**
 * @brief Verifica se dois vértices pertencem ao mesmo conjunto disjunto,
 * comparando suas raízes.
 *
 * @param v1 Primeiro vértice.
 * @param v2 Segundo vértice.
 * @return 1 se pertencem ao mesmo conjunto, 0 caso contrário.
 */
int comparaRaiz(Vertice* v1, Vertice* v2);


/**
 * @brief Função de comparação utilizada pelo `qsort` para ordenar um vetor de
 * ponteiros para vértices. A ordenação é feita primeiro pelo ID lexicograficamente
 * menor da raiz do conjunto e, em caso de empate, pelo ID do próprio vértice.
 *
 * @param a Ponteiro para o primeiro elemento (ponteiro para Vertice).
 * @param b Ponteiro para o segundo elemento (ponteiro para Vertice).
 * @return Valor negativo, zero ou positivo conforme a ordem relativa.
 */

int comparaPorNome(const void *a, const void *b);


/**
 * @brief Calcula o quadrado da distância euclidiana entre dois vértices em um
 * espaço m-dimensional.
 *
 * @param v1 Primeiro vértice.
 * @param v2 Segundo vértice.
 * @param m Número de dimensões do espaço.
 * @return O quadrado da distância euclidiana entre v1 e v2.
 */
double calculaEuclides(Vertice *v1, Vertice *v2, int m);

/**
 * @brief Libera toda a memória alocada para um vértice, incluindo seu
 * ID e seu vetor de coordenadas.
 *
 * @param v O vértice a ser liberado.
 */
void liberaVertice(Vertice *v);

#endif