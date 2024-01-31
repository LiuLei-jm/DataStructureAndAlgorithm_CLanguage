#include <stdio.h>
#include <stdlib.h>
#include "LeftHeap.c"

int main()
{
    PriorityQueue H1 = Initialize();
    PriorityQueue H2 = Initialize();
    int nums[8] = {3, 8, 10, 21, 14, 17, 23, 26};
    for (int i = 0; i < 8; i++)
    {
        Insert(nums[i], H1);
    }
    int nums1[8] = {6, 7, 12, 18, 24, 37, 18, 33};
    for (int i = 0; i < 8; i++)
    {
        Insert(nums1[i], H2);
    }

    PrintSequence(H1);
    PrintSequence(H2);

    H1 = Merge(H1, H2);

    PrintSequence(H1);

    Destroy(H1);

    system("Pause");
    
    return 0;
}