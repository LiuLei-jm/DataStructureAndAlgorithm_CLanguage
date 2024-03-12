#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "GraphAdjacencyList.h"

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
    AdjListNode *node = (AdjListNode *)malloc(sizeof(AdjListNode));
    node->vertex = vet;
    node->next = head->next;
    head->next = node;
}

void RemoveEdgeHelper(AdjListNode *head, Vertex *vet)
{
    AdjListNode *pre = head;
    AdjListNode *cur = head->next;
    while (cur != NULL && cur->vertex != vet)
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
    GraphAdjList *G = (GraphAdjList *)malloc(sizeof(struct graphAdjList));
    if (!G)
    {
        FatalError("Out of space!!!");
    }
    G->size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        G->heads[i] = NULL;
    }
    return G;
}

void DelGraphAdjList(GraphAdjList *G)
{
    for (int i = 0; i < G->size; i++)
    {
        AdjListNode *cur = G->heads[i];
        while (cur != NULL)
        {
            AdjListNode *next = cur->next;
            if (cur != G->heads[i])
            {
                free(cur);
            }
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
        {
            return G->heads[i];
        }
    }
    return NULL;
}

void AddEdge(GraphAdjList *G, Vertex *vet1, Vertex *vet2)
{
    AdjListNode *head1 = FindNode(G, vet1);
    AdjListNode *head2 = FindNode(G, vet2);
    assert(head1 != NULL && head2 != NULL && head1 != head2);
    AddEdgeHelper(head1, vet2);
    AddEdgeHelper(head2, vet1);
}

void RemoveEdge(GraphAdjList *G, Vertex *vet1, Vertex *vet2)
{
    AdjListNode *head1 = FindNode(G, vet1);
    AdjListNode *head2 = FindNode(G, vet2);
    assert(head1 != NULL && head2 != NULL);
    RemoveEdgeHelper(head1, head2->vertex);
    RemoveEdgeHelper(head2, head1->vertex);
}

void AddVertex(GraphAdjList *G, Vertex *vet)
{
    assert(G != NULL && G->size < MAX_SIZE);
    AdjListNode *head = (AdjListNode *)malloc(sizeof(AdjListNode));
    head->vertex = vet;
    head->next = NULL;
    G->heads[G->size++] = head;
}

void RemoveVertex(GraphAdjList *G, Vertex *vet)
{
    AdjListNode *node = FindNode(G, vet);
    assert(node != NULL);
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

void FatalError(char *S)
{
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}