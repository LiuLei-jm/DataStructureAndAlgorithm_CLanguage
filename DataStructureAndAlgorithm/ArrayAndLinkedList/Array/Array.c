#include "Array.h"

int RandomAccess(int *nums, int size){
    int randomIndex = rand() % size;
    int randomNum = nums[randomIndex];
    return randomNum;
}

void Insert(int *nums, int size, int num, int index){
    for(int i = size - 1; i > index; i--){
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

void RemoveItem(int *nums, int size, int index){
    for(int i = index; i < size - 1; i++){
        nums[i] = nums[i + 1];
    }
}

void Traverse(int *nums, int size){
    int count = 0;
    for(int i = 0; i < size; i++){
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

int Find(int *nums, int size, int target){
    for(int i = 0; i < size; i++){
        if(nums[i] == target)
        return i;
    }
    return -1;
}

int *Extend(int *nums, int size, int enlarge){
    int *res = (int *)malloc(sizeof(int)*(size+enlarge));
    for(int i = 0; i < size; i++){
        res[i] = nums[i];
    }
    for(int i = size; i < size + enlarge; i++){
        res[i] = 0;
    }
    return res;
}