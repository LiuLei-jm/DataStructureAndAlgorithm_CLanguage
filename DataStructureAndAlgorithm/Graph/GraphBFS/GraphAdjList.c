#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjList.h"
#include "Queue.c"

#define MAX_SIZE 10

struct adjListNode
{
    Vertex *vertex;
    AdjListNode *next;
};

struct graphAdjList
{
    AdjListNode *heads[MAX_SIZE];
    int size;
};

void AddEdgeHelper(AdjListNode *head, Vertex *vet)
{
    AdjListNode *node = malloc(sizeof(AdjListNode));
    if (node == NULL)
        FatalError("Out of space!!!");
    node->vertex = vet;
    node->next = head->next;
    head->next = node;
}

void RemoveEdgeHelper(AdjListNode *head, Vertex *vet)
{
    AdjListNode *pre = head;
    AdjListNode *cur = head->next;
    while (cur && cur->vertex != vet)
    {
        pre = cur;
        cur = cur->next;
    }
    if (cur == NULL)
        return;
    pre->next = cur->next;
    free(cur);
}

GraphAdjList *NewGraphAdjList()
{
    GraphAdjList *G = malloc(sizeof(GraphAdjList));
    if (G == NULL)
        FatalError("Out of space!!!");
    G->size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        G->heads[i] = NULL;
    }
    return G;
}

void DelGraphAdjList(GraphAdjList *G)
{
    AdjListNode *cur;
    AdjListNode *next;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cur = G->heads[i]->next;
        while (cur)
        {
            next = cur->next;
            free(cur);
            cur = next;
        }
        free(G->heads[i]->vertex);
        free(G->heads[i]);
    }
    free(G);
}

AdjListNode *FindNode(GraphAdjList *G, Vertex *vet)
{
    for (int i = 0; i < G->size; i++)
    {
        if (G->heads[i]->vertex == vet)
            return G->heads[i];
    }
    return NULL;
}

void AddEdge(GraphAdjList *G, Vertex *vet1, Vertex *vet2)
{
    AdjListNode *head1 = FindNode(G, vet1);
    if (head1 == NULL)
        FatalError("Vertex not find");
    AdjListNode *head2 = FindNode(G, vet2);
    if (head2 == NULL)
        FatalError("Vertex not find");
    if (head1 == head2)
        FatalError("The same vertices cannot produce edges");
    AddEdgeHelper(head1, vet2);
    AddEdgeHelper(head2, vet1);
}

void RemoveEdge(GraphAdjList *G, Vertex *vet1, Vertex *vet2)
{
    AdjListNode *head1 = FindNode(G, vet1);
    if (head1 == NULL)
        FatalError("Vertex not find");
    AdjListNode *head2 = FindNode(G, vet2);
    if (head2 == NULL)
        FatalError("Vertex not find");
    RemoveEdgeHelper(head1, head2->vertex);
    RemoveEdgeHelper(head2, head1->vertex);
}

void AddVertex(GraphAdjList *G, Vertex *vet)
{
    if (G == NULL || G->size > MAX_SIZE)
        FatalError("Graph not created or out of bounds");
    AdjListNode *head = malloc(sizeof(AdjListNode));
    if (head == NULL)
        FatalError("Out of space!!!");
    head->vertex = vet;
    head->next = NULL;
    G->heads[G->size++] = head;
}

void RemoveVertex(GraphAdjList *G, Vertex *vet)
{
    AdjListNode *node = FindNode(G, vet);
    if (node == NULL)
        FatalError("Out of space!!!");
    AdjListNode *cur = node->next, *pre = NULL;
    while (cur)
    {
        pre = cur;
        cur = cur->next;
        free(pre);
    }
    node->next = NULL;
    for (int i = 0; i < G->size; i++)
    {
        cur = G->heads[i];
        pre = NULL;
        while (cur)
        {
            pre = cur;
            cur = cur->next;
            if (cur && cur->vertex == vet)
            {
                pre->next = cur->next;
                free(cur);
                break;
            }
        }
    }
    int i;
    for (i = 0; i < G->size; i++)
    {
        if (G->heads[i] == node)
        {
            break;
        }
    }
    for (int j = i; j < G->size - 1; j++)
    {
        G->heads[j] = G->heads[j + 1];
    }
    G->size--;
}

void FatalError(char *S)
{
    fprintf(stderr, "%s\n", S);
}

void GraphBFS(GraphAdjList *G, Vertex *startVet, Vertex **res, Vertex **visited)
{
    int i, j;
    i = j = 0;
    Queue *Q = NewQueue();
    EnQueue(Q, startVet);
    visited[j++] = startVet;
    while (!IsEmpty(Q))
    {
        Vertex *vet = DeQueue(Q);
        res[i++] = vet;
        AdjListNode *node = FindNode(G, vet);
        while (node != NULL)
        {
            if (!IsVisited(visited, j, node->vertex))
            {
                EnQueue(Q, node->vertex);
                visited[j++] = node->vertex;
            }
            node = node->next;
        }
    }
    free(Q);
}

void PrintGraph(GraphAdjList *G, int size)
{
    AdjListNode *cur;
    for (int i = 0; i < G->size; i++)
    {
        printf("Vertex%d: %d -- ",(i+1), *(G->heads[i]->vertex));
        cur = G->heads[i]->next;
        while (cur)
        {
            printf("%d ", *(cur->vertex));
            cur = cur->next;
        }
        putchar('\n');
    }
    putchar('\n');
}
