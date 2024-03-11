#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void ShellSort(ElementType A[], int N);
void PrintList(ElementType A[], int N);

int main(){
    int nums[13] = {81,94,11,96,12,35,17,95,28,58,41,75,15};
    PrintList(nums, 13);
    ShellSort(nums, 13);
    PrintList(nums, 13);
    system("Pause");
    return 0;
}

void PrintList(ElementType A[], int N){
    int i;
    for(i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
    putchar('\n');
}

void ShellSort(ElementType A[], int N)
{
    int i, j, Increment;
    ElementType Tmp;

    for (Increment = N / 2; Increment > 0; Increment /= 2)
    {
        for (i = Increment; i < N; i++)
        {
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment)
                if (Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            A[j] = Tmp;
        }
    }
}