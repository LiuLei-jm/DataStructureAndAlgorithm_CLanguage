#ifndef _LeftHeap_H

typedef int ElementType;

struct TreeNode;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);
void Destroy(PriorityQueue H);

#define Insert(X, H) (H = Insert1((X), H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);
void Error(char* S);
void FatalError(char* S);

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void EnQueue(PriorityQueue P, Queue Q);
PriorityQueue FrontQueue(Queue Q);
void DeQueue(Queue Q);
PriorityQueue FrontAndDeQueue(Queue Q);
static int SuccQueue(int Value, Queue Q);
void PrintSequence(PriorityQueue P);

#endif