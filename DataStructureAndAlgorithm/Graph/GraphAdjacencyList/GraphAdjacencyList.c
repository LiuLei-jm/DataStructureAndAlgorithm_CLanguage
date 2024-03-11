#include "GraphAdjacencyList.h"
#define MAX_SIZE 10

struct adjacencyListNode{
    Vertex * vertex;
    struct AdjListNode* next;
};
struct graphAdjlist{
    AdjListNode* heads[MAX_SIZE];
    int size;
};

void AddEdgeHelper(AdjListNode* head, Vertex *vet){
    AdjListNode *node = (AdjListNode* )malloc(sizeof(AdjListNode));
    node->vertex = vet;
    node->next = head->next;
    head->next = node;   
}

void RemoveEdgeHelper(AdjListNode*head, Vertex *vet){
    AdjListNode* pre = head;
    AdjListNode* cur = head->next;
    while(cur != NULL && cur->vertex != vet){
        pre = cur;
        cur = cur->next;
    }
    if(cur == NULL)return ;
    pre->next = cur->next;
    free(cur);
}

GraphAdjList* NewGraphAdjList(){
    GraphAdjList *G = (GraphAdjList*)malloc(sizeof(struct graphAdjList));
    if(!graph){
        FatalError("Out of space!!!");
    }
    G->size = 0;
    for(int i = 0; i < MAX_SIZE; i++){
        G->heads[i] = NULL;
    }
    return G;
}

void DelGraphAdjList(GraphAdjList *G){
    for(int i = 0; i < G->size; i++){
        AdjListNode *cur = G->heads[i];
        while(cur != NULL){
            AdjListNode*next = cur->next;
            if(cur != G->heads[i]){
                free(cur);
            }
            cur = next;
        }
        free(G->heads[i]->vertex);
        free(G->heads[i]);
    }   
    free(G);
}

AdjListNode*FindNode(GraphAdjList*G, Vertex *vet){
     for(int i = 0; i< G->size; i++){
        if(G->heads[i]->vertex == vet){
            return G->heads[i];
        }
     }  
     return NULL;
}

void RemoveEdge(GraphAdjList*G, Vertex* vet1, Vertex* vet2){
       
}

void AddVertex(GraphAdjList *G, Vertex* vet);
void RemoveVertex(GraphAdjList*G, Vertex *vet);
void PrintGraph(GraphAdjList*G, int size);
void FatalError(char *S);