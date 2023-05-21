#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

typedef struct QueueNode
{
    TreeNode * treeNode;
    struct QueueNode *pre;
    struct QueueNode *next;
} QueueNode;

void createTree(TreeNode **T, char *string, int *index)
{
    char ch ;
    ch = string[*index];
    *index += 1;
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data = ch;
        createTree(&((*T)->lchild), string, index);
        createTree(&((*T)->rchild), string, index);
    }
}

void preOrder(TreeNode *T)
{
    if (T == NULL)
        return;
    else
    {
        printf("%c ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

QueueNode* initQueue(){
    QueueNode* Q =(QueueNode*)malloc(sizeof(QueueNode));
    Q->treeNode = NULL;
    Q->pre = Q;
    Q->next = Q;
    return Q;
}

void enQueue(QueueNode* Q, TreeNode* T){
    if(T == NULL) return ;
    else {
        QueueNode* qNode = (QueueNode*)malloc(sizeof(QueueNode));
        qNode->treeNode = T;
        qNode->pre = Q->pre;
        qNode->next = Q;
        Q->pre->next = qNode;
        Q->pre = qNode;
    }
}

int isEmpty(QueueNode* Q){
    if(Q->next == Q) return 1;
    else return 0;
}

TreeNode* outQueue(QueueNode* Q){
    if(isEmpty(Q))return NULL;
    QueueNode* rNode = Q->next;
    rNode->next->pre = Q;
    Q->next = rNode->next;
    TreeNode* temp = rNode->treeNode;
    free(rNode);
    return temp;
}

void levelTraversal(QueueNode* Q, TreeNode* T){
    enQueue(Q, T);
    while(!isEmpty(Q)){
        TreeNode* temp = outQueue(Q);
        printf("%c ", temp->data);
        if(temp->lchild){
            enQueue(Q,temp->lchild);
        }
        if(temp->rchild){
            enQueue(Q,temp->rchild);
        }
    }
}

int main()
{
    TreeNode *Tree;
    int index = 0;
    createTree(&Tree, "ABD##E##CF##G##", &index);
    QueueNode* Q = initQueue();
    preOrder(Tree);
    putchar('\n');
    levelTraversal(Q, Tree);
    putchar('\n');
    system("pause");
    return 0;
}