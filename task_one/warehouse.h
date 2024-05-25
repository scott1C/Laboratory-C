#ifndef WAREHOUSE_H
#define WAREHOUSE_H

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    char owner_name[50];
    char owner_surname[50];
    char product_name[50];
    char manufacturer[50];
    Date contract_date;
    float wholesale_price;
    float unit_price;
    int quantity;
} WarehouseRegistry;

typedef struct
{
    char category[50];
    int quantity;
} CategoryList;

#endif
