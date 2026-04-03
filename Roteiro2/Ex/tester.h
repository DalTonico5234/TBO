#ifndef tester_h
#define tester_h

typedef struct tester Tester;

#include "BST.h"

Tester *constructTester(int N);

void visitTree(Tester *test, void (*visit)(BST *));

void printHeight(Tester *test);

void freeTester(Tester *test);


#endif