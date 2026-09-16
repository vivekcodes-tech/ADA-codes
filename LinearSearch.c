#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int a[], int size, int target)
{
    for(int i = 0; i < size; i++)
    {
        if(a[i] == target)
            return i;
    }
    return -1;
}

int main()
{
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    int *a = (int *)malloc(size * sizeof(int));

    if(a == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    srand(time(NULL));

    for(int i = 0; i < size; i++)
    {
        a[i] = rand() % 10000;
    }

    int target = a[size - 1];   // Worst case

    int iterations = 10000;

    clock_t start = clock();

    int result = -1;

    for(int i = 0; i < iterations; i++)
    {
        result = linearSearch(a, size, target);
    }

    clock_t end = clock();

    double total_time =
        (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nTarget Value : %d\n", target);
    printf("Found at Index : %d\n", result);
    printf("Total Time : %lf seconds\n", total_time);

    free(a);

    return 0;
}