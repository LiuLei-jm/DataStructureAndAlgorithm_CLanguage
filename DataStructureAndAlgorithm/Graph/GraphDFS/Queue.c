#include "Queue.h"

#define MAX_SIZE 10

struct queue{
    Vertex * vertices[MAX_SIZE];
    int size, front, rear;
};

Queue* NewQueue(){
    Queue *Q = malloc(sizeof(Queue));
    if(Q == NULL) FatalError("Out of space!!!");
    Q->size = Q->front = Q->rear = 0;   
    return Q;
}

int IsEmpty(Queue *Q){
    return Q->size == 0;   
}

void EnQueue(Queue*Q, Vertex *vet){
    Q->vertices[Q->rear] = vet;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    Q->size++;
}

Vertex* DeQueue(Queue *Q){
    Vertex* vet = Q->vertices[Q->front];
    Q->front = (Q->front+ 1) % MAX_SIZE;
    Q->size--; 
}

int IsVisited(Vertex** res, int size, Vertex *vet){
    for(int i = 0; i < size; i++){
        if(res[i] == vet){
            return 1;
        }
    }
    return 0;
}