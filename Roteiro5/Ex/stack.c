#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


struct stack
{
    Item *stack;
    Item top;
    int max;
};

Stack *stack_init(int max)
{
    if (max <= 0)
        return NULL;
    Stack *sonic = (Stack *)malloc(sizeof(Stack));
    if (sonic == NULL)
        return NULL;

    sonic->stack = (Item *)calloc(max, sizeof(Item));
    if (sonic->stack == NULL)
    {
        free(sonic);
        return NULL;
    }

    sonic->top = -1;
    sonic->max = max;

    return sonic;
}

void push(Stack *sonic, Item element)
{
    if (stack_full(sonic))
    {
        printf("Error: Stack Overflow\n");
        return;
    }
    sonic->stack[++(sonic->top)] = element;
}

Item pop(Stack *sonic)
{
    if (stack_empty(sonic))
    {
        printf("Erro: Stack Underflow\n");
        return -1;
    }
    return sonic->stack[(sonic->top)--];
}

char stack_empty(Stack *sonic)
{
    return (sonic->top == -1);
}

char stack_full(Stack *sonic)
{
    return sonic->top == sonic->max - 1;
}

void free_stack(Stack *sonic)
{
    if (sonic != NULL)
    {
        if (sonic->stack != NULL)
            free(sonic->stack);
        free(sonic);
    }
}