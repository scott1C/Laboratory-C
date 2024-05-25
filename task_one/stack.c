#include <stdlib.h>
#include "stack.h"

void initializeStack(Stack *stack)
{
    stack->top = NULL;
}

void push(Stack *stack, WarehouseRegistry data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

WarehouseRegistry pop(Stack *stack)
{
    if (isEmptyStack(stack))
    {
        WarehouseRegistry empty = {0};
        return empty;
    }
    Node *temp = stack->top;
    WarehouseRegistry poppedData = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedData;
}

int isEmptyStack(Stack *stack)
{
    return stack->top == NULL;
}

void freeStack(Stack *stack)
{
    while (!isEmptyStack(stack))
    {
        pop(stack);
    }
}
