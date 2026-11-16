
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100];
    int dp[101][101];
    int m, n, i, j;

    printf("Enter first string: ");
    scanf("%99s", str1);

    printf("Enter second string: ");
    scanf("%99s", str2);

    m = strlen(str1);
    n = strlen(str2);

    // Initialize DP table
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1])
                           ? dp[i - 1][j]
                           : dp[i][j - 1];
        }
    }
    // Reconstruct LCS
    char lcs[101];
    int index = dp[m][n];

    lcs[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("\nLength of LCS: %d", dp[m][n]);
    printf("\nLongest Common Subsequence: %s\n", lcs);

    return 0;
}
