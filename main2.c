#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quickSortAscending(int *arr, int start, int end)
{
    int left = start, right = end;
    int pivot = arr[(start + end) / 2];

    while (left <= right)
    {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot)
            right--;

        if (left <= right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }

    if (start < right)
        quickSortAscending(arr, start, right);
    if (end > left)
        quickSortAscending(arr, left, end);
}

void quickSortDescending(int *arr, int start, int end)
{
    int left = start, right = end;
    int pivot = arr[(start + end) / 2];

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

void shellSortAscending(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void shellSortDescending(int *arr, int n)
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

void swappingElements(int *arr, int size)
{
    for (int i = 0; i < size; i += 2)
        swap(&arr[i], &arr[i + 1]);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int *arr, *arr_modified;
    int arr_size;

    printf("Enter the number of elements which will be in the array: ");
    scanf("%d", &arr_size);

    arr = (int *)malloc(arr_size * sizeof(int));
    arr_modified = (int *)malloc(arr_size * sizeof(int));

    printf("Reading array: ");
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

    free(arr);
    free(arr_modified);

    system("pause");
    return 0;
}
