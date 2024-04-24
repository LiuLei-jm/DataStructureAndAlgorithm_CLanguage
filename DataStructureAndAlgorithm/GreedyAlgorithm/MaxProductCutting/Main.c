#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxProductCutting(int n);

int main(){
    int n = 58;

    int res = maxProductCutting(n);
    printf("最大切分乘积为%d.\n", res);

    return 0;
}

int maxProductCutting(int n){
    if(n <= 3){
        return 1 * (n - 1);
    }
    int a = n / 3;
    int b = n % 3;
    if(b == 1){
        return pow(3, a - 1) * 2 * 2;
    }
    if(b == 2){
        return pow(3, a)* 2;
    }
    return pow(3, a);
}