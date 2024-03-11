#include <stdio.h>
#include <stdlib.h>
#include "Queue.c"

int main(){
    Queue Q = CreateQueue(10);
    EnQueue(1, Q);
    EnQueue(2, Q);
    EnQueue(3, Q);
    EnQueue(4, Q);
    PrintQueue(Q);
    ElementType Tmp = FrontAndDequeue(Q);
    printf("%d\n", Tmp);
    PrintQueue(Q);
    DisposeQueue(Q);

    system("Pause");
    return 0;
}