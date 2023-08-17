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
    struct Node *Next;
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

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }

    return P;
}

Position FindPrevious(ElementType X, List L)
{
    Position P;

    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);

    if (!IsLast(P))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(ElementType X, Position P)
{
    Position TmpCell;

    TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("Out of space!!");
        return;
    }

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
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

void SwapWithNext(Position P, List L){
    Position TmpCell1, TmpCell2;

    TmpCell1 = P->Next;
    if(IsLast(TmpCell1)){
        return;
    }
    TmpCell2 = TmpCell1->Next;
    TmpCell1->Next = TmpCell2->Next;
    P->Next = TmpCell2;
    TmpCell2->Next = TmpCell1;
}

int main()
{
    List list;
    list = MakeEmpty(list);
    Position find;
    find = FindPrevious(-1, list);
    for (int i = 1; i <= 8; i++)
    {
        Insert(i, find);
        find = Find(i, list);
    }
    PrintList(list);
    find = FindPrevious(7, list);
    SwapWithNext(find, list);
    PrintList(list);

    DeleteList(list);
    system("pause");
    return 0;
}