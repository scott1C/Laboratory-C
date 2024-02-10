#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Function to check for prime numbers in the array using pointers
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

// Function to merge two subarrays in Merge Sort
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

// Function to perform Merge Sort on an array and measure execution time
void mergeSort(int arr[], int l, int r)
{
    clock_t start_time = clock();

    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Merge Sort execution time: %f seconds\n", time_taken);
}

// Function to perform Insertion Sort on an array and measure execution time
void insertionSort(int arr[], int size)
{
    clock_t start_time = clock();

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

    clock_t end_time = clock();
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Insertion Sort execution time: %f seconds\n", time_taken);
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
