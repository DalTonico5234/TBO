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
    Tester *test = (Tester *)malloc(sizeof(Tester));

    test->N = N;

    srand(time(NULL));

    if (N > 0)
    {
        test->tree = constructBST(rand());
    }

    for (int i = 1; i < test->N; i++)
    {
        insertKey(test->tree, rand());
    }

    return test;
}

void printTree(Tester *test)
{
    clock_t start = clock();
    recursive_pre_order_transveral(test->tree, print);
    clock_t end = clock();
    double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nPre-order recursive time: %lf s\n", seconds);

    printf("\n\n");
    
    start = clock();
    iterative_pre_order_transveral(test->tree, print);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nPre-order iterative time: %lf s\n", seconds);

    printf("\n\n\n");

    start = clock();
    recursive_in_order_transveral(test->tree, print);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nIn-order recursive time: %lf s\n", seconds);
    
    printf("\n\n");

    start = clock();
    iterative_in_order_transveral(test->tree, print);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nIn-order iterative time: %lf s\n", seconds);

    printf("\n\n\n");

    start = clock();
    recursive_post_order_transveral(test->tree, print);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nPost-order recursive time: %lf s\n", seconds);

    printf("\n\n");

    start = clock();
    iterative_post_order_transveral(test->tree, print);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nPost-order iterative time: %lf s\n", seconds);
    
    printf("\n\n\n");
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
