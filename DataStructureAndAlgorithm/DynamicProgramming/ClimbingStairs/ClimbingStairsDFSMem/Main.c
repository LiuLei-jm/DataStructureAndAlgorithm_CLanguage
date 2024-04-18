#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

clock_t start, stop;

int dfs(int i, int *mem);
int climbingStairsDFSMem(int n);

int main(){
    int res;
    double duration;
    start = clock();
    res = climbingStairsDFSMem(1000);
    stop = clock();
    printf("tick: %f\n", (double)(stop - start));
    duration = (double)(stop - start) / CLK_TCK;
    printf("duration: %6.2e\n", duration);
    printf("%d\n", res);

    return 0;
}

int dfs(int i, int *mem){
    if(i == 1 || i == 2) return i;
    if(mem[i] != -1)
    return mem[i];
    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    mem[i] = count;
    return count;
}

int climbingStairsDFSMem(int n){
    int* mem = (int *)malloc((n + 1) * sizeof(int));
    for(int i = 0; i <= n; i++){
        mem[i] = -1;
    }
    int result = dfs(n, mem);
    free(mem);
    return result;
}