#ifndef consulta_h
#define consulta_h

#include "pagina.h"
#include "lista.h"

/**
 * @brief Cria um vetor de páginas a partir de uma lista de páginas.
 * 
 * @param list Lista de páginas.
 * @return tPagina** Vetor de páginas.
 */
tPagina **criaVetorPaginas(Lista *list);

/**
 * @brief Lê uma consulta de um arquivo e retorna a linha lida.
 * 
 * @param search Arquivo de onde a consulta será lida.
 * @return char* Linha lida do arquivo.
 */
char *leConsulta(FILE *search);

/**
 * @brief Processa uma consulta, removendo stopwords e retornando uma lista de resultados.
 * 
 * @param arvore_stopwords Árvore de stopwords.
 * @param arvore_palavras Árvore de palavras.
 * @param linha Linha da consulta a ser processada.
 * @return Lista* Lista de resultados da consulta.
 */
Lista *processaConsulta(tRBT *arvore_stopwords, tRBT *arvore_palavras, char *linha);

/**
 * @brief Imprime o resultado de uma consulta em um arquivo.
 * 
 * @param final Lista de resultados da consulta.
 * @param linha Linha da consulta que gerou os resultados.
 */
void imprimeResultado(Lista *final, char *linha);

#endif