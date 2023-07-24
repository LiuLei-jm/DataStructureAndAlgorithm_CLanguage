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

void bubbleSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        printArray(array, 8);
    }
}

int main()
{
    int array[8] = {49, 38, 65, 97, 76, 13, 27, 49};
    bubbleSort(array, 8);

    system("pause");
    return 0;
}