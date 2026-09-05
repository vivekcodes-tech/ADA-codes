#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10000;
    }
}

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    if (n <= 5000)
    {
        printf("Please enter a number greater than 5000.\n");
        return 0;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory not allocated.\n");
        return -1;
    }

    srand(time(NULL));

    generateRandomNumber(arr, n);

    // Select a random key from the array
    int randomIndex = rand() % n;
    int key = arr[randomIndex];

    // Display the key and its original index
    printf("\nKey selected for searching: %d\n", key);
    printf("Original index of key: %d\n", randomIndex);

    clock_t start = clock();

    int result;
    for (int i = 0; i < 1000; i++)
    {
        result = linearSearch(arr, n, key);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Key found at index: %d\n", result);
    printf("Average time taken for linear search in %d elements: %lf seconds\n",
           n, time_taken);

    free(arr);

    return 0;
}