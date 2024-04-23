#include <stdio.h>
#include <stdlib.h>

int climbingStairsDP(int n);
int climbingStairsDPComp(int n);

int main()
{
    int res;
    int n = 9;
    res = climbingStairsDPComp(n);
    printf("爬%d阶楼梯共有%d种方案。\n", n, res);

    return 0;
}

int climbingStairsDP(int n)
{
    if (n == 1 || n == 2)
        return n;
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int result = dp[n];
    free(dp);
    return result;
}

int climbingStairsDPComp(int n)
{
    if (n == 1 || n == 2)
        return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++)
    {
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}