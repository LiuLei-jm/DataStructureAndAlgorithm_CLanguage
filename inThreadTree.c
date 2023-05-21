#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lChild;
    struct TreeNode *rChild;
    int lTag ;
    int rTag;
} TreeNode;

void createTree(TreeNode **T, char *data, int *index)
{
    char ch = data[(*index)];
    *index += 1;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        (*T)->lTag = 0;
        (*T)->rTag = 0;
        createTree(&((*T)->lChild), data, index);
        createTree(&((*T)->rChild), data, index);
    }
}

void inThreadTree(TreeNode*T, TreeNode** pre){
    if(T){
        inThreadTree(T->lChild, pre);
        if(T->lChild == NULL){
            T->lTag = 1;
            T->lChild = *pre;
        }
        if(*pre != NULL && (*pre)->rChild == NULL){
            (*pre)->rTag = 1;
            (*pre)->rChild  = T;
        }
        *pre = T;
        inThreadTree(T->rChild, pre);
    }
}

TreeNode* getFirst(TreeNode*T){
    while(T->lTag == 0){
        T=T->lChild;
    }
    return T;
}

TreeNode* getNext(TreeNode*T){
    if(T->rTag == 1){
        return T->rChild;
    }
    else{
        return getFirst(T->rChild);
    }
}

int main()
{
    TreeNode *T;
    TreeNode*pre = NULL;
    int index = 0;
    createTree(&T, "ABD##E##CF##G##", &index);
    
    inThreadTree(T, &pre);
    pre->rTag = 1;
    pre->rChild = NULL;
    for(TreeNode* node = getFirst(T); node != NULL; node = getNext(node)){
        printf("%c ", node->data);
    }
    putchar('\n');

    system("pause");
    return 0;
}
