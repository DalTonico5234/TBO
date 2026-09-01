#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta.h"
#include "pagina.h"

static Lista *intersecao(Lista *lista_base, Lista *lista_nova)
{
    tRBT *temp = NULL;
    Celula *cel = getPrimLista(lista_nova);

    while (cel != NULL)
    {
        tPagina *p = (tPagina *)getItemCelula(cel);
        temp = tRBT_insert(temp, getNome(p), p, DADO);
        cel = getProxCel(cel);
    }

    Lista *resultado = inicializaLista();
    cel = getPrimLista(lista_base);

    while (cel != NULL)
    {
        tPagina *p = (tPagina *)getItemCelula(cel);
        if (tRBT_busca(temp, getNome(p)) != NULL)
        {
            insereFinalLista((void *)p, resultado);
        }
        cel = getProxCel(cel);
    }

    liberaArvore(temp, NULL);

    return resultado;
}

tPagina **criaVetorPaginas(Lista *list)
{
    if (getTamLista(list) == 0)
    {
        return NULL;
    }

    int i = 0;
    tPagina **vetor = malloc(getTamLista(list) * sizeof(tPagina *));
    Celula *p = getPrimLista(list);

    while (p != NULL)
    {
        vetor[i++] = (tPagina *)getItemCelula(p);
        p = getProxCel(p);
    }
    return vetor;
}

char *leConsulta(FILE *search)
{
    char *linha = NULL;
    size_t tam = 0;

    if (getline(&linha, &tam, search) == -1)
    {
        free(linha);
        if (feof(search))
            return NULL;
        
        if (ferror(search))
        {
            perror("Failed to get line");
            exit(2);
        }
    }

    return linha;
}

Lista *processaConsulta(tRBT *arvore_stopwords, tRBT *arvore_palavras, char *linha)
{
 
    char *copia_linha = strdup(linha);

    Lista *final = NULL;
    char *palavra = strtok(copia_linha, " \t\n\r");
    
    while(palavra != NULL){

        // Se a palavra for uma stopword (ignora o resto do loop)
        if(tRBT_busca(arvore_stopwords, palavra) != NULL){
            palavra = strtok(NULL, " \t\n\r");
            continue;
        }
        Lista *lista_paginas = (Lista*)tRBT_busca(arvore_palavras, palavra);

        // Lista não encontrada
        if(lista_paginas == NULL){
            if(final != NULL){
                liberaLista(final);
            }

            final = inicializaLista();
            break;
        }
        
        // Se for a primeira palavra da busca
        if(final == NULL){
            final = inicializaLista();
            Celula *cel = getPrimLista(lista_paginas);
            while(cel != NULL){
                insereFinalLista(getItemCelula(cel), final);
                cel = getProxCel(cel);
            }
            palavra = strtok(NULL, " \t\n\r");
        }
        // Já existe uma palavra na busca
        else{
            Lista *atual = intersecao(final, lista_paginas);
            liberaLista(final);
            final = atual;
            palavra = strtok(NULL, " \t\n\r");
        }
    }

    free(copia_linha);
    
    return final;
}

void imprimeResultado(Lista *final, char *linha){

    int tam = getTamLista(final);

    printf("search:%s", linha);
    printf("pages:");

    tPagina **vetor = criaVetorPaginas(final);
    qsort(vetor, tam, sizeof(tPagina*), comparaPaginas);

    for(int i = 0; i < tam; i++){
        printf("%s", getNome(vetor[i]));
        if (i != tam-1)
            printf(" ");
    }

    printf("\npr:");

    for(int i = 0; i < tam; i++){
        printf("%.17lf", getPageRank(vetor[i]));
        if (i != tam-1)
            printf(" ");
    }
    printf("\n");

    free(vetor);
}