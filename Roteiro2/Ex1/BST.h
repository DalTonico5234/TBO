#ifndef BST_h
#define BST_h

typedef struct bst BST;

BST *constructBST();

void insertKey(BST *tree, int key);

int height(BST *tree);

void freeBST(BST *tree);

#endif