#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
} TreeNode;

TreeNode *bstSearch(TreeNode *T, int data)
{
    if (T)
    {
        if (T->data == data)
        {
            return T;
        }
        else if (data < T->data)
        {
            return bstSearch(T->lChild, data);
        }
        else
        {
            return bstSearch(T->rChild, data);
        }
    }
    else
    {
        return NULL;
    }
}

void bstInsert(TreeNode **T, int data)
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->lChild = NULL;
        (*T)->rChild = NULL;
    }
    else if (data == (*T)->data)
    {
        return;
    }
    else if (data < (*T)->data)
    {
        bstInsert(&(*T)->lChild, data);
    }
    else
    {
        bstInsert(&(*T)->rChild, data);
    }
}

void preOrder(TreeNode *T)
{
    if (T)
    {
        printf("%d ", T->data);
        preOrder(T->lChild);
        preOrder(T->rChild);
    }
}

int main()
{
    TreeNode *T = NULL;
    int nums[6] = {4, 5, 19, 23, 2, 8};
    for (int i = 0; i < 6; i++)
    {
        bstInsert(&T, nums[i]);
    }

    preOrder(T);
    putchar('\n');

    system("pause");
    return 0;
}