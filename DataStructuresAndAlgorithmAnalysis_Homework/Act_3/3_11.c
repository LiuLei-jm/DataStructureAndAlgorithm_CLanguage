#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

#define ElementType int
#define NUMSIZE 32488

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node
{
    ElementType Element;
    PtrToNode Next;
};

List MakeEmpty()
{
    List head = (List)malloc(sizeof(struct Node));
    if (head == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    head->Next = NULL;
    return head;
}

List InitList(int size, List L)
{
    Position pCurrent = L;
    for (int i = 1; i <= size; i++)
    {
        Position TmpCell = (Position)malloc(sizeof(struct Node));
        TmpCell->Element = i;
        TmpCell->Next = NULL;
        pCurrent->Next = TmpCell;
        pCurrent = TmpCell;
    }
    return L;
}

int IteratorFind(int n, List L)
{
    Position pCurrent = L;
    while (pCurrent != NULL && pCurrent->Element != n)
    {
        pCurrent = pCurrent->Next;
    }
    if (pCurrent->Element == n)
    {
        return pCurrent->Element;
    }
    else
        return 0;
}

int RecursionFind(int n, List L){
    Position pCurrent = L->Next;
    if(!pCurrent || pCurrent->Element == n){
        if(pCurrent->Element == n) return pCurrent->Element;
        else return 0;
    }
    else
        return RecursionFind(n, pCurrent);
}
 
int main()
{
    double duration1, duration2;
    int find;
    List head = MakeEmpty();
    head = InitList(NUMSIZE, head);

    start = clock();
    find = IteratorFind(NUMSIZE, head);    
    stop = clock();
    if (find != 0)
    {
        duration1 = ((double)(stop - start)) / CLK_TCK;
        printf("tick1 = %f\n", (double)(stop - start));
        printf("duration1 = %6.2e\n", duration1);
    }

    start = clock();
    find = RecursionFind(NUMSIZE, head);    
    stop = clock();
    if (find != 0)
    {
        duration2 = ((double)(stop - start)) / CLK_TCK;
        printf("tick2 = %f\n", (double)(stop - start));
        printf("duration2 = %6.2e\n", duration1);
    }

    system("Pause");
    return 0;
}
