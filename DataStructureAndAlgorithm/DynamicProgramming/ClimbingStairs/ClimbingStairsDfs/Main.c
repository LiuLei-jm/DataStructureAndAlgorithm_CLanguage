#include <stdio.h>
#include <stdlib.h>

int dfs(int i);
int climbingStairsDFS(int n);

int main(){
    int res = climbingStairsDFS(5);
    printf("%d\n", res);

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