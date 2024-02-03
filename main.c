#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Without pointers

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void selectionSort(int arr[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;
        if (minIndex != i)
        {
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

void insertionSort(int arr[], const int size)
{
    for (int i = 1; i < size; i++)
    {
        int sorted = i - 1;
        while (sorted > -1 && arr[sorted] < arr[sorted + 1])
        {
            int tmp = arr[sorted];
            arr[sorted] = arr[sorted + 1];
            arr[sorted + 1] = tmp;
            sorted--;
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
    const int sizeOne = m - l + 1;
    const int sizeTwo = r - m;
    int L[sizeOne], R[sizeTwo];
    int k = l, i = 0, j = 0;
    for (i = 0; i < sizeOne; i++)
        L[i] = arr[l + i];
    for (i = 0; i < sizeTwo; i++)
        R[i] = arr[m + 1 + i];

    i = 0;
    while (i < sizeOne && j < sizeTwo)
    {
        if (L[i] >= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }
    while (i < sizeOne)
    {
        arr[k++] = L[i++];
    }
    while (j < sizeTwo)
    {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int oddDigits(int arr[], const int size)
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

// With pointers

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pointerBubbleSort(int *arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1 - i; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void pointerSelectionSort(int *arr, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        if (minIndex != i)
            swap(&arr[i], &arr[minIndex]);
    }
}

void pointerInsertionSort(int *arr, const int size)
{
    for (int i = 1; i < size; i++)
    {
        int sorted = i - 1;
        while (sorted > -1 && arr[sorted] < arr[sorted + 1])
        {
            swap(&arr[sorted], &arr[sorted + 1]);
            sorted--;
        }
    }
}

int main()
{
    int arr[] = {2, 8, 0, 5, 10, 3, 7, 6, 4, 9, 1};
    const int arrSize = sizeof(arr) / sizeof(arr[0]);
    int sortedArr[arrSize];
    printf("Version without pointers: \n");
    printf("Original array:\t");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", arr[i]);

    if (oddDigits(arr, arrSize))
    {
        printf("\nAll elements from the array have an odd number of digits!");
    }
    else
    {
        printf("\nNot all elements from the array have an odd number of digits!");
    }

    memcpy(sortedArr, arr, sizeof(arr));
    bubbleSort(sortedArr, arrSize);
    printf("\nSorted array after Bubble Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    memcpy(sortedArr, arr, sizeof(arr));
    selectionSort(sortedArr, arrSize);
    printf("\nSorted array after Selection Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    memcpy(sortedArr, arr, sizeof(arr));
    insertionSort(sortedArr, arrSize);
    printf("\nSorted array after Insertion Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    memcpy(sortedArr, arr, sizeof(arr));
    mergeSort(sortedArr, 0, arrSize - 1);
    printf("\nSorted array after Merge Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    printf("\n\nVersion with pointers:");
    memcpy(sortedArr, arr, sizeof(arr));
    pointerBubbleSort(sortedArr, arrSize);
    printf("\nSorted array after Bubble Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    memcpy(sortedArr, arr, sizeof(arr));
    pointerSelectionSort(sortedArr, arrSize);
    printf("\nSorted array after Selection Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    memcpy(sortedArr, arr, sizeof(arr));
    pointerInsertionSort(sortedArr, arrSize);
    printf("\nSorted array after Insetion Sort: ");
    for (unsigned i = 0; i < arrSize; i++)
        printf("%d ", sortedArr[i]);

    printf("\n");
    system("pause");
    return 0;
}