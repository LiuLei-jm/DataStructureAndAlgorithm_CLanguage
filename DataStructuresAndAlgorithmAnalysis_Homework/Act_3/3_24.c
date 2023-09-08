/*
 * 计算斐波那契数列的递归例程如果在N=50下运行，栈空间由可能用完吗
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

unsigned long long int Fibonacci(int N);
unsigned long long int FibonacciIteration(int N);

int main()
{
    unsigned long long int res;
    double duration;
    
    printf("Iteration Fibonacci:\n");
    start = clock();
    for (int i = 1; i <= 50; i++)
    {
        res = FibonacciIteration(i);
        printf("%dth Result = %llu\n", i, res);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);    

    printf("---------------------------");

    printf("Recursion Fibonacci:\n");
    start = clock();
    for (int i = 1; i <= 50; i++)
    {
        res = Fibonacci(i);
        printf("%dth Result = %llu\n", i, res);
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);

    system("Pause");
    return 0;
}

unsigned long long int FibonacciIteration(int N)
{
    if (N <= 2)
        return 1;
    else
    {
        unsigned long long int a, b, c;
        a = b = 1;
        for (int i = 2; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

unsigned long long int Fibonacci(int N)
{
    if (N <= 2)
        return 1;
    else
        return Fibonacci(N - 1) + Fibonacci(N - 2);
}
