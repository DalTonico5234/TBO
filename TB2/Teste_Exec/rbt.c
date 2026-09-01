#include "rbt.h"

#define RED true
#define BLACK false

struct RBT
{
    Key chave;
    tRBT *esq;
    tRBT *dir;
    bool color;
    void *valor;
    int size;
    TIPO_DADO tipo;
};

tRBT *create_node(Key key, Value val, bool color, TIPO_DADO tipo)
{
    tRBT *node = (tRBT *)malloc(sizeof(tRBT));

    node->chave = strdup(key);
    node->valor = val;
    node->color = color;
    node->esq = NULL;
    node->dir = NULL;
    node->size = 0;
    node->tipo = tipo;

    if(tipo == VETOR){
        node->valor = inicializaLista();
        insereFinalLista(val, node->valor);
    }

    return node;
}

bool is_red(tRBT *arv)
{
    if (arv == NULL)
        return BLACK;
    return arv->color;
}

tRBT *rotate_left(tRBT *arv)
{

    tRBT *dir = arv->dir;

    arv->dir = dir->esq;
    dir->esq = arv;
    dir->color = dir->esq->color;
    dir->esq->color = RED;

    return dir;
}

tRBT *rotate_right(tRBT *arv)
{

    tRBT *esq = arv->esq;

    arv->esq = esq->dir;
    esq->dir = arv;
    esq->color = esq->dir->color;
    esq->dir->color = RED;

    return esq;
}

void flip_colors(tRBT *arv)
{

    arv->color = RED;
    arv->esq->color = BLACK;
    arv->dir->color = BLACK;
}

void *tRBT_busca(tRBT *h, Key key)
{
    while (h != NULL)
    {
        int cmp;
        cmp = strcasecmp(key, h->chave);
        if (cmp < 0)
            h = h->esq;
        else if (cmp > 0)
            h = h->dir;
        else{
            return h->valor;
        }
    }
    return NULL;
}

tRBT *tRBT_insert(tRBT *h, Key key, Value val, TIPO_DADO tipo)
{
    if (h == NULL)
    {
        return create_node(key, val, RED, tipo);
    }

    int cmp = strcasecmp(key, h->chave);

    if (cmp < 0)
    {
        h->esq = tRBT_insert(h->esq, key, val, tipo);
    }
    else if (cmp > 0)
    {
        h->dir = tRBT_insert(h->dir, key, val, tipo);
    }
    else
    {
        if(tipo == DADO)
            h->valor = val;
        else if(tipo == VETOR){
            insereFinalLista(val, h->valor);
        }
    }

    if (is_red(h->dir) && !is_red(h->esq))
    {
        h = rotate_left(h);
    }
    if (is_red(h->esq) && is_red(h->esq->esq))
    {
        h = rotate_right(h);
    }
    if (is_red(h->esq) && is_red(h->dir))
    {
        flip_colors(h);
    }

    return h;
}

void percorre_arvore(tRBT *raiz, visitNode visit)
{
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL)
        percorre_arvore(raiz->esq, visit);
    if (raiz->dir != NULL)
        percorre_arvore(raiz->dir, visit);

    visit(raiz->valor);
}

void percorre_lePaginas(tRBT *raiz, tRBT **palavras, tRBT *stopwords)
{
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL)
        percorre_lePaginas(raiz->esq, palavras, stopwords);
    if (raiz->dir != NULL)
        percorre_lePaginas(raiz->dir, palavras, stopwords);

    lePagina(raiz->valor, palavras, stopwords);
}

void percorre_arvore_num(tRBT *raiz, double num, visitNodeNum visit)
{
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL)
        percorre_arvore_num(raiz->esq, num, visit);
    if (raiz->dir != NULL)
        percorre_arvore_num(raiz->dir, num, visit);

    visit(raiz->valor, num);
}

void calculateEk(tRBT *raiz, double *ek){
    
    if(raiz == NULL) return;

    if (raiz->esq != NULL)
        calculateEk(raiz->esq, ek);
    if (raiz->dir != NULL)
        calculateEk(raiz->dir, ek);

    *ek += getDiffPageRank(raiz->valor);
}

    int arv_vazia(tRBT *a)
{
    return (a == NULL);
}

void liberaArvore(tRBT *raiz, freeItem fLibera)
{
    if (raiz == NULL)
        return;

    if (raiz->esq != NULL)
        liberaArvore(raiz->esq, fLibera);
    if (raiz->dir != NULL)
        liberaArvore(raiz->dir, fLibera);

    if (fLibera != NULL)
    {
        fLibera(raiz->valor);
    }

    free(raiz->chave);
    free(raiz);
}

void imprimirArvore(tRBT *raiz, int nivel)
{
    // Condição de parada
    if (raiz == NULL){
        return;
    }


    // Vai para a subárvore da direita primeiro
    imprimirArvore(raiz->dir, nivel + 1);

    // Imprime espaços correspondentes ao nível atual
    for (int i = 0; i < nivel; i++)
    {
        printf("    ");
    }

    // Imprime o valor do nó atual
    printf("%s : paginas : \n", raiz->chave);
    if(raiz->tipo == VETOR)
        imprimeLista(raiz->valor, imprimePagina);

    // Vai para a subárvore da esquerda
    imprimirArvore(raiz->esq, nivel + 1);
}

tRBT *inicializaRubroNega()
{
    tRBT *r = (tRBT *)malloc(sizeof(tRBT));

    r->esq = r->dir = NULL;
    r->chave = NULL;
    r->valor = NULL;

    return r;
}