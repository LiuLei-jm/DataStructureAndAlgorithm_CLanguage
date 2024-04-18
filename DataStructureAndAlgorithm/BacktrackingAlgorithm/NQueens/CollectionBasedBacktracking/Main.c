#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 501

void backtrack(int row, int n, char state[n][n+1], char ***res, int *resSize, bool cols[n], bool diags1[2 * n - 1], bool diags2[2 * n - 1]);
char ***nQueens(int n, int *returnSize);

int main()
{
    int n;
    int returnSize;
    char ***res;
    printf("Please enter a number:");
    scanf("%d", &n);
    res = nQueens(n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", res[i][j]);
        }
        printf("===========res%d\n",i+1);
    }

     for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            free(res[i][j]);
        }
        free(res[i]);
    }
    free(res);

     system("Pause");
    return 0;
}

void backtrack(int row, int n, char state[n][n+1], char ***res, int *resSize, bool cols[n], bool diags1[2 * n - 1], bool diags2[2 * n - 1])
{
    if (row == n)
    {
        res[*resSize] = (char **)malloc(sizeof(char *) * n);
        for (int i = 0; i < n; ++i)
        {
            res[*resSize][i] = (char *)malloc(sizeof(char) * (n + 1));
            strncpy(res[*resSize][i], state[i], n+1);
        }
        (*resSize)++;
        return;
    }
    for (int col = 0; col < n; col++)
    {
        int diag1 = row - col + n - 1;
        int diag2 = row + col;
        if (!cols[col] && !diags1[diag1] && !diags2[diag2])
        {
            state[row][col] = 'Q';
            cols[col] = diags1[diag1] = diags2[diag2] = true;
            backtrack(row + 1, n, state, res, resSize, cols, diags1, diags2);
            state[row][col] = '.';
            cols[col] = diags1[diag1] = diags2[diag2] = false;
        }
    }
}

char ***nQueens(int n, int *returnSize)
{
    char state[n][n + 1];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            state[i][j] = '#';
        }
        state[i][n] = '\0';
    }
    bool cols[n];
    bool diags1[2 * n - 1];
    bool diags2[2 * n - 1];
    memset(cols, 0, n * sizeof(bool));
    memset(diags1, 0, (2 * n - 1) * sizeof(bool));
    memset(diags2, 0, (2 * n - 1) * sizeof(bool));

    char ***res = (char ***)malloc(sizeof(char **) * MAX_SIZE);
    *returnSize = 0;
    backtrack(0, n, state, res, returnSize, cols, diags1, diags2);
    return res;
}