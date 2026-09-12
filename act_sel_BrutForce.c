#include <stdio.h>

int main() {
    int n, i, j, mask;
    
    printf("Enter number of activities: ");
    scanf("%d", &n);

    int start[n], finish[n];

    printf("Enter start and finish times:\n");
    for(i = 0; i < n; i++) {
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    int maxCount = 0;
    int bestMask = 0;

    for(mask = 0; mask < (1 << n); mask++) {
        int valid = 1;
        int count = 0;

        for(i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                count++;

                for(j = i + 1; j < n; j++) {
                    if(mask & (1 << j)) {
                        if(!(finish[i] <= start[j] ||
                             finish[j] <= start[i])) {
                            valid = 0;
                            break;
                        }
                    }
                }
            }
            if(!valid)
                break;
        }

        if(valid && count > maxCount) {
            maxCount = count;
            bestMask = mask;
        }
    }
    printf("\nMaximum number of non-overlapping activities = %d\n",
           maxCount);

    printf("Selected Activities:\n");
    for(i = 0; i < n; i++) {
        if(bestMask & (1 << i)) {
            printf("Activity %d (%d, %d)\n",
                   i + 1, start[i], finish[i]);
        }
    }
    return 0;
}