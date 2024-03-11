#ifndef _GraphAdjacencyList_H

struct adjacencyListNode;
typedef struct adjacencyListNode AdjListNode;
struct graphAdjlist;
typedef struct graphAdjList GraphAdjList;

void AddEdgeHelper(AdjListNode* head, Vertex *vet);
void RemoveEdgeHelper(AdjListNode*head, Vertex *vet);
GraphAdjList* NewGraphAdjList();
void DelGraphAdjList(GraphAdjList *G);
AdjListNode*FindNode(GraphAdjList*G, Vertex *vet);
void AddEdge(GraphAdjList *G, Vertext* vet1, Vertext* vet2);
void RemoveEdge(GraphAdjList*G, Vertex* vet1, Vertex* vet2);
void AddVertex(GraphAdjList *G, Vertex* vet);
void RemoveVertex(GraphAdjList*G, Vertex *vet);
void PrintGraph(GraphAdjList*G, int size);
void FatalError(char *S);

#endif