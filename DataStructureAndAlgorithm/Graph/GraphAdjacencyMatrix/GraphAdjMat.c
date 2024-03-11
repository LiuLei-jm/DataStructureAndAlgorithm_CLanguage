#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjMat.h"
#define MAX_SIZE 10

struct graph
{
    int vertices[MAX_SIZE];
    int adjMat[MAX_SIZE][MAX_SIZE];
    int size;
};

GraphAdjMat *NewGraphAdjMat()
{
    GraphAdjMat *Graph = (GraphAdjMat *)malloc(sizeof(GraphAdjMat));
    if (Graph == NULL)
        FatalError("Out of space!");
    Graph->size = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            Graph->adjMat[i][j] = 0;
        }
    }
    return Graph;
}

void DelGraphAdjMat(GraphAdjMat *G)
{
    free(G);
}

void AddVertex(GraphAdjMat *G, int val)
{
    if (G->size == MAX_SIZE)
    {
        FatalError("The number of vertices in the graph has reached its maximum");
    }
    int n = G->size;
    G->vertices[n] = val;
    for (int i = 0; i <= n; i++)
    {
        G->adjMat[n][i] = G->adjMat[i][n] = 0;
    }
    G->size++;
}

void RemoveVertex(GraphAdjMat *G, int index)
{
    if (index < 0 || index >= G->size)
    {
        FatalError("The vertex index is out of baounds");
    }
    for (int i = index; i < G->size - 1; i++)
    {
        G->vertices[i] = G->vertices[i + 1];
    }
    for (int i = index; i < G->size - 1; i++)
    {
        for (int j = 0; j < G->size; j++)
        {
            G->adjMat[i][j] = G->adjMat[i + 1][j];
        }
    }
    for (int i = 0; i < G->size; i++)
    {
        for (int j = index; j < G->size - 1; j++)
        {
            G->adjMat[i][j] = G->adjMat[i][j + 1];
        }
    }
    G->size--;
}

void AddEdge(GraphAdjMat *G, int i, int j)
{
    if (i < 0 || j < 0 || i >= G->size || j >= G->size)
    {
        FatalError("Edge indexes are out of bounds or equal");
    }
    G->adjMat[i][j] = 1;
    G->adjMat[j][i] = 1;
}

void RemoveEdge(GraphAdjMat *G, int i, int j)
{
    if (i < 0 || j < 0 || i >= G->size || j >= G->size)
    {
        FatalError("Edge indexes are out of bounds or equal");
    }
    G->adjMat[i][j] = 0;
    G->adjMat[j][i] = 0;
}

void PrintGraphAdjMat(GraphAdjMat *G)
{
    printf("Vertex list:");
    PrintArray(G->vertices, G->size);
    printf("Adjacency matrix: \n");
    for (int i = 0; i < G->size; i++)
    {
        PrintArray(G->adjMat[i], G->size);
    }
    putchar('\n');
}

void FatalError(char *S)
{
    fprintf(stderr, "%s\n", S);
    exit(EXIT_FAILURE);
}

void PrintArray(int *arr, int num){
    for(int i = 0; i < num; i++){
        printf("%d ",arr[i]);
    }
    putchar('\n');
}