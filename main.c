#include <stdio.h>
#include <stdlib.h>

void neighborsSum(int matrix[][100], unsigned n, unsigned m)
{
    int isSuchPairs = 0;
    int S;
    printf("Enter the sum S: ");
    scanf("%d", &S);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m / 2; j++)
        {
            int sum = 0;
            if (j + 2 < m)
                sum = matrix[i][j] + matrix[i][j + 2];
            if (sum == S)
            {
                isSuchPairs = 1;
                printf("R%d pairs: \na[%d][%d]=%d + a[%d][%d]=%d\n\n", i + 1, i, j, matrix[i][j], i, j + 2, matrix[i][j + 2]);
            }
        }
    if (!isSuchPairs)
        printf("There is not such elements");
}

int main()
{
    int a[100][100];
    unsigned n, m;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    printf("Enter the number of columns: ");
    scanf("%d", &m);
    for (unsigned i = 0; i < n; i++)
        for (unsigned j = 0; j < m; j++)
        {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    // neighborsSum(a, n, m);
    system("pause");
    return 0;
}