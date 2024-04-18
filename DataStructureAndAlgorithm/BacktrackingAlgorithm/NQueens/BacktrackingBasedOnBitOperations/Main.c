#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **generateBoard(int *queens, int n);
void solve(char ***solutions, int *queens, int n, int row, int columns, int diagonals1, int diagonals2, int* returnSize);
char ***solveNQueens(int n, int *returnSize);

int main()
{
    int returnSize = 0;
    char ***sulotions;
    int n = 0;
    printf("Please enter a number:\n");
    scanf("%d", &n);

    sulotions = solveNQueens(n, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%s\n", sulotions[i][j]);
            free(sulotions[i][j]);
        }
        printf("============res%d\n", i+1);
        free(sulotions[i]);
    }
    free(sulotions);
    system("Pause");
    return 0;
}

char **generateBoard(int *queens, int n)
{
    char **board = (char **)malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
    {
        board[i] = (char *)malloc(sizeof(char) * (n + 1));
        for (int j = 0; j < n; j++)
            board[i][j] = '.';
        board[i][queens[i]] = 'Q', board[i][n] = 0;
    }
    return board;
}

void solve(char ***solutions, int *queens, int n, int row, int columns, int diagonals1, int diagonals2, int* returnSize)
{
    if (row == n)
    {
        char **board = generateBoard(queens, n);
        solutions[(*returnSize)++] = board;
    }
    else
    {
        int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
        while (availablePositions != 0)
        {
            int position = availablePositions & (-availablePositions);
            availablePositions = availablePositions & (availablePositions - 1);
            int column = __builtin_ctz(position);
            queens[row] = column;
            solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1, returnSize);
            queens[row] = -1;
        }
    }
}

char ***solveNQueens(int n, int *returnSize)
{
    char ***solutions = malloc(sizeof(char **) * 501);
    *returnSize = 0;
    int queens[n];
    memset(queens, -1, sizeof(queens));
    solve(solutions, queens, n, 0, 0, 0, 0, returnSize);
    return solutions;
}