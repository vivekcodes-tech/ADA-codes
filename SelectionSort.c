#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;

    for(i = 0; i < n - 1; i++) {
        min_idx = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }

        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, i;
    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));

    for(i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();

    selectionSort(arr, n);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}