#ifndef pagina_h
#define pagina_h

#include "rbt.h"
#include "lista.h"

#define TAM_MAX_PALAVRA 128

typedef struct RBT tRBT;
typedef struct Pagina tPagina;

/**
 * @brief Cria uma página completa, exceto pelos seus links.
 * @param nome Nome da página criada (string)
 * @param diretorio Caminho para a página 
 * @return Uma nova página inicializada
 */
tPagina *criaPagina(char *nome, char *diretorio);

/**
 * @brief Insere o link para outra página no vetor de apontamentos
 de uma página.
 * @param page Página que fará o apontamento
 * @param link Página que será apontada
 * @param indice
 */
void insereLink(tPagina *page, tPagina *link, int indice);

/**
 * @brief Calcula a diferença entre o page rank antigo e o atual.
 * @param page A página.
 * @return Double Valor da diferença.
 */
double getDiffPageRank(tPagina *p);

/**
 * @brief Cria e inicializa a lista de páginas apontadas, e seta a qtd de páginas apontadas.
 * @param page A página.
 * @param int A quantidade de páginas apontadas.
 */
void setNumOut(tPagina *page, int numOut);

/**
* @brief Libera toda a memória usada por uma página, incluindo as listas que ela guarda.
* @param page A página.
 */
void liberaPagina(void *pag);

/**
 * @brief Imprime o nome e o page rank da página.
 * @param page A página.
 */
void imprimePagina(void *p);

/**
 * @brief Obtém o nome da página.
 * @param page A página.
 * @return char O nome da página.
 */
char *getNome(tPagina *p);

/**
 * @brief Obtém a quantidade de apontamentos da página.
 * @param page A página.
 * @return int A quantidade de apontamentos da página.
 */
int getNumLinks(tPagina *p);

/**
 * @brief Obtém a quantidade de páginas que apontam pra página atual.
 * @param page A página.
 * @return int A quantidade de páginas que apontam pra página atual.
 */
int getNumIn(tPagina *p);

/**
 * @brief Obtém o page rank da página.
 * @param page A página.
 * @return double O page rank da página.
 */
double getPageRank(tPagina *p);

/**
 * @brief Seta os page ranks antigo e atual da página com o valor passado.
 * @param page A página.
 * @param double O page rank.
 */
void setPageRank(void *pag, double pageRank);

/**
 * @brief Faz o cálculo do page rank da página.
 * @param page A página.
 * @param double O número total de páginas.
 */
void calculaPageRank(void *pag, double num_paginas);

/**
 * @brief Incrementa o número de páginas que apontam para a página atual.
 * @param p Página que terá seu número de apontamentos incrementado
 */
void incrementaNumIn(tPagina *p);

/**
 * @brief Incrementa o número de páginas que a página atual aponta.
 * @param p Página que terá seu número de apontamentos incrementado
 */
void incrementaNumOut(tPagina *p);

/**
 * @brief Insere uma página na lista de páginas apontadas de outra página.
 * @param page Página que fará o apontamento
 * @param link Página que será apontada
 */
void inserePageIn(tPagina *page, tPagina *link);

/**
 * @brief Congela o page rank da página, ou seja, seta o page rank antigo com o valor do page rank atual.
 * @param page Página a ser congelada
 */
void congelaPageRank(void *page);

/**
 * @brief Le uma página e insere suas palavras na árvore de palavras, ignorando as stopwords.
 * @param p Página a ser lida
 * @param arvore_palavras Árvore de palavras onde as palavras da página serão inseridas
 * @param arvore_stopwords Árvore de stopwords que serão ignoradas na inserção
 */
void lePagina(tPagina *p, tRBT **arvore_palavras, tRBT *arvore_stopwords);

/*
 * @brief Compara duas páginas pelo seu page rank.
 * @param a Ponteiro para a primeira página
 * @param b Ponteiro para a segunda página
 * @return int 1 se a primeira página tem page rank maior, -1 se a segunda página tem page rank maior, 0 se forem iguais
 */
int comparaPaginas(const void *a, const void *b);

#endif