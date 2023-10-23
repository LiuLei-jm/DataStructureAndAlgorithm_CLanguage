#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 500000
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
SearchTree MakeRandomTree1(int Lower, int Upper);
SearchTree MakeRandomTree(int N);

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
    MakeEmpty(tree);
    start = clock();
    MakeRandomTree(500);
    stop = clock();
    duration = (double)(stop - start) / CLK_TCK;
    printf("tick = %f\n", (double)(stop - start));
    printf("duration = %6.2e\n", duration);

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
    {
        return NULL;
    }
    else if (X < T->Element)
    {
        T = Find(X, T->Left);
    }
    else if (X > T->Element)
    {
        T = Find(X, T->Right);
    }
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
    while (T->Right)
        T = T->Right;
    return T;
}

SearchTree Insert(ElementType X, SearchTree T)
{
    if (T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!");
        T->Element = X;
        T->Left = T->Right = NULL;
    }
    else if (X < T->Element)
    {
        T = Insert(X, T->Left);
    }
    else if (X > T->Element)
    {
        T = Insert(X, T->Right);
    }
    else
    {
        return T;
    }
}

SearchTree Delete(ElementType X, SearchTree T)
{
    Position TmpCell;
    if (T == NULL)
        return NULL;
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
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

SearchTree MakeRandomTree1(int Lower, int Upper){
    SearchTree T;
    int RandomValue;

    T = NULL;
    if(Lower <= Upper){
        T = malloc(sizeof(struct TreeNode));
        if(T != NULL){
            T->Element = RandomValue = RandInt(Lower, Upper);
            T->Left = MakeRandomTree1(Lower, RandomValue - 1);
            T->Right = MakeRandomTree1(RandomValue + 1, Upper);
        }
        else
        FatalError("Out of space!!!");
    }   
    return T;
}

SearchTree MakeRandomTree(int N){
    return MakeRandomTree1(1, N);
}