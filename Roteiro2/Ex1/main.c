#include "tester.h"
#include "BST.h"
#include <stdio.h>

#define N 1000000

int main()
{
    Tester *test = constructTester(N);

    printHeight(test);

    freeTester(test);
}