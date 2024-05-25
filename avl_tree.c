#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl_tree.h"

WarehouseRegistry *createNode()
{
    WarehouseRegistry *newNode = (WarehouseRegistry *)malloc(sizeof(WarehouseRegistry));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(WarehouseRegistry *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int maxEl(int a, int b)
{
    return (a > b) ? a : b;
}

WarehouseRegistry *rightRotate(WarehouseRegistry *y)
{
    WarehouseRegistry *x = y->left;
    WarehouseRegistry *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxEl(height(y->left), height(y->right)) + 1;
    x->height = maxEl(height(x->left), height(x->right)) + 1;

    return x;
}

WarehouseRegistry *leftRotate(WarehouseRegistry *x)
{
    WarehouseRegistry *y = x->right;
    WarehouseRegistry *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxEl(height(x->left), height(x->right)) + 1;
    y->height = maxEl(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(WarehouseRegistry *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

WarehouseRegistry *insertNode(WarehouseRegistry *node, WarehouseRegistry *newNode)
{
    if (node == NULL)
        return newNode;

    if (strcmp(newNode->product_name, node->product_name) < 0)
        node->left = insertNode(node->left, newNode);
    else if (strcmp(newNode->product_name, node->product_name) > 0)
        node->right = insertNode(node->right, newNode);
    else
        return node;

    node->height = 1 + maxEl(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(newNode->product_name, node->left->product_name) < 0)
        return rightRotate(node);

    if (balance < -1 && strcmp(newNode->product_name, node->right->product_name) > 0)
        return leftRotate(node);

    if (balance > 1 && strcmp(newNode->product_name, node->left->product_name) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(newNode->product_name, node->right->product_name) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

WarehouseRegistry *minValueNode(WarehouseRegistry *node)
{
    WarehouseRegistry *current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}

WarehouseRegistry *deleteNode(WarehouseRegistry *root, char *product_name)
{
    if (root == NULL)
        return root;

    if (strcmp(product_name, root->product_name) < 0)
        root->left = deleteNode(root->left, product_name);
    else if (strcmp(product_name, root->product_name) > 0)
        root->right = deleteNode(root->right, product_name);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            WarehouseRegistry *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            WarehouseRegistry *temp = minValueNode(root->right);
            strcpy(root->product_name, temp->product_name);
            root->right = deleteNode(root->right, temp->product_name);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + maxEl(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

WarehouseRegistry *searchNode(WarehouseRegistry *root, char *product_name)
{
    if (root == NULL || strcmp(root->product_name, product_name) == 0)
        return root;

    if (strcmp(root->product_name, product_name) < 0)
        return searchNode(root->right, product_name);

    return searchNode(root->left, product_name);
}

void preOrder(WarehouseRegistry *root)
{
    if (root != NULL)
    {
        printf("Owner's Name: %s\n", root->owner_name);
        printf("Owner's Surname: %s\n", root->owner_surname);
        printf("Product Name: %s\n", root->product_name);
        printf("Manufacturer: %s\n", root->manufacturer);
        printf("Contract Date: %02d-%02d-%04d\n", root->contract_date.day, root->contract_date.month, root->contract_date.year);
        printf("Wholesale Price: %.2f\n", root->wholesale_price);
        printf("Unit Price: %.2f\n", root->unit_price);
        printf("Quantity: %d\n", root->quantity);
        printf("\n");
        preOrder(root->left);
        preOrder(root->right);
    }
}

void saveToFile(WarehouseRegistry *root, const char *filename)
{
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }
    void saveNode(WarehouseRegistry * node)
    {
        if (node != NULL)
        {
            fwrite(node, sizeof(WarehouseRegistry), 1, file);
            saveNode(node->left);
            saveNode(node->right);
        }
    }
    saveNode(root);
    fclose(file);
}
