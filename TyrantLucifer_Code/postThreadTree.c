#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode* parent;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
    int lTag;
    int rTag;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index, TreeNode* parent)
{
    char ch = data[(*index)];
    (*index)++;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->lTag = 0;
        (*T)->rTag = 0;
        (*T)->parent = parent;
        createTree(&((*T)->lChild), data, index, *T);
        createTree(&((*T)->rChild), data, index, *T);
    }
}

void postThreadTree(TreeNode *T, TreeNode **pre)
{
    if (T)
    {
        postThreadTree(T->lChild, pre);
        postThreadTree(T->rChild, pre);
        if (T->lChild == NULL)
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
    }
}

TreeNode *getFirst(TreeNode *T)
{
    while (T->lTag == 0)
    {
        T = T->lChild;
    }
    if(T->rTag == 0){
        T = getFirst(T->rChild);
    }
    else{
        return T;
    }
}

TreeNode* getNext(TreeNode*node){
    if(node->rTag == 1){
        return node->rChild;
    }
    else{
        if(node->parent != NULL && node->parent->lChild == node && node->parent->rChild != NULL){
            return getFirst(node->parent->rChild);
        }
        else{
            return node->parent;
        }
    }
}

TreeNode* getNext (TreeNode*T);

int main()
{
    TreeNode *T;
    TreeNode *pre = NULL;
    int index = 0;
    char *data = "ABD##E##CF##G##";
    createTree(&T, data, &index, NULL);
    postThreadTree(T, &pre);

    for(TreeNode* node = getFirst(T);node != NULL; node = getNext(node)){
        printf("%c ", node->data);
    }
    putchar('\n');
    system("pause");
    return 0;
}