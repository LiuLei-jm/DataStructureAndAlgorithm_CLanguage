#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200000

clock_t start, stop;

struct Node
{
    int Element;
    struct Node *Next;
};
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty()
{
    List l = (List)malloc(sizeof(struct Node));
    if (l == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    l->Next = NULL;
    return l;
}

void insertTail(int n, Position *rear)
{
    Position tmp = (Position)malloc(sizeof(struct Node));
    if (tmp == NULL)
    {
        printf("out of space!\n");
        exit(-1);
    }
    tmp->Element = n;
    tmp->Next = NULL;
    (*rear)->Next = tmp;
    *rear = tmp;
}

void printList(List l)
{
    Position pCurrent = l->Next;
    while (pCurrent != NULL)
    {
        printf("%d ", pCurrent->Element);
        pCurrent = pCurrent->Next;
    }
    printf("\n");
}

void Delete(Position p)
{
    Position tmp = p->Next;
    p->Next = tmp->Next;
    free(tmp);
}

int main()
{
    List arr = MakeEmpty();
    Position pRear = arr;
    Position pCurrent;
    double duration;
    for (int i = 0, j = 1; i < MAX; i += 2, j++)
    {
        insertTail(j, &pRear);
        insertTail(j, &pRear);
    }
    // printList(arr);
    pCurrent = arr;
    start = clock();
    while (pCurrent != NULL && pCurrent->Next != NULL)
    {
        pRear = pCurrent->Next;
        while (pRear != NULL && pRear->Next != NULL)
        {
            if (pCurrent->Next->Element == pRear->Next->Element)
            {
                Delete(pRear);
            }
            pRear = pRear->Next;
        }
        pCurrent = pCurrent->Next;
    }
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick: %f\n", (double)(stop - start));
    printf("duration: %6.2e\n", duration);

    system("Pause");
    return 0;
}