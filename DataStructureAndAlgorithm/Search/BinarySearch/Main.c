#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 双闭区间
int BinarySearch(int *nums, int len, int target);
// 左闭右开区间
int BinarySearchLCRO(int *nums, int len, int target);

int main()
{
    int nums[10] = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};

    int index = BinarySearch(nums, 10, 6);
    printf("Index: %d\n", index);
    
    index = BinarySearchLCRO(nums, 10, 8);
    printf("Index: %d\n", index);

    system("Pause");
    return 0;
}

int BinarySearchLCRO(int *nums, int len, int target)
{
    int head = 0;
    int tail = len;
    int middle;
    while (head < tail)
    {
        middle = head + (tail - head) / 2;
        if (nums[middle] < target)
            head = middle + 1;
        else if (nums[middle] > target)
            tail = middle;
        else
            return middle;
    }
    return -1;
}

int BinarySearch(int *nums, int len, int target)
{
    int head = 0;
    int tail = len - 1;
    int middle;
    while (head <= tail)
    {
        middle = head + (tail - head) / 2;
        if (nums[middle] < target)
            head = middle + 1;
        else if (nums[middle] > target)
            tail = middle - 1;
        else
            return middle;
    }
    return -1;
}