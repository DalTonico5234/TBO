#ifndef rbt_h
#define rbt_h

#include "lista.h"
#include "pagina.h"
#include <stdbool.h>

typedef char* Key;
typedef void* Value;

typedef void (*freeItem)(Value);
typedef void (*visitNodeNum)(Value, double);
typedef void (*visitNode)(Value);

typedef struct RBT tRBT;

typedef enum
{
    DADO,
    VETOR
} TIPO_DADO;

/**
 * @brief Cria um nó da árvore rubro-negra com a chave, valor, cor e tipo de dado especificados.
 * 
 * @param key Chave do nó.
 * @param val Valor associado à chave.
 * @param color Cor do nó (true para vermelho, false para preto).
 * @param tipo Tipo de dado armazenado no nó (DADO ou VETOR).
 * @return tRBT* Árvore rubro-negra criada.
 */
tRBT *create_node(Key key,Value val, bool color, TIPO_DADO tipo);

/**
 * @brief Inicializa uma árvore rubro-negra vazia.
 * 
 * @return tRBT* Árvore rubro-negra inicializada.
 */
tRBT *inicializaRubroNega();

/**
 * @brief Rotaciona a árvore rubro-negra para a esquerda em relação ao nó especificado.
 * 
 * @param arv Árvore rubro-negra a ser rotacionada.
 * @return tRBT* Árvore rubro-negra após a rotação.
 */
tRBT* rotate_left(tRBT *arv);

/**
 * @brief Rotaciona a árvore rubro-negra para a direita em relação ao nó especificado.
 * 
 * @param arv Árvore rubro-negra a ser rotacionada.
 * @return tRBT* Árvore rubro-negra após a rotação.
 */
tRBT* rotate_right(tRBT *arv);

/**
 * @brief Insere um novo nó na árvore rubro-negra com a chave, valor e tipo de dado especificados.
 * 
 * @param h Árvore rubro-negra na qual o nó será inserido.
 * @param key Chave do nó a ser inserido.
 * @param val Valor associado à chave do nó a ser inserido.
 * @param tipo Tipo de dado armazenado no nó a ser inserido (DADO ou VETOR).
 * @return tRBT* 
 */
tRBT* tRBT_insert(tRBT *h, Key key, Value val, TIPO_DADO tipo);

/**
 * @brief Verifica se o nó especificado é vermelho.
 * 
 * @param x Árvore rubro-negra a ser verificada.
 * @return true Se o nó for vermelho.
 * @return false Se o nó for preto ou nulo.
 */
bool is_red(tRBT *x);

/**
 * @brief Inverte as cores do nó especificado e de seus filhos.
 * 
 * @param arv Árvore rubro-negra na qual as cores serão invertidas.
 */
void flip_colors(tRBT *arv);

/**
 * @brief Verifica se a árvore rubro-negra especificada está vazia.
 * 
 * @param a Árvore rubro-negra a ser verificada.
 * @return int 1 se a árvore estiver vazia, 0 caso contrário.
 */
int arv_vazia(tRBT *a);

/**
 * @brief Imprime a árvore rubro-negra em ordem, mostrando a chave, valor e cor de cada nó, com indentação de acordo com o nível do nó na árvore.
 * 
 * @param raiz Árvore rubro-negra a ser impressa.
 * @param nivel Nível atual na árvore (usado para indentação).
 */
void imprimirArvore(tRBT *raiz, int nivel);

/**
 * @brief Libera a memória ocupada pela árvore rubro-negra especificada, chamando a função de liberação de item fornecida para liberar os valores armazenados nos nós.
 * 
 * @param raiz Árvore rubro-negra a ser liberada.
 * @param fLibera Função de liberação de item a ser chamada para liberar os valores armazenados nos nós.
 */
void liberaArvore(tRBT *raiz, freeItem fLibera);

/**
 * @brief Busca um valor na árvore rubro-negra com a chave especificada.
 * 
 * @param h Árvore rubro-negra na qual a busca será realizada.
 * @param key Chave do valor a ser buscado.
 * @return void* Item encontrado na árvore com a chave especificada, ou NULL se não encontrado.
 */
void *tRBT_busca(tRBT *h, Key key);

/**
 * @brief Percorre a árvore rubro-negra, aplicando a função de visita fornecida a cada nó passando num como argumento da função.
 * 
 * @param raiz Árvore rubro-negra a ser percorrida.
 * @param num Valor numérico a ser passado para a função de visita.
 * @param visit Função de visita a ser aplicada a cada nó da árvore, recebendo o valor do nó e num como argumentos.
 */
void percorre_arvore_num(tRBT *raiz, double num, visitNodeNum visit);

/**
 * @brief Percorre a árvore rubro-negra, aplicando a função de visita fornecida a cada nó.
 * 
 * @param raiz Árvore rubro-negra a ser percorrida.
 * @param visit Função de visita a ser aplicada a cada nó da árvore, recebendo o valor do nó como argumento.
 */
void percorre_arvore(tRBT *raiz, visitNode visit);

/**
 * @brief Percorre as páginas da árvore rubro-negra, aplicando a função de visita fornecida a cada nó, e atualizando a árvore de palavras com base nas stopwords fornecidas.
 * 
 * @param raiz Árvore rubro-negra a ser percorrida.
 * @param palavras Árvore rubro-negra de palavras a ser atualizada com base nas stopwords.
 * @param stopwords Árvore rubro-negra de stopwords a ser usada para filtrar as palavras.
 */
void percorre_lePaginas(tRBT *raiz, tRBT **palavras, tRBT *stopwords);

/**
 * @brief Calcula o valor de ek para a árvore rubro-negra especificada, armazenando o resultado no ponteiro fornecido.
 * 
 * @param raiz Árvore rubro-negra para a qual o valor de ek será calculado.
 * @param ek Ponteiro para o local onde o valor de ek será armazenado.
 */
void calculateEk(tRBT *raiz, double *ek);


#endif