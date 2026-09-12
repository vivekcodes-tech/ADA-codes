#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start and finish times (sorted by finish time):\n");

    for (int i = 0; i < n; i++)
    {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    printf("\nSelected Activities:\n");

    int lastSelected = 0;

    printf("Activity 1 (%d, %d)\n",
           start[0], finish[0]);

    for (int i = 1; i < n; i++)
    {
        if (start[i] >= finish[lastSelected])
        {
            printf("Activity %d (%d, %d)\n",
                   i + 1, start[i], finish[i]);

            lastSelected = i;
        }
    }

    return 0;
}