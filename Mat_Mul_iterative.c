#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, k;

    printf("Enter matrix size (n x n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    srand(time(NULL));

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
    clock_t start, end;

    start = clock();

    // Matrix Multiplication
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}