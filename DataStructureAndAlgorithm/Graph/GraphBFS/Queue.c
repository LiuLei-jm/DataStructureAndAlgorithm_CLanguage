#include <stdlib.h>
#include "Queue.h"

#define MAX_SIZE 10

struct queue
{
    Vertex *vertices[MAX_SIZE];
    int front, rear, size;
};

Queue *NewQueue()
{
    Queue *Q = malloc(sizeof(Queue));
    Q->front = Q->rear = Q->size = 0;
    return Q;
}

int IsEmpty(Queue *Q)
{
    return Q->size == 0;
}

void EnQueue(Queue *Q, Vertex *vet)
{
    Q->vertices[Q->rear] = vet;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    Q->size++;
}

Vertex *DeQueue(Queue *Q)
{
    Vertex *vet = Q->vertices[Q->front];
    Q->front = (Q->front + 1) % MAX_SIZE;
    Q->size--;
    return vet;
}

int IsVisited(Vertex **visited, int size, Vertex *vet)
{
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == vet)
            return 1;
    }
    return 0;
}

void FatalError(char *S)
{
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}
