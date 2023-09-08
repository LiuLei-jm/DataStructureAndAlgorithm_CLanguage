/*
编写仅用一个数组实现两个栈的例程。除非数组的每一个单元都被使用，否则栈例程不能有溢出声明
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXELEMENTS 10

#ifndef _Stack_h

typedef int ElementType;

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S, int Tag);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S, int Tag);
ElementType Top(Stack S, int Tag);
void Pop(Stack S, int Tag);
ElementType TopAndPop(Stack S, int Tag);
void PrintStack(Stack S);

void FataError(char *s);

#endif

struct StackRecord
{
    ElementType *Array;
    int Top1;
    int Top2;
};

int main()
{
    Stack S = CreateStack(MAXELEMENTS);
    int tmp;
    Push(1, S, 0);
    Push(2, S, 0);
    Push(3, S, 0);
    Push(4, S, 0);
    tmp = TopAndPop(S, 0);
    Push(4, S, 0);
    printf("stack1 pop %d\n", tmp);

    Push(5, S, 1);
    Push(6, S, 1);
    Push(7, S, 1);
    Push(8, S, 1);
    Push(9, S, 1);
    Push(10, S, 1);
    PrintStack(S);
    Push(11, S, 1);


    DisposeStack(S);
    system("Pause");
    return 0;
}

void PrintStack(Stack S)
{
    int i;
    printf("Stack1: ");
    for (i = 0; i <= S->Top1; i++)
    {
        printf("%d ", S->Array[i]);
    }
    printf("\n");
    printf("Stack2: ");
    for (i = MAXELEMENTS - 1; i >= S->Top2; i--)
    {
        printf("%d ", S->Array[i]);        
    }
    printf("\n");
}

int IsEmpty(Stack S, int Tag)
{
    return Tag == 0 ? S->Top1 == -1 : S->Top2 == MAXELEMENTS;
}

int IsFull(Stack S)
{
    return S->Top2 - S->Top1 == 1;
}

Stack CreateStack(int MaxElements)
{
    Stack S = (Stack)malloc(sizeof(struct StackRecord));
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
    S->Top1 = -1;
    S->Top2 = MAXELEMENTS;
}

void Push(ElementType X, Stack S, int Tag)
{
    if (IsFull(S))
    {
        FataError("Stack is full!");
    }
    if (Tag == 0)
    {
        (S->Top1)++;
        S->Array[S->Top1] = X;
    }
    else
    {
        (S->Top2)--;
        S->Array[S->Top2] = X;
    }
}

ElementType Top(Stack S, int Tag)
{
    if (Tag == 0)
    {
        return S->Array[S->Top1];
    }
    else
    {
        return S->Array[S->Top2];
    }
}

void Pop(Stack S, int Tag)
{
    if (IsEmpty(S, Tag))
        FataError("Stack is empty");
    if (Tag == 0)
    {
        (S->Top1--);
    }
    else
    {
        (S->Top2++);
    }
}

ElementType TopAndPop(Stack S, int Tag)
{
    ElementType Tmp;
    Tmp = Top(S, Tag);
    Pop(S, Tag);
    return Tmp;
}

void FataError(char *s)
{
    fputs(s, stderr);
    exit(EXIT_FAILURE);
}