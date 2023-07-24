#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *initList()
{
    Node *L = (Node *)malloc(sizeof(Node));
    L->data = 0;
    L->next = L;
}

void headInsert(Node *L, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = L->next;
    L->next = node;
    L->data++;
}

void tailInsert(Node*L, int data){
    Node*node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = L;
    Node*current = L->next;
    while(current->next != L){
        current=current->next;
    }
    current->next = node;
    L->data++;
}

int deleteNode(Node* L, int data){
    Node* node = L;
    while(node->next != L){
        if(node->next->data == data){
            Node* temp = node->next;
            node->next = temp->next;
            free(temp);
            return TRUE;
        }
        node = node->next;
    }
    return FALSE;
}

void printList(Node *L)
{
    Node *current = L->next;
    while (current != L)
    {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *L = initList();
    headInsert(L, 1);
    headInsert(L, 2);
    headInsert(L, 3);
    headInsert(L, 4);
    headInsert(L, 5);
    tailInsert(L, 6);
    tailInsert(L, 7);
    if(deleteNode(L,6)== TRUE){
        printf("\n删除成功\n");
    }
    printList(L);

    system("pause");
    return 0;
}