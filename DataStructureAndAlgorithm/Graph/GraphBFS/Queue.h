#ifndef _Queue_H

struct queue;
typedef struct queue Queue;
typedef int Vertex;

Queue* NewQueue();
int IsEmpty(Queue *Q);
void EnQueue(Queue*Q, Vertex *vet);
Vertex* DeQueue(Queue *Q);
int IsVisited(Vertex** visited, int size, Vertex *vet);

#endif