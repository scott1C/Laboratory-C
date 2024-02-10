#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // We swap here the elements
                // In order to get the smallest element at the end
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

// Function to perform Selection Sort on an array
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;
        if (minIndex != i)
        {
            // If the smallest element is not at his place
            // then we place it there
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

// Function to check if all elements have an odd number of digits
int oddDigits(int arr[], int size)
{
    for (int i = 0; i < size; i++)
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
    int arr[100], arrSize;

    // Taking input for array size and elements
    printf("Enter the number which will be in the array: ");
    scanf("%d", &arrSize);
    printf("Enter elements which will be stored in the array: \n");
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("Original array:\t");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);

    int sortedArr[100];

    if (oddDigits(arr, arrSize))
    {
        printf("\nAll elements from the array have an odd number of digits!");
        memcpy(sortedArr, arr, sizeof(arr));
        bubbleSort(sortedArr, arrSize);
        printf("\nSorted array after Bubble Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }
    else
    {
        printf("\nNot all elements from the array have an odd number of digits!");
        memcpy(sortedArr, arr, sizeof(arr));
        selectionSort(sortedArr, arrSize);
        printf("\nSorted array after Selection Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}
