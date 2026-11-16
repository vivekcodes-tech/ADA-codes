#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500

int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
int n;

void multiplyRow(int row)
{
    if(row >= n)
        return;

    int j, k;

    for(j = 0; j < n; j++)
    {
        C[row][j] = 0;

        for(k = 0; k < n; k++)
        {
            C[row][j] += A[row][k] * B[k][j];
        }
    }

    multiplyRow(row + 1);
}

int main()
{
    int i, j;

    printf("Enter matrix size (n x n): ");
    scanf("%d", &n);

    srand(time(NULL));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    }

    clock_t start = clock();

    multiplyRow(0);

    clock_t end = clock();

    printf("Execution Time = %f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}