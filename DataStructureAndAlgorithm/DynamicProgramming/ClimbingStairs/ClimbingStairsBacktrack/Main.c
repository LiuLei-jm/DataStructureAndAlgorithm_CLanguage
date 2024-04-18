#include <stdio.h>
#include <stdlib.h>

void backtracking(int *choices, int state, int n, int *res, int len);
int climbingStairsBacktrack(int n);

int main()
{
    int res = climbingStairsBacktrack(3);
    printf("%d\n", res);

    system("Pause");
    return 0;
}

void backtracking(int *choices, int state, int n, int *res, int len)
{
    if (state == n){
        res[0]++;
    }
    for (int i = 0; i < len; i++)
    {
        int choice = choices[i];
        if (state + choice > n)
            continue;
        backtracking(choices, state + choice, n, res, len);
    }
}

int climbingStairsBacktrack(int n)
{
    int choices[2] = {1, 2};
    int state = 0;
    int *res = (int *)malloc(sizeof(int));
    *res = 0;
    int len = sizeof(choices) / sizeof(int);
    backtracking(choices, state, n, res, len);
    int result = *res;
    free(res);
    return result;
}