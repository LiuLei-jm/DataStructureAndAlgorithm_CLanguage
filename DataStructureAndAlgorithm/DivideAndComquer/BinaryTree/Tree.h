#ifndef _Tree_H


typedef int ElementType;

struct treeNode;
typedef struct treeNode *TreeNode;

struct queue;
typedef struct queue *Queue;

void LevelOrderTraverse(TreeNode  root);

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(TreeNode T, Queue Q);
TreeNode Front (Queue Q);
void DeQueue(Queue Q);
TreeNode FrontAndDeQueue(Queue Q);
void FatalError(char *S);
void Error(char*S);

#endif