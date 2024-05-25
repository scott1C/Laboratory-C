// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_tree.h"

void inputData(WarehouseRegistry *node);
void printMenu();

int main()
{
    WarehouseRegistry *root = NULL;
    int choice;
    char product_name[50];
    char filename[50];

    while (1)
    {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
        {
            WarehouseRegistry *newNode = createNode();
            inputData(newNode);
            root = insertNode(root, newNode);
            break;
        }
        case 2:
        {
            printf("Enter product name to search: ");
            scanf("%s", product_name);
            WarehouseRegistry *searchedNode = searchNode(root, product_name);
            if (searchedNode)
            {
                printf("Node found:\n");
                printf("Owner's Name: %s\n", searchedNode->owner_name);
                printf("Owner's Surname: %s\n", searchedNode->owner_surname);
                printf("Product Name: %s\n", searchedNode->product_name);
                printf("Manufacturer: %s\n", searchedNode->manufacturer);
                printf("Contract Date: %02d-%02d-%04d\n", searchedNode->contract_date.day, searchedNode->contract_date.month, searchedNode->contract_date.year);
                printf("Wholesale Price: %.2f\n", searchedNode->wholesale_price);
                printf("Unit Price: %.2f\n", searchedNode->unit_price);
                printf("Quantity: %d\n", searchedNode->quantity);
            }
            else
            {
                printf("Node not found\n");
            }
            break;
        }
        case 3:
        {
            printf("Enter product name to delete: ");
            scanf("%s", product_name);
            root = deleteNode(root, product_name);
            break;
        }
        case 4:
        {
            printf("Enter filename to save the AVL Tree: ");
            scanf("%s", filename);
            saveToFile(root, filename);
            break;
        }
        case 5:
            printf("AVL Tree (PreOrder Traversal):\n");
            preOrder(root);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}

void inputData(WarehouseRegistry *node)
{
    printf("Enter owner's name: ");
    scanf("%s", node->owner_name);
    printf("Enter owner's surname: ");
    scanf("%s", node->owner_surname);
    printf("Enter product name: ");
    scanf("%s", node->product_name);
    printf("Enter manufacturer: ");
    scanf("%s", node->manufacturer);
    printf("Enter contract conclusion date (DD MM YYYY): ");
    scanf("%d %d %d", &node->contract_date.day, &node->contract_date.month, &node->contract_date.year);
    printf("Enter wholesale price: ");
    scanf("%f", &node->wholesale_price);
    printf("Enter unit price: ");
    scanf("%f", &node->unit_price);
    printf("Enter quantity: ");
    scanf("%d", &node->quantity);
}

void printMenu()
{
    printf("\nMenu:\n");
    printf("1. Insert a node\n");
    printf("2. Search for a node\n");
    printf("3. Delete a node\n");
    printf("4. Save AVL Tree to file\n");
    printf("5. Display AVL Tree (PreOrder)\n");
    printf("0. Exit\n");
}
