#include <stdlib.h>
#include "Tree.h"

#define MinSize 5

struct treeNode{
    int val;
    TreeNode left;
    TreeNode right;
};

struct queue{
    TreeNode* array;
    int capacity;
    int size;
    int front;
    int rear;
};

void LevelOrderTraverse(TreeNode  root){
    TreeNode Tmp;
    
    Queue Q = CreateQueue(20);
    EnQueue(root, Q); 
    while(!IsEmpty(Q)){
        Tmp = FrontAndDeQueue(Q);
        printf("%d ", Tmp->val);
        if(Tmp->left != NULL){
            EnQueue(Tmp->left, Q);
        }
        if(Tmp->right != NULL){
            EnQueue(Tmp->right, Q);
        }
    }
    putchar('\n');
    DisposeQueue(Q);
}

int IsEmpty(Queue Q){
    return Q->size == 0;   
}

int IsFull(Queue Q){
    return Q->size == Q->capacity;   
}

Queue CreateQueue(int MaxElements){
    if(MaxElements < MinSize) FatalError("Queue is too small.");
    Queue Q = malloc(sizeof(Queue));
    if(Q == NULL) FatalError("Out of space!!!");
    Q->array = malloc(sizeof(TreeNode)*MaxElements);
    if(Q->array == NULL) FatalError("Out of space!!!");
    Q->capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}

void DisposeQueue(Queue Q){
    MakeEmpty(Q);
    free(Q->array);   
    free(Q);
}

void MakeEmpty(Queue Q){
    Q->size = 0;   
    Q->front = 1;
    Q->rear = 0;
}

void EnQueue(TreeNode T, Queue Q){
    if(IsFull(Q)) FatalError("Queue is full");
    else{
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->array[Q->rear] = T;
        Q->size++;
    }
}

TreeNode Front (Queue Q){
    return Q->array[Q->front];   
}

void DeQueue(Queue Q){
    if(IsEmpty(Q)) FatalError("Queue is empty");
    else{
        Q->front = (Q->front + 1) % Q->capacity;
        Q->size--;
    }
}

TreeNode FrontAndDeQueue(Queue Q){
    TreeNode tmp = Q->array[Q->front];
    DeQueue(Q);
    return tmp;
}

void FatalError(char *S){
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}

void Error(char*S){
    fputs(S, stderr);
}