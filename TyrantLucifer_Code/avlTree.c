#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    int height;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
} TreeNode;

int getHeight(TreeNode *node)
{
    return node ? node->height : 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void rrRotation(TreeNode *node, TreeNode **root)
{
    TreeNode *temp = node->rChild;
    node->rChild = temp->lChild;
    temp->lChild = node;
    node->height = max(getHeight(node->lChild), getHeight(node->rChild)) + 1;
    temp->height = max(getHeight(temp->lChild), getHeight(temp->rChild)) + 1;
    *root = temp;
}

void llRotation(TreeNode *node, TreeNode **root)
{
    TreeNode *temp = node->lChild;
    node->lChild = temp->rChild;
    temp->rChild = node;
    node->height = max(getHeight(node->lChild), getHeight(node->rChild)) + 1;
    temp->height = max(getHeight(temp->lChild), getHeight(temp->rChild)) + 1;
    *root = temp;
}

void avlInsert(TreeNode **T, int data)
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lChild = NULL;
        (*T)->rChild = NULL;
    }
    else if (data < (*T)->data)
    {
        avlInsert(&(*T)->lChild, data);
        int lHeight = getHeight((*T)->lChild);
        int rHeight = getHeight((*T)->rChild);
        if (lHeight - rHeight == 2)
        {
            if (data < (*T)->lChild->data)
            {
                llRotation(*T, T);
            }
            else
            {
                rrRotation((*T)->lChild, &(*T)->lChild);
                llRotation(*T, T);
            }
        }
    }
    else if (data > (*T)->data)
    {
        avlInsert(&(*T)->rChild, data);
        int lHeight = getHeight((*T)->lChild);
        int rHeight = getHeight((*T)->rChild);
        if (rHeight - lHeight == 2)
        {
            if (data > (*T)->rChild->data)
            {
                rrRotation(*T, T);
            }
            else
            {
                llRotation((*T)->rChild, &(*T)->rChild);
                rrRotation(*T, T);
            }
        }
    }
    (*T)->height = max(getHeight((*T)->lChild), getHeight((*T)->rChild)) + 1;
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
    int nums[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    putchar('\n');

    system("pause");
    return 0;
}