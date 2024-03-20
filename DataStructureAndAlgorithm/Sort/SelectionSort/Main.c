#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int nums[], int n);
void Traverse(int nums[], int n);

int main()
{
    int nums[6] = {4, 1, 3, 1, 5, 2};
    Traverse(nums, 6);
    SelectionSort(nums, 6);
    Traverse(nums, 6);

    int nums1[6] = {4, 4, 3, 1, 5, 2};
    Traverse(nums1, 6);
    SelectionSort(nums1, 6);
    Traverse(nums1, 6);

    system("Pause");
    return 0;
}

void Traverse(int nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

void SelectionSort(int nums[], int n)
{
    int k, tmp;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[k])
                k = j;
        }
        tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
    }
}