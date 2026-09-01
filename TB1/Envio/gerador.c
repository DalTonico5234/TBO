// /*
//  * gera_teste.c
//  * Gerador de casos de teste para o trab1.
//  *
//  * Uso: ./gera_teste <n> <m> <arquivo_saida> [semente]
//  *   n             -> quantidade de pontos
//  *   m             -> dimensão de cada ponto
//  *   arquivo_saida -> nome do arquivo a ser gerado
//  *   semente       -> (opcional) semente para reprodutibilidade. Se omitida, usa o tempo atual.
//  *
//  * Exemplo de uso:
//  *   ./gera_teste 10 2 entrada.txt
//  *   ./gera_teste 10 2 entrada.txt 42
//  */

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// int main(int argc, char *argv[])
// {
//     if (argc < 4 || argc > 5)
//     {
//         fprintf(stderr, "Uso: %s <n> <m> <arquivo_saida> [semente]\n", argv[0]);
//         fprintf(stderr, "  n             -> quantidade de pontos\n");
//         fprintf(stderr, "  m             -> dimensão de cada ponto\n");
//         fprintf(stderr, "  arquivo_saida -> nome do arquivo a ser gerado\n");
//         fprintf(stderr, "  semente       -> (opcional) semente para reprodutibilidade\n");
//         return 1;
//     }

//     int n = atoi(argv[1]);
//     int m = atoi(argv[2]);
//     char *caminho = argv[3];

//     if (n <= 0)
//     {
//         fprintf(stderr, "ERRO: n deve ser um inteiro maior que 0.\n");
//         return 1;
//     }
//     if (m <= 0)
//     {
//         fprintf(stderr, "ERRO: m deve ser um inteiro maior que 0.\n");
//         return 1;
//     }

//     unsigned int semente = (argc == 5) ? (unsigned int)atoi(argv[4]) : (unsigned int)time(NULL);
//     srand(semente);

//     FILE *saida = fopen(caminho, "w");
//     if (saida == NULL)
//     {
//         fprintf(stderr, "ERRO: não foi possível criar o arquivo '%s'.\n", caminho);
//         return 1;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         /* Calcula o número de dígitos de n para formatar os IDs com zeros
//             à esquerda, garantindo ordenação lexicográfica correta (P01, P02...) */
//         int digitos = 1, temp = n;
//         while (temp >= 10) { digitos++; temp /= 10; }
//         fprintf(saida, "P%0*d", digitos, i);

//         /* Gera m coordenadas aleatórias no intervalo [0.0, 1000.0] */
//         for (int j = 0; j < m; j++)
//         {
//             double coord = (double)rand() / RAND_MAX * 1000.0;
//             fprintf(saida, ",%.4f", coord);
//         }

//         fprintf(saida, "\n");
//     }

//     fclose(saida);

//     printf("Arquivo '%s' gerado com %d pontos de dimensão %d (semente: %u).\n", caminho, n, m, semente);

//     return 0;
// }