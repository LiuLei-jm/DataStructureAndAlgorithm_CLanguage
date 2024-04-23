#include <stdio.h>
#include <stdlib.h>

int coinChangeDP(int Coins[], int amt, int coinsSize);
int coinChangeDPComp(int Coins[], int amt, int coinsSize);
int coinChangeIIDP(int Coins[], int amt, int coinsSize);
int coinChangeIIDPComp(int Coins[], int amt, int coinsSize);
int myMin(int a, int b);

int main()
{
    int Coins[3] = {1, 2, 5};
    int amt = 5;
    // int res = coinChangeDP(Coins, 11, 3);
    // int res = coinChangeDPComp(Coins, 11, 3);
    // int res = coinChangeIIDP(Coins, 5, 3);
    int res = coinChangeIIDPComp(Coins, amt, 3);
    printf("凑到目标金额所需的最少硬币数量为%d\n", res);

    return 0;
}

int coinChangeIIDPComp(int Coins[], int amt, int coinsSize)
{
    int n = coinsSize;
    int *dp = calloc(amt + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (Coins[i - 1] > a)
            {
                dp[a] = dp[a];
            }
            else
            {
                dp[a] = dp[a] + dp[a - Coins[i - 1]];
            }
        }
    }
    int res = dp[amt];
    free(dp);
    return res;
}

int coinChangeIIDP(int Coins[], int amt, int coinsSize)
{
    int n = coinsSize;
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = calloc(amt + 1, sizeof(int));
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (Coins[i - 1] > a)
            {
                dp[i][a] = dp[i - 1][a];
            }
            else
            {
                dp[i][a] = dp[i - 1][a] + dp[i][a - Coins[i - 1]];
            }
        }
    }
    int res = dp[n][amt];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return res;
}

int coinChangeDPComp(int Coins[], int amt, int coinsSize)
{
    int n = coinsSize;
    int MAX = amt + 1;
    int *dp = malloc((amt + 1) * sizeof(int));
    for (int j = 1; j <= amt; j++)
    {
        dp[j] = MAX;
    }
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (Coins[i - 1] > a)
            {
                dp[a] = dp[a];
            }
            else
            {
                dp[a] = myMin(dp[a], dp[a - Coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[amt] != MAX ? dp[amt] : -1;
    free(dp);
    return res;
}

int myMin(int a, int b)
{
    return a > b ? b : a;
}

int coinChangeDP(int Coins[], int amt, int coinsSize)
{
    int n = coinsSize;
    int MAX = amt + 1;
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = calloc(amt + 1, sizeof(int));
    }
    for (int a = 1; a <= amt; a++)
    {
        dp[0][a] = MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= amt; a++)
        {
            if (Coins[i - 1] > a)
            {
                dp[i][a] = dp[i - 1][a];
            }
            else
            {
                dp[i][a] = myMin(dp[i - 1][a], dp[i][a - Coins[i - 1]] + 1);
            }
        }
    }
    int res = dp[n][amt] != MAX ? dp[n][amt] : -1;
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return res;
}