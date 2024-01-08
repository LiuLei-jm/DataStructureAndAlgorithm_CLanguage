#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef _BinHeap_H

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef int ElementType;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

#endif

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType *Elements;
};

#define MinPQSize 1
#define MinData 1

void Error(char *S);
void FatalError(char *S);
void PrintPriorityQueue(PriorityQueue H);

int main()
{
    PriorityQueue H = Initialize(20);

    Insert(10, H);
    Insert(12, H);
    Insert(1, H);
    Insert(14, H);
    Insert(6, H);
    Insert(5, H);
    Insert(8, H);
    Insert(15, H);
    Insert(3, H);
    Insert(9, H);
    Insert(7, H);
    Insert(4, H);
    Insert(11, H);
    Insert(13, H);

    PrintPriorityQueue(H);

    DeleteMin(H);
    DeleteMin(H);
    DeleteMin(H);

    PrintPriorityQueue(H);
    Destroy(H);

    system("Pause");
    return 0;
}

PriorityQueue Initialize(int MaxElements)
{
    PriorityQueue H;

    if (MaxElements < MinPQSize)
        Error("Priority queue size is too small!");

    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("Out of space!");

    H->Elements = malloc((MaxElements + 1) * sizeof(ElementType));
    if (H->Elements == NULL)
        FatalError("Out of space!");

    H->Capacity = MaxElements;
    MakeEmpty(H);
    return H;
}

void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
    H->Elements[0] = MinData;
}

void Insert(ElementType X, PriorityQueue H)
{
    int i;
    if (IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }

    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H){
     int i, Child;  
     ElementType MinElement, LastElement;

     if(IsEmpty(H)){
        Error("Priority queue is empty");
        return H->Elements[0];
     }
        MinElement = H->Elements[1];
        LastElement = H->Elements[H->Size--];

        for(i = 1; i * 2 <= H->Size; i=Child){
            Child =  i* 2;
           if(Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
            Child++;

           if(LastElement > H->Elements[Child])
           H->Elements[i] =  H->Elements[Child];
           else
           break;
        }
        H->Elements[i] = LastElement;
        return MinElement;
}

ElementType FindMin(PriorityQueue H){
       return H->Elements[1];
}

int IsEmpty(PriorityQueue H){
    return H->Size == 0;
}

int IsFull(PriorityQueue H){
    return H->Size == H->Capacity;
}

void Error(char *S){
    fputs(S, stderr);
}

void FatalError(char *S){
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintPriorityQueue(PriorityQueue H){
    int n,exponent = 0;
    n = pow(2, exponent);
    for(int i = 1; i <= H->Size; i++){
        printf("%d ", H->Elements[i]);
        if(i == n){
            putchar('\n');
            exponent++;
            n += pow(2,exponent);
        }
    }
    putchar('\n');
}