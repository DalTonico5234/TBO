#ifndef tester_h
#define tester_h

typedef struct tester Tester;

Tester *constructTester(int N);

void printTree(Tester *test);

void printHeight(Tester *test);

void freeTester(Tester *test);


#endif