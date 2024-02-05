#include <stdio.h>
#include <stdlib.h>

#define LeftChild(i) (2 * (i) + 1)

typedef int ElementType;

void PercDown(ElementType A[], int i, int N);
void HeapSort(ElementType A[], int N);
void Swap(ElementType *A1, ElementType *A2);
void PrintList(ElementType A[], int N);

int main()
{
    int nums[7] = {97, 53, 59, 26, 41, 58, 31};
    PrintList(nums, 7);
    HeapSort(nums, 7);
    PrintList(nums, 7);

     system("Pause");
    return 0;
}

void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;


    for (Tmp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void HeapSort(ElementType A[], int N)
{
    int i;

    for (i = N / 2; i >= 0; i--)
         PercDown(A, i, N);
    for (i = N - 1; i > 0; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}

void Swap(ElementType *A1, ElementType *A2)
{
    ElementType Tmp = *A1;
    *A1 = *A2;
    *A2 = Tmp;
}

void PrintList(ElementType A[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    putchar('\n');
}