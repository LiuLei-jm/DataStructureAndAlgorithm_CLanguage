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
    L->pre = L;
    L->next = L;
}

void headInsert(Node *L, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    if (L->data == 0)
    {
        node->pre = L;
        node->next = L;
        L->pre = node;
        L->next = node;
        L->data++;
    }
    else
    {
        node->next = L->next;
        L->next->pre = node;
        node->pre = L;
        L->next = node;
        L->data++;
    }
}

void tailInsert(Node *L, int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    Node *tail = L;
    L->pre = node;
    node->next = L;
    while (tail->next != L)
        tail = tail->next;
    tail->next = node;
    node->pre = tail;
    L->data++;
}

int delete(Node*L ,int data){
    Node* current = L->next;
    while(current != L){
        if(current->data == data){
            current->next->pre = current->pre;
            current->pre->next = current->next;
            free(current);
            L->data--;
            return TRUE;
        }
        current=current->next;
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
    printf("Total:%d\n", L->data);
}

int main()
{
    Node *head = initList();
    headInsert(head, 1);
    headInsert(head, 2);
    headInsert(head, 3);
    headInsert(head, 4);
    tailInsert(head, 6);
    tailInsert(head, 7);
    tailInsert(head, 8);
    tailInsert(head, 9);
    headInsert(head, 5);
    
    if(delete(head, 7)){
        printf("删除成功！\n");
    }
    if(delete(head, 2)){
        printf("删除成功！\n");
    }

    printList(head);

    system("pause");
    return 0;
}