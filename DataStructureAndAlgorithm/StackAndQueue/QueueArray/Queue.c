#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define MinQueueSize (5)

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

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
    Queue Q;
    if (MaxElements < MinQueueSize)
        Error("Queue size is too small");
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of space!!!");
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
    Q->Front = 1;
    Q->Rear = 0;
    Q->Size = 0;
}

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void EnQueue(ElementType X, Queue Q)
{
    if (IsFull(Q))
        Error("Full queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

ElementType Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void Dequeue(Queue Q)
{
    if (IsEmpty(Q))
        Error("Empty queue");
    else
    {
        Q->Size--;
        Q->Front = Succ(Q->Front, Q);
    }
}

ElementType FrontAndDequeue(Queue Q){
    ElementType Tmp = Front(Q);
    Dequeue(Q);
    return Tmp;
}

void FatalError(char *S){
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);   
}

void Error(char *S){
    fputs(S, stderr);
}

void PrintQueue(Queue Q){
    int i;
    for(i = Q->Front; i != Q->Rear; i = Succ(i, Q)){
        printf("%d ", Q->Array[i]);
    }
    printf("%d\n", Q->Array[i]);
}