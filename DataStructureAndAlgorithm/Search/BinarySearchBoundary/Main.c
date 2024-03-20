#include <stdio.h>
#include <stdlib.h>

int BinarySearchInsertion(int *nums, int numSize, int target);
// 二分查找最左一个
int BinarySearchLeftEdge(int *nums, int numSize, int target);
// 二分查找最右一个
int BinarySearchRightEdge(int *nums, int numSize, int target);


int main()
{
    int nums[10] = {1, 3, 6, 6, 6, 6, 6, 10, 12, 15};
    int index = BinarySearchLeftEdge(nums, 10, 6);
    printf("Left index %d\n", index);
    
    index = BinarySearchRightEdge(nums, 10, 6);
    printf("Right index: %d\n", index);

    system("Pause");
    return 0;
}

int BinarySearchInsertion(int *nums, int numSize, int target)
{
    int i = 0, j = numSize - 1;
    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (nums[m] < target)
            i = m + 1;
        else if (nums[m] > target)
            j = m - 1;
        else
            j = m - 1;
    }
    return i;
}

int BinarySearchLeftEdge(int *nums, int numSize, int target)
{
    int i = BinarySearchInsertion(nums, numSize, target);
    if (i == numSize || nums[i] != target)
    {
        return -1;
    }
    return i;
}

int BinarySearchRightEdge(int *nums, int numSize, int target){
    int i = BinarySearchInsertion(nums, numSize, target + 1);
    int j = i - 1;
    if(j == -1 || nums[j] != target) return -1;
    return j;
}