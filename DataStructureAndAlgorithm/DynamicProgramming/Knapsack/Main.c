#include <stdio.h>
#include <stdlib.h>

int knapsackDFS(int wgt[], int val[], int i, int c);
int knapsackDFSMem(int wgt[], int val[], int mem[5][51], int i, int c);
int knapsackDP(int wgt[], int val[], int cap, int wgtSize);
int knapsackDPComp(int wgt[], int val[], int cap, int wgtSize);
int myMax(int a, int b);

int main()
{
    int wgt[5] = {10, 20, 30, 40, 50};
    int val[5] = {50, 120, 150, 210, 240};
    // int mem[5][51];
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 51; j++)
    //     {
    //         mem[i][j] = -1;
    //     }
    // }
    int res;
    // res = knapsackDFS(wgt, val, 5, 50);
    // res = knapsackDFSMem(wgt, val, mem, 4, 50);
    // res = knapsackDP(wgt, val, 50, 4);
    res = knapsackDPComp(wgt, val, 50, 4);
    printf("不超过背包容量的最大物品价值为%d\n", res);

    return 0;
}

int knapsackDPComp(int wgt[], int val[], int cap, int wgtSize){
    int n = wgtSize;
    int *dp = calloc(cap + 1, sizeof(int));
    for(int i = 1; i <= n; i++){
        for(int c = cap; c >= 1; c--){
            if(wgt[i-1] <= c){
                dp[c] = myMax(dp[c], dp[c- wgt[i-1]] + val[i-1]);
            }
        }
    }
    int res = dp[cap];
    free(dp);
    return res;
}

int knapsackDP(int wgt[], int val[], int cap, int wgtSize){
    int n = wgtSize;
    int **dp = malloc((n + 1) * sizeof(int *));
    for(int i = 0; i <= n; i++){
        dp[i] = calloc(cap + 1, sizeof(int));
    }
    for(int i = 1; i <= n; i++){
        for(int c = 1; c <= cap; c++){
            if(wgt[i - 1] > c){
                dp[i][c] = dp[i-1][c];
            }
            else{
                dp[i][c] = myMax(dp[i-1][c], dp[i-1][c-wgt[i-1]] + val[i-1]);
            }
        }
    }
    int res = dp[n][cap];
    for(int i = 0; i <= n; i++){
        free(dp[i]);
    }
    return res;
}

int knapsackDFSMem(int wgt[], int val[], int mem[5][51], int i, int c)
{
    if (i == 0 || c == 0)
        return 0;
    if (mem[i][c] != -1)
    {
        return mem[i][c];
    }
    if (wgt[i - 1] > c)
    {
        return knapsackDFSMem(wgt, val, mem, i - 1, c);
    }
    int no = knapsackDFSMem(wgt, val, mem, i - 1, c);
    int yes = knapsackDFSMem(wgt, val, mem, i - 1, c - wgt[i - 1]) + val[i - 1];
    mem[i][c] = myMax(no, yes);
    return mem[i][c];
}

int knapsackDFS(int wgt[], int val[], int i, int c)
{
    if (i == 0 || c == 0)
        return 0;
    if (wgt[i - 1] > c)
        return knapsackDFS(wgt, val, i - 1, c);
    int no = knapsackDFS(wgt, val, i - 1, c);
    int yes = knapsackDFS(wgt, val, i - 1, c - wgt[i - 1]) + val[i - 1];
    return myMax(no, yes);
}

int myMax(int a, int b)
{
    return a > b ? a : b;
}