#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Cutoff (3)
#define MaxSize 100000
#define PrintSize 20
typedef int ElementType;

clock_t start, stop;

void QuickSort(ElementType A[], int N);
ElementType Median3(ElementType A[], int Left, int Right);
void Qsort(ElementType A[], int Left, int Right);
void Swap(ElementType *a, ElementType *b);
void InsertionSort(ElementType A[], int N);
void PrintList(ElementType A[], int N);

int main()
{
    double duration;
    int nums[MaxSize];
    for (int i = MaxSize, j = 0; i > 0; i--, j++)
    {
        nums[j] = i;
    }
    PrintList(nums, PrintSize);
    start = clock();
    QuickSort(nums, MaxSize);
    stop = clock();
    duration = ((double)(stop - start)) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);
    PrintList(nums, PrintSize);

    system("Pause");
    return 0;
}

void QuickSort(ElementType A[], int N)
{
    Qsort(A, 0, N - 1);
}

ElementType Median3(ElementType A[], int Left, int Right)
{
    int Center = (Left + Right) / 2;

    if (A[Left] > A[Center])
        Swap(&A[Left], &A[Center]);
    if (A[Left] > A[Right])
        Swap(&A[Left], &A[Right]);
    if (A[Center] > A[Right])
        Swap(&A[Center], &A[Right]);

    Swap(&A[Center], &A[Right - 1]);
    return A[Right - 1];
}

void Qsort(ElementType A[], int Left, int Right)
{
    int i, j;
    ElementType Pivot;
    if (Left + Cutoff <= Right)
    {
        Pivot = Median3(A, Left, Right);
        i = Left;
        j = Right - 1;
        for (;;)
        {
            while (A[++i] < Pivot)
            {
            }
            while (A[--j] > Pivot)
            {
            }
            if (i < j)
                Swap(&A[i], &A[j]);
            else
                break;
        }
        Swap(&A[i], &A[Right - 1]);

        Qsort(A, Left, i - 1);
        Qsort(A, i + 1, Right);
    }
    else
    {
        InsertionSort(A + Left, Right - Left + 1);
    }
}

void Swap(ElementType *a, ElementType *b)
{
    ElementType Tmp = *a;
    *a = *b;
    *b = Tmp;
}

void InsertionSort(ElementType A[], int N)
{
    int j, P;
    ElementType Tmp;
    for (P = 1; P < N; P++)
    {
        Tmp = A[P];
        for (j = P; j > 0 && A[j - 1] > Tmp; j--)
        {
            A[j] = A[j - 1];
        }
        A[j] = Tmp;
    }
}

void PrintList(ElementType A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    putchar('\n');
}