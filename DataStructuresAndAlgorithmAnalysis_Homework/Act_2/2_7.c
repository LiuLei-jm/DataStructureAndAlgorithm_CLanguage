#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

clock_t start, stop;

void BubbleSort(int *arr, int size){
    int i ,j,temp;
    for(i = 0; i < size; i ++){
        for(j = 0; j < size - i- 1; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }            
        }
    }
}

void generateRandom1(int N)
{
    start = clock();
    int n = N;
    int num;
    bool isExist = false;
    int array[n];
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            num = rand() % n;
            for (int j = 0; j < i; j++)
            {
                if (num == array[j])
                {
                    isExist = true;
                    break;
                }
            }
            if(isExist){
                isExist = false;
                continue;
            }
            else{
                array[i] = num;
                break;
            }
        }
    }
    stop = clock();
    // BubbleSort(array, n);
    // for(int i = 0; i < n; i++){
    //     printf("%d ", array[i]);
    // }
    // printf("\n");
    printf("N = %d, Duration: %f\n", n, (double)(stop - start) / CLK_TCK);
}



void generateRandom2(int N)
{
    start = clock();
    int n = N;
    int num;
    int array[n];
    int Used[n];
    for (int i = 0; i < n; i++)
    {
        Used[i] = 0;
    }
    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            num = rand() % n;
            if (Used[num] == 1)
            {
                continue;
            }
            array[i] = num;
            Used[num] = 1;
            break;
        }
    } 
    stop = clock();
    // BubbleSort(array, n);
    // for(int i = 0; i < n; i++){
    //     printf("%d ", array[i]);
    // }
    // printf("\n");
    printf("N = %d, Duration: %f\n", n, (double)(stop - start) / CLK_TCK);
}

void generateRandom3(int N){
    start = clock();
    int n = N;
    int array[n];
    for(int i = 0; i < n ; i++){
        array[i] = i+1;
    }
    stop = clock();
    printf("N = %d, Duration: %f\n", n, (double)(stop - start) / CLK_TCK);
}

int main()
{
    printf("Method 1:\n");
    generateRandom1(250);
    generateRandom1(500);
    generateRandom1(1000);
    generateRandom1(2000);

    printf("Method 2:\n");
    generateRandom2(2500);
    generateRandom2(5000);
    generateRandom2(10000);
    generateRandom2(20000);
    // generateRandom2(40000);
    // generateRandom2(80000);

    printf("Method 3:\n");
    generateRandom3(10000);
    generateRandom3(20000);
    generateRandom3(40000);
    generateRandom3(80000);
    generateRandom3(160000);
    generateRandom3(320000);
    // generateRandom3(640000);
    system("pause");
    return 0;
}