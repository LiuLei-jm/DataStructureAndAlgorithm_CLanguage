#include <stdio.h>
#include <stdlib.h>

int Digit(int num, int exp);
void CountingSortDigit(int nums[], int size, int exp);
void RadixSort(int nums[], int size);
void Traverse(int nums[], int size);

int main()
{
    int nums[10] = {10546151, 35663510, 42865989, 34862445, 81883077, 88906420, 72429244, 30524779, 82060337, 63832996};
    Traverse(nums, 10);
    RadixSort(nums, 10);
    Traverse(nums, 10);

    system("Pause");
    return 0;
}

int Digit(int num, int exp)
{
    return (num / exp) % 10;
}

void CountingSortDigit(int nums[], int size, int exp)
{
    int *counter = (int *)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10 ; i++){
        counter[i] = 0;
    }
    int d, j;
    for (int i = 0; i < size; i++)
    {
        d = Digit(nums[i], exp);
        counter[d]++;
    }
    for (int i = 1; i < 10; i++)
    {
        counter[i] += counter[i - 1];
    }
    int *res = (int *)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--)
    {
        d = Digit(nums[i], exp);
        j = counter[d] - 1;
        res[j] = nums[i];
        counter[d]--;
    }
    for (int i = 0; i < size; i++)
    {
        nums[i] = res[i];
    }
    free(counter);
    free(res);
}

void RadixSort(int nums[], int size)
{
    int max = INT_MIN;
    for (size_t i = 0; i < size - 1; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    for (int exp = 1; max >= exp; exp *= 10)
        CountingSortDigit(nums, size, exp);
}

void Traverse(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}