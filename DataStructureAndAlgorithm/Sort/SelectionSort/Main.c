#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 100000
#define PrintSize 20

clock_t start, stop;

typedef int ElementType ;

void SelectionSort(ElementType nums[], int n);
void Traverse(ElementType nums[], int n);

int main()
{
    int nums[6] = {4, 1, 3, 1, 5, 2};
    Traverse(nums, 6);
    SelectionSort(nums, 6);
    Traverse(nums, 6);

    int nums1[6] = {4, 4, 3, 1, 5, 2};
    Traverse(nums1, 6);
    SelectionSort(nums1, 6);
    Traverse(nums1, 6);
    
    int nums2[MAXSIZE];
    double duration;
    for(int i = MAXSIZE,j=0; i > 0; i--,j++){
        nums2[j] = i;
    }
    
    Traverse(nums2, PrintSize);
    start = clock();
    SelectionSort(nums2, MAXSIZE);
    stop = clock();
    duration = (stop - start) /CLK_TCK;
    printf("Tick: %f\n", (double)(stop-start));
    printf("duration: %6.2e\n", duration);
    Traverse(nums2, PrintSize);

    system("Pause");
    return 0;
}

void Traverse(ElementType nums[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    putchar('\n');
}

void SelectionSort(ElementType nums[], int n)
{
    int k, tmp;
    for (int i = 0; i < n - 1; i++)
    {
        k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[k])
                k = j;
        }
        tmp = nums[i];
        nums[i] = nums[k];
        nums[k] = tmp;
    }
}