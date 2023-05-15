#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* initStack(){
    Node* S = (Node*)malloc(sizeof(Node));
    S->data = 0;
    S->next = NULL;
    return S;
}

int pop(Node* S){
    if(isEmpty(S)) return -1;
    else  {
        Node* popData = S->next;
        S->next = popData->next;
        S->data--;
        int value = popData->data;
        free(popData);
        return value;
    }
}

void printStack(Node* S){
    Node* node = S->next;
    while(node){
        printf("%d->", node->data);
        node = node->next;
    }
    printf("Totel: %d\n",S->data);
}

void push(Node*S, int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = S->next;
    S->next = node;
    S->data++;
}

int isEmpty(Node* S){
    if(S->data == 0 || S->next == NULL){
        return 1;
    }
    return 0;
}


int main(){
    Node* S = initStack();
    push(S, 1);
    push(S, 2);
    push(S, 3);
    push(S, 4);
    pop(S);
    printStack(S);
    
    
    system("pause");
    return 0;
}