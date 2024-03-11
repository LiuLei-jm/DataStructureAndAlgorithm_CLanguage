#include <stdio.h>
#include <stdlib.h>
#include "array.c"

int main(){
    int *arr;
    int nums[5] = {1, 3, 2, 5, 4};
    int randNum = RandomAccess(nums, 5);
    printf("%d\n", randNum);

    RemoveItem(nums,5,2);
    Traverse(nums,4);
    Insert(nums, 5, 10,2);
    Traverse(nums, 5);
    
    int index = Find(nums, 5, 10);
    printf("Index: %d\n", index);

    arr = Extend(nums,5, 10);
    Insert(arr, 10, 11, 5);
    Insert(arr, 10, 12, 6);
    Insert(arr, 10, 13, 7);
    Traverse(arr, 10);

    free(arr);
    system("Pause");
    return 0;
}