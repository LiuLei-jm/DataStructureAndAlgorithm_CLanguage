#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MaxSize 100000
#define PrintSize 20

clock_t start, stop;

typedef int ElementType;

void InsertionSort(ElementType A[], int N);
void PrintList(ElementType A[], int N);

int main(){
    double duration;
    int nums[MaxSize];
    for(int i = MaxSize, j = 0; i > 0; i--, j++){
        nums[j] = i;
    }
    PrintList(nums, PrintSize);
    start = clock();
    InsertionSort(nums, MaxSize);
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
    PrintList(nums, PrintSize);

    system("Pause");
    return 0;
}

void PrintList(ElementType A[], int N){
    int i;
    for( i = 0; i < N; i++){
        printf("%d ", A[i]);
    }
    putchar('\n');
}

void InsertionSort(ElementType A[], int N)
{
    int j, P;

    ElementType Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
            A[j] = A[j - 1];
        A[j] = Tmp;
    }
}