/*
 * 使用一个数组实现三个栈
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXELEMENTS 15

typedef int ElementType;

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node
{
    ElementType *Array;
    int Top1;
    int Top2;
    int Top3;
    int Capacity;
    int Size;
};

int IsEmpty(Stack S, int Tag);
int IsFull(Stack S, int Tag);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S, int Tag);
ElementType Top(Stack S, int Tag);
void Pop(Stack S, int Tag);
ElementType TopAndPop(Stack S, int Tag);
void FataError(char *S);
void PrintStack(Stack S);

int main()
{
    Stack S = CreateStack(MAXELEMENTS);
    Push(1, S, 0);
    Push(2, S, 0);
    Push(3, S, 0);
    Push(4, S, 0);
    Push(5, S, 0);
    Push(6, S, 1);
    Push(7, S, 1);
    Push(8, S, 1);
    Push(9, S, 1);
    Push(10, S, 1);
    Push(11, S, 2);
    Push(12, S, 2);
    Push(13, S, 2);
    Push(14, S, 2);
    Push(15, S, 2);
    Pop(S,2);
    Pop(S,1);

    PrintStack(S);
    DisposeStack(S);
    system("Pause");
    return 0;
}

int IsEmpty(Stack S, int Tag)
{
    if (Tag == 0)
    {
        return S->Top1 == -3;
    }
    else if (Tag == 1)
    {
        return S->Top2 == -2;
    }
    else if (2 == Tag)
    {
        return S->Top3 == -1;
    }
    else
        return S->Size == 0;
}

int IsFull(Stack S, int Tag)
{
    if (Tag == 0)
    {
        return S->Top1 == MAXELEMENTS - 3;
    }
    else if (Tag == 1)
    {
        return S->Top2 == MAXELEMENTS - 2;
    }
    else if (2 == Tag)
    {
        return S->Top3 == MAXELEMENTS - 1;
    }
    else
        return S->Size == S->Capacity;
}

Stack CreateStack(int MaxElements)
{
    Stack S = (Stack)malloc(sizeof(struct Node));
    if (S == NULL)
    {
        FataError("out of space!");
    }
    S->Array = (ElementType *)malloc(sizeof(ElementType) * MAXELEMENTS);
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
    S->Top1 = -3;
    S->Top2 = -2;
    S->Top3 = -1;
    S->Size = 0;
    S->Capacity = MAXELEMENTS;
}

void Push(ElementType X, Stack S, int Tag)
{
    if (IsFull(S, Tag))
        FataError("Stack is full");
    if (Tag == 0)
    {
        S->Top1 += 3;
        S->Array[S->Top1] = X;
        S->Size++;
    }
    else if (Tag == 1)
    {
        S->Top2 += 3;
        S->Array[S->Top2] = X;
        S->Size++;
    }
    else
    {
        S->Top3 += 3;
        S->Array[S->Top3] = X;
        S->Size++;
    }
}

ElementType Top(Stack S, int Tag)
{
    if (IsEmpty(S, Tag))
        FataError("Stack is empty");
    if (Tag == 0)
    {
        return S->Array[S->Top1];
    }
    else if (Tag == 1)
    {
        return S->Array[S->Top2];
    }
    else
    {
        return S->Array[S->Top3];
    }
}

void Pop(Stack S, int Tag)
{
    if (IsEmpty(S, Tag))
        FataError("Stack is empty");
    if (Tag == 0)
    {
        S->Top1 -= 3;
        S->Size--;
    }
    else if (Tag == 1)
    {
        S->Top2 -= 3;
        S->Size--;
    }
    else
    {
        S->Top3 -= 3;
        S->Size--;
    }
}

ElementType TopAndPop(Stack S, int Tag)
{
    ElementType TmpCell;
    if (0 == Tag)
    {
        TmpCell = S->Array[S->Top1];
    }
    else if(1 == Tag){
        TmpCell = S->Array[S->Top2];
    }
    else{
        TmpCell = S->Array[S->Top3];
    }
    Pop(S, Tag);
    return TmpCell;
}

void FataError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintStack(Stack S)
{
    int i;
    printf("Stack1:");
    for (i = 0; i <= S->Top1; i += 3)
    {
        printf("%d ", S->Array[i]);        
    }
    printf("\n");
    printf("Stack2:");
    for (i = 1; i <= S->Top2; i += 3)
    {
        printf("%d ", S->Array[i]);
    }
    printf("\nStack3:");
    for (i = 2; i <= S->Top3; i += 3)
    {
        printf("%d ", S->Array[i]);
    }
    printf("\n");
}