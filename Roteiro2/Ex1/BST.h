#ifndef BST_h
#define BST_h

typedef struct bst BST;

typedef void(*visit)(BST*);

BST *constructBST();

void insertKey(BST *tree, int key);

int height(BST *tree);

void recursive_pre_order_transveral(BST *tree, void (*visit)(BST *));

void recursive_in_order_transveral(BST *tree, void (*visit)(BST*));

void recursive_post_order_transveral(BST *tree, void (*visit)(BST *));

void print(BST *tree);

void freeBST(BST *tree);

#endif