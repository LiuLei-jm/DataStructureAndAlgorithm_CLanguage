#include <stdio.h>
#include <stdlib.h>

int dfs(int i);
int climbingStairsDFS(int n);

int main(){
    int n = 9;
    int res = climbingStairsDFS(n);
    printf("爬%d阶楼梯共有%d种方案\n",n, res);

    return 0;
}

int dfs(int i){
    if(i == 1 || i == 2)
    return i;   
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

int climbingStairsDFS(int n){
    return dfs(n);
}