#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

void BacktrackI(int *state, int stateSize, int target, int total, int *choices, int choicesSize, int **res, int *resSize, int *resColSizes);
int **SubsetSumI(int *nums, int numsSize, int target, int* resColSizes, int *resSize);
void BacktrackII(int *state, int stateSize, int target, int start, int *choices, int choicesSize, int **res, int *resSize, int *resColSizes);
int **SubsetSumII(int *nums, int numsSize, int target, int* resColSizes, int *resSize);
int Compare(const void* a, const void* b);
void BacktrackIII(int *state, int stateSize, int target, int start, int *choices, int choicesSize, int **res, int *resSize, int *resColSizes);
int **SubsetSumIII(int *nums, int numsSize, int target, int* resColSizes, int *resSize);

int main()
{
    // int nums[3] = {3, 4, 5};
    int nums[3] = {4, 4, 5};
    int resColSizes[MAX_SIZE]={0};
    int resSize;
    // int **res = SubsetSumI(nums, 3, 9, resColSizes, &resSize);
    // int **res = SubsetSumII(nums, 3, 9, resColSizes, &resSize);
    int **res = SubsetSumIII(nums, 3, 9, resColSizes, &resSize);

    for(int i = 0 ; i < resSize; i++){
        for(int j = 0; j < resColSizes[i]; j++){
            printf("%d ", res[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    for(int i = 0; i < resSize; i++){
        free(res[i]);
    }
    free(res);
     system("Pause");
    return 0;
}

void BacktrackI(int *state, int stateSize, int target, int total, int *choices, int choicesSize, int **res, int *resSize, int* resColSizes)
{
    if (total == target)
    {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < stateSize; i++)
        {
            res[*resSize][i] = state[i];
        }
        resColSizes[(*resSize)++] = stateSize;
        return;
    }
    for (int i = 0; i < choicesSize; i++)
    {
        if (total + choices[i] > target)
        {
            continue;
        }
        state[stateSize++] = choices[i];
        BacktrackI(state, stateSize, target, total + choices[i], choices, choicesSize, res, resSize, resColSizes);
        stateSize--;
    }
}

int **SubsetSumI(int *nums, int numsSize, int target, int * resColSizes, int *resSize)
{
    int *state = (int *)malloc(numsSize * sizeof(int));
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *resSize = 0;

    BacktrackI(state, 0, target, 0, nums, numsSize, res, resSize,resColSizes);
    free(state);
    return res;
}

void BacktrackII(int *state, int stateSize, int target, int start, int *choices, int choicesSize, int **res, int *resSize, int* resColSizes)
{
    if (target == 0)
    {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < stateSize; i++)
        {
            res[*resSize][i] = state[i];
        }
        resColSizes[(*resSize)++] = stateSize;
        return;
    }
    for (int i = start; i < choicesSize; i++)
    {
        if(target - choices[i] < 0){
            break;
        }
        state[stateSize++] = choices[i];
        BacktrackII(state, stateSize, target - choices[i], i, choices, choicesSize, res, resSize, resColSizes);
        stateSize--;
    }
}

int **SubsetSumII(int *nums, int numsSize, int target, int * resColSizes, int *resSize)
{
    int start = 0;
    qsort(nums, numsSize, sizeof(int), Compare);
    int *state = (int *)malloc(numsSize * sizeof(int));
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *resSize = 0;

    BacktrackII(state, 0, target, start, nums, numsSize, res, resSize,resColSizes);
    free(state);
    return res;
}

int Compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

void BacktrackIII(int *state, int stateSize, int target, int start, int *choices, int choicesSize, int **res, int *resSize, int* resColSizes)
{
    if (target == 0)
    {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < stateSize; i++)
        {
            res[*resSize][i] = state[i];
        }
        resColSizes[(*resSize)++] = stateSize;
        return;
    }
    for (int i = start; i < choicesSize; i++)
    {
        if(target - choices[i] < 0){
            continue;
        }
        if(i > start && choices[i] == choices[i - 1]){
            continue;
        }
        state[stateSize++] = choices[i];
        BacktrackIII(state, stateSize, target - choices[i], i + 1, choices, choicesSize, res, resSize, resColSizes);
        stateSize--;
    }
}

int **SubsetSumIII(int *nums, int numsSize, int target, int * resColSizes, int *resSize)
{
    int start = 0;
    qsort(nums, numsSize, sizeof(int), Compare);
    int *state = (int *)malloc(numsSize * sizeof(int));
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *resSize = 0;

    BacktrackIII(state, 0, target, start, nums, numsSize, res, resSize,resColSizes);
    free(state);
    return res;
}
