#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initList(){
    Node* list = (Node*)malloc(sizeof(Node));
    list->data = 0;
    list->next = NULL;
    return list;
}

void headInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = list->next;
    list->next = node;
    list->data++;
}

void tailInsert(Node* list, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    Node* current = list;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = node;
    list->data++;
}

void delete(Node*list, int data){
    Node* current = list;
    while(current->next != NULL && current->next->data != data){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    list->data--;
}

void printList(Node* list){
    Node* current = list->next;
    while(current != NULL){
        printf("%d ", current->data);
        current= current->next;
    }
    printf("\n");
}

int main(){
    Node* list = initList();
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    headInsert(list,4);
    headInsert(list,5);
    tailInsert(list,6);
    tailInsert(list,7);
    tailInsert(list,8);
    tailInsert(list,9);
    tailInsert(list,10);
    delete(list,3);
    delete(list,5);
    printList(list);
    
    system("pause");
    return 0;
}