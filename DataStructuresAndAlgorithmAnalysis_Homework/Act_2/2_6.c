#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

clock_t start, stop;

int main()
{
    unsigned long int sum;
    int i;
    int j;
    int k;
    i = j = k = 0;

    start = clock();
    sum = 0;
    for (i = 0; i < N; i++)
    {
        sum++;
    }
    stop = clock();
    printf("(1) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    start = clock();
    sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum++;
        }
    }
    stop = clock();
    printf("(2) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    start = clock();
    sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N * N; j++)
        {
            sum++;
        }
    }
    stop = clock();
    printf("(3) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    start = clock();
    sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            sum++;
        }
    }
    stop = clock();
    printf("(4) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    start = clock();
    sum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i * i; j++)
        {
            for (k = 0; k < j; k++)
            {
                sum++;
            }
        }
    }
    stop = clock();
    printf("(5) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    start = clock();
    sum = 0;
    for (i = 1; i < N; i++)
    {
        for (j = 1; j < i * i; j++)
        {
            if (j % i == 0)
            {
                for (k = 0; k < j; k++)
                {
                    sum++;
                }
            }
        }
    }
    stop = clock();
    printf("(6) Duration: %f, Sum: %lu\n", (double)(stop - start) / CLK_TCK, sum);

    system("pause");
    return 0;
}