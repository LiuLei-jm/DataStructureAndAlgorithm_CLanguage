#include <stdio.h>
#include <stdlib.h>
#include "Tree.c"

int main(){
    SearchTree T = NULL;
    int nums[10] = {5,2,3,1,4,7,8,9,6,10};
    for(int i = 0; i < 10; i++){
        T = Insert(nums[i], T);
    }
    PrintTree(T);
    printf("\n");
    T = Delete(3, T);
    PrintTree(T);
    printf("\n");
    T = MakeEmpty(T);
    system("Pause");
    return 0;
}