#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef int ElementType;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position IterFind(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
ElementType Retrieve(Position P);
static int Height(Position P);
static Position SingleRotateWithLeft(Position A);
static Position DoubleRotateWithLeft(Position A);
static Position DoubleRotateWithLeft1(Position A);
static Position SingleRotateWithRight(Position A);
static Position DoubleRotateWithRight(Position A);
static Position DoubleRotateWithRight1(Position A);
void FatalError(char *S);
void PrintTree(AvlTree T);
void PrintElement(ElementType X);
void LeavePrint(AvlTree T);
int Max(int a, int b);
void ShowTree(AvlTree T);

struct AvlNode
{
    ElementType Element;
    AvlTree Left;
    AvlTree Right;
    int Height;
};

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void EnQueue(Position T, Queue Q);
Position FrontQueue(Queue Q);
void DeQueue(Queue Q);
Position FrontAndDeQueue(Queue Q);
static int SuccQueue(int Value, Queue Q);

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
    AvlTree avlTree = NULL;
    MakeEmpty(avlTree);
    avlTree = Insert(2, avlTree);
    avlTree = Insert(1, avlTree);
    ShowTree(avlTree);
    avlTree = Insert(3, avlTree);
    ShowTree(avlTree);
    avlTree = Insert(4, avlTree);
    avlTree = Insert(5, avlTree);
    ShowTree(avlTree);
    avlTree = Insert(6, avlTree);
    avlTree = Insert(7, avlTree);
    ShowTree(avlTree);
    avlTree = Insert(13, avlTree);
    avlTree = Insert(14, avlTree);
    avlTree = Insert(15, avlTree);
    // avlTree = Insert(16, avlTree);
    ShowTree(avlTree);
    avlTree = Insert(8, avlTree);
    avlTree = Insert(9, avlTree);
    avlTree = Insert(10, avlTree);
    avlTree = Insert(11, avlTree);
    avlTree = Insert(12, avlTree);
    ShowTree(avlTree);

    system("Pause");
    return 0;
}

AvlTree MakeEmpty(AvlTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, AvlTree T)
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

Position IterFind(ElementType X, AvlTree T)
{
    while (T)
    {
        if (X < T->Element)
            T = T->Left;
        else if (X > T->Element)
            T = T->Right;
        else
            return T;
    }
    return NULL;
}

Position FindMin(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T->Right);
}

Position FindMax(AvlTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Left);
}

AvlTree Insert(ElementType X, AvlTree T)
{
    if (T == NULL)
    {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        if (T == NULL)
            FatalError("Out of space!!");
        else
        {
            T->Element = X;
            T->Height = 0;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
        if (Height(T->Left) - Height(T->Right) == 2)
        {
            if (X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else
                T = DoubleRotateWithLeft1(T);
        }
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
        if (Height(T->Right) - Height(T->Left) == 2)
        {
            if (X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight1(T);
        }
    }
    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

static int Height(Position P)
{
    if (P == NULL)
        return -1;
    else
        return P->Height;
}

static Position SingleRotateWithLeft(Position A)
{
    Position B;
    B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(Height(A->Left), Height(A->Right)) + 1;
    B->Height = Max(Height(B->Left), Height(B->Right)) + 1;
    return B;
}

static Position DoubleRotateWithLeft(Position A)
{
    A->Left = SingleRotateWithRight(A->Left);
    return SingleRotateWithLeft(A);
}

static Position DoubleRotateWithLeft1(Position A)
{
    Position B, C;
    B = A->Left;
    C = B->Right;

    B->Right = C->Left;
    A->Left = C->Right;
    C->Left = B;
    C->Right = A;
    A->Height = Max(Height(A->Left), Height(A->Right)) + 1;
    B->Height = Max(Height(B->Left), Height(B->Right)) + 1;
    C->Height = Max(A->Height, B->Height) + 1;

    return C;
}

static Position SingleRotateWithRight(Position A)
{
    Position B;
    B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    B->Height = Max(Height(B->Left), Height(B->Right)) + 1;
    A->Height = Max(Height(A->Left), Height(A->Right)) + 1;
    return B;
}

static Position DoubleRotateWithRight(Position A)
{
    A->Right = SingleRotateWithLeft(A->Right);
    return SingleRotateWithRight(A);
}

static Position DoubleRotateWithRight1(Position A)
{
    Position B, C;
    B = A->Right;
    C = B->Left;

    B->Left = C->Right;
    A->Right = C->Left;
    C->Left = A;
    C->Right = B;
    A->Height = Max(Height(A->Left), Height(A->Right)) + 1;
    B->Height = Max(Height(B->Left), Height(B->Right)) + 1;
    C->Height = Max(A->Height, B->Height) + 1;

    return C;
}

void FatalError(char *S)
{
    fputs(S, stderr);
    exit(EXIT_FAILURE);
}

void PrintTree(AvlTree T)
{
    if (T != NULL)
    {
        PrintTree(T->Left);
        PrintElement(T->Element);
        PrintTree(T->Right);
    }
}

void PrintElement(ElementType X)
{
    printf("%d ", X);
}

void LeavePrint(AvlTree T)
{
    Position TmpCell;
    int m, n;
    m = n = 0;
    Queue Q = CreateQueue(30);
    EnQueue(T, Q);
    while (!IsEmptyQueue(Q))
    {
        TmpCell = FrontAndDeQueue(Q);
        printf("%d ", Retrieve(TmpCell));
        if (TmpCell->Left != NULL)
        {
            EnQueue(TmpCell->Left, Q);
        }
        if (TmpCell->Right != NULL)
        {
            EnQueue(TmpCell->Right, Q);
        }
        m++;
        if(m == pow(2,n)){
            putchar('\n');
            n++;
            m = 0;
        }
    }
    putchar('\n');
    DisposeQueue(Q);
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int IsEmptyQueue(Queue Q)
{
    return Q->Size == 0;
}

int IsFullQueue(Queue Q)
{
    return Q->Size == Q->Capacity;
}

Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
    {
        FatalError("Out of space!!");
    }
    Q->Array = (AvlTree *)malloc(sizeof(struct AvlNode) * MaxElements);
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
    if (IsFullQueue(Q))
        FatalError("Full Queue");
    else
    {
        Q->Size++;
        Q->Rear = SuccQueue(Q->Rear, Q);
        Q->Array[Q->Rear] = T;
    }
}

Position FrontQueue(Queue Q)
{
    return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    Q->Size--;
    Q->Front = SuccQueue(Q->Front, Q);
}

Position FrontAndDeQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
        FatalError("Empty queue");
    else
    {
        Position Tmp = Q->Array[Q->Front];
        DeQueue(Q);
        return Tmp;
    }
}

static int SuccQueue(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

void ShowTree(AvlTree T)
{
    // printf("Perorder traversal: ");
    // PrintTree(T);
    // printf("\n");
    printf("Sequence traversal: \n");
    LeavePrint(T);
}