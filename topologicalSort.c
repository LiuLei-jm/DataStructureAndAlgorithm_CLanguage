#include <stdio.h>
#include <stdlib.h>

#define MAX 3276

typedef struct Graph
{
    char *vexs;
    int **arcs;
    int vexNum;
    int arcNum;
} Graph;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initStack()
{
    Node *stack = (Node *)malloc(sizeof(Node));
    stack->data = 0;
    stack->next = NULL;
    return stack;
}

void push(Node *stack, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->next;
    stack->next = node;
    stack->data++;
}

int isEmpty(Node *stack)
{
    return stack->data == 0 ? 1 : 0;
}

int pop(Node *stack)
{
    if (!isEmpty(stack))
    {
        Node *node = stack->next;
        stack->next = node->next;
        int temp = node->data;
        free(node);
        stack->data--;
        return temp;
    }
    else
    {
        return -1;
    }
}

int *findInDegrees(Graph *G)
{
    int *inDegrees = (int *)malloc(sizeof(int) * G->vexNum);
    for (int i = 0; i < G->vexNum; i++)
    {
        inDegrees[i] = 0;
    }
    for (int i = 0; i < G->vexNum; i++)
    {
        for (int j = 0; j < G->vexNum; j++)
        {
            if (G->arcs[i][j])
                inDegrees[j] = inDegrees[j] + 1;
        }
    }
    return inDegrees;
}

void topologicalSort(Graph *G)
{
    int index = 0;
    int *top = (int *)malloc(sizeof(int) * G->vexNum);
    int *inDegrees = findInDegrees(G);
    Node *stack = initStack();
    for (int i = 0; i < G->vexNum; i++)
    {
        if (inDegrees[i] == 0)
        {
            push(stack, i);
        }
    }
    while (!isEmpty(stack))
    {
        int vex = pop(stack);
        top[index++] = vex;
        for (int i = 0; i < G->vexNum; i++)
        {
            if (G->arcs[vex][i])
            {
                inDegrees[i] -= 1;
                if (inDegrees[i] == 0)
                    push(stack, i);
            }
        }
    }
    for (int i = 0; i < index; i++)
    {
        printf("%c ", G->vexs[top[i]]);
    }
    putchar('\n');
}

Graph *initGraph(int vexNum)
{
    Graph *G = (Graph *)malloc(sizeof(Graph));
    G->vexs = (char *)malloc(sizeof(char) * vexNum);
    G->arcs = (int **)malloc(sizeof(int *) * vexNum);
    for (int i = 0; i < vexNum; i++)
    {
        G->arcs[i] = (int *)malloc(sizeof(int));
    }
    G->vexNum = vexNum;
    G->arcNum = 0;
    return G;
}

void createGraph(Graph *G, char *vexs, int *arcs)
{
    for (int i = 0; i < G->vexNum; i++)
    {
        G->vexs[i] = vexs[i];
        for (int j = 0; j < G->vexNum; j++)
        {
            G->arcs[i][j] = *(arcs + i * G->vexNum + j);
            if (G->arcs[i][j] != 0 && G->arcs[i][j] != MAX)
                G->arcNum++;
        }
    }
    G->arcNum /= 2;
}

void DFS(Graph *G, int *visited, int index)
{
    printf("%c\t", G->vexs[index]);
    visited[index] = 1;
    for (int i = 0; i < G->vexNum; i++)
    {
        if (G->arcs[index][i] != 0 && G->arcs[index][i] != MAX && !visited[i])
            DFS(G, visited, i);
    }
}

int main()
{
    Graph *G = initGraph(6);
    int *visited = (int *)malloc(sizeof(int));
    for (int i = 0; i < G->vexNum; i++)
        visited[i] = 0;
    int arcs[6][6] = {
        0,
        1,
        1,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        1,
        1,
        0,
    };
    createGraph(G, "123456", (int *)arcs);
    DFS(G, visited, 0);
    putchar('\n');
    topologicalSort(G);
    system("pause");
    return 0;
}