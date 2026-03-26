#ifndef ex_h
#define ex_h

typedef struct circulo Jose;

/**
 * @brief Constrói um objeto do tipo Círculo, guardando também o valor de M
 * @param N número inicial de pessoas
 * @param M ordem da pessoa eliminada
 * @return Círculo alocado e inicializado
 */
Jose *construct(int N, int M);

/**
 * @brief Retira uma pessoa do círculo e a retorna
 * @param circulo O círculo com os candidatos
 * @return Pessoa eliminada
 */
int elimina_pessoa(Jose *circulo);

/**
 * @brief Passa por todas as pessoas do círculo, eliminando cada uma e determinando o vencedor
 * @param circulo O círculo com os candidatos
 * @return Pessoa eleita
 */
// int eleicao(Jose *circulo);

void imprimeCirculo(Jose *circulo);

/**
 * @brief Desaloca a memória de um círculo
 * @param circulo O círculo a ser desalocado
 */
void destruct(Jose *circulo);

#endif