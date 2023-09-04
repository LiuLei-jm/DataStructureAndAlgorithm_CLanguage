#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

clock_t start, stop;

void Delete(int index, int a[], int *len)
{
    for (int i = index; i < *len - 1; i++)
    {
        a[i] = a[i + 1];
    }
    (*len) -= 1;
}

int main()
{
    int a[MAX];
    int i, j;
    for (i = 0, j = 1; i < MAX; i+=2, j++)
    {
        a[i] = j;
        a[i + 1] = j;
    }
    int listLen = sizeof(a) / sizeof(int);
    int LastPosition = listLen - 1;
    double duration;
    start = clock();
    for (i = 0; i < LastPosition; i++)
    {
        j = i + 1;
        while (j < LastPosition)
        {
            if (a[i] == a[j])
            {
                Delete(j, a, &LastPosition);
            }
            else
            {
                j++;
            }
        }
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick: %f\n", (double)(stop - start));
    printf("duration: %6.2e\n", duration);
    // for(int i = 0; i < LastPosition; i++){
    //     printf("%d ", a[i]);
    // }
    printf("\n");
    system("Pause");
    return 0;
}