#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef _LIST_H
#define _LIST_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

typedef int ElementType;

List MakeEmpty(List L);
int IsEmpty(List L);
int CountList(List L);
void DeleteNode(Position P, List L);
Position Find(ElementType X, List L);
void PrintList(List L);
void Insert(ElementType X, List L, Position P);
void LazyDelete(ElementType X, List L);

int IsLast(Position P, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List);
void DelelteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);
#endif

int main(){
    Position P;
    List L;
    L = MakeEmpty(L);
    int i;
    P = L;
    fputs("integer for list:", stdout);
    while(scanf("%d", &i) == 1){
        Insert(i, L, P);
        P = Advance(P);
    }
    PrintList(L);
    while(getchar() != '\n') continue;
    fputs("integer to delete:", stdout);
    while(scanf("%d", &i) == 1){
        LazyDelete(i, L);
        PrintList(L);
        putchar('\n');
    }
    PrintList(L);
    system("Pause");
    return 0;
}

struct Node
{
    ElementType Element;
    Position Next;
    int Num;
};

static void FataError(char *S);
void FataError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

List MakeEmpty(List L)
{
    Position P;
    P = (Position)malloc(sizeof(struct Node));
    P->Next = NULL;
    P->Num = 0;
    return P;
}

int IsEmpty(List L)
{
    if (CountList(L) - L->Num == 0)
        return 1;
    return 0;
}

int CountList(List L)
{
    int count = 0;
    Position P;
    P = L->Next;
    while (P != NULL)
    {
        P = Advance(P);
        count++;
    }
    return count;
}

void DeleteNode(Position P, List L)
{
    Position Current;
    Current = L;
    while (Current->Next != NULL && Current->Next != P)
        Current = Advance(Current);
    Current->Next = P->Next;
    L->Num--;
    free(P);
}

void LazyDelete(ElementType X, List L)
{
    Position P;
    if (L->Num >= (CountList(L) / 2))
    {
        P = L->Next;
        while (P != NULL)
        {
            if (P->Num == 0)
                DeleteNode(P, L);
        }
    }
    else
    {
        P = Find(X, L);
        P->Num = 0;
    }
}

Position Find(ElementType X, List L)
{
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X)
    {
    a:
        P = P->Next;
    }
    if (P->Num == 0)
        goto a;
    return P;
}

void PrintList(List L)
{
    Position P;
    P = L->Next;
    if (IsEmpty(L))
        FataError("List is empty!!!");
    while (P != NULL)
    {
        if (P->Num != 0)
        {
            printf("%-5d", P->Element);
        }
        P = P->Next;
    }
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        FataError("Out of space!!");
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    TmpCell->Num = 1;
    P->Next = TmpCell;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
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
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

void DeleteList(List L){
    Position P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while(P != NULL){
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L){
    return L;
}

Position First(List L){
    return L->Next;
}

Position Advance(Position P){
    return P->Next;
}

ElementType Retrieve(Position P){
    return P->Element;
}