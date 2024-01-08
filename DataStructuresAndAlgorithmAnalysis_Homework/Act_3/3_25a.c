/*
 * 实现队列，链表
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

struct QueueRecord;
typedef struct QueueRecord *Queue;
struct QueueRecord
{
    ElementType Element;
    struct QueueRecord *Next;
};

int IsEmpty(Queue Q);
Queue CreateQueue();
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X,Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndDeQueue(Queue Q);
void FataError(char *S);
void PrintQueue(Queue Q);

int main()
{
    Queue head = CreateQueue();
    EnQueue(1,head);
    EnQueue(2,head);
    EnQueue(3,head);
    EnQueue(4,head);
    EnQueue(5,head);
    ElementType Tmp = FrontAndDeQueue(head);
    printf("%d rank out!\n",Tmp);

    PrintQueue(head);
    DisposeQueue(head);

    system("Pause");
    return 0;
}

void PrintQueue(Queue Q){
    Queue pCurrent = Q->Next;
    while(pCurrent != NULL){
        printf("%d ",pCurrent->Element);
        pCurrent = pCurrent->Next;
    }
    printf("\n");
}

int IsEmpty(Queue Q)
{
    return Q->Next == NULL;
}

Queue CreateQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (NULL == Q)
        FataError("out of space!");
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q){
    Queue TmpCell;
    while(Q){
        TmpCell = Q->Next;
        free(Q);
        Q = TmpCell;
    }   
}

void MakeEmpty(Queue Q){
    Q->Element = -1;
    Q->Next = NULL;   
}

void EnQueue(ElementType X, Queue Q){
    Queue pCurrent = Q;
    while(pCurrent->Next != NULL){
        pCurrent = pCurrent->Next;
    }
    Queue TmpCell = (Queue)malloc(sizeof(struct QueueRecord));
    if(TmpCell == NULL){
        FataError("out of space!");
    }
    TmpCell->Element = X;
    TmpCell->Next = pCurrent->Next;
    pCurrent->Next = TmpCell;
}

ElementType Front(Queue Q){
    return Q->Next->Element;   
}

void DeQueue(Queue Q){
    Queue TmpCell = Q->Next;   
    Q->Next = TmpCell->Next;
    free(TmpCell);
}

ElementType FrontAndDeQueue(Queue Q){
    ElementType Tmp = Front(Q);
    DeQueue(Q);
    return Tmp;
}
void FataError(char *S){
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}
