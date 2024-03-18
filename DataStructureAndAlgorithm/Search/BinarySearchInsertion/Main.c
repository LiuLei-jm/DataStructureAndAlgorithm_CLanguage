#include <stdio.h>
#include <stdlib.h>
#include "Array.c"

// 二分查找插入点(无重复元素)
int BinarySearchInsertionSimple(int *nums, int numSize, int target);
// 二分查找插入点(存在重复元素)
int BinarySearchInsertion(int *nums, int numSize, int target);

int main()
{
    int nums[20] = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    int nums1[20] = {1, 3, 6, 6, 6, 6, 6, 10, 12, 15};

    Traverse(nums, 10);
    int index = BinarySearchInsertionSimple(nums, 20, 6);
    Insert(nums, 20, 6, index);
    Traverse(nums, 11);
    printf("\n===================\n");
    Traverse(nums1, 10);
    index = BinarySearchInsertion(nums1, 20, 6);
    Insert(nums1, 20, 5, index);
    Traverse(nums1,11);


    system("Pause");
    return 0;
}

int BinarySearchInsertion(int *nums, int numSize, int target)
{
    int i = 0, j = numSize - 1;
    while (i <= j)
    {
        int m = i + (j - 1) / 2;
        if (nums[m] < target)
        {
            i = m + 1;
        }
        else if (nums[m] > target)
        {
            j = m - 1;
        }
        else
        {
            j = m - 1;
        }
    }
    return i;
}

int BinarySearchInsertionSimple(int *nums, int numSize, int target)
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
            return m;
    }
    return i;
}
