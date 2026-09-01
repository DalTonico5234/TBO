#include "Espaco.h"

int main(int argc, char *argv[])
{
  clock_t start_main, end_main;
  start_main = clock();

  clock_t start, end;
  double time;

  if (argc != 4)
  {
    fprintf(stderr, "ERRO: uso deve ser \"./trab1 <nome_arquivo_entrada> k <nome_arquivo_saida>\"\n");
    exit(1);
  }

  char *caminho_entrada = argv[1];
  int k = atoi(argv[2]);
  char *caminho_saida = argv[3];

  if (k <= 0)
  {
    fprintf(stderr, "ERRO: k inválido (deve ser um inteiro maior que 0)!\n");
    exit(1);
  }
  // Imprime os argumentos recebidos para facilitar a identificação do teste
  if (PRINTA_TEMPO)
  {
    for (int i=0; i < argc; i++)
    {
      printf("%s ", argv[i]);
    }
    printf("\n");
  }

  Espaco *space = criaEspaco(k, caminho_entrada);

  if (PRINTA_TEMPO)
    start = clock();

  kruskal(space);

  if (PRINTA_TEMPO)
  {
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.4f\n", time);
  }

  if (PRINTA_TEMPO)
    start = clock();

  imprimeResultado(space, caminho_saida);

  if (PRINTA_TEMPO)
  {
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.4f\n", time);
  }

  if (PRINTA_TEMPO)
    start = clock();

  liberaEspaco(space);

  if (PRINTA_TEMPO)
  {
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("%.4f\n", time);
  }

  //Tempo total medido do início da main até após a liberação de memória
  if (PRINTA_TEMPO)
  {
    end_main = clock();
    time = (double)(end_main - start_main) / CLOCKS_PER_SEC;
    printf("%.4f\n", time);
  }

}