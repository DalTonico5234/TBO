#ifndef BST_h
#define BST_h

#include "pilha.h"
#include "fila.h"

typedef struct bst BST;

typedef void(*visit)(BST*);

BST *constructBST(int value);

void insertKey(BST *tree, int key);

int height(BST *tree);

void recursive_pre_order_transveral(BST *tree, void (*visit)(BST *));

void recursive_in_order_transveral(BST *tree, void (*visit)(BST*));

void recursive_post_order_transveral(BST *tree, void (*visit)(BST *));

void iterative_pre_order_transveral(BST *tree, void (*visit)(BST *));

void iterative_in_order_transveral(BST *tree, void (*visit)(BST *));

void iterative_post_order_transveral(BST *tree, void (*visit)(BST *));

void level_order_transversal(BST *tree, void (*visit)(BST *));

void print(BST *tree);

void justVisit(BST *tree);

void freeBST(BST *tree);

#endif