#ifndef STACK_H
#define STACK_H

#include "warehouse.h"

typedef struct Node
{
    WarehouseRegistry data;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
} Stack;

void initializeStack(Stack *stack);
void push(Stack *stack, WarehouseRegistry data);
WarehouseRegistry pop(Stack *stack);
int isEmptyStack(Stack *stack);
void freeStack(Stack *stack);

#endif
