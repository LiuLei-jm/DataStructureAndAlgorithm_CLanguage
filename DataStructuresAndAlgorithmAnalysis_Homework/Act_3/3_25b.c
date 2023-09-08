/*
 * 队列实现，数组
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndDeQueue(Queue Q);
void FataError(char *S);
void PrintQueue(Queue Q);
int Succ(int value, Queue Q);

int main()
{
    Queue Q = CreateQueue(10);
    EnQueue(1, Q);
    EnQueue(2, Q);
    EnQueue(3, Q);
    EnQueue(4, Q);
    EnQueue(5, Q);
    EnQueue(6, Q);
    EnQueue(7, Q);
    EnQueue(8, Q);
    EnQueue(9, Q);
    EnQueue(10, Q);

    ElementType Tmp = FrontAndDeQueue(Q);
    printf("%d rank out\n", Tmp);

    PrintQueue(Q);
    DisposeQueue(Q);

    system("Pause");
    return 0;
}

int Succ(int value, Queue Q)
{
    if (++value == Q->Capacity)
        value = 0;
    return value;
}

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (NULL == Q)
        FataError("out of space!");
    Q->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (NULL == Q->Array)
        FataError("out of space!");
    MakeEmpty(Q);
    Q->Capacity = MaxElements;
    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

void MakeEmpty(Queue Q)
{
    Q->Rear = 0;
    Q->Front = 1;
    Q->Size = 0;
}

void EnQueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        FataError("Queue is full!");
    else
    {
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
        Q->Size++;
    }
}

ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    if (IsEmpty(Q))
        FataError("Queue is empty");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDeQueue(Queue Q)
{
    if (IsEmpty(Q))
        FataError("Queue is empty");
    else
    {
        ElementType Tmp = Front(Q);
        DeQueue(Q);
        return Tmp;
    }
}

void FataError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintQueue(Queue Q)
{
    int j = Q->Front;
    for (int i = 0; i < Q->Size; i++)
    {
        printf("%d ", Q->Array[j]);
        j = Succ(j, Q);
    }
    printf("\n");
}
