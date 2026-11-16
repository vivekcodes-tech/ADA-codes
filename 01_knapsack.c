#include <stdio.h>

int main() {
    int n, W;
    int wt[100], val[100];
    int dp[101][101];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter capacity: ");
    scanf("%d", &W);

    printf("Enter weight and profit of each item:\n");
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (wt[i] <= w) {
                int include = val[i] + dp[i-1][w-wt[i]];
                int exclude = dp[i-1][w];

                dp[i][w] = (include > exclude)
                           ? include : exclude;
            }
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    printf("Maximum profit = %d\n", dp[n][W]);

    return 0;
}