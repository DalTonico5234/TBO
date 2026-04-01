#include "tester.h"
#include "BST.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct tester
{
    int N;
    BST *tree;
};

Tester *constructTester(int N)
{
    Tester *test = (Tester *) malloc (sizeof(Tester));
    
    test->tree = constructBST();

    test->N = N;

    srand(time(NULL));
    for (int i=0; i < test->N; i++)
    {
        insertKey(test->tree, rand());
    }

    return test;
}

void printTree(Tester *test)
{
    recursive_pre_order_transveral(test->tree, print);
}

void printHeight(Tester *test)
{
    printf("%d\n", height(test->tree));
}

void freeTester(Tester *test)
{
    freeBST(test->tree);
    
    free(test);
}
