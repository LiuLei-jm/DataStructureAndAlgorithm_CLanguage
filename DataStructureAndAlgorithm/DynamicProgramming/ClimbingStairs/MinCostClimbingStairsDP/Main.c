#include <stdio.h>
#include <stdlib.h>

int minCostClimbingStairsDP(int cost[], int costSize);
int minCostClimbingStairsDPComp(int cost[], int costSize);
int myMin(int a, int b);

int main(){
    int cost[4] = {0, 1 ,10 ,1} ;
    int res;
    res = minCostClimbingStairsDPComp(cost, 4);
    printf("%d\n", res);

    return 0;
}

int minCostClimbingStairsDPComp(int cost[], int costSize){
    int n = costSize - 1;
    if(n == 1|| n == 2) return cost[n];
    int a = cost[1], b= cost[2];
    for(int i = 3; i <= n; i++){
        int tmp = b;
        b = myMin(a, tmp) + cost[i];
        a=tmp;
    }
    return b;
}

int minCostClimbingStairsDP(int cost[], int costSize){
    int n = costSize - 1;
    if(n == 1 || n == 2) return cost[n];
    int *dp = calloc(n + 1, sizeof(int));
    dp[1] = cost[1];
    dp[2] = cost[2];
    for(int i = 3; i <= n; i++){
        dp[i] = myMin(dp[i - 1], dp[i - 2])+cost[i];
    }
    int res= dp[n];
    free(dp);
    return res;
}

int myMin(int a, int b){
    return a > b ? b : a;
}