#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void BubbleSort(int nums[], int size);
void BubbleSortWithFlag(int nums[], int size);
void Traverse(int nums[], int size);

int main()
{
    int nums[6] = {4, 1, 3, 1, 5, 2};
    Traverse(nums, 6);
    // BubbleSort(nums, 6);
    BubbleSortWithFlag(nums, 6);
    Traverse(nums, 6);

    system("Pause");
    return 0;
}

void Traverse(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

void BubbleSort(int nums[], int size)
{
    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

void BubbleSortWithFlag(int nums[], int size)
{
    bool flag;
    int temp;
    for (int i = size - 1; i > 0; i--)
    {
        flag = false;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
