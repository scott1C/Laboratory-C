#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to swap two integers using pointers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Function to perform Bubble Sort on an array using pointers
void pointerBubbleSort(int *arr, int *size)
{
    for (int i = 0; i < *size - 1; i++)
        for (int j = 0; j < *size - 1 - i; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

// Function to perform Selection Sort on an array using pointers
void pointerSelectionSort(int *arr, int *size)
{
    for (int i = 0; i < *size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < *size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

// Function to check if all elements have an odd number of digits using pointers
int pointerOddDigits(int *arr, int *size)
{
    for (int i = 0; i < *size; i++)
    {
        int digits = 0;
        int copy = arr[i];
        while (copy)
        {
            copy /= 10;
            digits++;
        }
        if (digits % 2 == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int *arr, arrSize;

    // Taking input for array size and elements
    printf("Enter the number which will be in the array: ");
    scanf("%d", &arrSize);

    arr = (int *)malloc(arrSize * sizeof(int));
    printf("Enter elements which will be stored in the array: \n");
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\t");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);

    if (pointerOddDigits(arr, &arrSize))
    {
        printf("\nAll elements from the array have an odd number of digits!");
        pointerBubbleSort(arr, &arrSize);
        printf("\nSorted array after Bubble Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        printf("\nNot all elements from the array have an odd number of digits!");
        pointerSelectionSort(arr, &arrSize);
        printf("\nSorted array after Selection Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    system("pause");
    return 0;
}