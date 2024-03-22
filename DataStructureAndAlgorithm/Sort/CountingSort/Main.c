#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountingSortNaive(int nums[], int size);
void CountingSort(int nums[], int size);
void Traverse(int nums[], int size);

int main()
{
    int nums[10] = {1, 0, 1, 2, 0, 4, 0, 2, 2, 4};
    Traverse(nums, 10);
    CountingSort(nums, 10);
    Traverse(nums, 10);

    system("Pause");
    return 0;
}

void CountingSortNaive(int nums[], int size)
{
    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }

    int *counter = calloc(m + 1, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        counter[nums[i]]++;
    }
    Traverse(counter, m + 1);

    int i = 0;
    for (int num = 0; num < m + 1; num++)
    {
        for (int j = 0; j < counter[num]; j++, i++)
        {
            nums[i] = num;
        }
    }

    free(counter);
}

void Traverse(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

void CountingSort(int nums[], int size)
{
    int m = 0;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] > m)
        {
            m = nums[i];
        }
    }

    int *counter = calloc(m+1, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        counter[nums[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        counter[i + 1] += counter[i];
    }
    int num;
    Traverse(counter, m + 1);
    int *res = malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--)
    {
        num = nums[i];
        res[counter[num] - 1] = num;
        counter[num]--;
    }
    memcpy(nums, res, size * sizeof(int));
    free(counter);
    free(res);
}