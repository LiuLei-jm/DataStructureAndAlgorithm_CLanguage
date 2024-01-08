#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P->Next != NULL && P->Element != X)
        P = P->Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;
    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P = L;
    while (P->Next->Element != X && P->Next != NULL)
        P = P->Next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;

    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FataError("Out of space!!!");

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, TmpCell;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        TmpCell = P->Next;
        free(P);
        P = TmpCell;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void FataError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintList(List L)
{
    Position P = L->Next;
    while (P != NULL)
    {
        printf("%d ", P->Element);
        P = P->Next;
    }
    putchar('\n');
}