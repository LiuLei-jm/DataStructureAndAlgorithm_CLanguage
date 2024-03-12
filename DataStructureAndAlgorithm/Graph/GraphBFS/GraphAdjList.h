#ifndef _GraphAdjList_H

typedef int Vertex;
struct adjListNode;
struct graphAdjList;
typedef struct adjListNode AdjListNode;
typedef struct graphAdjList GraphAdjList;

void AddEdgeHelper(AdjListNode* head, Vertex *vet);
void RemoveEdgeHelper(AdjListNode*head, Vertex *vet);
GraphAdjList* NewGraphAdjList();
void DelGraphAdjList(GraphAdjList *G);
AdjListNode*FindNode(GraphAdjList*G, Vertex *vet);
void AddEdge(GraphAdjList *G, Vertex* vet1, Vertex* vet2);
void RemoveEdge(GraphAdjList*G, Vertex* vet1, Vertex* vet2);
void AddVertex(GraphAdjList *G, Vertex* vet);
void RemoveVertex(GraphAdjList*G, Vertex *vet);
void FatalError(char *S);

#endif