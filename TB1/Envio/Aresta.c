#include "Aresta.h"

struct Aresta
{
    int v1;      //Índice do primeiro vértice no vetor de vértices do espaço
    int v2;      //Índice do segundo vértice no vetor de vértices do espaço
    double tam;  //Quadrado da distância euclidiana entre v1 e v2
};

Aresta *criaArestas(Vertice **v, int qnt_arestas, int n, int m)
{
    Aresta *a = (Aresta *)malloc(qnt_arestas*sizeof(Aresta));
    if(!a) exit(0);
    int l = 0;

    /* Itera sobre todos os pares (i, j) com i < j para gerar
       cada aresta exatamente uma vez, sem repetições */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
                a[l].v1 = i;
                a[l].v2 = j;
                a[l].tam = calculaEuclides(v[i], v[j] , m);
                l++;
        }
    }

    return a;
}

void imprimeTam(Aresta *a, int i)
{
    printf("%f", a[i].tam);
}

double getTam(Aresta *a, int i)
{
    return a[i].tam;
}

int getV1(Aresta *a, int i)
{
    return a[i].v1;
}

int getV2(Aresta *a, int i)
{
    return a[i].v2;
}

size_t getTamAresta(){
    return sizeof(Aresta);
}


int comparaDistancias(const void *a, const void *b)
{
    Aresta *a1 = (Aresta *)a;
    Aresta *a2 = (Aresta *)b;

    if (a1->tam > a2->tam)
        return 1;
    else if (a1->tam == a2->tam)
        return 0;
    else
        return -1;
}

void heapDesce(Aresta *a, int i, int n)
{
    while (1)
    {
        int menor = i;
        int esq = 2 * i + 1;
        int dir = 2 * i + 2;

        //Identifica o menor entre o nó atual e seus dois filhos
        if (esq < n && a[esq].tam < a[menor].tam) menor = esq;
        if (dir < n && a[dir].tam < a[menor].tam) menor = dir;
        
        //Se o nó já é o menor do trio, a propriedade de heap está restaurada
        if (menor == i) break;

        Aresta temp  = a[i];
        a[i]        = a[menor];
        a[menor]    = temp;
        i = menor;
    }
}

void constroiHeap(Aresta *a, int n)
{
    /* Heapifica de baixo para cima a partir do último nó interno,
       garantindo a propriedade de heap mínimo em O(n) */
    for (int i = n / 2 - 1; i >= 0; i--)
        heapDesce(a, i, n);
}

void extraiMinimo(Aresta *a, int n)
{
    /* Move a última aresta ativa para a raiz e restaura o heap.
       O chamador já decrementou n antes desta chamada */
    a[0] = a[n];
    heapDesce(a, 0, n);
}

void liberaAresta(Aresta *a)
{
    free(a);
}
