/*
** 问题描述：编写一个程序解决选择问题。令k = N / 2。画出表格显示你的程序对于N为不同值时的运行时间。
**（设有一组 N 个数确定其中第 k 个最大者，称选择问题（selection problem））
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

clock_t start, stop;

void createArray(int *array, int size)
{
    int random = 0;
    srand((unsigned int)time(NULL));
    for (unsigned int i = 0; i < size; i++)
    {
        random = rand() % 10000000;
        array[i] = random;
    }
}

void printArray(int *array, int size)
{
    for (int i = size - 5; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    putchar('\n');
}

int getMaxByIndex(int *array, int size, int index)
{
    start = clock();

    int *dataArray = (int *)malloc(sizeof(int) * index);
    int dataArrayMax;

    for (int i = 0; i < size; i++)
    {
        if (i == 0)
        {
            dataArray[i] = array[i];
            continue;
        }
        if (i < index)
        {
            dataArray[i] = array[i];
            for (int j = i; j > 0 && dataArray[j] < dataArray[j - 1]; j--)
            {
                int tmp = dataArray[j];
                dataArray[j] = dataArray[j - 1];
                dataArray[j - 1] = tmp;
            }
            continue;
        }
        else
        {
            dataArrayMax = dataArray[index - 1];

            if (array[i] >= dataArrayMax)
            {
                continue;
            }
            else
            {
                for (int j = 0; j < index; j++)
                {
                    if (dataArray[j] >= array[i])
                    {
                        for (int k = index - 1; k > j; k--)
                        {
                            dataArray[k] = dataArray[k - 1];
                        }
                        dataArray[j] = array[i];
                        break;
                    }
                }
            }
        }
    }

    stop = clock();
    printf("Duration: %.2f\n", (double)(stop - start) / CLK_TCK);
    printArray(dataArray, index);
    int result = dataArray[index - 1];
    free(dataArray);
    return result;
}

void executeTest(int size)
{

    int *array = (int *)malloc(sizeof(int) * size);
    createArray(array, size);
    int maxByIndex = getMaxByIndex(array, size, size / 2);
    printf("Index %d value: %d\n", size / 2, maxByIndex);
    free(array);
    printf("==================\n");
}

int main()
{
    int sizes[5] = {10000, 20000, 30000, 40000, 50000};

    for (int i = 0; i < 5; i++)
    {
        executeTest(sizes[i]);
    }

    system("pause");
    return 0;
}