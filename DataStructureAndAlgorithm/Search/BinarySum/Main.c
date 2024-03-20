#include <stdio.h>
#include <stdlib.h>
#include "Hash.c"

// 暴力枚举
int *TwoSumBruteForce(int *nums, int numsSize, int target, int *returnSize);
// 哈希表优化
int *TwoSumHashTable(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int nums[4] = {2, 7, 11, 15};
    int *res;
    int returnSize;
    // res = TwoSumBruteForce(nums, 4, 13, &returnSize);
    // for (int i = 0; i < returnSize; i++)
    // {
    //     printf("%d ", nums[res[i]]);
    // }
    // putchar('\n');
    // free(res);

    res = TwoSumHashTable(nums, 4, 13, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", nums[res[i]]);
    }
    putchar('\n');
    free(res);

    system("Pause");
    return 0;
}

int *TwoSumHashTable(int *nums, int numsSize, int target, int *returnSize)
{
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++)
    {
        HashTable *tmp = Find(target - nums[i]);
        if (tmp != NULL)
        {
            int *res = malloc(sizeof(int) * 2);
            res[0] = tmp->val;
            res[1] = i;
            *returnSize = 2;
            return res;
        }
        Insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int *TwoSumBruteForce(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize - 1; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *res = malloc(sizeof(int) * 2);
                res[0] = i, res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
        *returnSize = 0;
        return NULL;
    }
}