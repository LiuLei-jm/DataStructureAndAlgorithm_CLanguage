#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define ArraySize 10
#define PrintSize 10

typedef float ElementType;

clock_t start, stop;

void BucketSort(ElementType nums[], int size);
void Traverse(ElementType nums[], int size);
void swap(ElementType *x, ElementType *y);
int CompareFloat(const ElementType *x, const ElementType *y);

int main()
{
    ElementType nums[10] = {0.49, 0.96, 0.82, 0.09, 0.57, 0.43, 0.91, 0.75, 0.15, 0.37};
    Traverse(nums, 10);
    BucketSort(nums, 10);
    Traverse(nums, 10);

    system("Pause");
    return 0;
}

int CompareFloat(const ElementType *x, const ElementType *y)
{
    if (fabs(*x - *y) < 1e-6)
        return 0;
    else if (*x > *y)
        return 1;
    else
        return -1;
}

void swap(ElementType *x, ElementType *y)
{
    ElementType tmp = *x;
    *x = *y;
    *y = tmp;
}

void Traverse(ElementType nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", nums[i]);
    }
    putchar('\n');
}

void BucketSort(ElementType nums[], int size)
{
    int k = size / 2;
    ElementType **buckets = calloc(k, sizeof(ElementType *));
    for (int i = 0; i < k; i++)
    {
        buckets[i] = calloc(ArraySize, sizeof(ElementType));
    }

    for (int i = 0; i < size; i++)
    {
        int bucket_idx = nums[i] * k;
        int j = 0;
        while (buckets[bucket_idx][j] > 0 && buckets[bucket_idx][j] < nums[i])
        {
            j++;
        }
        ElementType temp = nums[i];
        while (j < ArraySize && buckets[bucket_idx][j] > 0)
        {
            swap(&temp, &buckets[bucket_idx][j]);
            j++;
        }
        buckets[bucket_idx][j] = temp;
    }
    int(* compare_float)(const ElementType*,const ElementType *) = &CompareFloat;
    for (int i = 0; i < k; i++)
    {
        qsort(buckets[i], ArraySize, sizeof(ElementType), compare_float);
    }

    for (int i = 0, j = 0; j < k; j++)
    {
        for (int l = 0; l < ArraySize; l++)
        {
            if (buckets[j][l] > 0)
                nums[i++] = buckets[j][l];
        }
    }

    for (int i = 0; i < k; i++)
    {
        free(buckets[i]);
    }
    free(buckets);
}