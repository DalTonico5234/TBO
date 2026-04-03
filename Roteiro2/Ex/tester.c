#include "tester.h"
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

    clock_t start = clock();
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

    clock_t end = clock();

    double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Generation time: %lf\n", seconds);

    return test;
}

void visitTree(Tester *test, void (*visit)(BST *) )
{
    clock_t start = clock();
    recursive_pre_order_transveral(test->tree, visit);
    clock_t end = clock();
    double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Pre-order recursive time: %lf s\n", seconds);

    
    start = clock();
    iterative_pre_order_transveral(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Pre-order iterative time: %lf s\n", seconds);


    start = clock();
    recursive_in_order_transveral(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("In-order recursive time: %lf s\n", seconds);
    

    start = clock();
    iterative_in_order_transveral(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("In-order iterative time: %lf s\n", seconds);


    start = clock();
    recursive_post_order_transveral(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Post-order recursive time: %lf s\n", seconds);


    start = clock();
    iterative_post_order_transveral(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Post-order iterative time: %lf s\n", seconds);

    start = clock();
    level_order_transversal(test->tree, visit);
    end = clock();
    seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Level-order time: %lf s\n", seconds);
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
