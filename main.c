#include <stdio.h>
#include <stdlib.h>

int numberOfPairs = 0, minPairsInRow = 0, maxPairsInRow = 0;
int rowWithMinPairs = 0, rowWithMaxPairs = 0;

void neighborsSum(int matrix[][100], unsigned n, unsigned m, int S)
{
    int pairs = 0;
    for (unsigned i = 0; i < n; i++)
    {
        int currentPairs = 0;
        for (unsigned j = 0; j < m / 2; j++)
        {
            int sum = 0;
            if (j + 2 < m)
                sum = matrix[i][j] + matrix[i][j + 2];
            if (sum == S)
            {
                printf("R%d pairs: \na[%d][%d]=%d + a[%d][%d]=%d\n\n", i + 1, i, j, matrix[i][j], i, j + 2, matrix[i][j + 2]);
                pairs++;
                currentPairs++;
            }
        }
        if (currentPairs > maxPairsInRow)
        {
            maxPairsInRow = currentPairs;
            rowWithMaxPairs = i;
        }
        if (currentPairs < minPairsInRow)
        {
            minPairsInRow = currentPairs;
            rowWithMinPairs = i;
        }
    }
    if (!pairs)
        printf("There is not such elements\n");
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
    int S;
    printf("Enter the sum S: ");
    scanf("%d", &S);
    // neighborsSum(a, n, m, S);
    system("pause");
    return 0;
}