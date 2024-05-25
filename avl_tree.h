#ifndef AVL_TREE_H
#define AVL_TREE_H

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
    struct WarehouseRegistry *left;
    struct WarehouseRegistry *right;
    int height;
} WarehouseRegistry;

WarehouseRegistry *createNode();
int height(WarehouseRegistry *N);
int max(int a, int b);
WarehouseRegistry *rightRotate(WarehouseRegistry *y);
WarehouseRegistry *leftRotate(WarehouseRegistry *x);
int getBalance(WarehouseRegistry *N);
WarehouseRegistry *insertNode(WarehouseRegistry *node, WarehouseRegistry *newNode);
WarehouseRegistry *minValueNode(WarehouseRegistry *node);
WarehouseRegistry *deleteNode(WarehouseRegistry *root, char *product_name);
WarehouseRegistry *searchNode(WarehouseRegistry *root, char *product_name);
void preOrder(WarehouseRegistry *root);
void saveToFile(WarehouseRegistry *root, const char *filename);

#endif
