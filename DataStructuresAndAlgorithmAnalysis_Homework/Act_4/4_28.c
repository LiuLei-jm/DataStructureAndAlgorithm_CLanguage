#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *BinaryTree;
typedef int ElementType;

BinaryTree MakeEmpty(BinaryTree T);
Position Find(ElementType X, BinaryTree T);
Position FindMin(BinaryTree T);
Position FindMax(BinaryTree T);
BinaryTree Insert(ElementType X, BinaryTree T);
BinaryTree Delete(ElementType X, BinaryTree T);
ElementType Retrieve(Position P);
void FatalError(char *S);

struct TreeNode
{
    ElementType Element;
    BinaryTree Left;
    BinaryTree Right;
};

int CountNodes(BinaryTree T);
int CountLeaves(BinaryTree T);
int CountFull(BinaryTree T);

int main()
{
    BinaryTree tree = NULL;
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

    int countNodes = CountNodes(tree);
    int countLeaves = CountLeaves(tree);
    int countFull = CountFull(tree);

    printf("CountNodes: %d, CountLeaves: %d, CountFull: %d\n",countNodes, countLeaves, countFull);

    system("Pause");
    return 0;
}

int CountNodes(BinaryTree T)
{
    if (T == NULL)
        return 0;
    return 1 + CountNodes(T->Left) + CountNodes(T->Right);
}

int CountLeaves(BinaryTree T)
{
    if (T == NULL)
        return 0;
    else if (T->Left == NULL && T->Right == NULL)
        return 1;
    return CountLeaves(T->Left) + CountLeaves(T->Right);
}

int CountFull(BinaryTree T)
{
    if (T == NULL)
        return 0;
    return (T->Left != NULL && T->Right != NULL) + CountFull(T->Left) + CountFull(T->Right);
}

BinaryTree MakeEmpty(BinaryTree T)
{
    if (T != NULL)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, BinaryTree T)
{
    if (T == NULL)
    {
        return NULL;
    }
    else if (X < T->Element)
        return Find(X, T->Left);
    else if (X > T->Element)
        return Find(X, T->Right);
    else
        return T;
}

Position FindMin(BinaryTree T)
{
    if (T == NULL)
        return NULL;
    while (T->Left != NULL)
        T = T->Left;
    return T;
}

Position FindMax(BinaryTree T)
{
    if (T == NULL)
        return NULL;
    else if (T->Right == NULL)
        return T;
    else
        return FindMax(T->Right);
}

BinaryTree Insert(ElementType X, BinaryTree T)
{
    if (T == NULL)
    {
        T = (BinaryTree)malloc(sizeof(struct TreeNode));
        if (T == NULL)
            FatalError("Out of space!!!");
        else
        {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else if (X < T->Element)
    {
        T->Left = Insert(X, T->Left);
    }
    else if (X > T->Element)
    {
        T->Right = Insert(X, T->Right);
    }
    return T;
}

BinaryTree Delete(ElementType X, BinaryTree T)
{
    Position TmpCell;
    if (T == NULL)
        FatalError("Element not found");
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right)
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