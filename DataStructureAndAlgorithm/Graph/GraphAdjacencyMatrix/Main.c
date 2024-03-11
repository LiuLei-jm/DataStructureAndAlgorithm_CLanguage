#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjMat.c"

int main(){
    GraphAdjMat *G = NewGraphAdjMat(); 
    AddVertex(G, 1);
    AddVertex(G, 2);
    AddVertex(G, 3);
    AddVertex(G, 4);
    AddVertex(G, 5);
    AddEdge(G, 0, 4);
    AddEdge(G, 0, 2);
    AddEdge(G, 4, 1);
    AddEdge(G, 4, 3);
    AddEdge(G, 2, 1);
    AddEdge(G, 1, 3);
    PrintGraphAdjMat(G);

    AddEdge(G, 0, 1);
    PrintGraphAdjMat(G);

    RemoveEdge(G, 0, 2);
    PrintGraphAdjMat(G);

    AddVertex(G, 6);
    PrintGraphAdjMat(G);

    RemoveVertex(G, 2);
    PrintGraphAdjMat(G);

    system("Pause");
    return 0;
}