#ifndef _ARESTA_H
#define _ARESTA_H

#include "Vertice.h"

/**
 * Trabalho 1 TBO - Minimum Spanning Tree
 * Trabalho desenvolvido pelos alunos João Arthur Subtil, Leonardo Roxo e Mateo Chisté
 * da turma de Técnicas de Busca e Ordenação 26/1 - Eng. Comp
 * 
 * Data: 15/05/2026
 */


/**
 * @brief Estrutura que representa uma aresta entre dois vértices do espaço métrico.
 */
typedef struct Aresta Aresta;


/**
 * @brief Aloca e preenche um vetor com todas as arestas possíveis entre os n
 * vértices fornecidos. Para cada par (i, j) com i < j, cria uma aresta com
 * os índices dos vértices e o quadrado da distância euclidiana entre eles.
 *
 * @param v Vetor de ponteiros para os vértices do espaço.
 * @param qnt_arestas Número total de arestas a serem criadas (n*(n-1)/2).
 * @param n Número de vértices.
 * @param m Número de dimensões do espaço.
 * @return Um ponteiro para o vetor de Aresta alocado, ou NULL em caso de falha.
 */
Aresta *criaArestas(Vertice **v, int qnt_arestas, int n, int m);


/**
 * @brief Imprime o peso da aresta de índice i na saída padrão.
 *
 * @param a O vetor de arestas.
 * @param i O índice da aresta a ser impressa.
 */
void imprimeTam(Aresta *a, int i);


/**
 * @brief Retorna o peso (quadrado da distância euclidiana) da aresta de índice i.
 *
 * @param a O vetor de arestas.
 * @param i O índice da aresta consultada.
 * @return O peso da aresta como valor em ponto flutuante.
 */
double getTam(Aresta *a, int i);


/**
 * @brief Retorna o índice do primeiro vértice da aresta de índice i.
 *
 * @param a O vetor de arestas.
 * @param i O índice da aresta consultada.
 * @return O índice do vértice v1 no vetor de vértices do espaço.
 */
int getV1(Aresta *a, int i);


/**
 * @brief Retorna o índice do segundo vértice da aresta de índice i.
 *
 * @param a O vetor de arestas.
 * @param i O índice da aresta consultada.
 * @return O índice do vértice v2 no vetor de vértices do espaço.
 */
int getV2(Aresta *a, int i);


/**
 * @brief Função de comparação utilizada pelo `qsort` para ordenar arestas
 * em ordem crescente de peso.
 *
 * @param a Ponteiro para a primeira aresta a ser comparada.
 * @param b Ponteiro para a segunda aresta a ser comparada.
 * @return Valor negativo, zero ou positivo conforme a ordem relativa.
 */
int comparaDistancias(const void *a, const void *b);


/**
 * @brief Constrói um heap mínimo in-place sobre o vetor de arestas,
 * organizando-o de forma que a aresta de menor peso esteja sempre na
 * posição 0. Utilizado antes das extrações sucessivas pelo algoritmo
 * de Kruskal.
 *
 * @param a O vetor de arestas a ser heapificado.
 * @param n O número de arestas no vetor.
 */
void constroiHeap(Aresta *a, int n);


/**
 * @brief Remove a aresta de menor peso (posição 0) do heap, substituindo-a
 * pela última aresta ativa e restaurando a propriedade de heap mínimo.
 * Deve ser chamada com o tamanho atual do heap já decrementado pelo chamador.
 *
 * @param a O vetor de arestas organizado como heap mínimo.
 * @param n O novo tamanho do heap após a remoção.
 */
void extraiMinimo(Aresta *a, int n);


/**
 * @brief Libera a memória alocada para o vetor de arestas.
 *
 * @param a O vetor de arestas a ser liberado.
 */
void liberaAresta(Aresta *a);

#endif