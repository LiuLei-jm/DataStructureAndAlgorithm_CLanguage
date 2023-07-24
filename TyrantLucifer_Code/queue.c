#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initQueue()
{
    Node *Q = (Node *)malloc(sizeof(Node));
    Q->data = 0;
    Q->next = NULL;
    return Q;
}

void enQueue(Node *Q, int data)
{
    Node *current = Q;
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    while (current->next)
    {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    Q->data++;
}

int outQueue(Node *Q)
{
    if (isEmpty(Q) == 1)
        return -1;
    else
    {
        Node *node = Q->next;
        int data = node->data;
        Q->next = node->next;
        free(node);
        Q->data--;
        return data;
    }
}

isEmpty(Node *Q)
{
    return (Q->data == 0) ? 1 : 0;
}

void printQueue(Node *Q)
{
    Node *current = Q->next;
    while (current)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("Totel:%d\n", Q->data);
}

int main()
{
    int data;
    Node *Q = initQueue();
    enQueue(Q, 1);
    enQueue(Q, 2);
    enQueue(Q, 3);
    enQueue(Q, 4);
    enQueue(Q, 5);

    data = outQueue(Q);
    printf("出队：%d\n", data);
    data = outQueue(Q);
    printf("出队：%d\n", data);

    printQueue(Q);

    system("pause");
    return 0;
}