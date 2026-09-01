#ifndef _ESPACO_H
#define _ESPACO_H

#include "Aresta.h"

/**
 * Trabalho 1 TBO - Minimum Spanning Tree
 * Trabalho desenvolvido pelos alunos João Arthur Subtil, Leonardo Roxo e Mateo Chisthe
 * da turma de Técnicas de Busca e Ordenação 26/1 - Eng. Comp
 *
 * Data: 15/05/2026
 */


/**
 * @brief Tamanho inicial do vetor de vértices e incremento a cada realocação.
 */
#define TAM_VET 50


/**
 * @brief Controla a impressão dos tempos de cada etapa do algoritmo na saída padrão.
 * Quando 1, imprime os tempos na seguinte ordem:
 *   1. Leitura dos dados e geração dos vértices
 *   2. Cálculo das distâncias (geração das arestas)
 *   3. Construção do heap mínimo
 *   4. Obtenção da MST (Kruskal com Union-Find)
 *   5. Identificação dos grupos e escrita do arquivo de saída
 *   6. Desalocação de memória
 *   7. Tempo total do algoritmo
 */
#define PRINTA_TEMPO 0


/**
 * @brief Estrutura que agrega todos os dados do problema: vértices, arestas,
 * dimensão do espaço e número de clusters desejados.
 */
typedef struct espaco Espaco;


/**
 * @brief Aloca e inicializa o espaço métrico lendo os vértices do arquivo de
 * entrada e gerando todas as arestas entre eles. Ao retornar, o heap mínimo
 * já está construído e pronto para o algoritmo de Kruskal.
 *
 * @param k Número de clusters desejados na solução final.
 * @param caminho_entrada Caminho para o arquivo CSV de entrada com os vértices.
 * @return Um ponteiro para o Espaco inicializado, ou NULL em caso de falha.
 */
Espaco *criaEspaco(int k, char *caminho_entrada);


/**
 * @brief Lê o arquivo CSV de entrada, infere o número de dimensões pela
 * primeira linha e popula o vetor de vértices do espaço, realocando-o
 * conforme necessário em blocos de TAM_VET.
 *
 * @param caminho_entrada Caminho para o arquivo CSV de entrada.
 * @param space O espaço a ser populado com os vértices lidos.
 */
void leVertices(char *caminho_entrada, Espaco *space);


/**
 * @brief Cria todas as n*(n-1)/2 arestas entre os vértices do espaço e
 * constrói o heap mínimo sobre elas para uso pelo algoritmo de Kruskal.
 *
 * @param space O espaço cujas arestas serão geradas e organizadas.
 */
void geraArestas(Espaco *space);


/**
 * @brief Cria todas as n*(n-1)/2 arestas entre os vértices do espaço e
 * constrói o heap mínimo sobre elas para uso pelo algoritmo de Kruskal.
 *
 * @param space O espaço cujas arestas serão geradas e organizadas.
 */
void kruskal(Espaco *space);


/**
 * @brief Escreve o resultado da clusterização no arquivo de saída. Vértices
 * do mesmo cluster são separados por vírgula e clusters distintos por
 * quebra de linha.
 *
 * @param space O espaço com a clusterização já calculada.
 * @param caminho_saida Caminho para o arquivo de saída a ser gerado.
 */
void imprimeResultado(Espaco *space, char *caminho_saida);


/**
 * @brief Libera toda a memória alocada para o espaço, incluindo o vetor de
 * arestas, cada vértice individualmente e a estrutura do espaço em si.
 *
 * @param space O espaço a ser liberado.
 */
void liberaEspaco(Espaco *space);

#endif