#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Without pointers

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

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
            int tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int sorted = i - 1;
        while (sorted > -1 && arr[sorted] > arr[sorted + 1])
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
    int sizeOne = m - l + 1;
    int sizeTwo = r - m;
    int L[100], R[100];
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

// With pointers

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void pointerBubbleSort(int *arr, int *size)
{
    for (int i = 0; i < *size - 1; i++)
        for (int j = 0; j < *size - 1 - i; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

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

int pointerPrimeNumbers(int *arr, int *size)
{
    int isPrime, hasPrime = 0;
    for (int i = 0; i < *size; i++)
    {
        isPrime = 1;
        for (int j = 2; j <= sqrt(arr[i]); j++)
            if (arr[i] % j == 0)
            {
                isPrime = 0;
                break;
            }
        if (isPrime && arr[i] > 1)
        {
            printf("Element: %d with index: %d is prime\n", arr[i], i);
            hasPrime = 1;
        }
    }
    if (!hasPrime)
        printf("This array does not contain any prime numbers!\n");
    return hasPrime;
}

int main()
{
    int arr[100], arrSize;
    printf("Enter the number which will be in array: ");
    scanf("%d", &arrSize);
    printf("Enter elements which will be stored in array: \n");
    for (int i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("Version without pointers: \n");
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

    printf("\n\nVersion with pointers:");
    if (pointerOddDigits(arr, &arrSize))
    {
        printf("\nAll elements from the array have an odd number of digits!");
        memcpy(sortedArr, arr, sizeof(arr));
        pointerBubbleSort(sortedArr, &arrSize);
        printf("\nSorted array after Bubble Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }
    else
    {
        printf("\nNot all elements from the array have an odd number of digits!");
        memcpy(sortedArr, arr, sizeof(arr));
        pointerSelectionSort(sortedArr, &arrSize);
        printf("\nSorted array after Selection Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }

    printf("\n\nThe second task: (where you need to check if all elements in the given array are not prime)\n");
    int hasPrime = pointerPrimeNumbers(arr, &arrSize);
    if (!hasPrime)
    {
        memcpy(sortedArr, arr, sizeof(arr));
        mergeSort(sortedArr, 0, arrSize - 1);
        printf("Sorted array after Merge Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }
    else
    {
        memcpy(sortedArr, arr, sizeof(arr));
        insertionSort(sortedArr, arrSize);
        printf("Sorted array after Insertion Sort: ");
        for (unsigned i = 0; i < arrSize; i++)
            printf("%d ", sortedArr[i]);
    }

    printf("\n");
    system("pause");
    return 0;
}