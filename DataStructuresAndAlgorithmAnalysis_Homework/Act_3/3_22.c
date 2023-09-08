/*
栈的第三种操作FindMin,返回数据结构的最小元素，所有操作在最坏的情况下的运行时间都是O(1)
第四种操作DeleteMin,找出并删除最小元素
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXELEMENTS 10

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node
{
    ElementType *Array;
    int Top;
    int Capacity;
    int Min;
};

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);
ElementType FindMin(Stack S);
void FataError(char *S);
void DeleteMin(Stack S);
void PrintStack(Stack S);

int main()
{
    Stack S = CreateStack(MAXELEMENTS);
    int min;

    Push(10, S);
    Push(4, S);
    Push(5, S);
    Push(8, S);
    Push(9, S);
    Push(7, S);
    Push(6, S);
    min = FindMin(S);
    printf("min : %d\n", min);
    Push(2, S);
    min = FindMin(S);
    printf("min : %d\n", min);
    DeleteMin(S);
    PrintStack(S);
    DeleteMin(S);
    PrintStack(S);
    DisposeStack(S);
    system("Pause");
    return 0;
}

int IsEmpty(Stack S)
{
    return S->Top == -1;
}

int IsFull(Stack S)
{
    return S->Capacity - S->Top == 1;
}

Stack CreateStack(int MaxElements)
{
    Stack S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL)
    {
        FataError("out of space!");
    }
    S->Array = (ElementType *)malloc(sizeof(ElementType) * MaxElements);
    if (S->Array == NULL)
    {
        FataError("out of space!");
    }
    MakeEmpty(S);
    return S;
}

void DisposeStack(Stack S)
{
    free(S->Array);
    free(S);
}

void MakeEmpty(Stack S)
{
    S->Top = -1;
    S->Capacity = MAXELEMENTS;
    S->Min = 0;
}

void Push(ElementType X, Stack S)
{
    if (IsFull(S))
        FataError("Stack is full!");
    S->Array[++(S->Top)] = X;
    if (S->Array[S->Min] > S->Array[S->Top])
        S->Min = S->Top;
}

ElementType Top(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->Top];
    else
        FataError("Stack is empty");
}

void Pop(Stack S)
{
    if (IsEmpty(S))
        FataError("Stack is empty!");
    (S->Top)--;
}

ElementType TopAndPop(Stack S)
{
    ElementType Tmp = Top(S);
    Pop(S);
    return Tmp;
}

ElementType FindMin(Stack S)
{
    if (!IsEmpty(S))
        return S->Array[S->Min];
    else
        FataError("Stack is empty!");
}

void FataError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void DeleteMin(Stack S)
{
    int i;
    for (i = S->Min; i < S->Top; i++)
    {
        S->Array[i] = S->Array[i + 1];
    }
    (S->Top)--;
    S->Min = S->Top;
    for (i = S->Top - 1; i >= 0; i--)
    {
        if (S->Array[i] < S->Array[S->Min])
            S->Min = i;
    }
}

void PrintStack(Stack S){
    int i;
    for(i = S->Top; i >= 0; i--){
        printf("%d ", S->Array[i]);
    }
    printf("\n");
}