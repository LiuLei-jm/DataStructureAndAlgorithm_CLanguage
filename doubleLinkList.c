#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node
{
    int data;
    struct Node *pre;
    struct Node *next;
} Node;

Node *initList()
{
    Node *L = (Node *)malloc(sizeof(Node));
    L->data = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}

void headInsert(Node *L, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (L->data == 0)
    {
        node->next = NULL;
        node->pre = L;
        L->next = node;
    }
    else
    {
        node->pre = L;
        node->next = L->next;
        L->next->pre = node;
        L->next = node;
    }
    L->data++;
}

void tailInsert(Node* L, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    Node* current = L;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;
    node->pre = current;
    node->next = NULL;
    L->data++;
}

int delete(Node*L , int data){
    Node* current = L->next;
    while(current){
        if(current->data == data){
            current->pre->next = current->next;
            current->next->pre = current->pre;
            free(current);
            L->data--;
            return TRUE;
        }
        current = current->next;
    }
    return FALSE;
}

void printList(Node* L){
    Node* current = L->next;
    while(current){
        printf("%d->", current->data);
        current= current->next;
    }
    printf("Total: %d\n", L->data);
}

int main()
{
    Node* head = initList();
    headInsert(head, 1);
    headInsert(head, 2);
    headInsert(head, 3);
    headInsert(head, 4);
    headInsert(head, 5);
    tailInsert(head, 6);
    tailInsert(head, 7);
    tailInsert(head, 8);
    if(delete(head, 4)) printf("删除成功\n");
    printList(head);
    system("pause");
    return 0;
}