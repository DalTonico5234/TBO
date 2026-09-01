/**
 * @file lista.h
 * @author Davi Santos de Araujo Boni
 * @brief Definição das estruturas de lista e célula e das funções que gerenciam uma lista duplamente encadeada genérica.
 * @version 0.1
 * @date 2025-07-03
 * * @copyright Copyright (c) 2025
 * */

#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pagina.h"

typedef void (*ImprimeItem)(void *);

typedef struct celula Celula;

// Definição de tipos para uso na lista genérica
#define PAGINA 0

typedef struct lista Lista;

/**
 * @brief Aloca e inicializa uma nova lista vazia.
 * * @return Lista* Ponteiro para a nova lista criada.
 */
Lista* inicializaLista();

/**
 * @brief Obtém a primeira célula de uma lista.
 * * @param l A lista.
 * @return Celula* Ponteiro para a primeira célula, ou NULL se a lista estiver vazia.
 */
Celula *getPrimLista(Lista *l);

/**
 * @brief Obtém a próxima célula na lista.
 * * @param p A célula atual.
 * @return Celula* Ponteiro para a próxima célula.
 */
Celula *getProxCel(Celula *p);

/**
 * @brief Obtém o tipo do dado armazenado em uma célula.
 * * @param p A célula.
 * @return int O tipo do item (LEITOR, LIVRO, etc.).
 */
int getTipoCelula(Celula *p);

/**
 * @brief Obtém o ponteiro para o item (dado) armazenado em uma célula.
 * * @param p A célula.
 * @return void* Ponteiro genérico para o item.
 */
void *getItemCelula(Celula *p);

/**
 * @brief Insere um item genérico no final da lista.
 * * @param item O item a ser inserido.
 * @param l A lista onde o item será inserido.
 * @param tipo O tipo do item que está sendo inserido.
 * @return Lista* Ponteiro para a lista.
 */
Lista* insereFinalLista(void *item, Lista *l);

/**
 * @brief Remove o primeiro item da lista.
 * * @param l A lista.
 * @return void* Ponteiro para o item removido.
 */
void *removeInicioLista(Lista *l);

/**
 * @brief Imprime os itens de uma lista em um arquivo, formatando de acordo com o tipo.
 * * @param l A lista a ser impressa.
 * @param tipo O tipo dos itens na lista para formatação correta.
 * @param saida O arquivo de saída.
 */
void imprimeLista(Lista *l, ImprimeItem fImpressao);

/**
 * @brief Libera toda a memória usada por uma lista, incluindo suas células e os itens que elas contêm.
 * * @param l A lista a ser liberada.
 * @param tipo O tipo dos itens para saber como liberá-los corretamente.
 */
void liberaLista(void *list);

/**
 * @brief Libera apenas as células de uma lista, sem liberar os itens para os quais elas apontam.
 * * @param l A lista cujas células serão liberadas.
 */
void liberaCelulas(Lista *l);

/**
 * @brief Conta a qtd de elementos da lista.
 * * @param p A lista.
 * @return int Tamanho da lista.
 */
int getTamLista(Lista *l);

/**
 * @brief Verifica se um item está presente na lista.
 * @param l Lista a ser verificada.
 * @param item Item a ser procurado na lista.
 * @return int 1
 */
int estaNaLista(Lista *l, void *item);

#endif