#include "BST.h"
#include <stdlib.h>
#include <stdio.h>

struct bst
{
    int data;
    BST *left;
    BST *right;
};

BST *constructBST(int value)
{
    BST *new = (BST *)malloc(sizeof(BST));

    new->left = NULL;
    new->right = NULL;
    new->data = value;

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
            tree->left = constructBST(key);
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
            tree->right = constructBST(key);
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
        return (leftHeight + 1);
    }
    else
    {
        return (rightHeight + 1);
    }
}

void recursive_pre_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {
        visit(tree);
        recursive_pre_order_transveral(tree->left, visit);
        recursive_pre_order_transveral(tree->right, visit);
    }
}

void recursive_in_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {
        recursive_in_order_transveral(tree->left, visit);
        visit(tree);
        recursive_in_order_transveral(tree->right, visit);
    }
}

void recursive_post_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {
        recursive_post_order_transveral(tree->left, visit);
        recursive_post_order_transveral(tree->right, visit);
        visit(tree);
    }
}

void iterative_pre_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {

        Pilha *sonic = criaPilha(sizeof(BST *));

        BST *current = tree;

        empilha(sonic, &current);
        while (!ehPilhaVazia(sonic))
        {
            desempilha(sonic, &current);
            visit(current);
            if (current->right != NULL)
            {
                empilha(sonic, &current->right);
            }
            if (current->left != NULL)
            {
                empilha(sonic, &current->left);
            }
        }
        destroiPilha(sonic);
    }
}

void iterative_in_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {
        Pilha *sonic = criaPilha(sizeof(BST *));

        BST *current = tree;

        while (!ehPilhaVazia(sonic) || current != NULL)
        {
            if (current != NULL)
            {
                empilha(sonic, &current);
                current = current->left;
            }
            else
            {
                desempilha(sonic, &current);
                visit(current);
                current = current->right;
            }
        }
        destroiPilha(sonic);
    }
}

void iterative_post_order_transveral(BST *tree, void (*visit)(BST *))
{
    if (tree != NULL)
    {
        Pilha *sonic = criaPilha(sizeof(BST *));

        BST *lastNodeVisited = NULL;

        BST *current = tree;

        BST *peekNode;

        while (!ehPilhaVazia(sonic) || current != NULL)
        {
            if (current != NULL)
            {
                empilha(sonic, &current);
                current = current->left;
            }
            else
            {
                topo(sonic, &peekNode);
                if (peekNode->right != NULL && lastNodeVisited != peekNode->right)
                {
                    current = peekNode->right;
                }
                else
                {
                    visit(peekNode);
                    desempilha(sonic, &lastNodeVisited);
                }
            }
        }

        destroiPilha(sonic);
    }
}

void print(BST *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
    }
}

void justVisit(BST *tree)
{
    if (tree != NULL)
    {
        return;
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