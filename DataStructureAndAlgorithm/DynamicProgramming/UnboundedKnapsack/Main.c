#include <stdio.h>
#include <stdlib.h>

int unboundedKnapsackDP(int wgt[], int val[], int cap, int wgtSize);
int unboundedKnapsackDPComp(int wgt[], int val[], int cap, int wgtSize);
int myMax(int a, int b);

int main()
{
    int wgt[5] = {10, 20, 30, 40, 50};
    int val[5] = {50, 120, 150, 210, 240};
    int res;
    // res = unboundedKnapsackDP(wgt, val, 50, 4);
    res = unboundedKnapsackDPComp(wgt, val, 50, 4);
    printf("%d\n", res);
    return 0;
}

int unboundedKnapsackDPComp(int wgt[], int val[], int cap, int wgtSize)
{
    int n = wgtSize;
    int *dp = calloc(cap + 1, sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        for (int c = 1; c <= cap; c++)
        {
            if (wgt[i - 1] > c)
            {
                dp[c] = dp[c];
            }
            else
            {
                dp[c] = myMax(dp[c], dp[c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[cap];
    free(dp);
    return res;
}

int myMax(int a, int b)
{
    return a > b ? a : b;
}

int unboundedKnapsackDP(int wgt[], int val[], int cap, int wgtSize)
{
    int n = wgtSize;
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = calloc(cap + 1, sizeof(int));
    }
    for (int i = 1; i <= n; i++)
    {
        for (int c = 1; c <= cap; c++)
        {
            if (wgt[i - 1] > c)
            {
                dp[i][c] = dp[i - 1][c];
            }
            else
            {
                dp[i][c] = myMax(dp[i - 1][c], dp[i][c - wgt[i - 1]] + val[i - 1]);
            }
        }
    }
    int res = dp[n][cap];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return res;
}