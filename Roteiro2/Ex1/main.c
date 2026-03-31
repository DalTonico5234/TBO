#include "tester.h"
#include "BST.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    Tester *test = constructTester(atoi(argv[argc-1]));

    printHeight(test);

    freeTester(test);
}