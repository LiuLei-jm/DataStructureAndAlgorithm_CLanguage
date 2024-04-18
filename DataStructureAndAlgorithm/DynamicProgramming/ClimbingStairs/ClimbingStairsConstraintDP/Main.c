#include <stdio.h>
#include <stdlib.h>

int climbingStairsConstraintDP(int n);

int main()
{
    int res;
    res = climbingStairsConstraintDP(10);
    printf("%d\n", res);

    return 0;
}

int climbingStairsConstraintDP(int n)
{
    if (n == 1 || n == 2)
        return 1;
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = calloc(3, sizeof(int));
    }

    dp[1][1] = 1;
    dp[1][2] = 0;
    dp[2][1] = 0;
    dp[2][2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    int res=dp[n][1] + dp[n][2];
    for(int i = 0; i <= n; i++){
        free(dp[i]);
    }
    free(dp);
    return res;
}