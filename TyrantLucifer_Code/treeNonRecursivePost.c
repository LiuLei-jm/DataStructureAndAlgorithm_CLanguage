#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
    int flag;
} TreeNode;

typedef struct StackNode
{
    TreeNode *treeNode;
    struct StackNode *next;
} StackNode;

TreeNode *createTree(TreeNode **T, char *data, int *index)
{
    char ch = data[(*index)];
    *index += 1;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->flag = 0;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
}

StackNode *initStack()
{
    StackNode *qNode = (StackNode *)malloc(sizeof(StackNode));
    qNode->treeNode = NULL;
    qNode->next = NULL;
    return qNode;
}

void push(StackNode *S, TreeNode *T)
{
    StackNode *sNode = (StackNode *)malloc(sizeof(StackNode));
    sNode->treeNode = T;
    sNode->next = S->next;
    S->next = sNode;
}

int isEmpty(StackNode *S)
{
    return S->next == NULL ? 1 : 0;
}

TreeNode *pop(StackNode *S)
{
    if (isEmpty(S))
        return NULL;
    StackNode *sNode = S->next;
    S->next = sNode->next;
    TreeNode *treeNode = sNode->treeNode;
    free(sNode);
    return treeNode;
}

TreeNode *getTop(StackNode *S)
{
    if (isEmpty(S))
        return NULL;
    return S->next->treeNode;
}

void postOrder(TreeNode *T)
{
    TreeNode *current = T;
    StackNode *S = initStack();
    while (current || !isEmpty(S))
    {
        if (current && current->flag == 0)
        {
            push(S, current);
            current = current->lchild;
        }
        else
        {
            TreeNode* top = getTop(S);
            if (top->rchild && top->rchild->flag == 0)
            {
                top = top->rchild;
                push(S, top);
                current = top->lchild;
            }
            else
            {
                top = pop(S);
                printf("%c ", top->data);
                top->flag = 1;
            }
        }
    }
}

int main()
{
    TreeNode *T;
    int index = 0;
    createTree(&T, "ABD##E##CF##G##", &index);
    postOrder(T);

    system("pause");
    return 0;
}