#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

int minPathSumDFS(int grid[MAX_SIZE][MAX_SIZE], int i, int j);
int minPathSumDFSMem(int grid[MAX_SIZE][MAX_SIZE], int mem[MAX_SIZE][MAX_SIZE], int i, int j);
int minPathSumDP(int grid[MAX_SIZE][MAX_SIZE], int n, int m);
int myMin(int a, int b);

int main()
{
    int grid[MAX_SIZE][MAX_SIZE] = {
        {1, 3, 1, 5},
        {2, 2, 4, 2},
        {5, 3, 2, 1},
        {4, 3, 5, 2}};
    int mem[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            mem[i][j] = -1;
        }
    }
    int res;
    // res = minPathSumDFS(grid, 3, 3);
    // res = minPathSumDFSMem(grid, mem, 3, 3);
    res = minPathSumDP(grid, MAX_SIZE, MAX_SIZE);
    printf("从左上角到右下角的最小路径和为%d.\n", res);

    return 0;
}

int minPathSumDP(int grid[MAX_SIZE][MAX_SIZE], int n, int m)
{
    int **dp = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        dp[i] = calloc(m, sizeof(int));
    }
    dp[0][0] = grid[0][0];
    for (int j = 1; j < m; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = myMin(dp[i][j - 1], dp[i - 1][j]) + grid[i][j];
        }
    }
    int res = dp[n - 1][m - 1];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", dp[i][j]);
        }
        putchar('\n');
    }
    for (int i = 0; i < n; i++)
        free(dp[i]);
    free(dp);
    return res;
}

int minPathSumDFSMem(int grid[MAX_SIZE][MAX_SIZE], int mem[MAX_SIZE][MAX_SIZE], int i, int j)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int up = minPathSumDFSMem(grid, mem, i - 1, j);
    int left = minPathSumDFSMem(grid, mem, i, j - 1);
    mem[i][j] = myMin(left, up) != INT_MAX ? myMin(left, up) + grid[i][j] : INT_MAX;
    return mem[i][j];
}

int minPathSumDFS(int grid[MAX_SIZE][MAX_SIZE], int i, int j)
{
    if (i == 0 && j == 0)
        return grid[0][0];
    if (i < 0 || j < 0)
        return INT_MAX;
    int up = minPathSumDFS(grid, i - 1, j);
    int left = minPathSumDFS(grid, i, j - 1);
    return myMin(left, up) != INT_MAX ? myMin(left, up) + grid[i][j] : INT_MAX;
}

int myMin(int a, int b)
{
    return a > b ? b : a;
}