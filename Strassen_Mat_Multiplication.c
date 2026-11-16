#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if(n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int m = n / 2;

    int A11[m][m], A12[m][m], A21[m][m], A22[m][m];
    int B11[m][m], B12[m][m], B21[m][m], B22[m][m];
    int M1[m][m], M2[m][m], M3[m][m], M4[m][m];
    int M5[m][m], M6[m][m], M7[m][m];
    int T1[m][m], T2[m][m];

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+m];
            A21[i][j]=A[i+m][j];
            A22[i][j]=A[i+m][j+m];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+m];
            B21[i][j]=B[i+m][j];
            B22[i][j]=B[i+m][j+m];
        }
    }

    add(m,A11,A22,T1);
    add(m,B11,B22,T2);
    strassen(m,T1,T2,M1);

    add(m,A21,A22,T1);
    strassen(m,T1,B11,M2);

    sub(m,B12,B22,T2);
    strassen(m,A11,T2,M3);

    sub(m,B21,B11,T2);
    strassen(m,A22,T2,M4);

    add(m,A11,A12,T1);
    strassen(m,T1,B22,M5);

    sub(m,A21,A11,T1);
    add(m,B11,B12,T2);
    strassen(m,T1,T2,M6);

    sub(m,A12,A22,T1);
    add(m,B21,B22,T2);
    strassen(m,T1,T2,M7);

    int C11[m][m], C12[m][m], C21[m][m], C22[m][m];

    add(m,M1,M4,T1);
    sub(m,T1,M5,T2);
    add(m,T2,M7,C11);

    add(m,M3,M5,C12);

    add(m,M2,M4,C21);

    sub(m,M1,M2,T1);
    add(m,T1,M3,T2);
    add(m,T2,M6,C22);

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            C[i][j] = C11[i][j];
            C[i][j+m] = C12[i][j];
            C[i+m][j] = C21[i][j];
            C[i+m][j+m] = C22[i][j];
        }
    }
}

int main()
{
    int n;

    printf("Enter matrix size (power of 2): ");
    scanf("%d",&n);

    int A[n][n], B[n][n], C[n][n];

    srand(time(NULL));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            A[i][j] = rand()%10;
            B[i][j] = rand()%10;
        }
    }

    clock_t start = clock();

    strassen(n,A,B,C);

    clock_t end = clock();

    printf("Execution Time = %f seconds\n",
           (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
}
