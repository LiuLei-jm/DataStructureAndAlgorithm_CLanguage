#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

struct treeNode
{
    ElementType val;
    TreeNode left;
    TreeNode right;
};

TreeNode MakeEmpty(ElementType E)
{
    TreeNode T = malloc(sizeof(struct treeNode));
    if (T == NULL)
        FatalError("Out of space!!!");
    T->val = E;
    T->left = NULL;
    T->right = NULL;
    return T;
}

ElementType Retrieve(TreeNode T)
{
    return T->val;
}

void FatalError(char *S)
{
    fprintf(stderr, "%d\n", S);
    exit(EXIT_FAILURE);
}