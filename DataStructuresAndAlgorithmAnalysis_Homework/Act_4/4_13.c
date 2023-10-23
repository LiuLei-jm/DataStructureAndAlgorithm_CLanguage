#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
void FatalError(char *S);
void PrintTree(SearchTree T);
void PrintElement(ElementType E);
void LeavePrint(SearchTree T);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void EnQueue(Position T, Queue Q);
Position Front(Queue Q);
void DeQueue(Queue Q);
Position FrontAndDeQueue(Queue Q);
static int Succ(int Value, Queue Q);

struct QueueRecord
{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    Position *Array;
};

int main()
{
    SearchTree tree = NULL;
    MakeEmpty(tree);
    tree = Insert(4, tree);
    tree = Insert(2, tree);
    tree = Insert(6, tree);
    tree = Insert(1, tree);
    tree = Insert(3, tree);
    tree = Insert(5, tree);
    tree = Insert(15, tree);
    tree = Insert(7, tree);
    tree = Insert(16, tree);

    PrintTree(tree);
    putchar('\n');
    LeavePrint(tree);

    tree = Delete(2, tree);

    PrintTree(tree);
    putchar('\n');
    LeavePrint(tree);

    MakeEmpty(tree);

    system("Pause");
    return 0;
}

SearchTree MakeEmpty(SearchTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T)
{
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
        T->Left = Insert(X, T->Left);
    else if (X > T->Element)
        T->Right = Insert(X, T->Right);
    return T;
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        FatalError("Element not found");
    else
    {
        if (X < T->Element)
            T->Left = Delete(X, T->Left);
        else if (X > T->Element)
            T->Right = Delete(X, T->Right);
        else
        {
            if (T->Left && T->Right)
            {
                TmpCell = FindMin(T->Right);
                T->Element = TmpCell->Element;
                T->Right = Delete(T->Element, T->Right);
            }
            else
            {
                TmpCell = T;
                if (T->Left == NULL)
                    T = T->Right;
                else if (T->Right == NULL)
                    T = T->Left;
                free(TmpCell);
            }
        }
    }
    return T;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void FatalError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintTree(SearchTree T)
{
    if (T != NULL)
    {
        PrintTree(T->Left);
        PrintElement(T->Element);
        PrintTree(T->Right);
    }
}

void PrintElement(ElementType E)
{
    printf("%d ", E);
}

int IsEmpty(Queue Q)
{
    return Q->Size == 0;
}

int IsFull(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
    {
        FatalError("Out of space!!!");
    }
    Q->Array = (SearchTree *)malloc(sizeof(struct TreeNode) * MaxElements);
    if (Q->Array == NULL)
    {
        FatalError("Out of space!!!");
    }
    MakeEmptyQueue(Q);
    Q->Capacity = MaxElements;
    return Q;
}

void DisposeQueue(Queue Q)
{
    free(Q->Array);
    free(Q);
}

void MakeEmptyQueue(Queue Q)
{
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

void EnQueue(Position T, Queue Q)
{
    if (IsFull(Q))
        FatalError("Full Queue");
    else
    {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = T;
    }
}

Position Front(Queue Q)
{
    return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    Q->Size--;
    Q->Front = Succ(Q->Front, Q);
}

Position FrontAndDeQueue(Queue Q)
{
    if (IsEmpty(Q))
        FatalError("Empty queue");
    else
    {
        Position Tmp = Q->Array[Q->Front];
        DeQueue(Q);
        return Tmp;
    }
}

static int Succ(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void LeavePrint(SearchTree T)
{
    Position TmpCell;
    Queue Q = CreateQueue(20);
    EnQueue(T, Q);
    while (!IsEmpty(Q))
    {
        TmpCell = FrontAndDeQueue(Q);
        printf("%d ", TmpCell->Element);
        if (TmpCell->Left != NULL)
        {
            EnQueue(TmpCell->Left, Q);
        }
        if (TmpCell->Right != NULL)
        {
            EnQueue(TmpCell->Right, Q);
        }
    }
    putchar('\n');
    DisposeQueue(Q);
}