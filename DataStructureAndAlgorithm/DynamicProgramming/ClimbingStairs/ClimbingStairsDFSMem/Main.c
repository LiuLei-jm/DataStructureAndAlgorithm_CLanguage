#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dfs(int i, int *mem);
int climbingStairsDFSMem(int n);

int main()
{
    int res;
    int n = 9;
    res = climbingStairsDFSMem(n);
    printf("爬%d阶楼梯共有%d种方案。\n", n, res);

    return 0;
}

int dfs(int i, int *mem)
{
    if (i == 1 || i == 2)
        return i;
    if (mem[i] != -1)
        return mem[i];
    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    mem[i] = count;
    return count;
}

int climbingStairsDFSMem(int n)
{
    int *mem = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i <= n; i++)
    {
        mem[i] = -1;
    }
    int result = dfs(n, mem);
    free(mem);
    return result;
}