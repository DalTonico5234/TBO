#include "Espaco.h"

struct espaco
{
    Vertice **vertices;  //Vetor de ponteiros para os vértices lidos da entrada */
    Aresta *arestas;     // Vetor de todas as arestas entre os vértices */
    int qtd_arestas;     // Total de arestas: n*(n-1)/2 */
    int n;               // Número de vértices lidos */
    int m;               // Número de dimensões do espaço */
    int k;               // Número de clusters desejados */
};

Espaco *criaEspaco(int k, char *caminho_entrada)
{
    Espaco *space = (Espaco *)malloc(sizeof(Espaco));

    /* m começa em -1 pois a contagem de colunas inclui o ID,
    que não é uma dimensão, ao fim do loop m terá o valor correto */
    space->n = 0;
    space->m = -1;
    space->k = k;

    clock_t start, end;
    double time;

    if (PRINTA_TEMPO)
        start = clock();

    leVertices(caminho_entrada, space);

    if (PRINTA_TEMPO)
    {
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%.4f\n", time);
    }

    geraArestas(space);

    return space;
}

void leVertices(char *caminho_entrada, Espaco *space)
{
    FILE *entrada = fopen(caminho_entrada, "r");
    if (entrada == NULL)
    {
        fprintf(stderr, "ERRO: <nome_arquivo_entrada> inválido!\n");
        exit(1);
    }

    space->vertices = (Vertice **)calloc(TAM_VET, sizeof(Vertice *));

    char *input = NULL;
    size_t buffer = 0;

    /* Lê a primeira linha para inferir o número de dimensões contando
    as vírgulas, depois rebobina para processar os dados normalmente */
    if (getline(&input, &buffer, entrada) != -1)
    {
        char *pedaco = strtok(input, ",");
        while (pedaco != NULL)
        {
            (space->m)++;
            pedaco = strtok(NULL, ",");
        }
        rewind(entrada);
    }
    else
    {
        fprintf(stderr, "ERRO: arquivo de entrada vazio!\n");
        exit(2);
    }

    char *ID;
    char *ch_coord;
    double coords[(space->m)];

    while (getline(&input, &buffer, entrada) != -1)
    {
        ID = strtok(input, ",");

        for (int i = 0; i < space->m; i++)
        {
            ch_coord = strtok(NULL, ",");
            coords[i] = atof(ch_coord);
        }

        Vertice *v = criaVertice(ID, coords, space->m);
        
        /* Realoca o vetor em blocos de TAM_VET sempre que estiver cheio,
           evitando realocações a cada novo vértice */
        if ((space->n) % TAM_VET == 0 && space->n > 0)
            space->vertices = realloc(space->vertices, sizeof(Vertice *) * ((space->n) + TAM_VET));
        space->vertices[(space->n)] = v;
        (space->n)++;
    }

    free(input);
    fclose(entrada);
}

void geraArestas(Espaco *space)
{
    //Fórmula de combinação C(n,2): número de pares únicos entre n vértices
    space->qtd_arestas = (((space->n - 1) * space->n) / 2);

    clock_t start, end;
    double time;

    if (PRINTA_TEMPO)
        start = clock();

    space->arestas = criaArestas(space->vertices, space->qtd_arestas, space->n, space->m);

    if (PRINTA_TEMPO)
    {
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%.4f\n", time);
    }

    if (PRINTA_TEMPO)
        start = clock();

    constroiHeap(space->arestas, space->qtd_arestas);

    if (PRINTA_TEMPO)
    {
        end = clock();
        time = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%.4f\n", time);
    }
}

void kruskal(Espaco *space)
{
    int j = 0;
    int final_heap = space->qtd_arestas;

    /* Executa n-k uniões para obter exatamente k clusters:
       cada união reduz o número de componentes em 1, partindo de n */
    while (j < (space->n - space->k))
    {
        Vertice *v1 = space->vertices[getV1(space->arestas, 0)];
        Vertice *v2 = space->vertices[getV2(space->arestas, 0)];

        /* Só une se os vértices estiverem em componentes distintos,
           evitando ciclos na MST */
        if (!comparaRaiz(v1, v2))
        {
            uneVertices(v1, v2);
            j++;
        }

        /* Remove o mínimo do heap independentemente da união ter ocorrido */
        final_heap--;
        extraiMinimo(space->arestas, final_heap);
    }
    qsort(space->vertices, space->n, sizeof(Vertice *), comparaPorNome);
}

void imprimeResultado(Espaco *space, char *caminho_saida)
{
    FILE *saida = fopen(caminho_saida, "w");
    if (saida == NULL)
    {
        fprintf(stderr, "ERRO: <nome_arquivo_saida> inválido!\n");
        exit(1);
    }
    Vertice *raiz_atual = encontraRaiz(space->vertices[0]);
    Vertice *raiz;
    for (int i = 0; i < space->n; i++)
    {
        fprintf(saida, "%s", getId(space->vertices[i]));

        if (i + 1 < space->n)
        {
            raiz = encontraRaiz(space->vertices[i + 1]);
        }
        else
        {
            break;
        }

        // Mesmo cluster: separa por vírgula; cluster diferente: quebra de linha
        if (raiz == raiz_atual)
        {
            fprintf(saida, ",");
        }
        else
        {
            fprintf(saida, "\n");
            raiz_atual = raiz;
        }
    }
    fclose(saida);
}

void liberaEspaco(Espaco *space)
{
    liberaAresta(space->arestas);
    for (int i = 0; i < space->n; i++)
    {
        liberaVertice(space->vertices[i]);
    }
    free(space->vertices);
    free(space);
}