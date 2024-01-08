/*
 * 编写一个非递归程序以O(N)时间反转单链表
*/
#include <stdio.h>
#include <stdlib.h>

#define ElementType int

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
    ElementType Element;
    PtrToNode Next;
};

List MakeEmpty(){
    List head = (List)malloc(sizeof(struct Node));
    if(head == NULL){
        printf("out of space!\n");
        exit(-1);
    }
    head->Next = NULL;
    return head;
}

List InitList(int n, List L){
    Position pCurrent = L;
    for(int i = 1; i <= n; i++){
        Position TmpCell = (Position)malloc(sizeof(struct Node));
        if(TmpCell == NULL){
            printf("out of space!\n");
            exit(-1);
        }
        TmpCell->Element = i;
        TmpCell->Next = NULL;
        pCurrent->Next = TmpCell;
        pCurrent = TmpCell;
    }
    return L;
}

void PrintList(List L){
    Position pCurrent = L->Next;
    while(pCurrent != NULL){
        printf("%d ", pCurrent->Element);
        pCurrent= pCurrent->Next;
    }
    putchar('\n');
}

List ReversedList(List head){
    Position pCurrent, pPrev, temp;
    pPrev = head->Next;
    pCurrent = pPrev->Next;
    pPrev->Next = NULL;
    while(pCurrent != NULL){
        temp = pCurrent->Next;
        pCurrent->Next = pPrev;
        pPrev = pCurrent;
        pCurrent = temp;
    }
    head->Next = pPrev;
    return head;
}

int main(){
    List head = MakeEmpty();
    head = InitList(100, head);
    PrintList(head);
    head = ReversedList(head);
    PrintList(head);
    system("Pause");
    return 0;
}