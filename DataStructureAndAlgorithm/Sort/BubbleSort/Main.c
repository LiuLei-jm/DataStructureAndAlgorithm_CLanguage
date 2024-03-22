#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MaxSize 100000
#define PrintSize 20

typedef int ElementType;

clock_t start, stop;

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

    int nums1[MaxSize];
    double duration;
    for (int i = MaxSize, j = 0; i > 0; i--, j++)
    {
        nums1[j] = i;
    }
    Traverse(nums1, PrintSize);
    start = clock();
    BubbleSortWithFlag(nums1, MaxSize);
    stop = clock();
    duration = (stop - start) / CLK_TCK;
    printf("Tick: %f\n", (double)(stop - start));
    printf("duration: %6.2e\n", duration);
    Traverse(nums1, PrintSize);

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
