#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX_LENGTH_OF_CHAR 100
const int size = 2;

typedef struct
{
    int type;
    union
    {
        int intData;
        float floatData;
        char charData[MAX_LENGTH_OF_CHAR];
    } data;
} StackItem;

typedef struct
{
    StackItem *data;
    int top;
    unsigned int capacity;
} Stack;

void initializeStack(Stack *stack)
{
    if (size < 0)
    {
        printf("Size of stack cannot be less than 0 \n");
        system("pause");
        exit(1);
    }
    stack->data = calloc(size, sizeof(StackItem));
    if (stack->data == NULL)
    {
        printf("System cannot allocate this amount of memory space from heap! \n");
        system("pause");
        exit(1);
    }
    stack->capacity = size;
    stack->top = -1;
}

int isFull(Stack *stack)
{
    return stack->capacity - 1 == stack->top;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void pushToStack(Stack *stack, StackItem *value)
{
    int position = stack->top + 1;
    stack->data[position] = *value;
    stack->top++;
}

void popStack(Stack *stack)
{
    stack->top = stack->top - 1;
}

void peekStack(Stack *stack)
{
    StackItem item = stack->data[stack->top];
    if (item.type == 1)
        printf("%d\n", item.data.intData);
    else if (item.type == 2)
        printf("%f\n", item.data.floatData);
    else if (item.type == 3)
        printf("%s\n", item.data.charData);
}

void showStack(Stack *stack)
{
    printf("Stack Contents: ");
    if (stack->top > -1)
    {
        for (int i = 0; i <= stack->top; i++)
        {
            StackItem item = stack->data[i];
            if (item.type == 1)
                printf("%d ", item.data.intData);
            else if (item.type == 2)
                printf("%f ", item.data.floatData);
            else if (item.type == 3)
                printf("%s ", item.data.charData);
        }
    }
    else
        printf("(empty)");
    printf("\n");
}

void operationsMenu()
{
    printf("Stack Operations Menu:\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. IsFull\n6. Exit\n");
    printf("Enter your choice: ");
}

void clearOutput()
{
    system("cls");
}

int main()
{
    Stack stack;
    initializeStack(&stack);
    int n = 1;

    while (n)
    {
        int operation;
        operationsMenu();
        scanf("%d", &operation);
        if (operation == 1)
        {
            clearOutput();
            if (!isFull(&stack))
            {
                StackItem item;
                printf("Type 1 for integer, 2 for float or 3 for char: ");
                scanf("%d", &item.type);
                if (item.type == 1)
                {
                    printf("Enter the value to push onto the stack: ");
                    scanf("%d", &item.data.intData);
                    clearOutput();
                    printf("Element %d pushed onto the stack\n", item.data.intData);
                }
                else if (item.type == 2)
                {
                    printf("Enter the value to push onto the stack: ");
                    scanf("%f", &item.data.floatData);
                    clearOutput();
                    printf("Element %f pushed onto the stack\n", item.data.floatData);
                }
                else if (item.type == 3)
                {
                    printf("Enter the value to push onto the stack: ");
                    scanf("%s", item.data.charData);
                    clearOutput();
                    printf("Element %s pushed onto the stack\n", item.data.charData);
                }
                else
                {
                    clearOutput();
                    printf("You entered an incorect number, try again \n");
                    continue;
                }
                pushToStack(&stack, &item);
                showStack(&stack);
            }
            else
            {
                printf("The Stack is full, you cannot enter more elements!\n");
            }
        }
        else if (operation == 2)
        {
            clearOutput();
            if (isEmpty(&stack))
            {
                printf("The stack is empty, you are not allowed to do this operation!\n");
            }
            else
            {
                printf("Popped element: ");
                peekStack(&stack);
                popStack(&stack);
                showStack(&stack);
            }
        }
        else if (operation == 3)
        {
            clearOutput();
            if (isEmpty(&stack))
            {
                printf("The stack is empty, you are not allowed to do this operation!\n");
            }
            else
            {
                printf("Peeked element: ");
                peekStack(&stack);
            }
        }
        else if (operation == 4)
        {
            clearOutput();
            if (isEmpty(&stack))
                printf("The Stack is empty\n");
            else
                printf("The Stack is NOT empty\n");
        }
        else if (operation == 5)
        {
            clearOutput();
            if (isFull(&stack))
                printf("The Stack is full\n");
            else
                printf("The Stack is NOT full\n");
        }
        else if (operation == 6)
        {
            printf("Exiting the program");
            n = 0;
            free(stack.data);
        }
        else
        {
            printf("You entered the wrong number, try again\n");
        }
    }

    getch();
    return 0;
}
