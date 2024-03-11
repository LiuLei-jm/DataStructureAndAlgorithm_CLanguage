#ifndef _GraphAdjMat_H

struct graph;
typedef struct graph GraphAdjMat;

GraphAdjMat *NewGraphAdjMat();
void DelGraphAdjMat(GraphAdjMat *G);
void AddVertex(GraphAdjMat *G, int val);
void RemoveVertex(GraphAdjMat *G, int index);
void AddEdge(GraphAdjMat *G, int i, int j);
void RemoveEdge(GraphAdjMat *G, int i, int j);
void PrintGraphAdjMat(GraphAdjMat *G);
void FatalError(char *S);
void PrintArray(int *arr, int num);

#endif