#include <stdio.h>

int main() {
    int n;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    int dp[n];

    if (n >= 1)
        dp[0] = 0;

    if (n >= 2)
        dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", dp[i]);
    }

    return 0;
}