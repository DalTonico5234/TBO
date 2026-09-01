#include "sistema.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "consulta.h"
#include "lista.h"
#include "pagina.h"
#include "rbt.h"

struct sistema
{
    tRBT *stopwords;
    tRBT *palavras;
    tRBT *paginas;
    double tamanho_arvore_paginas;
    char *caminho_raiz;
};

Sistema *createSistema(char *caminho_diretorio)
{
    Sistema *system = (Sistema *)malloc(sizeof(Sistema));

    system->tamanho_arvore_paginas = 0;
    system->caminho_raiz = caminho_diretorio;

    system->stopwords = NULL;
    system->paginas = NULL;
    system->palavras = NULL;

    return system;
}

void leStopWords(Sistema *system)
{
    char *caminho = strdup(system->caminho_raiz);
    caminho = (char *)realloc(caminho, (strlen(caminho) + strlen("stopwords.txt") + 1) * sizeof(char));
    strcat(caminho, "stopwords.txt");

    FILE *stopwords = fopen(caminho, "r");
    if (stopwords == NULL)
    {
        perror("Failed to open stopwords.txt");
        exit(1);
    }
    free(caminho);

    char words[TAM_MAX_PALAVRA];

    while (fscanf(stopwords, " %s\n", words) != EOF)
    {
        system->stopwords = tRBT_insert(system->stopwords, words, words, DADO);
    }

    fclose(stopwords);
}

void lePalavras(Sistema *system)
{
    percorre_lePaginas(system->paginas, &system->palavras, system->stopwords);
}

void lePaginas(Sistema *system)
{
    char *caminho = strdup(system->caminho_raiz);
    caminho = (char *)realloc(caminho, (strlen(caminho) + strlen("index.txt") + 1) * sizeof(char));
    strcat(caminho, "index.txt");
    char *entrada = strdup(system->caminho_raiz);
    entrada = (char *)realloc(entrada, (strlen(entrada) + strlen("/pages/") + 1) * sizeof(char));
    strcat(entrada, "/pages/");

    FILE *index = fopen(caminho, "r");
    if (index == NULL)
    {
        perror("Failed to open index.txt");
        exit(1);
    }
    free(caminho);

    char titulo[TAM_MAX_PALAVRA];

    while (fscanf(index, "%s\n", titulo) != EOF)
    {
        tPagina *page = criaPagina(titulo, entrada);
        system->paginas = tRBT_insert(system->paginas, titulo, page, DADO);
        system->tamanho_arvore_paginas++;
    }

    free(entrada);
    fclose(index);
}

void leGraph(Sistema *system)
{
    char *caminho = strdup(system->caminho_raiz);
    caminho = (char *)realloc(caminho, (strlen(caminho) + strlen("graph.txt") + 1) * sizeof(char));
    strcat(caminho, "graph.txt");

    FILE *graph = fopen(caminho, "r");
    if (graph == NULL)
    {
        perror("Failed to open graph.txt");
        exit(1);
    }
    free(caminho);

    char titulo[TAM_MAX_PALAVRA];

    while (fscanf(graph, "%s\n", titulo) != EOF)
    {
        tPagina *pagina_atual = (tPagina *)tRBT_busca(system->paginas, titulo);

        int qtd_links = 0;
        fscanf(graph, " %d", &qtd_links);
        setNumOut(pagina_atual, qtd_links);

        for (int i = 0; i < qtd_links; i++)
        {
            char links[TAM_MAX_PALAVRA];
            fscanf(graph, " %s", links);
            tPagina *pagina_linkada = (tPagina *) tRBT_busca(system->paginas, links);
            incrementaNumIn(pagina_linkada);
            insereLink(pagina_atual, pagina_linkada, i);
            inserePageIn(pagina_linkada, pagina_atual);
        }
    }

    fclose(graph);
}

void calculaPageRanks(Sistema *system)
{
    percorre_arvore_num(system->paginas, 1 / system->tamanho_arvore_paginas, setPageRank);

    double ek = 1 / system->tamanho_arvore_paginas;

    while (ek >= epsilon)
    {
        ek = 1 / system->tamanho_arvore_paginas;
        double variable = 0.0;
        percorre_arvore(system->paginas, congelaPageRank);
        percorre_arvore_num(system->paginas, system->tamanho_arvore_paginas, calculaPageRank);
        calculateEk(system->paginas, &variable);
        ek *= variable;
    }
}

void roda_consultas(Sistema *system)
{
    char *caminho = strdup(system->caminho_raiz);
    caminho = (char *)realloc(caminho, (strlen(caminho) + strlen("searches.txt") + 1) * sizeof(char));
    strcat(caminho, "searches.txt");

    FILE *search = fopen(caminho, "r");
    if (search == NULL)
    {
        perror("Failed to open search.txt");
        exit(1);
    }
    free(caminho);

    char *linha;
    while (1)
    {
        linha = leConsulta(search);
        if (linha == NULL)
            break;
        Lista *result = processaConsulta(system->stopwords, system->palavras, linha);
        imprimeResultado(result, linha);
        free(linha);
        liberaLista(result);
    }

    fclose(search);
}

void liberaSistema(Sistema *system)
{
    liberaArvore(system->paginas, liberaPagina);
    liberaArvore(system->stopwords, NULL);
    liberaArvore(system->palavras, liberaLista);
    free(system);
}
