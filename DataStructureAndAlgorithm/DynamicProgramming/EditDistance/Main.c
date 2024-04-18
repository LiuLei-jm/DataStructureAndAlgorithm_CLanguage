#include <stdio.h>
#include <stdlib.h>

int editDistanceDP(char *s, char *t, int n, int m);
int editDistanceDPComp(char *s, char *t, int n, int m);
int myMin(int a, int b);

int main()
{
    char *s = "bag";
    char *t = "pack";
    // int res = editDistanceDP(s, t, 3, 4);
    int res = editDistanceDPComp(s, t, 3, 4);
    printf("%d\n", res);

    return 0;
 }

int editDistanceDPComp(char *s, char *t, int n, int m){
    int *dp = calloc(m + 1, sizeof(int));
    for(int j = 1; j <= m; j++){
        dp[j] = j;
    }
    for(int i = 1; i <= n; i++){
        int leftup = dp[0];
        dp[0] = i;
        for(int j = 1; j<= m; j++){
            int temp = dp[j];
            if(s[i-1] == t[j-1]){
                dp[j] = leftup;
            }
            else{
                dp[j] = myMin(myMin(dp[j-1], dp[j]), leftup)+1;
            }
        }
    }
    int res = dp[m];
    free(dp);
    return res;
}

int myMin(int a, int b)
{
    return a > b ? b : a;
}

int editDistanceDP(char *s, char *t, int n, int m)
{
    int **dp = malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
    {
        dp[i] = calloc(m + 1, sizeof(int));
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = myMin(myMin(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    int res = dp[n][m];
    for (int i = 0; i <= n; i++)
    {
        free(dp[i]);
    }
    free(dp);
    return res;
}