#ifndef _Queue_h

typedef int ElementType;
struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType Front (Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);
void FatalError(char *S);
void Error(char*S);
void PrintQueue(Queue Q);

#endif