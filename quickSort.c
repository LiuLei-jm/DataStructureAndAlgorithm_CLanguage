#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int partition(int array[], int i, int j)
{
    int x = array[i];
    while (i < j)
    {
        while (i < j && array[j] >= x)
        {
            j--;
        }
        if (i < j)
        {
            array[i] = array[j];
            i++;
        }
        while (i < j && array[i] < x)
        {
            i++;
        }
        if (i < j)
        {
            array[j] = array[i];
            j--;
        }
    }
    array[i] = x;
    return i;
}

void quickSort(int array[], int i, int j)
{
    if (i < j)
    {
        int index = partition(array, i, j);
        printArray(array, 8);
        quickSort(array, i, index - 1);
        quickSort(array, index + 1, j);
    }
}

int main()
{
    int array[8] = {27,38,13,49,76,97,65, 49};
    quickSort(array, 0, 7);
    printArray(array, 8);
    system("pause");
    return 0;
}