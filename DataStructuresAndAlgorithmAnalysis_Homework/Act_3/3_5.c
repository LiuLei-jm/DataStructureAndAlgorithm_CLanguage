/*
给定两个排序的表L1和L2，只使用基本的表操作编写计算L1⋃L2的过程
*/
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

List MakeEmpty(List L)
{
    L = (List)malloc(sizeof(struct Node));
    L->Element = -1;
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P)
{
    return P->Next == NULL;
}

Position Find(List L, ElementType value)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != value)
    {
        P = P->Next;
    }
    return P;
}

Position FindPrevious(List L, ElementType value)
{
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != value)
    {
        P = P->Next;
    }
    return P;
}

void Insert(Position P, ElementType value)
{
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("out of space!\n");
        return;
    }
    TmpCell->Element = value;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, TmpCell;
    P = L;
    while (P->Next != NULL)
    {
        TmpCell = P;
        P = TmpCell->Next;
        free(TmpCell);
    }
}

void PrintList(List L)
{
    Position P;
    P = L->Next;
    while (P != NULL)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    putchar('\n');
}

List Union(List L1, List L2)
{
    Position L1Pos, L2Pos, ResPos;
    List result;
    result = MakeEmpty(result);
    ResPos = FindPrevious(result, -1);
    L1Pos = L1->Next;
    L2Pos = L2->Next;
    while (L1Pos != NULL && L2Pos != NULL)
    {
        if (L1Pos->Element < L2Pos->Element)
        {
            Insert(ResPos, L1Pos->Element);
            ResPos = Find(result, L1Pos->Element);
            L1Pos = L1Pos->Next;
        }
        else if (L1Pos->Element > L2Pos->Element)
        {
            Insert(ResPos, L2Pos->Element);
            ResPos = Find(result, L2Pos->Element);
            L2Pos = L2Pos->Next;
        }
        else
        {
            Insert(ResPos, L1Pos->Element);
            ResPos = Find(result, L1Pos->Element);
            L1Pos = L1Pos->Next;
            L2Pos = L2Pos->Next;
        }
    }
    while(L1Pos != NULL){
        Insert(ResPos, L1Pos->Element);
        ResPos = Find(result, L1Pos->Element);
        L1Pos = L1Pos->Next;
    }
    while(L2Pos != NULL){
        Insert(ResPos, L2Pos->Element);
        ResPos = Find(result, L2Pos->Element);
        L2Pos = L2Pos->Next;
    }
    return result;
}

int main()
{
    List list1;
    list1 = MakeEmpty(list1);
    Position pos = FindPrevious(list1, -1);
    Insert(pos, 1);
    pos = Find(list1, 1);
    Insert(pos, 3);
    pos = Find(list1, 3);
    Insert(pos, 5);

    List list2;
    list2 = MakeEmpty(list2);
    pos = FindPrevious(list2, -1);
    Insert(pos, 2);
    pos = Find(list2, 2);
    Insert(pos, 4);
    pos = Find(list2, 4);
    Insert(pos, 6);
    pos = Find(list2, 6);
    Insert(pos, 8);

    PrintList(list1);
    PrintList(list2);

    List result;
    result = MakeEmpty(result);
    result = Union(list1, list2);

    PrintList(result);
    DeleteList(list1);
    DeleteList(list2);
    DeleteList(result);

    system("Pause");
    return 0;
}