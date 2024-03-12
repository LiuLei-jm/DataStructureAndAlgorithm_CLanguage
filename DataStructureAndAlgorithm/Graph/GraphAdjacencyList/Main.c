#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjacencyList.c"

int main()
{
    GraphAdjList *G = NewGraphAdjList();
    Vertex n1 = 1;
    Vertex n2 = 2;
    Vertex n3 = 3;
    Vertex n4 = 4;
    Vertex n5 = 5;
    AddVertex(G, &n1);
    AddVertex(G, &n2);
    AddVertex(G, &n3);
    AddVertex(G, &n4);
    AddVertex(G, &n5);
    AddEdge(G, G->heads[0]->vertex, G->heads[2]->vertex);
    AddEdge(G, G->heads[0]->vertex, G->heads[4]->vertex);
    AddEdge(G, G->heads[4]->vertex, G->heads[3]->vertex);
    AddEdge(G, G->heads[4]->vertex, G->heads[1]->vertex);
    AddEdge(G, G->heads[2]->vertex, G->heads[1]->vertex);
    AddEdge(G, G->heads[1]->vertex, G->heads[3]->vertex);
    PrintGraph(G, G->size);

    AddEdge(G, G->heads[0]->vertex, G->heads[1]->vertex);
    PrintGraph(G, G->size);

    RemoveEdge(G, G->heads[0]->vertex, G->heads[2]->vertex);
    PrintGraph(G, G->size);

    Vertex n6 = 6;
    AddVertex(G, &n6);
    PrintGraph(G, G->size);

    RemoveVertex(G, G->heads[2]->vertex);
    PrintGraph(G, G->size);

    system("Pause");
    return 0;
}