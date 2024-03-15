#include <stdio.h>
#include <stdlib.h>
#include "GraphAdjList.c"


int main(){
    GraphAdjList *G = NewGraphAdjList();
    Vertex v1 = 0;
    Vertex v2 = 1;
    Vertex v3 = 2;
    Vertex v4 = 3;
    Vertex v5 = 4;
    Vertex v6 = 5;
    Vertex v7 = 6;
    Vertex v8 = 7;
    Vertex v9 = 8;
    AddVertex(G, &v1);
    AddVertex(G, &v2);
    AddVertex(G, &v3);
    AddVertex(G, &v4);
    AddVertex(G, &v5);
    AddVertex(G, &v6);
    AddVertex(G, &v7);
    AddVertex(G, &v8);
    AddVertex(G, &v9);
    AddEdge(G,G->heads[0]->vertex,G->heads[1]->vertex);
    AddEdge(G,G->heads[0]->vertex,G->heads[3]->vertex);
    AddEdge(G,G->heads[1]->vertex,G->heads[2]->vertex);
    AddEdge(G,G->heads[1]->vertex,G->heads[4]->vertex);
    AddEdge(G,G->heads[2]->vertex,G->heads[5]->vertex);
    AddEdge(G,G->heads[3]->vertex,G->heads[4]->vertex);
    AddEdge(G,G->heads[3]->vertex,G->heads[6]->vertex);
    AddEdge(G,G->heads[4]->vertex,G->heads[5]->vertex);
    AddEdge(G,G->heads[4]->vertex,G->heads[7]->vertex);
    AddEdge(G,G->heads[5]->vertex,G->heads[8]->vertex);
    AddEdge(G,G->heads[6]->vertex,G->heads[7]->vertex);
    AddEdge(G,G->heads[7]->vertex,G->heads[8]->vertex);
    
    PrintGraph(G, G->size);
    
    Vertex* res[MAX_SIZE];
    Vertex* visited[MAX_SIZE];
    
    GraphBFS(G,G->heads[0]->vertex, res, visited);
    
    printf("Graph BFS:");
    for(int i = 0; i < G->size; i++){
        printf("%d ", *(res[i]));
    }
    putchar('\n');

    system("Pause");
    return 0;
}