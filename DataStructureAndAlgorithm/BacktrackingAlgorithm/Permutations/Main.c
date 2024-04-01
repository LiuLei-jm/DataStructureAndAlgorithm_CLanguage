#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 10

void BacktrackI(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize);
int **PermutationsI(int *nums, int numsSize, int *returnSize);
void BacktrackII(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize);
int **PermutationsII(int *nums, int numsSize, int *returnSize);

int main()
{
    // int nums[4] = {1, 2, 3, 4};
    // int returnSize = 0;
    // int **res = PermutationsI(nums, 4, &returnSize);

    // for (int i = 0; i < returnSize; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         printf("%d ", res[i][j]);
    //     }
    //     putchar('\n');
    // }
    // putchar('\n');

    int nums1[3] = {1,1,2};
    int returnSize = 0;
    int **res1 = PermutationsII(nums1, 3, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", res1[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    
    // free(res);
    free(res1);
    system("Pause");
    return 0;
}

void BacktrackI(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize)
{
    if (stateSize == choicesSize)
    {
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for (int i = 0; i < choicesSize; i++)
        {
            res[*resSize][i] = state[i];
        }
        (*resSize)++;
        return;
    }
    for (int i = 0; i < choicesSize; i++)
    {
        int choice = choices[i];
        if (!selected[i])
        {
            selected[i] = true;
            state[stateSize] = choice;
            BacktrackI(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            selected[i] = false;
        }
    }
}

int **PermutationsI(int *nums, int numsSize, int *returnSize)
{
    int *state = (int *)malloc(numsSize * sizeof(int));
    bool *selected = (bool *)malloc(numsSize * sizeof(bool));
    for (int i = 0; i < numsSize; i++)
    {
        selected[i] = false;
    }
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *returnSize = 0;

    BacktrackI(state, 0, nums, numsSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}

void BacktrackII(int *state, int stateSize, int *choices, int choicesSize, bool *selected, int **res, int *resSize){
      if(stateSize == choicesSize){
        res[*resSize] = (int *)malloc(choicesSize * sizeof(int));
        for(int i= 0; i < choicesSize; i++){
            res[*resSize][i] = state[i];
        }
        (*resSize)++;
        return;
      } 
      bool duplicated[MAX_SIZE] = {false}; 
      for(int i = 0; i < choicesSize; i++){
        int choice = choices[i];
        if(!selected[i] && !duplicated[choice]){
            duplicated[choice] = true;
            selected[i] = true;
            state[stateSize] = choice;
            BacktrackII(state, stateSize + 1, choices, choicesSize, selected, res, resSize);
            selected[i] = false;
        }
      }
}

int **PermutationsII(int *nums, int numsSize, int *returnSize){
    int *state = (int *)malloc(numsSize * sizeof(int));
    bool *selected = (bool*)malloc(numsSize * sizeof(bool));
    for(int i = 0; i< numsSize; i++){
        selected[i] = false;
    }
    int **res = (int **)malloc(MAX_SIZE * sizeof(int *));
    *returnSize = 0;
    BacktrackII(state, 0, nums, numsSize, selected, res, returnSize);

    free(state);
    free(selected);

    return res;
}