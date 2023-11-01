#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t start, stop;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);
void FatalError(char *S);
SearchTree GenTree(int Height, int *LastNode);
SearchTree PerfectTree(int H);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

#define MAXELEMENTS 10000

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void EnQueue(Position P, Queue Q);
Position FrontQueue(Queue Q);
void DeQueue(Queue Q);
Position FrontAndDeQueue(Queue Q);
static int SuccQueue(int Value, Queue Q);

struct QueueRecord
{
    int Capacity;
    int Size;
    int Front;
    int Rear;
    Position *Array;
};

static void PrintSequence(SearchTree T);

int main()
{
    double duration;
    SearchTree tree = NULL;

    start = clock();

    tree = PerfectTree(22);

    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.4e\n", duration);

    PrintSequence(tree);

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
    else if (X < T->Element)
        T = Find(X, T->Left);
    else if (X > T->Element)
        T = Find(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T->Left;
    else
        return FindMin(T->Left);
}

Position FindMax(SearchTree T)
{
    if (T == NULL)
        return NULL;
    while (T->Right != NULL)
        T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!!");
        T->Element = X;
        T->Left = T->Right = NULL;
    }
    else if (X < T->Element)
        T = Insert(X, T->Left);
    else if (X > T->Element)
        T = Insert(X, T->Right);
    return T;
}
SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        T = Delete(X, T->Left);
    else if (X > T->Element)
        T = Delete(X, T->Right);
    else if (T->Left && T->Right)
    {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        free(TmpCell);
    }
    else
    {
        TmpCell = T;
        if (TmpCell->Left == NULL)
            T = TmpCell->Right;
        else if (TmpCell->Right == NULL)
            T = TmpCell->Left;
        free(TmpCell);
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

SearchTree GenTree(int Height, int *LastNode)
{
    SearchTree T = NULL;

    if (Height >= 0)
    {
        T = malloc(sizeof(*T));
        T->Left = GenTree(Height - 1, LastNode);
        T->Element = ++(*LastNode);
        T->Right = GenTree(Height - 1, LastNode);
    }
    return T;
}

SearchTree PerfectTree(int H)
{
    int LastNodeAssigned = 0;
    return GenTree(H, &LastNodeAssigned);
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
    Queue Q;
    Q = malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!!");
    Q->Array = (Position *)malloc(sizeof(struct TreeNode) * MaxElements);
    if (Q->Array == NULL)
        FatalError("Out of space!!!");
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

void EnQueue(Position P, Queue Q)
{
    if (IsFullQueue(Q))
        FatalError("Queue is full");
    else
    {
        Q->Size++;
        Q->Rear = SuccQueue(Q->Rear, Q);
        Q->Array[Q->Rear] = P;
    }
}

Position FrontQueue(Queue Q)
{
    return Q->Array[Q->Front];
}

void DeQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
        FatalError("Queue is empty");
    else
    {
        Q->Size--;
        Q->Front = SuccQueue(Q->Front, Q);
    }
}

Position FrontAndDeQueue(Queue Q)
{
    Position TmpCell;
    TmpCell = FrontQueue(Q);
    DeQueue(Q);
    return TmpCell;
}

static int SuccQueue(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

static void PrintSequence(SearchTree T)
{
    if (T == NULL)
        return;
    Position TmpCell, Previous;
    TmpCell = Previous = NULL;
    int n = 1;
    Queue Q = CreateQueue(MAXELEMENTS);
    EnQueue(T, Q);
    while (!IsEmptyQueue(Q))
    {
        TmpCell = FrontAndDeQueue(Q);
        if (n == 1 || TmpCell->Element < Previous->Element)
        {
            printf("\n-------------%d------------\n", n);
            n++;
        }
        printf("%d ", TmpCell->Element);
        if (TmpCell->Left != NULL)
            EnQueue(TmpCell->Left, Q);
        if (TmpCell->Right != NULL)
            EnQueue(TmpCell->Right, Q);
        Previous = TmpCell;
    }
    putchar('\n');
    DisposeQueue(Q);
}
