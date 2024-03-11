#include <stdio.h>
#include <stdlib.h>
#include "LeftHeap.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

static void SwapChildren(PriorityQueue H)
{
    PriorityQueue TmpCell = H->Left;
    H->Left = H->Right;
    H->Right = TmpCell;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL)
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue Initialize(void)
{
    PriorityQueue H = NULL;
    return H;
}

ElementType FindMin(PriorityQueue H)
{
    if(IsEmpty(H)) Error("Leftist Heap is empty");
    else return H->Element;
}

int IsEmpty(PriorityQueue H)
{
    return H == NULL;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if (H1 == NULL)
        return H2;
    if (H2 == NULL)
        return H1;
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

void Destroy(PriorityQueue H){
    if(H != NULL){
        Destroy(H->Left);
        Destroy(H->Right);
        free(H);
    }
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;

    SingleNode = malloc(sizeof(struct TreeNode));
    if (SingleNode == NULL)
        FatalError("Out of space!!!");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    PriorityQueue LeftHeap, RightHeap;

    if (IsEmpty(H))
    {
        Error("Priority queue is empty");
        return H;
    }

    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    return Merge(LeftHeap, RightHeap);
}

void Error(char *S)
{
    fputs(S, stderr);
}

void FatalError(char *S)
{
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}

struct QueueRecord
{
    int Capacity;
    int Size;
    int Front;
    int Rear;
    PriorityQueue *Array;
};

void PrintSequence(PriorityQueue H)
{
    if (H == NULL)
        return;
    PriorityQueue TmpCell, Previous;
    TmpCell = Previous = NULL;
    Queue Q = CreateQueue(1000);
    EnQueue(H, Q);
    while (!IsEmptyQueue(Q))
    {
        TmpCell = FrontAndDeQueue(Q);
        printf("%d ", TmpCell->Element);
        if (TmpCell->Left != NULL)
            EnQueue(TmpCell->Left, Q);
        if (TmpCell->Right != NULL)
            EnQueue(TmpCell->Right, Q);
        Previous = TmpCell;
    }
    putchar('\n');
    DisposeQueue(Q);
}

int IsEmptyQueue(Queue Q)
{
    return Q->Size == 0;
}

int IsFullQueue(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");
    Q->Array = malloc(sizeof(ElementType) * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of space!!!");
    MakeEmptyQueue(Q);
    Q->Capacity = MaxElements;
    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

void MakeEmptyQueue(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void EnQueue(PriorityQueue P, Queue Q)
{
    if (IsFullQueue(Q))
        Error("Queue is full");
    else        
    {
        Q->Size++;
        Q->Rear = SuccQueue(Q->Rear, Q);
        Q->Array[Q->Rear] = P;
    }
}

PriorityQueue FrontQueue(Queue Q){
    return Q->Array[Q->Front];   
}

void DeQueue(Queue Q){
    if(IsEmptyQueue(Q))
    Error("Queue is empty");
    else{
        Q->Size--;
        Q->Front = SuccQueue(Q->Front, Q);
    }   
}

PriorityQueue FrontAndDeQueue(Queue Q){
    PriorityQueue Tmp = Q->Array[Q->Front];
    DeQueue(Q);
    return Tmp;   
}

static int SuccQueue(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;    
}