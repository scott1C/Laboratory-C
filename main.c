#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSortAscending(int arr[], int start, int end)
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
        quickSortAscending(arr, start, right);

    // If there are still elements in the right partition, recursively call quickSort on it
    if (end > left)
        quickSortAscending(arr, left, end);
}

void quickSortDescending(int arr[], int start, int end)
{
    int left = start, right = end, pivot = arr[(start + end) / 2];

    while (left <= right)
    {
        while (arr[left] > pivot)
            left++;
        while (arr[right] < pivot)
            right--;

        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    if (start < right)
        quickSortDescending(arr, start, right);
    if (end > left)
        quickSortDescending(arr, left, end);
}

void shellSortAscending(int arr[], int n)
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

void shellSortDescending(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] < temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void swappingElements(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
        swap(&arr[i], &arr[i + 1]);
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int arr[100];
    int arr_modified[100];
    int arr_size;
    printf("Enter the number of elements which will be in the array: ");
    scanf("%d", &arr_size);
    printf("Reading arrray: ");
    for (int i = 0; i < arr_size; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < arr_size; i++)
        arr_modified[i] = arr[i];

    printf("Original array is: \n");
    printArray(arr, arr_size);

    quickSortAscending(arr, 0, arr_size - 1);
    printf("Sorted original array using quicksort (ascending) is: \n");
    printArray(arr, arr_size);

    quickSortDescending(arr, 0, arr_size - 1);
    printf("Sorted original array using quicksort (descending) is: \n");
    printArray(arr, arr_size);

    // Modified array
    swappingElements(arr_modified, arr_size);
    printf("Modified array is: \n");
    printArray(arr_modified, arr_size);

    shellSortAscending(arr_modified, arr_size);
    printf("Sorted modified array using shellsort (ascending) is: \n");
    printArray(arr_modified, arr_size);

    shellSortDescending(arr_modified, arr_size);
    printf("Sorted modified array using shellsort (descending) is: \n");
    printArray(arr_modified, arr_size);

    system("pause");
    return 0;
}