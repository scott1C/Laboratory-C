#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void swap(int *num_one, int *num_two)
{
    int tmp = *num_one;
    *num_one = *num_two;
    *num_two = tmp;
}

void fillMatrix(int matrix[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            matrix[i][j] = rand() % 100;
}

void printMatrix(int matrix[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int matrixToArray(int matrix[100][100], int arr[], int rows, int cols)
{
    int length = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            arr[length++] = matrix[i][j];

    return length;
}

int insertionSort(int arr[], int length)
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

void fillSpiralFromLeft(int matrix[100][100], int arr[], int top, int bottom, int left, int right, int index)
{
    if (top > bottom || left > right)
    {
        return;
    }

    for (int i = left; i <= right; i++)
    {
        matrix[top][i] = arr[index++];
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
        matrix[i][right] = arr[index++];
    }
    right--;

    if (top <= bottom)
    {
        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = arr[index++];
        }
        bottom--;
    }

    if (left <= right)
    {
        for (int i = bottom; i >= top; i--)
        {
            matrix[i][left] = arr[index++];
        }
        left++;
    }

    fillSpiralFromLeft(matrix, arr, top, bottom, left, right, index);
}

void fillSpiralFromRight(int matrix[100][100], int arr[], int top, int bottom, int left, int right, int index)
{
    if (top > bottom || left > right)
        return;

    for (int i = right; i >= left; i--)
    {
        matrix[top][i] = arr[index++];
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
        matrix[i][left] = arr[index++];
    }
    left++;

    if (left < right)
    {
        for (int i = left; i <= right; i++)
        {
            matrix[bottom][i] = arr[index++];
        }
        bottom--;
    }

    for (int i = bottom; i >= top; i--)
    {
        matrix[i][right] = arr[index++];
    }
    right--;

    fillSpiralFromRight(matrix, arr, top, bottom, left, right, index);
}

void fillSpiralFromMiddle(int matrix[100][100], int arr[], int top, int bottom, int left, int right, int index, int middle)
{
    if (top > bottom || left > right)
        return;

    for (int i = middle; i <= right; i++)
    {
        matrix[top][i] = arr[index++];
    }
    top++;

    for (int i = top; i <= bottom; i++)
    {
        matrix[i][right] = arr[index++];
    }
    right--;

    for (int i = right; i >= left; i--)
    {
        matrix[bottom][i] = arr[index++];
    }
    bottom--;

    for (int i = bottom; i >= top; i--)
    {
        matrix[i][left] = arr[index++];
    }
    left++;

    if (top <= bottom)
    {
        for (int i = top - 1; i < middle; i++)
        {
            matrix[left - 1][i] = arr[index++];
        }
    }

    fillSpiralFromMiddle(matrix, arr, top, bottom, left, right, index, middle);
}

void fillSpiralFromMiddleRight(int matrix[100][100], int arr[], int top, int bottom, int left, int right, int index, int middle)
{
    if (top > bottom || left > right)
        return;

    for (int i = middle; i <= bottom; i++)
    {
        matrix[i][right] = arr[index++];
    }
    right--;

    for (int i = right; i >= left; i--)
    {
        // printf("%d %d\n", bottom, i);
        matrix[bottom][i] = arr[index++];
    }
    bottom--;

    for (int i = bottom; i >= top; i--)
    {
        matrix[i][left] = arr[index++];
    }
    left++;

    for (int i = left; i <= right; i++)
    {
        matrix[top][i] = arr[index++];
    }
    top++;

    for (int i = left - 1; i < middle; i++)
    {
        matrix[i][right + 1] = arr[index++];
    }

    fillSpiralFromMiddleRight(matrix, arr, top, bottom, left, right, index, middle);
}

int main()
{
    int matrix[100][100], rows, cols;
    scanf("%d%d", &rows, &cols);
    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int arr[10000] = {0};
    int length = matrixToArray(matrix, arr, rows, cols);
    insertionSort(arr, length);

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    fillSpiralFromLeft(matrix, arr, top, bottom, left, right, 0);
    printMatrix(matrix, rows, cols);

    top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    fillSpiralFromRight(matrix, arr, top, bottom, left, right, 0);
    printMatrix(matrix, rows, cols);

    top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int middle = cols / 2;
    fillSpiralFromMiddle(matrix, arr, top, bottom, left, right, 0, middle);
    printMatrix(matrix, rows, cols);

    top = 0, bottom = rows - 1, left = 0, right = cols - 1, rows / 2;
    fillSpiralFromMiddleRight(matrix, arr, top, bottom, left, right, 0, middle);
    printMatrix(matrix, rows, cols);

    getch();
    return 0;
}