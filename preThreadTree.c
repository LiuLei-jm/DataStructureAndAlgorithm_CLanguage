#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
    int lTag;
    int rTag;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index)
{
    char ch = data[(*index)];
    (*index)++;
    if (ch == '#')
    {
        (*T) = NULL;
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->lTag = 0;
        (*T)->rTag = 0;
        createTree(&((*T)->lChild), data, index);
        createTree(&((*T)->rChild), data, index);
    }
}

void preThreadTree(TreeNode *T, TreeNode **pre)
{
    if (T)
    {
        if (T->lChild == NULL )
        {
            T->lTag = 1;
            T->lChild = *pre;
        }
        if (*pre != NULL && (*pre)->rChild == NULL)
        {
            (*pre)->rTag = 1;
            (*pre)->rChild = T;
        }
        *pre = T;
        if (T->lTag == 0)
            preThreadTree(T->lChild, pre);
        preThreadTree(T->rChild, pre);
    }
}

TreeNode* getNext(TreeNode* node){
    if(node->lTag == 1 || node ->rTag == 1)
    return node->rChild;
    else
    return node->lChild;
}

int main()
{
    TreeNode *tree;
    TreeNode *pre= NULL;
    int index = 0;
    // char *str = "ABD##E##CF##G##";
    char *str = "A#BC#D##E##";
    createTree(&tree, str, &index);
    preThreadTree(tree, &pre);
    pre->rTag = 1;
    pre->rChild = NULL;
    for(TreeNode* node = tree; node != NULL; node = getNext(node)){
        printf("%c ", node->data);
    }
    putchar('\n');

    system("pause");
    return 0;
}