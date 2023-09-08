/*
给定两个排序的表L1和L2，只使用基本的表操作编写计算L1⋂L2的过程
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
    L = (Position)malloc(sizeof(struct Node));
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

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;
    return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, Position P)
{
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("out of space!\n");
        return;
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, TmpCell;
    P = L->Next;
    while (P != NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
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
    printf("\n");
}

List Intersect(List L1, List L2)
{
    Position TmpCell1, TmpCell2, pos;
    TmpCell1 = L1->Next;
    TmpCell2 = L2->Next;
    List result;
    result = MakeEmpty(result);
    pos = FindPrevious(-1, result);
    while (TmpCell1 != NULL && TmpCell2 != NULL)
    {
        if (TmpCell1->Element < TmpCell2->Element)
        {
            TmpCell1 = TmpCell1->Next;
        }
        else if (TmpCell1->Element > TmpCell2->Element)
        {
            TmpCell2 = TmpCell2->Next;
        }
        else
        {
            Insert(TmpCell1->Element, pos);
            pos = Find(TmpCell1->Element, result);
            TmpCell1 = TmpCell1->Next;
            TmpCell2 = TmpCell2->Next;
        }
    }
    return result;
}

int main()
{
    List list1;
    list1 = MakeEmpty(list1);
    Position pos = FindPrevious(-1, list1);
    Insert(1, pos);
    pos = Find(1, list1);
    Insert(2, pos);
    pos = Find(2, list1);
    Insert(3, pos);
    pos = Find(3, list1);
    Insert(5, pos);
    pos = Find(5, list1);
    PrintList(list1);

    List list2;
    list2 = MakeEmpty(list2);
    pos = FindPrevious(-1, list2);
    Insert(2, pos);
    pos = Find(2, list2);
    Insert(3, pos);
    pos = Find(3, list2);
    Insert(4, pos);
    pos = Find(4, list2);
    Insert(5, pos);
    pos = Find(5, list2);
    PrintList(list2);

    List result;
    result = MakeEmpty(result);
    result = Intersect(list1, list2);
    PrintList(result);
    DeleteList(list1);
    DeleteList(list2);
    DeleteList(result);
    system("pause");
    return 0;
}