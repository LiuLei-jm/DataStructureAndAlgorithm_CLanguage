#include <stdio.h>
#include <stdlib.h>

int maxCapacity(int ht[], int htLength);
int myMin(int a, int b);
int myMax(int a, int b);

int main(){
    int ht[8] = {3,8,5,2,7,7,3,4};
    int res = maxCapacity(ht, 8);
    printf("最大容量为%d.\n",res);
    return 0;
}

int maxCapacity(int ht[], int htLength){
    int i = 0;
    int j = htLength - 1;
    int res = 0;
    while(i < j ){
        int capacity = myMin(ht[i],ht[j]) * (j - i);
        res = myMax(res, capacity);
        if(ht[i]< ht[j]){
            i++;
        }
        else{
            j--;
        }
    }
    return res;
}

int myMin(int a, int b){
    return a > b ? b : a;
}

int myMax(int a, int b){
    return a > b ? a : b;
}