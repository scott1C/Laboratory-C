#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

typedef struct WarehouseRegistry
{
    char owner_name[50];
    char owner_surname[50];
    char product_name[50];
    char manufacturer[50];
    Date contract_date;
    float wholesale_price;
    float unit_price;
    int quantity;
    struct WarehouseRegistry *next;
    struct WarehouseRegistry *prev;
} WarehouseRegistry;

WarehouseRegistry *createNode();
void displayList(WarehouseRegistry *head);
void insertNode(WarehouseRegistry **head, int position, WarehouseRegistry *newNode);
WarehouseRegistry *searchNode(WarehouseRegistry *head, int position);
void deleteNode(WarehouseRegistry **head, int position);
void registerList(WarehouseRegistry *head, const char *filename);

#endif // LINKED_LIST_H
