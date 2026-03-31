#include "BST.h"
#include <stdlib.h>

struct bst
{
    int data;
    BST *left;
    BST *right;
};

BST *constructBST()
{
    BST *new = (BST *) malloc (sizeof(BST));

    new->left = NULL;
    new->right = NULL;
    new->data = 0;

    return new;
}

void insertKey(BST *tree, int key)
{
    if (tree->data == key)
    {
        return;
    }

    // Buscar na esquerda
    else if (key < tree->data)
    {
        if (tree->left == NULL)
        {
            tree->left = constructBST();
            tree->left->data = key;
        }
        else
        {
            insertKey(tree->left, key);
        }
    } 

    // Buscar na direita
    else if (tree->data < key)
    {
        if (tree->right == NULL)
        {
            tree->right = constructBST();
            tree->right->data = key;
        }
        else
        {
            insertKey(tree->right, key);
        }
    }
}

int height(BST *tree)
{
    if (tree == NULL)
    {
        return -1;
    }

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    if (leftHeight > rightHeight)
    {
        return (leftHeight+1);
    }
    else
    {
        return (rightHeight+1);
    }
}

void freeBST(BST *tree)
{
    if (tree == NULL)
    {
        return;
    }

    freeBST(tree->left);
    freeBST(tree->right);

    free(tree);
}