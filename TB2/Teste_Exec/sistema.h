#ifndef sistema_h
#define sistema_h

#define epsilon 1e-6

typedef struct sistema Sistema;

/**
 * @brief Cria uma estrutura contendo todas as tabelas de símbolos e
 * o tamanho da árvore de páginas.
 * @param caminho_diretorio String para a pasta raiz onde todos os arquivos
 * estão localizados
 * @return Uma estrutura com todos os atributos citados.
 */
Sistema *createSistema(char *caminho_diretorio);

/**
 * @brief Lê o arquivo de stopwords e armazena as palavras em uma tabela de símbolos
 * 
 * @param system Os sistema contendo a tabela de símbolos de stopwords
 */
void leStopWords(Sistema *system);

/**
 * @brief Lê os arquivos index.txt, abre todas as páginas 
 * e armazena as palavras em uma tabela de símbolos
 * 
 * @param system Os sistema contendo as tabela de símbolos 
 */
void lePaginas(Sistema *system);

/**
 * @brief Lê o arquivo de palavras e armazena as palavras em uma tabela de símbolos
 * 
 * @param system O sistema contendo a tabela de símbolos de palavras
 */
void lePalavras(Sistema *system);

/**
 * @brief Lê o arquivo de links e armazena as ligações entre as páginas em uma tabela de símbolos
 * 
 * @param system O sistema contendo a tabela de símbolos de links
 */
void leGraph(Sistema *system);

/**
 * @brief Calcula o PageRank de todas as páginas do sistema
 * 
 * @param system O sistema    
 */
void calculaPageRanks(Sistema *system);

/**
 * @brief Faz o processamento de todas as linhas do arquivo searches, buscando as palavras e imprimindo as páginas que as contém
 * 
 * @param system O sistema
 */
void roda_consultas(Sistema *system);

/**
 * @brief Libera a memória alocada para o sistema
 * 
 * @param system Sistema a ser liberado
 */
void liberaSistema(Sistema *system);

#endif