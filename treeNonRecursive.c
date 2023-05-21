#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef struct StackNode
{
    TreeNode *treeNode;
    struct StackNode *next;
} StackNode;

TreeNode *createTree(TreeNode **T, char *data, int *index)
{
    char ch = data[(*index)];
    (*index) += 1;
    if (ch != '#')
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&((*T)->lchild), data, index);
        createTree(&((*T)->rchild), data, index);
    }
    else
    {
        *T = NULL;
    }
}

StackNode *initStack()
{
    StackNode *S = (StackNode *)malloc(sizeof(StackNode));
    S->treeNode = NULL;
    S->next = NULL;
    return S;
}

void push(StackNode *S, TreeNode *T)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));
    node->treeNode = T;
    node->next = S->next;
    S->next = node;
}

TreeNode *pop(StackNode *S)
{
    if (isEmpty(S))
        return NULL;
    TreeNode *node = S->next->treeNode;
    StackNode *temp = S->next;
    S->next = S->next->next;
    free(temp);
    return node;
}

void preOrder(TreeNode* T){
    StackNode* S = initStack();
    TreeNode* current = T;
    TreeNode* temp;
    while(current || !isEmpty(S)){
        if(current){
        printf("%c ", current->data);
        push(S, current);
        current = current->lchild;
        }
        else{
            temp = pop(S);
            current = temp->rchild;
        }
    }
}

void inOrder(TreeNode* T){
    StackNode* S = initStack();
    TreeNode*current = T;
    while(current || !isEmpty(S)){
        if(current){
            push(S, current);
            current = current->lchild;
        }
        else{
            current = pop(S);
            printf("%c ", current->data);
            current = current->rchild;
        }
    }
}

int isEmpty(StackNode *S)
{
    return S->next == NULL ? 1 : 0;
}

int main()
{
    TreeNode *T;
    int index = 0;
    createTree(&T, "ABD##E##CF##G##", &index);
    printf("PreOrder:");
    preOrder(T);
    putchar('\n');
    
    printf("InOrder:");
    inOrder(T);
    putchar('\n');


system("pause");
    return 0;
}