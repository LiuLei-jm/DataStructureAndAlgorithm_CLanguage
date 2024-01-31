#include <stdio.h>
#include <stdlib.h>
#include "BinHeap.c"

int main()
{
    PriorityQueue H = Initialize(20);
    int nums[20] = {10, 12, 1, 14, 6,
                    5, 8, 15, 3, 9,
                    7, 4, 11, 13, 2,
                    20, 19, 18, 17, 16};

    for (int i = 0; i < 20; i++)
    {
        Insert(nums[i], H);
    }

    PrintPriorityQueue(H);

    DeleteMin(H);

    PrintPriorityQueue(H);

    Destroy(H);
    system("Pause");
    return 0;
}