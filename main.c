#include <stdio.h>
#include <conio.h>
#include <time.h>

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void swap(int *num_one, int *num_two)
{
    int tmp = *num_one;
    *num_one = *num_two;
    *num_two = tmp;
}

void bubbleSort(int arr[], int length)
{
    while (length)
    {
        int max_index = 0;
        for (int i = 1; i < length; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                swap(&arr[i - 1], &arr[i]);
                max_index = i;
            }
        }
        length = max_index;
    }
}

void selectionSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[min_index] > arr[j])
                min_index = j;
        }
        if (min_index != i)
            swap(&arr[min_index], &arr[i]);
    }
}

void insertionSort(int arr[], int length)
{
    for (int i = 1; i < length; i++)
    {
        int sorted = i - 1;
        while (sorted >= 0 && arr[sorted] > arr[sorted + 1])
        {
            swap(&arr[sorted], &arr[sorted + 1]);
            sorted--;
        }
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int part_index = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(&arr[i], &arr[part_index]);
            part_index++;
        }
    }
    swap(&arr[end], &arr[part_index]);

    return part_index;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int piv_index = partition(arr, start, end);
        quickSort(arr, start, piv_index - 1);
        quickSort(arr, piv_index + 1, end);
    }
}

int main()
{
    int a[1000], b[1000], c[1000], d[1000];
    int n;
    clock_t start_time, end_time;
    double time_used;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    start_time = clock();
    bubbleSort(a, n);
    end_time = clock();
    time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printArr(a, n);
    printf("Timp luat: %f secunde\n\n", time_used);

    start_time = clock();
    selectionSort(b, n);
    end_time = clock();
    time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printArr(b, n);
    printf("Timp luat: %f secunde\n\n", time_used);

    start_time = clock();
    insertionSort(c, n);
    end_time = clock();
    time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printArr(c, n);
    printf("Timp luat: %f secunde\n\n", time_used);

    start_time = clock();
    quickSort(d, 0, n - 1);
    end_time = clock();
    time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printArr(d, n);
    printf("Timp luat: %f secunde\n\n", time_used);

    getch();
    return 0;
}