#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

clock_t start, stop;

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType Element, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType Element, SearchTree T);
SearchTree Delete(ElementType Element, SearchTree T);
ElementType Retrieve(Position P);
void FatalError(char *S);
SearchTree GenTree(int Height, int *LastNode);
SearchTree MinAvlTree(int H);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

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
    SearchTree tree;
    start = clock();

    tree = MinAvlTree(20);

    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.23e\n", duration);

    PrintSequence(tree);

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
    };
    return NULL;
}

Position Find(ElementType Element, SearchTree T)
{
    if (T == NULL)
        return NULL;
    else if (Element < T->Element)
        T = Find(Element, T->Left);
    else if (Element > T->Element)
        T = Find(Element, T->Right);
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

SearchTree Insert(ElementType Element, SearchTree T)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!!");
        T->Element = Element;
        T->Left = T->Right = NULL;
    }
    else if (Element < T->Element)
        T = Insert(Element, T->Left);
    else if (Element > T->Element)
        T = Insert(Element, T->Right);
    return T;
}

SearchTree Delete(ElementType Element, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        return NULL;
    else if (Element < T->Element)
        T = T->Left;
    else if (Element > T->Element)
        T = T->Right;
    else if (T->Left && T->Right)
    {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        free(TmpCell);
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
    SearchTree T;

    if (Height >= 0)
    {
        T = malloc(sizeof(*T));
        T->Left = GenTree(Height - 1, LastNode);
        T->Element = ++(*LastNode);
        T->Right = GenTree(Height - 2, LastNode);
        return T;
    }
    else
        return NULL;
}

SearchTree MinAvlTree(int H)
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
    Queue Q = (Queue)malloc(sizeof(struct QueueRecord));
    if (Q == NULL)
        FatalError("Out of space!!");
    Q->Array = (Position *)malloc(sizeof(struct TreeNode) * MaxElements);
    if (Q->Array == NULL)
    {
        FatalError("Out of space!");
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

void EnQueue(Position P, Queue Q)
{
    if (IsFullQueue(Q))
        FatalError("Queue is Full!");
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
        FatalError("Queue is empty!");
    else
    {
        Q->Size--;
        Q->Front = SuccQueue(Q->Front, Q);
    }
}

Position FrontAndDeQueue(Queue Q)
{
    Position Tmp;
    Tmp = FrontQueue(Q);
    DeQueue(Q);
    return Tmp;
}

static int SuccQueue(int Value, Queue Q)
{
    if (++Value == Q->Capacity)
        Value = 0;
    return Value;
}

static void PrintSequence(SearchTree T)
{
    Position TmpCell;
    Position Previous;
    int n = 1;
    Queue Q = CreateQueue(10000);
    EnQueue(T, Q);
    while (!IsEmptyQueue(Q))
    {
        TmpCell = FrontAndDeQueue(Q);
        if(n == 1 || TmpCell->Element < Previous->Element){
            printf("\n-----------%d---------\n",n);
            n++;
        }
        printf("%d ", TmpCell->Element);
        if (TmpCell->Left != NULL)
        {
            EnQueue(TmpCell->Left, Q);
        }
        if (TmpCell->Right != NULL)
        {
            EnQueue(TmpCell->Right, Q);
        }
        Previous = TmpCell;

    }
    putchar('\n');
    DisposeQueue(Q);
}