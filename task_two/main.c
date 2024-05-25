#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void inputData(WarehouseRegistry *node);
void printMenu();

int main()
{
    WarehouseRegistry *head = NULL;
    int choice, position;
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
            printf("Enter the position to insert: ");
            scanf("%d", &position);
            WarehouseRegistry *newNode = createNode();
            inputData(newNode);
            insertNode(&head, position, newNode);
            break;
        case 2:
            printf("Enter the position to search: ");
            scanf("%d", &position);
            WarehouseRegistry *foundNode = searchNode(head, position);
            if (foundNode)
            {
                displayList(foundNode);
            }
            break;
        case 3:
            printf("Enter the position to delete: ");
            scanf("%d", &position);
            deleteNode(&head, position);
            break;
        case 4:
            displayList(head);
            break;
        case 5:
            printf("Enter the filename to save the list: ");
            scanf("%s", filename);
            registerList(head, filename);
            break;
        default:
            printf("Invalid choice!\n");
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
    printf("Enter contract date (DD MM YYYY): ");
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
    printf("+--------------------------------------+\n");
    printf("|               Menu                   |\n");
    printf("+--------------------------------------+\n");
    printf("| 0 - Exit                             |\n");
    printf("| 1 - Insert node                      |\n");
    printf("| 2 - Search node by position          |\n");
    printf("| 3 - Delete node by position          |\n");
    printf("| 4 - Display list                     |\n");
    printf("| 5 - Save list to file                |\n");
    printf("+--------------------------------------+\n");
}
