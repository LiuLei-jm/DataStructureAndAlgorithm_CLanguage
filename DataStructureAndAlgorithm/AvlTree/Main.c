#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.c"

int main()
{
    AvlTree T = NULL;
    T = MakeEmpty(T);
    int nums[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 9; i++)
    {
        T = Insert(nums[i], T);
    }
    PrintTree(T);
    putchar('\n');

    T = MakeEmpty(T);
    system("Pause");
    return 0;
}