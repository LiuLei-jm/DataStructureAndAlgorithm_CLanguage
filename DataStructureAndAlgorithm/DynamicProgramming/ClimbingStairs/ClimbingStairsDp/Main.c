#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

int climbingStairsDP(int n);
int climbingStairsDPComp(int n);

int main(){
    int res;
    double duration;
    start = clock();
    res = climbingStairsDPComp(1000);
    stop = clock();
    duration = (stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
    printf("%d\n", res);
    
    return 0;
}

int climbingStairsDP(int n){
    if(n == 1 || n == 2)
    return n;
    int *dp = (int *)malloc((n + 1) * sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    int result= dp[n];
    free(dp);
    return result;
}

int climbingStairsDPComp(int n){
    if( n == 1 || n == 2) return n;
    int a = 1, b = 2;
    for(int i = 3; i <= n; i++){
        int tmp = b;
        b = a + b;
        a = tmp;
    }
    return b;
}