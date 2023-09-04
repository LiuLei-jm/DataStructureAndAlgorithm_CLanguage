#include <stdio.h>
#include <stdlib.h>

#define MAXN 7
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

List CreatList()
{
    List L = (List)malloc(sizeof(struct Node));
    if (L == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    L->Element = -1;
    L->Next = NULL;
    return L;
}

void Insert(int n, List l)
{
    Position pCurrent = l;
    Position TmpCell = (Position)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    TmpCell->Element = n;
    TmpCell->Next = NULL;
    while (pCurrent->Next != NULL)
        pCurrent = pCurrent->Next;
    pCurrent->Next = TmpCell;
}

Position Advance(List l)
{
    if (l->Next != NULL)
    {
        return l->Next;
    }
    else
        return NULL;
}

ElementType Retrieve(Position p)
{
    return p->Element;
}

void DeleteList(List l){
    Position pCurrent, Tmp;
    pCurrent = l;
    while(pCurrent != NULL){
        Tmp = pCurrent->Next;
        free(pCurrent);
        pCurrent = Tmp;
    }
}

void graphToSpot(int graph[][MAXN], List spot[MAXN])
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            if (graph[i][j] > 0)
                Insert(j, spot[i]);
        }
    }
}

void printAll(List l)
{
    Position p = Advance(l);
    while (p)
    {
        printf("%d ", Retrieve(p));
        p = Advance(p);
    }
}

int main()
{
    int graph[MAXN][MAXN] = {
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {2, 1, 1, 1, 0, 0, 0},
        {3, 2, 1, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0},
        {3, 3, 3, 3, 2, 1, 0},
        {2, 2, 2, 1, 0, 0, 0}};
    List spot[MAXN];
    for(int i = 0; i < MAXN; i++){
        spot[i] = CreatList();
    }
    graphToSpot(graph, spot);
    for (int i = 0; i < MAXN; i++)
    {
        printAll(spot[i]);
        printf("\n");
    }
    for(int i = 0; i < MAXN; i++){
        DeleteList(spot[i]);
    }
    system("Pause");
    return 0;
}