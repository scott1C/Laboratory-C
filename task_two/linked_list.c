#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

WarehouseRegistry *createNode()
{
    WarehouseRegistry *newNode = (WarehouseRegistry *)malloc(sizeof(WarehouseRegistry));
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void displayList(WarehouseRegistry *head)
{
    WarehouseRegistry *current = head;
    while (current != NULL)
    {
        printf("Owner's Name: %s\n", current->owner_name);
        printf("Owner's Surname: %s\n", current->owner_surname);
        printf("Product Name: %s\n", current->product_name);
        printf("Manufacturer: %s\n", current->manufacturer);
        printf("Contract Date: %02d-%02d-%04d\n", current->contract_date.day, current->contract_date.month, current->contract_date.year);
        printf("Wholesale Price: %.2f\n", current->wholesale_price);
        printf("Unit Price: %.2f\n", current->unit_price);
        printf("Quantity: %d\n", current->quantity);
        printf("\n");
        current = current->next;
    }
}

void insertNode(WarehouseRegistry **head, int position, WarehouseRegistry *newNode)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if (*head == NULL && position == 1)
    {
        *head = newNode;
        return;
    }
    WarehouseRegistry *current = *head;
    for (int i = 1; current != NULL && i < position - 1; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of bounds!\n");
        return;
    }
    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

WarehouseRegistry *searchNode(WarehouseRegistry *head, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return NULL;
    }
    WarehouseRegistry *current = head;
    for (int i = 1; current != NULL && i < position; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of bounds!\n");
        return NULL;
    }
    return current;
}

void deleteNode(WarehouseRegistry **head, int position)
{
    if (*head == NULL || position < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    WarehouseRegistry *current = *head;
    for (int i = 1; current != NULL && i < position; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        printf("Position out of bounds!\n");
        return;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
}

void registerList(WarehouseRegistry *head, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    WarehouseRegistry *current = head;
    while (current != NULL)
    {
        fwrite(current, sizeof(WarehouseRegistry), 1, file);
        current = current->next;
    }
    fclose(file);
}
