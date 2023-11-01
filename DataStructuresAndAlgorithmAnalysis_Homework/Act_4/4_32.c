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
void PrintRange(ElementType Lower, ElementType Upper, SearchTree T);
void PrintLine(ElementType X);

struct TreeNode
{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

int main()
{
    double duration;
    SearchTree tree = NULL;
    start = clock();
    tree = PerfectTree(10);
    PrintRange(20,10000,tree);
    putchar('\n');
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.4e\n", duration);

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
        return T;
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
        T = malloc(sizeof(struct TreeNode));
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
    SearchTree T = NULL;

    if (Height >= 0)
    {
        T = malloc(sizeof(*T));
        if (T == NULL)
            FatalError("Out of space!!!");
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

void PrintRange(ElementType Lower, ElementType Upper, SearchTree T)
{
    if (T != NULL)
    {
        if (Lower <= T->Element)
            PrintRange(Lower, Upper, T->Left);
        if (Lower <= T->Element && T->Element <= Upper)
            PrintLine(T->Element);
        if (T->Element <= Upper)
            PrintRange(Lower, Upper, T->Right);
    }
}

void PrintLine(ElementType X){
    printf("%d ", X);
}