/*
 * 双端队列(deque)是由一些项的表组成的数据结构，对该数据结构可以进行下列操作：
 Push(X, D): 将项X插入到双端队列D的前端。
 Pop(D): 从双端队列D中删除前端项并将其返回。
 Inject(X, D): 将项X插入到双端队列D的尾端。
 Eject(D): 从双对队列D中删除尾端项并将其返回。
 编写支持双端队列的例程，每种操作均花费O(1)时间。
*/

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Deque;
struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmpty(Deque D);
int IsFull(Deque D);
Deque CreateDeque(int MaxElements);
void DisposeDeque(Deque D);
void MakeEmpty(Deque D);
void Push(ElementType X, Deque D);
ElementType Pop(Deque D);
void Inject(ElementType X, Deque D);
ElementType Eject(Deque D);
void FataError(char *S);
int Succ(int Value, Deque D);
int DeSucc(int Value, Deque D);
void PrintDeque(Deque D);

int main()
{
    Deque D = CreateDeque(10);
    ElementType Tmp;
    Push(4, D);
    Push(3, D);
    Push(2, D);
    Push(1, D);
    Push(0, D);
    Tmp = Pop(D);
    printf("%d rank out\n", Tmp);

    Inject(5, D);
    Inject(6, D);
    Inject(7, D);
    Inject(8, D);
    Inject(9, D);
    Inject(10, D);
    Tmp = Eject(D);
    printf("%d rank out\n", Tmp);

    PrintDeque(D);
    DisposeDeque(D);

    system("Pause");
    return 0;
}

int IsEmpty(Deque D)
{
    return D->Size == 0;
}

int IsFull(Deque D)
{
    return D->Size == D->Capacity;
}

Deque CreateDeque(int MaxElements)
{
    Deque D = (Deque)malloc(sizeof(struct QueueRecord));
    if (NULL == D)
        FataError("out of space!");
    D->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (NULL == D->Array)
        FataError("out of space!");
    D->Capacity = MaxElements;
    MakeEmpty(D);
    return D;
}

void DisposeDeque(Deque D){
    free(D->Array);
    free(D);
}

void MakeEmpty(Deque D){
    D->Front = 1;
    D->Rear = 0;
    D->Size = 0;   
}

void Push(ElementType X, Deque D){
    if(IsFull(D))
    FataError("Deque is full!");
    else{
        D->Size++;
        D->Front = DeSucc(D->Front, D);
        D->Array[D->Front] = X;
    }
}

ElementType Pop(Deque D){
    if(IsEmpty(D))
    FataError("Deque is empty");
    else{
        D->Size--;
        ElementType Tmp = D->Array[D->Front];
        D->Front = Succ(D->Front, D);
        return Tmp;
    }   
}

void Inject(ElementType X, Deque D){
    if(IsFull(D))
    FataError("Deque is full");
    else{
        D->Size++;
        D->Rear = Succ(D->Rear, D);
        D->Array[D->Rear] = X;
    }
}

ElementType Eject(Deque D){
    if(IsEmpty(D))
    FataError("Deque is empty");
    else{
        D->Size--;
        ElementType Tmp = D->Array[D->Rear];
        D->Rear = DeSucc(D->Rear, D);
        return Tmp;
    }
}

void FataError(char *S){
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

int Succ(int Value, Deque D){
    if(++Value == D->Capacity)
    Value = 0;
    return Value;   
}

int DeSucc(int Value, Deque D){
    if(--Value < 0)
    Value = D->Capacity - 1;
    return Value;
}

void PrintDeque(Deque D){
    int j = D->Front;
    for(int i = 0; i < D->Size; i++){
        printf("%d ", D->Array[j]);
        j = Succ(j, D);
    }
    printf("\n");
}
