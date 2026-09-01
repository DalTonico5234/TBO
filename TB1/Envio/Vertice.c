#include "Vertice.h"

struct Vertice
{
  double *coord;            //Vetor de coordenadas no espaço m-dimensional */
  char *id;                 //Identificador textual do vértice */
  struct Vertice *pai;      //Pai no conjunto disjunto (Union-Find) */
  int tam_arvore;           //Tamanho do conjunto, usado na união por tamanho */
  struct Vertice *primeiro; // Vértice com menor id lexicográfico do conjunto */
};

Vertice *criaVertice(char *id, double *coord, int m)
{

  Vertice *v = (Vertice *)malloc(sizeof(Vertice));
  v->id = strdup(id);
  v->coord = (double *)malloc(m * sizeof(double));
  for (int i = 0; i < m; i++)
  {
    v->coord[i] = coord[i];
  }

// Inicializa o vértice como raiz e único membro do seu próprio conjunto
  v->tam_arvore = 1;
  v->pai = v;
  v->primeiro = v;
  
  return v;
}

void imprimeId(Vertice *v) { printf("%s", v->id); }

double *getCoord(Vertice *v) { return v->coord; }

char *getId(Vertice *v) { return v->id; }

Vertice *encontraRaiz(Vertice *v)
{
  if (v->pai == v)
  {
    return v;
  }
  /* Aponta o pai diretamente para a raiz,
     achatando a árvore e acelerando buscas futuras */
  return v->pai = encontraRaiz(v->pai);
}

void uneVertices(Vertice *pai, Vertice *filho)
{
  Vertice *temp1 = encontraRaiz(pai);
  Vertice *temp2 = encontraRaiz(filho);
  
  //O conjunto menor é anexado ao maior, mantendo a árvore achatada
  if (temp1->tam_arvore < temp2->tam_arvore)
  {
    temp1->pai = temp2;
    temp2->tam_arvore += temp1->tam_arvore;

    //Propaga o menor id lexicográfico para a raiz do conjunto resultante
    if (strcmp(temp1->primeiro->id, temp2->primeiro->id) < 0){
      temp2->primeiro = temp1->primeiro;
    }
  }

  else
  {
    temp2->pai = temp1;
    temp1->tam_arvore += temp2->tam_arvore;
    if (strcmp(temp1->primeiro->id, temp2->primeiro->id) > 0){
      temp1->primeiro = temp2->primeiro;
    }
  }
}

int comparaRaiz(Vertice *v1, Vertice *v2)
{
  return (encontraRaiz(v1) == encontraRaiz(v2));
}

int comparaPorNome(const void *a, const void *b){
    Vertice *v1 = *(Vertice **)a;
    Vertice *v2 = *(Vertice **)b;
    Vertice *raiz1 = encontraRaiz(v1);
    Vertice *raiz2 = encontraRaiz(v2);
    
    /* Vértices de clusters diferentes são ordenados pelo menor id do cluster;
     vértices do mesmo cluster são ordenados pelo próprio id */
    if (raiz1!=raiz2)
        return strcmp(raiz1->primeiro->id, raiz2->primeiro->id);
    else
        return strcmp(v1->id,v2->id);
}

double calculaEuclides(Vertice *v1, Vertice *v2, int m)
{
    double soma = 0;
    double *coord1 = v1->coord;
    double *coord2 = v2->coord;

    for (int i = 0; i < m; i++)
    {
        double prod = coord1[i] - coord2[i];
        soma += prod*prod;
    }
    //double tam = sqrt(soma);

    return soma;
}

void liberaVertice(Vertice *v)
{
  free(v->id);
  free(v->coord);
  free(v);
}