#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void mergeAscending(int arr[], int l, int m, int r)
{
    int i, j, k;
    int sizeOne = m - l + 1;
    int sizeTwo = r - m;

    // Creating temp arrays
    int L[sizeOne], R[sizeTwo];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < sizeOne; i++)
        L[i] = arr[l + i];

    for (j = 0; j < sizeTwo; j++)
        R[j] = arr[m + j + 1];

    i = 0, j = 0, k = l;
    while (i < sizeOne && j < sizeTwo)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[] and R[], if there are any
    while (i < sizeOne)
        arr[k++] = L[i++];

    while (j < sizeTwo)
        arr[k++] = R[j++];
}

void mergeSortAscending(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortAscending(arr, start, mid);
        mergeSortAscending(arr, mid + 1, end);
        mergeAscending(arr, start, mid, end);
    }
}

void mergeDescending(int arr[], int l, int m, int r)
{
    int i, j, k;
    int sizeOne = m - l + 1;
    int sizeTwo = r - m;

    // Creating temp arrays
    int L[sizeOne], R[sizeTwo];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < sizeOne; i++)
        L[i] = arr[l + i];

    for (j = 0; j < sizeTwo; j++)
        R[j] = arr[m + j + 1];

    i = 0, j = 0, k = l;
    while (i < sizeOne && j < sizeTwo)
    {
        if (L[i] >= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy the remaining elements of L[] and R[], if there are any
    while (i < sizeOne)
        arr[k++] = L[i++];

    while (j < sizeTwo)
        arr[k++] = R[j++];
}

void mergeSortDescending(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSortDescending(arr, start, mid);
        mergeSortDescending(arr, mid + 1, end);
        mergeDescending(arr, start, mid, end);
    }
}

void findMinMax(int arr[], int n, int *minEl, int *maxEl)
{
    // Finding the minimum and the maximum by iterating the array
    *minEl = arr[0];
    *maxEl = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > *maxEl)
            *maxEl = arr[i];
        else if (arr[i] < *minEl)
            *minEl = arr[i];
    }
}

void countSortAscending(int inputArr[], int size)
{
    // Determine the maximum and minimum element from the array
    int minValue, maxValue;
    findMinMax(inputArr, size, &minValue, &maxValue);

    // Initialize countingArr elements to zero
    int countingArr[maxValue + 1];
    for (int i = 0; i <= maxValue; i++)
        countingArr[i] = 0;

    // Counting the occurence of each element which will be placed in the countArr[]
    for (int i = 0; i < size; i++)
        countingArr[inputArr[i]]++;

    // Modifying the count array such that each element at each index stores the sum of previous counts
    for (int i = 1; i <= maxValue; i++)
        countingArr[i] += countingArr[i - 1];

    // Iterate from end of the input array and storing elements in outputArr

    int outputArr[size];
    for (int i = size - 1; i >= 0; i--)
    {
        int position = countingArr[inputArr[i]] - 1;
        outputArr[position] = inputArr[i];
        countingArr[inputArr[i]]--;
    }

    // Copy the sorted elements from the output array back to the original array
    for (int i = 0; i < size; i++)
        inputArr[i] = outputArr[i];
}

void countSortDescending(int inputArr[], int size)
{
    int minValue, maxValue;
    findMinMax(inputArr, size, &minValue, &maxValue);

    // Initialize countingArr elements to zero
    int countingArr[maxValue - minValue + 1];
    for (int i = 0; i <= maxValue - minValue; i++)
        countingArr[i] = 0;

    // Count the occurrence of each element which will be placed in the countArr[]
    for (int i = 0; i < size; i++)
        countingArr[maxValue - inputArr[i]]++;

    // Modify the count array such that each element at each index stores the sum of previous counts
    for (int i = 1; i <= maxValue - minValue; i++)
        countingArr[i] += countingArr[i - 1];

    // Iterate from start of the input array and store elements in outputArr
    int outputArr[size];
    for (int i = 0; i < size; i++)
    {
        int position = countingArr[maxValue - inputArr[i]] - 1;
        outputArr[position] = inputArr[i];
        countingArr[maxValue - inputArr[i]]--;
    }

    // Copy the sorted elements from the output array back to the original array
    for (int i = 0; i < size; i++)
        inputArr[i] = outputArr[i];
}

// Finding the most frequent element in array, with the condition that array has non-negative elements
int mostFrequentElement(int arr[], int size)
{
    int minEl = arr[0];
    int maxEl = arr[0];
    findMinMax(arr, size, &minEl, &maxEl);

    int countArr[maxEl + 1];
    for (int i = 0; i <= maxEl; i++)
        countArr[i] = 0;

    for (int i = 0; i < size; i++)
        countArr[arr[i]]++;

    int frequentElement = countArr[0];
    int position = 0;
    for (int i = 1; i <= maxEl; i++)
        if (countArr[i] > frequentElement)
        {
            frequentElement = countArr[i];
            position = i;
        }
    return position;
}

int main()
{
    int arr[100];
    int arr_size;
    printf("Enter the number of elements which will be in the array: ");
    scanf("%d", &arr_size);
    printf("Reading arrray: ");
    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);

    printf("Original array is: \n");
    printArray(arr, arr_size);

    printf("The most frequent element here is: ");
    printf("%d\n", mostFrequentElement(arr, arr_size));

    mergeSortAscending(arr, 0, arr_size - 1);
    printf("Sorted array after merge sort: (ascending) ");
    printArray(arr, arr_size);

    mergeSortDescending(arr, 0, arr_size - 1);
    printf("Sorted array after merge sort: (descending) ");
    printArray(arr, arr_size);

    countSortAscending(arr, arr_size);
    printf("Sorted array after count sort (ascening): ");
    printArray(arr, arr_size);

    countSortDescending(arr, arr_size);
    printf("Sorted array after count sort (descending): ");
    printArray(arr, arr_size);

    system("pause");
    return 0;
}
