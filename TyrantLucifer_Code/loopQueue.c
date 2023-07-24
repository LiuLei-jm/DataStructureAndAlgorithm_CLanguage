#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 7

typedef struct Queue{
    int rear;
    int front;
    int data[MAXSIZE];
}Queue;

Queue* initQueue(){
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

void enQueue(Queue* Q, int data){
    if(!isFull(Q)){
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    }
}

int outQueue(Queue* Q){
    if(!isEmpty(Q)){
        int data = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXSIZE;
        return data;
    }
    else{
        return -1;
    }
}

int isEmpty(Queue* Q){
    return (Q->front == Q->rear) ? 1 : 0;
}

int isFull(Queue* Q){
    return (Q->front == (Q->rear + 1) % MAXSIZE) ? 1 : 0;
}

void printQueue(Queue* Q){
    int i = Q->front;
    int j = Q->rear;
    for(i; i < j; i = (i + 1) % MAXSIZE)
    printf("%d->", Q->data[i]);
    printf("end\n");
}

int main(){
    Queue* Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    enQueue(Q, 5);
    enQueue(Q, 6);
    enQueue(Q, 7);
    
    printf("鍑洪槦锛�%d\n", outQueue(Q));
    printf("鍑洪槦锛�%d\n", outQueue(Q));

    printQueue(Q);

    system("pause");
    return 0;
}