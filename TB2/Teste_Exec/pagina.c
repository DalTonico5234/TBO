#include "pagina.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHA 0.85

struct Pagina
{
    char *nome;
    FILE *page;
    double oldPageRank;
    double pageRank;
    int numOut;
    tPagina **Out;
    int numIn;
    Lista *In;
    double variacao;
};

char *getNome(tPagina *p)
{
    return p->nome;
}

double getPageRank(tPagina *p)
{
    return p->pageRank;
}

double getOldPageRank(tPagina *p)
{
    return p->oldPageRank;
}

int getNumOut(tPagina *p)
{
    return p->numOut;
}

double getDiffPageRank(tPagina *p)
{
    if (p->pageRank >= p->oldPageRank)
    {
        return p->pageRank - p->oldPageRank;
    }

    return p->oldPageRank - p->pageRank;
}

int getNumIn(tPagina *p)
{
    return p->numIn;
}

void incrementaNumIn(tPagina *p)
{
    p->numIn++;
}

void incrementaNumOut(tPagina *p)
{
    p->numOut++;
}

tPagina *criaPagina(char *nome, char *diretorio)
{

    tPagina *pagina = (tPagina *)malloc(sizeof(tPagina));

    pagina->nome = strdup(nome);
    pagina->numOut = 0;
    pagina->numIn = 0;
    pagina->In = inicializaLista();
    pagina->variacao = -1.0;

    char *page_title = (char *)malloc((strlen(diretorio) + strlen(nome) + 1) * sizeof(char));

    strcpy(page_title, diretorio);
    strcat(page_title, nome);

    pagina->page = fopen(page_title, "r");

    if (pagina->page == NULL)
    {
        perror("Erro na abertura da página");
        exit(1);
    }

    free(page_title);

    pagina->pageRank = 0.0;
    pagina->oldPageRank = 0.0;

    return pagina;
}

void insereLink(tPagina *page, tPagina *link, int indice)
{
    if (link != NULL)
    {
        page->Out[indice] = link;
    }
}

void inserePageIn(tPagina *page, tPagina *link)
{
    if (link != NULL)
        insereFinalLista((void *)link, page->In);
}

void setPageRank(void *pag, double pageRank)
{
    tPagina *p = (tPagina *)pag;
    p->pageRank = pageRank;
    p->oldPageRank = pageRank;
}

void congelaPageRank(void *pag)
{
    tPagina *p = (tPagina *)pag;
    p->oldPageRank = p->pageRank;
}

void calculaPageRank(void *pag, double num_paginas)
{
    tPagina *p = (tPagina *)pag;

    p->pageRank = 0;

    Celula *atual = getPrimLista(p->In);
    while (atual != NULL)
    {
        tPagina *j = (tPagina *)getItemCelula(atual);
        p->pageRank += (double)j->oldPageRank / (double)j->numOut;
        atual = getProxCel(atual);
    }
    p->pageRank *= ALPHA;

    p->pageRank += (1 - ALPHA) / num_paginas;

    if (p->numOut == 0)
    {
        p->pageRank += ALPHA * p->oldPageRank;
    }
}

void setNumOut(tPagina *pagina, int numOut)
{

    if (pagina == NULL)
        return;

    pagina->numOut = numOut;
    pagina->Out = (tPagina **)malloc(numOut * sizeof(tPagina *));

    for (int i = 0; i < pagina->numOut; i++)
    {
        pagina->Out[i] = NULL;
    }
}

void lePagina(tPagina *p, tRBT **arvore_palavras, tRBT *arvore_stopwords)
{
    char buffer[TAM_MAX_PALAVRA];

    while (fscanf(p->page, " %s", buffer) != EOF)
    {
        Value *valor = tRBT_busca(arvore_stopwords, buffer);

        if (valor == NULL)
        {                        
            *arvore_palavras = tRBT_insert(*arvore_palavras, buffer, p, VETOR);
        }
    }
}

void liberaPagina(void *pag)
{
    tPagina *p = (tPagina *)pag;

    liberaLista(p->In);
    free(p->nome);
    fclose(p->page);
    free(p->Out);
    free(p);
}

void imprimePagina(void *p)
{
    tPagina *pag = (tPagina *)p;
    if (pag == NULL)
    {
        return;
    }
    printf("Página: %s - Rank: %.8lf\n", pag->nome, pag->pageRank);
}

int comparaPaginas(const void *a, const void *b)
{
    tPagina *pag1 = *(tPagina **) a;
    tPagina *pag2 = *(tPagina **) b;

    if (pag1->pageRank != pag2->pageRank)
    {
        if (pag1->pageRank > pag2->pageRank)
            return 1;
        return -1;
    }

    else
    {
        return strcmp(pag1->nome, pag2->nome);
    }
}