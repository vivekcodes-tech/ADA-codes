#include <stdio.h>

int dp[100];

int fibonacci(int n) {
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    for (int i = 0; i < 100; i++)
        dp[i] = -1;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    return 0;
}