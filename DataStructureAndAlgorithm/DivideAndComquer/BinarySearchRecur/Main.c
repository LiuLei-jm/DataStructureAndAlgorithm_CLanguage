#include <stdio.h>
#include <stdlib.h>

int dfs(int nums[], int target, int i, int j);
int BinarySearch(int nums[], int target, int numSize);
void Traverse(int nums[], int size);

int main()
{
    int nums[10] = {1, 3, 6, 8, 12, 15, 23, 26, 31, 35};
    Traverse(nums, 10);
    int index = BinarySearch(nums, 6, 10);
    printf("Index: %d\n", index);

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

int dfs(int nums[], int target, int i, int j)
{
    if (i > j)
        return -1;
    int m = (i + j) / 2;
    if (nums[m] < target)
        return dfs(nums, target, m + 1, j);
    else if (nums[m] > target)
        return dfs(nums, target, i, m - 1);
    else
        return m;
}

int BinarySearch(int nums[], int target, int numSize)
{
    int n = numSize;
    return dfs(nums, target, 0, n - 1);
}