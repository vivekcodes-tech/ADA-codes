#include <stdio.h>

void recursiveActivitySelector(int start[], int finish[], int n, int k)
{
    int m = k + 1;

    while (m < n && start[m] < finish[k])
        m++;

    if (m < n)
    {
        printf("Activity %d (%d, %d)\n",
               m + 1, start[m], finish[m]);

        recursiveActivitySelector(start, finish, n, m);
    }
}

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

    printf("Activity 1 (%d, %d)\n", start[0], finish[0]);

    recursiveActivitySelector(start, finish, n, 0);

    return 0;
}