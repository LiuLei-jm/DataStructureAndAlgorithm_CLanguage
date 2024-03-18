#include "Array.h"

int RandomAccess(int *nums, int size){
    int randomIndex = rand() % size;   
    int randomNumber = nums[randomIndex];
    return randomNumber;
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
    for(int i = 0; i < size ; i++){
        printf("%d ", nums[i]);
    }   
    putchar('\n');
}
