#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int a[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(a[mid] == target)
            return mid;

        if(a[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
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
        a[i] = rand() % 100000;
    }

    qsort(a, size, sizeof(int), compare);

    int target = a[size - 1];   // Worst case

    int iterations = 1000000;

    clock_t start = clock();

    int result = -1;

    for(int i = 0; i < iterations; i++)
    {
        result = binarySearch(a, size, target);
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