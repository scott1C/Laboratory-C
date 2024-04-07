#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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

void countSort(int inputArr[], int size)
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

void quickSort(int arr[], int start, int end)
{
    // Choose the pivot as the middle element in the current subarray
    int left = start, right = end, pivot = arr[(start + end) / 2];

    // Continue the loop until the left and right indices meet or cross
    while (left <= right)
    {
        // Move the left index to the right until finding an element greater than or equal to the pivot
        while (arr[left] < pivot)
            left++;

        // Move the right index to the left until finding an element less than or equal to the pivot
        while (arr[right] > pivot)
            right--;

        // If left index is still less than or equal to the right index, swap the elements at these indices
        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            // Move indices to continue the partitioning process
            left++;
            right--;
        }
    }

    // If there are still elements in the left partition, recursively call quickSort on it
    if (start < right)
        quickSort(arr, start, right);

    // If there are still elements in the right partition, recursively call quickSort on it
    if (end > left)
        quickSort(arr, left, end);
}

void merge(int arr[], int l, int m, int r)
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

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < n; i += 1)
        {
            // add arr[i] to the elements that have been gap sorted
            int temp = arr[i];
            // shift earlier gap-sorted elements up until the correct location for arr[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            // put temp (the original arr[i]) in its correct location
            arr[j] = temp;
        }
    }
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7, 5, 3, 1, 3, 6, 1, 8, 9, 0, 21, 312, 21, 212, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Given array is \n");
    printArray(arr, arr_size);

    shellSort(arr, arr_size);
    printf("\nSorted array is \n");
    printArray(arr, arr_size);

    system("pause");
    return 0;
}