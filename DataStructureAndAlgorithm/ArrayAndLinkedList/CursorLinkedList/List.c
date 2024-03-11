#include <stdio.h>
#include <stdlib.h>
#include "List.h"

#define SpaceSize 100

struct Node
{
    ElementType Element;
    Position Next;
};

struct Node CursorSpace[SpaceSize];

static Position CursorAlloc(void)
{
    Position P;

    P = CursorSpace[0].Next;
    CursorSpace[0].Next = CursorSpace[P].Next;

    return P;
}

static void CursorFree(Position P)
{
    CursorSpace[P].Next = CursorSpace[0].Next;
    CursorSpace[0].Next = P;
}


void InitializeCursorSpace(void)
{
    for (int i = 0; i < SpaceSize; i++)
    {
        CursorSpace[i].Next = (i + 1) % SpaceSize;
    }
}

List MakeEmpty(List L)
{
    if (L != 0)
        DeleteList(L);
    L = CursorAlloc();
    if (L == 0)
        FatalError("Out of space!!!");
    CursorSpace[L].Next = 0;
    return L;
}

int IsEmpty(const List L)
{
    return CursorSpace[L].Next == 0;
}

int IsLast(const Position P, const List L)
{
    return CursorSpace[P].Next == 0;
}

Position Find(ElementType X, const List L)
{
    Position P;

    P = CursorSpace[L].Next;
    while (P && CursorSpace[P].Element != X)
        P = CursorSpace[P].Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P, L))
    {
        TmpCell = CursorSpace[P].Next;
        CursorSpace[P].Next = CursorSpace[TmpCell].Next;
        CursorFree(TmpCell);
    }
}

Position FindPrevious(ElementType X, const List L)
{
    Position P;
    P = L;
    while (CursorSpace[P].Next && CursorSpace[CursorSpace[P].Next].Element != X)
        P = CursorSpace[P].Next;

    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = CursorAlloc();
    if (TmpCell == 0)
        FatalError("Out of space!!!");

    CursorSpace[TmpCell].Element = X;
    CursorSpace[TmpCell].Next = CursorSpace[P].Next;
    CursorSpace[P].Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, Tmp;
    P = CursorSpace[L].Next;
    CursorSpace[L].Next = 0;
    while (P != 0)
    {
        Tmp = CursorSpace[P].Next;
        CursorFree(P);
        P = Tmp;
    }
}

Position Header(const List L)
{
    return L;
}

Position First(const List L)
{
    return CursorSpace[L].Next;
}

Position Advance(const Position P)
{
    return CursorSpace[P].Next;
}

ElementType Retrieve(const Position P)
{
    return CursorSpace[P].Element;
}

void PrintCursorLinkedList(const List L)
{
    Position P = Header(L);

    if (IsEmpty(P))
        printf("Empty list\n");
    else
    {
        do
        {
            P = Advance(P);
            printf("%d ", Retrieve(P));
        } while (!IsLast(P, L));
        printf("\n");
    }
}

void FatalError(char * S){
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}