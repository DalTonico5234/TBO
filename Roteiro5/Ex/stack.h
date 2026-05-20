#ifndef stack_h
#define stack_h

typedef struct stack Stack;

#include "item.h"

#define push2(sonic, A, B) push(sonic, B); push(sonic, A)

Stack *stack_init(int MAX);

void push(Stack *sonic, Item element);

char stack_empty(Stack *sonic);

char stack_full(Stack *sonic);

Item pop(Stack *sonic);

void free_stack(Stack *sonic);

#endif