#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warehouse.h"
#include "stack.h"
#include "queue.h"

void input_data(const char *filename, Stack *stack, Queue *queue);
void display_data(const char *filename);
void group_and_sort_data(const char *input_filename, const char *output_filename);
void merge_files(const char *file1, const char *file2, const char *output_file);

int main()
{
    Stack stack;
    Queue queue;
    initializeStack(&stack);
    initializeQueue(&queue);

    input_data("input2.txt", &stack, &queue);
    display_data("input2.txt");

    group_and_sort_data("input2.txt", "output2.txt");
    merge_files("input2.txt", "output2.txt", "result.txt");

    freeStack(&stack);
    freeQueue(&queue);

    return 0;
}

void input_data(const char *filename, Stack *stack, Queue *queue)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Error creating input file");
        exit(EXIT_FAILURE);
    }

    WarehouseRegistry registry;

    printf("Enter owner's name: ");
    scanf("%s", registry.owner_name);
    printf("Enter owner's surname: ");
    scanf("%s", registry.owner_surname);
    printf("Enter product name: ");
    scanf("%s", registry.product_name);
    printf("Enter manufacturer: ");
    scanf("%s", registry.manufacturer);
    printf("Enter contract conclusion date (DD MM YYYY): ");
    scanf("%d %d %d", &registry.contract_date.day, &registry.contract_date.month, &registry.contract_date.year);
    printf("Enter wholesale price: ");
    scanf("%f", &registry.wholesale_price);
    printf("Enter unit price: ");
    scanf("%f", &registry.unit_price);
    printf("Enter quantity: ");
    scanf("%d", &registry.quantity);

    fwrite(&registry, sizeof(WarehouseRegistry), 1, file);
    fclose(file);

    push(stack, registry);
    enqueue(queue, registry);
}

void display_data(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WarehouseRegistry registry;

    fread(&registry, sizeof(WarehouseRegistry), 1, file);
    fclose(file);

    printf("Owner's Name: %s\n", registry.owner_name);
    printf("Owner's Surname: %s\n", registry.owner_surname);
    printf("Product Name: %s\n", registry.product_name);
    printf("Manufacturer: %s\n", registry.manufacturer);
    printf("Contract Date: %02d-%02d-%04d\n", registry.contract_date.day, registry.contract_date.month, registry.contract_date.year);
    printf("Wholesale Price: %.2f\n", registry.wholesale_price);
    printf("Unit Price: %.2f\n", registry.unit_price);
    printf("Quantity: %d\n", registry.quantity);
}

void group_and_sort_data(const char *input_filename, const char *output_filename)
{
    FILE *file = fopen(input_filename, "r");
    if (file == NULL)
    {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WarehouseRegistry registry;
    CategoryList categories[100];
    int category_count = 0;

    while (fread(&registry, sizeof(WarehouseRegistry), 1, file))
    {
        int found = 0;
        for (int i = 0; i < category_count; i++)
        {
            if (strcmp(categories[i].category, registry.product_name) == 0)
            {
                categories[i].quantity += registry.quantity;
                found = 1;
                break;
            }
        }
        if (!found)
        {
            strcpy(categories[category_count].category, registry.product_name);
            categories[category_count].quantity = registry.quantity;
            category_count++;
        }
    }
    fclose(file);

    for (int i = 0; i < category_count - 1; i++)
    {
        for (int j = i + 1; j < category_count; j++)
        {
            if (strcmp(categories[i].category, categories[j].category) < 0)
            {
                CategoryList temp = categories[i];
                categories[i] = categories[j];
                categories[j] = temp;
            }
        }
    }

    file = fopen(output_filename, "w");
    if (file == NULL)
    {
        perror("Error creating output file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < category_count; i++)
    {
        fprintf(file, "%s - %d\n", categories[i].category, categories[i].quantity);
    }
    fclose(file);
}

void merge_files(const char *file1, const char *file2, const char *output_file)
{
    FILE *f1 = fopen(file1, "r");
    FILE *f2 = fopen(file2, "r");
    FILE *out = fopen(output_file, "w");

    if (f1 == NULL || f2 == NULL || out == NULL)
    {
        perror("Error opening files for merging");
        exit(EXIT_FAILURE);
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), f1) != NULL)
    {
        fputs(buffer, out);
    }

    while (fgets(buffer, sizeof(buffer), f2) != NULL)
    {
        fputs(buffer, out);
    }

    fclose(f1);
    fclose(f2);
    fclose(out);
}
